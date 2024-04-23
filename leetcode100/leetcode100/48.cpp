//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void rotate(vector<vector<int>>& matrix) {
//        vector<vector<int>> tmp = matrix;
//        int n = matrix.size();
//
//        for (int i = 0; i != n; ++i)
//        {
//            for (int j = 0; j != n; ++j)
//            {
//                tmp[j][n - i - 1] = matrix[i][j];
//            }
//        }
//
//        matrix = tmp;
//
//       /* for (auto& v : matrix)
//        {
//            for (auto& x : v)
//            {
//                cout << x << " ";
//            }
//            cout << endl;
//        }*/
//
//    }
//};
//
//int main()
//{
//    vector<vector<int>> matrix = { {1,2,3} ,{4,5,6},{7,8,9} };
//    Solution s;
//    s.rotate(matrix);
//    return 0;
//}
//
