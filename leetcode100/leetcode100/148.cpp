//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        if (!head) return nullptr;
//
//        vector<int> vals;
//
//        ListNode* p = head;
//        while (p)
//        {
//            vals.push_back(p->val);
//            p = p->next;
//        }
//
//        sort(vals.begin(), vals.end());
//
//        p = head;
//        int i = 0;
//        while (p)
//        {
//            p->val = vals[i];
//            ++i;
//            p = p->next;
//        }
//       
//        return head;
//    }
//};
//
//int main()
//{
//    ListNode* l4 = new ListNode(3, nullptr);
//    ListNode* l3 = new ListNode(1, l4);
//    ListNode* l2 = new ListNode(2, l3);
//    ListNode* l1 = new ListNode(4, l2);
//
//    Solution s;
//    ListNode* ans = s.sortList(l1);
//    while (ans)
//    {
//        cout << ans->val << " ";
//        ans = ans->next;
//    }
//}