#include "Automate.h"

Automate::Automate(Lexer* l, Etat* e){
    this->lexer=l;
    statestack.push_back(e);
}

void Automate::decalage(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer();   
}
void Automate::transitionSimple(Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
}
void Automate::reduction(int n,Entier * s) {
    result=s->valeur;
    for (int i=0;i<n;i++)
    {
        delete(statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this,s);
}
void Automate::popSymbol(){
    symbolstack.pop_back();
}
int Automate::popReturnSymbol(){
    Entier* e= (Entier *)symbolstack.back();
    symbolstack.pop_back();
    return e->valeur;
}