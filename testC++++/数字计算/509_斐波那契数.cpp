//
//  feibonaqi.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include <stdio.h>

//https://leetcode-cn.com/problems/fibonacci-number/submissions/

int fib1(int n){
    if (n<=1) {
        return n;
    }
    
    int first = 0;
    int second = 1;
    for (int i = 0; i<n-1; i++) {
        int sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}

void _509_feibonaqiTest(){
    int a = fib1(4);
    
}
