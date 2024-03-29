//
//  20_有效的括号.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#import "20_有效的括号.hpp"
#import "common.h"
//
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//示例 1:
//
//输入: "()"
//输出: true
//示例 2:
//
//输入: "()[]{}"
//输出: true
//示例 3:
//
//输入: "(]"
//输出: false
//示例 4:
//
//输入: "([)]"
//输出: false
//示例 5:
//
//输入: "{[]}"
//输出: true
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/valid-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool isValid(string s) {
    
    stack<string> mystack;
    int length = s.size();
    
    if (length%2==1) {
        return false;
    }
    
    for (int i = 0; i<length; i++) {
        string c = s.substr(i,1);
        bool res1 = !c.compare("{");
        bool res2 = !c.compare("(");
        bool res3 = !c.compare("[");
        if (res1 || res2 || res3) {
            mystack.push(c);
        }else{
            if (mystack.empty()) {
                return false;
            }
            string d = mystack.top();
            if (!d.compare("{") && !c.compare("}")) {
                
            }else if (!d.compare("(") && !c.compare(")")) {
                
            }else if (!d.compare("[") && !c.compare("]")) {
                
            }else{
                return false;
            }
            mystack.pop();
        }

    }
    
    return mystack.empty();
}

void _20_test(){
    string s = "){";
    bool isValidRes = isValid(s);
    
}
