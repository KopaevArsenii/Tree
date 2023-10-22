//
// Created by Арсений Копаев on 22.10.2023.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#endif //TREE_TREE_H

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int element) {
        data = element;
        left = nullptr;
        right = nullptr;
    }
};

typedef TreeNode* Tree;

void init(Tree& root);
void init(Tree& root, int element);
void init(Tree& root, int element, Tree leftSubTree, Tree rightSubTree);
bool isEmpty (Tree& root);
void clear(Tree& root);
bool attachLeftSubTree(Tree& root, Tree subTree);
bool attachRightSubTree(Tree& root, Tree subTree);
void detachLeftSubTree(Tree root, Tree& subTree);
void detachRightSubTree(Tree root, Tree& subTree);
void copy(Tree root, Tree& newRoot);
Tree copyLeftSubTree(Tree root);
Tree copyRightSubTree(Tree root);
int getRootData(Tree root);
void setRootData(Tree& root, int element);
void updateLeftSubTree(Tree root, Tree subTree);
void updateRightSubTree(Tree root, Tree subTree);
