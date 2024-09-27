/*
시험감독
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, b, c;
    long long answer = 0;
    
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    cin >> b >> c;

    for(int num : v){
        if(num - b < 0){
            answer++;
            continue;
        }
        answer += ((num - b) / c) + ((num - b) % c == 0 ? 0 : 1) + 1;
    }
    cout << answer;
}