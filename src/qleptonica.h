#ifndef QLEPTONICA_H
#define QLEPTONICA_H

#include <QMap>
#include <QString>

#include <leptonica/allheaders.h>
#if (LIBLEPT_MAJOR_VERSION > 1) || (LIBLEPT_MINOR_VERSION > 82)
    #include <leptonica/pix_internal.h>
#endif

QMap<int, QString> leptonicaFormats();
QString getFormatDesc(int format);
PIXA *lineremoval(PIX *pix_input);

#endif // QLEPTONICA_H
