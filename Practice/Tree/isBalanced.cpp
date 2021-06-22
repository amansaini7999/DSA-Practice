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

bool isBalanced(node* root, int &height){
    int lheight=0;
    int rheight=0;

    if(root==NULL)
        return true;
    
    if(isBalanced(root->left, lheight)==false)
        return false;
    
    if(isBalanced(root->right, rheight)==false)
        return false;

    height = max(lheight, rheight)+1;

    if(abs(lheight-rheight)<=1)
        return true;
    else
        return false;

}

int main(){
    node* root = insertNode(10);
    root->left = insertNode(23);
    root->right = insertNode(17);
    root->left->left = insertNode(90);
    root->left->left->left = insertNode(93);
    root->left->right = insertNode(92);

    int height=0;
    if(isBalanced(root, height))
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}