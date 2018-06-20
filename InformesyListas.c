#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 100

void totalPromediosSuperan(eProducto vec[],int superaPromedio){
    float total=0,promedio=0;
    int contador=0,contador2=0;
    for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
        total=vec[i].importe+total;
        contador++;
        //printf("%f \t %f \n",total,vec[i].importe);
    }
    if(contador!=0)
        {promedio=total/contador;}
    printf(" Total de importes: %f\n\n",total);
    printf(" Promedio de Importes: %f\n\n ",promedio);
    for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
        if(superaPromedio&&vec[i].importe>promedio){
            contador2++;
        }else if(!superaPromedio&&vec[i].importe<=promedio){
            contador2++;
        }
    }
    if(superaPromedio){
        printf("Superan");
    }else{
        printf("No superan");
    }printf(" el promedio %d productos",contador2);
    printf("\n\n ");system("pause");
}

void stockMenorDiez(eProducto vec[],int menor){
    int contador=0;
    printf(" Productos con stock ");
    if(menor){
            printf("menor o igual a diez: ");
    }else{
            printf("mayor a diez: ");
    }
    for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
        if(menor&&vec[i].cantidad<=10){
            contador++;
        }else if(!menor&&vec[i].cantidad>10){
            contador++;
        }
    }printf("%d",contador);
    printf("\n\n ");system("pause");
}

int listarProductos(eProducto vec[],int mostrar){
    eProducto aux;int cont=0;
    for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
        for(int j=i+1;j<TAM&&vec[j].isEmpty!=1;j++){
            if(stricmp(vec[i].descripcion,vec[j].descripcion)>0){
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }if(vec[i].importe<vec[j].importe){
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }cont++;
    }
    if(mostrar){
        printf("\n  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
        for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++)
            {mostrarProducto2(vec[i]);}
        printf("\n ");system("pause");
    }
    return cont;
}

void listaMenorDiez(eProducto vec[],int menor){
    if(menor){
            printf("\n Stock menor o igual a diez:\n");
    }else{
            printf("\n Stock mayor a diez:\n");
    }
    printf("  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
    for(int i=0;i<TAM&&vec[i].isEmpty==0;i++){
        if(menor&&vec[i].cantidad<=10){
            mostrarProducto2(vec[i]);
        }else if(!menor&&vec[i].cantidad>10){
            mostrarProducto2(vec[i]);
        }
    }printf("\n ");system("pause");
}

void listaPromediosSuperan(eProducto vec[],int superaPromedio){
    float total=0,promedio=0;
    int contador=0;
    for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
        total=vec[i].importe+total;
        contador++;
    }
    if(contador!=0)
        {promedio=total/contador;}
    if(superaPromedio){
            printf("\n Productos que superan el promedio:\n");
    }else{
            printf("\n Productos que no superan el promedio:\n");
    }
    printf("  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
    for(int i=0;i<TAM&&vec[i].isEmpty==0;i++){
        if(superaPromedio&&vec[i].importe>promedio){
                mostrarProducto2(vec[i]);
        }else if(!superaPromedio&&vec[i].importe<=promedio){
                mostrarProducto2(vec[i]);
        }
    }printf("\n ");system("pause");
}

void listaProvMenorDiez(eProducto vec[],eProveedor vec2[]){
    int id=0,flag[]={0,0,0,0};
    for(int i=0;i<TAM&&vec[i].isEmpty==0;i++){
        if(vec[i].cantidad<=10){
            if(id==0)
                {printf("\n Proveedores con stock menor o igual a 10:\n ");}
            id=vec[i].proveedor;
            if(id&&!flag[id-1]){
                printf(" ID%d - %s\n ",vec2[id-1].id,vec2[id-1].descripcion);
                flag[id-1]=1;
            }
        }
    }
    if(id==0)
        {printf("\n No hay proveedores con stock menor o igual a 10.\n ");}
    printf("\n ");system("pause");
}

void listaPorProvs(eProducto vec[],eProveedor vec2[]){
    for(int i=0;i<4;i++){
        printf("\n Productos de %s:\n",vec2[i].descripcion);
        printf("  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
        for(int j=0;j<TAM&&vec[j].isEmpty!=1;j++){
            //printf("//");mostrarProducto2(vec[j]);
            if(vec[j].proveedor==vec2[i].id){
                mostrarProducto2(vec[j]);
            }
        }
    }printf("\n ");system("pause");
}

void listaPorProv(eProducto vec[],eProveedor vec2[]){
    int id;
    printf("\n Ingrese Id de proveedor:\n ");
    for(int i=0;i<4;i++){
        if(vec2[i].isEmpty==0){
            printf(" %d-%s\n ",vec2[i].id,vec2[i].descripcion);
        }
    }
    do{
        id=(getch())-48;
    }while(!(id>0&&id<5));
    system("cls");
    printf("\n Productos de %s:\n",vec2[id-1].descripcion);
    printf("  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
    for(int j=0;j<TAM&&vec[j].isEmpty!=1;j++){
        if(vec[j].proveedor==vec2[id-1].id){
            mostrarProducto2(vec[j]);
        }
    }
    printf("\n ");system("pause");
}

void listaProvCantidadProductos(eProducto vec[],eProveedor vec2[],int menos){
    int aux,lleno=0,idProvMenos,idProvMas,counterProv[]={0,0,0,0};
    for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
        aux=vec[i].id-1;
        counterProv[aux]++;
        lleno=1;
    }aux=0;
    for(int i=0;i<4;i++){
        if(aux<counterProv[i]){
            aux=counterProv[i];
            idProvMas=i;
        }
    }for(int i=0;i<4;i++){
        if(aux>counterProv[i]){
            aux=counterProv[i];
            idProvMenos=i;
        }
    }
    if(lleno){
        if(menos){
            printf("\n El proveedor que provee menos productos es %s\n",vec2[idProvMenos].descripcion);
            printf("\n Productos de %s:\n",vec2[idProvMenos].descripcion);
            printf("  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
            for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
                if(vec[i].proveedor==vec2[idProvMenos].id){
                    mostrarProducto2(vec[i]);
                }
            }
        }else{
            printf("\n El proveedor que provee mas productos es %s\n",vec2[idProvMas].descripcion);
            printf("\n Productos de %s:\n",vec2[idProvMas].descripcion);
            printf("  | Id |                     Descripcion                     |  Importe  | Cantidad |\n");
            for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
                if(vec[i].proveedor==vec2[idProvMas].id){
                    mostrarProducto2(vec[i]);
                }
            }
        }
    }else{printf("\n No hay productos\n");}
    printf("\n ");system("pause");
}

void proveedorProductoMaxMin(eProducto vec[],eProveedor vec2[],int precio){
    int cont=listarProductos(vec,0);
    if(cont==0)
        {printf("\n No hay productos\n");}
    else{
        int aux=0,idmax=0,idmin=0;
        for(int i=0;i<TAM&&vec[i].isEmpty!=1;i++){
            if(i==0&&precio){
                idmax=vec[i].proveedor-1;
                printf("\n El producto mas caro\n");
                printf("_____________________________________________________________________________________\n");
                printf(" %d-%s:\n ",vec2[idmax].id,vec2[idmax].descripcion);
                mostrarProducto(vec[i]);
            }
            aux=i;
        }
        if(aux!=0&&!precio){
            idmin=vec[aux].proveedor-1;
            printf("\n El producto mas barato\n");
            printf("_____________________________________________________________________________________\n");
            printf(" %d-Producto de %s:\n ",vec2[idmin].id,vec2[idmin].descripcion);
            mostrarProducto(vec[aux]);
        }
    }printf("\n ");system("pause");
}

