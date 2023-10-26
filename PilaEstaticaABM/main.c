#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>

#define MAX 10

struct Pila{
    int datos[MAX];
    int Inicio;
};

void inicializarPila(struct Pila *pila) {
    pila->Inicio = -1;
    for (int i = 0; i < MAX; i++) {
        pila->datos[i] = 0; // Inicializa todos los elementos a 0
    }
}

int estaVacia(struct Pila *pila) {
    return (pila->Inicio == -1);
}

int estaLlena(struct Pila *pila) {
    return (pila->Inicio == MAX - 1);
}

void agregarValor(struct Pila *pila, int valor) {
    if (!estaLlena(pila)) {
        pila->Inicio++;
        pila->datos[pila->Inicio] = valor;
    } else {
        printf("La pila está llena, no se puede agregar más valores.\n");
    }
}

int eliminarValor(struct Pila *pila) {
    if (!estaVacia(pila)) {
        int valorEliminado = pila->datos[pila->Inicio];
        pila->Inicio--;
        printf("¡Se ha eliminado el valor '%d' correctamente!\n",valorEliminado);
        puts("--------------------------------------");
        system("pause");
        return valorEliminado;
    } else {
        printf("La pila está vacía, no se puede eliminar ningún valor.\n");
        puts("--------------------------------------");
        system("pause");
        return -1; // Se podría elegir otro valor para indicar un error.
    }
}

void verPila(struct Pila *pila) {
    if (!estaVacia(pila)) {
        puts("Contenido de la pila:\n");
        int i = pila->Inicio;
        printf("Inicio->");
        while (i >= 0) {
            printf("%d->", pila->datos[i]);
            i--;
        }
    } else {
        printf("La pila está vacía.\n");
    }
    puts("NULL");
    puts("--------------------------------------");
    system("pause");
}


void Menu(){
    puts("Menú: \n");
    puts("1. Agregar valor");
    puts("2. Eliminar valor");
    puts("3. Ver pila");
    puts("3. Salir");
    puts("----------------------------");
    printf("Elegir opción: ");
}

int main()
{
    struct Pila pila;
    int op, op2, op3,dato;

    inicializarPila(&pila);

    setlocale(LC_ALL, "");
    srand(time(NULL));

    do{
        system("cls");
        Menu();
        scanf("%d",&op);
        while(op>4 || op<1){
            puts("------------------------------------");
            puts("¡Opción no valida, intente de nuevo!");
            puts("------------------------------------");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }
        switch(op){
            case 1:
                do{
                    system("cls");
                    if (!estaLlena(&pila)) {
                        printf("Ingrese un valor: ");
                        scanf("%d", &dato);
                        agregarValor(&pila, dato);
                        system("cls");
                        puts("¿Desea agregar otro valor?\n1.Si\n2.No");
                        puts("-----------------");
                        printf("Elegir opción: ");
                        scanf("%d",&op2);
                        while(op2>2 || op2<1){
                            puts("------------------------------------");
                            puts("¡Opción no valida, intente de nuevo!");
                            puts("------------------------------------");
                            printf("Elegir opción: ");
                            scanf("%d",&op2);
                        }
                    } else {
                        printf("La pila está llena, no se puede agregar más valores.\n");
                        puts("------------------------------------");
                        system("pause");
                        break;
                    }
                }while(op2!=2);
                break;
            case 2:
                system("cls");
                eliminarValor(&pila);
                break;
            case 3:
                system("cls");
                verPila(&pila);
                break;
            case 4:
                system("cls");
                puts("¿Está seguro que desea salir?\n1.Si\n2.No");
                puts("-----------------");
                printf("Elegir opción: ");
                scanf("%d",&op3);
                while(op3>2 || op3<1){
                    puts("------------------------------------");
                    puts("¡Opción no valida, intente de nuevo!");
                    puts("------------------------------------");
                    printf("Elegir opción: ");
                    scanf("%d",&op3);
                }
                switch(op3){
                case 1:
                    system("cls");
                    puts("Saliendo del programa...");
                    sleep(2);
                    break;
                case 2:
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                    op=1;
                    break;
                }
                break;
        }
    }while(op!=4);

    return 0;
}
