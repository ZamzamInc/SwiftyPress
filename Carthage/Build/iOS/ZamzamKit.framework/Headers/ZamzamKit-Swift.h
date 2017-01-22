// Generated by Apple Swift version 3.0.2 (swiftlang-800.0.63 clang-800.0.42.1)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import Foundation;
@import CoreLocation;
@import ObjectiveC;
@import UIKit;
@import CoreGraphics;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

@interface NSBundle (SWIFT_EXTENSION(ZamzamKit))
/**
  Gets the contents of the specified plist file.
  \param plistName property list where defaults are declared

  \param bundle bundle where defaults reside


  returns:
  dictionary of values
*/
+ (NSDictionary<NSString *, id> * _Nonnull)contentsOfFile:(NSString * _Nonnull)plistName inDirectory:(NSString * _Nullable)inDirectory bundle:(NSBundle * _Nullable)bundle;
/**
  Gets the contents of the specified bundle URL.
  \param bundleURL bundle URL where defaults reside

  \param plistName property list where defaults are declared


  returns:
  dictionary of values
*/
+ (NSDictionary<NSString *, id> * _Nonnull)contentsOfFileWithBundleURL:(NSURL * _Nonnull)bundleURL plistName:(NSString * _Nonnull)plistName;
/**
  Gets the contents of the specified bundle name.
  \param bundleName bundle name where defaults reside

  \param plistName property list where defaults are declared


  returns:
  dictionary of values
*/
+ (NSDictionary<NSString *, id> * _Nonnull)contentsOfFileWithBundleName:(NSString * _Nonnull)bundleName plistName:(NSString * _Nonnull)plistName;
/**
  Gets the contents of the specified bundle.
  \param bundle bundle where defaults reside

  \param bundleName bundle name where defaults reside

  \param plistName property list where defaults are declared


  returns:
  dictionary of values
*/
+ (NSDictionary<NSString *, id> * _Nonnull)contentsOfFileWithBundle:(NSBundle * _Nonnull)bundle bundleName:(NSString * _Nonnull)bundleName plistName:(NSString * _Nonnull)plistName;
@end


@interface CLLocation (SWIFT_EXTENSION(ZamzamKit))
@end

@protocol CLLocationManagerDelegate;

@interface CLLocationManager (SWIFT_EXTENSION(ZamzamKit))
- (nonnull instancetype)init:(id <CLLocationManagerDelegate> _Nonnull)delegate desiredAccuracy:(CLLocationAccuracy)desiredAccuracy distanceFilter:(double)distanceFilter forceInitialRequest:(BOOL)forceInitialRequest monitorSignificantLocationChanges:(BOOL)monitorSignificantLocationChanges;
/**
  Cross-platform method for updating location
  Calls startUpdatingLocation for iOS
  Calls requestLocation for watchOS
*/
- (BOOL)tryStartUpdating:(BOOL)forceInitialRequest monitorSignificantLocationChanges:(BOOL)monitorSignificantLocationChanges;
+ (BOOL)isAuthorized;
@end


@interface NSDateFormatter (SWIFT_EXTENSION(ZamzamKit))
- (nonnull instancetype)initWithDateFormat:(NSString * _Nonnull)dateFormat;
@end


@interface NSFileManager (SWIFT_EXTENSION(ZamzamKit))
/**
  Get file system path for document file
  \param fileName Name of file


  returns:
  File path from document directory
*/
+ (NSString * _Nonnull)getDocumentPath:(NSString * _Nonnull)fileName;
/**
  Get file system paths for document file
  \param filter Specify filter to apply


  returns:
  List of file paths from document directory
*/
+ (NSArray<NSString *> * _Nonnull)getDocumentPaths:(BOOL (^ _Nullable)(NSURL * _Nonnull))filter;
@end


@interface NSObject (SWIFT_EXTENSION(ZamzamKit))
@end


