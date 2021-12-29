//
//  ViewController.m
//  PocoDemo
//
//  Created by Anton Katekov on 2021/12/24.
//

#import "ViewController.h"
#include "Socket.hpp"


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        Socket s;
        s.Send();
    });
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
