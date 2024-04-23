//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = nullptr;
//        random = nullptr;
//    }
//};
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        Node* a = head;
//        Node* p = new Node(head->val);
//        a = a->next;
//        vector<int> indexv;
//        Node* ans = p;
//
//        while (a)
//        {
//            Node* q = new Node(a->val);
//            p->next = q;
//            p = q;
//            a = a->next;
//        }
//
// /*       while (ans)
//        {
//            cout << ans->val << " ";
//            ans = ans->next;
//        }*/
//
//        Node* b = head;
//        while (head)
//        {
//            if (!head->random)
//                indexv.push_back(-1);
//            else
//            {
//                Node* tmp = b;
//                int index = 0;
//                while (tmp != head->random)
//                {
//                    tmp = tmp->next;
//                    ++index;
//                }
//                indexv.push_back(index);
//            }
//            head = head->next;
//        }
//
//        //cout << endl;
//        //for (int i = 0; i != indexv.size(); ++i)
//        //{
//        //    cout << indexv[i] << " ";
//        //}
//
//        head = ans;
//        Node* c = ans;
//        for (int i = 0; i != indexv.size(); ++i)
//        {
//            if (indexv[i] == -1)
//            {
//                head->random = nullptr;
//            }
//            else
//            {
//                int k = indexv[i];
//                Node* d = c;
//                for (int j = 0; j != k; ++j)
//                {
//                    d = d->next;
//                }
//                head->random = d;
//            }
//            head = head->next;
//        }
//
//
//        return ans;
//    }
//};
//
////class Solution {
////public:
////    Node* copyRandomList(Node* head) {
////        if (head == nullptr) return nullptr;
////        Node* cur = head;
////        unordered_map<Node*, Node*> map;
////        // 3. ���Ƹ��ڵ㣬������ ��ԭ�ڵ� -> �½ڵ㡱 �� Map ӳ��
////        while (cur != nullptr) {
////            map[cur] = new Node(cur->val);
////            cur = cur->next;
////        }
////        cur = head;
////        // 4. ����������� next �� random ָ��
////        while (cur != nullptr) {
////            map[cur]->next = map[cur->next];
////            map[cur]->random = map[cur->random];
////            cur = cur->next;
////        }
////        // 5. �����������ͷ�ڵ�
////        return map[head];
////    }
////};
//
//int main()
//{
//    Node* p5 = new Node(1);
//    Node* p4 = new Node(10);
//    Node* p3 = new Node(11);
//    Node* p2 = new Node(13);
//    Node* p1 = new Node(7);
//    p5->next = nullptr;
//    p5->random = p1;
//    p4->next = p5;
//    p4->random = p3;
//    p3->next = p4;
//    p3->random = p5;
//    p2->next = p3;
//    p2->random = p1;
//    p1->next = p2;
//    p1->random = nullptr;
//
//    Solution s;
//    Node* ans = s.copyRandomList(p1);
//    int i = 0;
//    while (ans)
//    {
//        if (!ans->random)
//            cout << ans->val << " " << "null" << endl;
//        else
//            cout << ans->val << " " << i  << endl;
//        ++i;
//        ans = ans->next;
//    }
//    return 0;
//}