@interface UIActivity (SWIFT_EXTENSION(ZamzamKit))
/**
  Creates an instance of an activity.
  \param title Title to display for the activity

  \param imageName Name of the image

  \param imageBundle Bundle of the image

  \param canPerform Function to determine if the activity can be shown. Default is true.

  \param handler Function to perform activity when selected by the user.


  returns:
  The custom activity
*/
+ (UIActivity * _Nonnull)create:(NSString * _Nonnull)title imageName:(NSString * _Nonnull)imageName imageBundle:(NSBundle * _Nullable)imageBundle canPerform:(BOOL (^ _Nullable)(NSArray * _Nonnull))canPerform handler:(void (^ _Nonnull)(void))handler;
@end


@interface UIAlertAction (SWIFT_EXTENSION(ZamzamKit))
- (nonnull instancetype)initWithTitle:(NSString * _Nonnull)title handler:(void (^ _Nonnull)(void))handler;
@end

@class UIMutableUserNotificationAction;
@class UILocalNotification;
@class UIMutableApplicationShortcutItem;

@interface UIApplication (SWIFT_EXTENSION(ZamzamKit))
- (void)registerUserNotificationSettings:(NSArray<UIMutableUserNotificationAction *> * _Nullable)actions category:(NSString * _Nonnull)category type:(UIUserNotificationType)type;
- (void)removeLocalNotification:(NSString * _Nonnull)identifier;
- (BOOL)hasLocalNotification:(NSString * _Nonnull)identifier;
- (NSArray<UILocalNotification *> * _Nonnull)getLocalNotifications:(NSString * _Nonnull)identifier;
- (void)clearNotificationTray;
/**
  Update existing home short cut.
  \param type Indentifier of shortcut item.

  \param handler Handler which to modify the shortcut item.

*/
- (void)updateShortcutItem:(NSString * _Nonnull)type handler:(SWIFT_NOESCAPE UIMutableApplicationShortcutItem * _Nonnull (^ _Nonnull)(UIMutableApplicationShortcutItem * _Nonnull))handler;
@end


@interface UIBarButtonItem (SWIFT_EXTENSION(ZamzamKit))
/**
  Initializes a UIBarButtonItem with an image more conveniently.
  \param imageName Image name.

  \param target Target of the context.

  \param action Action to trigger.

  \param bundleIdentifier Identifier of the bundle.


  returns:
  An initialized UIBarButtonItem.
*/
- (nonnull instancetype)initWithImageName:(NSString * _Nonnull)imageName target:(id _Nullable)target action:(SEL _Nonnull)action bundleIdentifier:(NSString * _Nullable)bundleIdentifier;
@end

@class UICollectionViewCell;

@interface UICollectionView (SWIFT_EXTENSION(ZamzamKit))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull defaultCellIdentifier;)
+ (NSString * _Nonnull)defaultCellIdentifier;
/**
  Register NIB to table view. NIB name and cell reuse identifier can match for convenience.
  \param nibName Name of the NIB.

  \param cellIdentifier Name of the reusable cell identifier.

  \param bundleIdentifier Name of the bundle identifier if not local.

*/
- (void)registerNib:(NSString * _Nonnull)nibName cellIdentifier:(NSString * _Nonnull)cellIdentifier bundleIdentifier:(NSString * _Nullable)bundleIdentifier;
- (UICollectionViewCell * _Nonnull)objectForKeyedSubscript:(NSIndexPath * _Nonnull)indexPath;
@end

@class UIColor;
@class UIActivityIndicatorView;

@interface UICollectionViewController (SWIFT_EXTENSION(ZamzamKit))
/**
  Adds activity indicator to the table view.
  http://stackoverflow.com/questions/29912852/how-to-show-activity-indicator-while-tableview-loads

  returns:
  Returns an instance of the activity indicator that is centered.
*/
- (UIActivityIndicatorView * _Nonnull)setupActivityIndicator:(UIActivityIndicatorViewStyle)viewStyle color:(UIColor * _Nonnull)color;
@end


