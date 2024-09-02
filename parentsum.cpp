bool isParentSum(Node* root) {
    if (root == NULL) {
        return true;
    }

    if (root->left != NULL && root->right != NULL) {
        if (root->data != (root->left->data) + (root->right->data)) {
            return false;
        }
    }

    if (root->right == NULL) {
        if (root->data != root->left->data) {
            return false;
        }
    }

    if (root->left == NULL) {
        if (root->data != root->right->data) {
            return false;
        }
    }

    bool a = isParentSum(root->left);
    if (!a) {
        return false;
    }

    bool b = isParentSum(root->right);
    if (!b) {
        return false;
    }

    return true;
}