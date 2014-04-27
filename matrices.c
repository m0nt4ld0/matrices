#include <stdio.h>
#include <conio.h>

#define MAX_COL 3
#define MAX_FI 3

int sumatoriaDiagInf(const int[][MAX_COL]);
int sumatoriaDiagSup(const int[][MAX_COL]);
int sumatoriaSecSup(const int[][MAX_COL]);
int sumatoriaSecInf(const int[][MAX_COL]);
int cargarMenu(void);
int trazaDiagSec(const int[][MAX_COL]);
int trazaDiagPpal(const int[][MAX_COL]);
void cargarMatriz(int [][MAX_COL]);
void mostrarMatriz(const int[][MAX_COL]);
void traspuesta(int[][MAX_COL]);
void intercambio(int *, int *);
    
void main(void){
    int matriz[MAX_FI][MAX_COL];
    int op = -1;
    printf("\nTP 1 Matrices: Ejercicios con matrices cuadradas");
    while(op!=0) {
        op = cargarMenu();
        switch(op){
            case 0:
                return;
            case 1:cargarMatriz(matriz);
            break;
            case 2:printf("\nResultado: %d",sumatoriaDiagSup(matriz));
            break;
            case 3:printf("\nResultado: %d",sumatoriaSecSup(matriz));
            break;
            case 4: printf("\nResultado: %d",sumatoriaDiagInf(matriz));
            break;
            case 5: printf("\nResultado: %d",sumatoriaSecInf(matriz));
            break;
            case 6: printf("\nResultado: %d",trazaDiagPpal(matriz));
            break;
            case 7: printf("\nResultado: %d",trazaDiagSec(matriz));
            break;
            case 8:
                printf("\nResultado: %d",sumatoriaDiagSup(matriz)+trazaDiagPpal(matriz));
            break;
            case 9: 
                printf("\nResultado: %d",sumatoriaDiagInf(matriz)+trazaDiagPpal(matriz));
            break;
            case 10:
                traspuesta(matriz);
                mostrarMatriz(matriz);
            break;
        }    
    }
}

int cargarMenu(void){
    int opcion = -1;
    do{
        printf("\nSeleccione la operacion a realizar \n1)Ingresar matriz \n2)Sumatoria de los elem. superiores a la diag. ppal. (s/diag. ppal.) \n3)Sumatoria de los elem. superiores a la diag. sec. (s/diag. sec.) \n4)Sumatoria de los elem. inferiores a la diag. ppal. (s/diag. ppal.) \n5)Sumatoria de los elem. inferiores a la diag. sec. (s/diag. sec.) \n6)Traza de la diag. ppal. de la matriz \n7)Traza de la diag. sec. de la matriz \n8)Sumatoria de los elem. superiores a la diag. ppal. (incluyendo diag. ppal.) \n9)Sumatoria de los elem. inferiores a la diag. ppal. (incluyendo diag. ppal.) \n10)Trasponer matriz \n0)Salir \n");
        scanf("%d",&opcion);
    } while(opcion<1 && opcion >10);
    return opcion;
}
//Sumatoria de los elem. inferiores a la diag. ppal. (s/ incluir diag. ppal.)
int sumatoriaDiagInf(const int Mat[][MAX_COL]){
    int diag=1, f, c, acuminf=0;
    while(diag<MAX_FI){
        f=diag;
        c=0;
        while(f<MAX_FI){
            if(c<f){
                acuminf+=Mat[f][c];
                f++;
                c++;
            }
        }
        diag++;
    }
    return acuminf;
}
//Sumatoria de los elem. superiores a la diag. ppal. (s/ incluir diag. ppal.)
int sumatoriaDiagSup(const int Mat[][MAX_COL]){
    int diag=1, f, c, acumsup=0;
    while(diag<MAX_COL){
        f=0;
        c=diag;
        while(c<MAX_COL){
            if(f<c){
                acumsup+=Mat[f][c];
                f++;
                c++;
            }
        }
        diag++;
    }
    return acumsup;
}
//Sumatoria de elem. superiores a la diag sec.
int sumatoriaSecSup(const int Mat[][MAX_COL]){
    int cf, cc, acumsup = 0;
    for(cf=0; cf<MAX_FI-1; cf++){
        for(cc=0; cc<MAX_COL-1-cf; cc++){
            acumsup+=Mat[cf][cc];
        }
    }
    return acumsup;
}
//Sumatoria de elem. inferiores a la diag sec.
int sumatoriaSecInf(const int Mat[][MAX_COL]){
    int cf, cc, acuminf = 0;
    for(cf=MAX_FI-1; cf>=1; cf--){
        for(cc = MAX_FI-cf; cc <= MAX_COL-1; cc++)
        acuminf+=Mat[cf][cc];
    }
    return acuminf;
}

void cargarMatriz(int M[][MAX_COL]){
    int i, j;
    for(i=0; i<MAX_FI; i++){
        for(j=0; j<MAX_COL; j++){
            printf("\nIngrese un valor para la posicion [%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    }
    printf("\nMatriz ingresada: \n");
    mostrarMatriz(M);
}

void mostrarMatriz(const int M[][MAX_COL]){
    int i, j;
    for(i=0; i<MAX_FI; i++){
        for(j=0; j<MAX_COL; j++){
            printf("\t[%d]",M[i][j]);
        }
        printf("\n");
    }
}

//Traza de diag sec.
int trazaDiagSec(const int M[][MAX_COL]){
    int acumSec=0, f=MAX_FI-1, c=0;
    while(c<=MAX_COL-1){
        acumSec+=M[f][c];
        f--;
        c++;
    }
    return acumSec;
}
//Traza de diag ppal.
int trazaDiagPpal(const int M[][MAX_COL]){
    int acum=0, f=0, c=0;
    while(c<MAX_COL){
        acum+=M[f][c];
        f++;
        c++;
    }
    return acum;
}

void traspuesta(int M[][MAX_COL]){
    int f=1, c=0;
    while(c<MAX_COL-1){
        intercambio(&M[f][c], &M[c][f]);
        c++;
        if(f==c && f<MAX_FI-1){
            f++;
            c=0;
        }
    }
}

void intercambio(int *a, int *b){
    int aux=*a;
    *a = *b;
    *b = aux;
}
