#include <bitset>
#include <iostream>
using namespace std;

int countLeadingZeros(unsigned int x) {
    if (x == 0) return 32;
    bitset<32> b(x);
    int cnt = 0;
    for (int i = 31; i >= 0; --i) {
        if (b.test(i)) break;
        ++cnt;
    }
    return cnt;
}

int main() {
    unsigned int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Binary: " << bitset<32>(n) << '\n';
    cout << "Leading zeros: " << countLeadingZeros(n) << '\n';
    return 0;
}