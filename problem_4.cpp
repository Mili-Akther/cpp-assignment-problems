#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
public:
    int productID;
    string productName;
    double price;
    int stock;
    int sold = 0;
};

class Inventory {
private:
    Product products[100];
    int totalProducts = 0;
    double totalSales = 0;

public:

    int findProduct(int id) {
        for (int i = 0; i < totalProducts; i++) {
            if (products[i].productID == id)
                return i;
        }
        return -1;
    }

    void addProduct() {
        cout << "Product ID: ";
        cin >> products[totalProducts].productID;

        cin.ignore();

        cout << "Product Name: ";
        getline(cin, products[totalProducts].productName);

        cout << "Price: ";
        cin >> products[totalProducts].price;

        cout << "Stock: ";
        cin >> products[totalProducts].stock;

        totalProducts++;

        cout << "Product Added Successfully.\n";
    }

    void updateStock() {
        int id, quantity;

        cout << "Product ID: ";
        cin >> id;

        int index = findProduct(id);

        if (index == -1) {
            cout << "Product Not Found.\n";
            return;
        }

        cout << "Add Stock Quantity: ";
        cin >> quantity;

        products[index].stock += quantity;

        cout << "Stock Updated Successfully.\n";
    }

    void sellProduct() {
        int id, quantity;

        cout << "Product ID: ";
        cin >> id;

        int index = findProduct(id);

        if (index == -1) {
            cout << "Product Not Found.\n";
            return;
        }

        cout << "Quantity: ";
        cin >> quantity;

        if (quantity > products[index].stock) {
            cout << "Not Enough Stock.\n";
            return;
        }

        double bill = quantity * products[index].price;

        products[index].stock -= quantity;
        products[index].sold += quantity;
        totalSales += bill;

        cout << "\n CUSTOMER BILL \n";
        cout << "Product : " << products[index].productName << endl;
        cout << "Price   : " << products[index].price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total   : " << bill << endl;
    }

  void showTotalSales() {
    cout << fixed << setprecision(0);
    cout << "\nTotal Sales = " << totalSales << endl;
}

    void bestSellingProduct() {

        if (totalProducts == 0) {
            cout << "No Products Available.\n";
            return;
        }

        int best = 0;

        for (int i = 1; i < totalProducts; i++) {
            if (products[i].sold > products[best].sold)
                best = i;
        }

        cout << "\nBest Selling Product\n";
        cout << "Product ID   : " << products[best].productID << endl;
        cout << "Product Name : " << products[best].productName << endl;
        cout << "Sold Quantity: " << products[best].sold << endl;
    }
};

int main() {

    Inventory inventory;
    int choice;

    do {

        cout << "\n INVENTORY MENU \n";
        cout << "1. Add Product\n";
        cout << "2. Update Stock\n";
        cout << "3. Sell Product\n";
        cout << "4. Total Sales\n";
        cout << "5. Best Selling Product\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            inventory.addProduct();
            break;

        case 2:
            inventory.updateStock();
            break;

        case 3:
            inventory.sellProduct();
            break;

        case 4:
            inventory.showTotalSales();
            break;

        case 5:
            inventory.bestSellingProduct();
            break;

        case 6:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}
