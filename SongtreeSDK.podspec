
Pod::Spec.new do |s|

s.name         = "SongtreeSDK"
s.version      = "0.0.6"
s.summary      = "Songtree SDK for iOS"

s.description  = "Songtree is an online community for collaborative music making"

s.homepage     = "https://github.com/SongtreeSDK/Songtree"

s.license      = { :type => "Apache License, Version 2.0" , :file =>"License" }


s.author             = "Songtree"
s.platform     = :ios, "7.0"

s.source       = { :git => "https://github.com/SongtreeSDK/Songtree.git", :tag => "0.0.6" }


s.resource  = "SongtreeBundle.bundle"
s.vendored_frameworks = "SongtreeSDK.framework"
s.library = 'c++'


s.frameworks = "AssetsLibrary", "MessageUI", "Social", "SystemConfiguration", "CFNetwork", "CoreData", "CoreMedia", "AVFoundation", "CoreLocation", "AddressBook", "CoreMotion", "Twitter", "MediaPlayer"

s.dependency 'NXOAuth2Client', '~> 1.2.0'
s.dependency 'FBSDKCoreKit', '~> 4.6'
s.dependency 'FBSDKLoginKit', '~> 4.6'
s.dependency 'FBSDKShareKit', '~> 4.6'
s.dependency 'google-plus-ios-sdk', '~> 1.7'
end
