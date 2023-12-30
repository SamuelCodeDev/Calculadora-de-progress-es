#pragma once

#include <chrono>
#include <thread>
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

inline void ConfigurarAcentuacaoConsole() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}
#endif

inline void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif 
}

inline void Sleep() {
    sleep_for(milliseconds(2000));
}

void menu();
void menu_pa();
void menu_pg();
void limpar_buffer();
void validar_opcao(int&);
void validar_numero(float&);