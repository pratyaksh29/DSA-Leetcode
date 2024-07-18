class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>mp; //num and its frequency
        int l=0;
        int r =0;
        int len =0;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            len = max(len , r-l+1);
            r++;
            
        }
        return len;
    }
};