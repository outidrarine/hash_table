# Une simple table de hashage <img alt="" src="https://img.shields.io/github/languages/code-size/outidrarine/Go-Game.svg">
Ce repo contient une simple implementation d'une table de hashage, en utilisant une fonction de hashage polynomial, avec les methodes, afficher, ajouter et supprimer, implimenté en c++
# Introduction
Le but des tables de hachage est d'implémenter l'interface d'une table de symboles. Cette structure de données vous permet de stocker 
efficacement des paires "clé-valeur".

Toute la difficulté consiste à écrire une fonction de hachage correcte. Comment transformer une chaîne de caractères en un nombre unique ?

# Gestion des collisions 
Quand la fonction de hachage renvoie le même nombre pour deux clés différentes, on dit qu'il y a collision. Par exemple dans le
cas d’ un anagramme, la somme des lettres est la même ( si nous avons opté pour une fonction de hashage qui fait la somme des caractères
dans une chaine de caractère comme c'est le cas dans ce repo ), donc le résultat de la fonction de hachage sera le même !

Deux raisons peuvent expliquer une collision.
-	La fonction de hachage n'est pas très performante.
-	Le tableau dans lequel on stocke nos données est trop petit.

Si une collision survient on a deux solutions pour gérer cette collision.
## L'adressage ouvert
S'il reste de la place dans votre tableau, vous pouvez utiliser la technique dite du hachage linéaire. Le principe est simple. La 
case est occupée ? Pas de problème, allez à la case suivante. Ah, elle est occupée aussi ? Allez à la suivante !

Ainsi de suite, continuez jusqu'à trouver la prochaine case libre dans le tableau. Si vous arrivez à la fin du tableau, retournez à 
la première case et continuez.

Cette méthode est très simple à mettre en place, mais si vous avez beaucoup de collisions, vous allez passer beaucoup de temps à 
chercher la prochaine case libre.

Il existe des variantes (hachage double, hachage quadratique…) qui consistent à hacher à nouveau selon une autre fonction en 
cas de collision. Elles sont plus efficaces mais plus complexes à mettre en place.
## Le chaînage
Une autre solution consiste à créer une liste chaînée à l'emplacement de la collision. Vous avez deux données (ou plus)
à stocker dans la même case ? Utilisez une liste chaînée et créez un pointeur vers cette liste depuis le tableau (fig. suivante).
### qu'est-ce qu'une bonne fonction de hashage ?
Dans notre table de hachage, les indices sont générés en deux opérations :

- le hachage : on hache la clé, qui donne un nombre pouvant être très grand en valeur absolue ;
- la compression : on compresse le hash code, pour qu'il puisse rentrer dans la table.

Il est assez facile d'avoir une bonne fonction de hachage, les problèmes apparaisseant dans la compression.

Pour que cette dernière soit efficace, la première chose qu'elle devra faire est de satisfaire
l'hypothèse de hachage uniforme simple, qui dit que :

>chaque clé a la même chance d'être placée dans une case que dans 
n'importe quel autre emplacement de la table, indépendamment des endroits où les autres clés sont allées.


Autrement dit, lors de l'ajout d'une clé, pour une case quelconque d'une table de taille M, il y a une chance sur M pour 
que la clé se trouve dans cette case.

Malheureusement, il est très difficile de trouver LA fonction qui vérifie cette condition sans avoir des informations 
précises sur les clés.

# Quelques bonnes fonctions de hashage : 
## Hashage polynomiale : 
Une fonction de hachage polynomiale est une fonction qui est basée sur la somme de la valeur de chaque caractère. 
Cette méthode sera efficace pour des chaînes différentes... Mais des chaînes dont les caractères sont permutés auront le même hash !

On peut améliorer le hashge de cette fonction en élevant sur chaque terme une puissance dans son ordre d'apparition.
## Hachage cyclique :
On prend les n premiers bits (les bits de poids fort) du hash et on les met à la place des p derniers bits 
(les bits de poids faible). On y ajoute ensuite la valeur numérique du caractère courant.
### exemple :
```
for(int i = 0 ; i < s.length() ; i++) // On parcourt tous les caractères
	{
		h = (h << 5) | (h >>> 27); // Décalage cyclique de 5 bits
		h += (int) s.charAt(i);
	}
```
  
# Quelques bonnes fonctions de compression :
## Méthode de la division
La méthode de division est la plus simple et la plus intuitive :
pour qu'un grand nombre n'en dépasse pas un autre... on prend le modulo ! ( c'est la méthode utilisé dans ce repo )
## Méthode de la multiplication
Cette méthode est un peu plus tordue : on va multiplier le hash code par une constante comprise entre 0 et 1 (exclus) et
récupérer la partie décimale. Ensuite, on va la multiplier par la taille de la table, et prendre la valeur inférieure entière
la plus proche.
```
private double c = 0.618;

private static int hash(String s)
{
	// ...				
	return floor(m * ( ( (double) abs(h) * c) % 1)) ;
}
```
