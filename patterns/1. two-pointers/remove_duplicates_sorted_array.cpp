#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    // uniqueIndex guarda a posicao do ultimo valor unico encontrado.
    int uniqueIndex = 0;

    for (int current = 1; current < static_cast<int>(nums.size()); ++current) {
        if (nums[current] != nums[uniqueIndex]) {
            ++uniqueIndex;
            // Move o novo valor unico para a proxima posicao valida do array.
            nums[uniqueIndex] = nums[current];
        }
    }

    return uniqueIndex + 1;
}

/*
                            *Enunciado*
                ## Remover Duplicatas de uma Lista Ordenada ##

Voce trabalha em um sistema que recebe uma lista de IDs de clientes ja ordenada.
Por causa de importacoes duplicadas, o mesmo ID pode aparecer varias vezes.

Seu objetivo e remover as duplicatas in-place, mantendo apenas uma ocorrencia
de cada ID e preservando a ordem original.

A funcao deve retornar o novo tamanho valido do array. Os valores depois desse
tamanho nao importam.

Como o array esta ordenado, implemente a solucao usando Two Pointers:
um ponteiro acompanha a posicao do ultimo valor unico e outro percorre o array.

Exemplo:
nums = {1, 1, 2, 2, 3, 4, 4, 5}

Depois da remocao:
nums = {1, 2, 3, 4, 5, ...}

Resposta esperada:
5
*/

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = removeDuplicates(nums);

    cout << "Remove Duplicates - Novo comprimento: " << newLength << endl;
    cout << "Array apos remocao: ";

    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
