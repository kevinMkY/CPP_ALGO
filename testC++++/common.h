//
//  common.h
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#ifndef common_h
#define common_h

#include <stdio.h>
#include <cmath>


#pragma mark string
#include <string>
//
//字符串查找
// s.find(s1)         //查找s中第一次出现s1的位置，并返回（包括0）
//
// s.rfind(s1)        //查找s中最后次出现s1的位置，并返回（包括0）
//
// s.find_first_of(s1)       //查找在s1中任意一个字符在s中第一次出现的位置，并返回（包括0）
//
//s.find_last_of(s1)       //查找在s1中任意一个字符在s中最后一次出现的位置，并返回（包括0）
//
//s.fin_first_not_of(s1)         //查找s中第一个不属于s1中的字符的位置，并返回（包括0）
//
//s.fin_last_not_of(s1)         //查找s中最后一个不属于s1中的字符的位置，并返回（包括0）
//2、字符串截取
//s.substr(pos, n)    //截取s中从pos开始（包括0）的n个字符的子串，并返回
//
//s.substr(pos)        //截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回
//3、字符串替换
// s.replace(pos, n, s1)     //用s1替换s中从pos开始（包括0）的n个字符的子串
//4、代码测试（字符串操作.cpp）
//#include <iostream>
//using namespace std;
//
///* 字符串查找 */
//void findSubString(string str){
//    // find()函数的使用，返回查找对象第一次出现的位置.
//    cout << str.find("fs") << endl;
//    // rfind()函数的使用，返回查找对象最后出现的位置
//    cout << str.rfind("s") << endl;
//}
//
///* 字符串截取 */
//void getSubString(string str){
//    // substr(pos)函数的使用，返回从pos开始(包含pos位置的字符)所有的字符
//    cout << str.substr(2) << endl;
//    // substr(pos,n)，返回从pos开始(包含pos位置的字符)n个字符
//    cout << str.substr(2, 2) << endl;
//}
//
///* 字符串替换 */
//void replaceString(string str){
//    // replace(pos,n,s1)，用s1替换从pos开始的n个字符
//    cout << str.replace(0,2,"xiaoming") << endl;
//}
//
//int main()
//{
//    string str = string("sdfsf");
//    // findSubString(str);
//    // getSubString(str);
//    replaceString(str);
//    return 0;
//}
//
//
//5、字符替换（用x替换字符串中所有的a.cpp）
//#include <iostream>
//using namespace std;
//
///* 用x替换a */
//void replaceAWithX(string str){
//    int pos;
//    pos = str.find("a");
//    while(pos != -1){
//        // str.length()求字符的长度，注意str必须是string类型
//        str.replace(pos,string("a").length(),"x");
//        pos = str.find("a");
//    }
//
//    cout << str << endl;
//}
//
//int main()
//{
//    string str = string("fsafsdf");
//    replaceAWithX(str);
//    return 0;
//}

#include <vector>
#include <stack>
#include <queue>
#include "ListNode.hpp"
#include "TreeNode.hpp"

using namespace std;

#endif /* common_h */
