#include "Header.h"
//Rank Function
int File::Rank_Case1(string key_search)
{
	string key = key_search;
	for (int i = 0; i < key.size(); i++)
		if (isalpha(key[i])) key[i] = tolower(key[i]);
	int k = key.find(" and ");
	
	string s1 = key.substr(0, k);
	string s2 = key.substr(k+5, key.size()-k-5);
	if (Rank_Case9(s1) != 0 && 
		Rank_Case9(s2) != 0) return 10000;
	else return 0;
}
int File::Rank_Case2(string key_search) 
{
	string key = key_search;
	for (int i = 0; i < key.size(); i++)
		if (isalpha(key[i])) key[i] = tolower(key[i]);
	int k = key.find(" or ");
	
	string s1 = key.substr(0, k);
	string s2 = key.substr(k + 4, key.size()-k-4);
	long int R1 = Rank_Case9(s1);
	long int R2 = Rank_Case9(s2);
	if (R1 != 0 ||
		R2 != 0) return 10000;
	else return 0;
}
int File::Rank_Case3(string key_search)
{
	string key = key_search;
	int k = key.find(" - ");
	for (int i = 0; i < key.size(); i++)
		if (isalpha(key[i])) key[i] = tolower(key[i]);
	string s1 = key.substr(0, k);
	string s2 = key.substr(k + 3, key.size());
	long int R1 = Rank_Case9(s1);
	long int R2 = Rank_Case9(s2);
	if (R1 > 1000 &&
		R2 == 0) 
		return 100000;
	else return 0;
}
int File::Rank_Case4(string key_search)
{
	string c = key_search;
	c = c.erase(0, 8);
	if (c.size() != 0)
	{
		for (int i = 0; i < c.size(); i++)
		{
			if (isalpha(c[i])) c[i] = tolower(c[i]);
		}
	}
	string T = Titile;
	if (T.size() != 0) {
		for (int i = 0; i < T.size(); i++)
		{
			if (T[i] <= -1 || T[i] >= 255) T[i] = ' ';
			if (isalpha(T[i])) T[i] = tolower(T[i]);
		}
	}
	if (T.find(c) != std::string::npos) return 10000;
	else return 0;
}
int File::Rank_Case5(string key_search ) 
{
	string key = key_search;
	int k = key_search.find("+");
	key.erase(k, 1);
	int R = 0;
	R += Rank_Case9(key);
	return R;
}
int File::Rank_Case6(string key_search ) 
{
	string c = key_search;
	c = c.erase(0, 9);
	if (c.size() != 0)
	{
		for (int i = 0; i < c.size(); i++)
		{
			if (isalpha(c[i])) c[i] = tolower(c[i]);
		}
	}
	int err=c.find(" ");
	if(err != std::string::npos) c = c.substr(0, err);
	string T = this->type;
	if (T==c) return 10000;
	else return 0;
}
int File::Rank_Case7(string key_search ) 
{
	int R = 0;
	string c = key_search;
	if (c.find(" $") > 0)
	{
		string c1 = c.substr(0, c.find(" $"));
		string c2 = c.substr(c.find(" $")+2, c.size()- c.find(" $")-2);
		if (c2.size() != 0)
		{
			for (int i = 0; i < c2.size(); i++)
			{
				if (isalpha(c2[i])) c2[i] = tolower(c2[i]);
			}
		}
		int err = c2.find(" ");
		if (err != std::string::npos) c2 = c2.substr(0, err);
		//
		Node* cur = FileWord.search("$");
		if (cur != NULL)
		{
			for (int i = 0; i < cur->N_times; i++)
			{
				int pos = cur->position[i] + 1;
				if (Token[pos] == c2)
				{

					
					for (int ii = cur->position[i] - 10; ii < cur->position[i] + 10; ii++)
					{
						if (ii < 0 || ii>Token.size() - 1) continue;
						if (Token[ii] == c1)
						{
							R += 10000;
							for (int iii = cur->position[ii] - 10; iii < cur->position[ii] + 10 && i<7; iii++)
							{
								if (iii < 0 || iii>Token.size() - 1) continue;
								this->Content_Searched += Token[iii];
								this->Content_Searched += " ";
							}
							if (i<7)this->Content_Searched += "...";
						}
					}
				}
			}
		}
	}
	/*
	if (c[0] == '$')
	{
		c = c.erase(0, 1);
		if (c.size() != 0)
		{
			for (int i = 0; i < c.size(); i++)
			{
				if (isalpha(c[i])) c[i] = tolower(c[i]);
			}
		}
		int err = c.find(" ");
		if (err != std::string::npos) c = c.substr(0, err);
		//
		Node* cur = FileWord.search("$");
		if (cur != NULL)
		{
			for (int i = 0; i < cur->N_times; i++)
			{
				int pos = cur->position[i] + 1;
				if (Token[pos] == c)
				{
					for (int ii = cur->position[i] - 2; ii < cur->position[i] + 5 && i<7; ii++)
					{
						if (ii < 0 || ii>Token.size() - 1) continue;
						this->Content_Searched += Token[ii];
						this->Content_Searched += " ";
					}
					if (i<7)this->Content_Searched += "...";
					R += 10000;
				}
			}
		}
	}*/
	return R;
}
int File::Rank_Case8(string key_search ) 
{
	int R = 0;
	string c = key_search;
	if (c[0] == '#')
	{
		c = c.erase(0, 1);
		if (c.size() != 0)
		{
			for (int i = 0; i < c.size(); i++)
			{
				if (isalpha(c[i])) c[i] = tolower(c[i]);
			}
		}
		int err = c.find(" ");
		if (err != std::string::npos) c = c.substr(0, err);
		//
		Node* cur = FileWord.search("#");
		if (cur != NULL)
		{
			for (int i = 0; i < cur->N_times; i++)
			{
				int pos = cur->position[i]+1;
				if (Token[pos] == c) R += 10000;
			}
		}
	}
	return R;
}
int File::Rank_Case10(string key_search)
{
	string key = key_search;
	int k = key_search.find(" * ");
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i] <= -1 || key[i] >= 255) key[i] = ' ';
		if (isalpha(key[i])) key[i] = tolower(key[i]);
	}
	string s1 = key.substr(0, k);
	string s2 = key.substr(k + 3, key.size());
	//
	int R = 0;
	vector <string> Tok_key1,Tok_key2;
	string_to_token(s1, Tok_key1);
	string_to_token(s2, Tok_key2);
	if (Tok_key1.size() != 0) {
		Node* cur = FileWord.search(Tok_key1[0]);
		if (cur != NULL)
		{
			for (int i = 0; i < cur->N_times; i++)
			{
				int tm = 0;
				int j;
				for (j = 0; j < Tok_key1.size(); j++)
				{
					if (Tok_key1[j] == Token[cur->position[i] + j]) tm++;
				}
				if (tm == Tok_key1.size())
				{
					tm = 0;
					int k = cur->position[i] + j+1;
					for (int m = 0; m < Tok_key2.size(); m++)
					{
						if (Tok_key2[m] == Token[k + m]) tm++;
					}
					if (tm == Tok_key2.size()) R += 10000;
				}
			}
		}
	}
	return R;
}
int File::Rank_Case9(string key_search ) 
{

	long int R = 0;
	vector <string> Tok_key;
	string_to_token(key_search, Tok_key);
	if (Tok_key.size() != 0) {
		Node* cur = FileWord.search(Tok_key[0]);
		if (cur != NULL)
		{
			for (int i = 0; i < cur->N_times; i++)
			{
				int tm = 0;
				for (int j = 0; j < Tok_key.size(); j++)
				{
					if (cur->position[i] + j >= Token.size()) break;
					if (Tok_key[j] == Token[cur->position[i] + j]) tm++;
				}
				if (tm == Tok_key.size())
				{
					for (int ii = cur->position[i] - 3; ii < cur->position[i] + 5 && i<7; ii++)
					{
						if (ii < 0 || ii>Token.size()-1) continue;
						this->Content_Searched += Token[ii];
						this->Content_Searched += " ";
					}
					if(i<7)this->Content_Searched += "...";
					R += 10000;
				}
			}
		}
	}
	return R;
}
int File::Rank_Case11(string key_search ) 
{
	int R=0;
	//
	if (key_search.find(" $") > 0)
	{
		string Noun=key_search.substr(0, key_search.find(" $"));
		string key = key_search.substr(key_search.find(" $") + 2, key_search.size() - key_search.find(" $") - 2);
		int k = key.find("..");
		for (int i = 0; i < key.size(); i++)
			if (isalpha(key[i])) key[i] = tolower(key[i]);
		string s1 = key.substr(0, k);
		string s2 = key.substr(k + 2, key.size() - k - 2);
		//
		vector <string> tok1;
		vector <string> tok2;
		string_to_token(s1, tok1);
		string_to_token(s2, tok2);
		int a1 = -1, a2 = -1;
		for (int i = 0; i < tok1.size(); i++)
		{
			if (check_string_digit(tok1[i])) a1 = stoi(tok1[i]);
		}
		for (int i = 0; i < tok2.size(); i++)
		{
			if (check_string_digit(tok2[i])) a2 = stoi(tok2[i]);
		}
		if (a1 > a2) swap(a1, a2);
		//
		Node* cur = FileWord.search("$");
		if (cur != NULL)
		{
			for (int i = 0; i < cur->N_times; i++)
			{
				int pos = cur->position[i] + 1;
				if (check_string_digit(Token[pos])) if (stoi(Token[pos]) > a1 && stoi(Token[pos]) < a2)
				{
					for (int ii = cur->position[i] - 10; ii < cur->position[i] + 10; ii++)
					{
						if (ii < 0 || ii>Token.size() - 1) continue;
						if (Token[ii] == Noun)
						{
							R += 10000;
							for (int iii = cur->position[ii] - 10; iii < cur->position[ii] + 10 && i<7; iii++)
							{
								if (iii < 0 || iii>Token.size() - 1) continue;
								this->Content_Searched += Token[iii];
								this->Content_Searched += " ";
							}
							if (i<7)this->Content_Searched += "...";
						}
					}
				}
			}
		}
		//
	}
	return R;
}
int File::Rank_Case12(string key_search ,NodeList *SynArr[462], Synonymous& SynTree)
{
	string key = key_search;
	int k = key_search.find("~");
	for (int i = 0; i < key.size(); i++)
		if (isalpha(key[i])) key[i] = tolower(key[i]);
	string s = standard_alpha(key);
	int x = SynTree.Search(s);
	int R = 0;
	if (x != -1)
	{
		NodeList*cur = SynArr[x];
		while (cur != NULL)
		{
			R+=Rank_Case9(cur->data);
			cur = cur->synnext;
		}
	}
	return R;
}
int File::Rank_Case13(string key_search ) 
{
	long int R = 0;
	vector <string> key_tok;
	string_to_token(key_search,key_tok);
	R += Rank_Case9(key_search)/1000;
	if (R == 0)
	{
		for (int i = 0; i < key_tok.size(); i++)
		{

			R += (Rank_Case9(key_tok[i]) / 5000);
		}
	}
	return R;
}

