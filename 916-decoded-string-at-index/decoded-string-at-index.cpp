class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size =0;
        for(char c : s){
            if(isalpha(c)){
                size++;
            }
            else if(isdigit(c)){
                size *= (c - '0');
            }
        }
        for(int i =s.size()-1;i>=0;--i){
            if(isdigit(s[i])){
                size = size / (s[i]-'0');
                k = k%size;
            }
            else{
                if(k==0 || k ==size){
                    return string(1,s[i]);
                }
                size--;
            }
            
        }
        return "";
    }
};