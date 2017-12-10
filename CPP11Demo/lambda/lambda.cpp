//
//  lambda.cpp
//  CPP11Demo
//
//  Created by guowei on 09/12/2017.
//  Copyright © 2017 MOMO. All rights reserved.
//

#include <iostream>

int main(int argc, char *argv[])
{
    int a = 0;
    auto f1 = [=] {
        return a;
    };
    a += 1;
    std::cout << f1() << std::endl;
    
    return 0;
}

