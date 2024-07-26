
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    unordered_map<int, int> umap;
    unordered_map<int, list<int>::iterator> address;
    list<int> l;
    int capa;
    int size;

public:
    LRUCache(int capacity) {
        capa = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (umap.find(key) == umap.end())
            return -1;
        
        auto it = address[key];
        l.erase(it);
        l.push_front(key);
        address[key] = l.begin();
        return umap[key];
    }
    
    void put(int key, int value) {
        if (umap.find(key) != umap.end()) {
            auto it = address[key];
            l.erase(it);
            size--;
        } else if (size == capa) {
            int k = l.back();
            l.pop_back();
            umap.erase(k);
            address.erase(k);
            size--;
        }
        
        umap[key] = value;
        l.push_front(key);
        address[key] = l.begin();
        size++;
    }
};