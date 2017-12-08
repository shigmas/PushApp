#include "NotificationHandler.h"

#include <QDebug>

#ifdef Q_OS_ANDROID
#include "FBListener.h"
#endif

NotificationHandler* NotificationHandler::_instance = NULL;


NotificationHandler*
NotificationHandler::GetInstance()
{
    if (_instance == NULL) {
        _instance = new NotificationHandler();
    }

    return _instance;
}

void
NotificationHandler::StartMessaging()
{
#ifdef Q_OS_ANDROID
    qDebug() << "Calling intializer";
    _fbListener->InitializeMessaging();
#endif

}

void
NotificationHandler::RegisterToken(const void *bytes, size_t length)
{
    qDebug() << "Token of length " << length << " registered";
}

NotificationHandler::NotificationHandler(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_ANDROID
    _fbListener = new FBListener();
#endif
}
