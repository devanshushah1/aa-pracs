# include<iostream>
# include<bits/stdc++.h>
using namespace std;

#define RED 1
#define BLACK 0

class Node{
    public:
        Node *parent, *left, *right;
        int data;
        bool colour;

    //constructor()
    Node(int data){
        this->data = data;
        this->colour = RED;
        this->parent = NULL; 
        this->left =  NULL;
        this->right = NULL;
    }
};

Node *root = NULL;

void left_rotate(Node *pt){
    Node *pt_right = pt->right;
    pt->right = pt_right->left;

    if(pt->right!=NULL) pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if(pt->parent==NULL) root = pt_right;
    else if(pt->parent->left == pt) pt->parent->left = pt_right;
    else pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void right_rotate(Node *pt){
    Node *pt_left = pt->left;
    pt->left = pt_left->right;
    if(pt->left != NULL) pt->left->parent  = pt;
    pt_left->parent = pt->parent;
    if(pt->parent == NULL) root = pt_left;
    else if(pt->parent->left == pt) pt->parent->left = pt_left;
    else pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}

Node* BSTInsert(Node *rt, Node *pt){
    if(rt == NULL) return pt;
    
    if(pt->data<rt->data){
        rt->left = BSTInsert(rt->left, pt);
        rt->left->parent = rt;
    }else{
        rt->right = BSTInsert(rt->right, pt);
        rt->right->parent = rt;
    }

    return rt;
}


void fixViolation(Node *pt){
    Node *parent_pt = NULL;
    Node *grandparent_pt = NULL;
    // if(pt->data ==6) cout<<"####: "<<pt<<" --- "<<pt->parent<<" --- "<< root <<"#####"<<endl;
    while((pt!=root) && (pt->colour != BLACK ) && (pt->parent->colour == RED )){

        parent_pt = pt->parent;
        grandparent_pt = pt->parent->parent;

        // CASE A: parent of pt is left child of grandparent
        if(parent_pt == grandparent_pt->left){
            Node *uncle_pt = grandparent_pt->right;
            
            if(uncle_pt != NULL && uncle_pt->colour==RED){
                //case 1 - uncle is red, only recolouring
                parent_pt->colour = BLACK;
                grandparent_pt->colour = RED;
                uncle_pt->colour = BLACK;
                pt = grandparent_pt;
            }else{
                //case 2 - uncle is black, triangle
                //left rotate parent
                if(pt == parent_pt->right){
                    left_rotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                //case 3 - uncle is black, straight
                //right rotate grandparent
                //recolour og parent and grandparent
                else{
                    right_rotate(grandparent_pt);
                    swap(parent_pt->colour, grandparent_pt->colour);
                    pt = parent_pt;
                }
            }
        }
        // CASE B: parent of pt is right child of grandparent
        else{
            Node *uncle_pt = grandparent_pt->left;
            
            if((uncle_pt!=NULL) && (uncle_pt->colour==RED)){
                grandparent_pt->colour = RED;
                parent_pt->colour = BLACK;
                uncle_pt->colour = BLACK;
                pt = grandparent_pt;
            }else{
                if(pt == pt->parent->left){
                    right_rotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }else{
                    left_rotate(grandparent_pt);
                    swap(parent_pt->colour, grandparent_pt->colour);
                    pt = parent_pt;
                }
            }
        }
    }

    root->colour = BLACK;
}

void inorder(Node *rt)
{
    if (rt == NULL)
        return;

    inorder(rt->left);
    cout << rt->data << "  ";
    inorder(rt->right);
}


void insert(const int &data){
    Node *pt = new Node(data);
    // cout<<"hi"<<endl;
    root = BSTInsert(root, pt);
    // cout<<"hi2"<<endl;
    fixViolation(pt);
    // cout<<"hi3"<<endl;
}

int main(){

    insert(7);
    // cout<<root->data<<endl;
    // cout<<endl;
    insert(6);
    // cout<<root->data<<endl<<endl;
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);

    cout << "Inorder Traversal of Created Tree\n";
    inorder(root);
    cout<<endl;
    return 0;
}