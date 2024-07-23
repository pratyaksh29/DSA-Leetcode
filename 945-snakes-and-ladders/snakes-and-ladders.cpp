class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> cells = createCellMapping(n);
        return performBFS(board, cells);
    }

private:
vector<pair<int, int>> createCellMapping(int n) {
    vector<pair<int, int>> cells(n*n + 1);
    int label = 1;
    vector<int> cols(n);
    for (int i = 0; i < n; i++) cols[i] = i;

    for (int row = n - 1; row >= 0; row--) {
        for (int col : cols) {
            cells[label++] = {row, col};
        }
        reverse(cols.begin(), cols.end());
    }
    return cells;
}

    int performBFS(const vector<vector<int>>& board, const vector<pair<int, int>>& cells) {
        int n = board.size();
        vector<int> dist(n*n + 1, -1);
        queue<int> q;

        // Start from position 1
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // If we've reached the last cell, return the distance
            if (curr == n*n) return dist[curr];

            // Check the next 1-6 positions
            for (int next = curr + 1; next <= min(curr + 6, n*n); next++) {
                auto [row, column] = cells[next];
                
                // If there's a snake or ladder, update the destination
                int destination = next;
                if (board[row][column] != -1) {
                    destination = board[row][column];
                }

                // If this position hasn't been visited, update distance and add to queue
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                } 
            }
        }

        // If we can't reach the last cell, return -1
        return -1;
    }
};