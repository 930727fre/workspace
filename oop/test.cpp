#include <iostream>

void foo(int x, double y) {
    std::cout << "foo(int, double)" << std::endl;
}

void foo(double x, int y) {
    std::cout << "foo(double, int)" << std::endl;
}

int main() {
    std::cout<<[1]<<endl;
    return 0;
}
