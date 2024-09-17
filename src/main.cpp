#include <iostream>
#include "..\include\JogoDaVelha.hpp"
#include "..\include\JogoDeTabuleiro.hpp"
#include "..\include\Reversi.hpp"
#include "..\include\Lig4.hpp"
#include "..\include\JogoDaVelha2.hpp"
#include <iostream>


void jogar(JogoDeTabuleiro* jogo, int& indiceJogo) {
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
                    
        } else if(jogo->ehJogoDaVelha2()){
            // Implementação especial para o jogo da velha 2 ou tridimensionais
            std::cout << "Turno do jogador " << jogador << " (linha coluna): ";
            std::cin >> linha >> coluna;
            linha -= 1; // Ajuste para o índice da linha
            coluna -= 1; // Ajuste para o índice da coluna
            
            
            if (jogo->jogadaValida(linha, coluna, indiceJogo)) {
                bool verificaComeu = jogo->fazerJogada(linha, coluna, jogador, indiceJogo);
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
    int inicio=-1;
    int escolha;
    std::cout << "Escolha o jogo:\n1. Jogo da Velha\n2. Reversi\n3. Lig4\n4. Jogo da velha 2.0\n";
    std::cin >> escolha;

    JogoDeTabuleiro* jogo = nullptr;

    switch (escolha){
        case 1:
            jogo = new JogoDaVelha();
            break;
        case 2:
            jogo = new Reversi();
            break;
        case 3:
            jogo = new Lig4();
            break;
        case 4:
            std::cout << "Jogo de inicio(entre 1 e 9): ";
            std::cin >> inicio;
            while(inicio<1||inicio>9){
                std::cout << "Escolha invalida! Tente novamente: ";
                std::cin >> inicio;
                
            }
            inicio--;
            jogo = new JogoDaVelha2(inicio);

        }
    if(jogo!=nullptr){
        jogar(jogo, inicio);
        delete jogo;
    }
    return 0;
}