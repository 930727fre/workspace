#include <iostream>
#include <string>

int main() {
    std::string str;
    char arr[100];
    std::getline(std::cin, str, '?');
    std::cout<<std::cin.peek();
    // std::cin.getline(arr, 80, '?');
    // std::cout<<str<<std::endl;
    // std::cout<<arr<<std::endl;

    return 0;
}
