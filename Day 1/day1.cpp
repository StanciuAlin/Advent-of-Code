#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

int checkTwiceFreq(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 2)
		{
			return i;
		}
	}
	return -1;
}

void f(vector<string>& v, string str)
{
	v.push_back(str); //add string to vector
	str.erase(0, 1); // erase the sign number from string
}

int main()
{
	vector<string> temp;
	string line; //current line from input
	char sign; //retain sign of every string(number)
	int result; //integer number from input string
	long int sum = 0; //result of puzzle
	//read input
	getline(cin, line);
	f(temp, line);

	while (getline(cin, line))
	{
		
		if (line.empty()) //check if current string is empty
			break;
		f(temp, line);

	}

	vector<int> freqp(1000000, 0); //frequencies for positive number
	vector<int> freqn(1000000, 0); //frequencies for negative number
	//initially, 0 appear for positive and negative frequencies
	freqp[0] = 1; 
	freqn[0] = 1;
	vector<string> helper(temp); //vector for help to iterate second or third or more time if the solution has been found yet

	int res1 = checkTwiceFreq(freqp);
	int res2 = checkTwiceFreq(freqn);
	sum = 0;
	while (res1 == -1 && res2 == -1)
	{
		for (int i = 0; i < temp.size(); i++)
		{
			sign = temp.at(i)[0]; // retain '+' or '-'
			temp[i].erase(0, 1); // erase the sign number from string
			result = stoi(temp[i]); //convert string to integer

			(sign == '-') ? sum -= result : sum += result;
			//check for first appearance of frequency
			if (sum <= 0)
			{
				freqn[-sum]++;
				if (freqn[-sum] == 2)
				{
					cout << "Frequency: " << -sum;
					Sleep(10000);
					return 0;
				}
			}
			else
			{
				freqp[sum]++;
				if (freqp[sum] == 2)
				{
					cout << "Frequency: " << sum;
					Sleep(10000);
					return 0;
				}
			}
	
		}
		temp = helper;
	}
	return 0;
}