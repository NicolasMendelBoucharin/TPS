#include <iostream>
#include "../include/qq.h"

int main() {
    qq r(1, 4);
    double result = r + 0.5;
    std::cout << "1/4 + 0.5 = " << result << std::endl;
    std::cout << "Expected: 0.75" << std::endl;
    return 0;
}
