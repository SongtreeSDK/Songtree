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
-(void)openSongtreeCommunity:
-(void)OpenUploadPage:
-(void)uploadToSongtree:parameters:parentViewController:
</pre>

## External dependencies (Not needed if you use CocoaPods)
Download OAuth2Client framework and add it to your project
https://github.com/nxtbgthng/OAuth2Client

## CocoaPods
<pre>pod 'SongtreeSDK', '~> 0.0'</pre>

# LOGIN WITH SOCIAL ACCOUNTS
 Download Facebook SDK v4.6.0 and Google+ iOS SDK and add them to your project.(Not needed if you use CocoaPods)
 
##Login with Facebook
To enable FACEBOOK login follow this guide https://developers.facebook.com/docs/ios/getting-started
 - Create a Facebook App
 - Configure Facebook App Settings for iOS
 - Configure Xcode Project
<pre>	[SongtreeController instance].facebookClientID = @"YOUR_FAEBOOK_APP_ID”;</pre>

 
##Login with Google Plus
To enable GOOGLE Plus Login follow this guide https://developers.google.com/identity/sign-in/ios/sdk/
- Add to your Xcode project Google Plus frameworks and in your main UIViewController set
<pre>	[SongtreeController instance].googlePlusClientID = @"YOUR_GOOGLE_APP_ID”;</pre>
- Get a configuration file on Google Developers Console
- In the Project > Target > Info > URL Types panel, create a new item and paste your REVERSED_CLIENT_ID into the URL Schemes field. You can find your REVERSED_CLIENT_ID in the GoogleService-Info.plist file.
  Also in the Project > Target > Info > URL Types panel, create a new item and type your bundle identifier in the URL Schemes field.


##iOS9 App Transport Security
Add to your plist

    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSExceptionDomains</key>
        <dict>
            <key>songtr.ee</key>
            <dict>
                <key>NSIncludesSubdomains</key>
                <true/>
                <key>NSTemporaryExceptionAllowsInsecureHTTPLoads</key>
                <true/>
                <key>NSTemporaryExceptionMinimumTLSVersion</key>
                <string>TLSv1.1</string>
            </dict>
        </dict>
    </dict>
