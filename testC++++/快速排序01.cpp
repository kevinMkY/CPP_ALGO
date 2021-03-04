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

void quickSort333(vector<int>& arr, int l, int r) {
        // 子数组长度为 1 时终止递归
        if (l >= r) return;
        // 哨兵划分操作（以 arr[l] 作为基准数）
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        // 递归左（右）子数组执行哨兵划分
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }


vector<int> quickSort4(vector<int>& arr,int l,int r) {
    if (l >= r) {
        return arr;
    }
    int i = l,j=r;
    int pivont = arr[l];
    while (i < j) {
        while (i < j && arr[j] >= pivont) { j--; }
        while (i < j && arr[i] <= pivont) { i++; }
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    quickSort4(arr,l,i-1);
    quickSort4(arr,i+1,r);
    return arr;
}
void quickSort555(vector<int>& arr, int l, int r) {
        // 子数组长度为 1 时终止递归
        if (l >= r) return;
        // 哨兵划分操作（以 arr[l] 作为基准数）
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        // 递归左（右）子数组执行哨兵划分
        quickSort555(arr, l, i - 1);
        quickSort555(arr, i + 1, r);
    }

void _facetest_01_test()
{
    vector<int> list1 = {1,3,5,2,4};
    vector<int> list2 = {1,2,3,4,5};
    vector<int> list3 = {4,5,3,2,1};
    vector<int> list4 = {};
    vector<int> list5 = {1,6,2,5,3,4};
    vector<int> list6 = {1,6,2,5,3,4};
//    vector<int> res1 = quickSort2(list1);
//    vector<int> res2 = quickSort2(list2);
//    vector<int> res3 = quickSort2(list3);
//    vector<int> res4 = quickSort2(list4);
    quickSort4(list5,0,list5.size()-1);
    quickSort555(list6,0,list6.size()-1);
    
}
