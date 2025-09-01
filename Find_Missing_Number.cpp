#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

unsigned int findMissingNumber(const vector<unsigned int>& arr) {
    bitset<32> acc(0);
    unsigned int n = (unsigned int)arr.size();
    for (unsigned int i = 0; i <= n; ++i) acc ^= bitset<32>(i);
    for (unsigned int v : arr) acc ^= bitset<32>(v);
    return (unsigned int)acc.to_ulong();
}

int main() {
    cout << "Enter number of elements in array : ";
    size_t n;
    if (!(cin >> n)) return 0;
    cout << "Enter " << n << " distinct numbers from range 0.." << n << " with one missing:\n";
    vector<unsigned int> arr;
    arr.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned int v; cin >> v;
        arr.push_back(v);
    }
    cout << "Missing number is: " << findMissingNumber(arr) << '\n';
    return 0;
}
