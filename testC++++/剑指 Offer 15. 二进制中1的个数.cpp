//
//  剑指 Offer 15.cpp
//  testC++++
//
//  Created by mm on 2021/2/26.
//

#include "剑指 Offer 15. 二进制中1的个数.hpp"
#include "common.h"


int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n > 0   )
        {
            sum += n&1;
            n >>= 1;
        }
        return sum;
    }


void _offer_15_repeat_test()
{

    
    int res = hammingWeight(9);


}
