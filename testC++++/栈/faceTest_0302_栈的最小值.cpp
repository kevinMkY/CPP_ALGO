//
//  faceTest_0302_栈的最小值.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#import "faceTest_0302_栈的最小值.hpp"
#import "common.h"

//请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。
//
//
//示例：
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/min-stack-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class MinStack {
public:
    stack<int> normalStack;
    stack<int> minStack;
    
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        normalStack.push(x);
        
        if (minStack.size()>0) {
            int min = minStack.top();
            if (min < x) {
                minStack.push(min);
            }else{
                minStack.push(x);
            }
        }else{
            minStack.push(x);
        }
    }
    
    void pop() {
        normalStack.pop();
        minStack.pop();
    }
    
    int top() {
        return normalStack.top();;
    }
    
    int getMin() {
        return minStack.top();;
        return 0;
    }
};

void _facetest_0302_test(){
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    int num1 = minStack.getMin();   //--> 返回 -3.
    minStack.pop();
    minStack.top();      //--> 返回 0.
    int num2 = minStack.getMin();   //--> 返回 -2.

    
}
