#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string itemID, itemName, search;
    int itemQuantity, itemPrice;
    fstream file, file1;
    int totalAmount = 1, quantity, itemRate;
    char _choice;

public:
    void addProduct(void);
    void viewProduct(void);
    void buyProduct(void);
} obj;
int main()
{
    char choice;
    cout << "Press 1 - - > Start Shopping..\n";
    cout << "Press 0 - - > Exit......\n";
    cin >> choice;

    switch (choice)
    {
    case 'A':
        obj.addProduct();
        break;
    case '1':
        obj.viewProduct();
        obj.buyProduct();
        break;
    case '0':
        system("exit");
        break;
    default:
        cout << "Invalid Selection....";
        break;
    }
    return 0;
}
void temp ::addProduct()
{
    cout << "Enter product ID :\n";
    cin >> itemID;
    cout << "Enter product name :\n";
    cin >> itemName;
    cout << "Enter product quantity :\n";
    cin >> itemQuantity;
    cout << "Enter product price :\n";
    cin >> itemPrice;

    file.open("Sdata.txt", ios ::out | ios ::app);
    file << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
    file.close();
}
void temp ::viewProduct()
{
    file.open("Sdata.txt", ios ::in);
    file >> itemID >> itemName >> itemQuantity >> itemPrice;
    while (!file.eof())
    {
        cout << "- - - - - - - - - - - - - \n";
        cout << "Product ID\t\tProduct Name\t\tQuantity\t\tProduct Price" << endl;
        cout << itemID << "\t\t\t" << itemName << "\t\t\t" << itemQuantity << "\t\t\t" << itemPrice << endl;
        cout << "- - - - - - - - - - - - - \n";
        file >> itemID >> itemName >> itemQuantity >> itemPrice;
    }
    file.close();
}
void temp ::buyProduct()
{
    _choice = 'y';
    while (_choice == 'y')
    {
        file.open("Sdata.txt", ios ::in);
        file1.open("Sdata1.txt", ios ::out | ios ::app);
        file >> itemID >> itemName >> itemQuantity >> itemPrice;
        cout << "Enter Product ID :\n";
        cin >> search;
        cout << "Enter quantity\n";
        cin >> quantity;
        while (!file.eof())
        {
            if (itemID == search)
            {
                itemQuantity = itemQuantity - quantity;
                file1 << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
                itemRate = quantity * itemPrice;
                totalAmount = totalAmount * itemRate;
                cout << "- - - -Payment Bill- - - - " << endl;
                cout << "Total Purchase Amount :" << totalAmount << endl;
                cout << "- - - - - - - - - - - - - - " << endl;
            }
            else
            {
                file1 << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
            }
            file >> itemID >> itemName >> itemQuantity >> itemPrice;
        }
        file.close();
        file1.close();
        remove("Sdata.txt");
        rename("S1data.txt", "Sdata.txt");
        cout << "\nContinue Shopping ? (Y / N)";
        cin >> _choice;
    }
}