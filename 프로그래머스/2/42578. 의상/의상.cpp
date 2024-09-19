/*
의상

음 종류가 abc고 갯수가 1 2 3 이면
1 + 2 + 3 + 1*2 + 1*3 + 2*3 + 1*2*3 이 됨
(1 + 1) * (2 + 1) + (3 + 1) - 1이 됨

왜? 선택한 경우와 선택하지 않은 경우를 고려하니 + 1이지만
전체를 선택하지 않은 경우의 수는 빼야하므로 그렇게 됨 ㅇㅇ
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    
    for(auto c : clothes){
        if(m.find(c[1]) != m.end()){
            m[c[1]] += 1;
        }else{
            m.insert({c[1], 1});
        }
    }

    for(auto a : m){
        answer *= (a.second + 1); 
    }
    
    return answer - 1;
}