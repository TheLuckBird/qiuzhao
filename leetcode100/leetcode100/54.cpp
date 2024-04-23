//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        vector<int> ans;
//
//        //定义螺旋边界
//        int upper = 0;
//        int down = matrix.size() - 1;
//        int left = 0;
//        int right = matrix[0].size() - 1;
//
//        while (true)
//        {
//            //向右
//            for (int i = left; i <= right; ++i)
//            {
//                ans.push_back(matrix[upper][i]);
//            }
//            if (++upper > down) break;
//            //向下
//            for (int i = upper; i <= down; ++i)
//            {
//                ans.push_back(matrix[i][right]);
//            }
//            if (--right < left) break;
//            //向左
//            for (int i = right; i >= left; --i)
//            {
//                ans.push_back(matrix[down][i]);
//            }
//            if (--down < upper) break;
//            //向上
//            for (int i = down; i >= upper; --i)
//            {
//                ans.push_back(matrix[i][left]);
//            }
//            if (++left > right) break;
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> matrix = { {1,2,3} ,{4,5,6},{7,8,9} };
//    Solution s;
//    vector<int> ans = s.spiralOrder(matrix);
//    for (auto& x : ans) cout << x << " ";
//    cout << endl;
//    return 0;
//}