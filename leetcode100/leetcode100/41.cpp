//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
////class Solution {
////public:
////    int firstMissingPositive(vector<int>& nums) {
////        sort(nums.begin(), nums.end());
////        
////        for (int i = 1; i != nums.size() + 2; ++i)
////        {
////            if (find(nums.begin(), nums.end(), i) == nums.end())
////                return i;
////        }
////    }
////};
//
//class Solution {
//public:
//    int firstMissingPositive(vector<int>& nums) {
//        int n = nums.size();
//        for (auto& x : nums)//��С��ʧ������ֻ��[1��N],�����ڴ˷�Χ�ڵ����ĳ�n+1,ֻ��<=0����
//        {
//            if (x <= 0)
//            {
//                x = n + 1;
//            }
//        }
//
//        for (int i = 0; i != n; ++i)//��Ԫ����ֵӳ��Ϊ���������Թ����ϣ����Ԫ��ֵ�޸�Ϊ����
//        {
//            int tmp = abs(nums[i]);
//            if (tmp <= n)
//            {
//                nums[tmp - 1] = -abs(nums[tmp - 1]);
//            }
//        }
//
//        for (int i = 0; i != n; ++i)
//        {
//            if (nums[i] > 0)
//                return i + 1;
//        }
//        return n + 1;
//    }
//};
//
//int main()
//{
//    vector<int> nums1 = { 1,2,0 };
//    vector<int> nums2 = { 3,4,-1,1 };
//    vector<int> nums3 = { 7,8,9,11,12 };
//    Solution s;
//    int ans = s.firstMissingPositive(nums2);
//    cout << ans;
//}