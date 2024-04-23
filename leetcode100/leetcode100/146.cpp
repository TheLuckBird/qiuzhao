//#include <map>
//
//using namespace std;
//
//struct DLinkedNode
//{
//    DLinkedNode* pre;
//    DLinkedNode* next;
//
//    int key;
//    int val;
//
//    DLinkedNode()
//    {
//        pre = nullptr;
//        next = nullptr;
//        key = 0; 
//        val = 0;
//    }
//};
//
//class LRUCache {
//private:
//    DLinkedNode* head;
//    DLinkedNode* tail;
//    map<int, DLinkedNode*> m_cache;
//    int m_capacity;
//    int size;
//
//public:
//    LRUCache(int capacity) {
//        m_capacity = capacity;
//        size = 0;
//
//        head = new DLinkedNode();
//        tail = new DLinkedNode();
//
//        head->next = tail; 
//        tail->pre = head;
//    }
//
//    int get(int key) {
//        if (m_cache.find(key) == m_cache.end())
//            return -1;
//
//        DLinkedNode* node = m_cache[key];
//        moveToHead(node);
//        return node->val;
//    }
//
//    void put(int key, int value) {
//        if (m_cache.find(key) == m_cache.end())
//        {
//            DLinkedNode* node = new DLinkedNode();
//            node->key = key;
//            node->val = value;
//
//            m_cache[key] = node;
//            addToHead(node);
//            ++size;
//            if (size > m_capacity)
//            {
//                DLinkedNode* removed = removeTail();
//                m_cache.erase(removed->key);
//                delete removed;
//                --size;
//            }
//        }
//        else
//        {
//            DLinkedNode* node = m_cache[key];
//            node->val = value;
//            addToHead(node);
//        }
//    }
//
//    void removeNode(DLinkedNode* node)
//    {
//        node->pre->next = node->next;
//        node->next->pre = node->pre;
//    }
//
//    void addToHead(DLinkedNode* node)
//    {
//        node->pre = head;
//        node->next = head->next;
//        head->next->pre = node;
//        head->next = node;
//    }
//
//    void moveToHead(DLinkedNode* node)
//    {
//        removeNode(node);
//        addToHead(node);
//    }
//
//    DLinkedNode* removeTail()
//    {
//        DLinkedNode* node = tail->pre;
//        removeNode(node);
//        return node;
//    }
//
//
//};
