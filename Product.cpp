#include <iostream>
#include <string.h>
#include <chrono>
#include <random>
#include <string>
#include <regex>
#include <map>


using namespace std;
using namespace std::chrono;



class Product{

    private:
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

    string getDescription(){
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

//Setters
    void setName(string name){
        //TODO Add code that set the Product Name
        this->name = name;
    }

    void setBrand(string brand){
        //TODO Add code that set the Product Brand
        this->brand = brand;
    }

    void setDescription(string description){
        //TODO Add code that set the Product Description
        this->description = description;
    }
    //write setters for the remaining getter
    void setDosageInstraction(string dosageInstruction){
        //TODO Add code that set the Product Dosage Instruction
        this->dosageInstruction = dosageInstruction;
    }

    void setCategory(string category){
        //TODO Add code that set the Product Category
        this->category = category;
    }

    void setQuantity(int quantity){
        //TODO Add code that set the Product Quantity
        this->quantity = quantity;
    }

    void setPrice(float price){
        //TODO Add code that set the Product Price
        this->price = price;
    }

    void setRequiresPrescription(bool requires_prescription){
        //TODO Add code that set Product Requires Prescription status
        this->requires_prescription = requires_prescription;
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
        cout << promptText;
        cin >> input;
        return input;

    }

    float promptNumberField(string promptText){
       // TODO Add code to prompt user for input for any Product Numeric field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        float input;
        cout << promptText;
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
         name = promptTextField("Enter Product Name:");

        // TODO Add code that calls promptTextField() method and prompt user for entering product brand and update the brand field.
         brand = promptTextField("Enter Product Brand:");
        // TODO Add code that calls promptTextField() method and prompt user for entering product description and update the decription field.
         description = promptTextField("Enter Product Description:");
        // TODO Add code that calls promptTextField() method and prompt user for entering product category and update the category field.
         category = promptTextField("Enter Product Category:");
        // TODO Add code that calls promptTextField() method and prompt user for entering product dosageInstruction and update the dosage instruction field.
         dosageInstruction = promptTextField("Enter Product Dosage Instruction:");
        // TODO Add code that calls promptNumberField() method and prompt user for entering product quantity and update the quantity field.
         quantity = promptNumberField("Enter Product Quantity:");
        // TODO Add code that calls promptNumberField() method and prompt user for entering product price and update the price field.
         price = promptNumberField("Enter Product Price:");
        // TODO Add code that calls promptRequirePrescription() method and prompt user for entering product requires presc and update the requiresprescription field.
         requires_prescription = promptRequirePrescription();
        // Add code to generate Unique code for product using generateUniqueCode method 



       
    };

    string toJson()
    {

       // string productInJson;

      // TODO Add code for converting a product to json form from the private declared attributes.
      // The Output should look like:
      //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
    std::ostringstream jsonStream;

    jsonStream << "{"
               << "\"code\":\"" << code << "\","
               << "\"name\":\"" << name << "\","
               << "\"brand\":\"" << brand << "\","
               << "\"description\":\"" << description << "\","
               << "\"dosage_instruction\":\"" << dosageInstruction << "\","
               << "\"price\":" << price << ","
               << "\"quantity\":" << quantity << ","
               << "\"category\":\"" << category << "\","
               << "\"requires_prescription\":" << requires_prescription
               << "}";

        // std::string jsonString
        //productInJson = 
        //  std::cout << jsonString << std::endl;

        return jsonStream.str();
    };


    
    void productFromJson(string JSONString)
    {
        //TODO Add code to convert a json string product to product object
        // string is in the form below
        //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
        // You need to extract value for each field and update private attributes declared above.
      // std::string jsonString = "{\"code\":\"tgtwdNbCnwx\",\"name\":\"name 1\",\"brand\":\"br 2\",\"description\":\"df\",\"dosage_instruction\":\"dfg\",\"price\":123.000000,\"quantity\":13,\"category\":\"des\",\"requires_prescription\":1}";

     name = extractValueFromJSON(JSONString, "name");
     brand = extractValueFromJSON(JSONString, "brand");
     description = extractValueFromJSON(JSONString, "description");
     dosageInstruction = extractValueFromJSON(JSONString, "dosage_instruction");
     category = extractValueFromJSON(JSONString, "category");
     price = stof(extractValueFromJSON(JSONString, "price"));
     quantity = stoi(extractValueFromJSON(JSONString, "quantity"));
     requires_prescription = stoi(extractValueFromJSON(JSONString, "requires_prescription"));

    };



    // Function to extract value from a JSON string based on a key using regex
    string extractValueFromJSON(const std::string& jsonString, const std::string& key) {
    regex regex("\"" + key + "\"\\s*:\\s*\"([^\"]*)\"");
    smatch match;

    if (std::regex_search(jsonString, match, regex)) {
        if (match.size() > 1) {
            return match[1].str();
        }
    }
    return "Key not found";
}

};
