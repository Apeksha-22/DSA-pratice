#include <bitset>
#include <iostream>
using namespace std;

unsigned int flipAlternateBits(unsigned int x) {
    const unsigned int mask = 0x55555555u;
    bitset<32> b(x);
    bitset<32> m(mask);
    b ^= m;
    return (unsigned int)b.to_ulong();
}

int main() {
    unsigned int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    cout << "Before: " << bitset<32>(n) << '\n';
    unsigned int out = flipAlternateBits(n);
    cout << "After : " << bitset<32>(out) << '\n';
    cout << "Decimal result: " << out << '\n';
    return 0;
}
