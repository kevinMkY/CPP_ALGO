//
//  common.h
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#ifndef common_h
#define common_h

#include <stdio.h>


#include <string>

#include <vector>

////vector的添加数据
//2     void push_back(数据) 向vector 尾部添加一个数据data
//3     v.insert(v.begin(),9); 在v.begin()之前 插入一个数据
//4     v.insert(v.begin(),10,1);在v.begin()之前 插入10个1 ，第一个参数是iterator ,第二个参数是一个序列list n=10 val=1
//5     v.insert(v.begin()+5,v.begin()+1,v.begin()+3);在迭代器指向的begin+5位置之前，插入序列 [v.begin()+1,v.begin()+3 )之间的数据

#include "ListNode.hpp"


using namespace std;

#endif /* common_h */
