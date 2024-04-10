class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res ="";
        int a = word1.size();
        int b = word2.size();
        int i =0;
        while(i<a && i<b){
            res.push_back(word1[i]);
            res.push_back(word2[i]);
            i++;
        }

        while(b>i){
            res.push_back(word2[i]);
            i++;
        }


        while(a>i){
            res.push_back(word1[i]);
            i++;
        }

        return res;
    }
};