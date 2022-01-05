//
//  ViewController.m
//  PocoDemoIOS
//
//  Created by Anton Katekov on 2021/12/24.
//

#import "ViewController.h"
#include "Socketios.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        Socketios s;
        s.Send();
        int a = 0;
        a++;
    });
}


@end
