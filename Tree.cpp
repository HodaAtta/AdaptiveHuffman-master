#include "Tree.h"
#include<bits/stdc++.h>
using namespace std;
Tree::Tree()
{
    //ctor
    root = NULL;
    NYT->parent = NULL;
    NYT->symbol = '#';
    NYT->left=NULL;
    NYT->right=NULL;
    NYT->weight=0;
}
void Tree :: modify_NYT (treeNode *p)
{
    NYT->parent = p;
}
Tree:: treeNode* Tree:: create_Parent_Node()
{
    treeNode* Node = new treeNode();
    Node->left=NULL;
    Node->right=NULL;
    Node->symbol='@';
    Node->parent = NYT->parent;
    Node->weight=0;
    modify_NYT(Node);
    return Node;
}
Tree:: treeNode* Tree:: create_Child_Node(char s)
{
    treeNode* Node = new treeNode();
    Node->left=NULL;
    Node->right=NULL;
    Node->symbol=s;
    Node->parent = NYT->parent;
    Node->weight=1;
    if(s >= 'a' && s <= 'z'){
        Node->symbol_index = s - 'a' + 1;
    }else{
        Node->symbol_index = s - '0' + 1 + 26;
    }
    return Node;
}
void Tree:: public_add_Node(char symb)
{
    if (root==NULL)
    {

        praivate_add_Node( root, symb);
    } int s_i;
    if(symb >= 'a' && symb <= 'z'){
        s_i = symb - 'a' + 1;
    }else{
        s_i = symb - '0' + 27;
    }
    modify_index_cnt(s_i);
    treeNode* n = new treeNode();
    n = searchKeyPrivate(root,symb);
    if (n->symbol == symb)
    {
        modify_weight_child(n,symb);
        while(n->parent!=NULL)
                {
                    (n->parent)->weight += 1;
                     n=n->parent;
                }
        SwapTree(NYT);
    }
    else
    {
        praivate_add_Node( root, symb);
        SwapTree(NYT);
    }

}
    void Tree:: praivate_add_Node(treeNode* r,char symb)
    {
        if (root==NULL)
        {
            root = create_Parent_Node();
            root->right = create_Child_Node(symb);
            root->left = NYT;
          //  modify_weight_parent(root,root->symbol);
        }
        else
        {
            if(r->left != NYT&&r->left->symbol=='@')
            {
                praivate_add_Node( r->left, symb);
            }
            else if (r->left != NYT && r->left->symbol!='@')
            {
                praivate_add_Node(r->right,symb);
            }
            else
            {
                r->left = create_Parent_Node();
                r->left->right = create_Child_Node(symb);
                r->left->left = NYT;
                r->left->weight+=1;
                while(r!=NULL)
                {
                    r->weight += 1;
                    r=r->parent;
                }

               // cout << r->weight << endl;
                }


               // modify_weight_parent(r,r->symbol);

        }


    }
    void Tree:: printTree()
    {
        printTreePrivate(root);
    }
    void Tree:: printTreePrivate(treeNode* t)
    {
        if(root != NULL)
        {
            if (t->left != NULL)
            {
                printTreePrivate(t->left);
            }

            if (t->right != NULL)
            {
                printTreePrivate(t->right);

            }
      cout <<"[" <<t->symbol <<"     weight "<<t->weight << "]" << endl ;
        }

        else
            cout << "The Tree is Empty" << endl;

    }
    void Tree:: modify_index_cnt(int n)
    {
        Arr [n]++;
    }
    void Tree:: modify_weight_child( treeNode* n,char s)
    {
        int symbol_index ;
        if(s >= 'a' && s <= 'z'){
            symbol_index = s - 'a' + 1;
        }else{
            symbol_index = s - '0' + 27;
        }
        if(Arr[symbol_index]>1)
            {
                (n->weight)++;
            }
    }

    void Tree:: searchKeyPublic( char s)
    {
        cout << searchKeyPrivate( root, s)->symbol << endl;

    }

    Tree:: treeNode* Tree:: searchKeyPrivate(treeNode* t, char k)
    {
        //treeNode * searchSymbol = new treeNode();
        if(root != NULL)
        {
            if (t->right != NULL)
            {
                searchKeyPrivate(t->right,k);
            }
            if (t->symbol == k)
            {
                searchSymbol = t;

            }
            if (t->left != NULL)
            {
                searchKeyPrivate(t->left,k);
            }
            return searchSymbol;
        }
        else
        {
            return NULL;
        }

    }

