#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left=NULL;
    node* right=NULL;
};

node* insertNode(int data){
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* findLCA(node* root, int n1, int n2){
    if(root==NULL)
        return NULL;
    
    if(root->data==n1 || root->data==n2)
        return root;

    node* l = findLCA(root->left, n1, n2);
    node* r = findLCA(root->right, n1, n2);

    if(l&&r)
        return root;

    return (l!=NULL)?l:r;
}

int main(){
    node* root = insertNode(2);
    root->left = insertNode(10);
    root->right = insertNode(20);
    root->left->left = insertNode(30);
    root->left->left->left = insertNode(40);

    node* lca = findLCA(root, 10, 30);
    cout<<lca->data<<"\n";

    return 0;
}