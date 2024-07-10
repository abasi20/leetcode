
struct Node{
    int value;
    Node* left;
    Node* right;
};


void pre_traverse(Node* root){
    if(node==nullptr) return;
    else{

        std::cout<<root->value<<std::endl ;
        traverse(root->left);
        traverse(root->right);
    }
}


void in_traverse(Node* root){
    if(node==nullptr) return;
    else{

        traverse(root->left);
                std::cout<<root->value<<std::endl ;

        traverse(root->right);
    }
}

void post_traverse(Node* root){
    if(node==nullptr) return;
    else{

        traverse(root->left);
        std::cout<<root->value<<std::endl ;
        traverse(root->right);
    }
}

int  main(int argc, char** argv){

    return 0;
}