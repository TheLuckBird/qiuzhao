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
//    void helper(TreeNode* root, vector<int>& nv)
//    {
//        if (!root)
//            return;
//        nv.push_back(root->val);
//        helper(root->left,nv);
//        helper(root->right,nv);
//    }
//
//    void flatten(TreeNode* root) {
//        if (!root)
//            return;
//
//        vector<int> nv;
//        helper(root, nv);
//
//        TreeNode* p = root;
//        for (int i =1;i!=nv.size();++i)
//        {
//            TreeNode* node = new TreeNode(nv[i]);
//            p->right = node;
//            p->left = nullptr;
//            p = p->right;
//        }
//
//        TreeNode* q = root;
//        while (q)
//        {
//            if (q->right)
//                cout << q->val << " " << "null" << " ";
//            else
//                cout << q->val;
//            q = q->right;
//        }
//    }
//};
//
//int main()
//{
//    TreeNode* n1 = new TreeNode(3, nullptr,nullptr);
//    TreeNode* n2 = new TreeNode(4, nullptr, nullptr);
//    TreeNode* n3 = new TreeNode(2, n1, n2);
//    TreeNode* n4 = new TreeNode(6, nullptr, nullptr);
//    TreeNode* n5 = new TreeNode(5, nullptr, n4);
//    TreeNode* root = new TreeNode(1, n3, n5);
//
//    Solution s;
//    s.flatten(root);
//}