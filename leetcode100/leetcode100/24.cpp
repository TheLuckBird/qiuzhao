//#include <iostream>
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
//    ListNode* swapPairs(ListNode* head) {
//        if (!head || !head->next)
//            return head;
//
//        ListNode* p = head;
//        ListNode* q = p->next;
//
//        p->next = q->next;
//        q->next = p;
//        head = q;
//
//        while (p && q)
//        {
//            q = p->next;
//            p = p->next->next;
//            p->next = q->next;
//            q->next = p;
//        }
//        return head;
//    }
//};
//
//int main()
//{
//    ListNode *a4 = new ListNode(4, nullptr);
//    ListNode* a3 = new ListNode(3, a4);
//    ListNode* a2 = new ListNode(2, a3);
//    ListNode* a1 = new ListNode(1, a2);
//
//    Solution s;
//    ListNode *ans =  s.swapPairs(a1);
//
//    while (ans)
//    {
//        cout << ans->val << " ";
//        ans = ans->next;
//    }
//    return 0;
//}