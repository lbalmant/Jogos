#ifndef JOGODAVELHA2_HPP
#define JOGODAVELHA2_HPP

#include "JogoDaVelha.hpp"

class JogoDaVelha2 : public JogoDaVelha{
    protected:
        int linhas = 9;
        int colunas = 9;
        JogoDaVelha* jogos[9];
    public:
        JogoDaVelha2();

        bool verificarVitoria(char jogador) const override;
        bool vitoriaJoguinho(int indice);

        virtual bool tabuleiroCheio() const override;
        virtual bool isBidimensional() const override;
        virtual bool ehJogoDaVelha2() const override;

        void imprimirTabuleiro() const override;

        bool jogadaValida(int linha, int coluna, int indice) const override;
        bool fazerJogada(int linha, int coluna, char jogador, int& indice) override;

};

#endif // JOGODAVELHA2_HPP