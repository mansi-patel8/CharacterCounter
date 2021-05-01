/*
* Name: Mansi Patel
* Purpose: The purpose of this program is return the character count in an array.
* Pseducode/ Program outline logic:
			- first we are going to create an array with random letters with mixture of uppercase and lowercase characters.
			- then printing the random array created
			- after that, we will convert all the lowercase letters to uppercase letters for counting purposes
			- then the while loop will do the calculation
			- at the end we are showing the total number of characters in the array with how many times each of the letter is repeated in the array
*/

#include <iostream>
#include <ctime>

using namespace std;

const int N = 120;

//generating random characters
char generate_random_char()
{
	//generating random numbers between 0 to 25
	int i = 26.0 * rand() / RAND_MAX;

	//for 50% chance character 
	if (static_cast<double>(rand()) / RAND_MAX < 0.5) {
		return static_cast<char>(65 + i); //65 to 90 (A-Z)
	}

	return static_cast<char>(97 + i);  //97 to 122 (a-z)
}

int main()
{
	srand(time(0));

	// Set up an array of characters
	char arr[N];
	for (int i = 0; i < N; ++i)
	{
		arr[i] = generate_random_char();  //creating array of random chars (A-Z to a-z)
	}

	// Printing the contents of the input array
	cout << "Input array:" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << arr[i];
	}
	cout << endl;

	//for loop to covert lowercase character to uppercase
	for (int i = 0; i < N; i++)
	{
		if (arr[i] >= 97 && arr[i] <= 122)
		{
			arr[i] = toupper(arr[i]);
		}
		//cout << arr[i];         //array in uppercase characters
	}
	//cout << endl;

	int m = 0, n;
	int uppercase_array[26] = { 0 };  //initailizing arrays of of 25 ints with 0

	//creating the array for uppercase chars 
	while (arr[m] != '\0')
	{
		if (arr[m] >= 'A' && arr[m] <= 'Z')   //if chars are between A to Z 
		{
			//finding position of the charater in A-Z by minusing the current arr[m]-A and assigning the number of times it's been repeated to new array uppercase_array
			n = arr[m] - 'A';
			uppercase_array[n]++;
		}
		m++;
	}

	int total_char = 0;

	cout << "Counts: " << endl;
	//priting the final number of chars in the uppercase_array array
	for (int i = 0; i < 26; i++)
	{
		//casting to char
		cout << char(i + 'A') << " : " << uppercase_array[i] << endl;
		total_char += uppercase_array[i];
	}
	cout << total_char;
	return 0;
}