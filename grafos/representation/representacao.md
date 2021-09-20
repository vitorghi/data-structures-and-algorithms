# Grafos
  Conjunto de objetos ligados entre si

  - chamamos os objetos de vértices, ex: pessoas em uma rede social

  - chamamos as conexões de arestas, ex: relação de amizade na rede social

Matematicamente, um grafo G é um par ordenado, **G = (V, E)**

    - V é o conjunto de vértices do grafo
        Ex: V = {0,1,2,3,4,5}
    - E é o conjunto de arestas do grafo (edges)
        1. Representamos uma aresta ligando u, v E V como {u, v}
        2. Para toda aresta {u, v} em E, temos que u != v
        3. Existe, no máximo, uma aresta {u, v} em E
        Ex: E = { {0,1}, {0,4}, {5,3}, {1,2}, {2,5} }

> Um grafo com N vértices pode ter **(n * (n - 1)) / 2** arestas, ou seja, O(n²) arestas.


### Grafos esparsos

Dizemos que um grafo é esparso se ele tem "poucas" arestas

  - bem menos do que O(n²) arestas
  - Facebook tem no máximo 5000 amigos
  - grafos que têm no máximo um grau **d** (constante)
    * o número de arestas é **dn/2 = O(n)**
  - grafos com **O(nlogn)** arestas

> Não dizemos que um grafo com (n(n - 1))/20 arestas é esparso, pois o número de    arestas não é assintoticamente menor, é da mesma grandeza de n²


## Representação

### Matriz de adjacências
    - Se o grafo tem n vértices
    - Os vértices serão numerados de 0 a n - 1
    - A matriz de adjacências é n x n
    - adjacencia[u][v] = 1, significa que u e v são vizinhos
        há uma aresta que os liga
    - adjacencia[u][v] = 0, significa que u e v não são vizinhos
        não há aresta que os liga

### Lista de adjacências
    - Se o grafo tem n vértices
    - Teremos uma lista ligada para cada vértice
    - A lista armazena quais são os vizinhos do vértice

### Comparando lista e matriz de adjacência
#### **Espaço para armazenamento**:
| Representação | Espaço           |
| ------------- | ---------------- |
| Matriz        | O(\|V\|²)        |
| Lista         | O(\|V\| + \|E\|) |

#### **Tempo**:
| Operação              | Matriz   | Lista   |
| --------------------- | -------- | ------- |
| Inserir               | O(1)     | O(1)    |
| Remover               | O(1)     | O(d(v)) |
| Aresta existe?        | O(1)     | O(d(v)) |
| Percorrer vizinhança  | O(\|V\|) | O(d(v)) |

> Qual usar? Depende das operações a serem usadas e se o grafo é esparso.

# Grafos Dirigidos (Digrafos)

Um grafo dirigido tem:

  - um conjunto de vértices
  - conectados através de um conjunto de arcos (arestas dirigidas, indicam início e fim)

Representamos um digrafo visualmente

  - com os vértices representados por pontos;
  - os arcos representados por curvas com uma seta na ponta ligando dois vértices

Matematicamente, um digrafo é um par ordenado **G = (V, A)**

  - V é o conjunto de vértices do grafo
  - A é o conjunto de arcos do grafo
    * Representamos um arco ligando u, v E V como (u, v)
    * u é a cauda ou origem de (u, v)
    * v é a cabeça ou destino de (u, v)
  - Podemos ter laços; arcos da forma (u, u)
  - Existe no máximo um arco (u, v) em A
