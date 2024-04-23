//#include <vector>
//#include <String>
//#include <unordered_map>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        unordered_map<string, vector<string>>mp;
//        for (string& str : strs)
//        {
//            string key = str;
//            sort(key.begin(), key.end());
//            mp[key].emplace_back(str);
//        }
//
//        vector<vector<string>> ans;
//        for (auto it = mp.begin(); it != mp.end(); ++it)
//        {
//            ans.emplace_back(it->second);
//        }
//
//        return ans;
//    }
//};
//
///*
//int main()
//{
//    vector<string> strs1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
//    vector<string> strs2 = {""};
//    Solution s;
//    vector<vector<string>> ans = s.groupAnagrams(strs2);
//    for (auto it = ans.begin(); it != ans.end(); ++it)
//    {
//        for (auto i = it->begin(); i != it->end(); ++i)
//        {
//            cout << *i << " ";
//        }
//        cout << endl;
//    }
//}
//*/
