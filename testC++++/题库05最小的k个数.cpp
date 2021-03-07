//
//  题库05最小的k个数.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/5.
//

#include "题库05最小的k个数.hpp"
#include "common.h"

void sort(vector<int>&list,int l,int r,int k){
    if(l>=r)return;
    int s = l,end = r;
    int pivont = list[l];
    while (s<end) {
        while (s<end && pivont <= list[end]) {end--;}
        while (s<end && pivont >= list[s]) {s++;}
        swap(list[s],list[end]);
    }
    swap(list[l], list[s]);
    
    
    sort(list,l,s-1,k);
    if(s-l+1>=k){
        
    }else{
        sort(list,s+1,r,k);
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int n = input.size();
    if(n<k)return{};
    if(n<1)return input;
    sort(input,0,n-1,k);
    vector<int>res{input.begin(),input.begin()+k};
    return res;
}

void _tk_05_test()
{
    vector<int> list1 = {4,5,1,6,2,7,3,8};
    
    vector<int> res = GetLeastNumbers_Solution(list1,6);
    
}