//File
void File::Rank(string key_search,bool &yes,NodeList *SynArr[462], Synonymous& SynTree)
{																															//!

	if (this->Titile != "") this->rank++;
	if (this->Content != "") this->rank++;

	if (key_search.find("AND") != std::string::npos || key_search.find("and") != std::string::npos)                            //case 1 "AND"
	{
		rank += Rank_Case1(key_search);
	}
	if (key_search.find("OR") != std::string::npos|| key_search.find("or") != std::string::npos)                        //case 2 "OR"
	{
		rank += Rank_Case2(key_search);
	}
	if (key_search.find("-") != std::string::npos)                         //case 3 co A ma khong co B : difference
	{
		rank += Rank_Case3(key_search);
	}
	if (key_search.find("intitle:") != std::string::npos)                  //case 4 search titile
	{
		this->rank += Rank_Case4(key_search);
	}
	if (key_search.find("+") != std::string::npos)                
	{
		this->rank += Rank_Case5(key_search);
	}																			//case 5 Peanut Butter +and Jam
	if (key_search.find("filetype:") != std::string::npos)                 
	{
		this->rank += Rank_Case6(key_search);
	}																			//case 6 filetype
	if (key_search.find("$") != std::string::npos)                         //case 7 price
	{
		if (key_search.find("..") != std::string::npos)                        //case 11 range of numbers
		{
			this->rank += Rank_Case11(key_search);
		}
		else this->rank += Rank_Case7(key_search);
	}
	if (key_search.find("#") != std::string::npos)                         //case 8 hagtage
	{
		this->rank += Rank_Case8(key_search);
	}
	if (key_search.find("\"") != std::string::npos)                        //case 9 exact match
	{
		this->rank += Rank_Case9(key_search);
	}
	if (key_search.find("*") != std::string::npos)                         //case 10 unknown words
	{
		this->rank += Rank_Case10(key_search);
	}
	if (key_search.find("~") != std::string::npos)                         //case 12 synonyms
	{
		this->rank += Rank_Case12(key_search, SynArr, SynTree);
	}
	if (rank > 10) yes = 1;
	if(yes==0)
	{
		this->rank += Rank_Case13(key_search);
	}																	//case 13 Normal case
}
void File::RemoveAll(Node *& node) {

	if (node != NULL) {

		for (int i = 0; i < ALPHABERT_NUM; i++) {
			RemoveAll(node->Children[i]);
			if (node->Children[i] != NULL)
			{
				delete node->Children[i];
				node->Children[i] = NULL;
			}
		}
	}
}
void File::Input(string X,string folder)
{
	this->Address = X;
	this->Address = folder+"/" + this->Address;
	//this->Address.insert(this->Address.size() - 3, ".");
	int ty = this->Address.find(".");
	if (ty > -1) this->type = this->Address.substr(ty + 1, X.size() - 1-ty);
	ifstream file(this->Address.c_str());
	getline(file, this->Titile);

	stringstream buffer;
	buffer << file.rdbuf();
	this->Content = buffer.str();

	this->Content_Searched = this->Content.substr(0, 20);
	string_to_token(this->Content, this->Token);
	file.close();
}
void File::Print()
{
	textcolor(4);
	cout << this->Titile << endl;
	textcolor(9);
	cout << this->Content << endl;
	textcolor(7);
	cout << "                                                                                  ->Enter to Back";
	//for (int i = 0; i < this->Token.size(); i++) cout << this->Token[i] << '\n';
}
void File::Print_Search(string key)
{
	textcolor(10);
	cout << this->Titile << endl;
	textcolor(13);
	cout << "  " << this->Address << endl;
	textcolor(6);
	cout << "  " << this->rank << endl;
	textcolor(2);
	string con = this->Content_Searched;
	
	bool check = 0;
	vector <string> tok_search;
	string_to_token(key, tok_search);
	vector <int> pos_paint;
	vector <int> len_paint;
	for (int i = 0; i < tok_search.size(); i++)
	{
		int found = Content_Searched.find(tok_search[i]);
		while (found != std::string::npos)
		{
			check=1;
			pos_paint.push_back(found);
			len_paint.push_back(tok_search[i].size());
			found = Content_Searched.find(tok_search[i], found + tok_search[i].size());
		}
	}
	if (pos_paint.size()>1)
	for (int i = 0; i < pos_paint.size() - 1; i++)
	{
		for (int j = i+1; j < pos_paint.size(); j++)
		{
			if (pos_paint[i] > pos_paint[j])
			{
				swap(len_paint[i], len_paint[j]);
				swap(pos_paint[i], pos_paint[j]);
			}
		}
	}
	textcolor(9);
	if (check != 0)
	{
		int format = 0;
		string p = Content_Searched.substr(0, pos_paint[0]);
		for (int i = 0; i < pos_paint.size()&& format<7; i++)
		{
			format++;
			cout << p;
			p = Content_Searched.substr(pos_paint[i], len_paint[i]);
			textcolor(6);
			cout << p;
			if (i + 1 == pos_paint.size())
				p = Content_Searched.substr(pos_paint[i] + len_paint[i], Content_Searched.size() - pos_paint[i] - len_paint[i]);
			else
				p = Content_Searched.substr(pos_paint[i] + len_paint[i], pos_paint[i + 1] - pos_paint[i] - len_paint[i]);
			textcolor(9);
		}
		cout << p << endl<<endl;
	}
	else 
		cout <<con.substr(0,250) <<"..."<< endl<<endl;
}


