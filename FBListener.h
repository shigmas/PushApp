#ifndef FBLISTENER_H
#define FBLISTENER_H

#include <firebase/messaging.h>

// Being lazy and not forward declaring these
#include "firebase/app.h"
#include "firebase/util.h"

class QAndroidJniEnvironment;

class FBListener : public ::firebase::messaging::Listener
{
public:
    FBListener();

    void InitializeMessaging();

    virtual void OnTokenReceived(const char *token);

    virtual void OnMessage(const ::firebase::messaging::Message & message);

private:
    QAndroidJniEnvironment *_jniEnv;
    ::firebase::App* _app;
    ::firebase::ModuleInitializer _initializer;

};

#endif // FBLISTENER_H
