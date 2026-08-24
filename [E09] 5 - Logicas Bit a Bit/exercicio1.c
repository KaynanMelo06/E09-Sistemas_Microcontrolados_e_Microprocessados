#include <stdint.h>
#include <stdio.h>

int main(){
    
    // A. Inicie o valor com 127 em decimal
    uint8_t binario = 127; // binario = 0b01111111
    printf("Valor do binario: %d\n\n", binario);

    // B. ‘Ative' apenas o bit mais significativo
    binario = binario | (1 << 7);
    // binario = 0b11111111
    printf("Valor do binario após ativar o bit mais significativo: %d\n\n", binario);

    // C. Desative os 2 menos significativos
    binario = binario & ~(1 << 0) & ~(1 << 1);
    // binario = 0b11111100
    printf("Valor do binario após desativar os 2 bits menos significativos: %d\n\n", binario);

    // D. ‘Ative' apenas o bit 5
    binario = binario | (1 << 5);
    // binario = 0b11111100
    printf("Valor do binario após ativar o bit 5: %d\n\n", binario);

    /*  
    No valor resultante:
    A. Teste e o bit 6 está em 1    
    binario = 0b11111100 --> bit 6 esta em 1    */
    printf("Teste para ver se o bit 6 está em 1:\n");
    if (binario & (1 << 6) == (1 << 6)){
        printf("O bit 6 esta em 1\n\n");
    } else {
        printf("o bit 6  esta em 0\n\n");
    }

    // B. Teste se o bit 3 esta em 0
    // binario = 0b11111100 --> bit 3 esta em 1    
    printf("Teste para ver se o bit 3 está em 0:\n");
    if (binario & (1 << 3) == (1 << 3)){
        printf("O bit 3 esta em 1\n\n");
    } else {
        printf("o bit 3 esta em 0\n\n");
    }

    // C. Inverta o estado de todos os bits
    printf("Invertendo o estado de todos os bits:\n");
    // binario = 0b11111100 --> antes de inverter
    printf("Valor antes de inverter: %d\n", binario);
    binario = ~binario;
    // binario = 0b00000011 --> depois de inverter
    printf("Valor depois de inverter: %d\n", binario);

    return 0;
}