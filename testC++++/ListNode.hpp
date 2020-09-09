//
//  ListNode.c
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

//结构体初始化 https://blog.csdn.net/LeviKing98/article/details/108429589

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
         
    }
};

//
//static ListNode ListNodeInit1234(){
//    ListNode node1(1);
//    ListNode node2(2);
//    ListNode node3(3);
//    ListNode node4(4);
//    
//    node1.next = &node2;
//    node2.next = &node3;
//    node3.next = &node4;
//    
//    return node1;
//}
