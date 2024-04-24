//#include <iostream>
//#include <vector>
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
//    void helper(TreeNode* root, vector<int>& v)
//    {
//        if (!root)
//            return;
//        helper(root->left, v);
//        v.push_back(root->val);
//        helper(root->right, v);
//    }
//
//    int kthSmallest(TreeNode* root, int k) {
//        vector<int> v;
//
//        helper(root, v);
//
//        return v[k - 1];
//
//    }
//};
//
//int main()
//{
//    TreeNode* t1 = new TreeNode(2, nullptr, nullptr);
//    TreeNode* t2 = new TreeNode(1, nullptr, t1);
//    TreeNode* t3 = new TreeNode(4, nullptr, nullptr);
//    TreeNode* root = new TreeNode(3, t2, t3);
//
//    Solution s;
//    auto ans = s.kthSmallest(root, 1);
//    cout << ans << endl;
//    return 0;
//}