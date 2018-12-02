#include <iostream>
#include <string>
#include <vector>

using namespace std;

void f(vector<string>& v, string str)
{
	v.push_back(str); //add string to vector
	str.erase(0, 1); // erase the sign number from string
}

void reset(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = 0;
	}
}

int main()
{
	vector<string> file;
	string temp;
	string line; //current line from input
	int ch_position;

	//read input
	while (getline(cin, line))
	{
		
		if (line.empty()) //check if current string is empty
			break;
		f(file, line);
	}
	for (int i = 0; i < file.size(); i++)
	{
		for (int j = i; j < file.size(); j++)
		{
			int count = 0;
			for (int k = 0; k < file[i].size(); k++)
			{
				if (file[i][k] != file[j][k]) //search different characters from k position in both strings
				{
					count++;
					ch_position = k; //retain position for different characters
				}
			}
			if (count == 1) //check for only one difference between i-th and j-th string
			{
				//delete that character and print the remaining string
				string aux = file[i];
				aux.erase(ch_position, 1);
				cout << aux;
			}
		}
	}
	return 0;
}