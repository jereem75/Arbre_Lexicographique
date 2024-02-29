# Compte Rendu DM Algo

Thierno Sy/Jeremy Sutra

## Fonctionnement de notre DM
Notre DM est compose de tout les fichiers demandés dans l'enonce du DM.
Pour compiler le fichier il faut simplement ouvrir un terminal, se placer dans le dossier contenant les fichiers du DM et entrer la commande make. Celle-ci compilera automatiquement tout les fichiers necessaires a la compilation. Ensuite un fichier executable a ete cree intitule filtre. Il suffit d'ecrire ./filtre (-v) texte.txt filtre.txt
L'option -v est optionnelle. Elle permet de creer des fichiers pdf pour les fichiers textes. Le premier parametre est un fichier texte simple. Le deuxieme fichier filtre.txt est un fichier qui va filtrer les mots du fichier texte.txt en y retirant les mots presents dans le fichier filtre.txt .
Nous n'avons pas trop eu de difficultes.

Concernant la fonction supression, nous avons décidé e la faire en deux paties, une premiere fonction auxiliaire qui supprime la tête d'un arbre et une fonction principale qui se place un noeud avant le noeud à supprimer et enleve se dernier en mettant à jour correctement l'arbre.