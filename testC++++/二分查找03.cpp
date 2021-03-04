//
//  二分查找03.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/4.
//

#include "二分查找03.hpp"
#include "common.h"

//返回待插入的序号
int binarySearch(vector<int> list1,int k){
    int l = 0;
    int r = list1.size();
    int mid = l;
    while (l<r) {
        mid = l+((r-l)>>1);
        if (k == list1[mid]) {
            return mid;
        }else if(k < list1[mid]){
            r = mid;
        }else if(k > list1[mid]){
            l = mid;
        }
    }
    return 0;
}

void _facetest_03_test()
{
    
    vector<int> list1 = {1,2,4,9,10};
//    vector<int> list2 = {2,3,4};
    int res1 = binarySearch(list1,3);
    
    
}
