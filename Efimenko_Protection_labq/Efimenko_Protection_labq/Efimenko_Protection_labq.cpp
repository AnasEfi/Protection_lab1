#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <windows.h>
#include <vector>
using namespace std;

class Efimenko_vigener
{
private:
	string key;
	int mod;
public:
	Efimenko_vigener(string key_input, int size_N = 255)
	{
		key = key_input;
		mod = size_N;
	}

	string encrypt(string word)
	{
		string output = "";
		int j = 0;

		for (int i = 0;i < word.size();i++)
		{
			if (j >= key.size())
				j = 0;

			unsigned char ch = word[i] + key[j];
			//ch = ch % mod;
			output += ch;
			j++;
		}
		return output;
	}

	string decrypt(string data)
	{
		string output;
		int j = 0;
		for (int i = 0;i < data.size();i++)
		{
			if (j >= key.size())
				j = 0;

			unsigned char ch = data[i] - key[j];
			ch = (ch + mod) % mod;
			output += ch;
			j++;
		}
		return output;

	}
};

int main()

{
	string filename, string, word, key, count;
	cout << "Enter name of file: ";
	cin >> filename;
	ifstream inf(filename, ios::in);
	while (!inf.eof())
	{
		getline(inf, count);
		word += count+'\n';
	}
	inf.close();

	cout << "Enter key: ";
	cin >> key;
	Efimenko_vigener chiefr(key, 255);
	ofstream fout;
	fout.open("data2.txt", ios::out);
	fout << chiefr.encrypt(word);
	fout.close();
	fout.open("data3.txt", ios::out);
	fout << chiefr.decrypt(chiefr.encrypt(word));
	fout.close();
}
