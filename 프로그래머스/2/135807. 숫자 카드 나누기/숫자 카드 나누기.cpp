/*
숫자 카드 나누기

나누기 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getGcd(const vector<int> &v1, const vector<int> &v2);
int gcd(int small, int big);

int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int gcd1 = getGcd(arrayA, arrayB);
    int gcd2 = getGcd(arrayB, arrayA);
    
    return max(gcd1,gcd2);
}

int getGcd(const vector<int> &v1, const vector<int> &v2){
    int num = v1[0];
    
    for(int i = 1; i < v1.size(); i++){
        num = gcd(num, v1[i]);
        if(num == 1){
            return 0;
        }
    }
    
    for(int i = 0 ; i < v2.size(); i++){
        if(v2[i] % num == 0){
            return 0;
        }
    }
    return num;
}

int gcd(int small, int big){
    int num = 1;
    
    for(int i = 2; i <= small; i++){
        if(big % i == 0 && small % i == 0){
            num = i;
        }
    }
    return num;
}