//
//  Node.hpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#ifndef Node_h
#define Node_h

#import <vector>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

static Node *parentNode(Node * root){
    Node *target = nullptr;
    if (root == nullptr) {
        return nullptr;
    }
    vector<Node *>childs = root->children;
    if (childs.size() == 0) {
        target = root;
    }else{
        for (int i = 0; i<childs.size(); i++) {
            Node *child = childs[i];
            if (child->children.size() == 0) {
                target = child;
                break;
            }
        }
        if (!target) {
            target = childs.front();
        }
    }
    return target;
}

static Node *initNXTreeWithVector (std::vector<int> para){

    int size = para.size();
    Node *res = nullptr;
    if (size == 0) {
        return res;
    }
    
    para.push_back(NULL);
    size++;
    Node *node;
    vector<Node *> levelRes;
    for (int i = 0; i<size; i++) {
        int val = para[i];
        if (val == NULL) {
            Node *pNode = parentNode(res);
            if (pNode) {
                pNode->children = levelRes;
            }
            levelRes = {};
        }else{
            node  = new Node(val);
            levelRes.push_back(node);
            if (i == 0) {
                res = node;
            }else{
                
            }
        }
    }
    
    return res;
}

#endif /* Node_h */
