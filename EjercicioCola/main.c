#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>

struct Documento{
    char nombre[20];
    int cantidad;

    struct Documento *sig;
};

struct Documento *Inicio = NULL;
struct Documento *Final = NULL;

int vacia()
{
    if (Inicio == NULL)
        return 1;
    else
        return 0;
}

void agregarDocumento(char *nom, int cant){
    struct Documento *nuevo;
    nuevo=malloc(sizeof(struct Documento));
    strcpy(nuevo->nombre, nom);
    nuevo->cantidad = cant;
    nuevo->sig = NULL;

    if(vacia()){
        Inicio = nuevo;
        Final = nuevo;
    }else{
        Final->sig = nuevo;
        Final = nuevo;
    }
}

void verDocumentos(){
    struct Documento *recorrido = Inicio;
    printf("Listado de todos los documentos de la cola.\n\n");
    printf("Proximo a imprimir: ");
    while (recorrido != NULL)
    {
        printf("%s (%d)-> ", recorrido->nombre, recorrido->cantidad);

        recorrido = recorrido->sig;
    }
    printf("NULL\n");
    puts("----------------------------------------------");
    system("pause");
}

void Menu(){
    puts("Menú: \n");
    puts("1. Agregar documento");
    puts("2. Documentos a imprimir");
    puts("3. Salir");
    puts("----------------------------");
    printf("Elegir opción: ");
}

int main()
{
    int op,op2,op3,cant;
    char nom[20];

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
                    printf("Ingrese el nombre del docuemento a imprimir: ");
                    gets(nom);
                    printf("Ingrese la cantidad de '%s' a imprimir: ",nom);
                    scanf("%d",&cant);
                    agregarDocumento(nom,cant);
                    system("cls");
                    puts("¿Desea agregar otro documento?\n1.Si\n2.No");
                    puts("-----------------");
                    printf("Elegir opción: ");
                    scanf("%d",&op2);
                    while(op>2 || op<1){
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
                verDocumentos();
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

    printf("Hello world!\n");
    return 0;
}
