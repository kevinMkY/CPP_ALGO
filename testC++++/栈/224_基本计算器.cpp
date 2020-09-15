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

int calu(string stra,string sym,string strb)
{
    int a = atoi(stra.c_str());
    int b = atoi(strb.c_str());
    bool res3 = !sym.compare("+");
    bool res4 = !sym.compare("-");
    if (res3) {
        return a+b;
    }else if (res4){
        return a-b;
    }else{
        return 0;
    }
}

string calustr(stack<string> stack){
    
    int size = stack.size();
    
    while (size > 2) {
        string numa = stack.top();
        stack.pop();
        string sym = stack.top();
        stack.pop();
        string numb = stack.top();
        stack.pop();
        
        int result = calu(numa, sym, numb);
        stack.push(to_string(result));
        
        size = stack.size();
    }
    
    return stack.top();
}

int calculate(string s) {

    stack<string> finallystack;
    stack<string> mystack;
    stack<string> tempstack;
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
            
        }else if (res1){    //  (  直接入栈
            mystack.push(c);
        }else if (res2){    //  )，需要一直找到（）之间的所有，来计算压栈
            
            string nextstr = "";
            int stacksize = mystack.size();
            tempstack = {};
            while (nextstr.compare("(")) {
                if (nextstr.size() > 0) {
                    tempstack.push(nextstr);
                }
                nextstr = mystack.top();
                mystack.pop();
            }
            
            string result = calustr(tempstack);
            mystack.push(result);
            
        }else if (res3 || res4){    //+-
            //将运算符压榨
            mystack.push(c);
        }else if(res6){
            int stacksize = mystack.size();
            string nextstr = "";
            tempstack = {};
            while (stacksize>0) {
                nextstr = mystack.top();
                mystack.pop();
                tempstack.push(nextstr);
                stacksize = mystack.size();
            }
            string result = calustr(tempstack);
            
            finallystack.push(result);
        }else{
            //第一个数字直接压栈
            if (mystack.empty()) {
                mystack.push(c);
            }else{
                string pre = mystack.top();
                bool res5 = !pre.compare("+");
                bool res6 = !pre.compare("-");
                bool res7 = !pre.compare("(");
                if (res5 || res6 || res7) { //代表前一个是运算符号,直接将新数字压栈
                    mystack.push(c);
                }else{  //代表前一个是数字,将两个数字拼接
                    pre = pre.append(c);
                    mystack.pop();
                    mystack.push(pre);
                }
            }
            
        }
    }
    
    if (finallystack.empty()) {
        return 0;
    }else{
        string pre = finallystack.top();
        return atoi(pre.c_str());
    }
    
    
    return 0;
   }

//符号压榨
void _224_test(){
    string s1 = "1 + 1";                //2
    string s2 = " 2-1 + 2 ";            //3
    string s3 = "(1+(4+5+2)-3)+(6+8)";  //23
    string s4 = "2147";                 //2147
    string s5 = "1-11";                 //-10
    string s6 = " 2 - ( 5 -6)";              //3
    string s7 = " 2 - 1 + 2";              //3
    string s8 = "(1+(4+5+2)-3)+(6+8)";  //23
//    int sum1 = calculate(s1);
//    int sum2 = calculate(s2);
//    int sum3 = calculate(s3);
//    int sum4 = calculate(s4);
//    int sum5 = calculate(s5);
//    int sum6 = calculate(s6);
//    int sum7 = calculate(s7);
    int sum8 = calculate(s8);
    
}
