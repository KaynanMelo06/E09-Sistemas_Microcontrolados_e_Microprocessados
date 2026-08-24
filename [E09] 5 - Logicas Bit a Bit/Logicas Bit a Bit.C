#include <stdint.h>
#include <stdio.h>

int main() {
    // Valor inicial de teste: 0b00001000 (Decimal 8)
    // Apenas o Bit 3 está ligado.
    uint8_t status = 0b00001000;
    printf("--- Estado Inicial ---\n");
    printf("Valor: %d (Binario: 0b00001000)\n\n", status);

    // 1. Lógica OU (|) - Seta um ou mais bits em '1'
    // Vamos "ligar" o Bit 0 e o Bit 1, mantendo o resto como está.
    status = status | (1 << 0) | (1 << 1); 
    // Esperado: 0b00001011 (Decimal 11)
    printf("1. Lógica OU (|) ativando bits 0 e 1:\n");
    printf("Valor: %d (Binario: 0b00001011)\n\n", status);

    // 2. Lógica E com inverso (& ~) - Reseta um ou mais bits em '0'
    // Vamos "desligar" o Bit 3 de forma cirúrgica.
    status = status & ~(1 << 3);
    // Esperado: 0b00000011 (Decimal 3)
    printf("2. Lógica E com inverso (& ~) desativando bit 3:\n");
    printf("Valor: %d (Binario: 0b00000011)\n\n", status);

    // 3. Lógica E (&) - Utilizada em máscaras para teste 
    // Vamos verificar se o Bit 0 está em '1' ou '0'.
    printf("3. Lógica E (&) para teste de estado:\n");
    if (status & (1 << 0)) {
        printf("-> O Bit 0 esta ATIVADO (1)!\n\n");
    } else {
        printf("-> O Bit 0 esta DESATIVADO (0)!\n\n");
    }

    // 4. Lógica OU Exclusivo (^) - Troca o estado dos bits 
    // Se o Bit 1 for '1', vira '0'. Se for '0', vira '1'.
    // Como no nosso status atual o Bit 1 é '1', ele vai ser desligado.
    status = status ^ (1 << 1);
    // Esperado: 0b00000001 (Decimal 1)
    printf("4. Lógica OU Exclusivo (^) invertendo o bit 1:\n");
    printf("Valor: %d (Binario: 0b00000001)\n\n", status);

    // 5. Complemento de 1 (~) - Inverte o estado de todos os bits 
    // Onde tem 0 vira 1, onde tem 1 vira 0.
    // ~0b00000001 vira 0b11111110 (Decimal 254)
    uint8_t inverso = ~status;
    printf("5. Complemento de 1 (~) em todos os bits:\n");
    printf("Valor: %d (Binario: 0b11111110)\n\n", inverso);

    // 6. Deslocamento para a direita (>>) - Empurra bits para a direita 
    // Vamos pegar o decimal 4 (0b00000100) e empurrar 1 vez para a direita.
    uint8_t teste_dir = 0b00000100;
    teste_dir = teste_dir >> 1;
    // Esperado: 0b00000010 (Decimal 2)
    printf("6. Shift Right (>>):\n");
    printf("Valor original (4) virou: %d (Binario: 0b00000010)\n\n", teste_dir);

    return 0;
}