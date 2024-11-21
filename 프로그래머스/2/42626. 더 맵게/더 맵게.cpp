/*
더 맵게

가장 맵지 않은 음식 + 두번째 * 2

k이상이 될때까지 반복하여 섞음
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int a : scoville){
        pq.push(a);
    }
    
    while(!pq.empty()){
        if(pq.top() >= K)
            return answer;
        
        int first = pq.top();
        pq.pop();
        
        if(pq.empty())
            return -1;
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    
    return answer;
}