#ifndef QLEPTONICA_H
#define QLEPTONICA_H

#include <QMap>
#include <QString>

#include <leptonica/allheaders.h>

QMap<int, QString> leptonicaFormats();
QString getFormatDesc(int format);
PIXA *lineremoval(PIX *pix_input);

#endif // QLEPTONICA_H
