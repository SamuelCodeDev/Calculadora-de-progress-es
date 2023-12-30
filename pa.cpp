#include "menu.h"
#include "pa.h"
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

void pa_calcular_razao() {
    cout << "======== Calcular a razão ========\n\n";
    cout << "1) r = (An - Ak) / (n - k)\n";
    cout << "2) r = (2 * (An * n - Sn)) / -(n * (1 - n))\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    LimparTela();
    PA pa;

    if(opcao == 1) {
        cout << "Informe o termo inicial (Ak): ";
        cin >> pa.Ak;
        validar_numero(pa.Ak);

        cout << "Informe a posição do termo inicial (k): ";
        cin >> pa.k;
        validar_numero(pa.k);

        cout << "Informe o termo desejado (An): ";
        cin >> pa.An;
        validar_numero(pa.An);

        cout << "Informe a posição do termo desejado (n): ";
        cin >> pa.n;
        validar_numero(pa.n);

        if (pa.n - pa.k != 0) {
            pa.r = (pa.An - pa.Ak) / (pa.n - pa.k);
            cout << "A razão da PA é igual a " << pa.r << '\n';
        } else {
            cout << "O termo inicial (k) não pode ser igual ao termo desejado (n)\n";
        }
        
        Sleep();
        return;
    }

    cout << "Informe o termo desejado (An): ";
    cin >> pa.An;
    validar_numero(pa.An);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> pa.n;
    validar_numero(pa.n);

    cout << "Informe a soma dos termos (Sn): ";
    cin >> pa.Sn;
    validar_numero(pa.Sn);

    if ( (pa.n * ( 1 - pa.n )) != 0) {
        pa.r = -( 2 * ( pa.n * pa.An - pa.Sn ) ) / ( pa.n * ( 1 - pa.n ) );
        cout << "A razão da PA é igual a " << pa.r << '\n';
    } else {
        cout << "A posição do termo (n) não pode ser igual a 1 ou 0\n";
    }

    Sleep();
}

void pa_calcular_enesimo_termo() {
    cout << "======== Calcular a razão ========\n\n";
    cout << "1) An = Ak + (n - k)r;\n";
    cout << "2) An = (2 * Sn + n ^ 2 * r - n * r) / 2n\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    PA pa;
    LimparTela();
    if(opcao == 1) {
        cout << "Informe o termo inicial (Ak): ";
        cin >> pa.Ak;
        validar_numero(pa.Ak);

        cout << "Informe a posição do termo inicial (k): ";
        cin >> pa.k;
        validar_numero(pa.k);

        cout << "Informe a posição do termo desejado (n): ";
        cin >> pa.n;
        validar_numero(pa.n);

        cout << "Informe a razão da PA: ";
        cin >> pa.r;
        validar_numero(pa.r);

        pa.An = pa.Ak + ( pa.n - pa.k ) * pa.r;
        cout << "O " << pa.n << "° termo da PA é igual a " << pa.An << '\n';
        Sleep();
        return;
    }

    cout << "Informe a soma dos termos (Sn): ";
    cin >> pa.Sn;
    validar_numero(pa.Sn);

    cout << "Informe a razão da PA: ";
    cin >> pa.r;
    validar_numero(pa.r);

    cout << "Informe a posição do termo desejado (n): ";
    cin >> pa.n;
    validar_numero(pa.n);

    pa.An = (2 * ( pa.Sn + ( pow(pa.n, 2) * pa.r ) - pa.n * pa.r) ) / (2 * pa.n);
    cout << "O " << pa.n << "° termo da PA é igual a " << pa.An << '\n';
    Sleep();
}

void pa_calcular_qtd_termos() {
    PA pa;
    cout << "Informe o termo inicial (Ak): ";
    cin >> pa.Ak;
    validar_numero(pa.Ak);

    cout << "Informe a posição do termo inicial (k): ";
    cin >> pa.k;
    validar_numero(pa.k);

    cout << "Informe a razão da PA: ";
    cin >> pa.r;
    validar_numero(pa.r);

    cout << "Informe o termo desejado (An): ";
    cin >> pa.An;
    validar_numero(pa.An);

    if(pa.r + pa.k != 0) {
        pa.n = (pa.An - pa.Ak) / (pa.r + pa.k);
        cout << "A quantidade de termos da PA é igual a " << pa.n << '\n';
    } else {
        cout << "Não pode divisão por zero!\n";
    }

    Sleep();
}

void pa_calcular_soma_termos() {
    PA pa;
    LimparTela();
    cout << "======== Soma dos termos ========\n\n";
    cout << "1) Sn = [(A1 + An) * n] / 2\n";
    cout << "2) Sn = {n * [2 * A1 + (n - 1) * r]} / 2\n\n";
    cout << "Sua opção: ";
    int opcao;
    cin >> opcao;
    while(cin.fail() || opcao < 1 || opcao > 2) {
        cout << "Digite um opção válida: ";
        limpar_buffer();
        cin >> opcao;
    }

    LimparTela();
    if(opcao == 1) {
        cout << "Informe o termo desejado (An): ";
        cin >> pa.An;
        validar_numero(pa.An);

        cout << "Informe a posição do termo desejado (n): ";
        cin >> pa.n;
        validar_numero(pa.n);

        cout << "Informa o A1: ";
        cin >> pa.Ak;
        validar_numero(pa.Ak);

        pa.Sn = ( ( pa.Ak + pa.An ) * pa.n ) / 2;
        cout << "A soma dos termos da PA é igual a " << pa.Sn << '\n';
        Sleep();
        return;
    }

    cout << "Informe a posição do termo desejado (n): ";
    cin >> pa.n;
    validar_numero(pa.n);

    cout << "Informe a razão da PA: ";
    cin >> pa.r;
    validar_numero(pa.r);

    cout << "Informa o A1: ";
    cin >> pa.Ak;
    validar_numero(pa.Ak);

    pa.Sn = ( pa.n * ( 2 * pa.Ak + ( pa.n - 1 ) * pa.r) ) / 2;
    cout << "A soma dos termos da PA é igual a " << pa.Sn << '\n';
    Sleep();
}

void pa_calcular_termo_medio() {
    PA pa;
    cout << "Informe o termo inicial (Ak): ";
    cin >> pa.Ak;
    validar_numero(pa.Ak);

    cout << "Informe o termo desejado (An): ";
    cin >> pa.An;
    validar_numero(pa.An);

    float am = (pa.An + pa.Ak) / 2;
    cout << "O termo médio dessa PA é igual a " << am << '\n';
    Sleep();
}

void pa_calcular_posicao_termo() {
    PA pa;
    cout << "Informe o termo inicial (Ak): ";
    cin >> pa.Ak;
    validar_numero(pa.Ak);

    cout << "Informe o termo desejado (An): ";
    cin >> pa.An;
    validar_numero(pa.An);

    cout << "Informe a razão da PA: ";
    cin >> pa.r;
    validar_numero(pa.r);

    if(pa.r != 0) {
        pa.n = (pa.An - pa.Ak + pa.r) / pa.r;
        cout << "O número " << pa.An << " ocupa a " << pa.n << "° posição\n";
    } else {
        cout << "A razão não pode ser igual a zero.\n";
    }

    Sleep();
}