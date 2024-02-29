#include "ABR.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int filtre(Arbre * A, Arbre filtre_abr, Arbre *utilises) {
    if (*A == NULL) {
        return 1;
    }
    filtre(&((*A)->fd), filtre_abr, utilises);
    filtre(&((*A)->fg), filtre_abr, utilises);
    Noeud *new = recherche(filtre_abr, (*A)->mot); //on recherche le mot dans filtre
    if (new != NULL) { //si on le trouve
        ajout(utilises, new->mot); //on ajoute le mot à utilise
        Noeud *sup = suppression(A, new->mot); //on supprime le mot dans A
        detruit_noeud(sup);//on libere le noeud supprimé
    }
    return 1;
}


int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 4) {
        printf("Probleme sur le nombre d'arguments !\n");
        return 0;
    }
    int verbose = 0;
    Arbre texte = NULL;
    Arbre filtre_abr = NULL;
    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-v") == 0) { //si l'option verbose est activée
            verbose = 1;
        }
        else if (texte == NULL) { //si texte n'est pas déjà initialisé
            if (cree_arbre(argv[i], &texte) == 0) { //si on arrive pas a créer l'arbre
                printf("Un probleme est survenu avec le fichier %s\n", argv[1]);
                return 0;
            }
        }
        else if (filtre_abr == NULL) {
            if (cree_arbre(argv[i], &filtre_abr) == 0) {
                libere(&texte);
                printf("Un probleme est survenu avec le fichier %s\n", argv[2]);
                return 0;
            }
        }
    }
    Arbre utilises = NULL;
    //on affiche le parcours de texte
    if (verbose == 1) { //si l'option est activée
        dessine("texte", texte);
    }
    filtre(&texte, filtre_abr, &utilises); //on fait le filtrage
    printf("Mots présents uniquement dans le texte de référence :\n");
    printf("-----------------------------------------------------\n");
    parcours_infixe(texte);
    printf("\nMots présents dans les deux textes :\n");
    printf("-----------------------------------------------------\n");
    parcours_infixe(utilises);//on affiche utilise
    if (verbose == 1) {
        dessine("en_commun", utilises);
        dessine("filtrage", texte);
        dessine("filtre", filtre_abr);
    }
    libere(&texte);
    libere(&filtre_abr);
    libere(&utilises);
    return 0;

}
