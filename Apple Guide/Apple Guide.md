## Basic Guides

### [Framework Programming Guide](https://developer.apple.com/library/content/documentation/MacOSX/Conceptual/BPFrameworks/Frameworks.html#//apple_ref/doc/uid/10000183-SW1)



### [Understanding and Analyzing Application Crash Reports](https://developer.apple.com/library/content/technotes/tn2151/_index.html)

1. Thread 0是主线程 [1](https://stackoverflow.com/questions/38962155/is-thread-0-always-the-main-thread-in-an-ios-crash-report)

2. Crash报告和符号化流程，如下

<img src="images/01 - Crash报告和符号化流程.png" width="512"/>


3. asdfasd


4. sdfadf

### [iOS Debugging Magic](https://developer.apple.com/library/content/technotes/tn2239/_index.html#//apple_ref/doc/uid/DTS40010638-CH1-SUBSECTION21)

* `DYLD_PRINT_LIBRARIES`

```
dyld: loaded: /Users/wesley_chen/Library/Developer/CoreSimulator/Devices/3F4F7973-FCBE-4FBB-BC3B-3D7A3D1F22D4/data/Containers/Bundle/Application/197BB56C-718A-44C9-8783-59D3BEAD4801/HelloFramework.app/HelloFramework
dyld: loaded: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/usr/lib/libBacktraceRecording.dylib
dyld: loaded: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator10.3.sdk/Developer/Library/PrivateFrameworks/DTDDISupport.framework/libViewDebuggerSupport.dylib
...
```

### [Bundle Programming Guide](https://developer.apple.com/library/content/documentation/CoreFoundation/Conceptual/CFBundles/Introduction/Introduction.html#//apple_ref/doc/uid/10000123i-CH1-SW1)

