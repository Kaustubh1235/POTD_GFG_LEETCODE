class Solution {
  void inorder(Node* root, vector<int>& arr) {
      if (!root) return;
      inorder(root->left, arr);
      arr.push_back(root->data);
      inorder(root->right, arr);
  }

  vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
      vector<int> res;
      int i = 0, j = 0;
      while (i < a.size() && j < b.size()) {
          if (a[i] < b[j]) res.push_back(a[i++]);
          else res.push_back(b[j++]);
      }
      while (i < a.size()) res.push_back(a[i++]);
      while (j < b.size()) res.push_back(b[j++]);
      return res;
  }

public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);
        return mergeSortedArrays(a, b);
    }
};
