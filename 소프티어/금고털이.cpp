#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(int argc, char** argv)
{
    int w, n, answer = 0;

    cin >> w >> n;

    vector<pair<int, int>> v(n,{0,0});
    
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    for(int i  = 0 ; i < v.size(); i++){
        if(w > v[i].first){
            w -= v[i].first;
            answer += v[i].second * v[i].first;
        }else{
            answer += v[i].second * w;
            break;
        }
        
    }

    cout << answer;
    return 0;
}