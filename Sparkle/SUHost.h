//
//  SUHost.h
//  Sparkle
//
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SUHost;

@protocol SUHostDelegate <NSObject>

- (BOOL)host:(SUHost *)host shouldGetInfoFromBundleItselfForBundle:(NSBundle *)bundle;

@end

@interface SUHost : NSObject

@property (weak) id<SUHostDelegate> delegate;

@property (strong, readonly) NSBundle *bundle;

- (instancetype)initWithBundle:(NSBundle *)aBundle;
@property (readonly, copy) NSString *bundlePath;
@property (readonly, copy) NSString *name;
@property (readonly, copy) NSString *version;
@property (readonly, copy) NSString *displayVersion;
@property (getter=isRunningOnReadOnlyVolume, readonly) BOOL runningOnReadOnlyVolume;
@property (readonly, copy) NSString *publicDSAKey;
@property (readonly, nonatomic, copy) NSString *publicDSAKeyFileKey;

- (id)objectForInfoDictionaryKey:(NSString *)key;
- (BOOL)boolForInfoDictionaryKey:(NSString *)key;
- (id)objectForUserDefaultsKey:(NSString *)defaultName;
- (void)setObject:(id)value forUserDefaultsKey:(NSString *)defaultName;
- (BOOL)boolForUserDefaultsKey:(NSString *)defaultName;
- (void)setBool:(BOOL)value forUserDefaultsKey:(NSString *)defaultName;
- (id)objectForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
@end
