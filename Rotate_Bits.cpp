#include <bitset>
#include <iostream>
using namespace std;

unsigned int rotateLeft(unsigned int x, unsigned int k) {
    const unsigned int WIDTH = 32;
    k %= WIDTH;
    if (k == 0) return x;
    bitset<32> b(x);
    bitset<32> left = (b << k);
    bitset<32> right = (b >> (WIDTH - k));
    bitset<32> res = left | right;
    return (unsigned int)res.to_ulong();
}

int main() {
    unsigned int n;
    unsigned int k;
    cout << "Enter number and rotate-by (k): ";
    cin >> n >> k;
    cout << "Before: " << bitset<32>(n) << '\n';
    unsigned int r = rotateLeft(n, k);
    cout << "After : " << bitset<32>(r) << '\n';
    cout << "Decimal: " << r << '\n';
    return 0;
}
