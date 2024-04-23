//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
////class Solution {
////public:
////    int maxSubArray(vector<int>& nums) {
////        int ans = nums[0];
////
////        for (int i = 0; i != nums.size(); ++i)
////        {
////            int tmp = nums[i];
////            for (int j = i; j != nums.size() - 1;)
////            {
////                ans = max(tmp, ans);//����Ԫ��Ҳ���������������飬����ȱȽ��ټ������ĺ�
////                tmp += nums[++j];
////            }
////            ans = max(tmp, ans);//���һ��Ҳ����������
////        }
////        return ans;
////    }
////};
//
//
////1.�±��Ԫ�صĺ���
////2.��f(i) = f(i-1) + nums[i] �� f(i) = nums[i],��f(i) = max(f(i-1) + nums[i],nums[i])
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans = nums[0];
//
//        int sum = 0;
//        
//        for (const auto& i : nums)
//        {
//            sum = max(sum + i, i);
//            ans = max(ans, sum);
//            
//            cout << sum << " ";
//        }
//        return ans;
//    }
//};
//
//
//int main()
//{
//    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    vector<int> nums2 = { -1, 0, 2};
//
//    Solution s;
//    int ans = s.maxSubArray(nums1);
//    cout << endl << ans << endl;
// }