std::  string Tree:: NYTPath ()
    {
        nytpath="";
        return NYTPATH(NYT);
    }
    std:: string Tree:: NYTPATH (treeNode* nyt)
    {
        if (nyt == root)
        {
            nytpath = nytpath.substr(1,nytpath.size() - 1);
            reverseStr(nytpath);
            return nytpath;
        }
        else if (nyt== nyt->parent->left)
        {

            nytpath+='0';
             return NYTPATH(nyt->parent);

        }
        else if (nyt == nyt->parent->right)
        {
            nytpath+='1';
           return NYTPATH(nyt->parent);
        }
    }
    void Tree:: Swap(treeNode* n , treeNode* m)
    {
        treeNode * tmp1 = new treeNode();
        treeNode * tmp2 = new treeNode();
            tmp1 = n;
            tmp2 = m;
        if(n->parent->left== n)
        {
            if (m->parent->left == m)
            {
                n->parent->left = tmp2;
                m->parent->left = tmp1;
            }
            else if (m->parent->right== m)
            {
                n->parent->left = tmp2;
                m->parent->right = tmp1;
            }
        }
        else if (n->parent->right == n)
        {
            if (m->parent->left == m)
            {
                n->parent->right = tmp2;
                m->parent->left = tmp1;
            }
            else if (m->parent->right== m)
            {
                n->parent->right = tmp2;
                m->parent->right = tmp1;
            }
        }
    }
     void Tree:: Swaptest()
     {
         Swap(root->left, root->right);
     }

     void Tree:: SwapTreeTest ()
     {
          SwapTree (NYT);
     }
     void Tree:: SwapTree (treeNode * nyt)
   {
       if (nyt== root)
       {
           return ;
       }
       else if ((nyt->weight > nyt->parent->right->weight) && ((nyt->weight) - (nyt->parent->right->weight)!=0))
       {
           Swap(nyt, nyt->parent->right);
           return SwapTree(nyt->parent);
       }
       else
       {
           return SwapTree(nyt->parent);
       }
   }

   std::string Tree::BinaryToDecimal (int d){
    if(d==0)
    {
        return "0";
    } else if (d == 1)
    {
        return "1";
    } else {
        return BinaryToDecimal(d/2) + BinaryToDecimal(d%2);
    }
   }

   std :: string Tree :: PublicSymbCode(char s){
    symCode = "";
    code = "";
    treeNode* n = new treeNode();
    n = searchKeyPrivate(root,s);
    return PrivateSymbCode(n);
   }

   std :: string Tree::PrivateSymbCode(treeNode* r){
       if (r->weight>1){
           if (r == root)
           {
               reverseStr(symCode);
               return symCode;
           } else if (r == r->parent->left)
           {
               symCode+='0';
               return PrivateSymbCode(r->parent);
           } else if (r == r->parent->right)
           {
               symCode+='1';
               return PrivateSymbCode(r->parent);
           }

       } else {
            int i ;
            for (i=0 ; i<=36 ; i++)
            {
                if(r->symbol == Arr1[i])
                {
                    if(i<20)
                    {

                     symCode = addBitStrings("00000",BinaryToDecimal(i));
                      code+=NYTPath();
                      code+=":";
                      code+=symCode;
                      return code;

                    } else if (i>=20 && i<26){
                        i = i-10;
                        symCode = addBitStrings("0000",BinaryToDecimal(i));
                          code+=NYTPath();
                          code+=":";
                          code+=symCode;
                          return code;

                    }else if (i>=26){
                        i=i-26;
                        if(i<4)
                       {
                           symCode = addBitStrings("0000",BinaryToDecimal(i));
                          code+=NYTPath();
                          code+=":";
                          code+=symCode;
                          return code;
                       } else {
                        i=i-2;
                        symCode = addBitStrings("000",BinaryToDecimal(i));
                          code+=NYTPath();
                          code+=":";
                          code+=symCode;
                          return code;
                        }
                    }
                }
          }
    }
     //SwapTree(NYT);
}

int Tree::makeEqualLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0 ; i < len2 - len1 ; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 = '0' + str2;
	}
	return len1;
}

std::string Tree::addBitStrings( string first, string second )
{
	string result;
	int length = makeEqualLength(first, second);

	int carry = 0;

	for (int i = length-1 ; i >= 0 ; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';

		int sum = (firstBit ^ secondBit ^ carry)+'0';

		result = (char)sum + result;

		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}

	if (carry)
		result = '1' + result;

	return result;
}

