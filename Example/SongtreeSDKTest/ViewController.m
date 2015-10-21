//
//  ViewController.m
//  SongtreeSDKTest
//
//  Created by Flavio Antonioli on 31/07/15.
//  Copyright (c) 2015 Songtree S.r.l. All rights reserved.
//

#import "ViewController.h"

#define kParentSongID @"ParentSongID"
SongtreeController *controller;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    //Instantiate Songtree controller
    controller=[SongtreeController instance];
    controller.delegate=self;

    //Your App Name
    controller.appAgent=@"test";
    
//    controller.googlePlusClientID=@"344554389001926";
    controller.facebookClientID=@"344554389001926";

    [SongtreeController instance].showCloseButton=NO;
//    [SongtreeController instance].showStartupPage=NO;
//    [SongtreeController instance].appIcon=[UIImage imageNamed:@"appIcon"];
//    [SongtreeController instance].hideTutorial=YES;
//    [SongtreeController instance].showOnlySongsCreatedByApp=YES;
//    [SongtreeController instance].showLoopsCreatedByApp=YES;
//    [SongtreeController instance].postUploadBehaviour=kST_ShowClipboard;
    
    //YES = DEMO server / NO = PRODUCTION server
#ifdef DEBUG
    controller.debugMode=YES;
#else
    controller.debugMode=NO;
#endif

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)OpenSongtreeCommunity:(UIButton *)sender
{
    [[SongtreeController instance] openSongtreeCommunity:self];
}

- (IBAction)UploadSong:(UIButton *)sender
{
    [[SongtreeController instance] OpenUploadPage:self];
}

- (IBAction)DeleteLinkToParentSong:(UIButton *)sender
{
    //When you delete parent song from your project remember to
    //remove reference to Parent Song ID too
    [[NSUserDefaults standardUserDefaults]removeObjectForKey:kParentSongID];
    [[NSUserDefaults standardUserDefaults]synchronize];
}

#pragma mark SONGTREE DELEGATE METHODS
-(void)showErrorMessage:(NSString *)errorString fromView: (UIView *)fromView
{}
-(bool)importAudioFile:(NSString *)filePath songID:(NSString*)songID fromViewController: (UIViewController *)fromViewController
{
    //Store parent song ID
    [[NSUserDefaults standardUserDefaults]setObject:songID forKey:kParentSongID];
    [[NSUserDefaults standardUserDefaults]synchronize];
    
    //Close Community and return to your view controller
    [[SongtreeController instance] CloseSongtreeCommunity];
    return true;
}
-(void)setBpmFromImportedSong: (int)bpm1000 tempoSubdivisions:(int)num tempoDivisor: (int)den
{
    //Use this to get the parent song tempo info 
}
-(NSString *)getParentId
{
    //MUST return the song parent ID to get the parent info and upload the song in the parent tree
    return [[NSUserDefaults standardUserDefaults]objectForKey:kParentSongID];
}

-(void)OnSongUploadRequested:(NSString *)songName fromView:(UIView *)theView parameters:(NSDictionary *)parameters
{
    //Your mixdown audio file - Should be m4a
    NSString *path=[[NSBundle mainBundle] pathForResource:@"testSong" ofType:@"m4a"];
    
    [[SongtreeController instance] uploadToSongtree:path parameters:parameters parentViewController:self isLoop:NO];
}

@end
