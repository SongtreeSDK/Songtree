# Songtree SDK

Songtree is an online community for collaborative music-making.
Each time a user adds to a track, another branch gets added to the song’s “tree”, allowing users to create different versions of the same track within the same project.
With Songtree SDK you can simply import into your music app a backing track created from any user and overdub it; then you can upload the mixdown back to Songtree community and watch the song grows.

## Setup

1)Include Framework Header 
<pre>
#import &lt;SongtreeSDK/SongtreeController.h&gt;
</pre>

2)Instantiate the SongtreeController in your main UIViewController
<pre>
SongtreeController  *controller=[SongtreeController instance];
controller.delegate=yourViewController;
controller.appAgent=@"your app name";
</pre>

3)Implement the mandatory delegate method
<pre>
-(bool)importAudioFile:songID:fromViewController:
-(NSString *)getParentId
-(void)OnSongUploadRequested:fromView:parameters:
</pre>

4)Use the SongtreeController method to show the Community, open the Share View and upload your audio file:
<pre>
-(void)openSongtreeCommunity:shareAfterUpload:fromViewController:
-(void)OpenUploadPage:
-(void)uploadToSongtree:parameters:parentViewController:
</pre>

## External dependencies (Not needed if you use CocoaPods)
5)Download OAuth2Client framework and add it to your project
https://github.com/nxtbgthng/OAuth2Client

## CocoaPods
<pre>pod 'SongtreeSDK', '~> 0.0'</pre>
