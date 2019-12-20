#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

struct rol{
    int position;
    int lato;
};
typedef struct rol role;

struct pl{
    role *ruol;
    int shirt_num;
    char name[20];
    char lastn[20];
};
typedef struct pl player;

struct tm{
    int classpos;
    int pnt;
    player players[MAX];
};


typedef struct tm team;

void define_role (role *ruolo);
void make_pl(player *pl);
void print_pl(player *pl,int i,role *x);
int main(int argc, char** argv) {
    int risp,i;
    player *giocatore;
    int cont = 0;
    printf("Vuoi effettuare lavori su un giocatore o su una squadra ? \n [ 1) giocatore  2)  squadra] ");
    scanf(" %d",&risp);

    if(risp==1) {
        do {
            printf("\n\n1)Crea Giocatore \n 2)Modifica giocatore \n3)Inserisci giocatore in una squadra");
            printf("\n 4)Visualizza dati giocatore \n 5) Finish program");
            scanf(" %d",&risp);
            if(risp==1) {
                cont++;
                giocatore = (player*)malloc (cont*sizeof(player));
                if (giocatore== NULL) { 
            printf("Memory not allocated.\n"); 
            exit(0); 
            } 
                giocatore->ruol = (role*)malloc(cont*sizeof(role));
                if (giocatore->ruol== NULL) { 
            printf("Memory not allocated.\n"); 
            exit(0); 
            } 
                make_pl(&giocatore[cont-1]); //this is the main problem basically 
            }
            if (risp==4){
                printf("\n Quale giocatore vuoi visualizzare? ");
                scanf("%d",&i);
                print_pl(giocatore,i,giocatore[i].ruol);
            }
            } while(risp != 5);
    }
    return 0;
}

void make_pl(player *pl) {
    printf("\n Inserisci nome ");
    scanf(" %s",pl->name);
    printf("\n Inserisci cognome ");
    scanf(" %s",pl->lastn);
    define_role(pl->ruol);
    printf("Inserisci numero di maglia ");
    scanf(" %d",&pl->shirt_num);
} 

void define_role(role *ruolo) {
    printf("\n Inserisci lato ");
    scanf("%d",&ruolo->lato);
    printf("\n Inserisci posizione ");
    scanf("%d",&ruolo->position);
}

void print_pl(player *pl,int i,role *x){
    printf ("\n Nome : %s \n Cognome : %s",pl[i].name,pl[i].lastn);
    printf ("\n Numero maglia : %d",pl[i].shirt_num);
    printf ("\n Ruolo : ");
    if (x->position==0)
        printf("Portiere");
    if (x->position==1)
        printf("Difensore");
    if (x->position==2)
        printf("Centrocampista");
    if (x->position==3)
        printf("Attaccante");
}
