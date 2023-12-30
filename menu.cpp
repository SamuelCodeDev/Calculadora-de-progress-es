#include "menu.h"
#include "enum.h"
#include "pa.h"
#include "pg.h"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::streamsize;
using std::numeric_limits;

inline void limpar_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void validar_opcao(int & opcao) {
    while(opcao < 1 || opcao > 3 || cin.fail()) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }
}

void validar_numero(float & num) {
    while (cin.fail()) {
        cout << "Erro: Por favor, digite apenas números. Tente novamente: ";
        limpar_buffer();
        cin >> num;
    }
}

void menu() {
    LimparTela();
    cout << "==========================================\n";
    cout << "\tCalculadora de progressões\n";
    cout << "==========================================\n\n";
    cout << "1) PA\n";
    cout << "2) PG\n";
    cout << "3) Sair\n\n";
    cout << "Sua opção: ";
}

void menu_pa() {
    cout << "==========================\n";
    cout << "\tMenu da PA\n";
    cout << "==========================\n\n";
    cout << "1) Calcular a razão\n";
    cout << "2) Calcular o enésimo termo\n";
    cout << "3) Calcular a quantidade de termos\n";
    cout << "4) Calcular a soma dos termos\n";
    cout << "5) Calcular o termo médio\n";
    cout << "6) Calcular a posição do termo\n";
    cout << "7) Sair\n\n";
    cout << "Sua opção: ";
    
    int operacao;
    cin >> operacao;
    while(operacao < 1 || operacao > 7 || cin.fail()) {
        cout << "Opção inválida. Tente novamente: ";
        limpar_buffer();
        cin >> operacao;
    }

    LimparTela();
    switch (operacao) {
        case RAZAO:
            pa_calcular_razao();    
            break;
        case ENESIMO_TERMO:
            pa_calcular_enesimo_termo();    
            break;
        case QTD_TERMO:
            pa_calcular_qtd_termos();    
            break;
        case SOMA_TERMOS:
            pa_calcular_soma_termos();
            break;
        case TERMO_MEDIO:
            pa_calcular_termo_medio();
            break;
        case POSICAO_TERMO:
            pa_calcular_posicao_termo();
            break;
        case SAIR:
            return;
    }
    
    Sleep();
}

void menu_pg() {
    cout << "==========================\n";
    cout << "\tMenu da PG\n";
    cout << "==========================\n";
    cout << "1) Calcular a razão\n";
    cout << "2) Calcular o enésimo termo\n";
    cout << "3) Calcular a quantidade de termos\n";
    cout << "4) Calcular a soma dos termos\n";
    cout << "5) Calcular o termo médio\n";
    cout << "6) Calcular a posição do termo\n";
    cout << "7) Sair\n\n";
    cout << "Sua opção: ";

    int operacao;
    cin >> operacao;
    while(operacao < 1 || operacao > 7 || cin.fail()) {
        cout << "Opção inválida. Tente novamente: ";
        limpar_buffer();
        cin >> operacao;
    }

    LimparTela();
    switch (operacao) {
        case RAZAO:
            pg_calcular_razao();    
            break;
        case ENESIMO_TERMO:
            pg_calcular_enesimo_termo();    
            break;
        case QTD_TERMO:
            pg_calcular_qtd_termos();    
            break;
        case SOMA_TERMOS:
            pg_calcular_soma_termos();
            break;
        case TERMO_MEDIO:
            pg_calcular_termo_medio();
            break;
        case POSICAO_TERMO:
            pg_calcular_posicao_termo();
            break;
        case SAIR:
            return;
    }

    Sleep();
}