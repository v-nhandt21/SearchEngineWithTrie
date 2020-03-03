#pragma once
#include <iostream>
#include <chrono>
using namespace std::chrono;
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include<functional>
#include <vector>
#include <algorithm>
#include "ctype.h"
#define _WIN32_WINNT 0x0500
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
const int ALPHABERT_NUM = 38;
const int File_scale = 100;




//UI
void gotoxy(int x, int y);
int wherex();
int wherey();                                               //Cac ham ho tro hien thi 
void textcolor(int x);
void resizeConsole(int width, int height);
void centerstring(char* s);
void window(int x, int y);

//Test
string standard_alpha(string s);
void CreatTXT();
string Int_to_String(int &x);                        //Cac ham thu nghiem
void ColorChoose();
void string_to_token(string content, vector <string>&Token);
string standard_alpha(string s);
void chuan(vector <string>&Token, string tok);
bool check_string_digit(string s);

//Main structure
//Trie
struct Node {
	Node *Children[ALPHABERT_NUM];
	int N_times = 0;                         //so lan tu xuan hien trong van ban
	int position[100] = { -1 };                       //danh sach vi tri nhung tu do
	int posNum = 0;
};
class Trie {
public:
	Node * pHead = NULL;
	Node* search(string key);
	void Insert_Vector(vector <string> &Token, Trie SW);          //Dung build Trie cua File
	void Insert_Token(string s, int i);                           //Dung build Trie cua Stopword
};
//AVL
struct AVLNode {
	int index;
	string Token;
	int height;
	AVLNode *left, *right;
};
//Synonym
struct NodeList {
	string data;
	NodeList *synnext = NULL;
};

class Synonymous
{
public:
	Synonymous() { pHead = NULL; }
	void Insert(string Token, int index);
	AVLNode* Insert1(string Token, AVLNode *& t, int index);
	int Search(string Token);

	AVLNode* singleRightRotate(AVLNode* &t)
	{
		AVLNode* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(u->left), t->height) + 1;
		return u;
	}

	AVLNode* singleLeftRotate(AVLNode* &t)
	{
		AVLNode* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(t->right), t->height) + 1;
		return u;
	}

	AVLNode* doubleLeftRotate(AVLNode* &t)
	{
		t->right = singleRightRotate(t->right);
		return singleLeftRotate(t);
	}

	AVLNode* doubleRightRotate(AVLNode* &t)
	{
		t->left = singleLeftRotate(t->left);
		return singleRightRotate(t);
	}
	int height(AVLNode * t)
	{
		return (t == NULL ? -1 : t->height);
	}

	void RemoveAll(AVLNode *& node) {
		if (node != NULL) {
			RemoveAll(node->left);
			RemoveAll(node->right);
			delete node;
		}
	}

	~Synonymous() { RemoveAll(pHead); }
	void Build(NodeList *SynArr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			NodeList *cur = SynArr[i];
			while (cur != NULL) {
				this->Insert(cur->data, i);
				cur = cur->synnext;
			}
		}
	}
private:
	AVLNode * pHead;

};



//File
class File {
private:
	string Address;													 //1.txt
	string Titile;													 //Ngoc Trinh cap dat
	string Content_Searched;										 //Phan doan van chua tu do
	string Content;													 //Toan van ban
	vector <string> Token;											//Toan van ban luu dang Token
	Trie FileWord;													//Cay de tim kiem tu khoa	
	string type;
public:
	long int rank = 0;
	File() {
		FileWord.pHead = NULL;
	}
	~File() {
		RemoveAll(FileWord.pHead);
		if (FileWord.pHead != NULL)
		{
			delete FileWord.pHead;
			FileWord.pHead = NULL;
		}
	}

	void Input(string X,string folder);   //Input File -> string -> vector token
							//vector -> Trie
	void BuildTrie(Trie SW)
	{
		FileWord.Insert_Vector(this->Token, SW);
	}
	void Print_Search(string key); //Print trong luc hien top 5    
						 //void swapF(File F2);
	void Print();        //Print toan bo van ban
	void RemoveAll(Node *& node);
	void Rank(string key_search,bool &yes, NodeList *SynArr[462], Synonymous& SynTree);                  //!
	int Rank_Case1(string key_search);
	int Rank_Case2(string key_search);
	int Rank_Case3(string key_search);
	int Rank_Case4(string key_search);
	int Rank_Case5(string key_search);
	int Rank_Case6(string key_search);
	int Rank_Case7(string key_search);
	int Rank_Case8(string key_search);
	int Rank_Case9(string key_search);
	int Rank_Case10(string key_search);
	int Rank_Case11(string key_search);
	int Rank_Case12(string key_search, NodeList *SynArr[462], Synonymous& SynTree);
	int Rank_Case13(string key_search);
	void Reset()
	{
		rank = 0;
	}
};

//Backend
void Read_Filename(vector <string> & Data);
void Index_Screen();
void Input_Key(string & search_key, vector <string> & His);
void Search_Result(File *&F, string search_key,int size);
void Build_Trie_Stopword(Trie& Stopword);
int Input_syn_to_hash(NodeList* SynArr[]);
void Input_Sym(NodeList *SynArr[462], Synonymous& SynTree);
