#ifndef JOGO_DE_TABULEIRO_HPP
#define JOGO_DE_TABULEIRO_HPP

class JogoDeTabuleiro{
    public:
        JogoDeTabuleiro(int linhas, int colunas);
        virtual ~JogoDeTabuleiro() = default;
        // Métodos para jogos com duas dimensões
        virtual bool jogadaValida(int linha, int coluna) const;
        virtual bool fazerJogada(int linha, int coluna, char jogador);
        
        // Métodos para jogos com uma dimensão
        virtual bool jogadaValida(int coluna) const;
        virtual void fazerJogada(int coluna, char jogador);

        // Método para o jogo da velha 2.0
        virtual bool jogadaValida(int linha, int coluna, int indice) const;
        virtual bool fazerJogada(int linha, int coluna, char jogador, int& indice);

        virtual bool verificarVitoria(char jogador) const = 0;
        virtual bool tabuleiroCheio() const = 0;
        virtual bool isBidimensional() const = 0;
        virtual bool ehJogoDaVelha2() const = 0;
        
        virtual void imprimirTabuleiro() const;

        void setValorTabuleiro(int linha, int coluna, char jogador);
        char getValorTabuleiro(int linha, int coluna);

    protected:
        int linhas, colunas;
        char** tabuleiro;
};

#endif // JOGO_DE_TABULEIRO_HPP