#include <iostream>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int nodeValue) {
        value = nodeValue;
        next = nullptr;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next; // Guarda o proximo node antes de mudar o ponteiro.
        current->next = previous;          // Inverte o ponteiro do node atual.
        previous = current;                // Avanca previous para o node atual.
        current = nextNode;                // Continua percorrendo a lista original.
    }

    return previous;
}

void printList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->value;

        if (current->next != nullptr) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

/*
                            *Enunciado*
                ## Reverter uma Lista Ligada In-Place ##

Voce trabalha em um sistema que exibe uma sequencia de tarefas encadeadas.
Cada tarefa aponta para a proxima tarefa.

Dada a cabeca de uma linked list, reverta a ordem dos nodes sem criar uma nova
lista. A reversao deve ser feita in-place, alterando apenas os ponteiros next.

Exemplo:
1 -> 2 -> 3 -> 4 -> 5

Resposta esperada:
5 -> 4 -> 3 -> 2 -> 1

Para resolver, usamos tres ponteiros:

previous guarda o node anterior ja revertido.
current aponta para o node que esta sendo processado.
nextNode guarda temporariamente o proximo node original.

Em cada passo, fazemos current->next apontar para previous.
No final, previous sera a nova cabeca da lista.
*/

int main() {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Lista original: ";
    printList(first);

    ListNode* reversedHead = reverseList(first);

    cout << "Lista revertida: ";
    printList(reversedHead);

    deleteList(reversedHead); //não obrigatório, mas é uma boa prática liberar a memória alocada.

    return 0;
}
