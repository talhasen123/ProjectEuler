// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <forward_list>

using namespace std;

//Problem 1

int sumOfMuliple3or5(int bound)
{
	int sum = 0;

	for (int i = 1; i < bound; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;
}

//Problem 2

int evenFibonacciSum(int bound)
{
	int sum = 0;
	int fib1 = 1;
	int fib2 = 2;
	int fibTemp = fib2;

	while ( fib2 < bound)
	{
		if (fib2 % 2 == 0)
		{
			sum += fib2;
		}

		fib2 += fib1;
		fib1 = fibTemp;
		fibTemp = fib2;
	}

	return sum;
}

//Problem 3

bool isPrime( unsigned long long int number)
{
	for (unsigned long long int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

unsigned long long int findLargestPrime(unsigned long long int number)
{
	// Initialize the maximum prime factor 
	// variable with the lowest one 
	unsigned long long int maxPrime = -1;

	// Print the number of 2s that divide n 
	while (number % 2 == 0) {
		maxPrime = 2;
		number >>= 1; // equivalent to n /= 2 
	}

	// n must be odd at this point, thus skip 
	// the even numbers and iterate only for 
	// odd integers 
	for (int i = 3; i <= sqrt(number); i += 2) {
		while (number % i == 0) {
			maxPrime = i;
			number = number / i;
		}
	}

	// This condition is to handle the case 
	// when n is a prime number greater than 2 
	if (number > 2)
		maxPrime = number;

	return maxPrime;
}

//Problem 4
bool isPalindrome(string number)
{
	string numberBack = "";
	for (int i = 0; i < number.length(); i++)
	{
		numberBack = number.at(i) + numberBack;
	}

	if (number == numberBack)
	{
		return true;
	}
	return false;
}

void largestPalindrome3Digit()
{
	int i1 = 999;
	int i2 = 999;
	int number;
	int max = 0;

	while (i1 > 99)
	{
		while (i2 > 99)
		{
			number = i1 * i2;
			cout << "i1 is: " << i1 << " i2 is: " << i2 << " number is: " << number << endl;
			string numberString;
			ostringstream ss;
			ss << number;
			numberString = ss.str();
			if (isPalindrome(numberString))
			{
				cout << number << endl;
				max = number;
			}

			i2--;
		}
		i1--;
		i2 = i1;
	}

}

//Problem 5
int smallestMultiple()
{
	for (int i = 21; ; i++)
	{
		for (int p = 1; i % p == 0; p++)
		{
			if (p == 20)
			{
				return i;
			}
		}
	}

	return 0;
}

//Problem 6
int sumSquareDifference()
{
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum1 += i * i;
	}

	sum2 = (100 * 101 / 2) * (100 * 101 / 2);

	return sum2 - sum1;
}

//Problem 7
int tenThousandFirstPrime()
{
	int current = 1;
	for (int i = 2; ; i++)
	{
		if (isPrime(i))
		{
			if (current == 10001)
			{
				return i;
			}
			current++;
		}
	}
}

//Problem 8
int largestProductInASeries()
{
	string number = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	unsigned long long int max = 0;

	for (int i = 0; i + 12 < number.length(); i++)
	{
		unsigned long long int product = (number.at(i) - '0') * (number.at(i + 1) - '0') * (number.at(i + 2) - '0') * (number.at(i + 3) - '0') * (number.at(i + 4) - '0') * (number.at(i + 5) - '0') * (number.at(i + 6) - '0') * (number.at(i + 7) - '0') * (number.at(i + 8) - '0') * (number.at(i + 9) - '0') * (number.at(i + 10) - '0') * (number.at(i + 11) - '0') * (number.at(i + 12) - '0');
		if ( product > max)
		{
			max = product;
		}
	}
	return max;
}

//Problem 9
int specialPythagoreanTriplet()
{
	int a = 1;
	int b = 2;

	while (b < 1000)
	{
		while (a < b)
		{
			if (a + b + (sqrt(pow(a, 2) + pow(b, 2))) == 1000)
			{
				return a * b * (sqrt(pow(a, 2) + pow(b, 2)));
			}
			a++;
		}
		b++;
		a = 1;
	}
	return 0;
}

//Problem 10
unsigned long long int sumOfPrimesBelowTwoMillion()
{
	unsigned long long int sum = 0;

	for (int i = 2; i < 2000000; i++)
	{
		if (isPrime(i))
		{
			if (i > 1000000)
			{
				cout << "half way" << endl;
			}
			sum += i;
		}
	}
	return sum;
}

//Problem 11
int recursiveGridSearch(int grid[20][20], int direction, int row, int column, int backRow, int backColumn, int visited, int product, int& maxProduct)
{
	if (row < 0 || row >= 20 || column < 0 || column >= 20)
	{
		return 1;
	}
	else
	{
		if (visited == 4)
		{
			row = backRow;
			column = backColumn;
			if (direction == 0)
			{
				backRow--;
			}
			else if (direction == 1)
			{
				backRow--;
				backColumn++;
			}
			else if (direction == 2)
			{
				backColumn++;
			}
			else if (direction == 3)
			{
				backRow++;
				backColumn++;
			}
			else if (direction == 4)
			{
				backRow++;
			}
			else if (direction == 5)
			{
				backRow++;
				backColumn--;
			}
			else if (direction == 6)
			{
				backColumn--;
			}
			else if (direction == 7)
			{
				backRow--;
				backColumn--;
			}

			visited = 0;
			if (product > maxProduct)
			{
				maxProduct = product;
			}
			product = 1;
		}
		visited++;

		if (direction == 0)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row - 1, column, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 1)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row - 1, column + 1, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 2)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row, column + 1, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 3)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row + 1, column + 1, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 4)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row + 1, column, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 5)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row + 1, column - 1, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 6)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row, column - 1, backRow, backColumn, visited, product, maxProduct);
		}
		else if (direction == 7)
		{
			product *= grid[row][column];
			recursiveGridSearch(grid, direction, row - 1, column - 1, backRow, backColumn, visited, product, maxProduct);
		}

		return 1;
	}
}

