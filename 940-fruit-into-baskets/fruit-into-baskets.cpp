class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l =0;
        int r =0;
        unordered_map<int,int>mp;  //num,freq
        int c = 0;
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            else{
                c = max(c,r-l+1);   
            }
            r++;

        }
        return c;

    }
};