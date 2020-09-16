//
//  844_比较含退格的字符串.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#include "844_比较含退格的字符串.hpp"
#include "common.h"
//
//给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
//
//注意：如果对空文本输入退格字符，文本继续为空。
//
//
//
//示例 1：
//
//输入：S = "ab#c", T = "ad#c"
//输出：true
//解释：S 和 T 都会变成 “ac”。
//示例 2：
//
//输入：S = "ab##", T = "c#d#"
//输出：true
//解释：S 和 T 都会变成 “”。
//示例 3：
//
//输入：S = "a##c", T = "#a#c"
//输出：true
//解释：S 和 T 都会变成 “c”。
//示例 4：
//
//输入：S = "a#c", T = "b"
//输出：false
//解释：S 会变成 “c”，但 T 仍然是 “b”。
//
//
//提示：
//
//1 <= S.length <= 200
//1 <= T.length <= 200
//S 和 T 只含有小写字母以及字符 '#'。
//
//
//进阶：
//
//你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/backspace-string-compare
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool backspaceCompare(string S, string T) {
    
    stack<string> stack1,stack2;
    
    int size1 = S.size();
    int size2 = T.size();
    
    string c1,c2;
    int finallySize = max(size1, size2);
    for (int i = 0 ; i<finallySize; i++) {
        
        if (i < size1) {
            c1 = S.substr(i,1);
            bool compareres = (c1=="#");
            if (compareres) {
                if (!stack1.empty()) {
                    stack1.pop();
                }
            }else{
                stack1.push(c1);
            }
        }
        if (i < size2) {
            c2 = T.substr(i,1);
            bool compareres = (c2=="#");
            if (compareres) {
                if (!stack2.empty()) {
                    stack2.pop();
                }
            }else{
                stack2.push(c2);
            }
        }
        
    }
    
    return stack1 == stack2;
    

    }

//反向遍历,对比

//"ab##"-->"##ba"-->遇到#则指针跳到下一个,然后依次对比每一次指针为0的情况
//"a#c#"-->"#c#a"-->
bool backspaceCompare2(string S, string T) {
    
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    
    int size1 = S.size();
    int size2 = T.size();
    
    
    return true;
}

void _844_test(){
    
    string S1 = "ab#c", T1 = "ad#c";
    string S2 = "ab##", T2 = "c#d#";
    string S3 = "a##c", T3 = "#a#c";
    string S4 = "a#c", T4 = "b";
    string S5 = "bbbextm", T5 = "bbb#extm";
    bool res1 = backspaceCompare2(S1, T1);
    bool res2 = backspaceCompare2(S2, T2);
    bool res3 = backspaceCompare2(S3, T3);
    bool res4 = backspaceCompare2(S4, T4);
    bool res5 = backspaceCompare2(S5, T5);
    
}
