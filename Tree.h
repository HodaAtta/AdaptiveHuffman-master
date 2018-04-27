#ifndef TREE_H
#define TREE_H
#include<bits/stdc++.h>
using namespace std;
class Tree
{
private:
    struct treeNode
    {
        int weight;
        char symbol;
        treeNode* right;
        treeNode* left;
        treeNode* parent;
        int order;
        int symbol_index = 0;
//nyt * NYT;
    };
    /*struct nytNode {
    int weight = 0;
    char symbol = '-1';
    int order;
    treeNode *parent;
    };*/
    treeNode* root = new treeNode();
    treeNode* NYT=new treeNode();
//    int cnt = 51;
    treeNode* searchSymbol;
//void addLeafPrivate (treeNode* t, int k , string s);
    void printTreePrivate(treeNode* t);
//treeNode* searchKeyPrivate(treeNode* t, int k);
    void modify_NYT (treeNode *p);
    void praivate_add_Node(treeNode* r,char symb);
    treeNode* searchKeyPrivate(treeNode* t, char k);
     void  modify_weight_child( treeNode* n,char s);
  string NYTPATH(treeNode * nyt);
  string PrivateSymbCode (treeNode* r);
   void  Swap(treeNode* n , treeNode* m);
   void  SwapTree (treeNode * nyt);
   //string printCodeprivate (treeNode* t);

   string Decode(string s);
    int codeToDec(int x);
    char AsciiToChar(int x);
    string sequence = "";
    bool ifExist(treeNode*r,string A);
    int strToInt(string s);



public:
    Tree();
    void printTree();
    treeNode* create_Parent_Node();
    treeNode* create_Child_Node(char s);
    void public_add_Node(char symb);
    void modify_index_cnt(int n);
    int Arr [36] = {0};
    char Arr1 [36]= {'a','b','c','d','e','f','g','h','i','j','k','l',
         'm','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    //char AlphabitArray[26] = };
    //char FigureArray[10] = {
    void searchKeyPublic( char k);
    string nytpath ;
    string NYTPath();
    string symCode;
    string code;
    string BinaryToDecimal (int d);
    string PublicSymbCode(char s);
    int makeEqualLength(string &str1, string &str2);
    string addBitStrings( string first, string second );
    void reverseStr(string &str);
    //string printCode();
     void  Swaptest();
     void SwapTreeTest ();
  //  void  modify_weight_parent(treeNode* n, char s);

  int codeToSeq(int s);
  string Decode(treeNode*r ,string s);

};

#endif // TREE_H
