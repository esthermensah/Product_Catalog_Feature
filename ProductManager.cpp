#include "SearchProduct.cpp"
//#include "FileHandler.cpp"
#include <iostream>
#include <string>
#include <vector>
//#include "Product.cpp"


class ProductManager
{
private:
    Product prod;
public:

    int getMenu(){

        // TODO Add code to display Menu
        // Menu should have 
        // Add Product
        //Search Product By Name
        //Search Product By Category
        //Search Product By Brand
        // Update Product
        // Delete Product
        //int choice;
        
            cout<<"Menu:" <<endl;
            cout<<"1. Add Product"<<endl;
            cout<<"2. Search Product By Name"<<endl;
            cout<<"3. Search Product By Category"<<endl;
            cout<<"4. Search Product By Brand"<<endl;
            cout<<"5. Update Product"<<endl;
            cout<<"6. Delete Product"<<endl;
            cout<<"7. Exit"<<endl;
            cout<<"Enter your choice: ";
            //cin>>choice;
            return 0;
    }

    void addProduct(){
        // TODO add code to add product and 
        // store the product to products.json file by using Product class and FileHandler class
         // TODO add code to add product and 
        // store the product to products.json file by using Product class and FileHandler clas
        // TODO add code to add product and 
        // store the product to products.json file by using Product class and FileHandler class
        FileHandler fileHandler;
        prod.createProduct();
        fileHandler.saveToJsonFile(prod);
    
    }
   void updateProduct(){
     FileHandler fHandler;
    SearchProduct searchProduct;
    vector<Product>  result = vector<Product>();
    result = fHandler.readJsonFile();
    string name;
    cout << "Enter Product Name: ";
    cin>>name;
    result = searchProduct.searchByName(name);
    float price;
    int quantity;
    cout << "Enter new Price: ";
    cin >> price ;
    cout << "Enter new Quantity: ";
    cin >> quantity ;

    
    
    for(int i = 0; i < result.size(); i++){
        if (result[i].getName() == name){
            result[i].setPrice(price);
            result[i].setQuantity(quantity);
        }

    }     
    fHandler.saveToJsonFile(result);
    cout << "Product '" << name << "' has been updated." << endl;
   // saveToJsonFile(Product p)    

}

void deleteProduct() {
    FileHandler fHandler;
    SearchProduct searchProduct;
    vector<Product> result = fHandler.readJsonFile();

    string name;
    cout << "Enter Product Name to delete: ";
    cin >> name;

    vector<Product> newResult;
    bool deleted = false;

    for (int i = 0; i < result.size(); i++) {
        if (result[i].getName() != name) {
            newResult.push_back(result[i]);
        } else {
            deleted = true;
        }
    }

    if (!deleted) {
        cout << "Product not found." << endl;
    } else {
        fHandler.saveToJsonFile(newResult);
        cout << "Product '" << name << "' has been deleted." << endl;
    }
}

    
};

       



int main()
{
    ProductManager pm;
    pm.getMenu();
    cout<<"Enter your choice: ";
    // ADD Code for displaying a welcome Menu
    // and handle all required logic to add, search, update, and delete product
    while(true){
    int choice ;
cin>>choice;
    switch (choice)
    {
                case 1:{
                    pm.addProduct();
                    break;
                }
                case 2:{
                cout<<"Enter Product Name: ";
                SearchProduct sp;
                string searchName;
                cin>>searchName;
                vector<Product> products = sp.searchByName(searchName);
                    sp.showSearchResult(products,"Name");
                    break;}
                case 3:{
                    cout<<"Enter Product Category: ";
                SearchProduct sp;
                string searchCategory;
                cin>>searchCategory;
                vector<Product> products = sp.searchByCategory(searchCategory);
                    sp.showSearchResult(products,"Category");
                    break;}
                case 4:{
                    cout<<"Enter Product Brand: ";
                SearchProduct sp;
                string searchBrand;
                cin>>searchBrand;
                vector<Product> products = sp.searchByBrand(searchBrand);
                    sp.showSearchResult(products,"Brand");
                    break;}
                case 5:{
                    pm.updateProduct();
                    break;}
                case 6:{
                    pm.deleteProduct();
                    break;}
                case 7:{
                    exit(0);
                    break;}
                default:
                    cout<<"Invalid Choice"<<endl;
                    break;
            }
    }
    return 0;
}


