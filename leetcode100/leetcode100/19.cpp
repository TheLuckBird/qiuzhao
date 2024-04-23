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
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* p = head;
//        int size = 0;
//
//        while (p)
//        {
//            ++size;
//            p = p->next;
//        }
//        p = head;
//        if (n == size)
//        {
//            head = head->next;
//        }
//        else
//        {
//            for (int i = 1; i != size; ++i)
//            {
//                if (i == size - n)
//                {
//                    p->next = p->next->next;
//                    break;
//                }
//                p = p->next;
//            }
//        }
//        return head;
//    }
//};
//
//int main()
//{
//    ListNode* a5 = new ListNode(10, nullptr);
//    ListNode* a4 = new ListNode(9, a5);
//    ListNode* a3 = new ListNode(3, a4);
//    ListNode* a2 = new ListNode(4, a3);
//    ListNode* a1 = new ListNode(2, a2);
//
//    Solution s;
//    ListNode *ans = s.removeNthFromEnd(a4,1);
//
//    while (ans)
//    {
//        cout << ans->val << " ";
//        ans = ans->next;
//    }
//    return 0;
//}