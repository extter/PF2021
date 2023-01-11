#include "static.h"
#include <iostream>
using numerino = int; //type alias
numerino main (){

std::cout << Complex::GetCounter();
Complex d{};
Complex c{};
std::cout << c.GetCounter();

} 