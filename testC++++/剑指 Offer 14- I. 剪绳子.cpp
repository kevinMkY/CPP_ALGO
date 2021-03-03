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

long fastPow(long base,int a,int mol){
    
    bool underZero = a < 0;
    a = abs(a);
    long res = 1;
    while (a > 0) {
        if (a%2==1) {
            res=(res * base)%mol;
            a--;
        }
        base=(base*base)%mol;
        a/=2;
    }
    if (underZero) {
        return 1.0/res;
    }else{
        return res;
    }
}
/*
 为什么取模1000000007
 1.1000000007是一个质数(素数),对质数取余能最大程度避免冲突～
 2.int32位的最大值为2147483647,所以对于int32位来说1000000007足够大
 3.int64位的最大值为2^63-1,对于1000000007来说它的平方不会在int64中溢出
 */
int cuttingRope3(int n) {
    if (n <=3) {
        return n-1;
    }
    int a = n/3;
    int b = n%3;
    if (b==0) {
        return fastPow(3, a,1000000007)%1000000007;
    }else if (b==1) {
        return (fastPow(3, a-1,1000000007) * 4)%1000000007;
    }else if (b==2) {
        return (fastPow(3, a,1000000007) * 2)%1000000007;
    }
    
    return 0;
}

void _offer_14_repeat_test()
{

//620946522
    int res1 = cuttingRope(8);
    int res2 = cuttingRope(1000);
    int res3 = cuttingRope3(8);
    int res4 = cuttingRope3(1000);
    


}
