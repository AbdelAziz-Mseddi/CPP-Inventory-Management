# Gestion Stock - Inventory Management System

A C++ application for managing an inventory system with article management, search functionality, and persistent file storage.

## Features

- **Add Articles**: Add new articles to the stock with reference number, name, price, and quantity
- **Search Articles**: 
  - Search by reference number
  - Search by name
  - Search by price range
- **Delete Articles**: Remove articles from the stock
- **Modify Articles**: Update article details (reference, name, price, quantity)
- **Display Stock**: View all articles in the stock with formatted output
- **Save to File**: Export all articles to `stock.txt` for persistence

## Project Structure

```
gestion_stock/
├── article.h          # Article class definition
├── article.cpp        # Article class implementation
├── stock.h            # Stock class definition
├── stock.cpp          # Stock class implementation
├── main.cpp           # Main program entry point
└── README.md          # This file
```

## Class Details

### Article Class
Represents a single article in the inventory.

**Attributes:**
- `num_ref` (int): Reference number
- `nom` (string): Article name
- `prixV` (double): Selling price
- `qnt` (int): Quantity in stock

**Methods:**
- Getters: `getRef()`, `getNom()`, `getPrixv()`, `getQnt()`
- Setters: `setNum()`, `setNom()`, `setPriv()`, `setQnt()`
- `toString()`: Return formatted article information

### Stock Class
Manages a collection of articles.

**Attributes:**
- `arr` (vector): Vector of articles
- `qnt` (int): Number of articles in stock

**Methods:**
- `ajout_article(article)`: Add article to stock
- `supp_article(int ref)`: Remove article by reference number
- `rechref_art(int ref)`: Search article by reference
- `rechnom_art(string name)`: Search article by name
- `rechpri_art(double p1, double p2)`: Search articles within price range
- `modif_article(...)`: Modify article details
- `afficher()`: Display all articles
- `stock_stock(string filename)`: Save articles to file

## Compilation

Compile the project with:
```bash
g++ *.cpp *.h -o main
```

## Usage

Run the program:
```bash
./main.exe
```

### Example Output
```
=== Adding Articles ===
Added: Laptop (Ref: 101, Price: 25.50, Qty: 100)
Added: Mouse (Ref: 102, Price: 15.75, Qty: 50)

=== All Articles ===
øøøø- STOCK -øøøø
Article 1:
  Reference: 101
  Nom: Laptop
  Prix: 25.5 TND
  Quantite: 100
øøøøøøøøø
...

=== Saving to stock.txt ===
Articles saved to stock.txt
```

## File Output

The `stock.txt` file contains all articles in the format:
```
L'article à référence <101>
ø Son prix= 25.5TND
ø Sa quantité en stock= 100

L'article à référence <102>
...
```

## Language

The application uses French for output messages and comments:
- `Nom` - Name
- `Prix` - Price
- `Quantité` - Quantity
- `Référence` - Reference number
- `TND` - Tunisian Dinar (currency)

## Requirements

- C++11 or later
- Standard C++ libraries (bits/stdc++.h)
- File I/O support

## Author

Created as a semester project for C++ programming course.