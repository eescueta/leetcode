#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
*/


/*
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
21
22
23
23
24
25
26
36
47
58
69
71
72
83
94
100
201
310
421
532
643
754
865
976
0
1
12
11
10
210
212
211
213
214
215
21
123
12345
1234567
121234567
1231231231
1000
2000000
3000000000
*/

// for numbers less than 1000
string hundredNumToWord(int num)
{
	string ones [] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen"};
	string tens[] = { "", "Teen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

	string res = "";

	for (int i = 0; i < 3 && num > 0; i++)
	{
		if (i == 0)
		{

			if (num % 100 > 9 && num % 100 < 16)
			{
				res += ones[num % 100];
				i++;
				num = num / 100;
				continue;
			}
			else if (num % 100 == 18)
			{
				res += "Eighteen";
				i++;
				num = num / 100;
				continue;
			}

			res += ones[num % 10];
		}

		else if (i == 1)
		{
			if (num % 10 == 1)
				res += "teen";
			else if (num % 10 == 0)
				res = tens[num % 10] + res;
			else
			{
				if (res != "")
					res = tens[num % 10] + " " + res;
				else
					res = tens[num % 10];
			}
		}
		
		else if (i == 2)
		{
			res = (res != "") ? ones[num] + " " + "Hundred" + " " + res : ones[num] + " " + "Hundred";
		}


		num = num / 10;
	}

	return res;
}

string numberToWords(int num) 
{
	if (num == 0)
		return "Zero";

	string res = "";
	vector<string> magnitudes = { "", " Thousand", " Million", " Billion" };

	for (int i = 0; i < magnitudes.size() && num > 0; i++)
	{
		int last3Digits = num % 1000;

		if (last3Digits == 0)
		{
			num = num / 1000;
			continue;
		}

		string currRes = hundredNumToWord(last3Digits) + magnitudes[i];

		if (res == "")
			res = currRes;
		else
			res = currRes + " " + res;

		num = num / 1000;

	}

	return res;
}