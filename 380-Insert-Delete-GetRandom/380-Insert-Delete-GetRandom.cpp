class RandomizedSet {
public:
    vector<int>data;
    unordered_map<int, int>mp;

    RandomizedSet() {

    }
    
    bool insert(int val) {
       if (mp.find(val) != mp.end()) {
           return false;
       }  else {
           data.push_back(val);
           mp[val] = data.size() -1;
           return true;
       }
    }
    
    bool remove(int val) {
        if (mp.find(val) != mp.end()) {
            int idx = mp[val];
            int temp = data.back();
            data.back() = val;
            data[idx] = temp;
            mp[temp] = idx;
            data.pop_back();
            mp.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int n = data.size();
        int random = rand()%n;
        return data[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
