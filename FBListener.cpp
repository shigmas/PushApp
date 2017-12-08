#include "FBListener.h"

#include "NotificationHandler.h"

#include <QtAndroid>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>

#include <QDebug>

FBListener::FBListener()
{
    qDebug() << "PushDelegate. Creating JNI Env";
    _jniEnv = new QAndroidJniEnvironment();
    qDebug() << "Getting Android Activity";
    QAndroidJniObject jniObject = QtAndroid::androidActivity();
    qDebug() << "Creating Firebase App";
    ::firebase::App *instance = ::firebase::App::GetInstance();
    if (instance) {
        qDebug() << "App instance already exists";
        _app = instance;
    } else {
        qDebug() << "Creating app instance";
        _app = ::firebase::App::Create(*_jniEnv, jniObject.object<jobject>());
    }
}

static ::firebase::InitResult _InitializeMessaging(::firebase::App *app, void *) {
    qDebug() << "Try to initialize Firebase Messaging";
    NotificationHandler *handler = NotificationHandler::GetInstance();
    return ::firebase::messaging::Initialize(*app, handler->GetListener());
}

void
FBListener::InitializeMessaging()
{
    qDebug() << "Initializing Firebase module";
    _initializer.Initialize(_app, nullptr,_InitializeMessaging);
    qDebug() << "Module initialized. Waiting on messaging initialization";

}

void
FBListener::OnTokenReceived(const char *token)
{
    // I guess this is null terminated?
    qDebug() << "Token received: [" << token << "]";
}

void
FBListener::OnMessage(const ::firebase::messaging::Message & /*message*/)
{
    qDebug() << "Received message";
}

