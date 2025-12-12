#include <bits/stdc++.h>
#include "stock.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    stock myStock;
    int choix = 0;
    
    cout << "ø GESTION DE STOCK - MENU PRINCIPAL ø" << endl;

    
    while(choix != 9){
        cout << " 1. Rechercher un article par reference  " << endl;
        cout << " 2. Ajouter un article au stock          " << endl;
        cout << " 3. Afficher tous les articles           " << endl;
        cout << " 4. Supprimer un article                 " << endl;
        cout << " 5. Modifier un article                  " << endl;
        cout << " 6. Rechercher un article par nom        " << endl;
        cout << " 7. Rechercher par intervalle de prix    " << endl;
        cout << " 8. Stocker tous les articles en fichier " << endl;
        cout << " 9. Quitter                              " << endl;

        cout << "Entrez votre choix: ";
        cin >> choix;
        cin.ignore();
        
        if(choix == 1){
            int ref;
            cout << "\nEntrez la reference de l'article: ";
            cin >> ref;
            cin.ignore();
            
            article art = myStock.rechref_art(ref);
            if(art.getRef() == 0){
                cout << "Article non trouve!" << endl;
            } else {
                cout << art.toString();
            }
        }
        
        else if(choix == 2){
            int ref, qnt;
            double prix;
            string nom;
            
            cout << "\nEntrez la reference: ";
            cin >> ref;
            cin.ignore();
            
            article existing = myStock.rechref_art(ref);
            if(existing.getRef() == ref){
                cout << "Erreur: Cette reference existe deja!" << endl;
                continue;
            }
            
            cout << "Entrez le nom: ";
            getline(cin, nom);
            
            cout << "Entrez le prix: ";
            cin >> prix;
            
            cout << "Entrez la quantite: ";
            cin >> qnt;
            cin.ignore();
            
            article newArt(ref, prix, qnt);
            newArt.setNom(nom);
            myStock.ajout_article(newArt);
            
            cout << "Article ajoute avec succes!" << endl;
        }
        
        else if(choix == 3){
            cout << endl;
            myStock.afficher();
        }
        
        else if(choix == 4){
            int ref;
            cout << "\nEntrez la reference de l'article à supprimer: ";
            cin >> ref;
            cin.ignore();
            
            myStock.supp_article(ref);
            cout << "Article supprime!" << endl;
        }
        
        else if(choix == 5){
            int ref, newRef, qnt;
            double prix;
            string nom;
            
            cout << "\nEntrez la reference de l'article à modifier: ";
            cin >> ref;
            cin.ignore();
            
            article existing = myStock.rechref_art(ref);
            if(existing.getRef() != ref){
                cout << "Article non trouve!" << endl;
                continue;
            }
            
            cout << "Entrez la nouvelle reference: ";
            cin >> newRef;
            cin.ignore();
            
            cout << "Entrez le nouveau nom: ";
            getline(cin, nom);
            
            cout << "Entrez le nouveau prix: ";
            cin >> prix;
            
            cout << "Entrez la nouvelle quantite: ";
            cin >> qnt;
            cin.ignore();
            
            myStock.modif_article(ref, newRef, prix, qnt, nom);
            cout << "Article modifie avec succes!" << endl;
        }
        
        else if(choix == 6){
            string nom;
            cout << "\nEntrez le nom à rechercher: ";
            getline(cin, nom);
            
            article art = myStock.rechnom_art(nom);
            if(art.getRef() == 0){
                cout << "Article non trouve!" << endl;
            } else {
                cout << art.toString();
            }
        }
        
        else if(choix == 7){
            double p1, p2;
            cout << "\nEntrez le prix minimum: ";
            cin >> p1;
            cout << "Entrez le prix maximum: ";
            cin >> p2;
            cin.ignore();
            
            cout << "\nArticles dans cet intervalle de prix:" << endl;
            stock result = myStock.rechpri_art(p1, p2);
            result.afficher();
        }
        
        else if(choix == 8){
            cout << "\nStockage des articles en cours..." << endl;
            myStock.stock_stock("stock.txt");
            cout << "Articles stockes dans D:\\" << endl;
        }
        
        else if(choix == 9){
            cout << "\nAuf Wiederesehen" << endl;
        }
        
        else {
            cout << "\nChoix invalide! Veuillez reessayer." << endl;
        }
    }
    
    return 0;
}