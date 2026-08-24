#include <stdint.h>
#include <stdio.h>

uint8_t inverso(int8_t num){

    num = num ^(0b11111111);
    return num;
}

void main(void){

uint8_t num = 0b10110010;
uint8_t num_invertido = inverso(num);

printf("Valor original: %d (Binario: 0b10110010)\n", num);
printf("Valor invertido: %d (Binario: 0b01001101)\n", num_invertido);


}