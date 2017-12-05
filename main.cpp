/*Onur Kulaksizoglu
21401315
Section 2
*/



#include "AVL.h"
#include <fstream>
#include <iostream>

//takes dictionary file as an argument

using namespace std;
int main(int argc, char* argv[])
{
    ifstream file;

    file.open(argv[1]);
    AVL tree;
    //creates tree from the file
    while(!file.eof())
    {
        string str;
        file>>str;
        tree.insert(new Node(str));
    }

//menu for search operation
    cout<<"Welcome to Dothraki Vocabulary!"<<endl;
    cout<<"This vocabulary contains "<<tree.size<<" words."<<endl;
    while(true)
    {
        string answ;
        cout<<"Enter a word: ";
        cin>>answ;
        if(answ.compare("quit")==0)
        {
            cout<<"Good Bye";
            break;
        }
        else
        {
            tree.search(answ);
        }
    }
}
