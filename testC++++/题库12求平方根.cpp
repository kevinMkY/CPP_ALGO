//
//  题库12求平方根.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/7.
//

#include "题库12求平方根.hpp"
#include "common.h"

int mysqrt(int x) {
        if(x<=1)return x;
        int low = 0;
        int high = x;
        int middle = 0;
        while(low<=high){
            middle = (low+high)>>1;
            if(middle == x/middle){
                return middle;
            }else if(middle < x/middle){
                low = middle+1;
            }else{// if(middle > x/middle){
                high=middle-1;
            }
        }
        return high;
    }

void _tk_12_test()
{
    int res = mysqrt(3);
    
}
