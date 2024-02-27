#pragma once
#include "Etat.h"
#include <vector>
#include "lexer.h"
#include <iostream>

class Automate{
    public:
    Automate(Lexer* l, Etat* e);
    void decalage(Symbole * s, Etat * e);
    void reduction(int n,Entier * s);
    void transitionSimple(Symbole * s, Etat * e);
    void popSymbol();
    Lexer* lexer;
    vector<Symbole*> symbolstack;
    vector<Etat*> statestack; 
    int popReturnSymbol();
};
