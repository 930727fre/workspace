#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n, a1, a2, a3;
    int b1, b2, b3;
    string str;
    
    cin >> str;

    // Using stringstream to parse comma-separated values
    istringstream iss(str);
    char delimiter = ',';
    
    string token;
    getline(iss, token, delimiter);
    n = stoi(token);

    getline(iss, token, delimiter);
    a1 = stoi(token);

    getline(iss, token, delimiter);
    a2 = stoi(token);

    getline(iss, token, delimiter);
    a3 = stoi(token);

    if (n < a1 * 15 + a2 * 20 + a3 * 30) {
        cout << "0\n";
        return 0;
    } else {
        n -= a1 * 15 + a2 * 20 + a3 * 30;
        b3 = n / 50;
        n %= 50;
        b2 = n / 5;
        n %= 5;
        b1 = n;

        cout << b1 << "," << b2 << "," << b3 << "\n";
    }

    return 0;
}
