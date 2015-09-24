/*
SongtreeController.h
Created by Flavio Antonioli on 05/08/15.

SONGTREE FRAMEWORK INSTRUCTIONS
1)Include Framework Header #import <SongtreeSDK/SongtreeController.h>

2)Instantiate the SongtreeController in your main UIViewController
SongtreeController  *controller=[SongtreeController instance];
controller.delegate=yourViewController;
controller.appAgent=@"your app name";

3)Implement the mandatory delegate method
-(bool)importAudioFile:songID:fromViewController:
-(NSString *)getParentId
-(void)OnSongUploadRequested:fromView:parameters:

4)Use the SongtreeController method to show the Community, open the Share View and upload your audio file:
-(void)openSongtreeCommunity:
-(void)OpenUploadPage:
-(void)uploadToSongtree:parameters:parentViewController:

5)Download OAuth2Client framework and add it to your project
https://github.com/nxtbgthng/OAuth2Client
 
6)To enable FACEBOOK login follow this guide https://developers.facebook.com/docs/ios/getting-started
 - Download Facebook SDK
 - Create a Facebook App
 - Configure Facebook App Settings for iOS
 - Add the SDK to your Xcode Project
 - Configure Xcode Project
 
7)To enable GOOGLE Plus Login follow this guide https://developers.google.com/+/mobile/ios/getting-started
 - Create your project on Google Developers Console
 - Add to your XCode project Google Plus frameworks and in your main UIViewController set
	[SongtreeController instance].googlePlusClientID = @"YOUR_CLIENT_ID”;
 
 - Add into your app plist a new URL type with your app bundle ID
 
 NOTES ON THE UPLOAD PROCESS:
 - the host app calls OpenUploadPage:
 - the user enters the song's metadata (BPM, key, song title, etc.) and clicks "Upload"
 - Songtree SDK calls OnSongUploadRequested:fromView:parameters:
 - the host app creates the song mixdown file in m4a format (possibly showing a progress indication during the process)
 - the host app invokes uploadToSongtree:parameters:parentViewController: with the path of the newly created mixdown file
*/


#ifndef n_Track_iOS_SongtreeController_h
#define n_Track_iOS_SongtreeController_h

@class UIViewController;
@class UIView;
@class SongboxProgress;

//After upload you can choose to open Songtree community on the User Account page (Default), or show a popup with the link to the song just uploaded, or do nothing.
typedef enum {
    kST_ShowMySongs = 0,
    kST_ShowClipboard,
    kST_DoNothing
} STPostUploadBehaviour;

@protocol SongtreeDelegateProtocol

//Called when some error in the Comminity happens
-(void)showErrorMessage:(NSString *)errorString fromView: (UIView *)fromView;

//When a user download a song from the Songtree Community this method returns the path to the audio file in your device folder and the related song ID. The songID must be saved and returned in the following method getParentID.
-(bool)importAudioFile: (NSString *)filePath songID:(NSString*)songID fromViewController: (UIViewController *)fromViewController;

//Use this to get the BPM and the other tempo info about the audio file downloaded
-(void)setBpmFromImportedSong: (int)bpm1000 tempoSubdivisions:(int)num tempoDivisor: (int)den;

//Must return the parent song ID saved after the import from importAudioFile:songID:fromViewController:
-(NSString*)getParentId;

//This method is called when user clicks on the Upload button inside the Share View.
//You must pass the path to your mixdown m4a audio file to the SongtreeController with:
//uploadToSongtree:parameters:parentViewController:;
-(void)OnSongUploadRequested: (NSString *)songName fromView: (UIView *)theView parameters: (NSDictionary *)parameters;

@optional
-(void)loginInfoUpdated;
-(void)checkSpinningWheel;
-(void)initializeMainApp;
-(void)addProgressView:(UIView *)theView fromView:(UIView *)myView;
-(void)onCommunityViewAppeared;
-(void)onCommunityViewDisappeared;
-(void)OnUploadFinished;
-(void)switchToMainApp:(UIViewController *)songtreeViewController;
-(void)SetApplicationBadgeValue:(int)value;
@end

@interface SongtreeController : NSObject 
{
    
}
@property (retain) id <SongtreeDelegateProtocol> delegate;
@property (nonatomic, retain) NSString *appAgent;
@property (nonatomic, assign) STPostUploadBehaviour postUploadBehaviour;
@property (nonatomic,assign) BOOL debugMode;
@property (nonatomic,assign) int currentCommunitySection;
@property (nonatomic, retain) SongboxProgress *songboxProgressView;

//Login with Social Account (Optional)
@property (nonatomic, retain) NSString *googlePlusClientID;
@property (nonatomic, retain) NSString *facebookClientID;

//Open the Songtree Main page
-(void)openSongtreeCommunity:(UIViewController*)parentViewController;
//Close Songtree main view controller
-(void)CloseSongtreeCommunity;

//Open the Upload Page
-(void)OpenUploadPage:(UIViewController*)parentViewController;
//Use this to pass the m4a audio file path to upload
-(void)uploadToSongtree:(NSString *)path parameters:(NSDictionary *)parameters parentViewController:(UIViewController*)parentViewController;

+(SongtreeController *)instance;
+(NSBundle *)bundleHandle;
@end

#endif
