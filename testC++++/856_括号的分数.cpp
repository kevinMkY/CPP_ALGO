//
//  856_括号的分数.cpp
//  testC++++
//
//  Created by ykh on 2020/9/15.
//

#import "856_括号的分数.hpp"
#import "common.h"
//
//给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
//
//() 得 1 分。
//AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
//(A) 得 2 * A 分，其中 A 是平衡括号字符串。
// 
//
//示例 1：
//
//输入： "()"
//输出： 1
//示例 2：
//
//输入： "(())"
//输出： 2
//示例 3：
//
//输入： "()()"
//输出： 2
//示例 4：
//
//输入： "(()(()))"
//输出： 6
// 
//
//提示：
//
//S 是平衡括号字符串，且只含有 ( 和 ) 。
//2 <= S.length <= 50
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/score-of-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int score(int num) {
    int res = pow(2, num);
    
    return res;
}

//栈
int scoreOfParentheses(string S) {
    int sum = 0;
    int size = S.size();
    
    string pre;
    string cur;
    stack<string> mystack;
    for (int i = 0; i<size; i++) {
        cur = S.substr(i,1);
        if (i>0) {
            pre = S.substr(i-1,1);
        }
        if (!cur.compare("(")) {
            mystack.push(cur);
        }else if (!cur.compare(")")) {
            if (!pre.compare("(")) {
                int length = mystack.size();
                int prof = score(length-1);
                sum+=prof;
            }
            mystack.pop();
        }
    }
    
    return sum;
    }


#pragma mark ykh 等待补充----分治法

void _856_test(){
    string s1 = "()";
    string s2 = "(())";
    string s3 = "()()";
    string s4 = "(()(()))";
    string s5 = "(()())";
    string s6 = "()(()())";
    int isValidRes1 = scoreOfParentheses(s1);
    int isValidRes2 = scoreOfParentheses(s2);
    int isValidRes3 = scoreOfParentheses(s3);
    int isValidRes4 = scoreOfParentheses(s4);
    int isValidRes5 = scoreOfParentheses(s5);
    int isValidRes6 = scoreOfParentheses(s6);
    
}
