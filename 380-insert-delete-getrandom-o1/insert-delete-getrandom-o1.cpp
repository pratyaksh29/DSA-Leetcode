class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int index = mp[val]; // get the index of the element to remove
        int last = nums.back(); // get the last element
        
        // Swap the element to remove with the last element
        swap(nums[index], nums[nums.size() - 1]);
        
        // Update the index of the last element in the map
        mp[last] = index;
        
        // Remove the last element from the vector
        nums.pop_back();
        
        // Erase the element from the map
        mp.erase(val);
        
        return true;
    }

    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */