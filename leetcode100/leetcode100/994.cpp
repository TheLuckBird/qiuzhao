#include <vector>
#include <iostream>

using namespace std;

//class Solution {
//private:
//    void dfs(vector<vector<int>> grid,int r,int c)
//    {
//        int nr = grid.size();
//        int nc = grid[0].size();
//
//        grid[r][c] = 0;
//        if (r - 1 >= 0 && grid[r - 1][c] == 1) dfs(grid, r - 1, c);
//        if (r + 1 != nr && grid[r + 1][c] == 1) dfs(grid, r + 1, c);
//        if (c - 1 >= 0 && grid[r][c - 1] == 1) dfs(grid, r, c - 1);
//        if (c + 1 != nc && grid[r][c + 1] == 1) dfs(grid, r, c + 1);
//
//        ++t;
//    }
//public:
//    int t = 0;
//    int orangesRotting(vector<vector<int>>& grid) {
//        int nr = grid.size();
//        int nc = grid[0].size();
//
//        if (!nr) return -1;
//
//        for (int i = 0; i != nr;++i)
//        {
//            for (int j = 0; j != nc; ++j)
//            {
//                if (grid[i][j] == 2)
//                {
//                    dfs(grid, i, j);
//                }
//            }
//        }
//
//        for (int i = 0; i != nr; ++i)
//        {
//            for (int j = 0; j != nc; ++j)
//            {
//                if (grid[i][j] == 1)
//                    return -1;
//            }
//        }
//        return t;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> grid = { {2, 1, 1},
//                                 {1, 1, 0},
//                                 {0, 1, 1} };
//    
//    Solution s;
//    int ans = s.orangesRotting(grid);
//    cout << ans << endl;
//    return 0;
//}