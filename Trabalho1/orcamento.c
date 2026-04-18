#include <stdio.h>
#include <math.h>

#define diaeletricista 260.0
#define diatecnico 250.0
#define diapintor 240.0
#define diapedreiro 220.0
#define diaajudante 100.0




float orcamentocalc(char tipo, float area, char estacao, int hrpedreiro, int hreletricista, int hrtecnico, int hrpintor, float *valorpedreiro, float *valoreletricista, float *valortecnico, float *valorpintor, float *valorajudante, float *obrabruta, float *ajustepercent) {
    *valorpedreiro = (diapedreiro / 8) * hrpedreiro;
    *valoreletricista = (diaeletricista / 8) * hreletricista;
    *valortecnico = (diatecnico / 8) * hrtecnico;
    *valorpintor = (diapintor / 8) * hrpintor;
    *valorajudante = ((diaajudante / 8) * (hrpedreiro + hreletricista + hrtecnico + hrpintor));




        if (tipo == 'c' || tipo == 'C') {
        *obrabruta = area * 40.0;  
    } else if (tipo == 'a' || tipo == 'A') {
        *obrabruta = area * 50.0; 
    } else {
        *obrabruta = 0.0; 
    }

    if (estacao == 'v' || estacao == 'V') {
        *ajustepercent = 0.40; 
    } else if (estacao == 'i' || estacao == 'I') {
        *ajustepercent = -0.10;  
    } else {
        *ajustepercent = 0.0;  
    }


    float totalmaodeobra = *valorpedreiro + *valoreletricista + *valortecnico + *valorpintor + *valorajudante;
    return (totalmaodeobra + *obrabruta) * (1 + *ajustepercent);
}



float valortotalcalc(float orcamentovalor, int parcelas, float *pgmentoajuste, float *mensalidadevalor) {
    if (parcelas == 0) {
        *pgmentoajuste = -0.15 * orcamentovalor;
        *mensalidadevalor = 0;
        return orcamentovalor + *pgmentoajuste;
    } else {
        float valorjuros = orcamentovalor * pow(1.12, (float)parcelas / 12); 
        *pgmentoajuste = valorjuros - orcamentovalor;
        *mensalidadevalor = valorjuros / parcelas;
        return valorjuros;
    }
}



int main() {

    int orcamentonum;

    do {
        printf("Digite a quantidade de orcamentos: ");
        scanf("%d", &orcamentonum);
         fflush(stdin);
        if (orcamentonum <= 0) {
            printf("Valor invalido, informe novamente!\n");
        }
    } while (orcamentonum <= 0);



    for (int i = 1; i <= orcamentonum; i++) {
        int hrpedreiro = 0, hreletricista = 0, hrtecnico = 0, hrpintor = 0;
        float area;
        char tipo, estacao, pagamentotp;
        int profissionalcod, horas, parcelas = 0;


        while (1) {
                    do {
            printf("Codigo do profissional: ");
            scanf("%d", &profissionalcod);
             fflush(stdin);
            if (profissionalcod < 0 || profissionalcod > 4) {
                printf("Valor invalido, informe novamente!\n");
            }
        } while (profissionalcod < 0 || profissionalcod > 4);

        if (profissionalcod == 0) break;

        do {
            printf("Horas do profissional: ");
            scanf("%d", &horas);
             fflush(stdin);
            if (horas <= 0) {
                printf("Valor invalido, informe novamente!\n");
            }
        } while (horas <= 0);




            switch (profissionalcod) {
                case 1: hrpedreiro += horas; break;
                case 2: hreletricista += horas; break;
                case 3: hrtecnico += horas; break;
                case 4: hrpintor += horas; break;
            }
        }



        do {
            printf("Area do ambiente de instalacao: ");
            scanf("%f", &area);
             fflush(stdin);
            if (area <= 0) {
                printf("Valor invalido, informe novamente!\n");
            }
        } while (area <= 0);



        do {
         printf("Tipo do ambiente de instalacao: ");
        scanf(" %c", &tipo); 
         fflush(stdin);
            if (tipo != 'c' && tipo != 'C' && tipo != 'a' && tipo != 'A') {
        printf("Valor invalido, informe novamente!\n");
            }
        } 
            while (tipo != 'c' && tipo != 'C' && tipo != 'a' && tipo != 'A');




        do {
            printf("Estacao do ano: ");
            scanf(" %c", &estacao);
             fflush(stdin);
            if (estacao != 'i' && estacao != 'I' && estacao != 'v' && estacao != 'V') {
             printf("Valor invalido, informe novamente!\n");
            }
        } while (estacao != 'i' && estacao != 'I' && estacao != 'v' && estacao != 'V');



        do {
            printf("Forma de pagamento: ");
            scanf(" %c", &pagamentotp);
             fflush(stdin);
            if (pagamentotp != 'p' && pagamentotp != 'P' && pagamentotp != 'v' && pagamentotp != 'V') {
             printf("Valor invalido, informe novamente!\n");
            }
        } while (pagamentotp != 'p' && pagamentotp != 'P' && pagamentotp != 'v' && pagamentotp != 'V');



        if (pagamentotp == 'p' || pagamentotp == 'P') {
            do {
         printf("Quantidade de Parcelas: ");
         scanf("%d", &parcelas);
          fflush(stdin);
           
            if (parcelas < 2) {  
         printf("Valor invalido, informe novamente!\n");
            }
        } while (parcelas < 2); 

        }



        float valorpedreiro, valoreletricista, valortecnico, valorpintor, valorajudante;
        float obrabruta, ajustepercent;
        float orcamentovalor = orcamentocalc(tipo, area, estacao, hrpedreiro, hreletricista, hrtecnico, hrpintor, &valorpedreiro, &valoreletricista, &valortecnico, &valorpintor, &valorajudante, &obrabruta, &ajustepercent);

        float pgmentoajuste, mensalidadevalor;
        float valorTotal = valortotalcalc(orcamentovalor, parcelas, &pgmentoajuste, &mensalidadevalor);

        printf("-Pedreiro: R$ %.2f\n", valorpedreiro);
        printf("-Eletricista: R$ %.2f\n", valoreletricista);
        printf("-Tecnico em AC: R$ %.2f\n", valortecnico);
        printf("-Pintor: R$ %.2f\n", valorpintor);
        printf("-Ajudante: R$ %.2f\n", valorajudante);
        printf("Valor da Obra Bruta: R$ %.2f\n", obrabruta);
        printf("Ajuste: %.2f%%\n", ajustepercent * 100);
        printf("Valor do orcamento: R$ %.2f\n", orcamentovalor);
        printf("Valor total a ser pago: R$ %.2f\n", valorTotal);



        if (parcelas == 0) {
     printf("Valor do Desconto: R$ %.2f\n", pgmentoajuste);

    } else {
     printf("Valor da Parcela: R$ %.2f\n", mensalidadevalor);
     printf("Juros Total: R$ %.2f\n", pgmentoajuste);
     printf("Qtd. de Parcelas: %d", parcelas);
    
    }

    }

    return 0;
}
