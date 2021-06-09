#ifndef __NODO_H__
#define __NODO_H__

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo {
        int elem;
        Nodo* next;
    public:
    //Constructor
        Nodo(int _elem=0, Nodo * _next=NULL):elem(_elem),next(_next){}

    //Setters
        void setElem(int elem){
            this->elem = elem;
        }

        void setNext(Nodo *next){
            this->next=next;
        }
    //Getters
        int getElem();
        Nodo* getNext();

        void print();

        friend ostream& operator<<(ostream &salida,const Nodo &n){
            salida<<"\n"<<n.elem<<"->";
            if(n.next==NULL)
            salida<<"NULL\n";
            else
            salida<<n.next->elem;
            return salida;
        }
};

int Nodo::getElem(){
    return elem;   
}

Nodo *Nodo::getNext(){
    return next;   
}

void Nodo::print(){
    if(next==NULL){
        std::cout<<elem<<"->NULL"<<std::endl;
    }
    else
    std::cout<<elem<<"->"<<next->getElem()<<std::endl;
}

#endif