//OTAVIO SALOMAO ROCHA -- 21104191
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { falso, verdadeiro } bool;

bool haveConflict(char ** evento1, char ** evento2);

int main() {
    char** evento1;
    char** evento2;

//  ALOCA A MATRIZ DE STRINGS
    evento1 = (char **)malloc(sizeof(char*)*2);
    evento2 = (char **)malloc(sizeof(char*)*2);
    for ( int i=0 ; i<2 ; i++ ) {
        evento1[i] = (char*)malloc(sizeof(char)*5);
        evento2[i] = (char*)malloc(sizeof(char)*5);
    }

//  LE OS TEMPOS DE CADA EVENTO
    printf("Informe o horario do primeiro evento\n");
    printf(" Comeco: ");
    scanf("%[^\n]s", evento1[0]);
    printf(" Fim: ");
    getchar();
    scanf("%[^\n]s", evento1[1]);

    do {
        if ( evento1[0][0] > evento1[1][0] || (evento1[0][0] == evento1[1][0] && evento1[0][1] > evento1[1][1] ) || (evento1[0][0] == evento1[1][0] && evento1[0][1] == evento1[1][1] && evento1[0][3] > evento1[1][3]) || (evento1[0][0] == evento1[1][0] && evento1[0][1] == evento1[1][1] && evento1[0][3] == evento1[1][3] && evento1[0][4] > evento1[1][4]) || !strcmp(evento1[0], evento1[1])) {
            printf("Horario de encerramento invalido, informe outro: ");
            getchar();
            scanf("%[^\n]s", evento1[1]);
        }
    } while ( evento1[0][0] > evento1[1][0] || (evento1[0][0] == evento1[1][0] && evento1[0][1] > evento1[1][1] ) || (evento1[0][0] == evento1[1][0] && evento1[0][1] == evento1[1][1] && evento1[0][3] > evento1[1][3]) || (evento1[0][0] == evento1[1][0] && evento1[0][1] == evento1[1][1] && evento1[0][3] == evento1[1][3] && evento1[0][4] > evento1[1][4]) || !strcmp(evento1[0], evento1[1]) );
    

//  LE HORARIOS DO EVENTO 2
    printf("Informe o horario do segundo evento\n");
    printf(" Comeco: ");
    getchar();
    scanf("%[^\n]s", evento2[0]);
    printf(" Fim: ");
    getchar();
    scanf("%[^\n]s", evento2[1]);

    do {
        if ( evento2[0][0] > evento2[1][0] || (evento2[0][0] == evento2[1][0] && evento2[0][1] > evento2[1][1] ) || (evento2[0][0] == evento2[1][0] && evento2[0][1] == evento2[1][1] && evento2[0][3] > evento2[1][3]) || (evento2[0][0] == evento2[1][0] && evento2[0][1] == evento2[1][1] && evento2[0][3] == evento2[1][3] && evento2[0][4] > evento2[1][4]) || !strcmp(evento2[0], evento2[1]) ) {
            printf("Horario de encerramento invalido, informe outro: ");
            getchar();
            scanf("%[^\n]s", evento2[1]);
        }
    } while ( evento2[0][0] > evento2[1][0] || (evento2[0][0] == evento2[1][0] && evento2[0][1] > evento2[1][1] ) || (evento2[0][0] == evento2[1][0] && evento2[0][1] == evento2[1][1] && evento2[0][3] > evento2[1][3]) || (evento2[0][0] == evento2[1][0] && evento2[0][1] == evento2[1][1] && evento2[0][3] == evento2[1][3] && evento2[0][4] > evento2[1][4]) || !strcmp(evento2[0], evento2[1]) );

    if ( haveConflict(&evento1[1], &evento2[0]) == verdadeiro ) {
        printf("Ha conflito\n");
    } else {
        printf("Nao ha conflito\n");
    }

//  LIBERA O ESPAÇO ALOCADO
    for ( int i=0 ; i<2 ; i++ ) {
        free(evento1[i]);
        free(evento2[i]);
    }
    free(evento1);
    free(evento2);

    return 0;
}

bool haveConflict(char ** evento1, char ** evento2) {
    int flag=15;

    flag = strcmp(*evento1, *evento2);
    if ( flag==0 ) {
        return verdadeiro;
    } else {
        if ( *(*evento1) == *(*evento2) ) {
            if ( *(*evento1 + 1) == *(*evento2 + 1) ) {
                if ( *(*evento1 + 3) == *(*evento2 + 3) ) {
                    if ( *(*evento1+4) > *(*evento2+4) ) {
                        return verdadeiro;
                    } else {
                        return falso;
                    }
                } else if ( *(*evento1+3) > *(*evento2+3) ) {
                    return verdadeiro;
                } else {
                    return falso;
                }
            } else if ( *(*evento1+1) > *(*evento2+1) ) {
                return verdadeiro;
            } else {
                return falso;
            }
        } else if ( *(*evento1) > *(*evento2) ) {
            return verdadeiro;
        } else {
            return falso;
        }
    }
    return falso;
}
