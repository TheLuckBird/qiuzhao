//#include <vector>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void backtrack(vector<string>& ans, string& path,int open, int close, int n)
//    {
//        if (path.size() == n * 2)
//        {
//            ans.push_back(path);
//            return;
//        }
//
//        if (open < n)
//        {
//            path.push_back('(');
//            backtrack(ans, path, open + 1, close, n);
//            path.pop_back();
//        }
//        if (close < open)
//        {
//            path.push_back(')');
//            backtrack(ans, path, open , close + 1, n);
//            path.pop_back();
//        }
//    }
//
//    vector<string> generateParenthesis(int n) {
//        vector<string> ans;
//        string path;
//
//        backtrack(ans, path, 0, 0, n);
//
//        return ans;
//    }
//};
//
//int main()
//{
//    int n = 3;
//    Solution s;
//    vector<string> ans = s.generateParenthesis(n);
//
//    for (auto& i : ans)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//
//    return 0;
//}