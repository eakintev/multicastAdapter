#include<iostream>
//  add -lws2_32 to build
#include<boost/any.hpp>

int main()
{
    boost::any a(5);
    a = 7.67;
    std::cout<<boost::any_cast<double>(a)<<std::endl;
}