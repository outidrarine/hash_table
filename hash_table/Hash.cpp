#include <iostream>
#include <string>
#include "Hash.h"
using namespace std;
Hashage::Hashage()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->data = "empty";
		HashTable[i]->next = NULL;
	}
}

void Hashage::ajouter(string data)
{

	int index = Hash(data);

	if (HashTable[index]->data == "empty")
	{
		HashTable[index]->data = data;
	}
	else
	{
		collisions++;
		item* Ptr = HashTable[index];
		item* n = new item;
		n->data = data;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}
int Hashage::numeroDesNoeuds(int index)
{
	int count = 0;

	if (HashTable[index]->data == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}
void Hashage::afficher()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = numeroDesNoeuds(i);
		cout << "------------------------" << endl;
		cout << "indice =" << i << endl;
		cout << HashTable[i]->data << endl;
		cout << "numero des noeuds = " << number << endl;
		if (number > 1)
		{
			afficherNoeuds(i);
		}
		cout << "------------------------" << endl;
	}
	cout << "numero des collisions: " << collisions << endl;
}
void Hashage::afficherNoeuds(int index)
{
	item* Ptr = HashTable[index];

	if (Ptr->data == "empty")
	{
		cout << "index = " << index << "est vide" << endl;
	}
	else
	{
		cout << "indice = " << index << "contient les noeuds suivants: " << endl;

		while (Ptr != NULL)
		{
			cout << "----------------------------" << endl;
			cout << Ptr->data << endl;
			cout << "----------------------------" << endl;
			Ptr = Ptr->next;
		}

	}
}
void Hashage::supprimer(string name)
{
	int index = Hash(name);

	item* delPtr;
	item* P1;
	item* P2;

	//Case 0 - bucket is empty
	if (HashTable[index]->data == "empty")
	{
		//cout << name << " non trouve" << endl;
	}
	//Case 1 - only one item is contained on the bucket and this item has matching name
	else if (HashTable[index]->data == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->data == "empty";
		//cout << name << " was deleted" << endl;
	}
	//Case 2 - match is located in the first item in the bucket but there are more items in the bucket
	else if (HashTable[index]->data == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		//cout << name << " element supprime" << endl;
		collisions--;
	}
	//Case 3 - bucket contains items but the first item is not a match
	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];
		while (P1 != NULL && P2->data != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
		if (P1 == NULL)
		{
			//cout << name << " non trouve" << endl;
		}
		else
		{
			delPtr = P1;
			P1 = P1->next;
			//P2->next = P1;
			delete delPtr;
			cout << name << " supprime " << endl;
			collisions--;
		}

	}
}

int Hashage::Hash(string key)
{
	int hash1 = 0;
	int index;
	cout << "ajoute a l indice ";
	for (int i = 0; i < key.length(); i++)
	{
		hash1 = hash1 + (int)key[i];
	}
	index = hash1 % tableSize;
	cout << index;
	cout << endl;
	cout << "====================" << endl;
	

	return index;
}