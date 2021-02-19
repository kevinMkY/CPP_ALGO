//
//  118_杨辉三角.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/19.
//

#include "118_杨辉三角.hpp"
#include "common.h"

//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例:
//
//输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/pascals-triangle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> res(numRows);
    for (int i = 0; i<numRows; i++) {
        res[i].resize(i+1);
        for (int j = 0; j<=i; j++) {
            if(j == 0 || j == i){
                res[i][j] = 1;
            }else{
                res[i][j] = res[i-1][j-1] +res[i-1][j];
            }
        }
    }
    
    return res;
}

void _118_test()
{
    vector<vector<int>> list1 = generate(5);
    
}
