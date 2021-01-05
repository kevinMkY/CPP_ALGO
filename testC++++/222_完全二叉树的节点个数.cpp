//
//  222_完全二叉树的节点个数.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/29.
//

#include "222_完全二叉树的节点个数.hpp"
#include "common.h"

//给出一个完全二叉树，求出该树的节点个数。
//
//说明：
//
//完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
//
//示例:
//
//输入:
//    1
//   / \
//  2   3
// / \  /
//4  5 6
//
//输出: 6
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int countNodes1(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    res = 1;
    auto leftcount = countNodes1(root->left);
    auto rightcount = countNodes1(root->right);
    return res + leftcount +rightcount;
    }

int countNodes2(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        res++;
        auto left = node->left;
        auto right = node->right;
        if (left) {
            myqueue.push(left);
        }
        if (right) {
            myqueue.push(right);
        }
    }
    return res;
    }

int countLevel(TreeNode *root){
    int level = 0;
    while (root) {
        root = root->left;
        level++;
    }
    return level;
}

int countNodes3(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    
    auto leftlevel = countLevel(root->left);
    auto rightlevel = countLevel(root->right);
    
    //说明右边一定也有节点,左右为满二叉树
    if (leftlevel == rightlevel) {
        int leftcount = (1<<leftlevel)-1;
        int rightcount = countNodes3(root->right);
        res = leftcount + rightcount + 1;
        printf("");
        //说明右边少一层,是满二叉树,左边零星有几个
    }else if (leftlevel > rightlevel){
        int leftcount = countNodes3(root->left);
        int rightcount = (1<<rightlevel)-1;
        res = leftcount + rightcount + 1;
        printf("");
    }else{  //左边《右边,肯定不是满二叉树,不符合题意
        
    }
    return res;
}


/*
 尝试解释一下这个位运算

     1            h = 0
    / \
   2   3          h = 1
  / \  /
 4  5 6           h = 2
 现在这个树中的值都是节点的编号，最底下的一层的编号是[2^h ，2^h - 1]，现在h = 2，也就是4, 5, 6, 7。
 4, 5, 6, 7对应二进制分别为 100 101 110 111

 不看最左边的1，从第二位开始，0表示向左，1表示向右，正好可以表示这个节点相对于根节点的位置。
 比如4的 00 就表示从根节点 向左 再向左。6的 10 就表示从根节点 向右 再向左

 那么想访问最后一层的节点就可以从节点的编号的二进制入手。从第二位开始的二进制位表示了最后一层的节点相对于根节点的位置。
 那么就需要一个bits = 2^(h - 1) 这里就是2，对应二进制为010。这样就可以从第二位开始判断。
 比如看5这个节点存不存在，先通过位运算找到编号为5的节点相对于根节点的位置。010 & 101 发现第二位是0，说明从根节点开始，第一步向左走。
 之后将bit右移一位，变成001。001 & 101 发现第三位是1，那么第二步向右走。
 最后bit为0，说明已经找到编号为5的这个节点相对于根节点的位置，看这个节点是不是空，不是说明存在，exist返回真
 编号为5的节点存在，说明总节点数量一定大于等于5。所以二分那里low = mid

 再比如看7存不存在，010 & 111 第二位为1，第一部从根节点向右；001 & 111 第三位也为1，第二步继续向右。
 然后判断当前节点是不是null，发现是null，exist返回假。
 编号为7的节点不存在，说明总节点数量一定小于7。所以high = mid - 1
 */

/*
 运算规则：0&0=0;  0&1=0;   1&0=0;    1&1=1;

       即：两位同时为“1”，结果才为“1”，否则为0

 例如：3&5  即 0000 0011& 0000 0101 = 00000001  因此，3&5的值得1。
 */
bool countNodes4_isexitedNode(TreeNode* root,int k,int level){
    int bits = 1 << (level - 1);
    TreeNode* node = root;
    while (node != nullptr && bits > 0) {
        if (!(bits & k)) {
            node = node->left;
        } else {
            node = node->right;
        }
        bits >>= 1;
    }
    return node != nullptr;

}

bool exists(TreeNode* root, int level, int k) {
    int bits = 1 << (level - 1);
    TreeNode* node = root;
    while (node != nullptr && bits > 0) {
        int temp = bits & k;
        if (!(temp)) {
            node = node->left;
        } else {
            node = node->right;
        }
        bits >>= 1;
    }
    return node != nullptr;
}
int countNodes4(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

void _222_test()
{
    vector<int> list1 = {1,2,3,4,5,6};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
//    int res1 = countNodes1(node1);
//    int res2 = countNodes2(node1);
//    int res3 = countNodes3(node1);
    int res4 = countNodes4(node1);
    
}