int searchGrid()
{
	std::fstream myfile("D:\\gridData.txt", std::ios_base::in);

	float a;
	int grid[20][20];
	int maxProduct = 0;
	
	for (int n = 0; n < 20; n++)
	{
		for (int p = 0; p < 20; p++)
		{
			myfile >> a;
			grid[n][p] = a;
		}
	}

	for (int t = 0; t < 20; t++)
	{
		recursiveGridSearch(grid, 0, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 1, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 2, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 3, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 4, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 5, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 6, t, t, t, t, 0, 1, maxProduct);
		recursiveGridSearch(grid, 7, t, t, t, t, 0, 1, maxProduct);
	}

	return maxProduct;
}




//Problem 12
long long highlyDivisibleTriangularNumber()
{

	for (int i = 1; ; i++)
	{
		long long number = i * (i + 1) / 2;
		long long divisors = 0;
		for (long long p = 1; p < number; p++)
		{
			if (number % p == 0)
			{
				divisors++;

				
			}
		}
		if (divisors > 250)
		{
			cout << number << endl << " " << divisors;
		}

		if (divisors > 500)
		{
			return number;
		}
	}
}

//Problem 13
string largeSum()
{
	std::fstream myfile("D:\\largeSumData.txt", std::ios_base::in);
	string allNumbers = "";
	string aNumber = "";

	while (myfile >> aNumber)
	{
		allNumbers += aNumber;
	}

	string result = "";
	int carry = 0;
	int digit = 0;


	for (int i = 49; i >= 0; i--)
	{
		digit = carry;
		for (int p = 0; p < 5000; p += 50)
		{
			digit += allNumbers.at(i + p) - '0';
		}
		carry = digit / 10;
		digit = digit % 10;
		result = to_string(digit) + result;

		if (i == 0)
		{
			result = to_string(carry) + result;
		}
	}

	return result.substr(0, 10);
}

//Problem 14
int longestCollatzSequence()
{
	int start = 999999;
	int count = 1;
	int number;
	int maxCount = 1;
	int maxStart = 999999;

	while (start > 0)
	{
		number = start;
		while (number > 1)
		{
			if (number % 2 == 0)
			{
				number = number / 2;
			}
			else
			{
				number = 3 * number + 1;
			}
			count++;
		}

		count++;

		if (count > maxCount)
		{
			cout << start << endl;
			maxCount = count;
			maxStart = start;
		}
		start--;
		count = 0;
	}
	return maxStart;
}

