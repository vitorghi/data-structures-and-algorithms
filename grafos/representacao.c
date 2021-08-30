/*
Grafos: conjunto de objetos ligados entre si
    - chamamos os objetos de vértices
        ex: pessoas em uma rede social

    - chamamos as conexões de arestas
        ex: relação de amizade na rede social

Matematicamente, um grafo G é um par ordenado, G = (V, E)
    - V é o conjunto de vértices do grafo
        Ex: V = {0,1,2,3,4,5}
    - E é o conjunto de arestas do grafo (edges)
        1. Representamos uma aresta ligando u, v E V como {u, v}
        2. Para toda aresta {u, v} em E, temos que u != v
        3. Existe, no máximo, uma aresta {u, v} em E
        Ex: E = { {0,1}, {0,4}, {5,3}, {1,2}, {2,5} }

Matriz de adjacências:
    - Se o grafo tem n vértices
    - Os vértices serão numerados de 0 a n - 1
    - A matriz de adjacências é n x n
    - adjacencia[u][v] = 1, significa que u e v são vizinhos
        há uma aresta que os liga
    - adjacencia[u][v] = 0, significa que u e v não são vizinhos
        não há aresta que os liga

*/