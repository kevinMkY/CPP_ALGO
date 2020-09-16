//
//  offer_09_用两个栈实现队列.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#include "offer_09_用两个栈实现队列.hpp"
#include "common.h"

//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
//
//
//
//示例 1：
//
//输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
//示例 2：
//
//输入：
//["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
//[[],[],[5],[2],[],[]]
//输出：[null,-1,null,null,5,2]
//提示：
//
//1 <= values <= 10000
//最多会对 appendTail、deleteHead 进行 10000 次调用
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class CQueue {
public:
    stack<int> instack;
    stack<int> outstack;
    CQueue() {
        instack = {};
        outstack = {};
    }
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        checkStack();
        if (outstack.empty()) {
            return -1;
        }else{
            int res = outstack.top();
            outstack.pop();
            return res;
        }
    }
    
    void checkStack(){
        if (outstack.empty()) {
            while (!instack.empty()) {
                int res = instack.top();
                instack.pop();
                outstack.push(res);
            }
        }
    }
};

void _offer_09_test(){
    CQueue* obj = new CQueue();
    obj->appendTail(5);
    obj->appendTail(2);
    int param_2 = obj->deleteHead();
    
}
