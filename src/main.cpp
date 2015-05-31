#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QString filename = "";
  if (argc > 1)
    filename = QCoreApplication::arguments().at(1);
  MainWindow w(0, filename);
  w.show();
  return a.exec();
}
