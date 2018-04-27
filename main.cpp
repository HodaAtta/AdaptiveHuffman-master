#include<bits/stdc++.h>
#include<Tree.h>
#include <string>
using namespace std;

int main()
{
    string mystr = "lossless";
    string strCode = "";


    Tree t;
    for(int i = 0 ; i<mystr.length() ; i++){
            cout<<"Adding ( "<<mystr[i]<<" )to the tree"<<endl;
            cout<<endl;
             t.public_add_Node(mystr[i]);
            t.printTree();
            strCode+=t.PublicSymbCode(mystr[i]);
            strCode+="|";

            cout<<endl;
    }
           cout<< "The Binary Code is: "<<strCode<<endl;




    return 0;
}
