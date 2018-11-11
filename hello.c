#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Lorsque l'utilisateur a trouvé le nombre mystère, le programme s'arrête. Demandez si le joueur veut faire une autre partie !

// Il vous faudra faire une boucle qui englobera la quasi-totalité de votre programme. Cette boucle devra se répéter TANT QUE l'utilisateur n'a pas demandé à arrêter le programme.
// Je vous conseille de rajouter une variable booléenne du type continuerPartie initialisée à 1 au départ.
// Si l'utilisateur demande à arrêter le programme, vous mettrez la variable à 0 et le programme s'arrêtera.

// Créez plusieurs niveaux de difficulté. Au début, faites un menu qui demande le niveau de difficulté. Par exemple :
//     1 = entre 1 et 100 ;
//     2 = entre 1 et 1000 ;
//     3 = entre 1 et 10000.

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
            break;
            return difficulteChoisi;
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
    printf("Nombre mystere\n");

    int joueurVeutIlFaireUneNouvellePartie = 0;
    int partieGagneOuQuitte;
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
