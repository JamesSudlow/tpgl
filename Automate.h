#include "Etat.h";
#include <vector>
#include "lexer.h"


class Automate{
    public:
    void decalage(Symbole * s, Etat * e);
    void reduction(int n,Symbole * s);
    void transitionSimple(Symbole * s, Etat * e);
    private:
    Lexer* lexer;
    vector<Symbole*> symbolstack;
    vector<Etat*> statestack;
};
