#include <iostream>
#include "Nodo.h"
#include "LinkedList.h"

using namespace std;

int main() {

    Nodo a(1);
    Nodo b(5);
    Nodo c(2);

    a.setNext(&b);

    LinkedList lista(2,&a);

    cout<<lista<<endl;

    lista.insertar(&c);

    cout<<lista<<endl;

    lista.remove(2);

    cout<<lista<<endl;

    lista.~LinkedList();

    cout<<lista;

    return 0;
}
