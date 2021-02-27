//
//  Header.h
//  testC++++
//
//  Created by yekaihua on 2020/12/16.
//

#ifndef Header_h
#define Header_h

#pragma mark array

/*
 
*/

#pragma mark vector

/*
 add
 v.push_back(x)
 v.insert(v.begin(),x)
 v.insert(v.end(),e.begin(),e.end())
 
 反向
 reverse(v.begin(), v.end())
 
 初始化
 1.初始化amount个元素的vector,并且每个值都是-1;
    vector<int> collectCoins(amount,-1);
 2.根据其他vector copt
    vector<int> tempCoins{coins.begin(),coins.end()};
 3.初始化二维
    vector<int> colv  (length1,0);
    vector<vector<int>> dp(length2,colv); // colv为上面初始化的v
 
 
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
 
 19.sort()      排序
 sort(begin, end)   默认升序
 
 //自定义排序规则
 bool cmp(int x, int y) {
     return x > y;
 }
 void main() {
     int a[5] = {1, 3, 4, 2, 5};
     sort(a, a + 5, cmp);
 }
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
 
 //查找
 使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素，所以返回值只能是1或0。
 使用find，返回的是被查找元素的位置，没有则返回map.end()。
 
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
 
 */

#endif /* Header_h */
