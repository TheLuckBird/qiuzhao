//#include <string>
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution {
//public:
//    //可行字串判断
//    bool check()
//    {
//        for (const auto& pair : mpt)
//        {
//            if (mps[pair.first] < pair.second)//字串字符个数必须不小于t字符个数
//                return false;
//        }
//        return true;
//    }
//
//    unordered_map<char, int> mpt, mps;
//
//    string minWindow(string s, string t) {
//        for (auto& c : t) 
//            ++mpt[c];
//
//        int l = 0, r = -1, len = s.size() + 1, ansL = -1;
//
//        while(r < int(s.size()))
//        {
//            if(mpt.find(s[++r]) != mpt.end())//滑动窗口扩张，s中t的字符构建哈希表mps方便判断
//                ++mps[s[r]];
//
//            while (check() && l <= r)//1判断是否为可行字串，2滑动窗口左侧收缩，3最小子串
//            {
//                if (r - l + 1 < len)
//                {
//                    len = r - l + 1;//最小子串的长度
//                    ansL = l;//最小子串的起始位置
//                }
//                if (mpt.find(s[l]) != mpt.end())
//                    --mps[s[l]];//重建可行字串哈希表ing
//
//                ++l;//左侧收缩
//            }
//        }
//        return ansL == -1 ? string() : s.substr(ansL, len);
//    }
//};
//
//int main()
//{
//    string s = "ADOBECODEBANC";
//    string t = "ABC";
//
//    Solution S;
//    string ans = S.minWindow(s, t);
//    cout << ans << endl;
//}