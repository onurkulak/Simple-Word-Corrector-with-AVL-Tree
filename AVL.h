#ifndef AVL_H
#define AVL_H
/*Onur Kulaksizoglu
21401315
Section 2
*/


#include "Node.h"

class AVL
{
public:
    AVL();
    virtual ~AVL();

    bool insert(Node*);
    void search(string);
    int size;
protected:

private:
    Node* retrieveParent(string);
    void fix(string);
    void rotate(Node*&);
    void leftRightRotate(Node*&);
    void leftRotate(Node*&);
    void rightRotate(Node*&);
    void rightLeftRotate(Node*&);

    Node* root;
};

#endif // AVL_H
