//
//  剑指 Offer 57 - II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 57 - II. 和为s的连续正数序列.hpp"
#include "common.h"

vector<vector<int>> findContinuousSequence(int target) {

    vector<vector<int>>res;
    vector<int>levelres;
    for (int l = 1,r = 2; l<r;) {
        int sum = (l+r)*(r-l+1)/2;
        if (sum == target) {
            levelres.clear();
            for (int tl = l; tl <= r; tl++) {
                levelres.push_back(tl);
            }
            res.push_back(levelres);
            l++;
        }else if (sum < target){
            r++;
        }else{  //sum > target){
            l++;
        }
    }
    
    
    return res;
    }

void _offer_57_02_repeat_test()
{
    
    vector<vector<int>> res = findContinuousSequence(9);
    
    
}
