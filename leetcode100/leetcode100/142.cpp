//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode* next;
//    bool flag = false;
//    ListNode(int x) : val(x), next(nullptr) {}
//    
//};
//
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        while (head)
//        {
//            if (head->flag) return head;
//            else
//            {
//                head->flag = true;
//                head = head->next;
//            }
//        }
//        return nullptr;
//    }
//};
//
//int main()
//{
//    ListNode* p1 = new ListNode(3);
//    ListNode* p2 = new ListNode(2);
//    ListNode* p3 = new ListNode(0);
//    ListNode* p4 = new ListNode(-4);
//    p1->next = p2;
//    p2->next = p3;
//    p3->next = p4;
//    p4->next = p1;
//
//    Solution s;
//    ListNode *p = s.detectCycle(p1);
//    cout << p->val << endl;
//    return 0;
//}