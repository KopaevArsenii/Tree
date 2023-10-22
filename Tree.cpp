//
// Created by Арсений Копаев on 22.10.2023.
//

#include "Tree.h"



void init(Tree& root) {
    root = nullptr;
}

void init(Tree& root, int element) {
    root = new TreeNode(element);
}

void init(Tree& root, int element, Tree leftSubTree, Tree rightSubTree) {
    init(root, element);
    attachLeftSubTree(root, leftSubTree);
    attachRightSubTree(root, rightSubTree);
}

bool isEmpty (Tree& root) {
    return root == nullptr;
}

void clear(Tree& root) {
    if (!isEmpty(root)) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

bool attachLeftSubTree(Tree& root, Tree subTree) {
    bool canAttach = false;
    if (root->left == nullptr) {
        root->left = subTree;
        canAttach = true;
    }
    return canAttach;
}

int getRootData(Tree root) {
    return root->data;
}

void setRootData(Tree& root, int element) {
    root->data = element;
}


bool attachRightSubTree(Tree& root, Tree subTree) {
    bool canAttach = false;
    if (root->right == nullptr) {
        root->right = subTree;
        canAttach = true;
    }
    return canAttach;
}

void detachLeftSubTree(Tree root, Tree& subTree) {
    subTree = root -> left;
    root -> left = nullptr;
}

void detachRightSubTree(Tree root, Tree& subTree) {
    subTree = root -> right;
    root -> right = nullptr;
}

void copy(Tree root, Tree& newRoot) {
    if (root != nullptr) {
        newRoot = new TreeNode(root->data);
        copy(root -> left, newRoot -> left);
        copy(root -> right, newRoot -> right);
    } else {
        newRoot = nullptr;
    }
}

Tree copyLeftSubTree(Tree root) {
    Tree leftSubTree;
    init(leftSubTree);
    if (root != nullptr) {
        copy(root -> left, leftSubTree);
    }
    return leftSubTree;
}

Tree copyRightSubTree(Tree root) {
    Tree rightSubTree;
    init(rightSubTree);
    if (root != nullptr) {
        copy(root -> right, rightSubTree);
    }
    return rightSubTree;
}

void updateLeftSubTree(Tree root, Tree subTree) {
    if (!isEmpty(root)) {
        if (!isEmpty(root->left)){
            clear(root->left);
        }
        root->left = subTree;
    }
}

void updateRightSubTree(Tree root, Tree subTree) {
    if (!isEmpty(root)) {
        if (!isEmpty(root->right)){
            clear(root->right);
        }
        root->right = subTree;
    }
}

