//#include <vector>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void backtrack(vector<string>& ans, string& path, string& s,int index)
//    {
//        if (index == s.size() - 1)
//        {
//            ans.push_back(path);
//            return;
//        }
//        if (index < s.size() - 1)
//        {
//            ans.push_back(path);
//        }
//
//        for (int i = index; i != s.size(); ++i)
//        {
//            path.push_back(s[i]);
//            backtrack(ans, path, s, i + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<string> partition(string s) {
//        vector<string> ans;
//        string path;
//
//        backtrack(ans,path,s,0);
//
//        return ans;
//    }
//};
//
//void test()
//{
//    string s = "aab";
//    Solution S;
//    auto ans = S.partition(s);
//    for (const auto& c : ans)
//    {
//        cout << c << " ";
//    }
//    cout << endl;
//}
//
//int main()
//{
//    test();
//
//    return 0;
//}
//
