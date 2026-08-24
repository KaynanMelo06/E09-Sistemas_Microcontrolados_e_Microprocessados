#include <stdio.h>
#include <stdint.h>

// Definição das constantes
#define LIGADO 1
#define DESLIGADO 0

// Funções inline para ligar e desligar um LED. 
// Usamos ponteiros (*) para alterar o valor da variável original na memória.
static inline void ligar_led(uint8_t *led) {
    *led = LIGADO;
}

static inline void desligar_led(uint8_t *led) {
    *led = DESLIGADO;
}

int main() {
    // Declaração das variáveis uint8_t para os LEDs
    uint8_t led1 = DESLIGADO;
    uint8_t led2 = DESLIGADO;
    
    // Variável estado simulando a leitura dos botões. 
    // Você pode alterar este valor (0, 1, 2 ou 3) para testar as lógicas.
    uint8_t estado = 3; 

    // Lógica principal de acionamento
    if (estado == 0) {
        desligar_led(&led1);
        desligar_led(&led2);
    } 
    else if (estado == 1) {
        ligar_led(&led1);
        desligar_led(&led2);
    } 
    else if (estado == 2) {
        desligar_led(&led1);
        ligar_led(&led2);
    } 
    else if (estado == 3) {
        ligar_led(&led1);
        ligar_led(&led2);
    }

    // Exibir o resultado no terminal conforme solicitado
    printf("Resultados da simulacao (Estado atual: %d)\n", estado);
    
    if (led1 == LIGADO) {
        printf("LED1: ON\n");
    } else {
        printf("LED1: OFF\n");
    }
    
    if (led2 == LIGADO) {
        printf("LED2: ON\n");
    } else {
        printf("LED2: OFF\n");
    }

    return 0;
}