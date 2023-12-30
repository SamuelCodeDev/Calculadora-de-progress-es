#pragma once

struct PA {
    float Sn;
    float An;
    float Ak;
    float n;
    float k;
    float r;
};

void pa_calcular_posicao_termo();
void pa_calcular_enesimo_termo();
void pa_calcular_soma_termos();
void pa_calcular_termo_medio();
void pa_calcular_qtd_termos();
void pa_calcular_razao();