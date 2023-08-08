#include <iostream>
#include <string.h>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;
class Product{

    private:
    //why not public?
    int quantity;
    string name;
    string brand;
    string description;
    string code;
    float price;
    string dosageInstruction;
    string category;
    bool requires_prescription;

    public:

    string getName(){

        //TODO Add code that return the Product Name
        return name;
    }

    string getBrand(){
        //TODO Add code that return the Product Brand
        return brand;
    }

    string getDecrisption(){
        //TODO Add code that return the Product Description
        return description;
    }

    string getDosageInstraction(){
        //TODO Add code that return the Product Dosage Instruction
        return dosageInstruction;
    }

    string getCategory(){
        //TODO Add code that return the Product Category
        return category;
    }

    int getQuantity(){
        //TODO Add code that return the Product Quantity
        return quantity;
    }

    float getPrice(){
        //TODO Add code that return the Product Price
        return price;
    }

    bool getRequiresPrescription(){
        //TODO Add code that return Product Requires Prescription status
        return requires_prescription;
    }

    string generateUniqueCode()
    {
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        string uniqueCode = "";
        auto now = system_clock::now();
        auto millis = duration_cast<milliseconds>(now.time_since_epoch());
        mt19937 generator(millis.count());
        uniform_int_distribution<int> distribution(0, 100000);

        // generate 10 characters long unique string

        for (int i = 0; i <= 10; i++)
        {
            int random_index = distribution(generator) % characters.length();
            uniqueCode += characters[random_index];
        }

        return uniqueCode;
    };

    string promptTextField(string promptText){

        // TODO Add code to prompt user for input for any Product string field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        string input;
        cout << "Enter Product String Field:";
        cin >> input;
        return input;
    }

    float promptNumberField(string promptText){
        // TODO Add code to prompt user for input for any Product Numeric field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        float input;
        cout << "Enter Product numeric field:";
        cin >> input;
        return input;
    }

    bool promptRequirePrescription()
    {
        // TODO Add code to prompt user for choosing if Product requires prescription.
        // User can type 1 or 0. 
        // it prompts a user and return user input in form of boolean. 
        bool input;
        cout << "If the product requires prescription type 1, if not type 0:";
        cin >> input;
        return input;

    }

    void createProduct()
    
    {
        // TODO Add code that calls promptTextField() method and prompt user for entering product name and update the name field.
        string name = promptTextField("Enter Product Name:");

        // TODO Add code that calls promptTextField() method and prompt user for entering product brand and update the brand field.
        string brand = promptTextField("Enter Product Brand:");
        // TODO Add code that calls promptTextField() method and prompt user for entering product description and update the decription field.
        string description = promptTextField("Enter Product Description:");
        // TODO Add code that calls promptTextField() method and prompt user for entering product category and update the category field.
        string category = promptTextField("Enter Product Category:");
        // TODO Add code that calls promptTextField() method and prompt user for entering product dosageInstruction and update the dosage instruction field.
        string dosageInstruction = promptTextField("Enter Product Dosage Instruction:");
        // TODO Add code that calls promptNumberField() method and prompt user for entering product quantity and update the quantity field.
        float quantity = promptNumberField("Enter Product Quantity:");
        // TODO Add code that calls promptNumberField() method and prompt user for entering product price and update the price field.
        float price = promptNumberField("Enter Product Price:");
        // TODO Add code that calls promptRequirePrescription() method and prompt user for entering product requires presc and update the requiresprescription field.
        bool requires_prescription = promptRequirePrescription();
        // Add code to generate Unique code for product using generateUniqueCode method 


    };

    string toJson()
    {
        string productInJson;
      // TODO Add code for converting a product to json form from the private declared attributes.
      // The Output should look like:
      //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}

        json j;
        j["code"] = code;
        j["name"] = name;
        j["brand"] = brand;
        j["description"] = description;
        j["dosageInstruction"] = dosageInstruction;
        j["price"] = price;
        j["quantity"] = quantity;
        j["category"] = category;
        j["requires_prescription"] = requires_prescription;

        return productInJson;
    };


    
    void productFromJson(string txt)
    {
        //TODO Add code to convert a json string product to product object
        // string is in the form below
        //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
        // You need to extract value for each field and update private attributes declared above.

        json j = json::parse(txt);
        code = j["code"];
        name = j["name"];
        brand = j["brand"];
        description = j["description"];
        dosageInstruction = j["dosageInstruction"];
        price = j["price"];
        quantity = j["quantity"];
        category = j["category"];
        requires_prescription = j["requires_prescription"];

    };
};
