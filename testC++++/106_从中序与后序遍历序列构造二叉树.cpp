//
//  106_从中序与后序遍历序列构造二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#import "106_从中序与后序遍历序列构造二叉树.hpp"
#import "common.h"

//根据一棵树的中序遍历与后序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]
//返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//通过次数52,057提交次数74,672
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//vector<int> list1 = {9,3,15,20,7};    左中右
//vector<int> list2 = {9,15,7,20,3};    左右中
//vector<int> list1 = {2,3,1
//vector<int> list2 = {3,2,1
//递归
TreeNode* buildTree11(vector<int>& inorder, vector<int>& postorder) {
    TreeNode *res = nullptr;
    int size = inorder.size();
    if (size <= 0) {
        return res;
    }
    int centerVal = postorder[size -1];
    if (size == 1){
        res = new TreeNode(centerVal,nullptr,nullptr);
        return res;
    }
    
    int frontcount = 0;
    for (int i= 0; i<size; i++) {
        int inVal = inorder[i];
        if (inVal == centerVal) {
            break;
        }else{
            frontcount++;
        }
    }
    int backcount = size-frontcount-1;//(1是中)
    vector<int> inleft,inright,postleft,postright;
    if (frontcount>0) {
        vector<int> inleft1(inorder.begin(),inorder.begin()+frontcount);
        vector<int> postleft1(postorder.begin(),postorder.begin()+frontcount);
        swap(inleft, inleft1);
        swap(postleft, postleft1);
    }
    if (backcount>0) {
        vector<int> inright1(inorder.end()-backcount,inorder.end());
        vector<int> postright1(postorder.end()-backcount-1,postorder.end()-1);
        swap(inright, inright1);
        swap(postright, postright1);
    }
    
    TreeNode *left = buildTree11(inleft, postleft);
    TreeNode *right = buildTree11(inright, postright);
    
    res = new TreeNode(centerVal,left,right);
    
    return res;
    }

//迭代
TreeNode* buildTree12(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* res = nullptr;
    int size = inorder.size();
    if (size == 0) {
        return res;
    }
    
    return res;
    }

void _106_test(){
    
    vector<int> list1 = {9,3,15,20,7};
    vector<int> list2 = {9,15,7,20,3};
    
    vector<int> list3 = {2,3,1};
    vector<int> list4 = {3,2,1};
    
    TreeNode* res1 = buildTree11(list1, list2);
    TreeNode* res2 = buildTree11(list3, list4);
    
}
