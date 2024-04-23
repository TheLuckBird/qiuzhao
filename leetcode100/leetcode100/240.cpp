//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int lowerbound = matrix.size() - 1;
//        int rightbound = matrix[0].size() - 1;
//
//        for (int i = lowerbound; i >= 0; --i)
//        {
//            if (matrix[lowerbound][0] > target)
//            {
//                --lowerbound;
//                break;
//            }
//        }
//
//        for (int i = rightbound; i >= 0; --i)
//        {
//            if (matrix[0][rightbound] > target)
//            {
//                --rightbound;
//                break;
//            }
//        }
//
//        for (int i = 0; i <= lowerbound; ++i)
//        {
//            for (int j = 0; j <= rightbound; ++j)
//            {
//                if (matrix[i][j] == target)
//                    return true;
//            }
//        }
//        return false;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> matrix = { {1,4,7,11,15} ,{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
//    int target = 24;
//    Solution s;
//    bool ans = s.searchMatrix(matrix, target);
//    cout << ans << endl;
//    return 0;
//}