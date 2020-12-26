//
//  606_根据二叉树创建字符串.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/26.
//

#import "606_根据二叉树创建字符串.hpp"
#import "common.h"

//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
//
//示例 1:
//
//输入: 二叉树: [1,2,3,4]
//       1
//     /   \
//    2     3
//   /
//  4
//
//输出: "1(2(4))(3)"
//
//解释: 原本将是“1(2(4)())(3())”，
//在你省略所有不必要的空括号对之后，
//它将是“1(2(4))(3)”。
//示例 2:
//
//输入: 二叉树: [1,2,3,null,4]
//       1
//     /   \
//    2     3
//     \
//      4
//
//输出: "1(2()(4))(3)"
//
//解释: 和第一个示例相似，
//除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
//通过次数19,741提交次数35,711
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
string tree2str1(TreeNode* t) {

    string res;
    if (!t) {
        return res;
    }
    auto left = tree2str1(t->left);
    auto right = tree2str1(t->right);
    res+=to_string(t->val);
    if (left.length()>0 || right.length() > 0) {
        res+="("+left+")";
    }
    if (right.length()>0) {
        res+="("+right+")";
    }
    return res;
    }

//迭代
//{1,2,3,4,5} -----> "1(2(4)(5))(3)"
//[1,2,3,null,4]---->"1(2()(4))(3)"
string tree2str2(TreeNode* t) {

    string res;
    if (!t) {
        return res;
    }
    
    if (res.length()>2) {
        res = res.substr(1,res.length()-2);
    }
    
    return res;
    }

void _606_test()
{
    vector<int> list1 = {1,2,3,4,5};
    vector<int> list2 = {1,2,3,4,NULL,NULL,6};
    vector<int> list3 = {1,2,3,NULL,4};
    
    TreeNode *node1 = initTreeWithNULLVector(list3);
    
    string res1 = tree2str1(node1);
    string res2 = tree2str2(node1);
    
    
}
