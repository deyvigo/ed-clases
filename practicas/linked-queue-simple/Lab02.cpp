#include <iostream>
#include <cstdlib>
#include <time.h>


struct nodo
{
    int dato;
    struct nodo *siguiente;
};

using namespace std;
typedef struct nodo *Lista;

// definiciones de funcion
int generarRandom();
void insertarInicio(Lista &, int);
void insertarFinal(Lista &, int);
void mostrar(Lista);
void menu(Lista &);
void insertar(Lista &);
void buscarMayor(Lista);
void buscarMenor(Lista);
void promedio(Lista);

int main()
{
    Lista inicio = NULL;
    
    int opcion = 0;
    do
    {
        cout << "Que desea hacer: \n1. Agregar un dato.\n2. Mostrar.\n3. mostrar mayor y menor. \n 4.Salir\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            insertar(inicio);
            mostrar(inicio);
            break;
        case 2:
            mostrar(inicio);
            break;
        case 3:
        	buscarMayor(inicio);
        	buscarMenor(inicio);
			break;
        }
    } while (opcion == 1 || opcion ==  2  || opcion == 3);

    return 0;
}

void insertarInicio(Lista &lista, int dato)
{
    Lista tmp = new (struct nodo);
    tmp->dato = dato;
    tmp->siguiente = lista;
    lista = tmp;
}

void insertarFinal(Lista &lista, int dato)
{
    Lista tmp = new (struct nodo);
    Lista final = lista;
    tmp->dato = dato;
    tmp->siguiente = NULL;
    while (final->siguiente != NULL)
    {
        final = final->siguiente;
    }
    final->siguiente = tmp;
}

void mostrar(Lista lista)
{
    int index = 0;
    cout << "-----------------------------" << endl;
    while (lista != NULL)
    {
        cout << index + 1 << ": " << lista->dato << endl;
        lista = lista->siguiente;
        index++;
    }
    cout << "-----------------------------" << endl;
}

int generarRandom()
{
    int ran;
    srand(time(NULL));
    do
    {
        ran = -200 + rand() % 401;
    } while (ran == 0);
    return ran;
}

void insertar(Lista &l)
{
    int ran = generarRandom();
    if (l == NULL) {
    	l = new (struct nodo);
    	l->dato	= ran;
    	l->siguiente = NULL;
	} else {
		if (ran > 0)
    	{
        	insertarFinal(l, ran);
	    }
	    else
	    {
	        insertarInicio(l, ran);
	    }	
	}
    
}

void buscarMayor(Lista l){
	int mayor = l->dato;
	int i = 0;
	int pos = 0;
	while (l != NULL){
		if(l->dato >= mayor){
			mayor = l->dato;
			pos = i;
		}
		l = l->siguiente;
		i++;
	}
	cout<< pos + 1<< " || " <<mayor<<endl;
}


void buscarMenor(Lista l){
	int menor = l->dato;
	int i = 0;
	int pos = 0;
	while (l != NULL){
		if(l->dato <= menor){
			menor = l->dato;
			pos = i;
		}
		l = l->siguiente;
		i++;
	}
	cout<< pos + 1<< " || " <<menor<<endl;
}

