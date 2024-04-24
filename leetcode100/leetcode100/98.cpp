//#include <iostream>
//
//using namespace std;
//
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
//class Solution {
//public:
//    bool helper(TreeNode* root, long long lower, long long uper)
//    {
//        if (!root)
//            return true;
//        if (root->val <= lower || root->val >= uper)
//            return false;
//        return helper(root->left, lower, root->val) && helper(root->right, root->val, uper);
//    }
//
//    bool isValidBST(TreeNode* root) {
//        return helper(root, LONG_MIN, LONG_MAX);
//    }
//};
//
//int main()
//{
//    TreeNode* a = new TreeNode(3, nullptr, nullptr);
//    TreeNode* b = new TreeNode(6, nullptr, nullptr);
//    TreeNode* left = new TreeNode(1, nullptr, nullptr);
//    TreeNode* right = new TreeNode(4, a, b);
//    TreeNode* root = new TreeNode(5,left,right);
//
//    Solution s;
//    auto ans = s.isValidBST(root);
//    cout << ans << endl;
//}