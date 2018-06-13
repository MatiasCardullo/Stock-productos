#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#include "proveedores.h"

char menu(){
    char opcion;
    system("mode con cols=30 lines=15");
    printf("______________________________\n");
    printf("   1 - Alta\n");
    printf("   2 - Baja\n");
    printf("   3 - Modificar\n");
    printf("   4 - Informes\n");
    printf("   5 - Listas\n");
    printf("______________________________\n");
    printf("       ESC para salir");
    do{
        fflush(stdin);
        opcion=getch();
    }while(opcion!=27&&!(opcion>'0'&&opcion<'6'));
    return opcion;
}

void inicializarProductos(eProducto vec[], int tam){
    for(int i=0; i< tam; i++){
        vec[i].isEmpty =1;
    }
}//recorre el vector de eProducto y los marca como vacios

int buscarLibre(eProducto vec[], int tam){
    int indice = -1;
    for(int i=0; i < tam; i++){
        if(vec[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}//busca lugares libres en eProducto

int buscarProducto(eProducto vec[], int tam, int id){
    int indice = -1;
    for(int i=0; i < tam; i++){
        if(vec[i].isEmpty == 0 && vec[i].id == id){
            indice = i;
            break;
        }
    }
    return indice;
}//busca en eProductos y verifica si el id ya existe o si esta pero lleno

void mostrarProducto(eProducto stck){
    printf(" Id: %d   Descripcion: %s   Importe: %.2f   Cantidad: %d\n", stck.id, stck.descripcion, stck.importe, stck.cantidad);
}//muestra X Producto

void mostrarProducto2(eProducto stck){
    printf("  | %2d | %50s  | %7.2f | %8d |\n", stck.id, stck.descripcion, stck.importe, stck.cantidad);
}//muestra X Producto

void altaProducto(eProducto vec[],eProveedor vec2[], int tam){
    int indice;
    int esta;
    int id;
    system("mode con cols=80 lines=20");
    printf("________________________________________________________________________________\n");
    printf("\tAlta Producto\n\n");
    indice = buscarLibre(vec, tam);
    if(indice == -1){
        printf("\n El sistema esta completo. No se puede dar de alta a Productos nuevos.\n\n");
    }else{
        for(int i=1;i<tam;i++){
            id=i;
            esta = buscarProducto(vec, tam, id);
            if(esta == -1){break;}
        }
        vec[indice].isEmpty = 0;
        vec[indice].id = id;
        getDescripcion(vec,indice,51);
        getImporte(vec,indice);
        getCantidad(vec,indice);
        getProveedor(vec,vec2,indice);
        printf("\n Alta exitosa!!!\n\n");
    }
}

void bajaProducto(eProducto vec[],int tam){
    int id,esta;char confirma;
    system("mode con cols=80 lines=20");
    printf("________________________________________________________________________________\n");
    printf("\tBaja Producto\n\n");
    id=getId();
    esta = buscarProducto(vec, tam, id);
    if(esta == -1){
        printf("\nEl id %d no se encuentra en el sistema\n\n", id);
    }else{
        printf("\n");
        mostrarProducto(vec[esta]);
        printf("\n Confirma baja? (s/n) ");
        fflush(stdin);
        confirma=getch();
        if(confirma=='s'||confirma=='S'){
            vec[esta].isEmpty = 1;
            printf("\n Se ha realizado la baja\n\n");
        }else{
            printf("\n Se ha cancelado la baja\n\n");
        }
    }
}

void modificarProducto(eProducto vec[], int tam){
    int id,esta,cambio=0;
    system("mode con cols=41 lines=20");
    printf("_________________________________________\n");
    printf("\t    Modificar Producto\n\n");
    id=getId();
    esta = buscarProducto(vec, tam, id);
    if(esta == -1){
        printf("\n El id %d no se encuentra en el sistema\n\n ", id);
    }else{
        system("mode con cols=80 lines=20");
        int seguir=1;
        while(seguir){
            switch(cambiarMenu(vec[esta])){
                case '1':
                    getDescripcion(vec,esta,51);
                    cambio=1;break;
                case '2':
                    getImporte(vec,esta);
                    cambio=1;break;
                case '3':
                    getCantidad(vec,esta);
                    cambio=1;break;
                case 27:
                    if(cambio){
                        printf("\n Modificacion exitosa!!!\n");
                    }seguir=0;printf("\n ");break;
            }
        }
    }
}

/*void mostrarProductos(eProducto vec[], int tam){
    system("cls");
    system("mode con cols=100 lines=20");
    printf("____________________________________________________________________________________________________\n");
    printf("\tLista de Productos\n\n");
    printf(" id  Apellido                   Nombre                   Sexo  Sueldo          Fecha de Ingreso \n\n");
    for(int i=0; i< tam; i++){
        if(vec[i].isEmpty == 0){
            //mostrarProducto2(vec[i]);
        }
    }
}*/

char cambiarMenu(eProducto producto){
    char opcion;
    system("cls");
    printf("________________________________________________________________________________\n");
    mostrarProducto(producto);
    printf("________________________________________________________________________________\n");
    printf("   1-Modificar descripcion\n");
    printf("   2-Modificar importe\n");
    printf("   3-Modificar cantidad\n");
    printf("________________________________________________________________________________\n");
    do{
        fflush(stdin);
        opcion=getch();
    }while(opcion!=27&&!(opcion>'0'&&opcion<'4'));
    printf("\n");return opcion;
}

void menuInformes(eProducto vec[]){
    char opcion;
    do{
        system("mode con cols=80 lines=20");
        printf("________________________________________________________________________________\n");
        printf("   1-Total y Promedios de Importes y cuantos productos superan el promedio\n");
        printf("   2-Total y Promedios de Importes y cuantos productos no superan el promedio\n");
        printf("   3-Productos con stock menor o igual a 10\n");
        printf("   4-Productos con stock mayor a 10\n");
        printf("________________________________________________________________________________\n");
        do{
            fflush(stdin);
            opcion=getch();
        }while(opcion!=27&&!(opcion>'0'&&opcion<'5'));
        switch(opcion){
            case '1':
                totalPromediosSuperan(vec,1);
                break;
            case '2':
                totalPromediosSuperan(vec,0);
                break;
            case '3':
                stockMenorDiez(vec,1);
                break;
            case '4':
                stockMenorDiez(vec,0);
                break;
        }
    }while(opcion!=27);
}

void menuListas(eProducto vec[],eProveedor vec2[]){
    char opcion;
    do{
        system("mode con cols=85 lines=31");
        printf("\n\t\t\t\tMenu de listados\n");
        printf("_____________________________________________________________________________________\n");
        printf("   A-Listado de todos los productos\n\n");
        printf("   B-Todos los productos con stock menor o igual a 10\n\n");
        printf("   C-Todos los productos con stock mayor a 10\n\n");
        printf("   D-Todos los productos que superan el promedio de importes\n\n");
        printf("   E-Todos los productos que no superan el promedio de importes\n\n");
        printf("   F-Todos los proveedores cuyo stock de productos es menor o igual a 10\n\n");
        printf("   G-Todos los productos provistos por cada proveedor\n\n");
        printf("   H-Todos los productos provistos por un proveedor determinado\n\n");
        printf("   I-El proveedor que provee mas productos\n\n");//mostrando los productos
        printf("   J-El proveedor que provee menos productos\n\n");//mostrando los productos
        printf("   K-El proveedor que provee el producto mas caro\n\n");//mostrando el producto
        printf("   L-El proveedor que provee el producto menos caro\n");//mostrando el producto
        printf("_____________________________________________________________________________________\n");
        do {
            fflush(stdin);
            opcion=getch();
        }while(opcion!=27&&!(opcion>='A'&&opcion<='L')&&!(opcion>='a'&&opcion<='l'));
        system("mode con cols=85 lines=55");
        switch(opcion){
            case 'a':case 'A':
                listaProductos(vec);
                break;
            case 'b':case 'B':
                listaMenorDiez(vec,1);
                break;
            case 'c':case 'C':
                listaMenorDiez(vec,0);
                break;
            case 'd':case 'D':
                listaPromediosSuperan(vec,1);
                break;
            case 'e':case 'E':
                listaPromediosSuperan(vec,0);
                break;
            case 'f':case 'F':
                listaProvMenorDiez(vec,vec2);
                break;
            case 'g':case 'G':
                listaPorProvs(vec,vec2);
                break;
            case 'h':case 'H':
                listaPorProv(vec,vec2);
                break;
            case 'i':case 'I':
                listaProvCantidadProductos(vec,vec2,0);
                break;
            case 'j':case 'J':
                listaProvCantidadProductos(vec,vec2,1);
                break;
            case 'k':case 'K':

                break;
            case 'l':case 'L':

                break;
        }
    }while(opcion!=27);
}

int getId(){
    printf(" Ingrese id: ");
    int id;char aux[5];
    while(1){
        fflush(stdin);gets(aux);
        id=atoi(aux);
        if(id>0){break;}
        else{printf(" Id Invalido. Ingrese id: ");}
    }return id;
}

void getDescripcion(eProducto vec[],int indice,int tam){
    printf(" Ingrese descripcion: ");
    char aux[300];
    while(1){
        fflush(stdin);gets(aux);
        if(strlen(aux)!=0){
            if(strlen(aux)<=tam){
                strcpy(vec[indice].descripcion,aux);
                break;
            }else{
                printf(" Error, descripcion muy larga. Ingrese descripcion: ");
            }
        }
    }
}

void getImporte(eProducto vec[],int indice){
    printf(" Ingrese importe: ");
    char aux[50];float importe;
    while(1){
        fflush(stdin);gets(aux);
        importe=atof(aux);
        if(importe>0){
            vec[indice].importe=importe;
            break;
        }else{
            printf(" Importe no valido. Ingrese importe: ");
        }
    }
}

void getCantidad(eProducto vec[],int indice){
    printf(" Ingrese cantidad: ");
    char aux[50];int cantidad;
    while(1){
        fflush(stdin);gets(aux);
        cantidad=atoi(aux);
        if(cantidad>0){
            vec[indice].cantidad=cantidad;
            break;
        }else{
            printf(" Cantidad no valida. Ingrese cantidad: ");
        }
    }
}

void getProveedor(eProducto vec[],eProveedor vec2[],int indice){
    printf(" Ingrese Id de proveedor:\n ");
    for(int i=0;i<4;i++){
        if(vec2[i].isEmpty==0){
            printf("%d-%s\n ",vec2[i].id,vec2[i].descripcion);
        }
    }
    char aux[2];int id;
    while(1){
        fflush(stdin);
        aux[0]=getch();
        id=atoi(aux);
        if(id<5&&id>0){
            vec[indice].proveedor=id;
            break;
        }else{
            printf("\n Id invalido. Ingrese Id de proveedor: ");
        }
    }
}

