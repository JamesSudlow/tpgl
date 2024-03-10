#include <iostream>
#include <fstream>
#include "lexer.h"
#include "Automate.h"
#include <string>
using namespace std;

int main(void) {
   while(1){
      int mode=-1;
      cout<<"Please type in a number between 0 and 3"<<endl;
      cout<<"0 means close program, 1 loads a file, 2 types in a value, 3 uses default chaine"<<endl;
      cin>>mode;
      if(mode==0){
         break;
      }
      string chaine("(1+34)*123");
      string fileName="";
      if(mode==1){
         cin>>fileName;
      }
      ifstream MyReadFile(fileName);

      while(mode>0 && mode<4){
         if(mode==2){
            mode=-1;
            cin>>chaine;
         }
         if(mode==3){
            mode=-1;
            cout<<chaine<<endl;
         }
         if (mode==1 && getline(MyReadFile, chaine)) {
            cout << chaine<<endl;
         }
         else{
            if(mode==1){
               MyReadFile.close();
               break; 
            }
            mode=-1;
         }

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
            if(*s2==ERREUR ||*s==ERREUR){
               cout<<"Il y a une erreur dans la formule"<<endl;
               break;
            }
         }
         if(*s2!=ERREUR && *s!=ERREUR){
            cout<<"La valeur correcte est : "<<automate->result<<endl;
         }
      }
   }
   return 0;
}

