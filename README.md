# GCC109 - Algoritmos e Estruturas de Dados III
## Trabalho prático 1

<b> Descrição: </b>

Este trabalho consiste em implementar um protótipo de rede social utilizando a estrutura de dados árvore binária de busca.

O sistema permitirá o cadastramento de pessoas e suas amizades. Cada pessoa possuirá um nome, um id e um conjunto de amizades. O id é um identificador inteiro único. O nome é o nome da pessoa. O conjunto de amizades é constituído dos ids das pessoas com as quais a pessoa possui algum tipo de relação de amizade.
Pessoas serão armazenadas em uma árvore binária de busca em que a chave de cada nó será o id da pessoa correspondente. O conjunto de amizades de uma pessoa será representado por uma outra árvore binária de busca. Os nós desta árvore armazenam apenas o id de cada amigo, que também é usado como chave para a
organização da árvore.
Em resumo, o sistema armazenará uma árvore binária de busca de pessoas. Cada pessoa possuirá uma árvore binária de busca com suas amizades.

O sistema deverá suportar as seguintes operações:
  1. Inserção. Permite cadastrar uma nova pessoa no sistema.
  2. Remoção. Permite remover uma pessoa do sistema, dado seu id.
  3. Busca. Recebe o id de uma pessoa e caso a pessoa esteja no sistema, exibe suas informações e também suas amizades.
  4. Cadastrar amizade. Recebe o id de duas pessoas e, caso ambas estejam cadastradadas no sistema e já não sejam amigas, cadastra uma nova amizade entre estas pessoas. 
  5. Remover amizade. Recebe o id de duas pessoas e, caso ambas estejam cadastradas no sistema e sejam amigas, desfaz a amizade entre as duas pessoas.
  6. Consultar amizade. Recebe o id de duas pessoas e diz se existe amizade entre as duas.
  7. Caminho de amizade (Bônus). Recebe o id de duas pessoas, P e Q, e, caso as duas estejam no sistema, mostra um possível caminho de amizade entre as duas. Isto é, mostra uma sequência de pessoas p1, p2, …, pn, em que p1 = P e pn = Q e existe uma relação de amizade entre pi e pi-1, para 2 <= i <= n. Além do código fonte, deverá ser entregue um relatório. O relatório deverá obrigatoriamente conter:
    
    • Uma descrição de todas as estruturas de dados utilizadas
    
    • Uma descrição EM ALTO NÍVEL (isto é, sem código) de como cada uma das operações requisitadas foi implementada.

Cada uma das operações requisitada tem peso 17%. Os seguintes itens serão levados em conta na pontuação:
  
    • A operação funciona corretamente?
  
    • A operação manipula corretamente as estruturas de dados e utiliza corretamente os conceitos apresentados em sala?
 
    • A operação foi descrita corretamente no relatório?

O trabalho deverá ser implementado utilizando a linguagem de programação C++ e ser passível de compilação em Linux. O trabalho deverá ser feito em grupos de no máximo 3 alunos. A data de entrega é 16/05/2018, até às 23:55.
