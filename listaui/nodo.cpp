#include "nodo.h"

nodo::nodo()
{
    sig=NULL;
    dato="\0";
}

nodo::nodo(string dato): dato(dato),sig(NULL){

}
