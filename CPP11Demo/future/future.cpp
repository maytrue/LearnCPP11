//
//  main.cpp
//  CPP11Demo
//
//  Created by guowei on 09/12/2017.
//  Copyright © 2017 MOMO. All rights reserved.
//

#include <iostream>
#include <future>

int main(int argc, const char * argv[]) {
    
    std::future<int> f1 = std::async(std::launch::async, []() {
        return 8;
    });
    std::cout << f1.get() << std::endl;

    auto f2 = std::async(std::launch::async, []() {
        std::cout << "hello world" << std::endl;
    });
    
    f2.wait();
    
    auto f3 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "sleep end" << std::endl;
    });
    
    std::cout << "waiting thread" << std::endl;
    
    std::future_status status;
    do {
        status = f3.wait_for(std::chrono::seconds(1));
        
        if (status == std::future_status::deferred) {
            std::cout << "deferred" << std::endl;
        } else if (status == std::future_status::timeout) {
            std::cout << "timeout" << std::endl;
        } else if (status == std::future_status::ready) {
            std::cout << "ready" << std::endl;
        } else {
            
        }
    } while (status != std::future_status::ready);
    
    return 0;
}
