//
//  173_二叉搜索树迭代器.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/30.
//

#include "173_二叉搜索树迭代器.hpp"
#include "common.h"

//实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
//
//调用 next() 将返回二叉搜索树中的下一个最小的数。
//
//
//
//示例：
//
//
//
//BSTIterator iterator = new BSTIterator(root);
//iterator.next();    // 返回 3
//iterator.next();    // 返回 7
//iterator.hasNext(); // 返回 true
//iterator.next();    // 返回 9
//iterator.hasNext(); // 返回 true
//iterator.next();    // 返回 15
//iterator.hasNext(); // 返回 true
//iterator.next();    // 返回 20
//iterator.hasNext(); // 返回 false
//
//
//提示：
//
//next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
//你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-search-tree-iterator
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class BSTIterator1 {
public:
    BSTIterator1(TreeNode* root) {
        inorder(root);
    }
    
    void inorder(TreeNode *root){
        if (!root) {
            return;
        }
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        if (count >= nums.size()) {
            count = nums.size()-1;
        }
        return nums[count++];
    }
    
    bool hasNext() {
        return nums.size() != count;
    }
private:
    vector<int>nums;
    int count = 0;
};

class BSTIterator2 {
public:
    BSTIterator2(TreeNode* root) {
        p = root;
    }
    
    int next() {
        int res;
        while (p || mystack.size()) {
            if (p) {
                mystack.push(p);
                p = p->left;
            }else{
                p = mystack.top();mystack.pop();
                res = p->val;
                p = p->right;
                break;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return (p || mystack.size());
    }
private:
    stack<TreeNode *>mystack;
    TreeNode *p;
};

void _173_test()
{
    vector<int> list1 = {7,3,15,NULL,NULL,9,20};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    BSTIterator2 *iterator = new BSTIterator2(node1);
    int res1 = iterator->next();    // 返回 3
    int res2 = iterator->next();    // 返回 7
    bool bl1 = iterator->hasNext(); // 返回 true
    int res3 = iterator->next();    // 返回 9
    bool bl2 =iterator->hasNext(); // 返回 true
    int res4 = iterator->next();    // 返回 15
    bool bl3 =iterator->hasNext(); // 返回 true
    int res5 = iterator->next();    // 返回 20
    bool bl4 =iterator->hasNext(); // 返回 false
    
}
