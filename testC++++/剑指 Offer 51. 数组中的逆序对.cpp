//
//  剑指 Offer 51.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 51. 数组中的逆序对.hpp"
#include "common.h"

int mergeAndCount(vector<int>& nums,vector<int>& temp,int l,int r){
    
    for (int i = l; i<=r; i++) {
        temp[i] = nums[i];
    }
    
    int mid = (l+r)>>1;
    int ll = l;
    int rl = mid+1;
    int count = 0;
    
    for (int k = l; k<=r; k++) {
        if (ll == mid +1) { //假设左边已经跨越mid的边界,直接把右边copy过去
            nums[k] = temp[rl];
            rl++;
        }else if (rl == r+1){
            nums[k] = temp[ll];
            ll++;
        }else if(temp[ll] <= temp[rl]){ //temp的左右部分对比,左边较小,直接放进去
            nums[k] = temp[ll];
            ll++;
        }else{  //右边较小
            nums[k] = temp[rl];
            rl++;
            count += (mid-ll+1);
        }
    }
    
    return count;
}

int mergeSort(vector<int>& nums,vector<int>& temp,int l,int r){
    if (l == r) {
        return 0;
    }
    int mid = (l+r)>>1;
    
    //分
    int res1 = mergeSort(nums, temp, l, mid) + mergeSort(nums, temp, mid+1, r);
    
    //
    int res2 = mergeAndCount(nums, temp, l, r);
    
    
    return res1 + res2;
}

int reversePairs(vector<int>& nums) {

    int l = 0;
    int r = (int)nums.size()-1;
    if (r < 0) {
        return 0;
    }
    vector<int>tmp(nums.size());
    int res = mergeSort(nums, tmp, l, r);
    return res;
    }

void _offer_51_repeat_test()
{
    vector<int> nums = {7,3,2,6,0,1,5,4};
    int res =  reversePairs(nums);
    
}
