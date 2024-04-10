//


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>temp;
        sort(deck.begin(),deck.end(),greater<int>());
        deque<int>dq;
        dq.push_front(deck[0]);
        for(int i =1;i<deck.size();i++){
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }

        for(int i =0;i<dq.size();i++){
            temp.push_back(dq[i]);
        }
        
        return temp;
    }
};