
class Solution {
    public:
        Node* LCA(Node* root, Node* n1, Node* n2) {
            if (root == NULL || root == n1 || root == n2)
                return root;
            
            if (n1->data < root->data && n2->data > root->data || n1->data > root->data && n2->data < root->data)
                return root;
            
            if (n1->data < root->data && n2->data < root->data)
                return LCA(root->left, n1, n2);
            
            return LCA(root->right, n1, n2);
        }
  };