void Tree:: reverseStr(string &str)
{
    int n = str.length();
    for (int i=0; i<n/2; i++){
       swap(str[i], str[n-i-1]);
    }
}

//Decoding
int Tree:: codeToDec(int bin)
{
    int n=0, i=0;
    while (bin != 0){
        n += (bin%10)*pow(2,i);
        i++;
        bin /= 10;
    }
    return n;
}
int Tree:: codeToSeq(int s)
{
return codeToDec(s);
}


char Tree:: AsciiToChar(int A)
{    int x;
     if (A>96 && A<123){
      x = A + 96; //begin from a
     }
     else if (A>64 && A<91){
       x = A + 64;
     }
     else if (A>47 && A<58){
       x = A + 47;
     }

     char chr;
     chr = (char)x;
     return chr;
}
bool Tree:: ifExist(treeNode*r,string A){
    if (root == NULL) {
    return false;
    }
    if (root->right == NULL && root->left== NULL) {
    return true;
    }

    string A1 =A;
    A ="";
    for (int i=0;i<A1.length();i++){
        A += A1[i+1];
    }
    string c1 =A1[1];
    int x = strToInt (c1);
    if (x = 0){

        ifExist(root->left, A);
    }
    else{
        ifExist(root->right, A);
    }
}
char Tree:: secTimeDecode(treeNode*r,string A){
    if (root->right == NULL && root->left== NULL){
        char chr = root->symbol;
        return chr;
    }
    if (root == NULL) {
         char chr = "";
    return chr;
    }
    string A1 =A;
    A ="";
    for (int i=0;i<A1.length();i++){
        A += A1[i+1];
    }
    int x = strToInt (A1[1]);
    if (x = 0){

        secTimeDecode(root->left, A);
    }
    else{
        secTimeDecode(root->right, A);

    }

}
int Tree:: strToInt(string s){
    int x=0;
    int Size = s.length();
    for (int i=0, j=Size;i<Size;i++){
        x += (s[--j]-'0')*pow(10,i);
    }
    return x;
}

string Tree:: Decode(treeNode*r ,string s)
{
    char  *Arr1,*Arr2,*Temp;
    Arr1 = new char[1000];
    Arr2 = new char[1000];
    Temp = new char[1000];
    bool cond;
    string A ="";
    int B,x;
    char chr;


    for (int i=0;i<s.length();i++){
        Arr1[i] = s[i];
    }
    for (int i=0;i<4;i++){
        Arr2[i] = Arr1[i];
        A+=Arr1[i];
    }
    B = strToInt(A);
    x = codeToSeq(B);
    if (x<10){
        A += Arr1[4];
        B = strToInt(A);
        x = codeToSeq(B);
        chr = AsciiToChar(x+1);
        sequence += chr;
        public_add_Node(chr);

    }
    for (int i=0;i<Arr1.length();i++){
        Temp[i] = Arr1[i];
    }
    for (int i=0;i<Arr1.length();i++){
        Arr1[i] = "";
    }
    for (int i=0;i<Temp.length();i++){
        Arr1[i] = Temp[i+4] ;
    }
    for (int i=0;i<4;i++){
        Arr2[i] = Arr1[i];
        A+=Arr1[i];
       cond = ifExist(root,A);
       if (cond){
        chr = secTimeDecode(A);
        break;
       }

    }
    if (A.length()==4){
        for (int i=0;i<4;i++){
        Arr2[i] = Arr1[i];
        A+=Arr1[i];
        }
        Decode(root ,string A);
    }
    else{
        if (chr == '1'){

            for (int i=0;i<Arr1.length();i++){
            Temp[i] = Arr1[i];
            }
            for (int i=0;i<Arr1.length();i++){
            Arr1[i] = "";
            }
            for (int i=0;i<Temp.length();i++){
            Arr1[i] = Temp[i+(A.length())] ;
            }
            Decode(root ,string A);
        }
        else{
            sequence += chr;
            for (int i=0;i<Arr1.length();i++){
            Temp[i] = Arr1[i];
            }
            for (int i=0;i<Arr1.length();i++){
            Arr1[i] = "";
            }
            for (int i=0;i<Temp.length();i++){
            Arr1[i] = Temp[i+(A.length())] ;
            }
            Decode(root ,string A);
        }
    }

    return sequence;

}

