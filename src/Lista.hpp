#include "Lista.h"

Lista::Lista() {
    _primero = NULL;
    _ultimo = NULL;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    _destructor();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    _destructor();
    Nodo* actual = aCopiar._primero;
    while (actual != nullptr){
        this->agregarAtras(actual->valor);
        actual = actual->siguiente;
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    nuevo->siguiente = _primero;
    if (_primero != nullptr){
        _primero->anterior = nuevo;
    }
    if(_ultimo == nullptr && _primero == nullptr){
        _ultimo = nuevo;
    }
    _primero = nuevo;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    nuevo->anterior = _ultimo;
    if(_ultimo!= nullptr){
        _ultimo->siguiente = nuevo;
    }
    if(_ultimo == nullptr && _primero == nullptr){
        _primero = nuevo;
    }
    _ultimo = nuevo;
}

void Lista::eliminar(Nat i) {
    Nodo* actual = this->_primero;
    for (int j = 0; j < i; ++j) {
        actual = actual->siguiente;
    }
    if(actual->anterior != nullptr){
        actual->anterior->siguiente = actual->siguiente;
    }
    if(actual->siguiente != nullptr){
        if(actual->anterior != nullptr) {
            actual->siguiente->anterior = actual->anterior;
        } else {
            actual->siguiente = NULL;
        }
    }
    if(actual == _ultimo){
        _ultimo = actual->anterior;
    }
    if(actual == _primero){
        _primero = actual->siguiente;
    }
    delete actual;
}

int Lista::longitud() const {
    int res = 0;
    Nodo* actual = this->_primero;
    while (actual != nullptr){
        actual = actual->siguiente;
        res++;
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = this->_primero;
    for (int j = 0; j < i; ++j) {
        actual = actual->siguiente;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* actual = this->_primero;
    for (int j = 0; j < i; ++j) {
        actual = actual->siguiente;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {

}

void Lista::_destructor() {
    Nodo* temp = _primero;
    while (temp != nullptr){
        temp = temp->siguiente;
        if(temp != nullptr){
            delete temp->anterior;
        }
    }
    if (_ultimo != nullptr){
        delete _ultimo;
    }
}
