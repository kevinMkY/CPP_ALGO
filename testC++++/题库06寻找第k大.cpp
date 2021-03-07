//
//  题库06寻找第k大.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/5.
//

#include "题库06寻找第k大.hpp"
#include "common.h"

void _tk_06_test_sort(vector<int> a, int l, int r,int k) {
        if(r-l<2)return;
        int s = l,end = r;
        int pivont = a[l];
        while(s<end){
            while(s<end && pivont <= a[end]){end--;}
            while(s<end && pivont >= a[s]){s++;}
            swap(a[s],a[end]);
        }
        swap(a[s],a[l]);
        _tk_06_test_sort(a,l,s-1,k);
        _tk_06_test_sort(a,s+1,r,k-(s-l+1));
    }
    
    int _tk_06_test_findKth(vector<int> a, int n, int K) {
        _tk_06_test_sort(a, 0, a.size()-1,K);
        int t = a[n-K];
        return t;
    }

int maxLength(vector<int>& arr) {
        int n = arr.size();
        map<int, int>mymap;
        int l = 0;
        int res = 0;
        for(int i = 0;i<n;i++){
            mymap[arr[i]]++;
            while(mymap[arr[l]] > 1){
                mymap[arr[l]]--;
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;
    }

void _tk_06_test()
{
    vector<int> list1 = {1,3,5,2,2};
    
    int res= _tk_06_test_findKth(list1,5,3);
    vector<int>list2={2,3,4,5};
    int res1 = maxLength(list2);
    
    
}
