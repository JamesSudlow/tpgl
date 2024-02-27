#include <iostream>
#include "lexer.h"
#include "Automate.h"
#include <string>

int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbole * s;
   s=l.Consulter();
       cout<<"Create E0"<<endl;

   E0* etatInitial=new E0();
       cout<<"Create automate"<<endl;

   Automate* automate=new Automate(&l,etatInitial);
   cout<<"Do transition"<<endl;
   cout<<*s<<endl;
   int i=0;
   while(!automate->statestack.back()->transition(*automate, s) && i<10){
      s=l.Consulter();
      //cout<<automate->statestack.back()->name;
      //s->Affiche();
      //cout<<endl;
      //i++;
   }
   return 0;
}

