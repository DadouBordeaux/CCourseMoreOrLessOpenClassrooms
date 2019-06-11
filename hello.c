#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int niveauMax(int niveauChoisi)
{
    switch (niveauChoisi)
    {
    case 1:
        return 100;
        break;
    case 2:
        return 1000;
        break;
    case 3:
        return 10000;
        break;
    default:
        return 0;
        break;
    }
}

int menuNouvellePartie()
{
    int veutIlRefaireUnePartie;

    printf("Voulez vous faire une nouvelle partie ?\n");
    printf("0 - Non, merci\n");
    printf("1 - Encore !\n");

    scanf("%d", &veutIlRefaireUnePartie);
    return veutIlRefaireUnePartie;
}

int menuDifficulte()
{
    int difficulteChoisi;

    while (difficulteChoisi < 0 || difficulteChoisi > 3)
    {
        printf("=== Difficultée ===\n\n");
        printf("1. Facile, entre 1 et 100\n");
        printf("2. Moyen, entre 1 et 1000\n");
        printf("3. Awesome, entre 1 et 100000\n");
        printf("0. Annuler et quitter le jeu\n");
        printf("\nVotre choix ? ");

        scanf("%d", &difficulteChoisi);
        printf("\n");

        switch (difficulteChoisi)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("C'est parti\n");
            return difficulteChoisi;
            break;
        case 2:
            printf("Connaisseur à ce que je vois :)\n");
            return difficulteChoisi;
            break;
        case 3:
            printf("A demain... :p\n");
            return difficulteChoisi;
            break;
        default:
            printf("Vous n'avez pas rentre un numero de menu correct,  \n");
            break;
        }
    }
    printf("\n\n");
    return 0;
}

int partie()
{
    const int MIN = 1;
    const int partieGagne = 1;
    int MAX;
    int nombreMystere;
    int userInput;
    int coupJoueur = 0;
    int difficulteChoisi;

    srand(time(NULL));

    printf("Avant de commencer veuillez choisir la difficulte\n");

    difficulteChoisi = menuDifficulte();

    if (difficulteChoisi == 0)
    {
        return 0;
    }

    MAX = niveauMax(difficulteChoisi);
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    printf("Pour quitter la partie, indiquer 0\n\n");
    printf("Votre reponse ?\n");
    do
    {
        scanf("%d", &userInput);
        if (userInput == 0)
        {
            return 0;
        }

        coupJoueur++;
        printf("Nombre de coup joues: %d\n\n", coupJoueur);

        if (userInput < nombreMystere)
        {
            printf("Trop petit ! Essaye encore\n");
        }
        else if (userInput > nombreMystere)
        {
            printf("Trop grand ! Essaye encore\n");
        }
        else
        {
            printf("Bravo vous avez gagne en %d coups\n", coupJoueur);
        }
    } while (userInput != nombreMystere);

    return partieGagne;
}

int main(int argc, char *argv[])
{
    const int QUITTE_LA_PARTIE = 0;
    const int A_GAGNE = 1;
    int joueurVeutIlFaireUneNouvellePartie = 0;
    int partieGagneOuQuitte;
    printf("Nombre mystere\n");

    do
    {
        partieGagneOuQuitte = partie();
        if (partieGagneOuQuitte == A_GAGNE)
        {
            joueurVeutIlFaireUneNouvellePartie = menuNouvellePartie();
        }
        else if (partieGagneOuQuitte == QUITTE_LA_PARTIE)
        {
            joueurVeutIlFaireUneNouvellePartie = QUITTE_LA_PARTIE;
        }

    } while (joueurVeutIlFaireUneNouvellePartie);

    printf("Aurevoir et a la prochaine\n");
    return 0;
}
