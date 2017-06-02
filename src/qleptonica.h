#ifndef QLEPTONICA_H
#define QLEPTONICA_H

#include <QMap>
#include <QString>

QMap<int, QString> leptonicaFormats();
QString getFormatDesc(int format);

#endif // QLEPTONICA_H
