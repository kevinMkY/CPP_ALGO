//
//  889_根据前序和后序遍历构造二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "889_根据前序和后序遍历构造二叉树.hpp"
#include "common.h"

//返回与给定的前序和后序遍历匹配的任何二叉树。
//
// pre 和 post 遍历中的值是不同的正整数。
//
//
//
//示例：
//
//输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
//
//
//提示：
//
//1 <= pre.length == post.length <= 30
//pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
//每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
//通过次数7,201提交次数10,854
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//pre = [1,2,4,5,3,6,7],
//post = [4,5,2,6,7,3,1]
TreeNode* constructFromPrePost1(vector<int>& pre, vector<int>& post) {

    TreeNode *res = nullptr;
    int size = pre.size();
    if (size == 0) {
        return res;
    }
    int centerVal = pre.front();
    if (size == 1) {
        res = new TreeNode(centerVal,nullptr,nullptr);
        return res;
    }
    int nextLeftVal = pre[1];
    int leftCount = 0;
    for (int i= 0; i<size; i++) {
        int postVal = post[i];
        if (postVal == nextLeftVal) {
            leftCount++;
            break;
        }else{
            leftCount++;
        }
    }
    
    int backCount = size - 1 - leftCount;
    vector<int> inleft,postleft,inRight,postRight;
    if (leftCount > 0) {
        vector<int> inleft1(pre.begin()+1,pre.begin()+1+leftCount);
        vector<int> postleft1(post.begin(),post.begin()+leftCount);
        swap(inleft, inleft1);
        swap(postleft, postleft1);
    }
    if (backCount > 0) {
        vector<int> inRight1(pre.end()-backCount,pre.end());
        vector<int> postRight1(post.end()-backCount-1,post.end()-1);
        swap(inRight1, inRight);
        swap(postRight1, postRight);
    }
    
    TreeNode *left = constructFromPrePost1(inleft, postleft);
    TreeNode *right = constructFromPrePost1(inRight, postRight);
    res = new TreeNode(centerVal,left,right);
    return res;
    }

void _889_test(){
    
    vector<int> list1 = {1,2,4,5,3,6,7};
    vector<int> list2 = {4,5,2,6,7,3,1};
    
//    vector<int> list3 = {2,3,1};
//    vector<int> list4 = {3,2,1};
    
    TreeNode* res1 = constructFromPrePost1(list1, list2);
//    TreeNode* res2 = constructFromPrePost1(list3, list4);
    
}

