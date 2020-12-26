//
//  offer_59_滑动窗口的最大值.cpp
//  testC++++
//
//  Created by ykh on 2020/9/17.
//

#import "offer_59_滑动窗口的最大值.hpp"
#import "common.h"

//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
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
//你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
//
//注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    if (k == 1 || nums.size() < 2) {
            return nums;
        }
        
        int size = nums.size();
        int count = size - k + 1;
        
        vector<int> maxSlidingWindow;
        queue<int> myqueue;
        
        for (int i = 0; i<count; i++) {
            for (int j =0; j<k; j++) {
                int cur = nums[i+j];
                if (myqueue.size() > 0) {
                    int front = myqueue.front();
                    if (front < cur) {
                        while (myqueue.size()>0) {
                            myqueue.pop();
                        }
                    }
                }
                myqueue.push(cur);
            }
            maxSlidingWindow.push_back(myqueue.front());
            myqueue.pop();
        }
        
        return maxSlidingWindow;
    }


vector<int> maxSlidingWindow2(vector<int>& nums, int k) {

    int size = nums.size();
    if (k == 1 || size < 2) {
        return nums;
    }
    
    int count = size - k + 1;
    
    vector<int> maxSlidingWindow;
    deque<int> myqueue;
    
    for (int i = 0; i<size; i++) {
        int cur = nums[i];
        int low = i-k;
        if (low >=0) {
            if (myqueue.front() == nums[low]) {
                myqueue.pop_front();
            }
        }
        if (!myqueue.empty()) {
            int front = myqueue.front();
            if (front >= cur) {
                while (myqueue.size()>0 && myqueue.back()<cur) {
                    myqueue.pop_back();
                }
            }else{
                while (!myqueue.empty()) {
                    myqueue.pop_back();
                }
            }
        }
        myqueue.push_back(cur);
        if (i < k-1) {
            
        }else{
            maxSlidingWindow.push_back(myqueue.front());
        }
    }
    
    return maxSlidingWindow;
}

void _offer_59_test(){
    vector<int> v1 = {1,3,-1,-3,5,3,6,7};
    vector<int> v2 = {7,2,4};
    vector<int> v3 = {1,3,1,2,0,5};
    
    vector<int> res1 = maxSlidingWindow2(v1, 3); //3,3,5,5,6,7
    vector<int> res2 = maxSlidingWindow2(v2, 2); //7,4
    vector<int> res3 = maxSlidingWindow2(v3, 3); //3,3,2,5
    
}
