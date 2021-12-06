#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<set>
#include<map>
#include<iterator>
#include <fstream>


using namespace std;

//Task 1
template<typename T>
void printUniqueWords(T beg,T end)
{
	set<string> mySet;
	copy(beg, end, inserter(mySet, mySet.end()));
	copy(mySet.begin(), mySet.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
}

//Task 2
void userInput()
{
	multimap<int,string> myMap;
}

int main()
{
	setlocale(0, "");
	{
		//Task 1
		cout << "Task 1\n";
		vector<string> vec{ "Белый", "Зелёный", "Синий","Красный","Зелёный","Жёлтый","Чёрный","Синий" };
		printUniqueWords(vec.begin(), vec.end());
		list<string> lst{ "Белый", "Зелёный", "Синий","Красный","Зелёный","Жёлтый","Чёрный","Синий" };
		printUniqueWords(lst.begin(), lst.end());
		deque<string> deq{ "Белый", "Зелёный", "Синий","Красный","Зелёный","Жёлтый","Чёрный","Синий" };
		printUniqueWords(deq.begin(), deq.end());

	}

	{
		//Task 2
		cout << "\nTask 2\n";

	}
}