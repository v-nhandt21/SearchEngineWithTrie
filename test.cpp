#include "Header.h"
string standard_alpha(string s)
{
	string tmp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] <= -1 || s[i] >= 255) s[i] = 'o';
		if (isalpha(s[i]) || isdigit(s[i]))
		{
			if (isalpha(s[i])) s[i] = tolower(s[i]);
			tmp = tmp + s[i];
		}
	}
	return tmp;
}
void chuan(vector <string>&Token, string tok)
{
	if (tok.find("\n") != std::string::npos)
	{
		if (tok.find("\n") == 0)
		{
			tok = tok.erase(0, 1);
			chuan(Token, tok);
		}
		else
		{
			int z = tok.find("\n");
			if (int(tok[z - 1]) <= -1 || int(tok[z - 1]) >= 255) tok[z - 1] = 'o';
			if (isalpha(int(tok[z - 1])) == 0)
			{
				Token.push_back(standard_alpha((tok.substr(0, z - 1))));
			}
			else Token.push_back(standard_alpha(tok.substr(0, z)));
			//Token.push_back("\n");
			string end = tok.substr(z + 1, tok.size()-1-z);
			while (end[0] == ' ')
			{
				end = end.erase(0, 1);
			}
			chuan(Token, end);
		}
	}
	else
	{
		if ((tok[0] == '#' || tok[0] == '$') && tok.size() > 1)
		{
			stringstream ss;
			string target;
			ss << tok[0];
			ss >> target;
			Token.push_back(target);
			tok = tok.substr(1, tok.size() - 1);
		}
		if (standard_alpha(tok) != "")
			Token.push_back(standard_alpha(tok));
	}
}
void CreatTXT()
{
	ofstream creat;
	for (int i = 1; i <= 100; i++)
	{
		string Ex = ".txt";
		string Name = Int_to_String(i);
		Name = Name + Ex;
		creat.open(Name);
		creat.close();
	}
}
string Int_to_String(int &x)
{
	ostringstream oss;
	oss << x;
	return oss.str();

}
void string_to_token(string content, vector <string>&Token)
{

	string tok;
	stringstream buf;
	buf << content;
	while (getline(buf, tok, ' '))
	{
		chuan(Token, tok);
	}
}
void ColorChoose()
{
	for (int i = 0; i <= 300; i++)
	{
		textcolor(i);
		cout << i << "           Nhan" << endl;
	}
}
bool check_string_digit(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) == 0) return 0;
	}
	return 1;
}

