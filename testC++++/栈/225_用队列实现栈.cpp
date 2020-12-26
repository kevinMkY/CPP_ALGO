//
//  225_用队列实现栈.cpp
//  testC++++
//
//  Created by ykh on 2020/9/17.
//

#import "225_用队列实现栈.hpp"
#import "common.h"

//
//使用队列实现栈的下列操作：
//
//push(x) -- 元素 x 入栈
//pop() -- 移除栈顶元素
//top() -- 获取栈顶元素
//empty() -- 返回栈是否为空
//注意:
//
//你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/implement-stack-using-queues
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class MyStack {
public:
    
    queue<int> myQueue;
    queue<int> myQueue2;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        while (myQueue.size() > 1) {
            int res = myQueue.front();
            myQueue.pop();
            myQueue2.push(res);
        }
        
        int topEle = myQueue.back();
        myQueue.pop();
        while (myQueue2.size() > 0) {
            int res = myQueue2.front();
            myQueue2.pop();
            myQueue.push(res);
        }
        
        return topEle;
    }
    
    /** Get the top element. */
    int top() {
        int topEle = myQueue.back();
        return topEle;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.size() == 0;
    }
};

void _225_test(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->top();
    int param_3 = obj->pop();
    bool param_4 = obj->empty();
    
}
