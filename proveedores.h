#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
}eProveedor;

void totalPromediosSuperan(eProducto[],int);
void stockMenorDiez(eProducto[],int);
void listaProductos(eProducto[]);
void listaMenorDiez(eProducto[],int);
void listaPromediosSuperan(eProducto[],int);
void listaProvMenorDiez(eProducto[],eProveedor[]);
void listaPorProvs(eProducto[],eProveedor[]);
void listaPorProv(eProducto[],eProveedor[]);
void listaProvCantidadProductos(eProducto[],eProveedor[],int);

#endif // FUNCIONES_H_INCLUDED
