class Solution {
public:
    int lengthOfLastWord(string s) {
        int n =s.size();
        int minus=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                minus++;
            }
            else{
                break;
            }
        }
        int index = n-1-minus;
        int ans = 0;
        for(int i=index;i>=0;i--){
            if(s[i]!=' '){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};