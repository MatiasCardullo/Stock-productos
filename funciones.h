#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
    int isEmpty;
}eProveedor;

typedef struct{
    int id;
    char descripcion[50];
    float importe;
    int cantidad;
    int proveedor;
    int isEmpty;
} eProducto;

char menu();
char cambiarMenu(eProducto);
void menuInformes(eProducto[]);
void menuListas(eProducto[],eProveedor[]);

void inicializarProductos(eProducto[],int);
int buscarLibre(eProducto[], int);
void altaProducto(eProducto[],eProveedor[],int);
int buscarProducto(eProducto[], int, int);
void mostrarProducto(eProducto);
void mostrarProducto2(eProducto);
void bajaProducto(eProducto[],int);
void modificarProducto(eProducto[],int);

int getId();
void getDescripcion(eProducto[],int,int);
void getImporte(eProducto[],int);
void getCantidad(eProducto[],int);
void getProveedor(eProducto[],eProveedor[],int);

#endif // FUNCIONES_H_INCLUDED
