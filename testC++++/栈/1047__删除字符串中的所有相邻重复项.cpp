//
//  1047__删除字符串中的所有相邻重复项.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#import "1047__删除字符串中的所有相邻重复项.hpp"
#import "common.h"

//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//
//
//
//示例：
//
//输入："abbaca"
//输出："ca"
//解释：
//例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
//
//
//提示：
//
//1 <= S.length <= 20000
//S 仅由小写英文字母组成。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

string removeDuplicates(string S) {

    int size = S.size();
    
    stack<string> stack1;
    string pre = "";
    for (int i = 0; i<size; i++) {
        string c = S.substr(i,1);
        bool res1 = !c.compare(pre);
        if (res1) {
            if (stack1.size()>0) {
                stack1.pop();
            }
        }else{
            stack1.push(c);
        }
        if (stack1.size()>0) {
            pre = stack1.top();
        }else{
            pre = "";
        }
    }
    
    string finaStr = "";
    
    while (!stack1.empty()) {
        string pre = stack1.top();
        stack1.pop();
        finaStr = pre.append(finaStr);
    }
    
    return finaStr;
    }

string removeDuplicates2(string S) {

    int size = S.size();
    
    stack<string> stack1;
    string res = "";
    string pre = "";
    for (int i = 0; i<size; i++) {
        string c = S.substr(i,1);
        bool compareres = !c.compare(pre);
        if (compareres) {
            res = res.substr(0,res.size()-1);
        }else{
            res = res.append(c);
        }
        if (res.size()>0) {
            pre = res.substr(res.size()-1,1);
        }else{
            pre = "";
        }
    }
    
    
    return res;
    }

void _1047_test(){
    string s1 = "abbaca";   //ca
    string s2 = "niefxkwcunphbrmwifwatgwbkqxhmxkoskkkonxtssiwoebwbhfoqhervdnipfaahkcnkbdpsjeqatrgerptnrhhulixktlebkqsiqwtjwxqul";
    string s3 = "abbaca";
    
    string res1 = removeDuplicates2(s1);
    string res2 = removeDuplicates2(s2);
//    string res3 = removeDuplicates(s3);
    
}
