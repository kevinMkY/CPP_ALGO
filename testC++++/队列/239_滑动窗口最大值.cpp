//
//  239_滑动窗口最大值.cpp
//  testC++++
//
//  Created by ykh on 2020/9/17.
//

#import "239_滑动窗口最大值.hpp"
#import "common.h"

//
//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//
//返回滑动窗口中的最大值。
//
// 
//
//进阶：
//
//你能在线性时间复杂度内解决此题吗？
//
// 
//
//示例:
//
//输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7]
//解释:
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
//提示：
//
//1 <= nums.length <= 10^5
//-10^4 <= nums[i] <= 10^4
//1 <= k <= nums.length
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sliding-window-maximum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> maxSlidingWindow3(vector<int>& nums, int k) {

    int size = nums.size();
    if (size < 2 || k < 2) {
        return nums;
    }
    
    vector<int> res;
    deque<int> myqueue;
    for (int i = 0; i<size; i++) {
        int cur = nums[i];
        int low = i-k;
        if (low >= 0) {
            int last = nums[low];
            if (myqueue.size()>0 && myqueue.front() == last) {
                myqueue.pop_front();
            }
        }
        if (!myqueue.empty()) {
            int front = myqueue.front();
            if (front>=cur) {
                while (myqueue.back()<cur) {
                    myqueue.pop_back();
                }
            }else{
                while (!myqueue.empty()) {
                    myqueue.pop_back();
                }
            }
        }
        myqueue.push_back(cur);
        if (i<k-1) {
            
        }else{
            res.push_back(myqueue.front());
        }
    }
    
    return res;
    }

void _239_test(){
    vector<int> v1 = {1,3,-1,-3,5,3,6,7};
    vector<int> v2 = {7,2,4};
    vector<int> v3 = {1,3,1,2,0,5};
    
    vector<int> res1 = maxSlidingWindow3(v1, 3); //3,3,5,5,6,7
    vector<int> res2 = maxSlidingWindow3(v2, 2); //7,4
    vector<int> res3 = maxSlidingWindow3(v3, 3); //3,3,2,5
    
}
