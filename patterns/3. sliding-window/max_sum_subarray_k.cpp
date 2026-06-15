#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
//cout = saída no terminal
//<< = envia algo para o cout
//endl = pula para a próxima linha

vector<int> maxRevenueInKDays(const vector<int>& revenues, int k) {
    //validação para garantir que k seja um valor válido, ou seja, maior que zero e menor ou igual ao tamanho do array de receitas.
    if (k <= 0 || k > static_cast<int>(revenues.size())) {
        return {0, 0, 0};
    }

    int windowSum = 0;

    // Primeiro montamos a janela inicial com os primeiros k dias.
    for (int i = 0; i < k; ++i) {
        windowSum += revenues[i];
    }

    int maxSum = windowSum;
    int startDay = 1;
    int endDay = k;

    // Agora a janela desliza: entra o dia atual e sai o dia que ficou para tras.
    for (int right = k; right < static_cast<int>(revenues.size()); ++right) {
        int left = right - k;

        windowSum += revenues[right];
        windowSum -= revenues[left];

        if (windowSum > maxSum) {
            maxSum = windowSum;
            startDay = left + 2; // A janela atual começa no dia seguinte ao que saiu.
            endDay = right + 1; // A janela atual termina no dia que acabou de entrar.
        }
    }

    return {maxSum, startDay, endDay};
}

/*
                            *Enunciado*
                ## Melhor Periodo de Vendas ##

Voce trabalha em um sistema de analise de vendas. Cada posicao do array revenues
representa o total vendido em um dia.

Dado um array revenues e um numero k, encontre a maior receita total obtida em
qualquer periodo de k dias consecutivos.

Exemplo:
revenues = {120, 80, 45, 200, 60, 30, 90}
k = 3

Janelas possiveis:
120 + 80 + 45 = 245
80 + 45 + 200 = 325
45 + 200 + 60 = 305
200 + 60 + 30 = 290
60 + 30 + 90 = 180

Resposta esperada: 325

Como precisamos analisar trechos consecutivos de tamanho fixo, podemos usar
Sliding Window para atualizar a soma em O(1) a cada deslocamento da janela.
*/

int main() {
    vector<int> revenues = {120, 80, 45, 200, 60, 30, 90};
    int k = 3;

    vector<int> bestRevenue = maxRevenueInKDays(revenues, k);

    cout << "Sliding Window - Maior receita em " << k << " dias: " << bestRevenue[0] << " entre os dias " << bestRevenue[1] << " e " << bestRevenue[2] << endl;

    return 0;
}
