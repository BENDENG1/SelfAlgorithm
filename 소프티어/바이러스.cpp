/*
바이러스

1초당 p배 씩 증가
k마리 n초후 몇마리?
10억이니 int지만 10억일때 3배 늘어나면 overflow이니 long long
*/
#include<iostream>

#define MAX 1000000007

using namespace std;

int main(int argc, char** argv)
{
    int p,n;
    long long k;

    cin >> k >> p >> n;

    for(int i = 0 ; i < n; i++){
        k = (k *p) % MAX;
    }   

    cout << k;
    return 0;
}