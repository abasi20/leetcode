
struct Node{
    int value;

    Node* left;//左孩子
    Node* right;//右孩子
};

Node* LCA(Node* root, Node* p, Node q){
    if(root == nullptr || root==p || root == q) return root;

    auto* l_n= LCA(root->left, p, q);
    auto* r_n = LCA(root->right, p, q);
    if(l_n && r_n) return root;
    return l_n? l_n: r_n;

}




int main(int argc, char** argv){



    return 0;
}