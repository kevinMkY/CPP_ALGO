//
//  剑指 Offer 40.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 40. 最小的k个数.hpp"
#include "common.h"

vector<int> getLeastNumbers(vector<int>& arr, int k) {

    sort(arr.begin(), arr.end());
    
    vector<int>res(arr.begin(),arr.begin()+k);
    
    return res;
   }


//优先级队列,大顶堆
vector<int> getLeastNumbers2(vector<int>& arr, int k) {

    int n = (int)arr.size();
    if (n==0 || k == 0) {
        return {};
    }
    
    vector<int>res;
    priority_queue<int> tmp;
    
    for (int i = 0; i<k; i++) {
        tmp.push(arr[i]);
    }
    
    for (int i = k; i<n; i++) {
        if (tmp.top() > arr[i]) {
            tmp.pop();
            tmp.push(arr[i]);
        }
    }
    
    while (tmp.size()) {
        res.push_back(tmp.top());
        tmp.pop();
    }
    
    return res;
   }

void _offer_40_repeat_test()
{
    vector<int> arr = {3,2,1};
    vector<int> arr2 = {0,0,0,2,0,5};
    vector<int> res = getLeastNumbers2(arr,0);
    
}
