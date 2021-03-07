//
//  题库11大数加法.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/7.
//

#include "题库11大数加法.hpp"
#include "common.h"

string _tk_11_test_solve(string s, string t) {
    if(s.length() == 0)return t;
            if(t.length() == 0)return s;
            if(s.length() < t.length()) swap(s,t);
            string res;
            res.resize(s.length());
            int modify = s.length()-t.length();
            for(int i = 0;i<modify;i++){
                t ='0'+t;
            }
            int tmp = 0,carry = 0;
            for(int i = s.length()-1;i>=0;i--){
                tmp = s[i]-'0'+t[i]-'0'+carry;
                carry=tmp/10;
                tmp=tmp%10;
                res[i]=tmp+'0';
            }
            if(carry){
                res='1'+res;
            }
            return res;
}

void _tk_11_test()
{
    string res = _tk_11_test_solve("1","99");
    
}
