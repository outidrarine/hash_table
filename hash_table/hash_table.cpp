#include "Hash.h"
#include <iostream>
#include <string.h>
int main()
{
	int choice;
	Hashage uneTable;
	while (true)
	{
		cout << "\n choisissez : \n 1 - Ajouter \n 2 - Afficher \n 3 - Supprimer \n";
		cin >> choice;
		switch (choice)
		{
			case 2:
			{
				uneTable.afficher();
				break;
			}
			case 3:
			{
				cout << "\n donner un nom a supprimer : \n";
				string nom;
				cin >> nom;
				uneTable.supprimer(nom);
				break;
			}
			case 1:
			{
				cout << "\n donner un nom : \n";
				string nom;
				cin >> nom;
				uneTable.ajouter(nom);
				break;
			}

		}
	}

}
