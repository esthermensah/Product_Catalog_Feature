#include "FileHandler.cpp"

class SearchProduct
{
private:
    string filename;

public:
    string searchText;
    FileHandler fHandler;

    string to_lowercase(const string& text) {
        string lowercase_text;
        for (char c : text) {
            lowercase_text += tolower(c);
        }
        return lowercase_text;
    }

    vector<Product> searchByName(string name){
        // TODO
        //Add code to search by name. Searching is not case sensitive it means         
        //for input like: "name" products with names like "Name 1", "Product name" needs to included in the found results.
        vector<Product>  result;
        for (Product p : fHandler.readJsonFile()) {
            //    for (Product p : fHandler.getProducts()) {        
            if (to_lowercase(p.getName()).find(to_lowercase(name)) != string::npos) {
                result.push_back(p);
            }
        }
        return result;    
    };

    vector<Product> searchByCategory(string categ){

        // TODO
        //Add code to search by category. Searching is not case sensitive it means 
        //for input like: "categ" products with category like "category 1", "Product category" needs to included in the found results.
        vector<Product>  result;
        for (Product p : fHandler.readJsonFile()) {
            //    for (Product p : fHandler.getProducts()) {        
            if (to_lowercase(p.getCategory()).find(to_lowercase(categ)) != string::npos) {
                result.push_back(p);
            }
        }
        return result;
    
    
    };

    vector<Product> searchByBrand(string brand){
      // TODO
        //Add code to search by brand. Searching is not case sensitive it means 
        //for input like: "br" products with names like "Brand 1", "brand name" needs to included in the found results.
        vector<Product>  result;
        for (Product p : fHandler.readJsonFile()) {
            //    for (Product p : fHandler.getProducts()) {        
            if (to_lowercase(p.getBrand()).find(to_lowercase(brand)) != string::npos) {
                result.push_back(p);
            }
        }
        return result;
    };

    void showSearchResult(vector<Product> plist, string sTxt)
    {    
        // TODO
        //Add code to display Search results
        cout<< "Search results for:\"" << sTxt << "\":" << endl;
        if (plist.size() == 0) {
            cout << "No results found" << endl;
            return;
        }
        else {
            for (Product p : plist) {
                cout << "Name: "<< p.name << endl;
                cout << "Brand: "<< p.brand << endl;
                cout << "Description: "<< p.description << endl;
                cout << "Category: "<< p.category << endl;
                cout << "Price: $"<< p.price << endl;

            }
        }

    }
};