#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
    public:
        int data;

        TreeNode* left;
        TreeNode* right;

        // Constructor to initialize the Node.
        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        TreeNode* root; // pointer to the root node.

        // private helper functions for recusrive operations.
        TreeNode* insertRecursive(TreeNode* node, int value);
        bool searchRecursive(TreeNode* node, int value);
        void inorderRecursive(TreeNode* node);
        void preorderRecursive(TreeNode* node);
        void postorderRecursive(TreeNode* node);
        int heightRecursive(TreeNode* node);
        void deleteTree(TreeNode* node);

    public:
        // constructor.
        BinaryTree() : root(nullptr) {}

        // Desctructor.
        ~BinaryTree() {
            deleteTree(root);
        }

        // public interface functions.
        void insert(int value);
        bool search(int value);
        void inorderTransversal();
        void preorderTransversal();
        void postorderTransversal();
        void levelOrderTransversal();
        int height();
        void display();
};

// STEP 3: Implementing insertion (recusrion approach).
TreeNode* BinaryTree::insertRecursive(TreeNode* node, int value) {
    // Base case: if we reach a null node create a new node.
    if (node == nullptr) {
        return new TreeNode(value);
    }

    // Recursive case: deciding whether to go right or left.
    if(value <= node->data) {
        node->left = insertRecursive(node->left, value);
    } else {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

// STEP 4: Implementing the search (recursive approach)
bool searchRecursive(TreeNode* node, int value) {
    // Base case: if node is null.
    if (node == nullptr) {
        return false;
    }

    // Search for value in current node.
    if (node->data == value) {
        return true;
    }

    // Checking for the value in the subsequent nodes.
    if (node->data > value) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

bool BinaryTree::search(int value) {
    return searchRecursive(root, value);
}

// STEP 5: creating the inorder transversal logic LEFT->ROOT ->RIGHT
void BinaryTree::inorderRecursive(TreeNode* node) {
    if( node != nullptr) {
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }
}

void BinaryTree::inorderTransversal() {
    cout << "Inorder: ";
    inorderRecursive(root);
    cout << endl;
}

// STEP 6: Preorder logic ROOT -> LEFT -> RIGHT.
void BinaryTree::preorderRecursive(TreeNode* node) {
    if (node != nullptr) {
        // visiting the root node.
        cout << node->data << " ";
        // visiting the left node.
        preorderRecursive(node->left);
        // Visiting the right node.
        preorderRecursive(node->right);
    }
}

void BinaryTree::preorderTransversal() {
    cout << "Pre Order: ";
    preorderRecursive(root);
    cout << endl;
}

// STEP 7: Post Order logic
// LEFT->RIGHT->ROOT.
void BinaryTree::postorderRecursive(TreeNode* node) {
    if (node != nullptr) {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree::postorderTransversal() {
    cout << "post order: ";
    postorderRecursive(root);
    cout << endl;
}

// STEP 8: Level Order transversal. (breadth-first).
void BinaryTree::levelOrderTransversal() {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Level-order: ";
    while(!q.empty()) {
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

// STEP 10: Calculating the height of the tree
int BinaryTree::heightRecursive(TreeNode* node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = heightRecursive(node->left);
    int rightHeight = heightRecursive(node->right);

    return 1 + max(leftHeight, rightHeight);
}

// STEP 11: Cleaning up the memory.
void BinaryTree::deleteTree(TreeNode* node) {
    if (root != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// STEP 12: Display function for visualization.
void BinaryTree::display() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    cout << "\n=== Binary Tree Contents ========" << endl;

    inorderTransversal();
}