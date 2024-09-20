/*
기능개발

배포는 하루 한번 / 앞에가 끝나야 끝나는건데 다 끝나있으면 그냥 진행하면 됨

*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0; 
    int progress = 0;
    
    while(1){
        for(int i = 0; i < speeds.size();i++){
            progresses[i] += speeds[i];
        }
        
        if(progresses[idx] >= 100){
            while(progresses[idx] >= 100 && idx < progresses.size()){
                idx++;
                progress++;
            }
            answer.push_back(progress);
            progress = 0;
        }
        
        if(idx >= progresses.size())
            break;
    }

    return answer;
}