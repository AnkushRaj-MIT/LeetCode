class RandomizedSet {
public:
    unordered_map<int,int> mp;//to store the address of a val in arr
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) {
            return false;
        }
        int index = mp[val];
        int last = arr.back();// Move last element to this position
        arr[index] = last;
        mp[last] = index;
        arr.pop_back();// Remove last element
        mp.erase(val);
        return true; 
    }
    
    int getRandom() {
        int idx=rand()%arr.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */