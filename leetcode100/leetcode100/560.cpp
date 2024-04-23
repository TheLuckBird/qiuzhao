//#include <vector> 
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int ans = 0;
//
//        for (int i = 0; i != nums.size(); ++i)
//        {
//            int sum = 0;
//                
//            for (int j = i; j != nums.size();++j)
//            {
//                sum = sum + nums[j];
//                if (sum == k)
//                {
//                    ++ans;
//                }      
//            }
//            
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> arr1 = { 1,1,1 };
//    vector<int> arr2 = { 0,0 };
//    vector<int> arr3 = {1,-1,0};
//    int ans = s.subarraySum(arr3,0);
//    cout << ans << endl;
//}