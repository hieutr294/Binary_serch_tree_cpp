#include <iostream>
#include <vector>
#include <string>

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
};

int main()
{
    BST bst;
    int arr[9] = {8,3,10,1,6,14,4,7,13};
    for(int i = 0; i < 8; i++){
        bst.root = bst.insertNodeRecur(bst.root,arr[i]);
    }
    // bst.root = bst.insertNodeRecur(bst.root,8);
    // bst.root = bst.insertNodeRecur(bst.root,3);
    // bst.root = bst.insertNodeRecur(bst.root,10);  
    // bst.root = bst.insertNodeRecur(bst.root,1);  
    // bst.root = bst.insertNodeRecur(bst.root,6);
    // bst.root = bst.insertNodeRecur(bst.root,14);  
    // bst.root = bst.insertNodeRecur(bst.root,4);
    // bst.root = bst.insertNodeRecur(bst.root,7);  
    // bst.root = bst.insertNodeRecur(bst.root,13);
    // Node* firstNode = new Node;
    // Node* secondNode = new Node;
    // Node* thridNode = new Node;

    // firstNode->data = 3;
    // secondNode->data = 2;
    // thridNode->data = 1;

    // firstNode->right = secondNode;
    // firstNode->left = thridNode;
    
    // secondNode->left = NULL;
    // secondNode->right = NULL;

    // thridNode->left = NULL;
    // thridNode->right = NULL;

    cout << "Hello" << endl;
}