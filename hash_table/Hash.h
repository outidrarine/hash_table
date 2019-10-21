#include <iostream>
#include <string>
using namespace std;

class Hashage
{
private:

	static const int tableSize = 10;

	struct item
	{
		string data;
		item* next;
	};

	item* HashTable[tableSize];

	int collisions = 0;

public:

	Hashage();

	int  Hash(string key);

	void AddItem(string data);

	int NumberOfItemsInIndex(int index);

	void PrintTable();

	void PrintItemsInIndex(int index);

	void FindDrink(string info);

	void RemoveItem(string info);

};