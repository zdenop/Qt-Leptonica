#include "qleptonica.h"
#include "mainwindow.h"
#include <QDebug>
#include <QVector>

// Returns a map of Leptonica formats and their descriptions.
QMap<int, QString> leptonicaFormats() {
    return {
        {IFF_UNKNOWN, "Unknown"},
        {IFF_BMP, "bmp"},
        {IFF_JFIF_JPEG, "jpeg"},
        {IFF_PNG, "png"},
        {IFF_TIFF, "tiff (uncompressed)"},
        {IFF_TIFF_PACKBITS, "tiff (Packbits compressed)"},
        {IFF_TIFF_RLE, "tiff (RLE compressed)"},
        {IFF_TIFF_G3, "tiff (G3 compressed)"},
        {IFF_TIFF_G4, "tiff (G4 compressed)"},
        {IFF_TIFF_LZW, "tiff (LZW compressed)"},
        {IFF_TIFF_ZIP, "tiff (ZIP compressed)"},
        {IFF_PNM, "pnm"},
        {IFF_PS, "PostScript (write only)"},
        {IFF_GIF, "gif"},
        {IFF_JP2, "jp2"},
        {IFF_WEBP, "webp"},
        {IFF_LPDF, "Pdf (write only)"},
        {IFF_SPIX, "spix"}
    };
}

// Retrieves a description of the specified Leptonica format.
QString getFormatDesc(int format) {
    const auto map = leptonicaFormats();
    return map.value(format, "Unknown Format");
}

// Performs line removal on the input PIX and returns a PIXA object containing the result.
PIXA* lineremoval(PIX* pix_input) {
    if (pix_input->d != 8) {
        qDebug() << "Failure: Function pixRotateAMGray requires 8 bpp image depth.";
        return nullptr;
    }

    constexpr l_float32 deg2rad = 3.14159f / 180.0f;
    auto pixa = pixaCreate(0);

    PIX* pix1 = nullptr;
    switch (pix_input->d) {
    case 4:
    case 8:
        pix1 = pixThresholdToBinary(pix_input, 170);
        break;
    case 1:
        pix1 = pixCopy(nullptr, pix_input);
        break;
    case 32: {
        auto pixsg = pixConvertRGBToLuminance(pix_input);
        pix1 = pixThresholdToBinary(pixsg, 170);
        pixDestroy(&pixsg);
        break;
    }
    default:
        return nullptr;
    }

    pixaAddPix(pixa, pix1, L_INSERT);

    l_float32 angle, conf;
    pixFindSkew(pix1, &angle, &conf);
    auto pix2 = pixRotateAMGray(pix_input, deg2rad * angle, 255);
    pixaAddPix(pixa, pix2, L_INSERT);

    auto pix3 = pixCloseGray(pix2, 51, 1);
    pixaAddPix(pixa, pix3, L_INSERT);

    auto pix4 = pixErodeGray(pix3, 1, 5);
    pixaAddPix(pixa, pix4, L_INSERT);

    auto pix5 = pixThresholdToValue(nullptr, pix4, 210, 255);
    pixaAddPix(pixa, pix5, L_INSERT);

    auto pix6 = pixThresholdToValue(nullptr, pix5, 200, 0);
    pixaAddPix(pixa, pix6, L_COPY);

    auto pix7 = pixThresholdToBinary(pix6, 210);
    pixaAddPix(pixa, pix7, L_INSERT);

    pixInvert(pix6, pix6);
    auto pix8 = pixAddGray(nullptr, pix2, pix6);
    pixaAddPix(pixa, pix8, L_COPY);

    auto pix9 = pixOpenGray(pix8, 1, 9);
    pixaAddPix(pixa, pix9, L_INSERT);

    pixCombineMasked(pix8, pix9, pix7);
    pixaAddPix(pixa, pix8, L_INSERT);

    pixDestroy(&pix6);
    return pixa;
}

// Converts a Leptonica PIX to a Qt QImage.
QImage MainWindow::PixToQImage(PIX* pixs) {
    if (!pixs) return QImage();

    QVector<QRgb> _bwCT = {qRgb(255, 255, 255), qRgb(0, 0, 0)};
    QVector<QRgb> _grayscaleCT(256);
    for (int i = 0; i < 256; ++i) {
        _grayscaleCT[i] = qRgb(i, i, i);
    }

    auto s_data = pixGetData(pixEndianByteSwapNew(pixs));
    int width = pixGetWidth(pixs);
    int height = pixGetHeight(pixs);
    int depth = pixGetDepth(pixs);
    int bytesPerLine = pixGetWpl(pixs) * 4;

    QImage::Format format = (depth == 1) ? QImage::Format_Mono :
                                (depth == 8) ? QImage::Format_Indexed8 :
                                QImage::Format_RGB32;

    QImage result(reinterpret_cast<uchar*>(s_data), width, height, bytesPerLine, format);

    int xres, yres;
    pixGetResolution(pixs, &xres, &yres);
    const qreal toDPM = 1.0 / 0.0254;
    result.setDotsPerMeterX(static_cast<int>(xres * toDPM));
    result.setDotsPerMeterY(static_cast<int>(yres * toDPM));

    if (depth == 1) {
        result.setColorTable(_bwCT);
    } else if (depth == 8) {
        result.setColorTable(_grayscaleCT);
    }

    return result.isNull() ? QImage() : result.rgbSwapped();
}

// Converts a Qt QImage to a Leptonica PIX.
PIX* MainWindow::QImageToPIX(const QImage& qImage) {
    QImage myImage = qImage.rgbSwapped();
    int width = myImage.width();
    int height = myImage.height();
    int depth = myImage.depth();
    int wpl = myImage.bytesPerLine() / 4;

    auto pixs = pixCreate(width, height, depth);
    pixSetWpl(pixs, wpl);
    pixSetColormap(pixs, nullptr);
    auto datas = pixs->data;

    for (int y = 0; y < height; ++y) {
        auto lines = datas + y * wpl;
        const auto* srcLine = reinterpret_cast<const uchar*>(myImage.scanLine(y));
        std::copy(srcLine, srcLine + myImage.bytesPerLine(), reinterpret_cast<uchar*>(lines));
    }

    const qreal toDPM = 1.0 / 0.0254;
    int resolutionX = std::max(300, static_cast<int>(myImage.dotsPerMeterX() / toDPM));
    int resolutionY = std::max(300, static_cast<int>(myImage.dotsPerMeterY() / toDPM));
    pixSetResolution(pixs, resolutionX, resolutionY);

    return pixEndianByteSwapNew(pixs);
}
