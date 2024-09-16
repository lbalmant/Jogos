#include "..\include\JogoDeTabuleiro.hpp"
#include <iostream>
#include <algorithm> // para std::fill
#include <iomanip> // para std::setw

// Problema no reversi: Verificar se há possibilidade de jogada para o jogador que vai jogar. Caso não houver mudar a rota para o próximo jogador.


JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    tabuleiro = new char*[linhas];
    for (int i = 0; i < linhas; ++i) {
        tabuleiro[i] = new char[colunas];
        std::fill(tabuleiro[i], tabuleiro[i] + colunas, '-');
    }
}

char JogoDeTabuleiro::getValorTabuleiro(int linha, int coluna){
    return tabuleiro[linha][coluna];
}
void JogoDeTabuleiro::setValorTabuleiro(int linha, int coluna, char jogador){
    tabuleiro[linha][coluna] = jogador;
}

void JogoDeTabuleiro::imprimirTabuleiro() const {
    // Imprime a numeração das colunas
    std::cout << "  ";
    for (int j = 0; j < colunas; ++j) {
        std::cout << std::setw(2) << j + 1;
    }
    std::cout << '\n';

    // Imprime o tabuleiro com a numeração das linhas
    for (int i = 0; i < linhas; ++i) {
        std::cout << std::setw(2) << i + 1 << ' '; // Numeração das linhas
        for (int j = 0; j < colunas; ++j) {
            std::cout << tabuleiro[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool JogoDeTabuleiro::jogadaValida(int linha, int coluna) const {
    // Implementação padrão para jogos com duas dimensões
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && tabuleiro[linha][coluna] == '-';
}

bool JogoDeTabuleiro::fazerJogada(int linha, int coluna, char jogador) {
    // Implementação padrão para jogos com duas dimensões
    if (jogadaValida(linha, coluna)) {
        tabuleiro[linha][coluna] = jogador;
        return true;
    }
    return false;
}

bool JogoDeTabuleiro::jogadaValida(int coluna) const {
    // Implementação padrão para jogos com uma dimensão
    // Em jogos unidimensionais, você pode considerar a linha fixa ou verificar outras condições
    return coluna >= 0 && coluna < colunas && tabuleiro[0][coluna] == '-';
}

void JogoDeTabuleiro::fazerJogada(int coluna, char jogador) {
    // Implementação padrão para jogos com uma dimensão
    // Em jogos unidimensionais, você pode colocar a peça na primeira linha disponível ou semelhante
    for (int i = linhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == '-') {
            tabuleiro[i][coluna] = jogador;
            break;
        }
    }
}

bool JogoDeTabuleiro::jogadaValida(int linhas, int colunas, int indice) const{
    return false;
}

bool JogoDeTabuleiro::fazerJogada(int linhas, int colunas, char jogador, int& indice){
    return false;
}
