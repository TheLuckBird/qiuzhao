//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void showvs(vector<string> substring)
//{
//    for (auto& s : substring)
//        cout << s << " ";
//    cout << endl;
//}
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//
//        vector<string> substring;
//
//        for (auto i = s.begin(); i != s.end(); ++i)
//        {
//            string temp;
//            for (auto j = i; j != s.end(); ++j)
//            {
//                temp += *j;
//                substring.push_back(temp);
//            }
//        }
//
//        int ans = 0;
//        for (auto& subs : substring)
//        {
//            int l = 0;
//            for (auto i = subs.begin(); i != subs.end(); ++i)
//            {
//                if (find(subs.begin(), i, *i) == i)
//                {
//                    ++l;
//                }
//                else
//                    break;
//            }
//            ans = max(ans, l);
//        }
//
//        showvs(substring);
//
//        return ans;
//    }
//};
//
//int main()
//{
//    Solution s;
//    string S = "abcabcdb";
//    int ans = s.lengthOfLongestSubstring(S);
//    cout << ans;
//}