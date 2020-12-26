//
//  TreeNode.hpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#ifndef TreeNode_h
#define TreeNode_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//----------------------------不允许NULL--------------------------------

static TreeNode *AddNodeToTree(TreeNode *root,int val){
    if (val == NULL) {
        return root;
    }
    if (root == nullptr) {
        TreeNode *node = new TreeNode(val);
        return node;
    }

    if (root->val > val) {
        TreeNode *nextleft = AddNodeToTree(root->left, val);
        root->left = nextleft;
    }else if (root->val < val) {
        TreeNode *nextRight = AddNodeToTree(root->right, val);
        root->right = nextRight;
    }else{      //  ==
        
    }
    return root;
}

static TreeNode *initTreeWithVector (std::vector<int> para){

    int size = para.size();
    TreeNode *res = nullptr;
    if (size == 0) {
        return res;
    }
    
    for (int i = 0; i<size; i++) {
        int val = para[i];
        res = AddNodeToTree(res,val);
    }
    
    return res;
}

//----------------------------允许NULL--------------------------------

static TreeNode *initTreeWithNULLVector (std::vector<int> para){

    int size = para.size();
    TreeNode *res = nullptr;
    if (size == 0) {
        return res;
    }
    
    TreeNode *array[size];
    for (int i = 0; i<size; i++) {
        int val = para[i];
        TreeNode *node = NULL;
        if (val != NULL) {
            node = new TreeNode(val);
        }
        array[i] = node;
        if (i == 0) {
            res = node;
        }else{
            int parentIndex = (i-1)/2;
            TreeNode *parentNode = array[parentIndex];
            if (parentNode == NULL) {
                break;
            }
            if (i%2==0) {
                parentNode->right = node;
            }else{
                parentNode->left = node;
            }
        }
        
    }
    
    return res;
}

#endif /* TreeNode_h */
