#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T10:21:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PushApp
TEMPLATE = app

android {
    QT += androidextras
    FIREBASE_SDK = /Users/wyan/src/libs/firebase_cpp_sdk/
    INCLUDEPATH += $${FIREBASE_SDK}/include/
    
    LIBS += -L/Users/username/src/libs/firebase_cpp_sdk/libs/android/armeabi-v7a/c++/ -lmessaging -lapp -llog -lauth

}

ios  {
# The TEAM ID can be found in the developer portal, under Membership.
    MY_DEVELOPMENT_TEAM.value = <your key here>
    MY_DEVELOPMENT_TEAM.name = DEVELOPMENT_TEAM
    QMAKE_MAC_XCODE_SETTINGS += MY_DEVELOPMENT_TEAM

    #MY_ENTITLEMENTS.name = CODE_SIGN_ENTITLEMENTS
    #MY_ENTITLEMENTS.value = ios/pushnotifications.entitlements
    QMAKE_MAC_XCODE_SETTINGS += MY_ENTITLEMENTS

    CONFIG -= bitcode
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
        MainWindow.cpp \
        NotificationHandler.cpp \

HEADERS  += MainWindow.h \
    NotificationHandler.h \

ios {
    OBJECTIVE_SOURCES += \
        APNSApplicationDelegate.mm
}

android {
    HEADERS += \
         FBListener.h

    SOURCES += \
    FBListener.cpp
    
}
        
FORMS    += mainwindow.ui

CONFIG += mobility

ios {
    DISTFILES += \
        ios/pushnotifications.entitlements
        ios/Info.plist
}


android {

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
                                 
    DISTFILES += \
        android/gradle.properties \
        android/google-services.json \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/gradle/wrapper/gradle-wrapper.properties \
}
