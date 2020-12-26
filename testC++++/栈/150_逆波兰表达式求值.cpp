//
//  150_逆波兰表达式求值.cpp
//  testC++++
//
//  Created by ykh on 2020/9/15.
//

#import "150_逆波兰表达式求值.hpp"
#import "common.h"
//
//根据 逆波兰表示法，求表达式的值。
//
//有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//
//
//说明：
//
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//
//
//示例 1：
//
//输入: ["2", "1", "+", "3", "*"]
//输出: 9
//解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//示例 2：
//
//输入: ["4", "13", "5", "/", "+"]
//输出: 6
//解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
//示例 3：
//
//输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//输出: 22
//解释:
//该算式转化为常见的中缀算术表达式为：
//  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
//
//
//逆波兰表达式：
//
//逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
//
//平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
//该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
//逆波兰表达式主要有以下两个优点：
//
//去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
//适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int evalRPN(vector<string>& tokens) {
    
    int size = tokens.size();
    
    stack<string> mystack;
    
    for (int i = 0; i<size; i++) {
        string c = tokens[i];
        
        bool res1 = !c.compare("+");
        bool res2 = !c.compare("-");
        bool res3 = !c.compare("*");
        bool res4 = !c.compare("/");
        
        if (res1 || res2 || res3 || res4) {
            int curLength = mystack.size();
            if (curLength > 1) {
                string stra = mystack.top();
                int b = atoi(stra.c_str());
                mystack.pop();
                string strb = mystack.top();
                int a = atoi(strb.c_str());
                mystack.pop();
                int res;
                if (res1) {
                    res = a + b;
                }else if (res2){
                    res = a - b;
                }else if (res3){
                    res = a * b;
                }else if (res4){
                    res = a / b;
                }
                mystack.push(to_string(res));
            }else{
                return 0;
            }
        }else{
            mystack.push(c);
        }
    }
    
    if (mystack.empty()) {
        return 0;
    }
    string strres = mystack.top();
    int sum = atoi(strres.c_str());
    return sum;
    }

void _150_test(){
    vector<string> strs1 = {"2","1","+","3","*"};
    vector<string> strs2 = {"4", "13", "5", "/", "+"};
    vector<string> strs3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> strs4 = {};
    int res1 = evalRPN(strs1);
    int res2 = evalRPN(strs2);
    int res3 = evalRPN(strs3);
    int res4 = evalRPN(strs4);
    
}
