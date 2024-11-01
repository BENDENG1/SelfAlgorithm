/*
소프티어 성적 평균

걍 dp + 소수점을 출력할 수 있는지 확인하는 문제
*/
#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n,0);
    
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
        if(i != 0){
            v[i] += v[i - 1];
        }
    }

    for(int i = 0 ; i < k ; i++){
        int start, end;
        cin >> start >> end;

        cout << fixed;
        cout.precision(2);
        if(start == 1){
            cout << (double)(v[end - 1] / (double)(end - start + 1))<<"\n";
        }else{
            cout << (double)((v[end - 1] - v[start - 2]) / (double)(end - start + 1))<<"\n";
        }
    }

    return 0;
}