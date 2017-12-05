/*Onur Kulaksizoglu
21401315
Section 2
*/


#include "AVL.h"
#include <iostream>
using namespace std;

AVL::AVL()
{
    root=nullptr;
    size=0;
}


//inserts a given node to the AVL, first searches for the item
//then inserts and calls fix method that balances AVL
bool AVL::insert(Node* nd)
{
    if(root==nullptr)
        root=nd;
    else
    {
        Node* par=retrieveParent(nd->item);
        if(par->item.compare(nd->item)<0)
            par->left=nd;
        else par->right=nd;
        fix(nd->item);
    }
    size++;
    return true;
}


//returns the parent node of a node with the given key
//if item is not on the AVL returns the node that it's need to be attached
Node* AVL::retrieveParent(string key)
{
    if(root==nullptr)
        return nullptr;

    if(root->item.compare(key)==0)
        return root;
    Node* cur=root;
    while(true)
    {
        int res=cur->item.compare(key);
        if(res<0)
            if(cur->left==nullptr||cur->left->item.compare(key)==0)
                return cur;
            else cur=cur->left;
        else if (cur->right==nullptr||cur->right->item.compare(key)==0)
            return cur;
        else cur=cur->right;
    }

}


//balances height of the tree by rotating lowest level node that is unbalanced
void AVL::fix(string k)
{
    Node** cur=&root;
    Node** change=nullptr;
    while(*cur!=nullptr)
    {
        int dif =(*cur)->left->height()-(*cur)->right->height();
        if(dif>1||dif<-1)
        {
            change=cur;
        }
        if((*cur)->item.compare(k)<0)
            cur=&((*cur)->left);
        else cur=&((*cur)->right);
    }
    if(change!=nullptr)
        rotate(*change);
}


//if searched item is in the tree prints it
//if not, calls the traverseprint method on the first element
// that matches at least half prefix match with the string k
//if there isn't a word that provides half prefix match, prints it's not found
void AVL::search(string k)
{
    Node* n=retrieveParent(k);
    if(n==root)
        cout<<"Found! The word is in vocabulary."<<endl;
    else
    {
        if(n->item.compare(k)<0&&n->left!=nullptr)
            cout<<"Found! The word is in vocabulary."<<endl;
        else if(n->item.compare(k)>0&&n->right!=nullptr)
            cout<<"Found! The word is in vocabulary."<<endl;
        else
        {
            cout<<"Not Found! "<<endl;
            int enough=(k.length()+1)/2;
            string sub=k.substr(0,enough);
            Node* cur=root;
            while(cur!=nullptr)
            {
                if(cur->item.find(sub,0)!=0)
                    if(cur->item.compare(sub)<0)
                        cur=cur->left;
                    else cur=cur->right;
                else
                {
                    cout<<"Some suggestions: ";
                    cur->traversePrint(k);
                    cout<<endl;
                    break;
                }
            }
            if(cur==nullptr)
                cout<<"Some suggestions: There is no word starting with prefix: \""<< sub <<"\" in vocabulary! "<<endl;
        }
    }
}
AVL::~AVL()
{
    //dtor
}



//decides on what type of rotation to do on an unbalanced node
void AVL::rotate(Node*& nd)
{
    if(nd->left->height()>nd->right->height())
        if(nd->left->left->height()>nd->left->right->height())
            rightRotate(nd);
        else
            leftRightRotate(nd);
    else if(nd->right->left->height()>nd->right->right->height())
        rightLeftRotate(nd);
    else leftRotate(nd);
}



//rotation methods
void AVL::leftRotate(Node*& nd)
{
    Node* rc=nd->right;
    nd->right=rc->left;
    rc->left=nd;
    nd=rc;
}

void AVL::rightRotate(Node*& nd)
{
    Node* lc=nd->left;
    nd->left=lc->right;
    lc->right=nd;
    nd=lc;
}

void AVL::leftRightRotate(Node*& nd)
{
    leftRotate(nd->left);
    rightRotate(nd);
}

void AVL::rightLeftRotate(Node*& nd)
{
    rightRotate(nd->right);
    leftRotate(nd);
}
