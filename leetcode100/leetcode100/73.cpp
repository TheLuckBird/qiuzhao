//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size();//行数
//        int n = matrix[0].size();//列数
//
//        vector<int> row(m);//标记数组
//        vector<int> col(n);
//        for (int i = 0; i != m; ++i)
//        {
//            for (int j = 0; j != n; ++j)
//            {
//                if (matrix[i][j] == 0)
//                {
//                    row[i] = 0;
//                    col[j] = 0;
//                }
//            }
//        }
//
//        for (int i = 0; i != m; ++i)
//        {
//            for (int j = 0; j != n; ++j)
//            {
//                if (row[i] || col[j])
//                    matrix[i][j] = 0;
//            }
//        }
//
//    }
//};