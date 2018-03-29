#include "herois.h"

Lista::Lista ()
{
    topo = nullptr;
    fim = topo;
}

Lista::~Lista ()
{
}
void Lista::AdicionaInicio()
{
    node* n = new node;
    n->prox = nullptr; //inicializada

    cout << "Insira nome do heroi"<< endl;
    cin.ignore();
    getline(cin, n->nome, '\n');

    cout << n->nome << " foi adicionado ao inicio da lista!\n\n";

    if (topo == nullptr)
    {
        topo = n;
        fim = n;
    }
    else
    {
        n->prox = topo;
        topo = n;
    }
}


void Lista::AdicionaFim()
{
    node* n = new node;
    n->prox = nullptr; //inicializada

    cout << "Insira nome do heroi"<< endl;
    cin.ignore();
    getline(cin, n->nome, '\n');

    cout << n->nome << " foi adicionado ao fim da lista!\n\n";

    if (topo == nullptr)
    {
        topo = n;
        fim = n;
    }
    else
    {
        fim->prox = n;
        fim = n;
    }
}


void Lista::RemoveInicio()
{

}

void Lista::RemoveFim()
{

}

void Lista::ImprimeLista()
{
    node* aux = topo;

    int i = 1;

    if (topo == nullptr)
    {
        cout << "A lista esta vazia!" << endl << endl;
    }
    else
    {
        /**
        cout << i << "." << aux->nome << endl;//apagar
        i++;//apagar
        aux = aux->prox; //apagar**/


        while (aux != nullptr) //como q eu faço pra imprimir desde o 1º?
        {
            cout << i << "." << aux->nome << endl;
            i++;
            aux = aux->prox;
        }
    }
}


void Lista::MenuPrincipal() //MUDAR PRA SWITCH
{
    int opc;
    bool menu = true;

    while (menu)
    {
        cout << "Escolha uma opcao pra comecar\n" <<
             "1. Adicionar ao inicio da lista\n" <<
             "2. Adicionar ao fim da lista\n" <<
             "3. Remover do inicio da lista\n" <<
             "4. Remover do fim da lista\n" <<
             "5. Imprimir lista\n" <<
             "0. Encerrar e ir pra casa\n\n";

        cin >> opc;

        switch (opc)
        {
        case 1: //coisas
            AdicionaInicio();
            break;
        case 2:
            AdicionaFim();
            break;
        case 3:
            RemoveInicio();
            break;
        case 4:
            RemoveFim();
            break;
        case 5:
            ImprimeLista();
            break;
        case 0:
            cout << "tchau tchau" << endl;
            menu = false;
            break;
        default:
            cout << "ERRO: insira uma opcao valida" << endl;
            break;
        }
    }
}
