#include "mainwindow.h"


MainWindow* MainWindow::m_psMainWindow = nullptr;

void MainWindow::myErrorHandler(const char *msg) {
    QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString message = QString("[%1] %2").arg(dt, QString::fromStdString(msg));
    if(m_psMainWindow) {
        m_psMainWindow->textEdit->append(tr("<span style=\"color:#F04E32;\">%1</span>").arg(message));
    }
}

