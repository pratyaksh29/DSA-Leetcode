class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        int c = 0;
        int index=0;
        for(int i =0;i<haystack.size();i++){
            if(haystack[i]==needle[index]){
                c++;
                index++;
                if(c==needle.size()){
                    return i+1-c;
                }
            }
            else{
                i=i-c; //to start the loop again from the second matched character
                index = 0;
                c=0;
            }
            

        }
        return -1;
    }
};