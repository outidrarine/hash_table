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

	void ajouter(string data);

	int numeroDesNoeuds(int index);

	void afficher();

	void afficherNoeuds(int index);

	void supprimer(string info);

};