#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insertNode(int d){
    struct node* temp=new node;
    temp->data = d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preorder(node* head){
    if(head==NULL)
        return;

    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}

void inorder(node* head){
    if(head==NULL)
        return;

    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}

void postorder(node* head){
    if(head==NULL)
        return;

    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}

int main(){
    struct node* head=NULL;

    head = insertNode(2);
    head->left = insertNode(3);
    head->left->left = insertNode(7);
    head->left->right = insertNode(10);
    head->right = insertNode(15);

    cout<<"Preorder:\n";
    preorder(head);

    cout<<"\nInorder:\n";
    inorder(head);

    cout<<"\nPostorder:\n";
    postorder(head);

    return 0;
}