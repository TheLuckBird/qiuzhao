//#include <iostream>
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
//    pair<ListNode*, ListNode*> reverse(ListNode *head,ListNode *tail)
//    {
//        ListNode* prev = tail->next;
//        ListNode* p = head;
//
//        while (prev != tail)
//        {
//            ListNode* nex = p->next;
//            p->next = prev;
//            prev = p;
//            p = nex;
//        }
//
//        return { tail, head };
//    }
//    ListNode* reverseKGroup(ListNode* head, int k) 
//    {
//        ListNode* hair = new ListNode(0);
//        hair->next = head;
//        ListNode* pre = hair;
//
//        while (head)
//        {
//            ListNode* tail = pre;
//            for (int i = 0; i != k; i++)
//            {
//                tail = tail->next;
//                if (!tail)
//                {
//                    return hair->next;
//                }
//            }
//
//            ListNode* nex = tail->next;
//            pair<ListNode*, ListNode*> res = reverse(head, tail);
//            head = res.first;
//            tail = res.second;
//
//            pre->next = head;
//            tail->next = nex;
//            pre = tail;
//            head = tail->next;
//        }
//        return hair->next;
//    }
//};
//
//int main()
//{
//    ListNode* a4 = new ListNode(4, nullptr);
//    ListNode* a3 = new ListNode(3, a4);
//    ListNode* a2 = new ListNode(2, a3);
//    ListNode* a1 = new ListNode(1, a2);
//
//    Solution s;
//    ListNode* ans = s.reverseKGroup(a1,4);
//
//    while (ans)
//    {
//        cout << ans->val << " ";
//        ans = ans->next;
//    }
//    return 0;
//}