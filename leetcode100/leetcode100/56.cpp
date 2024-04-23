//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> ans;
//
//        sort(intervals.begin(), intervals.end());
//        ans.push_back(intervals[0]);
//        int size = 1;
//
//       for (int i = 1; i != intervals.size(); ++i)
//        {
//            vector<int> tmp = intervals[i];
//
//            //相容
//            if (*tmp.begin() >= *ans[size - 1].begin() && *(tmp.end()-1) <= *(ans[size - 1].end()-1))
//                continue;
//            //不相交
//            else if (*tmp.begin() > *(ans[size-1].end() - 1))
//            {
//                ++size;
//                ans.push_back(tmp);
//            }
//            //相交
//            else
//            {
//                int left = min(*tmp.begin(), *ans[size - 1].begin());
//                int right = max(*(tmp.end()-1), *(ans[size - 1].end()-1));
//                ans.back()[0] = left;
//                ans[size-1][1] = right;
//            }
//        }
//
//        //for (int i = 1; i < intervals.size(); ++i) {
//        //    if (intervals[i][0] <= ans.back()[1]) { // 如果当前区间与上一个区间重叠
//        //        ans.back()[1] = max(ans.back()[1], intervals[i][1]); // 更新上一个区间的结束位置
//        //    }
//        //    else { // 如果不重叠，则将当前区间加入结果中
//        //        ans.push_back(intervals[i]);
//        //    }
//        //}
//        
//
//        return ans;
//    }
//};
//
//int main()
//{
//    vector<vector<int>> intervals1 = { {1,3},{2,6},{8,10},{15,18} };
//    vector<vector<int>> intervals2 = { {2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6} };
//
//    Solution s;
//    vector<vector<int>> ans = s.merge(intervals2);
//    for (int i = 0; i != ans.size(); ++i)
//    {
//        for (const auto& x : ans[i])
//        {
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//}