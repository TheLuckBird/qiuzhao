//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void backtrack(vector<string>& ans, unordered_map<char, string> phonestring, string digits,int index, string ans_)
//    {
//        if (index == digits.length())
//        {
//            ans.push_back(ans_);
//        }
//        else
//        {
//            char digit = digits[index];
//            const string letters = phonestring.at(digit);
//            for (const char& c : letters)
//            {
//                ans_.push_back(c);
//                backtrack(ans, phonestring, digits, index + 1, ans_);
//                ans_.pop_back();
//            }
//        }
//
//    }
//
//    vector<string> letterCombinations(string digits) {
//        vector<string> ans;
//
//        if (!digits.size()) return ans;
//
//        unordered_map<char, string> phonestring = {
//            {'2',"abc"},
//            {'3',"def"},
//            {'4',"ghi"},
//            {'5',"jkl"},
//            {'6',"mno"},
//            {'7',"pqrs"},
//            {'8',"tuv"},
//            {'9',"wxyz"}
//
//        };
//        string ans_;
//        backtrack(ans, phonestring, digits, 0, ans_);
//
//        return ans;
//    }
//};
//
//int main()
//{
//    string digits = "23";
//    Solution s;
//    vector<string> ans = s.letterCombinations(digits);
//
//    for (string s : ans)
//        cout << s << " ";
//    cout << endl;
//
//    return 0;
//}