#include <iostream>
#include <string>
using namespace std;

class Hashage
{
private:

	static const int TABLESIZE = 20; 

	struct item
	{
		string data;
		item* next;
	};

	item* HashTable[TABLESIZE];

	int collisions = 0;

public:

	Hashage();

	int  Hash(string key); // prends une chaine de caract�res et retourne son indice

	void ajouter(string data); //prends une chaine de caract�re et l'ajoute dans notre table

	int nombreDesNoeuds(int index); // prends un indice d'un noeud et retourne combient de noeuds y existe

	void afficher(); // affichage de la table pour soucis de d�bougage

	void afficherNoeuds(int index); // prends un noeud et affiche son contenu et tous les noeuds qui y existe

	bool supprimer(string info); // prends un string et le supprime, retourne true si la chaine est rouv� et supprim�, false sinon
	
	int existe(string info); // prends une chaine de caract�re et retourne son indice,  elle retourne -1 si elle n'existe pas dans la table

};