// Given a grid matrix, findout if you can reach from source to destination

#include <bits/stdc++.h>
using namespace std ;

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