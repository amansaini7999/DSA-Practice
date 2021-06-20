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

void levelTraversal(node* head){
    queue<node*> q;
    q.push(head);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);

        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

void spiral(node* head){
    if(head==NULL)
        return;

    stack<node*> s1;
    stack<node*> s2;

    s1.push(head);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* temp = s1.top();
            cout<<temp->data<<" ";
            s1.pop();

            if(temp->right)
                s2.push(temp->right);

            if(temp->left)
                s2.push(temp->left);
        }

        while(!s2.empty()){
            node* temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";

            if(temp->left)
                s1.push(temp->left);

            if(temp->right)
                s1.push(temp->right);
        }
    }
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

    cout<<"\nLevel Traversal:\n";
    levelTraversal(head);

    cout<<"\nSpiral:\n";
    spiral(head);

    return 0;
}