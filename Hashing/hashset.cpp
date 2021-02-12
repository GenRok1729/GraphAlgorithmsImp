class MyHashSet {
    
    int nub;
    vector<vector<int>> buckets;
    int hf(int key)
    {
        return key%nub;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        nub = 15000;
        buckets = vector<vector<int>>(nub,vector<int>{});
    }
    
    void add(int key) {
        int i = hf(key);
        if(find(buckets[i].begin(),buckets[i].end(),key) == buckets[i].end())
            buckets[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hf(key);
        auto itr = find(buckets[i].begin(),buckets[i].end(),key);
        if(itr != buckets[i].end())
            buckets[i].erase(itr);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = hf(key);
        auto itr = find(buckets[i].begin(),buckets[i].end(),key);
        if(itr == buckets[i].end())
            return false;
        
      return true;   
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
