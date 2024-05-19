//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> ans;
//
//        if (numRows == 1)
//        {
//            return { {1} };
//        }
//        if (numRows == 2)
//        {
//            return { {1},{1,1} };
//        }
//
//        ans = { {1},{1,1} };
//        ans.resize(numRows);
//        for (int i = 2; i != numRows; ++i)
//        {
//            ans[i].resize(i + 1);
//            ans[i][0] = 1;
//            ans[i][i] = 1;
//            for (int j = 1; j != i; ++j)
//            {
//                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
//            }
//        }
//
//        return ans;
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    auto ans = s.generate(30);
//    for (auto& v : ans)
//    {
//        for (auto& i : v)
//        {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//}
