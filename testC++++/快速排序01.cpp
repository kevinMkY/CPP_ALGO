//
//  快速排序01.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/4.
//

#include "快速排序01.hpp"
#include "common.h"

int getpivont(vector<int> &list,int start,int end)
{
    int pivont = list[start];
    while (start<end) {
        while (start<end) {
            if (pivont <= list[end]) {
                end--;
            }else{  //} if (pivont > list[end]) {
                list[start] = list[end];
                start++;
                break;
            }
        }
        while (start<end) {
            if (pivont <= list[start]) {
                list[end] = list[start];
                end--;
                break;
            }else{  //} if (pivont > list[start]) {
                start++;
            }
        }
    }
    list[start] = pivont;
    return start;
}

void quickSort(vector<int> &list,int start,int end){
    if (end - start < 2) {return;}
    
    int pivont = getpivont(list, start, end);
    quickSort(list,start,pivont);
    quickSort(list,pivont+1,end);
}

vector<int> quickSort(vector<int> &list){
    quickSort(list, 0, list.size());
    return list;
}


int getPivontIdx2(vector<int> &list,int l,int r){
    int pivont = list[l];
    while (l<r) {
        while (l<r) {
            //{1,3,5,2,4}
            if (pivont <= list[r]) {
                r--;
            }else{//} if (pivont > list[r]){
                list[l]=list[r];
                l++;
                break;
            }
        }
        while (l<r) {
            if (pivont <= list[l]) {
                list[r] = list[l];
                r--;
                break;
            }else{//} if (pivont > list[l]){
                l++;
            }
        }
    }
    list[l] = pivont;
    return l;
}

void quicksort2(vector<int> &list,int l,int r){
    if(r-l<2)return;;
    int pivontIdx = getPivontIdx2(list,l,r);
    quicksort2(list, l, pivontIdx);
    quicksort2(list, pivontIdx+1,r);
}

vector<int> quickSort2(vector<int> &list){
    quicksort2(list, 0, list.size());
    return list;
}

void _facetest_01_test()
{
    vector<int> list1 = {1,3,5,2,4};
    vector<int> list2 = {1,2,3,4,5};
    vector<int> list3 = {4,5,3,2,1};
    vector<int> list4 = {};
    vector<int> list5 = {1,2};
    vector<int> res1 = quickSort2(list1);
    vector<int> res2 = quickSort2(list2);
    vector<int> res3 = quickSort2(list3);
    vector<int> res4 = quickSort2(list4);
    vector<int> res5 = quickSort2(list5);
    
}
