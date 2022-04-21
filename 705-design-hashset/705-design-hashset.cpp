class MyHashSet {
public:
    vector<bool>v;
    MyHashSet() {
        v.resize(1e6+1,false);
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int ele) {
        v[ele] = 0;
    }
    
    bool contains(int ele) {
        return v[ele];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */