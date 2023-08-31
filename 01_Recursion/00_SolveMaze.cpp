// Given a grid matrix, findout if you can reach from source to destination

#include <bits/stdc++.h>
using namespace std ;

class Solution1{
    // Recursion
public: 
    // 'S' -> Source cell
    // 'E' -> Destination cell
    // '*' -> obstacle.

    bool dfs(vector<string> &board, vector<vector<int>> &visited, int i, int j) {
        if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size()) return false;
        if (visited[i][j]) return false;

        if (board[i][j] == 'E') return true;
        visited[i][j] = 1;

        if (dfs(board, visited, i-1, j)) return true;
        if (dfs(board, visited, i, j+1)) return true;
        if (dfs(board, visited, i+1, j)) return true;
        if (dfs(board, visited, i, j-1)) return true;

        return false;
    }

    bool isPathAvailable(vector<string> board, int row, int col){
        int m = board.size(), n = board[0].length();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        return dfs(board, visited, row, col);
    }
};

class Solution{
public: 
    // 'S' -> Source cell
    // 'E' -> Destination cell
    // '*' -> obstacle.
    bool isPathAvailable(vector<string> board, int row, int col){
        int m = board.size(), n = board[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));

        stack<pair<int, int>> st;
        st.push({row, col});

        vector<pair<int, int>> shift = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(st.size()) {
            int r = st.top().first, c = st.top().second;
            st.pop();

            visited[r][c] = 1;
            if (board[r][c] == 'E') return true;

            for (int i = 0; i < 4; ++i)
            {
                int newRow = r + shift[i].first;
                int newCol = c + shift[i].second;

                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n){
                    continue;
                }

                if (board[newRow][newCol] == '*' || visited[newRow][newCol]){
                    continue;
                }

                st.push({newRow, newCol});
            }
        }

        return false;
    }
};

int main () {
    
    return 0;
}