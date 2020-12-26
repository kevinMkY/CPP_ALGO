//
//  Header.h
//  testC++++
//
//  Created by yekaihua on 2020/12/16.
//

#ifndef Header_h
#define Header_h

#pragma mark vector

/*
 add
 v.push_back(x)
 v.insert(v.begin(),x)
 v.insert(v.end(),e.begin(),e.end())
 
 reverse
 reverse(v.begin(), v.end())
 
 
 1.push_back   在数组的最后添加一个数据
 2.pop_back    去掉数组的最后一个数据
 3.at                得到编号位置的数据
 4.begin           得到数组头的指针
 5.end             得到数组的最后一个单元+1的指针
 6．front        得到数组头的引用
 7.back            得到数组的最后一个单元的引用
 8.max_size     得到vector最大可以是多大
 9.capacity       当前vector分配的大小
 10.size           当前使用数据的大小
 11.resize         改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
 12.reserve      改变当前vecotr所分配空间的大小
 13.erase         删除指针指向的数据项
 14.clear          清空当前的vector
 15.rbegin        将vector反转后的开始指针返回(其实就是原来的end-1)
 16.rend          将vector反转构的结束指针返回(其实就是原来的begin-1)
 17.empty        判断vector是否为空
 18.swap         与另一个vector交换数据
*/

#pragma mark stack

/*
 s.push()
 s.top()
 s.pop()
 s.isEmpty()
 s.clear
 */

#pragma mark queue
/*
 
 */

#pragma mark dequeue
/*
 
 */

#pragma mark set

/*
 if (set.count(val) > 0) {
     
 }
 set.insert(val);
 */

#pragma mark map

/*
 //定义
 map<int, TreeNode *> personnel;
 
 //size
 int size = personnel.size();
 
 //存储
 personnel[size+1] = res;
 
 //取值,注意,如果下标对应的没有值 personnel[1] ,则会创建一个值存进去,所以下标取值永远不会为空
 if(personnel.count(1)>0){res1 = personnel[1];}
 if(personnel.count(0)>0){res2 = personnel[0];}
 
 //删除
 personnel.erase(1);
 personnel.erase(0);
 
 */

#pragma mark string
/*
 转换
 string s = to_string(42)
 
 拼接1
 string str1 = "Hello ";
 string str2 = "World!";
 str1.append(str2);
 
 拼接2
 str1 += to_string(1);
 str1 += str2;
 
 字符串查找
  s.find(s1)         //查找s中第一次出现s1的位置，并返回（包括0）

  s.rfind(s1)        //查找s中最后次出现s1的位置，并返回（包括0）

  s.find_first_of(s1)       //查找在s1中任意一个字符在s中第一次出现的位置，并返回（包括0）

 s.find_last_of(s1)       //查找在s1中任意一个字符在s中最后一次出现的位置，并返回（包括0）

 s.fin_first_not_of(s1)         //查找s中第一个不属于s1中的字符的位置，并返回（包括0）

 s.fin_last_not_of(s1)         //查找s中最后一个不属于s1中的字符的位置，并返回（包括0）
 2、字符串截取
 s.substr(pos, n)    //截取s中从pos开始（包括0）的n个字符的子串，并返回

 s.substr(pos)        //截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回
 3、字符串替换
  s.replace(pos, n, s1)     //用s1替换s中从pos开始（包括0）的n个字符的子串
 4、代码测试（字符串操作.cpp）
 
//
// /* 字符串查找 */
// void findSubString(string str){
//     // find()函数的使用，返回查找对象第一次出现的位置.
//     cout << str.find("fs") << endl;
//     // rfind()函数的使用，返回查找对象最后出现的位置
//     cout << str.rfind("s") << endl;
// }
//
// /* 字符串截取 */
// void getSubString(string str){
//     // substr(pos)函数的使用，返回从pos开始(包含pos位置的字符)所有的字符
//     cout << str.substr(2) << endl;
//     // substr(pos,n)，返回从pos开始(包含pos位置的字符)n个字符
//     cout << str.substr(2, 2) << endl;
// }
//
// /* 字符串替换 */
// void replaceString(string str){
//     // replace(pos,n,s1)，用s1替换从pos开始的n个字符
//     cout << str.replace(0,2,"xiaoming") << endl;
// }
//
// int main()
// {
//     string str = string("sdfsf");
//     // findSubString(str);
//     // getSubString(str);
//     replaceString(str);
//     return 0;
// }
//
//
// 5、字符替换（用x替换字符串中所有的a.cpp）
// #include <iostream>
// using namespace std;
//
// /* 用x替换a */
// void replaceAWithX(string str){
//     int pos;
//     pos = str.find("a");
//     while(pos != -1){
//         // str.length()求字符的长度，注意str必须是string类型
//         str.replace(pos,string("a").length(),"x");
//         pos = str.find("a");
//     }
//
//     cout << str << endl;
// }
//
// int main()
// {
//     string str = string("fsafsdf");
//     replaceAWithX(str);
//     return 0;
// }

#endif /* Header_h */
