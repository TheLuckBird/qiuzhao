//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Trie {
//private:
//    vector<Trie*> children;
//    bool isEnd;
//
//public:
//    Trie():children(26),isEnd(false) {
//
//    }
//
//    void insert(string word) {
//        Trie* node = this;
//
//        for (auto ch : word)
//        {
//            ch -= 'a';
//            if (node->children[ch] == nullptr)
//            {
//                node->children[ch] = new Trie();
//            }
//            node = node->children[ch];
//        }
//
//        node->isEnd = true;
//    }
//
//    bool search(string word) {
//        Trie* res = this->searchPrefix(word);
//
//        return res != nullptr && res->isEnd;
//    }
//
//    bool startsWith(string prefix) {
//        return this->searchPrefix(prefix) != nullptr;
//    }
//
//    Trie* searchPrefix(string prefix)
//    {
//        Trie* node = this;
//
//        for (auto ch : prefix)
//        {
//            if (node->children[ch] == nullptr)
//            {
//                return nullptr;
//            }
//            node = node->children[ch];
//        }
//        return node;
//    }
//};
//
///**
// * Your Trie object will be instantiated and called as such:
// * Trie* obj = new Trie();
// * obj->insert(word);
// * bool param_2 = obj->search(word);
// * bool param_3 = obj->startsWith(prefix);
// */