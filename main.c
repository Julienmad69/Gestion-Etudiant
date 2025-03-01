#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

// Définition de la structure Étudiant
typedef struct {
    char nom[50];
    char prenom[50];
    int age;
    float moyenne;
    int rang;
    char mention[20];
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nombreEtudiants = 0;

// Fonction pour saisir la liste des étudiants
void saisirEtudiants() {
    printf("Combien d'étudiants voulez-vous ajouter ? ");
    scanf("%d", &nombreEtudiants);
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("\nÉtudiant %d :\n", i + 1);
        printf("Nom : "); scanf("%s", etudiants[i].nom);
        printf("Prénom : "); scanf("%s", etudiants[i].prenom);
        printf("Âge : "); scanf("%d", &etudiants[i].age);
        printf("Moyenne : "); scanf("%f", &etudiants[i].moyenne);
    }
}

// Fonction pour afficher la liste des étudiants
void afficherEtudiants() {
    printf("\nListe des étudiants :\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("%s %s, %d ans, Moyenne: %.2f, Rang: %d, Mention: %s\n",
               etudiants[i].nom, etudiants[i].prenom, etudiants[i].age,
               etudiants[i].moyenne, etudiants[i].rang, etudiants[i].mention);
    }
}

// Fonction pour affecter une mention
void affecterMention() {
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].moyenne >= 16) strcpy(etudiants[i].mention, "Très Bien");
        else if (etudiants[i].moyenne >= 14) strcpy(etudiants[i].mention, "Bien");
        else if (etudiants[i].moyenne >= 12) strcpy(etudiants[i].mention, "Assez Bien");
        else if (etudiants[i].moyenne >= 10) strcpy(etudiants[i].mention, "Passable");
        else strcpy(etudiants[i].mention, "Échec");
    }
}

// Fonction pour affecter le rang
void affecterRang() {
    for (int i = 0; i < nombreEtudiants; i++) {
        etudiants[i].rang = 1;
        for (int j = 0; j < nombreEtudiants; j++) {
            if (etudiants[j].moyenne > etudiants[i].moyenne)
                etudiants[i].rang++;
        }
    }
}

// Fonction pour afficher les admis (moyenne >= 10)
void afficherAdmis() {
    printf("\nListe des admis :\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].moyenne >= 10)
            printf("%s %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
}

// Fonction pour afficher les exclus (moyenne < 5)
void afficherExclus() {
    printf("\nListe des exclus :\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].moyenne < 5)
            printf("%s %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
}

// Fonction pour afficher les redoublants (5 <= moyenne < 10)
void afficherRedoublants() {
    printf("\nListe des redoublants :\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].moyenne >= 5 && etudiants[i].moyenne < 10)
            printf("%s %s\n", etudiants[i].nom, etudiants[i].prenom);
    }
}

// Fonction pour rechercher un étudiant
void rechercherEtudiant() {
    char nom[50], prenom[50];
    printf("Nom de l'étudiant : "); scanf("%s", nom);
    printf("Prénom de l'étudiant : "); scanf("%s", prenom);
    for (int i = 0; i < nombreEtudiants; i++) {
        if (strcmp(etudiants[i].nom, nom) == 0 && strcmp(etudiants[i].prenom, prenom) == 0) {
            printf("\n%s %s, %d ans, Moyenne: %.2f, Rang: %d, Mention: %s\n",
                   etudiants[i].nom, etudiants[i].prenom, etudiants[i].age,
                   etudiants[i].moyenne, etudiants[i].rang, etudiants[i].mention);
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

// Programme principal
int main() {
    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Saisir étudiants\n2. Afficher étudiants\n3. Affecter mention\n4. Affecter rang\n");
        printf("5. Afficher admis\n6. Afficher exclus\n7. Afficher redoublants\n8. Rechercher étudiant\n9. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: saisirEtudiants(); break;
            case 2: afficherEtudiants(); break;
            case 3: affecterMention(); break;
            case 4: affecterRang(); break;
            case 5: afficherAdmis(); break;
            case 6: afficherExclus(); break;
            case 7: afficherRedoublants(); break;
            case 8: rechercherEtudiant(); break;
            case 9: printf("Fin du programme.\n"); break;
            default: printf("Option invalide.\n");
        }
    } while (choix != 9);

    return 0;
}
