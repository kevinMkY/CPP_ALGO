//
//  剑指 Offer 58 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 58 - I. 翻转单词顺序.hpp"
#include "common.h"

string reverseWords(string s) {

    
    vector<string>vc;
    
    int l = (int)s.length();
    if (l== 0) {
        return "";
    }
    int left = 0;
    int right = l-1;
    //去除收尾
    while (s[left] == ' ' && left < right) {
        left++;
    }
    while (s[right] == ' '&& left < right) {
        right--;
    }
    
    deque<string>myqueue;
    string word;
    
    while (left <= right) {
        if (s[left] == ' ') {   //遇到空格
            if (word.size()) {
                myqueue.push_front(word);
                word ="";
            }
        }else{
            word+=s[left];
        }
        left++;
    }
    myqueue.push_front(word);
    
    string res = "";
    while (myqueue.size()) {
        res+=myqueue.front();
        myqueue.pop_front();
        if (myqueue.size()) {
            res+=" ";
        }
    }
    
    return res;
    }

void _offer_58_repeat_test()
{
    string s = reverseWords("a good   example");
    
}
