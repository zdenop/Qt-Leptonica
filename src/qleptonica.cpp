
#include <QObject>
#include <QDebug>

#include "qleptonica.h"

/**
 * List of Leptonica formats
 */
QMap<int, QString> leptonicaFormats() {
    QMap<int, QString> map;
    map[IFF_UNKNOWN] = "Unknown";
    map[IFF_BMP] = "bmp";
    map[IFF_JFIF_JPEG] = "jpeg";
    map[IFF_PNG] = "png";
    map[IFF_TIFF] = "tiff (uncompressed)";
    map[IFF_TIFF_PACKBITS] = "tiff (uncompressed)";
    map[IFF_TIFF_RLE] = "tiff (rle compressed)";
    map[IFF_TIFF_G3] = "tiff (g3 compressed)";
    map[IFF_TIFF_G4] = "tiff (g4 compressed)";
    map[IFF_TIFF_LZW] = "tiff (lzw compressed)";
    map[IFF_TIFF_ZIP] = "tiff (zip ompressed)";
    map[IFF_PNM] = "pnm";
    map[IFF_PS] = "PostScript (write only)";
    map[IFF_GIF] = "gif";
    map[IFF_JP2] = "jp2";
    map[IFF_WEBP] = "webp";
    map[IFF_LPDF] = "Pdf (write only)";
    // map[IFF_DEFAULT] = "default";
    map[IFF_SPIX] = "spix";
    return map;
}

/**
 * Get Leptonica format description
 */
QString getFormatDesc(int format) {
    QMap<int, QString> map = leptonicaFormats();
    return map[format];
}

/*
 * A fun little application, saved as a regression test.
 */
PIXA * lineremoval(PIX * pix_input){
    l_float32     angle, conf, deg2rad;
    PIX          *pix1, *pix2, *pix3, *pix4, *pix5;
    PIX          *pix6, *pix7, *pix8, *pix9;
    PIXA         *pixa;

    deg2rad = static_cast<l_float32>(3.14159 / 180.00);
    pixa = pixaCreate(0);

    /* Threshold to binary, extracting much of the lines */
    if (pix_input->d == 4 || pix_input->d == 8)
        pix1 = pixThresholdToBinary(pix_input, 170);
    else if (pix_input->d == 1) {
        pix1 = pixCopy(NULL, pix_input);
    } else if (pix_input->d == 32) {
        PIX * pixsg = pixConvertRGBToLuminance(pix_input);
        pix1 = pixThresholdToBinary(pixsg, 170);
        pixDestroy(&pixsg);
    } else {
        return 0;
    }

    pixaAddPix(pixa, pix1, L_INSERT);

    /* Find the skew angle and deskew using an interpolated
             * rotator for anti-aliasing (to avoid jaggies) */
    pixFindSkew(pix1, &angle, &conf);
    if (pix_input->d != 8) {
        qDebug() << "Error in pixRotateAMGray: pixs must be 8 bpp";
        return 0;
    } else {
        pix2 = pixRotateAMGray(pix_input, deg2rad * angle, 255);
    }
    pixaAddPix(pixa, pix2, L_INSERT);

    /* Extract the lines to be removed */
    pix3 = pixCloseGray(pix2, 51, 1);
    pixaAddPix(pixa, pix3, L_INSERT);

    /* Solidify the lines to be removed */
    pix4 = pixErodeGray(pix3, 1, 5);
    pixaAddPix(pixa, pix4, L_INSERT);

    /* Clean the background of those lines */
    pix5 = pixThresholdToValue(NULL, pix4, 210, 255);
    pixaAddPix(pixa, pix5, L_INSERT);

    pix6 = pixThresholdToValue(NULL, pix5, 200, 0);
    pixaAddPix(pixa, pix6, L_COPY);

    /* Get paint-through mask for changed pixels */
    pix7 = pixThresholdToBinary(pix6, 210);
    pixaAddPix(pixa, pix7, L_INSERT);

    /* Add the inverted, cleaned lines to orig.  Because
     * the background was cleaned, the inversion is 0,
     * so when you add, it doesn't lighten those pixels.
     * It only lightens (to white) the pixels in the lines! */
    pixInvert(pix6, pix6);
    pix8 = pixAddGray(NULL, pix2, pix6);
    pixaAddPix(pixa, pix8, L_COPY);

    pix9 = pixOpenGray(pix8, 1, 9);
    pixaAddPix(pixa, pix9, L_INSERT);
    pixCombineMasked(pix8, pix9, pix7);
    pixaAddPix(pixa, pix8, L_INSERT);

    pixDestroy(&pix6);
    return pixa;
}
