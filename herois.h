#ifndef HEROIS_H
#define HEROIS_H
#include <iostream>
#include <string>
using namespace std;

struct node
{
    string nome; //info
    node *prox; //ponteiro pra struct
};

class Lista
{
private:
    node* topo;
    node* fim;

public:
    void AdicionaInicio();
    void AdicionaFim();
    void RemoveInicio();
    void RemoveFim();
    void ImprimeLista();
    void MenuPrincipal();

    Lista();
    ~Lista();
};




//função pra alocar node

#endif // HEROIS_H
