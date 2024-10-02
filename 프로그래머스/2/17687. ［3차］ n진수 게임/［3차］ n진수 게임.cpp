/*
N진수 게임

10이상의 숫자부터는 한자리씩 끊어서 말함 
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string numberChange(int n, int num);

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt = 0, num = 0, turn =0;
    
    while(1){
        string s = numberChange(n, num);
        
        for(int i = 0 ; i < s.length(); i++){
            turn++;
            if(turn > m)
                turn = 1;
            if(turn == p){
                cnt++;
                answer += s[i];
            }
            if(cnt == t)
                return answer;
        }
        num ++;
    }
    return answer;
}

string numberChange(int n, int num){
    string rule = "0123456789ABCDEF";
    string number = "";
    if(num == 0)
        return "0";
    while(num > 0){
        number += rule[num % n];
        num /= n;
    }
    reverse(number.begin(), number.end());
    return number;
}