//909. Snakes and Ladders
/*
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    
    Problem Overview: Find the minimum of move to the cell n * n in a board

    - Call v is the number of rows and columns in the board
    - For this problem, we can use a BFS approach to find all the shortest paths from the start to the end.
    - We will use a queue to store the current position and then we iterate through all the possible moves (For this problem is from 1 to 6)
    - Call step is the next position we can move to and we will check if the position is a snake or a ladder.
    - We calculate next row and column suitable for the current step.
    - After that, call variable check is the value of the cell we can move to, if it equal v * v, we return the number of moves. 
    Else, if the res check is -1, we update the res check with res curr + 1 and push the check into the queue.
    - After all, if we cannot reach the end, we return -1.
*/
#include<bits/stdc++.h>
using namespace std;
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