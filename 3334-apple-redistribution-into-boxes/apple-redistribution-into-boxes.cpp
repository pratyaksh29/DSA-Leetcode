class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(); //pack
        int m = capacity.size(); //box
        sort(capacity.begin(), capacity.end(), greater());

        int c = 0;
        for(int i =0;i<n;i++){
            c+= apple[i];
        }
        int cap =0;
        for(int i =0;i<m;i++){
            cap+= capacity[i];
            if(cap>=c){
                return i+1;
            }
        }
        return -1;
    }
};