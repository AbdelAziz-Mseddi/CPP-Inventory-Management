#include "article.h"
//CONSTRUCTEURS
//Constructeur par défaut
article::article(){
    num_ref=0;
    prixV=10;
    qnt=0;
}
//Constructeur à paramètres
article::article(int numRef, double priv){
    num_ref=numRef;
    prixV=priv;
}
//Constructeur à paramètres 2.0
article::article(int numRef, double priv, int quant){
    num_ref=numRef;
    prixV=priv;
    qnt=quant;
}
//GETTERS
//Getter pour le numéro de réference
int article::getRef(){
    return this->num_ref;
}
//Getter pour le prix de vente
double article::getPrixv(){
    return this->prixV;
}
//Getter pour la quantité
int article::getQnt(){
    return this->qnt;
}
//Getter pour le nom
string article::getNom(){
    return this->nom;
}
//SETTERS
//Setter pour le numéro de réference
void article::setNum(int n){
    this->num_ref=n;
}
//Setter pour le prix de vente
void article::setPriv(double p){
    this->prixV=p;
}
//Setter pour la quantité en stock
void article::setQnt(int q){
    this->qnt=q;
}
//Setter pour le nom
void article::setNom(string s){
    this->nom=s;
}
//Surcharge de la méthode toString pour afficher article
string article::toString(){
    cout << "L'article à référence <" << num_ref<<">\nø Son prix= "<<prixV<<"TND\nø Sa quantité en stock= "<<qnt<< endl;
}