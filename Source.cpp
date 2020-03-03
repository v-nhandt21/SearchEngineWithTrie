#include "Header.h"

int main()
{
	//Index Process
	
	File *F; Trie SW;
	vector <string> Data;
	Read_Filename(Data);
	F = new File[Data.size()+File_scale];
	int size = Data.size();
	vector <string> His;
	Build_Trie_Stopword(SW);
	NodeList *SynArr[462];
	Synonymous SynTree;
	Input_Sym(SynArr,SynTree);
	for (int i = 0; i <Data.size(); i++)
	{
		string X = Data[i];
		F[i].Input(X,"Data");
		//F[i].prToken();
		//int k; cin >> k;
		F[i].BuildTrie(SW);
	}

	//Retrieval Process

	resizeConsole(1500, 700);
	while (true)
	{
		Index_Screen();
		string search_key="";
		Input_Key(search_key, His);
		if (search_key == "eytt" || search_key == "eytl")
		{
			int old_size = size;
			string data_add;
			for (int x = 0; x < 150; x++)
			{
				for (int y = 0; y < 100; y++)
					cout << " ";
			}
			gotoxy(0, 0);
			cout << "Input address of new data: " << endl;
			cin >> data_add; if (data_add == "x") continue;
			string fol = data_add;
			data_add += "\\\*";
			static const char* chFolderpath = data_add.c_str();
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
					if (data2.cFileName[0] != '.') 
						Data.push_back(data2.cFileName);
					//cout << data2.cFileName[0];
				} while (FindNextFileA(hFind, &data2));
				FindClose(hFind);
			}
			size = Data.size();
			if (size != old_size)
			{
				for (int i = old_size; i < Data.size(); i++)
				{
					string X = Data[i];
					F[i].Input(X,fol);
					//F[i].prToken();
					//int k; cin >> k;
					F[i].BuildTrie(SW);
					cout << "Input success file : " << Data[i]<<endl;
				}
			}
			else cout << "There is no file " << data_add << endl;
			_getch();
			continue;
		}
		if (search_key == "exit") break;
		auto start = high_resolution_clock::now();
		bool yes = 0;
		for (int i = 0; i <size; i++)
		{
			F[i].Rank(search_key,yes, SynArr,SynTree);																			//!
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Time taken by function: "
			<< duration.count() << " microseconds" << endl;
		_getch();
		Search_Result(F, search_key,size);
		for (int i = 0; i <size; i++)
		{
			F[i].Reset();																			//!
		}
	}
	return 0;
}