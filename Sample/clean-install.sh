rm -rf ~/Library/Caches/CocoaPods
rm -rf Pods
rm -rf ~/Library/Developer/Xcode/DerivedData/*
rm Podfile.lock

pod cache clean 'IDnowSDK' --all

pod deintegrate
pod setup
pod install --repo-update