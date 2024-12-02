#include <iostream>
#include <string>
#include <cmath>
	

#include "calculator.h"
using namespace std::literals;

const auto err_not_num = "Error: Numeric operand expected"s;

/*Переменные*/

Number accu1 = 0, accu2 = 0, memory = 0;
bool IsMemoryStored = false;

/*Функции*/

bool ReadNumber(Number& result) {

    if (std::cin >> result) {     
        return 1;}
    else {
        std::cerr << err_not_num << std::endl;
        return 0;}
}


bool RunCalculatorCycle() {
    if (!(ReadNumber(accu1)))  {
        return 0;
    } else {
        
        std::string argument;
            while(std::cin >> argument) {
                
                if (argument == "+"s) {
                    if (!(ReadNumber(accu2))) break; 
                    accu1 += accu2;
                } else if (argument == "-"s) {
                    if (!(std::cin >> accu2)) break;
                    accu1 -= accu2;
                } else if (argument == "*"s) {
                    if (!(ReadNumber(accu2))) break;
                    accu1 *= accu2;
                } else if (argument == "/"s) {
                    if (!(ReadNumber(accu2))) break;
                    accu1 /= accu2;
                } else if (argument == "**"s) {
                    if (!(ReadNumber(accu2))) break;
                    accu1 = std::pow(accu1, accu2);
                } else if (argument == "="s) {
                    std::cout << accu1 << std::endl;
                } else if (argument == "c"s) {
                    accu1 = 0;
                } else if (argument == ":"s) {
                    if (!(ReadNumber(accu1))) break;

                } else if (argument == "s"s) {
                    memory = accu1;
                    IsMemoryStored = 1;
                } else if (argument == "l"s) { 
                    if (!IsMemoryStored) std::cerr << "Error: Memory is empty";
                    else accu1 = memory;
                } else if (argument == "q"s) {
                    break;
                } else {
                    std::cerr << "Error: Unknown token "s << argument << std::endl;
                    break;
                }
            }    
    }  
    
   
    return 1;
}