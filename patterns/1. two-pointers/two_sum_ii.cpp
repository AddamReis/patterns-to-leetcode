#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
//cout = saída no terminal
//<< = envia algo para o cout
//endl = pula para a próxima linha
//.size() - Retorna o número de elementos em um vetor ou string.

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1}; // LeetCode usa indice comecando em 1.
        }

        // Como o array esta ordenado, soma pequena demais move o ponteiro esquerdo.
        if (sum < target) {
            ++left;
        } else {
            // Soma grande demais move o ponteiro direito.
            --right;
        }
    }

    return {};
}

/*
                            *Enunciado*
                ## Encontrar Duas Compras com Valor Exato ##

Voce trabalha em um sistema de checkout. O sistema recebe uma lista de precos
ordenada em ordem crescente e um valor alvo chamado target.

Seu objetivo e encontrar dois produtos diferentes cuja soma dos precos seja
exatamente igual ao target.

Como a lista ja esta ordenada, implemente a solucao usando Two Pointers:
um ponteiro comeca no inicio da lista e outro no final.

Exemplo:
numbers = {2, 7, 11, 15}
target = 9

Resposta esperada:
{1, 2}

Observacao:
Neste problema, os indices retornados seguem o padrao do LeetCode, ou seja,
comecam em 1. Por isso, os indices reais 0 e 1 viram 1 e 2 na resposta.
*/

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);

    cout << "Two Sum II: ";
    for (int index : result) { //foreach do c++
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
