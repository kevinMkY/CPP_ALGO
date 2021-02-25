//
//  剑指 Offer 16.cpp
//  testC++++
//
//  Created by mm on 2021/2/26.
//

#include "剑指 Offer 16. 数值的整数次方.hpp"
#include "common.h"


double myPow(double x, int n) {

    double res = 1.0;
    bool smallZero = n < 0;
    n = abs(n);
    while (n > 0) {
        if ((n & 1) != 0) {
            res = res * x;
            n -=1;
        }
        x = x * x;
        n = n/2;
    }
    
    if (smallZero) {
        return 1.0/res;
    }else{
        return res;
    }
    
}


void _offer_16_repeat_test()
{

 
    double res = myPow(2.0,10);
    double res2 = myPow(2.0,-2);


}
