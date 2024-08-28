#include <QApplication>
#include <QString>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    const auto args = QCoreApplication::arguments();
    const QString filename = args.size() > 1 ? args[1] : QString();

    MainWindow w(nullptr, filename);
    w.show();

    return a.exec();
}
