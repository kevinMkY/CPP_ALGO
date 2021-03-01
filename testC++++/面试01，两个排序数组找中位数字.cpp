//
//  面试01，两个排序数组找中位数字.cpp
//  testC++++
//
//  Created by mm on 2021/3/2.
//

#include "面试01，两个排序数组找中位数字.hpp"
#include "common.h"


double getMiddleVal(vector<int> nums1,vector<int> nums2){
    
    int n1 = nums1.size();
    int n2 = nums2.size();
    int totallen = n1+n2;
    vector<int> resNums;
    if (n1 == 0 && n2 == 0) {
        return 0;
    }else if (n1 == 0){
        resNums = nums2;
    }else{
        nums1.resize(totallen);
        for (int i = totallen-1; i>=0; i--) {
            if (n1>0 && n2>0) {
                int val1 = nums1[n1-1];
                int val2 = nums2[n2-1];
                if (val1 <=val2) {
                    nums1[i]=nums2[n2-1];
                    n2--;
                }else{
                    nums1[i]=nums1[n1-1];
                    n1--;
                }
            }else if (n1>0){
                nums1[i]=nums1[n1-1];
                n1--;
            }else if (n2>0){
                nums1[i]=nums2[n2-1];
                n2--;
            }
        }
    }
    resNums = nums1;
    
    if (totallen%2==0) {
        return (resNums[totallen/2]+resNums[(totallen-1)/2])*0.5;
    }else{
        return resNums[totallen/2];
    }
}


void _facetest_01_test()
{
    double res = getMiddleVal({1,3},{2,4});


}
