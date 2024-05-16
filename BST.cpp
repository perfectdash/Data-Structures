#include <iostream>
#include <queue> 
using namespace std;

class node {
    public:
      int data ;
      node *left;
      node *right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;    
    }
};

node* buildTree(node *root){
     int data ;
     cout<<"Enter the data :"<<"\n";
     cin>>data;
     root =new node(data);
     if(data==-1){
        return NULL;
     }
     cout<<"Enter the data for insertion in left :"<<"\n";
     root->left= buildTree(root->left);

     cout<<"Enter the data for insertion in Right :"<<"\n";
     root->right= buildTree(root->right);


};

void levelOrdertraveral(node *root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node* temp = q.front();
            cout<<temp->data<<"\n";
            q.pop();

            if(temp){
                cout<<"\n";
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
}


//inorder(LNR) preorder(NLR) and postorder table(LRN)

void inordertraversal(node *root){
    // base case 
    if(root==NULL){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<<"\n";
    inordertraversal(root->right);

}

// build these traversal using iteration 

node* buildtree(node *root){
    queue<node*> q;
    
}

int main(){
     node* root =NULL;

    return 0;
}
