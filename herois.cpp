#include "herois.h"

Lista::Lista ()
{
    topo = NULL;
    fim = topo;
}

Lista::~Lista ()
{
}
void Lista::AdicionaInicio()
{
    node* n = new node;
    cout << "Insira nome do heroi" << endl;
    cin >> n->nome;

    cout << n->nome << " foi adicionado a lista!\n\n";

    //aloca memoria (novo)

    cout << topo << endl;
    if (topo != nullptr)
    {
        topo = n;

    }
    else
    {
        fim = n;
        topo = n;
        n = nullptr; //acho que tá errado
        cout << " topo nao null\n";
    }
}


void Lista::AdicionaFim()
{
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
    while (aux->prox != nullptr)
    {
        cout << i << "." << aux->nome << endl;
        i++;
        aux = aux->prox;
    }

    if (aux->prox == NULL)
        cout << "A lista esta vazia!\n\n";
}


void Lista::MenuPrincipal() //MUDAR PRA SWITCH
{
    int opc = 10;
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
