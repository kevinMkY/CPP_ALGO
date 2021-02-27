//
//  剑指 Offer 46.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 46. 把数字翻译成字符串.hpp"
#include "common.h"

int translateNum(int num) {
    
    if (num < 10) {
        return 1;
    }
    
    string numstring = to_string(num);
    int n = (int)numstring.length();
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for (int i = 2; i<=n; i++) {
        string strv = numstring.substr(i-1-1,2);
        if (strv >= "10" && strv <= "25") {
            dp[i] = dp[i-1] + dp[i-2];
        }else{
            dp[i] = dp[i-1];
        }
    }

    return dp[n];
    }

int translateNum2_dfs(int num){
    if (num < 10) {
        return 1;
    }
    if (10<= (num % 100) && 25>=(num % 100)) {
        return translateNum2_dfs(num/10) + translateNum2_dfs(num/100);
    }else{
        return translateNum2_dfs(num/10);
    }
}

int translateNum2(int num) {
    if (num == 0) {
        return 1;
    }
    return translateNum2_dfs(num);
}

void _offer_46_repeat_test()
{
    int res1 = translateNum(12258);
    int res2 = translateNum2(12258);
    
}
