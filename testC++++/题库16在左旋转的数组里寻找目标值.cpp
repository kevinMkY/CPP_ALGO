//
//  题库16在左旋转的数组里寻找目标值.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/8.
//

#include "题库16在左旋转的数组里寻找目标值.hpp"
#include "common.h"

int _tk_16_test_search(int* A, int n, int target) {
        // write code here
        // write code here
        if(n == 0)return -1;
    if(target == A[n-1])return n-1;
    if(target == A[0])return 0;
        int l =0;
        int r = n-1;
        int mid = l;
        while(l<r){
            mid = l+((r-l)>>1);
            if(target == A[mid]){
                return mid;
            }else if(A[mid]>A[r]){    //7-0-1-2
                l = mid+1;
            }else if(A[mid]<A[l]){    //7-0-1-2
                r = mid-1;
            }else{
                break;
            }
        }
        int val = A[l];
        if(val == target){
            return l;
        }else if(l > 0 && target > A[0] && target < A[l-1]){    //
            while(l<r){
                mid = l+((r-l)>>1);
                if(target == A[mid]){
                    return mid;
                }else if(A[mid]>target){    //7-0-1-2
                    r = mid-1;
                }else if(A[mid]<target){    //7-0-1-2
                    l = mid+1;
                }
            }
        }else if(target > A[l] && target <= A[r]){    //
            
        }
        
        return -1;
    }

void _tk_16_test()
{
    int list1[] = {4,5,6,7,0,1,2};
    int list2[] = {1,3};
    int res = _tk_16_test_search(list2,2,3);
    
}
