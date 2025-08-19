//Resolução: exercício 1.12.30 (Livro Farrer)
#include <stdio.h>
#include <math.h>

long int pot(float base, int power){
    long int resultado = 1;
    for (int i = 0; i < power; i++){
        resultado = resultado * base;
    }
    return resultado;
}

double fatorial(int num){
    if (num == 0) return 1;
    double fat = 1;
    for(int i = 1; i <= num; i++){
        fat = fat * i;
    }
    return fat;
}

double senoA(float A, int quant_termos){
    double total = 0;
    int expoente = 1;
    int sinal = 1;

    for (int i = 0; i < quant_termos; i++){
        double fracao = (double)pot(A, expoente) / fatorial(expoente);
        total = total + (sinal * fracao);
        expoente = expoente + 2;
        sinal = sinal * -1;
    }

    return total;
}

int main (){
    for(int angulo=0; angulo <= 360; angulo++) {
        float angrad = (angulo * M_PI)/180;
        double senoC = sin(angrad);
        double senoAprox = senoA(angrad, 10); // 10 termos
        double delta = fabs(senoC - senoAprox);
        printf("%3d%10.3lf%10.3lf%10.3lf\n", angulo, senoC, senoAprox, delta);
    }
    return 0;
}


// Ângulo + 1 não altera o valor do ângulo, já o ++ altera o valor do ângulo.