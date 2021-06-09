#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"

using namespace std;

class LinkedList{
        int size;
        Nodo* head;
        Nodo* end;
    public:
    //Constructor
        LinkedList(int _size=0, Nodo * _head=NULL, Nodo* _end=NULL):size(_size),head(_head),end(_end){}
    //Metodos
        void setHead(Nodo*);
        Nodo* getHead();
        Nodo* getEnd();
        void insert(Nodo*);
        void search(int);
        void remove(int);
        void print();
        void insertar(Nodo*);
        
//Sobrecarga del operador <<
        friend ostream& operator<<(ostream &salida,const LinkedList &list){
            Nodo *aux=list.head;
            while(aux!=NULL){
                salida<<aux->getElem()<<" ";
                aux=aux->getNext();
            }
     
            return salida;
        }
   
    //Destructor
        ~LinkedList();
};

void LinkedList::setHead(Nodo*_head){
    head=_head;
}

Nodo* LinkedList::getHead(){
    return head;
}

Nodo* LinkedList::getEnd(){
    Nodo* end=head;
    while(end->getNext()!=NULL){
        end=end->getNext();
    }
    return end;
}

void LinkedList::insert(Nodo* nuevo){
    if(size==0)
    setHead(nuevo);
    else{
        size=size+1;
        getEnd()->setNext(nuevo);
    } 
}

void LinkedList::search(int numero){
    Nodo* buscar=head;
    
    while(buscar!=NULL&buscar->getElem()!=numero)
    buscar=buscar->getNext();

    if(buscar->getElem()==numero)
    cout<<"\nTrue\n";
    else
    cout<<"\nFalse\n";    
}

void LinkedList::remove(int numero){
    Nodo* buscar=head;
    Nodo* anterior=NULL;

    if(buscar->getElem()==numero)
    setHead(head->getNext());
    else{
        while(buscar!=NULL&buscar->getElem()!=numero){
            anterior=buscar;
            buscar=buscar->getNext();
        }
        if(buscar!=NULL){
            anterior->setNext(buscar->getNext());
            size=size-1;
        }
    }
delete buscar;
}

void LinkedList::print(){
    Nodo* aux=head;
    while(aux!=NULL){
    cout<<aux->getElem()<<" ";
    aux=aux->getNext();
    }
}

void LinkedList::insertar(Nodo *nuevo){
    if(head==NULL||nuevo->getElem()<head->getElem()){
        nuevo->setNext(head);
        head=nuevo;
    }
    else{
        Nodo*busca=head;
        while(busca->getNext()!=NULL&&busca->getNext()->getElem()<nuevo->getElem()){
            busca=busca->getNext();
        }
        if(busca->getNext()!=NULL){
            nuevo->setNext(busca->getNext());
        }
        busca->setNext(nuevo);
    }
}

LinkedList::~LinkedList(){ 
    while(head!=NULL){
        Nodo* aux=head;
        delete head;
        head=aux->getNext();
    }
    delete &head;
}
#endif