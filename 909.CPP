//909. Snakes and Ladders
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int v = board.size();
        vector<int> res(v * v + 1, -1);
        queue<int> q;
        res[1] = 0;
        q.push(1);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int i = 1 ; i <= 6 && curr + i <= v * v ; i++) {
                int step = curr + i, row = (step - 1) / v, col = (step - 1) % v;
                int u = board[v - 1 - row][row % 2 ? v - 1 - col : col];
                int check = u > 0 ? u : step;
                if(check == v * v) 
                    return res[curr] + 1;
                if(res[check] == -1) {
                    res[check] = res[curr] + 1;
                    q.push(check);
                }
            }
        }
        return -1;
    }
};