#include "Etat.h"
#include "Automate.h"
//enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

Etat::Etat(string name){
    this->name=name;
}
E0::E0():Etat("E1"){}
E1::E1():Etat("E1"){}
E2::E2():Etat("E2"){}
E3::E3():Etat("E3"){}
E4::E4():Etat("E4"){}
E5::E5():Etat("E5"){}
E6::E6():Etat("E6"){}
E7::E7():Etat("E7"){}
E8::E8():Etat("E8"){}
E9::E9():Etat("E9"){}

bool E0::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case E:
        automate.decalage(s, new E1);
        break;       
    }
    return false;
}
bool E1::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case FIN:
        return true;  
        break;  
    }
    return false;
}
bool E2::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case E:
        automate.decalage(s, new E6);
        break;       
    }
    return false;
}
bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        automate.popSymbol();
        automate.reduction(1, new Symbole(E));
        break;       
    }
    return false;
}
bool E4::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case E:
        automate.decalage(s, new E7);
        break;       
    }
    return false;
}
bool E5::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case E:
        automate.decalage(s, new E8);
        break;       
    }
    return false;
}
bool E6::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
        break;       
    }
    return false;
}
bool E7::transition(Automate & automate, Symbole * s) {
    switch (*s){
    case MULT:
        automate.decalage(s, new E5);
        break;
    case PLUS:
    case CLOSEPAR:
    case FIN:
        automate.popSymbol();
        automate.reduction(1, new Symbole(E));
        break;       
    }
    return false;
}