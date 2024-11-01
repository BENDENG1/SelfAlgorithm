/*
소프티어 염기서열 커버

a,c,g,t

n개 의 길이 m
와일드카드 . -> 모든 염기서열 대체
조건 모두 만족 -> 초염기 서열

그러니깐 길이에 맞는 조합중에 최대 몇개를 커버 가능한가?

음.. dp의 느낌으로 이중 포문을 도는데 70개중 12개가 틀리네 fuck
*/
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMatching(const string& s1,const string& s2);

int main(int argc, char** argv)
{
    int n, m, answer;
    cin >> n >> m;

    answer = n;

    vector<string> v(n);
    
    for(int i =0 ; i < n; i++){
        cin >> v[i];
    }
    vector<string> ref;

    for(int i = 0; i < n; i++){
        
        bool isMatch = false;

        for(auto& s : ref){
            if(isMatching(v[i], s)){
                for(int j = 0 ; j < m; j++){
                    if(s[j] == '.')
                        s[j] = v[i][j];
                }
                isMatch = true;
                break;
            }
        }

        if(!isMatch){
            ref.push_back(v[i]);
        }
    }

    cout <<ref.size();

   return 0;
}

bool isMatching(const string& s1,const string& s2){
    for(int i = 0 ; i < s1.length(); i++){
        if(s1[i] != s2[i] && s1[i] != '.' && s2[i] != '.')
            return false;
    }
    return true;
}

/*
aa.. a
aba. b
acac c
aaa. a
abab b
abab b

aa.. df
aba. df
acac
aaa. df
abab df
abab
*/