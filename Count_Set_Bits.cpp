#include<iostream>
#include<bitset>
using namespace std;

int count(unsigned int n){
    bitset<32> b(n);
    return b.count();
}

int main(){
    unsigned int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"ANSWER:- "<<count(n)<<endl;
    return 0;
}