# Songtree SDK

Songtree is an online community for collaborative music-making.
Each time a user adds to a track, another branch gets added to the song’s “tree”, allowing users to create different versions of the same track within the same project.
With Songtree SDK you can simply import into your music app a backing track created from any user and overdub it; then you can upload the mixdown back to Songtree community and watch the song grows.

## Setup

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
-(void)openSongtreeCommunity:shareAfterUpload:fromViewController:
-(void)OpenUploadPage:
-(void)uploadToSongtree:parameters:parentViewController:


## External dependencies (Not needed if you use CocoaPods)
5)Download OAuth2Client framework and add it to your project
https://github.com/nxtbgthng/OAuth2Client

