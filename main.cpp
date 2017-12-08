#include "MainWindow.h"
#include <QApplication>

#include "NotificationHandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    NotificationHandler::GetInstance()->StartMessaging();

    return a.exec();
}
