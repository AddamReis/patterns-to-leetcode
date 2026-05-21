# web doc

https://dev.to/somadevtoo/coding-interviews-was-hard-until-i-learned-these-patterns-2ji7

# PatternsCode

Repositorio para estudar patterns de algoritmos em C++ com exemplos separados por arquivo.

## Estrutura

```text
patterns/
  1. two-pointers/
    two_sum_ii.cpp
    remove_duplicates_sorted_array.cpp
  2. prefix-sum/
    prefix_sum.cpp
  3. sliding-window/
    max_sum_subarray_k.cpp
scripts/
  compile.bat
build/
  executaveis e arquivos gerados pela compilacao
```

## Como compilar

Na raiz do projeto:

```bat
compile.bat "patterns\1. two-pointers\two_sum_ii.cpp"
```

Outro exemplo:

```bat
compile.bat "patterns\1. two-pointers\remove_duplicates_sorted_array.cpp"
```

Exemplo com prefix sum:

```bat
compile.bat "patterns\2. prefix-sum\prefix_sum.cpp"
```

Exemplo com sliding window:

```bat
compile.bat "patterns\3. sliding-window\max_sum_subarray_k.cpp"
```

Para adicionar novos patterns, crie uma nova pasta dentro de `patterns/` e coloque cada problema em um `.cpp` proprio.
