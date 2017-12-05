/*Onur Kulaksizoglu
21401315
Section 2
*/


#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
public:
    Node();
    Node(string);
    virtual ~Node();
    string item;
    Node* left;
    Node* right;
    int height();
    void traversePrint(string k);

protected:

private:
    int findMaxPrefixSimilarity(string);
    void print(string,int);
};

#endif // NODE_H
