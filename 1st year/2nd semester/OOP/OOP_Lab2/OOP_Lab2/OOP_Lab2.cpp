// OOP_Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

bool prime(int n)
{
	if (n < 2)
		return false;

	if (n % 2 == 0 && n != 2)
		return false;

	for (int d = 3; d * d <= n; d += 2)
		if (n % d == 0)
			return false;

	return true;
}

void primes_less_than(int limit)
{
	int i = 2;
	while (i < limit)
	{
		if (prime(i))
			cout << i << ' ';

		++i;
	}
	
	cout << endl << endl;
}

void longest_increasing_contiguous_subsequence(int n, int *v)
{
	int st = 0, fin = 0;
	int st_max = 0, fin_max = 0;

	int i = 0;
	while (i < n - 1) // n - 1 becuase we'll use i + 1 in the loop
	{
		if (prime(v[i] + v[i + 1]))
		{
			st = i;
			fin = i + 1;
			
			while (prime(v[fin - 1] + v[fin]) && v[fin] > v[fin - 1] && fin < n) {
				//cout << v[fin - 1] << " --- " << v[fin] << endl;
				++fin;
			}
			
			// without this, fin_max will be one more than it should actually be
			// because we increase fin before we know that the next sum of the pair is a prime number
			fin -= 1;

			if (fin - st > fin_max - st_max)
			{
				st_max = st;
				fin_max = fin;
			}
		}

		++i;
	}

	cout << "Longest sequence from " << st_max << " to " << fin_max << endl;
	for (int i = st_max; i <= fin_max; ++i)
		cout << v[i] << ' ';
	cout << endl << endl;
}

int main()
{
	while (true)
	{
		int option;
		cout << "1. Print prime numbers less than a given number\n";
		cout << "2. Print the longest increasing contiguous subsequence in which the sum of any two consecutive elements is a prime number\n";
		cout << "3. Exit\n";
		cout << ">> ";
		cin >> option;

		if (option == 1)
		{
			int limit;
			cin >> limit;
			primes_less_than(limit);
		}
		else if (option == 2)
		{
			int n, v[100];
			cin >> n;
			for (int i = 0; i < n; ++i)
				cin >> v[i];

			longest_increasing_contiguous_subsequence(n, v);
		}
		else if (option == 3)
		{
			exit(0);
		}
		else
			cout << "Unknown option entered!";
	}

    return 0;
}

