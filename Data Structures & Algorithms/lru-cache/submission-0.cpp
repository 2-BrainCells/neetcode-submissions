class LRUCache {
    int capacity;
    unordered_map<int, int> cache; 
    list<int> usage;               

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        usage.remove(key); 
        usage.push_front(key);
        
        return cache[key];
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            usage.remove(key);
            usage.push_front(key);
            return;
        }
        
        if (cache.size() == capacity) {
            int oldestKey = usage.back();
            usage.pop_back();        
            cache.erase(oldestKey);  
        }
        
        cache[key] = value;
        usage.push_front(key);
    }
};
