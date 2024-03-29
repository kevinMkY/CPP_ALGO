//
//  1104_二叉树寻路.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/5.
//

#include "1104_二叉树寻路.hpp"
#include "common.h"

//在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。
//
//如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
//
//而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
//
//
//
//给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。
//
//
//
//示例 1：
//
//输入：label = 14
//输出：[1,3,4,14]
//示例 2：
//
//输入：label = 26
//输出：[1,2,6,10,26]
//
//
//提示：
//
//1 <= label <= 10^6
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


/*
 因为以1为根节点层次编号的满二叉树可以对应到位的表示，所以用位运算的思路即可。

 因为每层的顺序在变，所以每次需要对首位外的其它位取反。

 举例14=1110b，

 先将14右移，变为111b，然后对除第一位外所有位取反变为100b，即它的根节点4，

 同理100b，右移变为10b，对除第一位外所有位取反变为11b，即它的根节点3

 一直到1结束。

 def pathInZigZagTree(self, label: int) -> List[int]:
         res = []
         while label != 1:
             res.append(label)
             label >>= 1
            # 这里我采用异或实现
             label = label ^(1 << (label.bit_length() - 1)) - 1
         return [1]+res[::-1]

 作者：yybeta
 链接：https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/solution/pythonwei-yun-suan-by-mai-mai-mai-mai-zi/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


 作者：yybeta
 链接：https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/solution/pythonwei-yun-suan-by-mai-mai-mai-mai-zi/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

vector<int> pathInZigZagTree1(int label) {
    vector<int> res;
    return res;
    }

vector<int> pathInZigZagTree2(int label) {
    vector<int> res;
    return res;
    }

void _1104_test()
{
#warning todo 二叉树寻路
    int flag1 = 14;
    
    
    vector<int> res1 = pathInZigZagTree1(flag1);
    vector<int> res2 = pathInZigZagTree2(flag1);
    
}
