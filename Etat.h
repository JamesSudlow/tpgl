#pragma once
#include "symbole.h"
class Automate;
class Etat {
    public:Etat(string name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate & automate, Symbole * s) = 0;
    string name;
};
class E0 : public Etat{
    public:E0();
    ~E0();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E1 : public Etat{
    public:E1();
    ~E1();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E2 : public Etat{
    public:E2();
    ~E2();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E3 : public Etat{
    public:E3();
    ~E3();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E4 : public Etat{
    public:E4();
    ~E4();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E5 : public Etat{
    public:E5();
    ~E5();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E6 : public Etat{
    public:E6();
    ~E6();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E7 : public Etat{
    public:E7();
    ~E7();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E8 : public Etat{
    public:E8();
    ~E8();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 
class E9 : public Etat{
    public:E9();
    ~E9();
    void print() const;
    bool transition(Automate & automate, Symbole * s);
    string name;
}; 