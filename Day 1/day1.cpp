#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string line; //current line from input
	char sign; //retain sign of every string(number)
	int result; //integer number from input string
	long int sum = 0; //result of puzzle
	 
	while (getline(cin, line))
	{
		if (line.empty()) //check if current string is empty
			break;
		sign = line[0]; // retain '+' or '-'
		line.erase(0, 1); // erase the sign number from string
		result = stoi(line); //convert string to integer

		if (sign == '-') //verify if the number has '-' sign
		{
			sum -= result;
		}
		else
		{
			sum += result;
		}

	}
	cout << "\nSuma de valori este: " << sum; //print solution for puzzle
	return 0;
}