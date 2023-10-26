#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>

struct Pila{
    int valor;

    struct Pila *sig;
};

struct Pila *Inicio = NULL;
struct Pila *mayor = NULL;

int vacia()
{
    if (Inicio == NULL)
        return 1;
    else
        return 0;
}

void Menu(){
    puts("Menú: \n");
    puts("1. Agregar valor");
    puts("2. Ver pila de valores");
    puts("3. Salir");
    puts("----------------------------");
    printf("Elegir opción: ");
}

void agregarValor(int dato){
    struct Pila *nuevo;
    nuevo = malloc(sizeof(struct Pila));
    nuevo->valor = dato;
    nuevo->sig = NULL;

    if (Inicio == NULL) {
        Inicio = nuevo;
        nuevo->sig = NULL;
        mayor = nuevo; //EL PRIMER VALOR SIEMPRE ES EL MAYOR
    } else {
        nuevo->sig = Inicio;
        Inicio = nuevo;
        if (dato > mayor->valor) {
            mayor = nuevo; //SI EL NUEVO VALOR ES MAYOR QUE EL PRIMERO O EL ANTERIOR ACTUALIZA LA VARIABLE
        }
    }

    // REORDENA LA PILA PARA QUE EL MAYOR SEA EL PRIMERO
    if (mayor != Inicio) {
        struct Pila *anterior = NULL;
        struct Pila *actual = Inicio;

        while (actual != mayor) {
            anterior = actual;
            actual = actual->sig;
        }

        anterior->sig = actual->sig; //Elimina el valor más grande de su posición original
        actual->sig = Inicio;
        Inicio = actual;
    }

    /*ORDEN CLASICO DE UNA PILA
    if (Inicio == NULL) {
        Inicio = nuevo;
        nuevo->sig = NULL;
    } else {
        nuevo->sig = Inicio;
        Inicio=nuevo;
    }
    */
    /*ORDENA DE MAYOR A MENOR
    if (vacia() || dato > Inicio->valor) {
        nuevo->sig = Inicio;
        Inicio = nuevo;
    }else{
        struct Pila *temp = Inicio;

        while (temp->sig != NULL && dato <= temp->sig->valor) {
            temp = temp->sig;
        }

        nuevo->sig = temp->sig;
        temp->sig = nuevo;
    }
    */
}

void verPila(){
    struct Pila *recorrido = Inicio;
    printf("Listado de todos los documentos de la pila.\n\n");
    printf("Ordenado de mayor: ");
    while (recorrido != NULL)
    {
        printf("%d -> ",recorrido->valor);

        recorrido = recorrido->sig;
    }
    printf("NULL\n");
    puts("----------------------------------------------");
    system("pause");
}

int main()
{
    int op, op2, op3, dato;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    do{
        system("cls");
        Menu();
        scanf("%d",&op);
        while(op>3 || op<1){
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
                    fflush(stdin);
                    printf("Ingrese un valor: ");
                    scanf("%d",&dato);
                    agregarValor(dato);
                    system("cls");
                    puts("¿Desea agregar otro documento?\n1.Si\n2.No");
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
                }while(op2!=2);
                break;
            case 2:
                system("cls");
                verPila();
                break;
            case 3:
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
    }while(op!=3);

    return 0;
}
