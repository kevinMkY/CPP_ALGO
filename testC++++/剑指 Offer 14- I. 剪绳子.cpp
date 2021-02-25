//
//  剑指 Offer 14- I.cpp
//  testC++++
//
//  Created by mm on 2021/2/26.
//

#include "剑指 Offer 14- I. 剪绳子.hpp"
#include "common.h"


//n >= 2
int cuttingRope(int n) {
    if (n <= 3) {
        return n-1;
    }
    int a = n/3;
    int b = n%3;
    
    if (b == 0) {
        return pow(3, a);
    }else if (b == 1) {
        return pow(3, a-1) * 4;
    }else if (b == 2) {
        return pow(3, a) * 2;
    }
    return 0;
}

//求快速冥
long int fastpow(int base,int b,int c){
    
    long int res = 1;
    for (int i = 0; i<b; i++) {
        res = (res * base)%c;
    }
    
    return res;
}

//假设数据超大，需要求快速冥
int cuttingRope2(int n) {
    if (n <=3) {
        return n-1;
    }
    
    int a = n/3;
    int b = n%3;
    if (b== 0) {
        return fastpow(3, a,1000000007)%1000000007;
    }else if (b== 1) {
        return fastpow(3, a - 1,1000000007) * 4%1000000007;
    }else if (b== 2) {
        return fastpow(3, a,1000000007) * b%1000000007;
    }
    return 0;
}

void _offer_14_repeat_test()
{

//620946522
    int res2 = cuttingRope2(1000);
    


}
