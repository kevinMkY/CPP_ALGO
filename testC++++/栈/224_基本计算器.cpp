//
//  224_基本计算器.cpp
//  testC++++
//
//  Created by ykh on 2020/9/15.
//

#include "224_基本计算器.hpp"
#include "common.h"

//实现一个基本的计算器来计算一个简单的字符串表达式的值。
//
//字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
//
//示例 1:
//
//输入: "1 + 1"
//输出: 2
//示例 2:
//
//输入: " 2-1 + 2 "
//输出: 3
//示例 3:
//
//输入: "(1+(4+5+2)-3)+(6+8)"
//输出: 23
//说明：
//
//你可以假设所给定的表达式都是有效的。
//请不要使用内置的库函数 eval。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/basic-calculator
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int calculate(string s) {

    stack<string> mystack;
    string calus = s.append("@");
    
    int size = calus.size();
    
    for (int i = 0; i<size; i++) {
        string c = calus.substr(i,1);
        bool res1 = !c.compare("(");
        bool res2 = !c.compare(")");
        bool res3 = !c.compare("+");
        bool res4 = !c.compare("-");
        bool res5 = !c.compare(" ");
        bool res6 = !c.compare("@");
        
        if (res5) {   //空格
            
        }else if (res1 || res2){    //()
            
        }else if (res3 || res4 || res6){    //+-
            
            int size = mystack.size();
            if (size > 2) { //需要将之前的数据先运算
                string numstr1 = mystack.top();
                mystack.pop();
                string symstr = mystack.top();
                mystack.pop();
                string numstr2 = mystack.top();
                mystack.pop();
                
                int num2 = atoi(numstr1.c_str());
                int num1 = atoi(numstr2.c_str());
                
                res3 = !symstr.compare("+");
                res4 = !symstr.compare("-");
                
                if (res3) {
                    int result = num1 + num2;
                    string stringresult = to_string(result);
                    mystack.push(stringresult);
                }else{
                    int result = num1 - num2;
                    string stringresult = to_string(result);
                    mystack.push(stringresult);
                }
            }
            //将运算符压榨
            mystack.push(c);
        }else{
            //第一个数字直接压栈
            if (mystack.empty()) {
                mystack.push(c);
            }else{
                string pre = mystack.top();
                bool res5 = !pre.compare("+");
                bool res6 = !pre.compare("-");
                if (res5 || res6) { //代表前一个是运算符号,直接将新数字压栈
                    mystack.push(c);
                }else{  //代表前一个是数字,将两个数字拼接
                    pre = pre.append(c);
                    mystack.pop();
                    mystack.push(pre);
                }
            }
            
        }
    }
    
    if (mystack.empty()) {
        return 0;
    }
    mystack.pop();
    string finallyStr = mystack.top();
    int sum = atoi(finallyStr.c_str());
    return sum;
   }

//符号压榨
void _224_test(){
    string s1 = "1 + 1";                //2
    string s2 = " 2-1 + 2 ";            //3
    string s3 = "(1+(4+5+2)-3)+(6+8)";  //23
    string s4 = "2147";                 //2147
    string s5 = "1-11";                 //10
    string s6 = " 2 - ( 5 -6)";              //3
//    int sum1 = calculate(s1);
//    int sum2 = calculate(s2);
//    int sum3 = calculate(s3);
//    int sum4 = calculate(s4);
//    int sum5 = calculate(s5);
    int sum6 = calculate(s6);
    
}
