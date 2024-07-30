class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string>words;
        int i = 0;
        while(i<n){
            string t = "";
            while(i<s.size() && s[i]==' '){
                i++;
            }
            while(i<s.size() && s[i]!= ' '){
                t+=s[i];
                i++;
            }
            if (!t.empty()){
                words.push_back(t);
            }
        }
        string ans;
        for(int j=words.size()-1;j>=0;j--){
            ans+=words[j];
            if(j!=0){
                ans+=' ';
            }
        }
        return ans;
        
    }
};