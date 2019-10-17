# PoporFFmpegCommand

[![CI Status](https://img.shields.io/travis/wangkq/PoporFFmpegCommand.svg?style=flat)](https://travis-ci.org/wangkq/PoporFFmpegCommand)
[![Version](https://img.shields.io/cocoapods/v/PoporFFmpegCommand.svg?style=flat)](https://cocoapods.org/pods/PoporFFmpegCommand)
[![License](https://img.shields.io/cocoapods/l/PoporFFmpegCommand.svg?style=flat)](https://cocoapods.org/pods/PoporFFmpegCommand)
[![Platform](https://img.shields.io/cocoapods/p/PoporFFmpegCommand.svg?style=flat)](https://cocoapods.org/pods/PoporFFmpegCommand)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

PoporFFmpegCommand is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'PoporFFmpegCommand'


#import <PoporFFmpegCommand/PoporFFmpegCommand.h>
#import <mobileffmpeg/MobileFFmpegConfig.h>
#import <mobileffmpeg/MobileFFmpeg.h>

+ (void)executeCommand:(NSString * _Nonnull)ffmpegCommand finish:(void (^ __nullable)(BOOL executeFinish))finish {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        //NSLog(@"FFmpeg process started with arguments\n\'%@\'\n", ffmpegCommand);
        int result = [MobileFFmpeg execute:ffmpegCommand];
        //NSLog(@"FFmpeg process exited with rc %d\n", result);
        dispatch_async(dispatch_get_main_queue(), ^{
            if (result == RETURN_CODE_SUCCESS) {
                if (finish) {
                    finish(YES);
                }
            } else {
                if (finish) {
                    finish(NO);
                }
            }
        });
    });
}

```

## Author

wangkq, 908891024@qq.com

## License

PoporFFmpegCommand is available under the MIT license. See the LICENSE file for more info.
