#include <bitset>
#include <iostream>
using namespace std;

unsigned int xorWithoutCaret(unsigned int a, unsigned int b) {
    bitset<32> A(a), B(b);
    bitset<32> result = (A | B) & ~(A & B);
    return (unsigned int)result.to_ulong();
}

int main() {
    unsigned int a, b;
    cout << "Enter two numbers (a b): ";
    if (!(cin >> a >> b)) return 0;
    cout << "Using bitset expression a XOR b = " << xorWithoutCaret(a, b) << '\n';
    cout << "Expected (a ^ b) = " << (a ^ b) << '\n';
    return 0;
}
