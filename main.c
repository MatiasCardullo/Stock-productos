#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#define TAM 100

int main(){
    int salir = 0;system("color 0a");
    system("title ABM Productos");
    eProducto stock[TAM];
    eProveedor prov[]={ 1, "Coto", 0, 2, "Dia", 0, 3, "Walmart", 0, 4, "Carfour", 0};
    inicializarProductos(stock,TAM);
    //eProducto stock[]={1,"Mayonesa",56,200,1,0,2,"Ketchup",45,200,4,0,3,"Lego City",120,8,3,0,4,"Canicas",1.5,100,1,0};
    while(salir != 1){
        switch(menu()){
        case '1':
            altaProducto(stock,prov,TAM);
            system("pause");
            break;
        case '2':
            bajaProducto(stock,TAM);
            system("pause");
            break;
        case '3':
            modificarProducto(stock,TAM);
            system("pause");
            break;
        case '4':
            menuInformes(stock);
            break;
        case '5':
            menuListas(stock,prov);
            break;
        case 27:
            salir = 1;
            break;
        }
    }
    return 0;
}

