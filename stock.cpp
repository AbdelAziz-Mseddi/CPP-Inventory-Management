#include "stock.h"
//CONSTRUCTEUR PAR DEFAUT
stock::stock(){
    this->qnt=0;
}
//METHODES DE RECHERCHE D'ARTICLES
//Recherche par nom
article stock::rechnom_art(string nomch){
    bool found=false;
    int i=0;
    while(!found && i<this->qnt){
        string nomf=this->arr[i].getNom();
        if( nomf!=nomch ) i++;
        else found=true;
    }
    if(found) return this->arr[i];
    else return article();
}
//Recherche par réference
article stock::rechref_art(int refch){
    bool found=false;
    int i=0;
    while(!found && i<this->qnt){
        int reff=this->arr[i].getRef();
        if( reff!=refch ) i++;
        else found=true;
    }
    if(found) return this->arr[i];
    else return article();
}
//Recherche par prix
stock stock::rechpri_art(double p1, double p2){
    stock intervalle; 
    int i=0;
    while(i<this->qnt){
        double prif=this->arr[i].getPrixv();
        if( prif>=min(p1,p2) && prif<=max(p1,p2) ) intervalle.ajout_article(this->arr[i]);
        i++;
    }
    return intervalle;
}

//AJOUTER ARTICLE
void stock::ajout_article(article aj){
    this->arr.push_back(aj);
    this->qnt++;
    this->arr[0].setQnt(this->arr[0].getQnt()+1);
}

//SUPPRIMER ARTICLE
void stock::supp_article(int sp){
    bool found=false;
    int i=0;
    while(!found && i<this->qnt){
        int reff=this->arr[i].getRef();
        if( reff!=sp ) i++;
        else {
            found=true;
            this->arr.erase(this->arr.begin() + i);
            this->qnt--;
            if(this->arr[0].getQnt()>1) this->arr[0].setQnt(this->arr[0].getQnt()-1);
        }
    }
}
//MODIFIER ARTICLE
void stock::modif_article(int refch, int ref2, double pri2, int qnt2, string nom2){
    article nbadlouh=rechref_art(refch);
    nbadlouh.setNum(ref2);
    nbadlouh.setNom(nom2);
    nbadlouh.setPriv(pri2);
    nbadlouh.setQnt(qnt2);
}
//AFFICHER TOUS LES ARTICLES
void stock::afficher(){
    if(this->qnt == 0){
        cout << "Le stock est vide!" << endl;
        return;
    }
    cout << "øøøø- STOCK -øøøø" << endl;
    for(int i=0; i<this->qnt; i++){
        cout << "Article " << (i+1) << ":" << endl;
        cout << "  Reference: " << this->arr[i].getRef() << endl;
        cout << "  Nom: " << this->arr[i].getNom() << endl;
        cout << "  Prix: " << this->arr[i].getPrixv() << " TND" << endl;
        cout << "  Quantite: " << this->arr[i].getQnt() << endl;
        cout << "øøøøøøøøø" << endl;
    }
}
//STOCKER LES ARTICLES DANS UN FICHIER TXT
void stock::stock_stock(string ismFichier){
    if(this->qnt == 0){
        cout << "Le stock est vide!" << endl;
        return;
    }
    f.open("D:\\" + ismFichier, ios::out);
    for(int i=0; i<this->qnt; i++) f << this->arr[i].toString() << '\n';
    f.close();
}