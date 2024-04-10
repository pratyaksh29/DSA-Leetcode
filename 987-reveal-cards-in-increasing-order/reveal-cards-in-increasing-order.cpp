//


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater<int>());
        deque<int>dq;
        dq.push_front(deck[0]);
        for(int i =1;i<deck.size();i++){
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        vector<int>temp(dq.begin(),dq.end());
        return temp;
    }
};