#pragma once
#include <bits/stdc++.h>
#include <string>
using namespace std;
class article {
    private:
    string nom;
    int num_ref;
    double prixV;
    int qnt;
    
    public:
    article();
    article(int numRef, double priv);
    article(int numRef, double priv, int quant);
    ~article();
    string getNom();
    int getRef();
    double getPrixv();
    int getQnt();
    void setNom(string s);
    void setNum(int n);
    void setPriv(double p);
    void setQnt(int q);
    string toString();

};