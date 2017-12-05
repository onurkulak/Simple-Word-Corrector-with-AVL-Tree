/*Onur Kulaksizoglu
21401315
Section 2
*/


#include "Node.h"
#include <iostream>
Node::Node()
{
    //ctor
    left=nullptr;
    right=nullptr;
}

int Node::height()
{
    if(this==nullptr)
        return 0;
    int l=left->height();
    int r=right->height();
    if(l<r)
        return r+1;
    else return l+1;
} //returns height of subtree that called node is root

void Node::traversePrint(string k)
{
    int l=findMaxPrefixSimilarity(k);
    print(k,l);
} //from the called node and its subnodes, prints the words with maximum prefix match to the given string "k"



//returns the maximum prefix match length
int Node::findMaxPrefixSimilarity(string k)
{
    if(this==nullptr)
        return 0;
    int l=left->findMaxPrefixSimilarity(k);
    int r=right->findMaxPrefixSimilarity(k);
    int t=0;
    for(int i=1; i<=k.length()&&i<=item.length(); i++)
        if(k.find(item.substr(0,i),0)==0)
            t++;
        else break;
    if(t>l&&t>r) return t;
    else if(l<r) return r;
    return l;
}


//prints all the node items that match "l" length prefix with string "k"
void Node::print(string k, int l)
{
    if(this!=nullptr)
    {
        if(k.find(item.substr(0,l),0)==0&&l<=item.length())
            cout<<item+" "<<flush;
        left->print(k,l);
        right->print(k,l);
    }
}

//ctor
Node::Node(string ch)
{
    item=ch;
    left=nullptr;
    right=nullptr;
}

//dtor
Node::~Node()
{


}
