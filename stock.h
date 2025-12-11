#pragma once
#include <bits/stdc++.h>
#include "article.h"
#include <fstream>
using namespace std;
class stock{
    private:
    vector <article> arr;
    int qnt;
    ofstream f;
    public:
    stock();
    article rechref_art(int refch);
    void ajout_article(article aj);
    void afficher();
    void supp_article(int sp);
    void modif_article(int refch, int ref2, double pri2, int qnt2, string nom2);
    article rechnom_art(string nomch);
    stock rechpri_art(double p1, double p2);
    void stock_stock(string filename);
};