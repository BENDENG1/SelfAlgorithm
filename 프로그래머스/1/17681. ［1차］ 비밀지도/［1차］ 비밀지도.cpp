/*
비밀지도

' ' : 공백 / # : 벽
겹쳐서 벽인 부분은 모두 벽 둘다 공백은 공백

9
42100 -> 0이면 0 으로 쭈욱 하면 됨 ㅇㅇ
10010

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0 ; i < n; i++){
        int num1 = arr1[i];
        int num2 = arr2[i];
        string s = "";
        for(int j = 0 ; j < n; j++){
            if(num1 % 2 == 0 && num2 % 2 == 0){
                s += ' ';
            }else{
                s += '#';
            }
            num1 /= 2;
            num2 /= 2;
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    return answer;
}