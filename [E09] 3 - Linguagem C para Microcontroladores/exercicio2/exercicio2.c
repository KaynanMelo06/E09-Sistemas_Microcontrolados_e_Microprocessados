#include <stdint.h>
#include <stdio.h>

uint8_t pin_states = 0;

int main(){

    // bit 0 → LED1
    // bit 1 → LED2
    // bit 2 → LED3
    // bit 3 → BOTAO1
    // bit 4 → BOTAO2
    pin_states = 0b00010100;

    printf("Estado dos LEDs:\n");
    for (int i = 0; i < 3; i++) {
        if (pin_states & (1 << i)) {
            printf("LED%d está LIGADO\n", i + 1);
        } else {
            printf("LED%d está DESLIGADO\n", i + 1);
        }
    }

    printf("\nEstado dos botoes:\n");
    for (int j = 3; j < 5; j++){
        if (pin_states & (1 << j)) {
            printf("Botao%d esta LIGADO\n", j+1);
        } else {
            printf("Botao%d esta DESLIGADO\n", j+1);
        }
    }

}