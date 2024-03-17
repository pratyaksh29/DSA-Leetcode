class StockSpanner {
public:
    stack<pair<int, int>> prices; // {price, span}

    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while (!prices.empty() && price >= prices.top().first) {
            span += prices.top().second;
            prices.pop();
        }
        prices.push({price, span});
        return span;
    }
};
