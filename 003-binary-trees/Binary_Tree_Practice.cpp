#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
        int data;

        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : data(value), right(nullptr), left(nullptr) {}
};

class BinaryTree {
    
    private:
        TreeNode* root;

        TreeNode* insertRecursive(TreeNode* node, int value);
        bool searchRecursive(TreeNode* node, int value);
        void inorderRecursive(TreeNode* node);
        void preorderRecursive(TreeNode* node);
        void postorderRecursive(TreeNode* node);
        int heightRecursive(TreeNode* node);
        void deleteTree(TreeNode* node);

    public:
        BinaryTree() : root(nullptr) {}

        ~BinaryTree() {
            deleteTree(root);
        }
        void insert(int value);
        bool search(int value);
        void inorderTransversal();
        void preorderTransversal();
        void postorderTransversal();
        void levelorderTransversal();
        int height();
        void display();
};

TreeNode* BinaryTree::insertRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value <= node->data) {
        node->left = insertRecursive(node->left, value);
    } else {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinaryTree::insert(int value) {
    insertRecursive(root, value);
}

bool BinaryTree::searchRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (node-> data == value) {
        return true;
    }

    if (value <= node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

bool BinaryTree::search(int value) {
    searchRecursive(root, value);
}

void BinaryTree::inorderRecursive(TreeNode* node) {
    if(node != nullptr) {
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }
}

void BinaryTree::inorderTransversal() {
    cout << "Inorder transversal: " ;
    inorderRecursive(root);
    cout << endl;
}

void BinaryTree::preorderRecursive(TreeNode* node) {
    if(node != nullptr) {
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

void BinaryTree::preorderTransversal() {
    cout << "preorder transversal: ";
    preorderRecursive(root);
    cout << endl;
}

void BinaryTree::postorderRecursive(TreeNode* node) {
    if (node != nullptr) {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree::postorderTransversal() {
    cout << "post order transversal: ";
    postorderRecursive(root);
    cout << endl;
}

void BinaryTree::levelorderTransversal() {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Level order: ";
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

int BinaryTree::heightRecursive(TreeNode* node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = heightRecursive(node->left);
    int rightHeight = heightRecursive(node->right);

    return 1 + max(leftHeight, rightHeight);
}

void BinaryTree::deleteTree(TreeNode* node) {
    if (root != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BinaryTree::display() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    cout << "\n=== Binary Tree Contents ======" << endl;
    inorderTransversal();
}

int main () {
    BinaryTree tree;

    cout << "Building a binary tree from scratch!\n" << endl;

    cout  << "inserting some values:" << endl;
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);

    tree.display();

    return 0;
}