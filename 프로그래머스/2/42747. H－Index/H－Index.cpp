/*
H-index

h의 값을 구함 
h번 이상이 h편이상이고 h번 이하 인용이 h의 최댓값이 h-index

음 역으로 정렬하고 값을 넘으면 계속 아니면 끝
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    
    for(int i = 0; i < citations.size(); i++){
        if(i < citations[i])
            answer++;
        else break;
    }
    
    return answer;
}