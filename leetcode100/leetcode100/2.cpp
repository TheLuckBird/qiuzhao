//#include <iostream>
//#include <string>
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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        int jinwei = 0;
//        ListNode* head = new ListNode();
//        ListNode* ans = head;
//
//        while (l1 && l2)
//        {
//            ListNode* tmp = new ListNode();
//            if (l1->val + l2->val + jinwei >= 10)
//            {
//                tmp->val = l1->val + l2->val - 10 + jinwei;
//                jinwei = 1;
//            }
//            else
//            {
//                tmp->val = l1->val + l2->val + jinwei;
//                jinwei = 0;
//            }
//            head->next = tmp;
//            head = head->next;
//            l1 = l1->next;
//            l2 = l2->next;
//        }
//
//        while (l1)
//        {
//            ListNode* tmp = new ListNode();
//            head->next = tmp;
//            head = head->next;
//            if (l1->val + jinwei >= 10)
//            {
//                tmp->val = l1->val + jinwei - 10;
//                jinwei = 1;
//            }
//            else
//            {
//                tmp->val = l1->val + jinwei;
//                jinwei = 0;
//            }
//            l1 = l1->next;
//        }
//
//        while (l2)
//        {
//            ListNode* tmp = new ListNode();
//            head->next = tmp;
//            head = head->next;
//            if (l2->val + jinwei >= 10)
//            {
//                tmp->val = l2->val + jinwei - 10;
//                jinwei = 1;
//            }
//            else
//            {
//                tmp->val = l2->val + jinwei;
//                jinwei = 0;
//            }
//            l2 = l2->next;
//        }
//        if (jinwei)
//        {
//            ListNode* tmp = new ListNode(1,nullptr);
//            head->next = tmp;
//            head = head->next;
//        }
//            
//
//        return ans->next;
//    }
//};
//
//int main()
//{
//    ListNode* a4 = new ListNode(9, nullptr);
//    ListNode *a3 = new ListNode(3, a4);
//    ListNode *a2 = new ListNode(4, a3);
//    ListNode *a1 = new ListNode(2, a2);
//
//    ListNode* b3 = new ListNode(7, nullptr);
//    ListNode* b2 = new ListNode(6, b3);
//    ListNode* b1 = new ListNode(5, b2);
//
//    Solution s;
//    ListNode *p = s.addTwoNumbers(b1, a1);
//
//    while (p)
//    {
//        cout << p->val;
//        p = p->next;
//    }
//    return 0;
//}