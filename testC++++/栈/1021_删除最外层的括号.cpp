//
//  1021_删除最外层的括号.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#include "1021_删除最外层的括号.hpp"
#include "common.h"

//有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
//
//如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
//
//给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
//
//对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。
//
// 
//
//示例 1：
//
//输入："(()())(())"
//输出："()()()"
//解释：
//输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
//删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
//示例 2：
//
//输入："(()())(())(()(()))"
//输出："()()()()(())"
//解释：
//输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
//删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
//示例 3：
//
//输入："()()"
//输出：""
//解释：
//输入字符串为 "()()"，原语化分解得到 "()" + "()"，
//删除每个部分中的最外层括号后得到 "" + "" = ""。
// 
//
//提示：
//
//S.length <= 10000
//S[i] 为 "(" 或 ")"
//S 是一个有效括号字符串
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/remove-outermost-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

string removeOuterParentheses(string S) {
    
    stack<string> stack1;
    string temp = "";
    int size = S.size();
    int a = 0;
    int b = 0;
    for (int i = 0; i<size; i++) {
        string charater = S.substr(i,1);
        bool res1 = !charater.compare("(");
        bool res2 = !charater.compare(")");
        if (res1) {
            a++;
        }else if(res2){
            a--;
        }
        temp = temp.append(charater);
        if (a==0) {
            stack1.push(temp);
            temp = "";
        }
    }
    
    string resstring;
    while (!stack1.empty()) {
        string res = stack1.top();
        stack1.pop();
        int size = res.size();
        if (size>1) {
            res = res.substr(1,size-2);
        }
        resstring = res.append(resstring);
    }
    
    return resstring;
    }

void _1021_test(){
    string s1 = "(()())(())";           //"()()()"
    string s2 = "(()())(())(()(()))";   //"()()()()(())"
    string s3 = "()()";                 //""
    string s4 = "(()(()))";
    string s5 = "(()())";
    string s6 = "()(()())";
    string isValidRes1 = removeOuterParentheses(s1);
    string isValidRes2 = removeOuterParentheses(s2);
    string isValidRes3 = removeOuterParentheses(s3);
//    int isValidRes4 = scoreOfParentheses(s4);
//    int isValidRes5 = scoreOfParentheses(s5);
//    int isValidRes6 = scoreOfParentheses(s6);
    
}
