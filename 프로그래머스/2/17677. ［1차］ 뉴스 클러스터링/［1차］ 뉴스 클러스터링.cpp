/*
뉴스 클러스터링

자카드 유사도 : 교집합 / 합집합

두글자씩 끊어서 다중집합

영문으로 만 된 집합을 취급하고 다른 쌍은 다 버림
*/
#include <string>
#include <map>
#include <iostream>

using namespace std;

string toLowerString(string str);
bool isAlpha(char c);

int solution(string str1, string str2) {
    int answer = 0;
    int unionSize = 0, interSize = 0;
    string tmp;
    map<string,int> m;
    
    str1 = toLowerString(str1);
    str2 = toLowerString(str2);
    
    for(int i = 0; i < str1.length() - 1; i++){
        if(isAlpha(str1[i]) && isAlpha(str1[i  + 1])){
            tmp = str1.substr(i,2);
            unionSize++;
            
            if(m.find(tmp) == m.end())
                m.insert({tmp, 1});
            else 
                m[tmp]++;
        }
    }
    
    for(int i = 0 ; i < str2.length() - 1; i++){
        if(isAlpha(str2[i]) && isAlpha(str2[i + 1])){
            tmp = str2.substr(i,2);
            
            if(m.find(tmp) == m.end()){
                m.insert({tmp,0});
                unionSize++;
            }else {
                if(m[tmp] >= 1){
                    interSize++;
                    m[tmp] --;
                }else{
                    unionSize++;
                }
            }
        }
    }
    
    if(unionSize == 0)
        return 65536;
    return ((double) interSize / (double) unionSize) * 65536;
}

/*

fr ra an nc ce
fr re en nc ch
*/

bool isAlpha(char c){
    return 'a' <= c && c <= 'z';
}

string toLowerString(string str){
    for(int i = 0 ; i < str.length(); i++){
        if('A' <= str[i] && str[i] <= 'Z'){
            str[i] += 32;
        }
    }
    return str;
}

