//
//  933_最近的请求次数.cpp
//  testC++++
//
//  Created by ykh on 2020/9/17.
//

#include "933_最近的请求次数.hpp"
#include "common.h"

//写一个 RecentCounter 类来计算最近的请求。
//
//它只有一个方法：ping(int t)，其中 t 代表以毫秒为单位的某个时间。
//
//返回从 3000 毫秒前到现在的 ping 数。
//
//任何处于 [t - 3000, t] 时间范围之内的 ping 都将会被计算在内，包括当前（指 t 时刻）的 ping。
//
//保证每次对 ping 的调用都使用比之前更大的 t 值。
//
//
//
//示例：
//
//输入：inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
//输出：[null,1,2,3,3]
//
//
//提示：
//
//每个测试用例最多调用 10000 次 ping。
//每个测试用例会使用严格递增的 t 值来调用 ping。
//每次调用 ping 都有 1 <= t <= 10^9。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/number-of-recent-calls
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class RecentCounter {
public:
    queue<int> myqueue;
    RecentCounter() {

    }
    
    int ping(int t) {
        
        if (myqueue.size() == 0) {
            myqueue.push(t);
        }else{
            while (myqueue.size() > 0 && myqueue.front()<(t-3000)) {
                myqueue.pop();
            }
            myqueue.push(t);
        }
        return myqueue.size();
    }
};

void _933_test(){
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(642);
    int param_2 = obj->ping(1849);
    int param_3 = obj->ping(4921);
    int param_4 = obj->ping(5936);
    
}
