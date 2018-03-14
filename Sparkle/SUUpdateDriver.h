//
//  SUUpdateDriver.h
//  Sparkle
//
//  Created by Andy Matuschak on 5/7/08.
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#ifndef SUUPDATEDRIVER_H
#define SUUPDATEDRIVER_H

#import <Cocoa/Cocoa.h>
#import "SUConstants.h"

extern NSString *const SUUpdateDriverFinishedNotification;

@class SUHost, SUUpdater;
@interface SUUpdateDriver : NSObject <NSURLDownloadDelegate>

@property (readonly, weak) SUUpdater *updater;
@property (strong) SUHost *host;

- (instancetype)initWithUpdater:(SUUpdater *)updater;
- (void)checkForUpdatesAtURL:(NSURL *)URL host:(SUHost *)host;
- (void)abortUpdate:(SUUpdateAbortReason)reason;

- (void)showAlert:(NSAlert *)alert;

@property (getter=isInterruptible, readonly) BOOL interruptible;
@property (readonly) BOOL finished;
@property BOOL automaticallyInstallUpdates;
@property (readonly) SUUpdateAbortReason abortReason;

@property (nonatomic, readonly) BOOL shouldShowUI; // can change it's value during lifetime

@end

#endif
