//
//  105_从前序与中序遍历序列构造二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#import "105_从前序与中序遍历序列构造二叉树.hpp"
#import "common.h"

//根据一棵树的前序遍历与中序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//通过次数115,728提交次数170,163
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//[3,9,20,15,7]
//递归
TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* res = nullptr;
    int size = preorder.size();
    if (size == 0) {
        return res;
    }
    
    int preCenter = preorder.front();
    int frontCount = 0;
    for (int i = 0; i<size; i++) {
        int inCenter = inorder[i];
        if (preCenter == inCenter) {
            break;
        }else{
            frontCount++;
        }
    }
    int backCount = size-1-frontCount;
    vector<int> leftpre(preorder.begin()+1,preorder.begin()+1+frontCount);
    vector<int> rightpre(preorder.begin()+1+frontCount,preorder.begin()+1+frontCount+backCount);
    
    vector<int> leftin(inorder.begin(),inorder.begin()+frontCount);
    vector<int> rightin(inorder.begin()+1+frontCount,inorder.begin()+1+frontCount+backCount);
    
    TreeNode* leftnode = buildTree1(leftpre, leftin);
    TreeNode* rightnode = buildTree1(rightpre, rightin);
    res = new TreeNode(preCenter, leftnode, rightnode);
    return res;
    }

//[3,9,20,15,7]
//迭代
TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* res = nullptr;
    int size = preorder.size();
    if (size == 0) {
        return res;
    }
    int preCenter = preorder.front();
    int frontCount = 0;
    for (int i = 0; i<size; i++) {
        int temp = inorder[i];
        if (preCenter == temp) {
            break;
        }else{
            frontCount++;
        }
    }
    
    
    return res;
    }

void _105_test(){
        
    vector<int> list1 = {3,9,20,15,7};
    vector<int> list2 = {9,3,15,20,7};
    vector<int> list3 = {1,2,3};
    vector<int> list4 = {2,1,3};
    
    TreeNode* res1 = buildTree1(list1, list2);
    TreeNode* res2 = buildTree1(list3, list4);
    
}
