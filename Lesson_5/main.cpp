#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<set>
#include<map>
#include<iterator>
#include <fstream>
#include<string>


using namespace std;

//Task 1
template<typename T>
void printUniqueWords(T beg,T end)
{
	set<string> mySet;
	//Adding a container to set
	copy(beg, end, inserter(mySet, mySet.end()));
	copy(mySet.begin(), mySet.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
}

//Task 2
void processingInputData(string& buf)
{
	
	multimap<int,string> myMap;
	auto item = 0;
	auto prev = 0;
	auto count = 0;
	//Get a sentence from the buffer
	for (auto smb : buf)
	{
		if (smb != '.' && smb != '!' && smb != '?')
		{
			++item;
		}
		else
		{
			//Remove the space from the beginning of the sentence
			if (buf[prev] == ' ')
				++prev;

			count = ++item - prev;
			//Adding a sentence to the multimap
			myMap.insert(pair<int,string>(count, buf.substr(prev, count)));
			prev = item;
		}
	}
	
	//Output on display
	for_each(myMap.begin(), myMap.end(), [](pair<int, string> item) {cout << item.second <<"\n\n"; });
}

int main()
{
	setlocale(0, "");
	{
		//Task 1
		cout << "Task 1\n";
		vector<string> vec{ "�����", "������", "�����","�������","������","Ƹ����","׸����","�����" };
		printUniqueWords(vec.begin(), vec.end());
		list<string> lst{ "�����", "������", "�����","�������","������","Ƹ����","׸����","�����" };
		printUniqueWords(lst.begin(), lst.end());
		deque<string> deq{ "�����", "������", "�����","�������","������","Ƹ����","׸����","�����" };
		printUniqueWords(deq.begin(), deq.end());

	}

	{
		//Task 2
		cout << "\nTask 2\n";
		//Excerpt from the book 
		ifstream file("������� ���. ����� � ���.txt");
		if (!file)
			cout << "File not found";
		string buf;
		string tmpBuf;
		while (!file.eof())
		{
			getline(file, tmpBuf);
			buf += tmpBuf;
		}
		
		processingInputData(buf);
	}
}