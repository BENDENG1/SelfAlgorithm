/*
택배 상자

음 stack으로 넣어서 해결하면 되지 않을까?
*/
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> s;
    for(int i = 0 ; i < order.size(); i++){
        s.push(i + 1);
        
        while(!s.empty() && s.top() == order[answer]){
            s.pop();
            answer++;
        }
    }
    return answer;
}