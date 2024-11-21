/*
두 큐 합 같게 만들기

그리디로 음 작은것에 대해서 더해주는 방식을 반복하면될듯?

*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long oneSum = 0;
    long long twoSum = 0;
    queue<int> q1;
    queue<int> q2;
    
    for(int a : queue1){
        q1.push(a);
        oneSum += a;
    }
    
    for(int a : queue2) {
        q2.push(a);
        twoSum += a;
    }
    
    while(answer <= (q1.size() + q2.size()) * 2){
        if(oneSum == twoSum) return answer;
        
        answer++;
        
        if(oneSum < twoSum){
            int tmp = q2.front();
            oneSum += tmp;
            twoSum -= tmp;
            q2.pop();
            q1.push(tmp);
        }else {
            int tmp = q1.front();
            oneSum -= tmp;
            twoSum += tmp;
            q1.pop();
            q2.push(tmp);
        }
    }
    
    return -1;
}