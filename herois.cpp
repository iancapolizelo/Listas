#include "herois.h"

Lista::Lista () //Construtora
{
    topo = nullptr;
    fim = topo;
}

Lista::~Lista () //Destrutora
{
}
void Lista::AdicionaInicio()
{
    node* n = new node; //função new = cria e aloca node
    n->prox = nullptr; //inicializada

    cout << "Insira nome do heroi"<< endl;
    cin.ignore(); //comando pra aceitar nome com espaço
    getline(cin, n->nome, '\n'); //função pra receber linha ao invés de palavra, pra aceitar nome com espaço

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
    ImprimeLista();
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
    ImprimeLista();
}


void Lista::RemoveInicio()
{
    if (topo == nullptr)
    {
        cout << "ERRO: A lista esta vazia!" << endl << endl;
    }
    else
    {
        node *aux = nullptr;
        aux = topo->prox;
        cout << topo->nome << " foi removido com sucesso!" << endl << endl;
        delete topo;
        topo = aux;
        ImprimeLista();
    }

}

void Lista::RemoveFim() //ERRO AQUI: nao ta dando pra deletar fim ou aux->prox
{
    if (topo == nullptr)
    {
        ImprimeLista();
    }
    else if (topo == fim)
    {
        cout << topo->nome << " foi removido com sucesso!" << endl << endl;
        delete topo;
        delete fim;
        topo = nullptr;
        fim = nullptr;
    }
    else
    {
        node *aux;
        aux = topo;
        node *ultimo;
        ultimo = topo;

        while (ultimo->prox != nullptr) //acha o ultimo
        {
            aux = ultimo; //penultimo
            ultimo = ultimo->prox;  //ultimo
        }
        cout << ultimo->nome << " foi removido com sucesso!" << endl << endl;
        delete ultimo; //deleta o ultimo node
        aux->prox = nullptr; //zera o prox do penultimo
        fim = aux; // último = penúltimo

        ImprimeLista();
    }
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
        while (aux != nullptr)
        {
            cout << i << "." << aux->nome << endl;
            i++;
            aux = aux->prox;
        }
    }
    cout << endl;
}


void Lista::MenuPrincipal()
{
    //ADICIONAR MSG ERRO OPCAO INVALIDA (ex: ao invés de numero,
    //usuario inserir letra)
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
