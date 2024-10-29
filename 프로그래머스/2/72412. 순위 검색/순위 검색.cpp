/*
순위 검색

우선 그냥 복잡도 생각안하고 진행해보자
음 바로 효율성에서 개박살 나는듯..?

처음 논리 : 그냥 값들을 모두 넣고 query에 만족하는 info의 리스트를 다 탐색 하는 것이 문제임
결국 모든 시간 타임아웃..

음 그러면.. 점수에 대해서 정렬을 하고 진행?
그래도 시간 초과

맵을이용해서 푸는것은? -> 이 부분에서 음 

여기서 모든 경우의 수를 string으로 만들어서 
ex)a,b -> ab, a_, _b, __ 이렇게 4개 
4개면 16개
*/
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string,vector<int>> m;

vector<string> splitAndRemoveAnd(const string& str) {
    vector<string> result;
    istringstream iss(str);
    string word;

    while (iss >> word) {
        if (word != "and") {
            result.push_back(word);
        }
    }

    return result;
}

int stringToInt(string s){
    int num = 0;
    for(char c : s){
        num *= 10;
        num += c - '0';
    }
    return num;
}


void splitInfo(const string& info) {
    vector<string> infoVec = splitAndRemoveAnd(info);
    int score = stringToInt(infoVec[4]);
    
    for (int i = 0; i < 16; i++) {
        string key = "";
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                key += infoVec[j];
            } else {
                key += "-";
            }
        }
        m[key].push_back(score);
    }
}

int findQueryFilter(const string& query) {
    vector<string> infoVec = splitAndRemoveAnd(query);
    string key = infoVec[0] + infoVec[1] + infoVec[2] + infoVec[3];
    int scoreBound = stringToInt(infoVec[4]);

    if (m.find(key) == m.end()) return 0;

    const vector<int>& scores = m[key];
    return scores.end() - lower_bound(scores.begin(), scores.end(), scoreBound);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string s : info){
        splitInfo(s);
    }
    
    for (auto& [key, scores] : m) {
        sort(scores.begin(), scores.end());
    }
    
    for(string s : query){
        answer.push_back(findQueryFilter(s));
    }
    
    return answer;
}

/*

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Applicant {
    string language;
    string field;
    string history;
    string soulFood;
    int score;
    
    bool operator<(const Applicant& other) const {
        return tie(language, field, history, soulFood) < tie(other.language, other.field, other.history, other.soulFood);
    }
};

map<Applicant,vector<int>> m;

vector<string> splitAndRemoveAnd(const string& str) {
    vector<string> result;
    istringstream iss(str);
    string word;

    while (iss >> word) {
        if (word != "and") {
            result.push_back(word);
        }
    }

    return result;
}

int stringToInt(string s){
    int num = 0;
    for(char c : s){
        num *= 10;
        num += c - '0';
    }
    return num;
}


Applicant splitInfo(const string& info) {
    Applicant applicant = Applicant();
    vector<string> infoVec = splitAndRemoveAnd(info);
    
    applicant.language = infoVec[0];
    applicant.field = infoVec[1];
    applicant.history = infoVec[2];
    applicant.soulFood = infoVec[3];
    applicant.score = stringToInt(infoVec[4]);
    
    return applicant;
}

int findQueryFilter(const string& query) {
    int count = 0, idx = 0;
    Applicant condition = Applicant();
    vector<string> infoVec = splitAndRemoveAnd(query);
    
    condition.language = infoVec[0];
    condition.field = infoVec[1];
    condition.history = infoVec[2];
    condition.soulFood = infoVec[3];
    condition.score = stringToInt(infoVec[4]);
        
    for (const auto& [applicant, scores] : m) {
        if ((condition.language == "-" || applicant.language == condition.language) &&
            (condition.field == "-" || applicant.field == condition.field) &&
            (condition.history == "-" || applicant.history == condition.history) &&
            (condition.soulFood == "-" || applicant.soulFood == condition.soulFood)) {
            count += count_if(scores.begin(), scores.end(), [&](int score) {
                return score >= condition.score;
            });
        }
    }
    
    
    return count;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string s : info){
        Applicant tmp = splitInfo(s);
        m[tmp].push_back(tmp.score);
    }
    
    for(string s : query){
        answer.push_back(findQueryFilter(s));
    }
    
    return answer;
}


*/


/*
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct Applicant {
    string language;
    string field;
    string history;
    string soulFood;
    int score;
};

vector<string> splitAndRemoveAnd(const string& str) {
    vector<string> result;
    istringstream iss(str);
    string word;

    while (iss >> word) {
        if (word != "and") {
            result.push_back(word);
        }
    }

    return result;
}

int stringToInt(string s){
    int num = 0;
    for(char c : s){
        num *= 10;
        num += c - '0';
    }
    return num;
}


Applicant splitInfo(const string& info) {
    Applicant applicant = Applicant();
    vector<string> infoVec = splitAndRemoveAnd(info);
    
    applicant.language = infoVec[0];
    applicant.field = infoVec[1];
    applicant.history = infoVec[2];
    applicant.soulFood = infoVec[3];
    applicant.score = stringToInt(infoVec[4]);
    
    return applicant;
}

int findQueryFilter(const string& query, const vector<Applicant>& v) {
    int count = 0, idx = 0;
    Applicant condition = Applicant();
    vector<string> infoVec = splitAndRemoveAnd(query);
    
    condition.language = infoVec[0];
    condition.field = infoVec[1];
    condition.history = infoVec[2];
    condition.soulFood = infoVec[3];
    condition.score = stringToInt(infoVec[4]);
        
    for(Applicant app : v){
        if((app.score >= condition.score)
           &&(app.language == condition.language || condition.language == "-")
           && (app.field == condition.field || condition.field == "-")
           && (app.history == condition.history || condition.history == "-" )
           && (app.soulFood == condition.soulFood || condition.soulFood == "-")
          )
            count++;
    }
    
    
    return count;
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Applicant> v;
    
    for(string s : info){
        v.push_back(splitInfo(s));
    }
    
    for(string s : query){
        answer.push_back(findQueryFilter(s, v));
    }
    
    
    return answer;
}
*/