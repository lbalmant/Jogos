#include "..\include\JogoDaVelha2.hpp"
#include <iostream>

// Problemas: Olhar o main

JogoDaVelha2::JogoDaVelha2(){
    for(int i=0;i<9;i++){
        jogos[i] = new JogoDaVelha;
    }
}

void JogoDaVelha2::imprimirTabuleiro() const{
    int auxi = 0;
    int varJogos=0;
    int contAux=0;
    for(int i=0;i<linhas;++i){
        if(auxi==3){
            auxi = 0;
            std::cout << "\n";
        }
        for(int j=0;j<colunas;++j){
            if(contAux==27){
                varJogos+=3;
                contAux=0;
            }
            if(j>=0&&j<3){
                std::cout << jogos[varJogos]->getValorTabuleiro(auxi,j) << ' ';
            }else if(j>=3&&j<6){
                if (j==3)
                    std::cout << "    ";
                std::cout << jogos[varJogos+1]->getValorTabuleiro(auxi,j-3) << ' ';
            }else{
                if (j==6)
                    std::cout << "    ";
                std::cout << jogos[varJogos+2]->getValorTabuleiro(auxi,j-6) << ' ';
            }
            contAux++;
        }
        auxi++;
        std::cout << "\n";
    }
}

bool JogoDaVelha2::isBidimensional() const{
    return false;
}
bool JogoDaVelha2::ehJogoDaVelha2() const{
    return true;
}

bool JogoDaVelha2::tabuleiroCheio() const {
    for(int k=0;k<9;++k){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (jogos[k]->getValorTabuleiro(i,j) == '-') {
                    return false;
                }
            }
        }
    }
    return true;
}

bool JogoDaVelha2::vitoriaJoguinho(int indice){
    
    if(jogos[indice]->verificarVitoria('X')){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                jogos[indice]->setValorTabuleiro(i,j,'X');
                
            }
        }
        return true;
    }
    if(jogos[indice]->verificarVitoria('O')){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                jogos[indice]->setValorTabuleiro(i,j,'O');
                
            }
        }
        return true;
    }

    return false;
}

bool JogoDaVelha2::verificarVitoria(char jogador) const{
    
    // Verificar linhas
    int verificador=0;
    for(int i=0;i<3;i++){
        if(jogos[verificador]->verificarVitoria(jogador)&&jogos[verificador+1]->verificarVitoria(jogador)&&jogos[verificador+2]->verificarVitoria(jogador)){
            return true;
        }
        verificador+=3;
    }
    // Verificar colunas
    verificador = 0;
    for(int i=0;i<3;i++){
        if(jogos[verificador]->verificarVitoria(jogador)&&jogos[verificador+3]->verificarVitoria(jogador)&&jogos[verificador+6]->verificarVitoria(jogador)){
            return true;  
        }
        verificador += 1;
    }
    // Verificar Diagonais
    if(jogos[0]->verificarVitoria(jogador)&&jogos[4]->verificarVitoria(jogador)&&jogos[8]->verificarVitoria(jogador)){
        return true;
    }
    if(jogos[2]->verificarVitoria(jogador)&&jogos[4]->verificarVitoria(jogador)&&jogos[6]->verificarVitoria(jogador)){
        return true;
    }
    return false;
}

bool JogoDaVelha2::jogadaValida(int linha, int coluna, int indice) const{
    if(jogos[indice]->jogadaValida(linha,coluna)){
        return true;
    }
    return false;
}

bool JogoDaVelha2::fazerJogada(int linha, int coluna, char jogador, int& indice){

    if(jogos[indice]->fazerJogada(linha,coluna,jogador)){
        JogoDaVelha2::vitoriaJoguinho(indice);
        
        linha = (linha+1)*10;
        coluna++;
        int verificacao = linha+coluna;
        switch (verificacao){
        case 11:
            indice = 0;
            break;
        case 12:
            indice = 1;
            break;
        case 13:
            indice = 2;
            break;
        case 21:
            indice = 3;
            break;
        case 22:
            indice = 4;
            break;
        case 23:
            indice = 5;
            break;
        case 31:
            indice = 6;
            break;
        case 32:
            indice = 7;
            break;
        case 33:
            indice = 8;
            break;
        default:
            break;
        }
        if (vitoriaJoguinho(indice))
            imprimirTabuleiro();
        while(vitoriaJoguinho(indice)){
            std::cout << "Jogo ganho! Escolha o novo indice: ";
            int copia = indice;
            std::cin >> indice;
            if (indice<1||indice>9){
                std::cout << "Escolha inválida!";
                indice = copia;
            }else{
                indice-=1;
            }
        }

        return true;
    }
    return false;
}