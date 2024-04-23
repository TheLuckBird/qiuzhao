//#include <iostream>
//#include <vector>
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
//    ListNode* mergetwoList(ListNode* a, ListNode* b)
//    {
//        if ((!a) || (!b)) return a ? a : b;
//
//        ListNode* p = a;
//        ListNode* q = b;
//
//        ListNode* res = new ListNode(0);
//        ListNode* tmp = res;
//
//        while (p && q)
//        {
//            if (p->val < q->val)
//            {
//                tmp->next = p;
//                p = p->next;
//            }
//            else
//            {
//                tmp->next = q;
//                q = q->next;
//            }
//            tmp = tmp->next;
//        }
//
//        if (p)
//            tmp->next = p;
//        if (q)
//            tmp->next = q;
//        
//        return res->next;
//    }
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        int n = lists.size();
//        ListNode* ans = nullptr;
//
//        for(int i = 0;i != n;++i)
//        {
//            ans = mergetwoList(ans, lists[i]);
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    ListNode* a3 = new ListNode(5, nullptr);
//    ListNode* a2 = new ListNode(4, a3);
//    ListNode* a1 = new ListNode(1, a2);
//    ListNode* b3 = new ListNode(4, nullptr);
//    ListNode* b2 = new ListNode(3, b3);
//    ListNode* b1 = new ListNode(1, b2);
//    ListNode* c2 = new ListNode(6, nullptr);
//    ListNode* c1 = new ListNode(2, c2);
//
//    vector<ListNode*> lists = { a1,b1,c1 };
//
//    Solution s;
//    ListNode* ans = s.mergeKLists(lists);
//    while (ans)
//    {
//        cout << ans->val << " ";
//        ans = ans->next;
//    }
//    return 0;
//}