@interface UIColor (SWIFT_EXTENSION(ZamzamKit))
/**
  An additional convenience initializer function that allows to init a UIColor object using a hex color value.
  <ul>
    <li>
      param: RGB UInt color hex value (f.e.: 0x990000 for a hex color code like #990000)
    </li>
    <li>
      param: Alpha Double Optional value that sets the alpha range 0=invisible / 1=totally visible.
    </li>
  </ul>
*/
- (nonnull instancetype)initWithHex:(uint32_t)hex alpha:(double)alpha;
/**
  An additional convenience initializer function that allows to init a UIColor object using a RGB string.
  \param rgb A string of integers representing the RGB colors.

  \param alpha Alpha Double Optional value that sets the alpha range 0=invisible / 1=totally visible.

*/
- (nonnull instancetype)initWithRgb:(NSString * _Nullable)rgb alpha:(double)alpha;
/**
  Returns the inverse color
*/
@property (nonatomic, readonly, strong) UIColor * _Nonnull inverseColor;
@end


@interface UIImage (SWIFT_EXTENSION(ZamzamKit))
/**
  Convenience initializer to handle default parameter value
  \param named The name of the image.

  \param inBundle The bundle containing the image file or asset catalog. Specify nil to search the app’s main bundle.


  returns:
  The image object.
*/
- (nullable instancetype)initWithNamed:(NSString * _Nonnull)named inBundle:(NSBundle * _Nullable)inBundle;
/**
  Shorthand for always draw the original image, without treating it as a template.
*/
@property (nonatomic, readonly, strong) UIImage * _Nonnull original;
/**
  Shorthand for always draw the image as a template image, ignoring its color information.
*/
@property (nonatomic, readonly, strong, getter=template) UIImage * _Nonnull template_;
@end


@interface UIImageView (SWIFT_EXTENSION(ZamzamKit))
- (void)setProgressAnimation:(NSString * _Nonnull)imageName totalImages:(NSInteger)totalImages percent:(double)percent duration:(double)duration;
@end


@interface UILocalNotification (SWIFT_EXTENSION(ZamzamKit))
@end


@interface UIStoryboard (SWIFT_EXTENSION(ZamzamKit))
/**
  Creates and returns a storyboard object for the specified storyboard resource file in the main bundle of the current application.
  \param name The name of the storyboard resource file without the filename extension.


  returns:
  A storyboard object for the specified file. If no storyboard resource file matching name exists, an exception is thrown.
*/
- (nonnull instancetype)initWithName:(NSString * _Nonnull)name;
@end

@class UITableViewCell;

@interface UITableView (SWIFT_EXTENSION(ZamzamKit))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull defaultCellIdentifier;)
+ (NSString * _Nonnull)defaultCellIdentifier;
/**
  Register NIB to table view. NIB name and cell reuse identifier can match for convenience.
  \param nibName Name of the NIB.

  \param cellIdentifier Name of the reusable cell identifier.

  \param bundleIdentifier Name of the bundle identifier if not local.

*/
- (void)registerNib:(NSString * _Nonnull)nibName cellIdentifier:(NSString * _Nonnull)cellIdentifier bundleIdentifier:(NSString * _Nullable)bundleIdentifier;
- (UITableViewCell * _Nonnull)objectForKeyedSubscript:(NSIndexPath * _Nonnull)indexPath;
@end

@class UIFont;

@interface UITableViewController (SWIFT_EXTENSION(ZamzamKit))
/**
  Adds activity indicator to the table view.
  http://stackoverflow.com/questions/29912852/how-to-show-activity-indicator-while-tableview-loads

  returns:
  Returns an instance of the activity indicator that is centered.
*/
- (UIActivityIndicatorView * _Nonnull)setupActivityIndicator:(UIActivityIndicatorViewStyle)viewStyle color:(UIColor * _Nonnull)color;
/**
  Adds refresh control for pull to refresh functionality.
  \param action Action to trigger for reload.

  \param title Title of the refresh title.

  \param font Font of the title.

  \param color Color of the title.

*/
- (void)setupRefreshControl:(SEL _Nonnull)action title:(NSString * _Nonnull)title font:(UIFont * _Nonnull)font color:(UIColor * _Nonnull)color;
@end


