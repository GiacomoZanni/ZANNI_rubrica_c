#include <stdio.h>
#include <string.h>

#define MAX_CONTATTI 100

typedef struct {
    char nome[30];
    char cognome[30];
    char telefono[15];
} Contatto;

Contatto rubrica[MAX_CONTATTI];
int nContatti = 0;
void AggiungiContatto();
void VisualizzaContatti();
void CercaContatto();
void EliminaContatto();

int main() {
    int scelta;

    while (1) {
        printf("\n    RUBRICA    \n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza tutti i contatti\n");
        printf("3. Ricerca contatto per cognome\n");
        printf("4. Elimina contatto per cognome\n");
        printf("5. Esci\n");
        printf("Scegli opzione: ");

        if (scanf("%d", &scelta) != 1) {
            printf("Input non valido. Riprovare.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (scelta) {
            case 1: AggiungiContatto(); break;
            case 2: VisualizzaContatti(); break;
            case 3: CercaContatto(); break;
            case 4: EliminaContatto(); break;
            case 5:
                printf("Uscita. Arrivederci!\n");
                return 0;
            default:
                printf("Opzione non valida. Riprovare.\n");
        }
    }
    return 0;
}

void AggiungiContatto() {
    if (nContatti >= MAX_CONTATTI) {
        printf("Rubrica piena: impossibile aggiungere altri contatti.\n");
        return;
    }

    printf("Inserisci nome (max 29 caratteri, senza spazi): ");
    scanf("%29s", rubrica[nContatti].nome);

    printf("Inserisci cognome (max 29 caratteri, senza spazi): ");
    scanf("%29s", rubrica[nContatti].cognome);

    printf("Inserisci telefono (max 14 caratteri): ");
    scanf("%14s", rubrica[nContatti].telefono);

    nContatti++;
    printf("Contatto aggiunto con successo.\n");
}

void VisualizzaContatti() {
    if (nContatti == 0) {
        printf("Nessun contatto nella rubrica.\n");
        return;
    }

    printf("\nElenco contatti (%d):\n", nContatti);
    for (int i = 0; i < nContatti; i++) {
        printf("%d) Nome: %s\tCognome: %s\tTelefono: %s\n",
               i + 1,
               rubrica[i].nome,
               rubrica[i].cognome,
               rubrica[i].telefono);
    }
}

void CercaContatto() {
    char cognomeRicerca[30];
    int trovato = 0;

    printf("Inserisci il cognome da cercare (senza spazi): ");
    scanf("%29s", cognomeRicerca);

    for (int i = 0; i < nContatti; i++) {
        if (strcmp(rubrica[i].cognome, cognomeRicerca) == 0) {
            if (!trovato) {
                printf("Risultati della ricerca:\n");
            }
            printf("- Nome: %s\tCognome: %s\tTelefono: %s\n",
                   rubrica[i].nome,
                   rubrica[i].cognome,
                   rubrica[i].telefono);
            trovato = 1;
        }
    }

    if (!trovato) {
        printf("Nessun contatto trovato con cognome '%s'.\n", cognomeRicerca);
    }
}

void EliminaContatto() {
    char cognomeDaEliminare[30];
    int indice = -1;

    if (nContatti == 0) {
        printf("Rubrica vuota: nulla da eliminare.\n");
        return;
    }

    printf("Inserisci il cognome da eliminare (verrà eliminato il primo trovato): ");
    scanf("%29s", cognomeDaEliminare);

    for (int i = 0; i < nContatti; i++) {
        if (strcmp(rubrica[i].cognome, cognomeDaEliminare) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Nessun contatto trovato con cognome '%s'.\n", cognomeDaEliminare);
        return;
    }

    for (int j = indice; j < nContatti - 1; j++) {
        rubrica[j] = rubrica[j + 1];
    }
    nContatti--;
    printf("Contatto eliminato.\n");
}
