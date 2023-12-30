#pragma once

struct PG {
    float Sn;
    float An;
    float Ak;
    float k;
    float q;
    float n;
};

enum { SOMA_TERMOS_INFINITO = 1 };

void pg_calcular_soma_termos_infinita();
void pg_calcular_soma_termos_finita();
void pg_calcular_posicao_termo();
void pg_calcular_enesimo_termo();
void pg_calcular_termo_medio();
void pg_calcular_soma_termos();
void pg_calcular_qtd_termos();
void pg_calcular_razao();