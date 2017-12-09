//
//  sp.cpp
//  CPP11Demo
//
//  Created by guowei on 09/12/2017.
//  Copyright © 2017 MOMO. All rights reserved.
//

#include <iostream>

class Base
{
public:
    Base() {
        std::cout << __func__ << std::endl;
    }
    
    ~Base() {
        std::cout << __func__ << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived() {
        std::cout << __func__ << std::endl;
    }
    
    ~Derived() {
        std::cout << __func__ << std::endl;
    }
};

int main(int argc, char* argv[])
{
    std::shared_ptr<Base> ptr = std::make_shared<Derived>();
    
    std::cout << "Created shared derived ptr\n"
    << " p.get() = " << ptr.get()
    << " , count() = " << ptr.use_count()
    << std::endl;
    return 0;
}
