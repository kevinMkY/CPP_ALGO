//
//  剑指 Offer 17.cpp
//  testC++++
//
//  Created by mm on 2021/2/26.
//

#include "剑指 Offer 17. 打印从1到最大的n位数.hpp"
#include "common.h"



vector<int> printNumbers(int n) {

    int max = pow(10, n);
    vector<int>res;
    for (int i = 1; i<max; i++) {
        res.push_back(i);
    }
    return res;
    }



void _offer_17_repeat_test()
{

    vector<int>res = printNumbers(3);

    


}
