#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int hd;
    struct node* left=NULL;
    struct node* right=NULL;
};

node* insertNode(int d){
    node* temp = new node;
    temp->data = d;
    temp->hd = INT_MAX;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void bottomView(node* root){
    if(root==NULL)
        return;

    queue<node*> q;
    map<int, int> mp;

    root->hd=0;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int h = temp->hd;
        mp[h]=temp->data;

        if(temp->left){
            temp->left->hd = h-1;
            q.push(temp->left);
        }

        if(temp->right){
            temp->right->hd = h+1;
            q.push(temp->right);
        }
    }

    for(auto itr: mp)
        cout<<itr.second<<" ";

}

void topView(node* root){
    if(root==NULL)
        return;
    
    queue<node*> q;
    map<int, int> mp;
    root->hd=0;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int h = temp->hd;
        if(mp.find(h)==mp.end())
            mp[h] = temp->data;

        if(temp->left){
            temp->left->hd=h-1;
            q.push(temp->left);
        }

        if(temp->right){
            temp->right->hd=h+1;
            q.push(temp->right);
        }

    }

    for(auto itr: mp)
        cout<<itr.second<<" ";
}

void inorder(node* root, int level, map<int, int>& mp){
    if(root==NULL)
        return;

    inorder(root->left, level+1, mp);
    if(mp.find(level)==mp.end())
        mp[level]=root->data;
    inorder(root->right, level+1, mp);
}

void leftView(node* root){
    if(root==NULL)
        return;

    map<int, int> mp;
    inorder(root, 0, mp);

    for(auto itr: mp)
        cout<<itr.second<<" ";
}

int main(){
    struct node* root;
    root = insertNode(2);
    root->left = insertNode(5);
    root->right = insertNode(10);
    root->left->left=insertNode(15);
    root->left->right=insertNode(17);
    root->left->right->right=insertNode(23);

    cout<<"Bottomm View:\n";
    bottomView(root);

    cout<<"\nTop view:\n";
    topView(root);

    cout<<"\nLeft View:\n";
    leftView(root);

    return 0;
}