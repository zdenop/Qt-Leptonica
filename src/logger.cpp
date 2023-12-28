#include "mainwindow.h"


MainWindow* MainWindow::m_psMainWindow = nullptr;

void MainWindow::myErrorHandler(const char *msg) {
    QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString message = QString("[%1] %2").arg(dt, QString::fromStdString(msg));
    if(m_psMainWindow) {
        m_psMainWindow->textEdit->append(tr("<span style=\"color:#F04E32;\">%1</span>").arg(message));
    }
}

void MainWindow::customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    Q_UNUSED(context);

    QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString txt = QString("[%1] ").arg(dt);

    switch (type)    {
    case QtDebugMsg:
        txt += QString("[Debug] %1").arg(msg);
        break;
    case QtInfoMsg:
        txt += QString("[Info] %1").arg(msg);
        abort();
        break;
    case QtWarningMsg:
        txt += QString("[Warning] %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt += QString("[Critical] %1").arg(msg);
        break;
    case QtFatalMsg:
        txt += QString("[Fatal] %1").arg(msg);
        abort();
        break;
    }
    if(m_psMainWindow) {
        m_psMainWindow->textEdit->append(tr("<span style=\"color:#008000;\">%1</span>").arg(txt));
    }
}
