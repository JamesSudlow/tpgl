#pragma once
#include "Etat.h"
#include <vector>
#include "lexer.h"


class Automate{
    public:
    Automate(Lexer l);
    void decalage(Symbole * s, Etat * e);
    void reduction(int n,Symbole * s);
    void transitionSimple(Symbole * s, Etat * e);
    void popSymbol();
    private:
    Lexer* lexer;
    vector<Symbole*> symbolstack;
    vector<Etat*> statestack;
};
