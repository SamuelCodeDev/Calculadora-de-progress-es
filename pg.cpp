#include "menu.h"
#include "pg.h"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

void pg_calcular_razao() {
    PG pg;

    cout << "Informe o termo inicial (Ak): ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> pg.k;
    validar_numero(pg.k);

    cout << "Informe o An: ";
    cin >> pg.An;
    validar_numero(pg.An);

    cout << "Informe a posição do An (n): ";
    cin >> pg.n;
    validar_numero(pg.n);

    pg.q = pow( ( pg.An / pg.Ak ), 1 / ( pg.n - pg.k ) );
    cout << "A razão é igual a " << pg.q << '\n';
    Sleep();  
}

void pg_calcular_enesimo_termo() {
    PG pg;

    cout << "Informe o termo inicial (Ak): ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> pg.k;
    validar_numero(pg.k);

    cout << "Informe a razão da PG: ";
    cin >> pg.q;
    validar_numero(pg.q);

    cout << "Informe a posição do An (n): ";
    cin >> pg.n;
    validar_numero(pg.n);

    pg.An = pg.Ak * pow( pg.q, pg.n - pg.k );
    cout << "O An é igual a " << pg.An << '\n';
    Sleep();
}

void pg_calcular_termo_medio() {
    PG pg;

    cout << "Informa o A1: ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe o An: ";
    cin >> pg.An;
    validar_numero(pg.An);

    float am = pow( pg.Ak * pg.An, 0.5 );
    cout << "O termo médio da PG é igual a " << am << '\n';
    Sleep();
}

void pg_calcular_soma_termos() {
    PG pg;

    LimparTela();
    cout << "======== Menu soma dos termos========\n\n";
    cout << "1) Calcular soma dos termos infinito\n";
    cout << "2) Calcular soma dos termos finito\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    if(opcao == SOMA_TERMOS_INFINITO) {
        pg_calcular_soma_termos_infinita();
    } else {
        pg_calcular_soma_termos_finita();
    }
}

void pg_calcular_soma_termos_infinita() {
    PG pg;

    cout << "Informa o A1: ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe a razão da PG: ";
    cin >> pg.q;
    validar_numero(pg.q);

    if((1 - pg.q) != 0) {
        pg.Sn = pg.Ak / (1 - pg.q);
        cout << "A soma dos termos da PG é igual a " << pg.Sn << '\n';
    } else {
        cout << "A razão da pg não pode ser igual a zero\n";
    }

    Sleep();
}

void pg_calcular_soma_termos_finita() {
    LimparTela();
    cout << "======== Soma dos termos ========\n\n";
    cout << "1) Sn = (A1 * (q ^ n - 1)) / q - 1\n";
    cout << "2) Sn = (A1 * (1 - q ^ n)) / 1 - q\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    PG pg;
    LimparTela();
    if(opcao == 1) {
        cout << "Informa o A1: ";
        cin >> pg.Ak;
        validar_numero(pg.Ak);

        cout << "Informe a razão da PG: ";
        cin >> pg.q;
        validar_numero(pg.q);

        cout << "Informe a posição do termo desejado (n): ";
        cin >> pg.n;
        validar_numero(pg.n);

        if((1 - pg.q) != 0) {
            pg.Sn = pg.Ak * ( pow( pg.q, pg.n - 1) ) / pg.q - 1;
            cout << "A soma dos termos da PG é igual a " << pg.Sn << '\n';
        } else {
            cout << "A razão não pode ser igual a um\n";
        }

        Sleep();        
        return;
    }

    cout << "Informa o A1: ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe a razão da PG: ";
    cin >> pg.q;
    validar_numero(pg.q);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> pg.n;
    validar_numero(pg.n);

    if((1 - pg.q) != 0) {
        pg.Sn = ( pg.Ak * ( 1 - pow( pg.q, pg.n ) ) ) / ( 1 - pg.q );
        cout << "A soma dos termos da PG é igual a " << pg.Sn << '\n';
    } else {
        cout << "A razão da PG não pode ser igual a um\n";
    }

    Sleep();
}

void pg_calcular_qtd_termos() {
    PG pg;

    cout << "Informa o A1: ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe a razão da PG: ";
    cin >> pg.q;
    validar_numero(pg.q);

    cout << "Informe o número de termos (n): ";
    cin >> pg.n;
    validar_numero(pg.n);

    cout << "Digite a  soma dos primeiros termos (Sn): ";
    cin >> pg.Sn;
    validar_numero(pg.Sn);

    if(pg.q != 0) {
        pg.n = log( ( pg.Sn * ( pg.q - 1 ) ) / pg.Ak + 1 ) / log( pg.q );
        cout << "A quantidade de termos da PA é igual a " << pg.n << '\n';
    } else {
        cout << "A razão da PG não pode ser igual a zero\n";
    }

    Sleep();
}

void pg_calcular_posicao_termo() {
    PG pg;

    cout << "Informe a posição do termo inicial (k): ";
    cin >> pg.k;
    validar_numero(pg.k);

    cout << "Informe o termo inicial (Ak): ";
    cin >> pg.Ak;
    validar_numero(pg.Ak);

    cout << "Informe o termo desejado (An): ";
    cin >> pg.An;
    validar_numero(pg.An);

    cout << "Informe a razão da PG: ";
    cin >> pg.q;
    validar_numero(pg.q);

    if(pg.q != 0) {
        pg.n = pg.k + ( log( pg.An / pg.Ak ) / log( pg.q ) );
        cout << "A quantidade de termos da PG é igual a " << pg.n << '\n';
    } else {
        cout << "A razão da PG não pode ser igual a zero\n";
    }

    Sleep();
}