@interface UIView (SWIFT_EXTENSION(ZamzamKit))
@property (nonatomic) CGFloat height;
@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat x;
@property (nonatomic) CGFloat y;
@end


@interface UIViewController (SWIFT_EXTENSION(ZamzamKit))
/**
  Display an alert action in a convenient way.
  \param message Body of the alert.

  \param title Title of the alert.

  \param buttonTitle Text for the button.

  \param additionalActions Array of alert actions.

  \param handler Call back handler when main action tapped.

*/
- (void)presentAlert:(NSString * _Nonnull)title message:(NSString * _Nullable)message buttonText:(NSString * _Nonnull)buttonText additionalActions:(NSArray<UIAlertAction *> * _Nullable)additionalActions preferredStyle:(UIAlertControllerStyle)preferredStyle includeCancelAction:(BOOL)includeCancelAction handler:(void (^ _Nullable)(void))handler;
/**
  Open Safari view controller overlay.
  \param url URL to display in the browser.

  \param modalPresentationStyle The presentation style of the model view controller.

*/
- (void)presentSafariController:(NSString * _Nonnull)url modalPresentationStyle:(UIModalPresentationStyle)modalPresentationStyle;
/**
  Adds status bar background with color instead of being transparent.
  \param backgroundColor Background color of status bar.

*/
- (UIView * _Nonnull)addStatusBar:(UIColor * _Nonnull)backgroundColor;
/**
  Adds status bar background with light or dark mode.
  \param darkMode Light or dark mode color of status bar.

*/
- (UIView * _Nonnull)addStatusBarWithDarkMode:(BOOL)darkMode;
/**
  Presents an activity view controller modally that you can use to offer various services from your application.
  \param activityItems The array of data objects on which to perform the activity. The type of objects in the array is variable and dependent on the data your application manages.

  \param sourceView The view containing the anchor rectangle for the popover for supporting iPad device.

  \param applicationActivities An array of UIActivity objects representing the custom services that your application supports.

*/
- (void)presentActivityViewController:(NSArray * _Nonnull)activityItems sourceView:(UIView * _Nonnull)sourceView applicationActivities:(NSArray<UIActivity *> * _Nullable)applicationActivities;
/**
  Presents an activity view controller modally that you can use to offer various services from your application.
  \param activityItems The array of data objects on which to perform the activity. The type of objects in the array is variable and dependent on the data your application manages.

  \param barButtonItem The bar button item containing the anchor rectangle for the popover for supporting iPad device.

  \param applicationActivities An array of UIActivity objects representing the custom services that your application supports.

*/
- (void)presentActivityViewController:(NSArray * _Nonnull)activityItems barButtonItem:(UIBarButtonItem * _Nonnull)barButtonItem applicationActivities:(NSArray<UIActivity *> * _Nullable)applicationActivities;
@end


@interface NSUserDefaults (SWIFT_EXTENSION(ZamzamKit))
/**
  Stores the updated values from the dictionary to the user defaults.
  \param values The user default keys and values.

*/
- (void)update:(NSDictionary<NSString *, id> * _Nonnull)values;
/**
  Adds the registrationDictionary to the last item in every search list. This means that after NSUserDefaults has looked for a value in every other valid location, it will look in registered defaults, making them useful as a “fallback” value. Registered defaults are never stored between runs of an application, and are visible only to the application that registers them.
  \param registrationDictionary Values for user defaults.

  \param plistName property list where defaults are declared

  \param bundle bundle where defaults reside

*/
- (void)registerDefaults:(NSString * _Nonnull)plistName inDirectory:(NSString * _Nullable)inDirectory bundle:(NSBundle * _Nullable)bundle;
@end

#pragma clang diagnostic pop