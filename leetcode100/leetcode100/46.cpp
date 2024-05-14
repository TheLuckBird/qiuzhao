//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    void dfs(vector<vector<int>>& ans,vector<int>& output,int first,int len)
//    {
//        if (first == len)
//        {
//            ans.emplace_back(output);
//            return;
//        }
//
//        for (int i = first; i != len; ++i)
//        {
//            swap(output[i], output[first]);
//            dfs(ans, output, first + 1, len);
//            swap(output[i], output[first]);
//        }
//    }
//
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> ans;
//
//        dfs(ans,nums,0,(int)nums.size());
//
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<int> nums = { 1,2,3,4 };
//    Solution s;
//    s.permute(nums);
//    return 0;
//}