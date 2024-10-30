/*
LRU 알고리즘

*/
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    list<int> li;
    unordered_map<int, list<int>::iterator> hash;
    int csize;
public : 
    LRUCache(int);
    void refer(int);
    void listReferAndDisplay(list<int>);
    void display();
};

LRUCache::LRUCache(int n) {
    csize = n;
}

void LRUCache::refer(int x) {
    if (hash.find(x) == hash.end()) {
        if(li.size() == csize) {
            int last = li.back();
            li.pop_back();
            hash.erase(last);
        }
    } else {
        li.erase(hash[x]);
    }

    li.push_front(x);
    hash[x] = li.begin();
}

void LRUCache::display(){
    for (auto it = li.begin(); it != li.end(); it++) {
        cout << (*it) << " ";
    }
    cout << "\n";
}

void LRUCache::listReferAndDisplay(list<int> v){
    for (auto it = v.begin(); it != v.end(); it++){
        refer(*it);
        display();
    }
}

int main() {
    LRUCache ca(3);

    list<int> test = {1,3,0,3,5,6,3};

    ca.listReferAndDisplay(test);
    // ca.refer(1);
    // ca.display();
    // ca.refer(3);
    // ca.display();
    // ca.refer(0);
    // ca.display();
    // ca.refer(3);
    // ca.display();
    // ca.refer(5);
    // ca.display();
    // ca.refer(6);
    // ca.display();
    // ca.refer(3);
    // ca.display();
    return 0;
}