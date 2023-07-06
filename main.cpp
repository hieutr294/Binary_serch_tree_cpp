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
    private:
        Node* root = NULL;
    public:
        BST(){}
        
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
};

int main()
{
    BST bst;
    bst.insertNode(8);
    bst.insertNode(3);
    bst.insertNode(10);  
    bst.insertNode(1);  
    bst.insertNode(6);
    bst.insertNode(14);  
    bst.insertNode(4);
    bst.insertNode(7);  
    bst.insertNode(13);
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