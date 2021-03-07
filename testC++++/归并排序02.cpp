//
//  归并排序02.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/4.
//

#include "归并排序02.hpp"
#include "common.h"
#include<stdio.h>

void _facetest_03_test_merge(vector<int> &list1,vector<int> &temp,int l,int mid,int r){
    if (r-l<2) {
        return;
    }
    int ll = 0,lr=mid-l;
    int rl = mid,rr = r;
    int al = l;
    for (int i = ll; i<lr; i++) {
        temp[i] = list1[l+i];
    }
    
    //<=都优先将左边拿去覆盖,左边用完了之后,右边本来就是有序的,就不用继续了
    while (ll < lr) {
        //如果右边先用完,直接把剩余的左边依次覆盖过来就行
        if (rl < rr && list1[rl] < temp[ll]) {
            list1[al++] = list1[rl++];
        }else{
            list1[al++] = temp[ll++];
        }
    }
}

void _facetest_03_test_sort(vector<int> &list1,vector<int> &temp,int l,int r){
    if (r - l < 2) {
        return;
    }
    int mid = l+((r-l)>>1);
    _facetest_03_test_sort(list1,temp,l,mid);
    _facetest_03_test_sort(list1,temp,mid,r);
    _facetest_03_test_merge(list1,temp,l,mid,r);
}

vector<int> mergesort(vector<int> &list1){
    int n = list1.size();
    if (n < 2) {
        return list1;
    }
    vector<int> temp(n>>1);
    _facetest_03_test_sort(list1,temp,0,n);
    return list1;
}


vector<int> mergesort_index_3(vector<int> &list1,int l,int r){
    
    return list1;
}

vector<int> mergesort3(vector<int> &list1){
    
    
    return list1;
}

void _facetest_02_test()
{
    vector<int> list1 = {1,5,2,3,4};
//    vector<int> list2 = {2,3,4};
    vector<int> res1 = mergesort(list1);
    
}
