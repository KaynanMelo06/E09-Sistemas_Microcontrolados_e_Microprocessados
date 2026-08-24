#include <stdint.h>
#include <stdio.h>

int main(){

    uint8_t status = 0b00100000;

    // Se o sensor 1 estiver ativado, ligar o motor 2
    if (status & (1 << 7) == (1 << 7)){
        printf("Ligando o motor 2\n");
        status = (status | (1 << 1)) & ~(1 << 0);
    } 
    // Se o sensor 2 estiver ativado, ligar o motor 1
    else if (status & (1 << 6) == (1 << 6)){
        printf("Ligando o motor 1\n");
        status = (status | (1 << 0)) & ~(1 << 1);
    }
    // Se o sensor 3 estiver ativado, inverter o estado dos dois motores
    else if (status & (1 << 5) == (1 << 5)){
        printf("Invertendo o estado dos dois motores\n");
        // utilizando a operacao 'ou-exclusivo' ^
        status = status ^ ((1 << 0) | (1 << 1));
    }
    else if ((status & ((1 << 7) | (1 << 6) | (1 << 5))) == 0) {
        printf("Todos os sensores desativados, desligando os dois motores\n");
        status = status & ~((1 << 0) | (1 << 1));
    }
    return 0;
}