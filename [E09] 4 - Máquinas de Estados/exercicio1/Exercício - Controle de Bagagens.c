#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Necessario para a funcao sleep()

#define ESPERA 0
#define MOVER_PARA_RX 1
#define INSPECAO 2
#define MOVER_PARA_SAIDA 3
#define EMERGENCIA 4

int main(){


    char BI = 0; // Botao de inicio
    char S1 = 0; // Sensor do raio-x
    char S2 = 0; // Sensor para saida
    char BE = 0; // Botao de emergencia

    char estado = ESPERA; 

    while (1) {
        switch (estado) {
            case ESPERA:
                printf("\n[ESPERA] Digite 1 para apertar BI ou 0 para aguardar: ");
                scanf(" %hhd", &BI); // %hhd é o formato para ler números pequenos (char)
                
                if (BI == 1){
                    estado = MOVER_PARA_RX;
                    BI = 0; // Resetando o botão após soltar
                }
                if (BE == 1){
                    estado = EMERGENCIA;
                }
                break;

            case MOVER_PARA_RX:
                printf("\n[MOVENDO] Digite 1 para ativar S1 (Chegou no RX) ou 9 para Emergencia: ");
                int entrada;
                scanf("%d", &entrada);
                
                if (entrada == 1) S1 = 1;
                if (entrada == 9) BE = 1;

                if (S1 == 1){
                    estado = INSPECAO;
                    S1 = 0; // Resetando o sensor
                }
                if (BE == 1){
                    estado = EMERGENCIA;
                }
                break;

            case INSPECAO:
                printf("\n[INSPECAO] Iniciando Raio-X...\n");
                int tempo = 0;
                
                // Correção do loop: enquanto for menor que 5
                while (tempo < 5){ 
                    printf("Inspecionando... %d segundos\n", tempo + 1);
                    sleep(1); // Espera 1 segundo real
                    tempo++;
                }
                
                estado = MOVER_PARA_SAIDA;
                
                if (BE == 1){
                    estado = EMERGENCIA;
                }
                break;

            case MOVER_PARA_SAIDA:
                printf("\n[SAIDA] Digite 1 para ativar S2 (Retirada) ou 9 para emergencia: ");
                scanf(" %hhd", &S2);

                if (S2 == 9) BE = 1;

                if (S2 == 1){
                    estado = ESPERA;
                    S2 = 0;
                }
                if (BE == 1){
                    estado = EMERGENCIA;
                }
                break;

            case EMERGENCIA:
                printf("\n[ALERTA] BOTAO DE EMERGENCIA ATIVADO!\n");
                // Resetando o sistema para fins de simulação
                BE = 0; 
                estado = ESPERA;
                sleep(2);
                break;
            
            default:
                break;
        }
    }
    return 0;
}