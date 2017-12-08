
#import "UIKit/UIKit.h"

// Include our C++ class
#include "NotificationHandler.h"

// This is hidden, so we declare it here to hook into it
@interface QIOSApplicationDelegate
@end

//add a category to QIOSApplicationDelegate
@interface QIOSApplicationDelegate (NotificationDelegate)
@end

@implementation QIOSApplicationDelegate (NotificationDelegate)

- (BOOL)application:(UIApplication *)application
    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // This may be necessary to receive notifications
    [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];

    [application registerForRemoteNotifications];
    NSLog(@"registered for remote notifications");
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    NSLog(@"Did Register for Remote Notifications with Device Token (%@)", deviceToken);
    NotificationHandler::GetInstance()->RegisterToken(deviceToken.bytes, deviceToken.length);
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"Did Fail to Register for Remote Notifications");
    NSLog(@"%@, %@", error, error.localizedDescription);

}

@end
