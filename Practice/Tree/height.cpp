#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left=NULL;
    struct node* right=NULL;
};

node* insertNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(node* root){

    if(root==NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight)+1;
}

int diameter(node* root, int& height){
    int lheight=0;
    int rheight=0;

    if(root==NULL){
        height=0;
        return 0;
    }

    int ldiameter = diameter(root->left, lheight);
    int rdiameter = diameter(root->right, rheight);

    // int lheight = height(root->left);
    // int rheight = height(root->right);

    height = max(lheight, rheight)+1;

    return max(max(ldiameter, rdiameter), lheight+rheight+1);
}

int main(){
    struct node* root;
    root = insertNode(12);  
    root->left = insertNode(23);
    root->right = insertNode(17);
    root->left->left = insertNode(90);
    root->left->right = insertNode(92);

    cout<<"Height: "<<height(root)<<"\n";
    int height=0;
    cout<<"Diameter: "<<diameter(root, height)<<"\n";

    return 0;
}