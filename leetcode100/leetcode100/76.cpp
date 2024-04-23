//#include <string>
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution {
//public:
//    //�����ִ��ж�
//    bool check()
//    {
//        for (const auto& pair : mpt)
//        {
//            if (mps[pair.first] < pair.second)//�ִ��ַ��������벻С��t�ַ�����
//                return false;
//        }
//        return true;
//    }
//
//    unordered_map<char, int> mpt, mps;
//
//    string minWindow(string s, string t) {
//        for (auto& c : t) 
//            ++mpt[c];
//
//        int l = 0, r = -1, len = s.size() + 1, ansL = -1;
//
//        while(r < int(s.size()))
//        {
//            if(mpt.find(s[++r]) != mpt.end())//�����������ţ�s��t���ַ�������ϣ��mps�����ж�
//                ++mps[s[r]];
//
//            while (check() && l <= r)//1�ж��Ƿ�Ϊ�����ִ���2�����������������3��С�Ӵ�
//            {
//                if (r - l + 1 < len)
//                {
//                    len = r - l + 1;//��С�Ӵ��ĳ���
//                    ansL = l;//��С�Ӵ�����ʼλ��
//                }
//                if (mpt.find(s[l]) != mpt.end())
//                    --mps[s[l]];//�ؽ������ִ���ϣ��ing
//
//                ++l;//�������
//            }
//        }
//        return ansL == -1 ? string() : s.substr(ansL, len);
//    }
//};
//
//int main()
//{
//    string s = "ADOBECODEBANC";
//    string t = "ABC";
//
//    Solution S;
//    string ans = S.minWindow(s, t);
//    cout << ans << endl;
//}