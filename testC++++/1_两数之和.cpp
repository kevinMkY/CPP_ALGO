//
//  1_两数之和.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/19.
//

#include "1_两数之和.hpp"
#include "common.h"

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
//你可以按任意顺序返回答案。
//
//
//
//示例 1：
//
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
//示例 2：
//
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
//示例 3：
//
//输入：nums = [3,3], target = 6
//输出：[0,1]
//
//
//提示：
//
//2 <= nums.length <= 103
//-109 <= nums[i] <= 109
//-109 <= target <= 109
//只会存在一个有效答案
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/two-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//暴力
vector<int> twoSum(vector<int>& nums, int target) {

    for (int i = 0; i<nums.size()-1; i++) {
        for (int j = i+1; j<nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i,j};
            }
        }
    }
    
    return {};
    }

//哈希表
vector<int> twoSum2(vector<int>& nums, int target) {
    map<int, int> mymap;
    for (int i = 0; i<nums.size(); i++) {
        
        int modify = target - nums[i];
        //mymap.find(value) = key,key = i
        auto it = mymap.find(modify);
        if (it != mymap.end()) {  //找不到就是end
            return {it->second,i};
        }
        //mymap[value] = key;
        mymap[nums[i]] = i;
    }
    return {};
}


vector<int> twoSum3(vector<int>& nums, int target) {
    
    int n = (int)nums.size();
    
    
    map<int, int> mymap;
    for (int i = 0; i<n; i++) {
        int val = nums[i];
        int modify = target - val;
        if (mymap.find(modify) == mymap.end()) {
            mymap[val] = i;
        }else{
            return {mymap[modify],i};
        }
    }
    
    return {};
}

void _1_test()
{
    vector<int> list1 = {2,7,11,15};
    int flag1 = 9;
//    vector<int> sum = twoSum(list1, flag1);
    vector<int> sum2 = twoSum3(list1, flag1);
    
}
