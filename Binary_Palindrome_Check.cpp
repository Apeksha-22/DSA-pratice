#include <bitset>
#include <iostream>
using namespace std;

bool isBinaryPalindrome(unsigned int x) {
    if (x == 0) return true;
    bitset<32> b(x);
    int high = -1;
    for (int i = 31; i >= 0; --i) if (b.test(i)) { high = i; break; }
    for (int i = 0; i <= high / 2; ++i)
        if (b.test(i) != b.test(high - i)) return false;
    return true;
}

int main() {
    unsigned int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    cout << "Binary: " << bitset<32>(n) << '\n';
    cout << (isBinaryPalindrome(n) ? "Palindrome" : "Not palindrome") << '\n';
    return 0;
}
