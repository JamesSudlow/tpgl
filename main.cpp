#include <iostream>
#include "lexer.h"
#include "Automate.h"
#include <string>
using namespace std;

int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbole * s;
   Symbole * s2;

   s=l.Consulter();

   E0* etatInitial=new E0();

   Automate* automate=new Automate(&l,etatInitial);

   int i=0;
   while(!automate->statestack.back()->transition(*automate, s) && i<20){
      s=l.Consulter();
      s2=automate->symbolstack.back();
      if(*s2==ERREUR){
        cout<<"Il y a une erreur"<<endl;
        break;
      }
      //cout<<automate->statestack.back()->name;

      //s2->Affiche();

      //cout<<endl;
      i++;
      //s->Affiche();
      //cout<<endl;
   }
   if(*s2!=ERREUR){
        cout<<"La valeur correcte est : "<<automate->result<<endl;
   }
   return 0;
}

