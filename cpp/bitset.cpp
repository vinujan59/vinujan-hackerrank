#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
    long n,s,p,q;
    cin >> n >> s >> p >> q;
    const int nu = n;
    bitset<100000000> a ;
    int prev,next;
    prev = s;
    a.set(0,true);
    for(long i=1; i < n;++i){
        next = (prev * p + q )% static_cast<long>(pow(2,31));
        if(prev != next){
            a.set(i,true);
        }
        prev = next;
    }
    cout << a.count();
    return 0;
}

