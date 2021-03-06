/*
Problem: Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.
	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

link: https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
private:
    int capacity;
    unordered_map<int, int> m;
    list<int> l;
    
public:
    LRUCache(int capacity) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            l.remove(key);
            l.push_front(key);
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            l.remove(key);
            l.push_front(key);
            m[key] = value;
        }
        else {
            if(m.size() == capacity) {
                m.erase(l.back());
                l.pop_back();
                l.push_front(key);
                m[key] = value;
            }
            else {
                l.push_front(key);
                m[key] = value;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */