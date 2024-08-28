#ifndef QLEPTONICA_H
#define QLEPTONICA_H

#include <leptonica/allheaders.h>
#if (LIBLEPT_MAJOR_VERSION > 1) || (LIBLEPT_MINOR_VERSION > 82)
#include <leptonica/pix_internal.h>
#endif

#include <QMap>
#include <QString>

// Returns a map of Leptonica formats and their descriptions.
QMap<int, QString> leptonicaFormats();

// Returns a description of the specified Leptonica format.
QString getFormatDesc(int format);

// Performs line removal on the input PIX and returns a PIXA object containing the result.
PIXA* lineremoval(PIX* pix_input);

#endif  // QLEPTONICA_H
