#include <bits/stdc++.h>
#include "stock.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    // Create a stock instance
    stock myStock;
    
    // Create and add articles
    cout << "=== Adding Articles ===" << endl;
    
    article art1(101, 25.50, 100);
    art1.setNom("Laptop");
    myStock.ajout_article(art1);
    cout << "Added: Laptop (Ref: 101, Price: 25.50, Qty: 100)" << endl;
    
    article art2(102, 15.75, 50);
    art2.setNom("Mouse");
    myStock.ajout_article(art2);
    cout << "Added: Mouse (Ref: 102, Price: 15.75, Qty: 50)" << endl;
    
    article art3(103, 45.00, 30);
    art3.setNom("Keyboard");
    myStock.ajout_article(art3);
    cout << "Added: Keyboard (Ref: 103, Price: 45.00, Qty: 30)" << endl;
    
    article art4(104, 12.99, 200);
    art4.setNom("USB Cable");
    myStock.ajout_article(art4);
    cout << "Added: USB Cable (Ref: 104, Price: 12.99, Qty: 200)" << endl;
    
    // Display all articles
    cout << "\n=== All Articles ===" << endl;
    myStock.afficher();
    
    // Save to file
    cout << "\n=== Saving to stock.txt ===" << endl;
    myStock.stock_stock("stock.txt");
    cout << "Articles saved to stock.txt" << endl;
    
    // Test search by reference
    cout << "\n=== Search by Reference (103) ===" << endl;
    article found = myStock.rechref_art(103);
    
    // Test search by name
    cout << "\n=== Search by Name (Mouse) ===" << endl;
    article foundByName = myStock.rechnom_art("Mouse");
    
    // Test search by price range
    cout << "\n=== Articles with price between 15 and 50 ===" << endl;
    stock priceRange = myStock.rechpri_art(15, 50);
    priceRange.afficher();
    
    // Delete an article
    cout << "\n=== Deleting article with Ref: 102 ===" << endl;
    myStock.supp_article(102);
    myStock.afficher();
    
    // Save again
    cout << "\n=== Saving updated stock to stock.txt ===" << endl;
    myStock.stock_stock("stock.txt");
    cout << "Updated stock saved!" << endl;
    
    return 0;
}