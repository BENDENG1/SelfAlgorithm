/*
괄호 변환

(,)의 갯수가 같다면 -> 균현잡힌 문자열
짝이 모두 맞다면 -> 올바른 괄호 문자ㅕㅇㄹ

u,v분리
*/
#include <string>
#include <vector>

using namespace std;

bool isRightString(string s){
    int tmp = 0;
    for(char c : s) {
        if(c == '(')
            tmp++;
        if(c == ')')
            tmp --;
        if(tmp < 0)
            return false;
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if(p == "")
        return "";
    
    string u, v;
    
    int count = 0;
    for(int i = 0 ; i < p.length(); i++){
        if(p[i] == '(')
            count++;
        if(p[i] == ')')
            count--;
        
        if(count == 0){
            u = p.substr(0,i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    if(isRightString(u)){
        answer = u + solution(v);
    }else {
        string tmp = "";
        for(int i = 1; i <= u.length() - 2; i++){
            if(u[i] == '('){
                tmp += ")";
            }else {
                tmp += "(";
            }
        }
        
        answer = '(' + solution(v) + ')' + tmp;
    }
    
    
    return answer;
}
