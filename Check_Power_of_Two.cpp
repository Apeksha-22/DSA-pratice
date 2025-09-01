#include <bitset>
#include <iostream>
using namespace std;

bool isPowerOfTwo(unsigned int x) {
    if (x == 0) return false;
    bitset<32> b(x);
    return b.count() == 1;
}

int main() {
    unsigned int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    cout << n << (isPowerOfTwo(n) ? " is " : " is not ") << "a power of two\n";
    return 0;
}
