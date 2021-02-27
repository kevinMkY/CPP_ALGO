//
//  剑指 Offer 66.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 66. 构建乘积数组.hpp"
#include "common.h"

vector<int> constructArr(vector<int>& a) {

    
    int n = (int)a.size();
    if ( n < 2 ) {
        return a;
    }
    vector<int>leftres(n);
    vector<int>rightres(n);
    vector<int>res(n);
    
    leftres[0]=1;
    for (int i = 1; i<n; i++) {
        leftres[i] = leftres[i-1] * a[i-1];
    }
    
    res[n-1]=leftres[n-1];
    rightres[n-1]=1;
    for (int i = n-2; i>=0; i--) {
        rightres[i] = rightres[i+1] * a[i+1];
        res[i] = leftres[i] * rightres[i];
    }
    
    
    
    return res;
    }

void _offer_66_repeat_test()
{
    vector<int> list1 = {1, 2, 3, 4, 5};
    vector<int>res = constructArr(list1);
    
}
