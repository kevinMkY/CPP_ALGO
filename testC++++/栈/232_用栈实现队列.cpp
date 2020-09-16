//
//  232_用栈实现队列.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#include "232_用栈实现队列.hpp"
#include "common.h"

//232. 用栈实现队列
//使用栈实现队列的下列操作：
//
//push(x) -- 将一个元素放入队列的尾部。
//pop() -- 从队列首部移除元素。
//peek() -- 返回队列首部的元素。
//empty() -- 返回队列是否为空。
//
//
//示例:
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // 返回 1
//queue.pop();   // 返回 1
//queue.empty(); // 返回 false
//
//
//说明:
//
//你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

//https://leetcode-cn.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
        stack<int> instack;
        stack<int> outstack;
        /** Initialize your data structure here. */
        MyQueue() {
            
        }
        
        /** Push element x to the back of queue. */
        void push(int x) {
            instack.push(x);
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            int res = peek();
            if (outstack.empty()) {
                return 0;
            }
            outstack.pop();
            return res;
        }
        
        /** Get the front element. */
        int peek() {
            if (outstack.empty()) {
                while (!instack.empty()) {
                    int res = instack.top();
                    instack.pop();
                    outstack.push(res);
                }
            }
            if (outstack.empty()) {
                return 0;
            }
            int res = outstack.top();
            return res;
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return instack.empty() && outstack.empty();
        }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 
 */

void _232_test(){
    MyQueue queue = MyQueue();
    
    queue.push(1);
    queue.push(2);
    queue.peek();  // 返回 1
    queue.pop();   // 返回 1
    queue.empty(); // 返回 false
    
}
