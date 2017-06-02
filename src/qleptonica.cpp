
#include <QObject>

#include "qleptonica.h"
#include <leptonica/allheaders.h>

/**
 * List of Leptonica formats
 */
QMap<int, QString> leptonicaFormats() {
    QMap<int, QString> map;
    map[IFF_UNKNOWN] = QObject::trUtf8("Unknown");
    map[IFF_BMP] = QObject::trUtf8("bmp");
    map[IFF_JFIF_JPEG] = QObject::trUtf8("jpeg");
    map[IFF_PNG] = QObject::trUtf8("png");
    map[IFF_TIFF] = QObject::trUtf8("tiff (uncompressed)");
    map[IFF_TIFF_PACKBITS] = QObject::trUtf8("tiff (uncompressed)");
    map[IFF_TIFF_RLE] = QObject::trUtf8("tiff (rle compressed)");
    map[IFF_TIFF_G3] = QObject::trUtf8("tiff (g3 compressed)");
    map[IFF_TIFF_G4] = QObject::trUtf8("tiff (g4 compressed)");
    map[IFF_TIFF_LZW] = QObject::trUtf8("tiff (lzw compressed)");
    map[IFF_TIFF_ZIP] = QObject::trUtf8("tiff (zip ompressed)");
    map[IFF_PNM] = QObject::trUtf8("pnm");
    map[IFF_PS] = QObject::trUtf8("PostScript (write only)");
    map[IFF_GIF] = QObject::trUtf8("gif");
    map[IFF_JP2] = QObject::trUtf8("jp2");
    map[IFF_WEBP] = QObject::trUtf8("webp");
    map[IFF_LPDF] = QObject::trUtf8("Pdf (write only)");
    // map[IFF_DEFAULT] = QObject::trUtf8("default");
    map[IFF_SPIX] = QObject::trUtf8("spix");
    return map;
}

/**
 * Get Leptonica format description
 */
QString getFormatDesc(int format) {
    QMap<int, QString> map = leptonicaFormats();
    return map[format];
}
