//#include <vector> 
//#include <iostream>
//
//using namespace std;
//
//#if 0
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int maxarea = 0;
//        int temparea = 0;
//
//        for (auto i = height.begin(); i != height.end(); ++i)
//        {
//            for (auto j = i + 1; j != height.end(); ++j)
//            {
//                temparea = (j - i) * min(*i,*j);
//                maxarea = max(temparea, maxarea);
//            }
//        }
//
//        return maxarea;
//    }
//};
//#endif
//
//#if 1
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int l = 0, r = height.size() - 1;
//        int ans = 0;
//        while (l < r) {
//            int area = min(height[l], height[r]) * (r - l);
//            ans = max(ans, area);
//            if (height[l] <= height[r]) {
//                ++l;
//            }
//            else {
//                --r;
//            }
//        }
//        return ans;
//    }
//};
//#endif

//int main()
//{
//    vector<int> height1 = { 1,8,6,2,5,4,8,3,7 };
//    vector<int> height2 = { 1,1 };
//
//    Solution s;
//
//    int ans = s.maxArea(height1);
//
//    cout << ans << endl;
//}