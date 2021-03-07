//
//  面试02,数组排序.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/5.
//

#include "题库02数组排序.hpp"
#include "common.h"

//------------------------快排------------------------

void _face_offer_02_test_quickSort(vector<int> &list,int l,int r){
    if (l>=r) {
        return;
    }
    int s = l,end = r;
    int pivont = list[l];
    while (s<end) {
        while (s<end && pivont <= list[end]) {end--;}
        while (s<end && pivont >= list[s])   {s++;}
        swap(list[s], list[end]);
    }
    swap(list[l], list[s]);
    _face_offer_02_test_quickSort(list, l, s-1);
    _face_offer_02_test_quickSort(list, s+1, r);
}

vector<int>  _face_offer_02_test_quickSort(vector<int> &list){
    _face_offer_02_test_quickSort(list, 0, list.size()-1);
    return list;
}

//------------------------快排------------------------


//------------------------归并------------------------
//[0,2)
//0,1,2
void mergesort_merge(vector<int> &list,int l,int mid,int r){
    if (r-l<2) {
        return;
    }
    int leftS = mid-l;
    vector<int>temp(leftS);
    
    int tl = 0,tr = leftS;
    int rl = mid,rr = r;
    int fl = l;
    for (int i = tl; i<tr; i++) {
        temp[i]=list[l+i];
    }
    while (tl<tr) {
        if (rl<rr && list[rl] <= temp[tl]) {
            list[fl++] = list[rl++];
        }else{
            list[fl++] = temp[tl++];
        }
    }
}

//左闭右开[0,2)
void mergesort_sort(vector<int> &list,int l,int r){
    //[0,2)
    if (r-l<2) {
        return;
    }
    int mid = l + ((r-l)>>1);
    mergesort_sort(list,l,mid);
    mergesort_sort(list,mid,r);
    mergesort_merge(list, l,mid, r);
}

vector<int> _face_offer_02_test_mergeSort(vector<int> &list){
    //[0,2)
    mergesort_sort(list,0,list.size());
    return list;
}

//------------------------归并------------------------


//------------------------二分------------------------
int _face_offer_02_test_quickSearch(vector<int> &list1,int k){
    
    int l = 0;
    int r = list1.size()-1;
    int mid = l;
    while (l<r) {
        mid = l+((r-l)>>1);
        if (list1[mid] == k) {
            return mid;
        }else if (list1[mid] > k) {
            r = mid;
        }else if (list1[mid] < k) {
            l = mid;
        }
    }
    
    return -1;
}
//------------------------二分------------------------



void _tk_02_test()
{
    vector<int> list1 = {5,2,3,1,4};
    vector<int> list2 = {7,6,4,8,1,9,2,10};
    vector<int> list3 = {1,3,5,7,9,10};
    vector<int> res1 = _face_offer_02_test_quickSort(list1);
    vector<int> res2 = _face_offer_02_test_mergeSort(list2);
    int res3 = _face_offer_02_test_quickSearch(list3,5);
    
}
