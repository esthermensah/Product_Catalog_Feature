#include "SearchProduct.cpp"

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

        int choice;
        while(true){
            cout<<"Menu:" <<endl;
            cout<<"1. Add Product"<<endl;
            cout<<"2. Search Product By Name"<<endl;
            cout<<"3. Search Product By Category"<<endl;
            cout<<"4. Search Product By Brand"<<endl;
            cout<<"5. Update Product"<<endl;
            cout<<"6. Delete Product"<<endl;
            cout<<"7. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                    addProduct();
                    break;
                case 2:
                    searchByName();
                    break;
                case 3:
                    searchByCategory();
                    break;
                case 4:
                    searchByBrand();
                    break;
                case 5:
                 //   updateProduct();
                    break;
                case 6:
                  //  deleteProduct();
                    break;
                case 7:
                    exit(0);
                    break;
                default:
                    cout<<"Invalid Choice"<<endl;
                    break;
            }
        }




    }

    void addProduct(){
        // TODO add code to add product and 
        // store the product to products.json file by using Product class and FileHandler class
        Product p;
        cout << "Enter Product Name: ";
        cin >> p.name;
        cout << "Enter product brand: ";
        cin >> p.brand;
        cout << "Enter product category: ";
        cin >> p.category;
        cout << "Enter product price: ";
        cin >> p.price;

        fHandler.addProduct(p);
        
    }


    void updateProduct(){
    // TODO Add code to update a product
    

}

void deleteProduct(){
    // TODO Add code to delete a product
}
    
};

int main()
{

    // ADD Code for displaying a welcome Menu
    // and handle all required logic to add, search, update, and delete product

    return 0;
}


