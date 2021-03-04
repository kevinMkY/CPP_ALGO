//
//  二分查找03.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/4.
//

#include "二分查找03.hpp"
#include "common.h"

//返回查找数字的序号，找不到返回-1
int binarySearch(vector<int> list1,int k){
    //区间[l,r)
    int l = 0;
    int r = list1.size();
    int mid = l;
    while (l<r) {
        //l+r可能溢出，用l+差值的一半，就不会溢出
        mid = l+((r-l)>>1);
        if (k == list1[mid]) {
            return mid;
        }else if(list1[mid] > k){
            //记住，当前是k <[mid,r)
            r = mid;
        }else if(list1[mid] < k){
            //记住，当前是[l,mid) < k
            l = mid;
        }
    }
    return -1;
}

void _facetest_03_test()
{
    
    vector<int> list1 = {1,2,4,9,10};
//    vector<int> list2 = {2,3,4};
    int res1 = binarySearch(list1,4);
    
    
}
