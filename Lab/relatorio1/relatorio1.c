Alunos:
/*
Kaynan Henrique Dias de Melo - GEC - 2197
André Rodrigues Silva - GEA - 1125
Vithor Humberto Santos Spirandeli - GEA - 1033

QUESTÃO 1
*/

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int qnt;
    double preco_unidade;
    double preco_total;

    cin >> qnt;

    if (qnt < 12) {
        preco_unidade = 0.8;
    } else {
        preco_unidade = 0.65;
    }

    preco_total = qnt * preco_unidade;

    cout << fixed << setprecision(2);
    cout << "Preco da unidade: R$" << preco_unidade << endl;
    cout << "Preco total: R$" << preco_total << endl;

    return 0;
}


QUESTÃO 2 -


#include <iostream>
using namespace std;



int main() {

    int numero;

 
    do {
        cin >> numero;
    } while (numero < 0 || numero > 50);

   

    for (int i = 1; i < numero; i++) {
        int divisor = numero - i; 
        
        cout << "Resto da divisao de " << numero << " por " << divisor << ": " << numero % divisor << endl;
    }


    return 0;
}





QUESTÃO 3 -




#include <iostream>
using namespace std;


void analisaNumero() {
    int numero;
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    for (int i = 0; i < 5; i++) {
        cin >> numero;

        if (numero % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        if (numero > 0) {
            positivos++;
        } else if (numero < 0) {
            negativos++;
        }
    }

    cout << "qnt de numeros pares: " << pares << endl;
    cout << "qnt de numeros impares: " << impares << endl;
    cout << "qnt de numeros positivos: " << positivos << endl;
    cout << "qnt de numeros negativos: " << negativos << endl;
}


int main() {

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        analisaNumero();
    }

    return 0;
}