//Trie
Node* Trie::search(string key)
{
	Node *cur = pHead;
	if (cur == NULL) return NULL;
	int i;
	for (i = 0; i < key.length(); i++)
	{
		if (key[i] == '#')
		{
			int index = 36;
			if (!cur->Children[index])
				return NULL;
			cur = cur->Children[index];
		}
		if (key[i] == '$')
		{
			int index = 37;
			if (!cur->Children[index])
				return NULL;
			cur = cur->Children[index];
		}
		if (isalpha(key[i]))
		{
			int index = toupper(key[i]) - 'A';
			if (!cur->Children[index])
				return NULL;
			cur = cur->Children[index];
		}
		if (isdigit(key[i]))
		{
			int t = key[i] - '0' + 26;
			if (!cur->Children[t])
				return NULL;
			cur = cur->Children[t];
		}
	}
	if (i == key.size() && cur->N_times != 0)
		return cur;
	return NULL;
}
void Trie::Insert_Token(string s, int i) {
	if (pHead == NULL) {
		pHead = new Node;
		for (int i = 0; i < ALPHABERT_NUM; ++i) pHead->Children[i] = NULL;
	}

	string String = s;
	Node *cur = pHead;
	for (int j = 0; j < String.size(); ++j) {
		if (String[j] == '#')
		{
			int t = 36;
			if (cur->Children[t] == NULL) {
				cur->Children[t] = new Node;
				for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[t]->Children[k] = NULL;
			}
			cur = cur->Children[t];
		}
		if (String[j] == '$')
		{
			int t = 37;
			if (cur->Children[t] == NULL) {
				cur->Children[t] = new Node;
				for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[t]->Children[k] = NULL;
			}
			cur = cur->Children[t];
		}
		if (isalpha(String[j]))
		{
			if (cur->Children[toupper(String[j]) - 'A'] == NULL) {
				cur->Children[toupper(String[j]) - 'A'] = new Node;
				for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[toupper(String[j]) - 'A']->Children[k] = NULL;
			}
			cur = cur->Children[toupper(String[j]) - 'A'];
		}
		if (isdigit(String[j]))
		{
			int t = String[j] - '0' + 26;
			if (cur->Children[t] == NULL) {
				cur->Children[t] = new Node;
				for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[t]->Children[k] = NULL;
			}
			cur = cur->Children[t];
		}

		if (j == String.size() - 1) cur->N_times++;
		if (j == String.size() - 1) cur->position[cur->N_times++] = i;
	}
}
void Trie::Insert_Vector(vector <string> &Token, Trie SW) {

	for (int i = 0; i < Token.size(); ++i) {
		if (SW.search(Token[i]) != NULL) continue;
		if (pHead == NULL) {
			pHead = new Node;
			for (int i = 0; i < ALPHABERT_NUM; ++i) pHead->Children[i] = NULL;
		}

		string String = Token[i];
		Node *cur = pHead;
		for (int j = 0; j < String.size(); ++j) {
			if (String[j] == '#')
			{
				int t = 36;
				if (cur->Children[t] == NULL) {
					cur->Children[t] = new Node;
					for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[t]->Children[k] = NULL;
				}
				cur = cur->Children[t];
			}
			if (String[j] == '$')
			{
				int t = 37;
				if (cur->Children[t] == NULL) {
					cur->Children[t] = new Node;
					for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[t]->Children[k] = NULL;
				}
				cur = cur->Children[t];
			}
			if (isalpha(String[j]))
			{
				if (cur->Children[toupper(String[j]) - 'A'] == NULL) 
				{
					cur->Children[toupper(String[j]) - 'A'] = new Node;
					for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[toupper(String[j]) - 'A']->Children[k] = NULL;
				}
				cur = cur->Children[toupper(String[j]) - 'A'];
			}
			if (isdigit(String[j]))
			{
				int t = String[j] - '0' + 26;
				if (cur->Children[t] == NULL) {
					cur->Children[t] = new Node;
					for (int k = 0; k < ALPHABERT_NUM; ++k) cur->Children[t]->Children[k] = NULL;
				}
				cur = cur->Children[t];
			}

			if (j == String.size() - 1) cur->position[cur->N_times++] = i;
		}
	}
}
//Globle Function
void Read_Filename(vector <string> & Data)
{
	static const char* chFolderpath = "data\\*";
	string data;
	HANDLE hFind;
	WIN32_FIND_DATAA data2;
	hFind = FindFirstFileA(chFolderpath, &data2);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (data2.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
				data += "<DIR>";
			//data += data2.cFileName;
			//data += ' ';
			if (data2.cFileName[0] != '.') Data.push_back(data2.cFileName);
				//cout << data2.cFileName[0];
		} while (FindNextFileA(hFind, &data2));
		FindClose(hFind);
	}
	//int t;
	//cin >> t;
}
void Build_Trie_Stopword(Trie & Stopword) {
	string address = "stopword.txt";
	string content;
	vector <string> Token;
	ifstream file(address.c_str());
	stringstream buffer;
	buffer << file.rdbuf();
	content = buffer.str();
	string_to_token(content, Token);
	file.close();
	//
	for (int i = 0; i < Token.size(); ++i) {
		Stopword.Insert_Token(Token[i], i);
	}
}
void Input_Key(string & search_key, vector <string> & His)
{
	char e;
	int j = 0;
	e = _getch();
	int whereTro = 21;
	while (int(e) != 13)
	{

		if (e == 8)
		{
			if (search_key.length()>0) search_key.erase(search_key.length() - 1, 1);
			whereTro = 21;
		}
		else if (e == 32)
		{
			search_key += e;
			whereTro = 21;
		}
		else if (e == KEY_DOWN)
		{
			if (whereTro <= 21 + j)
			{
				if (whereTro != 21) {
					gotoxy(68, whereTro);
					cout << "  ";
					whereTro++;
				}
				else whereTro += 2;
				gotoxy(68, whereTro);
				cout << ">>";
			}
		}
		else if (e == KEY_UP)
		{
			if (whereTro > 21)
			{
				gotoxy(68, whereTro);
				cout << "  ";
				if (whereTro != 23) whereTro--;
				else whereTro -= 2;
				if (whereTro != 21)
				{

					gotoxy(68, whereTro);
					cout << ">>";
				}
			}
		}
		else if (e<256 && e>0)
		{
			//e = tolower(e);
			stringstream ss;
			string s;
			ss << e;
			ss >> s;
			search_key += s;
			whereTro = 21;
		}
		else {
			e = _getch(); continue;
		}
		gotoxy(71, 21);
		cout << search_key << "                    " << endl;
		for (int k = 0; k < 6; k++) {
			gotoxy(71, 23 + k);
			cout << "                                                       ";
		}
		j = 0;
		for (int i = 0; i < His.size(); i++)
		{
			if (j > 5) break;
			if (His[i].find(search_key) == 0)
			{
				gotoxy(71, 23 + j);
				cout << His[i] << endl;
				j++;
			}
		}
		e = _getch();
	}
	if (whereTro != 21)
	{
		int iii;
		int jj = 0;
		for (iii = 0; iii < His.size(); iii++)
		{
			if (His[iii].find(search_key) == 0)
			{
				jj++;
			}
			if (jj == whereTro - 22) break;
		}
		search_key = His[iii];
	}
	else His.push_back(search_key);
	system("CLS");
}
void Index_Screen()
{
	int color = 0;
	textcolor(color);
	//gotoxy(0, 0);
	for (int x = 0; x < 150; x++)
	{
		for (int y = 0; y < 100; y++)
			cout << " "; 
	}
	textcolor(color + 10);
	gotoxy(72, 9);
	cout << "  ___                       _      " << endl; gotoxy(72, 10);
	cout << " / _ \\                     | |     " << endl; gotoxy(72, 11);
	cout << "/ /_\\ \\_ __   ___ ___  __ _| | ___ " << endl; gotoxy(72, 12);
	cout << "|  _  | '_ \\ / __/ __|/ _` | |/ _ \\" << endl; gotoxy(72, 13);
	cout << "| | | | |_) | (__\\__ \\ (_| | |  __/" << endl; gotoxy(72, 14);
	cout << "\\_| |_/ .__/ \\___|___/\\__, |_|\\___|" << endl; gotoxy(72, 15);
	cout << "      | |              __/ |       " << endl; gotoxy(72, 16);
	cout << "      |_|             |___/        " << endl;

	int k = 20;
	int h = 140;
	gotoxy(h, k - 2);
	textcolor(color + 6);
	cout << "    Group 19:";
	gotoxy(h, k);
	textcolor(color + 3);
	cout << "Nguyen Minh Tri"; gotoxy(h, k + 1);
	cout << "Nguyen Ngoc Phong"; gotoxy(h, k + 2);
	cout << "Quynh Duc Huy"; gotoxy(h, k + 3);
	cout << "Do Tri Nhan"; gotoxy(h, k + 4);
	gotoxy(150, 2);
	cout << "*Gmail    *Image    *Sign in";
	window(70, 20);
}
void Search_Result(File *&F, string search_key, int size)
{
	int Top[5] = {-1,-1,-1,-1,-1};
	int *Top5;
	int *ArrRank;
	Top5 = new int[size];
	ArrRank = new int[size];
	for (int i = 0; i < size; i++)
	{
		ArrRank[i] = F[i].rank;
		Top5[i] = ArrRank[i];
	}
	sort(Top5, Top5 + size, greater<int>());
	for (int pp = 0; pp < size; pp++)
	{
		if (ArrRank[pp] == Top5[0])
		{
			Top[0] = pp;
			ArrRank[pp] = -1;
			break;
		}
	}
	for (int pp = 0; pp < size; pp++)
	{
		if (ArrRank[pp] == Top5[1])
		{
			Top[1] = pp;
			ArrRank[pp] = -1;
			break;
		}
	}
	for (int pp = 0; pp < size; pp++)
	{
		if (ArrRank[pp] == Top5[2])
		{
			Top[2] = pp;
			ArrRank[pp] = -1;
			break;
		}
	}
	for (int pp = 0; pp < size; pp++)
	{
		if (ArrRank[pp] == Top5[3])
		{
			Top[3] = pp;
			ArrRank[pp] = -1;
			break;
		}
	}
	for (int pp = 0; pp < size; pp++)
	{
		if (ArrRank[pp] == Top5[4])
		{
			Top[4] = pp;
			ArrRank[pp] = -1;
			break;
		}
	}
	int Y[5];
	//Run top 5 file 
	textcolor(10);
	cout << "   _____                     _       _____                 _ _   " << endl;
	cout << "  / ____|                   | |     |  __ \\               | | |  " << endl;
	cout << " | (___   ___  __ _ _ __ ___| |__   | |__) |___  ___ _   _| | |_ " << endl;
	cout << "  \\___ \\ / _ \\/ _` | '__/ __| '_ \\  |  _  // _ \\/ __| | | | | __|                                    =>Use arrow to move" << endl;
	cout << "  ____) |  __/ (_| | | | (__| | | | | | \\ \\  __/\\__ \ |_| | | |_ " << endl;
	cout << " |_____/ \\___|\\__,_|_|  \\___|_| |_| |_|  \\_\\___||___/\\__,_|_|\\__|" << endl;
	cout << "                                                                " << endl;
	cout << "" << endl;
	cout << "" << endl;

	window(8, 7);
	gotoxy(9, 8);
	cout << search_key;
	gotoxy(6, 10);
	cout << endl;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		Y[i] = wherey() + 1;
		F[Top[i]].Print_Search(search_key);
	}
	char t;
	t = _getch();
	int yy = 0;
	int enter = 0;
	while (int(t) != 13)
	{
		int yyy = yy;
		gotoxy(0, Y[yy]);
		textcolor(69);
		cout << ">>";
		if (t == KEY_UP)
		{
			if (yy == 0) yy = 4;
			else yy = yy - 1;
		}
		if (t == KEY_DOWN)
		{
			if (yy == 4) yy = 0;
			else yy = yy + 1;
		}
		t = _getch();
		gotoxy(0, Y[yyy]);
		textcolor(1);
		cout << "  ";
		enter = yyy;
	}
	system("CLS");
	F[Top[enter]].Print();
	t = _getch();
	while (int(t) != 13)
	{
		t = _getch();
	}
	system("CLS");
	delete[] Top5;
	delete[] ArrRank;
}
//Synonymous
void Synonymous::Insert(string Token, int index) {
	Insert1(Token, pHead, index);
}
AVLNode* Synonymous::Insert1(string Token, AVLNode *& p, int index) {

	if (p == NULL)
	{
		p = new AVLNode;
		p->Token = Token;
		p->index = index;
		p->left = NULL;
		p->right = NULL;
		//p->height = 0;
	}
	else
	{
		if (p->Token > Token) {

			Insert1(Token, p->left, index);
			if ((height(p->left) - height(p->right)) == 2)
			{
				if (Token < p->left->Token)
					p = singleRightRotate(p);
				else
					p = doubleRightRotate(p);
			}
		}
		else if (Token > p->Token)
		{
			Insert1(Token, p->right, index);
			if ((height(p->right) - height(p->left)) >= 2)
			{
				if (Token > p->right->Token)
					p = singleLeftRotate(p);
				else
					p = doubleLeftRotate(p);
			}
		}
	}
	int m, n, d;
	m = height(p->left);
	n = height(p->right);
	d = max(m, n);
	p->height = d + 1;

	return NULL;
}
int Synonymous::Search(string Token) {

	AVLNode *Node = pHead;
	while (Node != NULL)
	{
		if (Node->Token == Token) return Node->index;
		if (Token < Node->Token) Node = Node->left;
		else if (Token > Node->Token) Node = Node->right;
	}
	return -1;
}
int Input_syn_to_hash(NodeList* SynArr[])
{
	string line;
	ifstream fin;

	fin.open("syn.txt");
	int i = 0;
	while (!fin.eof())
	{
		vector <string> Token;
		getline(fin, line);
		string_to_token(line, Token);
		for (int j = 0; j < Token.size(); j++)
		{
			//SynArr[i].Insert(Token[j]);
			if (SynArr[i] == NULL)
			{
				SynArr[i] = new NodeList;
				SynArr[i]->data = Token[j];
				SynArr[i]->synnext = NULL;
			}
			else
			{
				NodeList* cur = SynArr[i];
				while (cur->synnext != NULL) cur = cur->synnext;
				cur->synnext = new NodeList;
				cur = cur->synnext;
				cur->data = Token[j];
				cur->synnext = NULL;
			}
		}
		i++;
	}
	fin.close();
	return i;
}
void Input_Sym(NodeList *SynArr[462], Synonymous &SynTree)
{
	for (int i = 0; i<462; i++) SynArr[i] = NULL;
	int n = Input_syn_to_hash(SynArr);
	SynTree.Build(SynArr, n);
}
