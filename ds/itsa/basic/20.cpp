#include <iostream>
#include <cstring>
#include <algorithm> // Include the algorithm header for std::reverse

#define MAX_DIGITS 31

// Function to add two large integers
void addLargeIntegers(std::string num1, std::string num2, std::string& result) {
    int carry = 0;
    int len1 = num1.length();
    int len2 = num2.length();
    int maxLength = std::max(len1, len2); // Determine the maximum length of the two numbers

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < len1) ? (num1[len1 - i - 1] - '0') : 0; // Extract individual digits from the strings
        int digit2 = (i < len2) ? (num2[len2 - i - 1] - '0') : 0;

        int sum = digit1 + digit2 + carry; // Calculate the sum of digits and the carry from the previous iteration
        result += (sum % 10) + '0'; // Append the current digit to the result string
        carry = sum / 10; // Update the carry for the next iteration
    }

    if (carry > 0) {
        result += carry + '0'; // If there is a carry after the loop, append it to the result
    }

    // Reverse the result string to obtain the correct order
    std::reverse(result.begin(), result.end());
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::string num1, num2, result;
        std::cin >> num1 >> num2;

        // Call the addLargeIntegers function to perform the addition
        addLargeIntegers(num1, num2, result);

        // Output the result for each test case
        std::cout << result << std::endl;
    }

    return 0;
}
