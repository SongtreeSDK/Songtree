//
//  ViewController.h
//  SongtreeSDKTest
//
//  Created by Flavio Antonioli on 31/07/15.
//  Copyright (c) 2015 Songtree S.r.l. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SongtreeSDK/SongtreeController.h"
@interface ViewController : UIViewController <SongtreeDelegateProtocol>

- (IBAction)OpenSongtreeCommunity:(UIButton *)sender;

- (IBAction)UploadSong:(UIButton *)sender;

- (IBAction)DeleteLinkToParentSong:(UIButton *)sender;
@end

