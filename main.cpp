#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

class BST{
    public:
        BST(){}
        Node* root = NULL;

        void insertNode(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;

            if(root==NULL){
                root = newNode;
                return;
            }else{
                Node* temp = root;
                while (true)
                {
                    if(data > temp->data){
                        if(temp->right==NULL){
                            temp->right = newNode;
                            break;
                        }else{
                            temp = temp->right;
                        }
                    }else{
                        if(temp->left==NULL){
                            temp->left = newNode;
                            break;
                        }else{
                            temp = temp->left;
                        }
                    }
                }
            }
            
        }

        Node* insertNodeRecur(Node* root,int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;

            if(root==NULL){
                root = newNode;
            }else{
                if(data > root->data){

                    if(root->right==NULL){
                        root->right = newNode;
                    }else{
                        delete newNode;
                        insertNodeRecur(root->right,data);
                    }
                    
                }else{

                    if(root->left==NULL){
                        root->left = newNode;
                    }else{
                        delete newNode;
                        insertNodeRecur(root->left,data);
                    }

                }
            }
            return root;
        }

        Node* leftMost(Node* root){

            Node* left = root;
            if(left->left==NULL) return left;
            while (left->left){
                left = left->left;
            }

            return left;
        }

        Node* deleteNode(Node* root,int data){
            if(data==root->data){
                if(!root->left && !root->right){
                    return NULL;
                }else if(root->left && !root->right){
                    return root->left;
                }else if(!root->left && root->right){
                    return root->right;
                }else{
                    Node* leftNode = leftMost(root->right);
                    root->data = leftNode->data;
                    deleteNode(root->right,leftNode->data);
                }
            }else if(data > root->data){
                root->right = deleteNode(root->right,data);
            }else{
                root->left = deleteNode(root->left,data);
            }
            return root;
        }
        
        Node* findNode(Node* root, int value){
            if(value < root->data){
                findNode(root->left,value);
            }else if(value > root->data){
                findNode(root->right,value);
            }else{
                cout << "Founded" << endl;
            }
            return root;
        }

        void printTree(Node* root){
            if(root==NULL) return;
            cout << root->data << endl;
            printTree(root->left);
            printTree(root->right);
        }

        int maxHeight(Node* root){
            if(root == NULL) return 0;
            int left = maxHeight(root->left);
            int right = maxHeight(root->right);
            return max(left,right)+1;
        }
};

int main()
{
    int i = 8;
    BST bst;
    int arr[i] = {5,1,6,0,3,7,2,8};

    for(int j = 0; j < i; j++){
        bst.insertNode(arr[j]);
    }

    cout << bst.maxHeight(bst.root) << endl;
    cout << "Hello" << endl;
}