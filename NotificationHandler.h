#ifndef NOTIFICATIONHANDLER_H
#define NOTIFICATIONHANDLER_H

#include <QObject>

class FBListener;

class NotificationHandler : public QObject
{
    Q_OBJECT
public:
    static NotificationHandler* GetInstance();

    void StartMessaging();
    void RegisterToken(const void *bytes, size_t length);

#ifdef Q_OS_ANDROID
    // Ideally, this would be some base class and we can return an
    // implementation subclass. But, we really want to keep this minimal
    FBListener* GetListener() const {
        return _fbListener;
    }
#endif
    
signals:

public slots:

protected:
    explicit NotificationHandler(QObject *parent = 0);

private:
    static NotificationHandler* _instance;

#ifdef Q_OS_ANDROID
    FBListener *_fbListener;
#endif

};

#endif // NOTIFICATIONHANDLER_H
