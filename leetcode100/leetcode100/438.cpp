//#include <string>
//#include <vector>
//#include <iostream>
//#include <unordered_set>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> ans;
//
//        int n = s.size();
//        int rk = p.size();//滑动窗口大小
//       /* unordered_set<char> occ;
//        for (auto& c : p) occ.insert(c);*/
//
//        for (int i = 0; i != n; ++i)
//        {
//            string tmp;
//            bool flag = false;
//            bool a = true;
//            for (int j = 0; j!= rk; ++j)
//            {
//                if (i + j < n)
//                    tmp.push_back(s[i + j]);
//                else
//                {
//                    a = false;
//                    break;
//                }
//            }
//            for (int j = 0; j != rk; ++j)
//            {
//                if (find(tmp.begin(), tmp.end(), p[j]) != tmp.end()
//                    && find(p.begin(), p.end(), tmp[j]) != p.end())
//                    flag = true;
//                else
//                {
//                    flag = false;
//                    break;
//                }
//                    
//            }
//
//            if (flag && a)
//                ans.push_back(i);
//        }
//        return ans;
//
//    }
//};
//
//int main()
//{
//    Solution s;
//    string S = "baa";
//    string P = "aa";
//    vector<int> ans = s.findAnagrams(S,P);
//    for (auto& i : ans) cout << i << " ";
//
//
//
//}
