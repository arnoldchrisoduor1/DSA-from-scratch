#include <iostream>
#include <queue>

using namespace std;

// Defining the node structure.
class TreeNode {
    public:
        int data; // the value to be stored in the node.
        TreeNode* left; // pointer to left child
        TreeNode* right; // pointer to the right child.

        // constructor to initialize a node.
        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Step 2: Defining the binary tree class.
class BinaryTree {
    private:
        TreeNode* root; // this is the pointer to the root node.

        // Private helper functions for recursive operations.
        TreeNode* insertRecursive(TreeNode* node, int value);
        bool searchRecursive(TreeNode* node, int value);
        void inorderRecursive(TreeNode* node);
        void preorderRecursive(TreeNode* node);
        void postorderRecursive(TreeNode* node);
        int heightRecursive(TreeNode* node);
        void deleteTree(TreeNode* node);

    public:
        // constructor
        BinaryTree() : root(nullptr) {}

        // Desctructor.
        ~BinaryTree() {
            deleteTree(root);
        }

        // Public interface functions.
        void insert(int value);
        bool search(int value);
        void inorderTransversal();
        void preorderTransversal();
        void postorderTransversal();
        void levelOrderTransversal();
        int height();
        void display();
};

// Step 3: Implement insertion (recursive approach).
TreeNode* BinaryTree::insertRecursive(TreeNode* node, int value) {
    // Base case: if we reach a null node, create a new node.
    if (node == nullptr) {
        return new TreeNode(value);
    }

    // Recursive case: decide whether to go left or right.
    //  For a binary search tree property, smaller values go left.
    if (value <=node->data) {
        node->left = insertRecursive(node->left, value);
    } else {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

// Step 4: Implementing search (recursive approach)
bool BinaryTree::searchRecursive(TreeNode* node, int value) {
    // Base case: node is null (value not found)
    if (node == nullptr) {
        return false;
    }

    // Base case: value found.
    if (node->data == value) {
        return true;
    }

    // Recusrive case: search in appropriate subtree.
    if (value < node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

bool BinaryTree::search(int value) {
    return searchRecursive(root, value);
}

// Step 5: implementing tree transversal.
// Inorder transversal: Left -> Root -> Right.
void BinaryTree::inorderRecursive(TreeNode* node) {
    if (node != nullptr) {
        inorderRecursive(node->left); // visit left subtree.
        cout << node->data << " "; // visit root.
        inorderRecursive(node->right); // visit right subtree.
    }
}

void BinaryTree::inorderTransversal() {
    cout << "Inorder: ";
    inorderRecursive(root);
    cout << endl;
}

// Preorder transversal: Root -> Left -> Right.
void BinaryTree::preorderRecursive(TreeNode* node) {
    if (node != nullptr) {
        cout << node->data << " "; // visit the root.
        preorderRecursive(node->left); // visit left subtree.
        preorderRecursive(node->right); // visit right subtree.
    }
}

void BinaryTree::preorderTransversal() {
    cout << "Preorder: ";
    preorderRecursive(root);
    cout << endl;
}

// Postorder transversal: Left -> Right -> Root
void BinaryTree::postorderRecursive(TreeNode* node) {
    if (node != nullptr) {
        postorderRecursive(node->left); // visit left subtree.
        postorderRecursive(node->right); // visit right subtree.
        cout << node->data << " "; /// visit the root.
    }
}

void BinaryTree::postorderTransversal() {
    cout << "Postorder: ";
    postorderRecursive(root);
    cout << endl;
}

// Step 6: Level-order transversal (breadth-first)
void BinaryTree::levelOrderTransversal() {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Level-order: ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";
    

        // Add children to queue
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Step 7: Calculating the height of the tree.
int BinaryTree::heightRecursive(TreeNode* node) {
    if (node == nullptr) {
        return -1; // height of the tree is -1.
    }

    int leftHeight = heightRecursive(node->left);
    int rightHeight = heightRecursive(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int BinaryTree::height() {
    return heightRecursive(root);
}

// Step 8: Clean up the memory.
void BinaryTree::deleteTree(TreeNode* node) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
}

// Step 9: Display function for visualization.
void BinaryTree:: display() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    cout << "\n=== Binary Tree Contents ========" << endl;
}

int main() {
    BinaryTree tree;

    cout << "Building a Binary Tree from scartch!\n" << endl;

    // Insert some values
    cout << "Inserting values: 50, 30, 70, 20, 40, 60, 80" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

     // Display the tree
    tree.display();
    
    // Test search functionality
    cout << "\nSearching for values:" << endl;
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 80: " << (tree.search(80) ? "Found" : "Not Found") << endl;
    
    return 0;
}