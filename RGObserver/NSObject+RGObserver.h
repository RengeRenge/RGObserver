//
//  NSObject+RGObserver.h
//  RGUIKit
//
//  Created by renge on 2019/8/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 
 ┌───────────┐         ┌───────────┐
 │ Concubine │ ┄ ┄ ┄ ⇢ │ Concubine │
 │           │ ⇠ ┄ ┄ ┄ │           │
 └───────────┙         └───────────┙
    ┇   ↑                  ┇  ↑
    ┇   | (retain)         ┇  | (retain)
    ⇣   |                  ⇣  |
 ┌───────────┐         ┌───────────┐
 │  Target   │         │ Observer  │
 │           │         │           │
 └───────────┙         └───────────┙
 
 1.use run time to associate Target with Concubine1 (reatin)
 2.use run time to associate Observer with Concubine2 (reatin)
 3.Concubine record the Target and Observer (unsafe_unretained)
 4.Concubine record other Concubine (weak)
 
 */

@interface NSObject(RGObserver)

/**
 auto remove KVO when dealloc
 */
- (void)rg_addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;


/**
 remove KVO
 */
- (void)rg_removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;

@end

NS_ASSUME_NONNULL_END
