//
//  PaddleBallAppDelegate.h
//  PaddleBall
//
//  Created by Z2Live QA on 3/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PaddleBallViewController;

@interface PaddleBallAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet PaddleBallViewController *viewController;

@end
