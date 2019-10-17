//
//  PoporFFmpegCommand.h
//  PoporFFmpegCommand
//
//  Created by apple on 2019/2/14.
//  Copyright © 2019 popor. All rights reserved.
//

#import <UIKit/UIKit.h>

#if __has_include(<mobileffmpeg/MobileFFmpegConfig.h>)
#define HasMobileffmpeg 1


#else
#define HasMobileffmpeg 0

#endif

/*
 1. 由于github不推荐超过100MB的framework，所以推荐用户自己pod引入。而且cocoapods老说RETURN_CODE_SUCCESS有问题。
 推荐使用3.1，4.2貌似有问题。3.1已经开始x264，压制的视频可以再chrome等浏览器上播放。
 pod 'mobile-ffmpeg-full', '3.1'
 
 2. 由于framework无法正确执行
 #if __has_include(<mobileffmpeg/MobileFFmpegConfig.h>) #define HasMobileffmpeg 1 #else #define HasMobileffmpeg 0 #endif
 所以需要在案例中补全下面函数
 
 */

/*
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
 
 */

@interface PoporFFmpegCommand : NSObject

// 只支持本地路径或者本地URL
+ (NSString * _Nullable)ffmpegCommand_VideoPath:(NSString * _Nonnull)videoPath tSize:(CGSize)tSize tPath:(NSString * _Nonnull)tPath;

#pragma mark - tool
+ (CGSize)sizeFrom:(CGSize)originSize targetSize:(CGSize)targetSize;
+ (CGSize)videoSizeFromPath:(NSString * _Nonnull)path;

@end
