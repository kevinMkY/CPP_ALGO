//
//  剑指 Offer 33.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 33. 二叉搜索树的后序遍历序列.hpp"
#include "common.h"


bool verifyPostorderIndex(vector<int>& postorder,int left ,int right) {
    
    if (left >= right) {
        return true;
    }
    
    int rootval = postorder[right];
    int start = left;
    
    while (postorder[start] < rootval) {
        start++;
    }
    int leftend = start-1;
    while (postorder[start] > rootval) {
        start++;
    }
    
    return start == right &&
    verifyPostorderIndex(postorder,left,leftend) &&
    verifyPostorderIndex(postorder,leftend+1,right-1);
    
}

//判断后续
bool verifyPostorder(vector<int>& postorder) {

    
    
    return verifyPostorderIndex(postorder,0,postorder.size()-1);
    }


bool verifyPostorderStartEnd3(vector<int>& postorder,int left,int end) {
    if ( left >= end) {
        return true;
    }
    int start = left;
    int root = postorder[end];
    while (postorder[start] < root) {
        start++;
    }
    int leftidx = start-1;
    while (postorder[start] > root) {
        start++;
    }
    
    return start == end &&
    verifyPostorderStartEnd3(postorder,left,leftidx) &&
    verifyPostorderStartEnd3(postorder,leftidx+1,end-1);
}
//
bool verifyPostorder3(vector<int>& postorder) {
    
    return verifyPostorderStartEnd3(postorder, 0, postorder.size()-1);
}

void _offer_33_repeat_test()
{
    vector<int>list1 ={4, 8, 6, 12, 16, 14, 10};
    vector<int>list2 ={5,7,6,9,11,10,8};
//    bool res1 =  verifyPostorder3(list1);
    bool res2 =  verifyPostorder3(list2);
    
}
