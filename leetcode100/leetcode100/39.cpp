//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, int& target, int& sum, vector<int>& path,int index)
//    {
//        if (sum > target)
//            return;
//        if (sum == target)
//        {
//            ans.push_back(path);
//            return;
//        }
//
//        for (int i = index;i != candidates.size();++i)
//        {
//            sum += candidates[i];
//            path.push_back(candidates[i]);
//            backtrack(ans, candidates, target, sum, path, i);
//            sum -= candidates[i];
//            path.pop_back();
//        }
//    }
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> ans;
//        int sum = 0;
//        vector<int> path;
//
//        backtrack(ans, candidates, target, sum, path,0);
//            
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<int> candidates = { 2,3,6,7 };
//    int target = 7;
//
//    Solution s;
//    vector<vector<int>> ans = s.combinationSum(candidates, target);
//
//    for (auto v : ans)
//    {
//        for (auto i : v)
//        {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//}
//