//Problem 16
int sumOf2To1000()
{
	string number = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	int sumOfDigits = 0;

	for ( int i = 0; i < number.length(); i++)
	{
		sumOfDigits += number.at(i) - '0';
	}

	return sumOfDigits;
}

//Problem 17
unsigned long long int numberLetterCounts()
{
	//enum Digits { ONE = 3, TWO = 3, THREE = 5, FOUR = 4, FIVE = 4, SIX = 3, SEVEN = 5, EIGHT = 5, NINE = 4 };
	//enum Tens { TEN = 3, ELEVEN = 6, TWELVE = 6, THIRTEEN = 8, FOURTEEN = 8, FIFTEEN = 7, SIXTEEN = 7, SEVENTEEN = 9, EIGHTEEN = 8, NINETEEN = 8};
	//enum BigTens { TWENTY = 6, THIRTY = 6, FORTY = 6, FIFTY = 5, SIXTY = 5, SEVENTY = 7, EIGHTY = 6, NINETY = 6};

	int digits[9] = { 3, 3, 5, 4, 4, 3, 5, 5, 4 };
	int tens[10] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	int bigTens[8] = { 6, 6, 5, 5, 5, 7, 6, 6 };

	unsigned long long int letterSum = 0;

	for (int i = 1; i < 10; i++)
	{
		letterSum += digits[i - 1];
	}

	for (int p = 10; p < 20; p++)
	{
		letterSum += tens[p % 10];
	}

	for (int t = 20; t < 100; t++)
	{
		if (t % 10 == 0)
		{
			letterSum += bigTens[(t / 10) - 2];
		}
		else
		{
			letterSum += bigTens[(t / 10) - 2] + digits[(t % 10) - 1];
		}
	}

	for (int n = 100; n < 1000; n++)
	{
		letterSum += digits[n / 100 - 1] + 7;

		if (n % 100 < 10 && n % 100 > 0)
		{
			letterSum += digits[n % 100 - 1] + 3; 
		}
		else if (n % 100 >= 10 && n % 100 < 20)
		{
			letterSum += tens[((n / 10) % 10) - 1] + 3;
		}
		else if (n % 100 != 0 && n % 100 >= 20)
		{
			letterSum += bigTens[((n / 10) % 10) - 2] + 3 + digits[n % 100 - 1];
		}
	}

	return letterSum;
}

//Problem 18

int maximumPathSum()
{
	std::fstream myfile("D:\\triangleData.txt", std::ios_base::in);

	int** triangle = new int*[15];
	for (int i = 0; i < 15; i++)
	{
		triangle[i] = new int[i + 1];
		for (int p = 0; p < i; p++)
		{
			float a;
			myfile >> a;
			triangle[i][p] = a;
		}
	}

	int maxPath = 0;

	for (int t = 0; t < 15; t++)
	{

	}
	
	return maxPath;
}

//Problem 20
int digitSumOfHundredFactorial()
{
	string factorial = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
	int sum = 0;

	for (int i = 0; i < factorial.length(); i++)
	{
		sum += factorial.at(i) - '0';
	}

	return sum;
}

//Problem 21
int sumOfDivisors(int number)
{
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}

	return sum;
}

int amicableNumbers()
{
	int sum = 0;

	for (int i = 1; i < 10000; i++)
	{
		int p = sumOfDivisors(i);
		if (sumOfDivisors(p) == i && i != p)
		{
			cout << i << endl;
			sum += i;
		}
	}

	return sum;
}

//Problem 29
int distinctPowers()
{
	forward_list<int> list;
	for (int i = 2; i <= 100; i++)
	{
		for (int p = 2; p <= 100; p++)
		{
			list.push_front(pow(i, p));
		}
	}

	list.sort();


	return list.max_size();
}

//Problem 50
int consecutivePrimeSum()
{
	int sum = 0;
	int result = 0;

	for (int i = 2; sum < 1000000; i++)
	{
		if (isPrime(i))
		{
			sum += i;

			if (isPrime(sum))
			{
				cout << sum << endl;
				result = sum;
			}
		}
	}
	return result;
}

int main()
{
	clock_t tStart = clock();
	cout << maximumPathSum() << endl;
	printf("Time taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}

