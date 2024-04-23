//#include <vector>
//#include <queue>
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
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> ans;
//
//        if (!root) return ans;
//
//        queue<TreeNode*> values;
//        values.push(root);
//
//        while (!values.empty())
//        {
//            int levelSize = values.size();
//            ans.push_back(vector<int>());
//
//            for (int i = 0; i != levelSize; ++i)
//            {
//                TreeNode* node = values.front();
//                values.pop();
//                ans.back().push_back(node->val);
//
//                if (node->left)
//                    values.push(node->left);
//                if (node->right)
//                    values.push(node->right);
//            }
//
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    TreeNode* l3l = new TreeNode(15, nullptr, nullptr);
//    TreeNode* l3r = new TreeNode(7, nullptr, nullptr);
//    TreeNode* l2l = new TreeNode(9, nullptr, nullptr);
//    TreeNode* l2r = new TreeNode(20, l3l, l3r);
//    TreeNode* root = new TreeNode(3, l2l, l2r);
//
//    Solution s;
//    vector<vector<int>> ans = s.levelOrder(root);
//    cout << "[";
//    for (auto& v : ans)
//    {
//        cout << "[";
//        for (auto& x : v)
//        {
//            cout<< " " << x << " ";
//        }
//        cout << "]";
//    }
//    cout << "]";
//    return 0;
//}