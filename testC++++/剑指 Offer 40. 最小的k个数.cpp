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


vector<int> getLeastNumbers3(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int>res;
    if (n < k || n == 0) {
        return res;
    }
    
    priority_queue<int> greatest;
    for (int i = 0; i<n; i++) {
        if (i<k) {
            greatest.push(arr[i]);
        }else{
            if (greatest.size()) {
                int top = greatest.top();
                if (top > arr[i]) {
                    greatest.pop();
                    greatest.push(arr[i]);
                }
            }
        }
    }
    
    while (greatest.size()) {
        res.push_back(greatest.top());
        greatest.pop();
    }
    
    return res;
    
}

int quickSearch(vector<int>&arr){
    int l = 0, r = arr.size();
    int pivont = arr[0];
    while (l<r) {
        while (l<r) {
            if (pivont <= arr[r]) {
                r--;
            }else{//if (pivont > arr[r]) {
                arr[l]=arr[r];
                l++;
                break;
            }
        }
        while (l<r) {
            if (pivont <= arr[l]) {
                arr[r]=arr[l];
                r--;
                break;
            }else{//if (pivont > arr[l]) {
                l++;
            }
        }
    }
    
    arr[l]=pivont;
    return l;
}

int getpoinvtIdx(){
    
    
    return 0;
}

void quickSelect(vector<int>& arr, int k,int l ,int r) {
    
    int poinvtidx = getpoinvtIdx();
    int num = poinvtidx - l + 1;
    if (num == k) {
        return;
    }else if (num < k){
        
    }else if (num > k){
        quickSelect(arr,k,l,poinvtidx-1);
    }
}

//快排变形
vector<int> getLeastNumbers4(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int>res;
    if (n == 0 || k ==0 || n < k) {
        return res;
    }
    
    
    return res;
}

void _offer_40_repeat_test()
{
    vector<int> arr = {3,2,1};
    vector<int> arr2 = {0,0,0,2,0,5,1};
    vector<int> res1 = getLeastNumbers4(arr,0);
    vector<int> res2 = getLeastNumbers4(arr2,5);
    
}
