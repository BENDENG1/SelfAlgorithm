/*
디펜스 게임

n명으로 연속 순서대로 막음

enemy[i]마리 적 등장
무적권 -> 한라운드 공격 막음 최대 k번 사용

음.. dp? 걍 우선순위 큐 해서 하면 될듯

*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int a: enemy){
        pq.push(a);
        if(pq.size() > k){
            if(n - pq.top() < 0){
                break;
            }else{
                n -= pq.top();
            }
            pq.pop();
        }
        answer++;
    }
    
    return answer;
}