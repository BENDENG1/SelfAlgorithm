/*
소프티어 징검다리

높이가 모두 다름 / 밟을 수 있는 돌의 최대 갯수

dp문제 -> 음..
걍 2중포문 dp
*/
#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int n, tmp, answer = 1;
    cin >> n;

    vector<int> v;
    vector<int> dp(n,1);

    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i] < v[j]){
                dp[j] = max(dp[i] + 1, dp[j]);
                answer = max(dp[j],answer);
            }
        }
    }

    cout << answer;

   return 0;
}