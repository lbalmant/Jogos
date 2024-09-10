#include <iostream>
#include "../include/JogoDaVelha.hpp"
#include "../include/JogoDeTabuleiro.hpp"
#include <iostream>


void jogar(JogoDeTabuleiro* jogo) {
    char jogador = 'X';
    while (!jogo->tabuleiroCheio()) {
        jogo->imprimirTabuleiro();

        int linha = -1, coluna = -1;
        if (jogo->isBidimensional()) {
            // Para jogos bidimensionais
            std::cout << "Turno do jogador " << jogador << " (linha coluna): ";
            std::cin >> linha >> coluna;
            linha -= 1; // Ajuste para o índice da linha
            coluna -= 1; // Ajuste para o índice da coluna
//tentando corrigir bug que passa para o próximo jogador após jogada invalida
            
            
            if (jogo->jogadaValida(linha, coluna)) {
                bool verificaComeu = jogo->fazerJogada(linha, coluna, jogador);
                if(!verificaComeu){
                    jogador = (jogador == 'X') ? 'O' : 'X';
                }
            } else {
                std::cout << "Jogada inválida. Tente novamente.\n";
                //jogador = (jogador == 'X') ? 'O' : 'X';
                continue;
            }
                    
        } else {
            // Para jogos unidimensionais
            std::cout << "Turno do jogador " << jogador << " (coluna): ";
            std::cin >> coluna;
            coluna -= 1; // Ajuste para o índice da coluna

            
            
            if (jogo->jogadaValida(coluna)) {
                jogo->fazerJogada(coluna, jogador);
            } else {
                std::cout << "Jogada inválida. Tente novamente.\n";
                continue;
            }
         
        }

        if (jogo->verificarVitoria(jogador)) {
            jogo->imprimirTabuleiro();
            std::cout << "Jogador " << jogador << " venceu!\n";
            return;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    jogo->imprimirTabuleiro();
    std::cout << "Empate!\n";
}

int main() {
    int escolha;
    std::cout << "Escolha o jogo:\n1. Jogo da Velha\n2. Lig4(ainda não unciona)\n";
    std::cin >> escolha;

    JogoDeTabuleiro* jogo = nullptr;

    if (escolha == 1) {
        jogo = new JogoDaVelha();
    } else if (escolha == 2) {
        //jogo = new Lig4();
    } else {
        std::cout << "Escolha inválida.\n";
        return 1;
    }

    jogar(jogo);
    delete jogo;

    return 0;
}