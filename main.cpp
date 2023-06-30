#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>


struct Date {
    int day;
    int month;
    int year;
};

struct Provider {
    std::string name;
    std::string phone;
    std::string identificationNumber;
};

struct Wine {
    std::string wineCode;
    std::string name;
    std::string brand;
    Date productionDate;
    Date entryDate;
    std::string type;
    double priceWithoutTaxes;
    double sellingPrice;
    Provider provider;
};

std::vector<Wine> inventory;

bool isNumericStr( std::string str){
    for (char i : str) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

bool isAlphaNumericStr( std::string str){
    for (char i : str) {
        if (!isalnum(i)) {
            return false;
        }
    }
    return true;
}

bool codeIsInUse(std::string code, std::vector<Wine> inventory) {
    for (auto wine : inventory) {
        if (wine.wineCode == code) {
            return true;
        }
    }
    return false;
}

bool isAlphaStr( std::string str){
    for (char i : str) {
        if (!isalpha(i)) {
            return false;
        }
    }
    return true;
}

void addWine() {
    Wine newWine;

//Wine Code
    while (true){
        std::cout<< std::endl;
        std::cout << "Enter the wine code: "; //has to be string
        std::cin >> newWine.wineCode;
        std::cout<< std::endl;

        //validates if the wine code is alphanumeric
        if (!isAlphaNumericStr(newWine.wineCode)) {
            std::cout << "The wine code must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        //validates code is not repeated
        if (codeIsInUse(newWine.wineCode, inventory)) {
            std::cout << "The wine code is already in use." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }


//Wine Name
    while (true){
        std::cout << "Enter the wine name: ";
        std::cin >> newWine.name;
        std::cout<< std::endl;

        if (!isAlphaNumericStr(newWine.name)) {
            std::cout << "The wine name must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }


//Brand Name
    while (true){
        std::cout << "Enter the brand: ";
        std::cin >> newWine.brand;
        std::cout<< std::endl;

        if (!isAlphaNumericStr(newWine.brand)) {
            std::cout << "The wine name must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }



//Production Date
    while (true){
        std::cout << "Enter the production day: ";
        std::cin >> newWine.productionDate.day;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }


        if (newWine.productionDate.day > 31 || newWine.productionDate.day < 1) {
            std::cout<<"The day must be between 1 and 31."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    while (true){

        std::cout << "Enter the production month: ";
        std::cin >> newWine.productionDate.month;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (newWine.productionDate.month > 12 || newWine.productionDate.month < 1) {
            std::cout<<"The month must be between 1 and 12."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    while (true){

        std::cout << "Enter the production year: ";
        std::cin >> newWine.productionDate.year;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (newWine.productionDate.year > 2023) {
            std::cout<<"Invalid Year."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }



//Entry Dates

    while (true){
        std::cout << "Enter the entry year: ";
        std::cin >> newWine.entryDate.year;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (newWine.entryDate.year > 2023) {
            std::cout<<"Invalid Year."<<std::endl;
            std::cout<< std::endl;
            continue;
        }

        if (newWine.entryDate.year < 1960) {
            std::cout<<"Invalid Year."<<std::endl;
            std::cout<< std::endl;
            continue;
        }

        if (newWine.entryDate.year < newWine.productionDate.year) {
            std::cout<<"The entry year must be greater than the production year."<<std::endl;
            std::cout<< std::endl;
            continue;
        }

        break;
    }


    while (true){
        std::cout << "Enter the entry month: ";
        std::cin >> newWine.entryDate.month;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (newWine.entryDate.month > 12 || newWine.entryDate.month < 1) {
            std::cout<<"The month must be between 1 and 12."<<std::endl;
            std::cout<< std::endl;
            continue;
        }

        if (newWine.entryDate.year == newWine.productionDate.year) {
            if (newWine.entryDate.month < newWine.productionDate.month) {
                std::cout<<"The entry month must be greater than the production month."<<std::endl;
                std::cout<< std::endl;
                continue;
            }
        }
        break;
    }


    while (true){
        std::cout << "Enter the entry day: ";
        std::cin >> newWine.entryDate.day;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (newWine.entryDate.day > 31 || newWine.entryDate.day < 1) {
            std::cout<<"The day must be between 1 and 31."<<std::endl;
            std::cout<< std::endl;
            continue;
        }

        if (newWine.entryDate.year == newWine.productionDate.year) {
            if (newWine.entryDate.month == newWine.productionDate.month) {
                if (newWine.entryDate.day < newWine.productionDate.day) {
                    std::cout<<"The entry day must be greater than the production day."<<std::endl;
                    std::cout<< std::endl;
                    continue;
                }
            }
        }

        break;
    }



//Wine Type
    while (true){
        std::cout << "Enter the wine type(Red, White, Rose): ";
        std::cin >> newWine.type;
        //turns the string to uppercase
        for (int i = 0; i < newWine.type.length(); i++) {
            newWine.type[i] = toupper(newWine.type[i]);
        }
        std::cout<< std::endl;

        if (newWine.type != "RED" && newWine.type != "WHITE" && newWine.type != "ROSE") {
            std::cout<<"Invalid wine type."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

//Price without taxes
    while (true){
        std::cout << "Enter the price without taxes: ";
        std::cin >> newWine.priceWithoutTaxes;
        std::cout<< std::endl;

        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (newWine.priceWithoutTaxes < 0) {
            std::cout<<"The price must be positive."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

//Selling Price
    newWine.sellingPrice = newWine.priceWithoutTaxes + (newWine.priceWithoutTaxes * 0.15);

//Provider name
    while (true){
        std::cout << "Enter the provider name: ";
        std::cin >> newWine.provider.name;
        std::cout<< std::endl;

        if (!isAlphaStr(newWine.provider.name)){
            std::cout<<"The provider name must be alphabetic."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }


//Provider phone
    while (true){
        std::cout << "Enter the provider phone: ";
        std::cin >> newWine.provider.phone;
        std::cout<< std::endl;

        if (!isNumericStr(newWine.provider.phone)){
            std::cout<<"The provider phone must be numeric."<<std::endl;
            std::cout<< std::endl;
            continue;
        }

        break;
    }


//Provider identification number
    while (true){
        std::cout << "Enter the provider identification number: ";
        std::cin >> newWine.provider.identificationNumber;
        std::cout<< std::endl;

        if (!isNumericStr(newWine.provider.identificationNumber)){
            std::cout<<"The provider identification number must be numeric."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        if (newWine.provider.identificationNumber.length() != 11){
            std::cout<<"The provider identification number must have 11 digits."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }



//NewWine Push
    inventory.push_back(newWine);

    std::cout << "Wine added successfully!" << std::endl;
    std::cout<< std::endl;

}

void viewInventory() {
    if (inventory.empty()) {
        std::cout<< std::endl;
        std::cout << "The inventory is empty." << std::endl;
        std::cout<< std::endl;

    } else {
        std::cout<< std::endl;
        std::cout<< std::endl;
        std::cout << "Wine Inventory:" << std::endl;
        for (const auto& wine : inventory) {
            std::cout << "Code: " << wine.wineCode << std::endl;
            std::cout << "Name: " << wine.name << std::endl;
            std::cout << "Brand: " << wine.brand << std::endl;
            std::cout << "Production Date: " << wine.productionDate.day << "/" << wine.productionDate.month << "/" << wine.productionDate.year << std::endl;
            std::cout << "Entry Date: " << wine.entryDate.day << "/" << wine.entryDate.month << "/" << wine.entryDate.year << std::endl;
            std::cout << "Type: " << wine.type << std::endl;
            std::cout << "Price without taxes: " << wine.priceWithoutTaxes << std::endl;
            std::cout << "Selling Price: " << wine.sellingPrice << std::endl;
            std::cout << "Provider Name: " << wine.provider.name << std::endl;
            std::cout << "Provider Phone: " << wine.provider.phone << std::endl;
            std::cout << "Provider Identification Number: " << wine.provider.identificationNumber << std::endl;
            std::cout << std::endl;
            std::cout<<"---------------------------------"<<std::endl;
        }
    }
}


void searchByName() {

    std::string name;
    while (true){
        std::cout << "Enter the wine name to search for: ";
        std::cin >> name;
        std::cout<< std::endl;

        //validates if the wine code is alphanumeric
        if (!isAlphaNumericStr(name)) {
            std::cout << "The wine name must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    bool found = false;
    for (const auto& wine : inventory) {
        if (wine.name == name) {
            found = true;
            std::cout << "Wine Found:" << std::endl;
            std::cout << "Code: " << wine.wineCode << std::endl;
            std::cout << "Name: " << wine.name << std::endl;
            std::cout << "Brand: " << wine.brand << std::endl;
            std::cout << "Production Date: " << wine.productionDate.day << "/" << wine.productionDate.month << "/" << wine.productionDate.year << std::endl;
            std::cout << "Entry Date: " << wine.entryDate.day << "/" << wine.entryDate.month << "/" << wine.entryDate.year << std::endl;
            std::cout << "Type: " << wine.type << std::endl;
            std::cout << "Price without taxes: " << wine.priceWithoutTaxes << std::endl;
            std::cout << "Selling Price: " << wine.sellingPrice << std::endl;
            std::cout << "Provider Name: " << wine.provider.name << std::endl;
            std::cout << "Provider Phone: " << wine.provider.phone << std::endl;
            std::cout << "Provider Identification Number: " << wine.provider.identificationNumber << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << std::endl;
        std::cout << "Wine " << name << " not found." << std::endl;
        std::cout << std::endl;


    }
}

void updateSellingPrice() {
    std::string code;

    while (true){
        std::cout << "Enter the wine code to update the selling price: ";
        std::cin >> code;

        //validates if the wine code is alphanumeric
        if (!isAlphaNumericStr(code)) {
            std::cout << "The wine code must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    bool found = false;
    for (auto& wine : inventory) {
        if (wine.wineCode == code) {
            found = true;
            double newSellingPrice;
            std::cout << "Enter the new selling price: ";
            std::cin >> newSellingPrice;
            wine.sellingPrice = newSellingPrice;
            std::cout << "Selling price updated successfully!" << std::endl;
            std::cout << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << std::endl;
        std::cout << "Wine with code " << code << " not found." << std::endl;
        std::cout << std::endl;
    }
}


void updateEntryDate() {

    std::string code;
    while (true){
        std::cout << "Enter the wine code to update the entry date: ";
        std::cin >> code;

        //validates if the wine code is alphanumeric
        if (!isAlphaNumericStr(code)) {
            std::cout << "The wine code must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    bool found = false;
    for (auto& wine : inventory) {
        if (wine.wineCode == code) {
            found = true;
            Date newEntryDate;

            while (true){
                std::cout << "Enter the entry year: ";
                std::cin >> newEntryDate.year;
                std::cout<< std::endl;

                if (std::cin.good())
                {
                    //Input is okay
                }
                else
                {
                    // resets the buffer's state to good
                    std::cin.clear();
                    //empty it
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid input." << std::endl;
                    continue;
                }

                if (newEntryDate.year > 2023) {
                    std::cout<<"Invalid Year."<<std::endl;
                    std::cout<< std::endl;
                    continue;
                }

                if (newEntryDate.year < 1960) {
                    std::cout<<"Invalid Year."<<std::endl;
                    std::cout<< std::endl;
                    continue;
                }

                if (newEntryDate.year < wine.productionDate.year) {
                    std::cout<<"The entry year must be greater than the production year."<<std::endl;
                    std::cout<< std::endl;
                    continue;
                }

                break;
            }


            while (true){
                std::cout << "Enter the entry month: ";
                std::cin >> newEntryDate.month;
                std::cout<< std::endl;

                if (std::cin.good())
                {
                    //Input is okay
                }
                else
                {
                    // resets the buffer's state to good
                    std::cin.clear();
                    //empty it
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid input." << std::endl;
                    continue;
                }

                if (newEntryDate.month > 12 || newEntryDate.month < 1) {
                    std::cout<<"The month must be between 1 and 12."<<std::endl;
                    std::cout<< std::endl;
                    continue;
                }

                if (newEntryDate.year == wine.productionDate.year) {
                    if (newEntryDate.month < wine.productionDate.month) {
                        std::cout<<"The entry month must be greater than the production month."<<std::endl;
                        std::cout<< std::endl;
                        continue;
                    }
                }
                break;
            }


            while (true){
                std::cout << "Enter the entry day: ";
                std::cin >> newEntryDate.day;
                std::cout<< std::endl;

                if (std::cin.good())
                {
                    //Input is okay
                }
                else
                {
                    // resets the buffer's state to good
                    std::cin.clear();
                    //empty it
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid input." << std::endl;
                    continue;
                }

                if (newEntryDate.day > 31 || newEntryDate.day < 1) {
                    std::cout<<"The day must be between 1 and 31."<<std::endl;
                    std::cout<< std::endl;
                    continue;
                }

                if (newEntryDate.year == wine.productionDate.year) {
                    if (newEntryDate.month == wine.productionDate.month) {
                        if (newEntryDate.day < wine.productionDate.day) {
                            std::cout<<"The entry day must be greater than the production day."<<std::endl;
                            std::cout<< std::endl;
                            continue;
                        }
                    }
                }

                break;
            }
            wine.entryDate = newEntryDate;
            std::cout << "Entry date updated successfully!" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Wine with code " << code << " not found." << std::endl;
    }
}

void searchByProvider() {
    std::string providerId;

    while (true){
        std::cout << "Enter the DNI of the provider: ";
        std::cin >> providerId;
        std::cout<< std::endl;

        if (!isNumericStr(providerId)){
            std::cout<<"The provider identification number must be numeric."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        if (providerId.length() != 11){
            std::cout<<"The provider identification number must have 11 digits."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    bool found = false;
    std::cout << "Wines provided by " << providerId << ":" << std::endl;
    for (const auto& wine : inventory) {
        if (wine.provider.name == providerId) {
            found = true;
            std::cout << "Code: " << wine.wineCode << std::endl;
            std::cout << "Name: " << wine.name << std::endl;
            std::cout << "Brand: " << wine.brand << std::endl;
            std::cout << "Production Date: " << wine.productionDate.day << "/" << wine.productionDate.month << "/" << wine.productionDate.year << std::endl;
            std::cout << "Entry Date: " << wine.entryDate.day << "/" << wine.entryDate.month << "/" << wine.entryDate.year << std::endl;
            std::cout << "Type: " << wine.type << std::endl;
            std::cout << "Price without taxes: " << wine.priceWithoutTaxes << std::endl;
            std::cout << "Selling Price: " << wine.sellingPrice << std::endl;
            std::cout << "Provider Name: " << wine.provider.name << std::endl;
            std::cout << "Provider Phone: " << wine.provider.phone << std::endl;
            std::cout << "Provider Identification Number: " << wine.provider.identificationNumber << std::endl;
            std::cout << std::endl;
            std::cout<<"---------------------------------"<<std::endl;
        }
    }

    if (!found) {
        std::cout<< std::endl;
        std::cout << "No wines found for provider " << providerId << std::endl;
        std::cout<< std::endl;
    }
}



void writeCSV() {
    remove("./inventory.csv");
    std::ofstream inventory_file;
    inventory_file.open("./inventory.csv",  std::ios::app);
    inventory_file << "Wine Code, Name, Brand, Production Date, Entry Date, Wine Type, Price Without Taxes, Selling Price, Provider Name, Provider Phone, Provider DNI " << std::endl;
    for (const Wine& w : inventory) {
        inventory_file << w.wineCode<<","<<w.name<<","<<w.brand<<","<<std::to_string(w.productionDate.day)<<"/"<<std::to_string(w.productionDate.month)<<"/"<<std::to_string(w.productionDate.year)
        <<","<<std::to_string(w.entryDate.day)<<"/"<<std::to_string(w.entryDate.month)<<"/"<<std::to_string(w.entryDate.year)<<","<<w.type<<","<<w.priceWithoutTaxes<<","<<w.sellingPrice<<","<<w.provider.name<<","
        <<w.provider.phone<<","<<w.provider.identificationNumber<<"\n";
    }
    inventory_file.close();
}


void deleteWine() {
    std::string code;

    while (true){
        std::cout << "Enter the wine code to delete: ";
        std::cin >> code;

        //validates if the wine code is alphanumeric
        if (!isAlphaNumericStr(code)) {
            std::cout << "The wine code must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    bool found = false;
    for (auto i = inventory.begin(); i != inventory.end(); ++i) {
        if (i->wineCode == code) {
            found = true;
            inventory.erase(i);
            std::cout << "Wine with code " << code << " deleted successfully!" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Wine with code " << code << " not found." << std::endl;
    }
}


//get info of product in a .csv file
void writeProductCSV(){
    std::string code;

    while (true){
        std::cout << "Enter the wine code to get the product info: ";
        std::cin >> code;
        std::cout<< std::endl;

        //validates if the wine code is alphanumeric
        if (!isAlphaNumericStr(code)) {
            std::cout << "The wine code must be alphanumeric." << std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }

    remove("./product.csv");
    std::ofstream product_file;
    product_file.open("./product.csv",  std::ios::app);
    product_file << "Wine Code, Name, Brand, Production Date, Entry Date, Wine Type, Price Without Taxes, Selling Price " << std::endl;
    for (const Wine& w : inventory) {
        if (w.wineCode == code){
            product_file << w.wineCode<<","<<w.name<<","<<w.brand<<","<<std::to_string(w.productionDate.day)<<"/"<<std::to_string(w.productionDate.month)<<"/"<<std::to_string(w.productionDate.year)
                         <<","<<std::to_string(w.entryDate.day)<<"/"<<std::to_string(w.entryDate.month)<<"/"<<std::to_string(w.entryDate.year)<<","<<w.type<<","<<w.priceWithoutTaxes<<","<<w.sellingPrice<<"\n";
        }
    }

}


//get info of provider in a .csv file
void writeProviderCSV(){

    std::string providerId;

    while (true){
        std::cout << "Enter the DNI of the provider: ";
        std::cin >> providerId;
        std::cout<< std::endl;

        if (!isNumericStr(providerId)){
            std::cout<<"The provider identification number must be numeric."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        if (providerId.length() != 11){
            std::cout<<"The provider identification number must have 11 digits."<<std::endl;
            std::cout<< std::endl;
            continue;
        }
        break;
    }


    remove("./provider.csv");
    std::ofstream provider_file;
    provider_file.open("./provider.csv",  std::ios::app);
    provider_file << "Provider Name, Provider Phone, Provider DNI " << std::endl;
    for (const Wine& w : inventory) {
        if (w.provider.identificationNumber == providerId){
            provider_file << w.provider.name<<","<<w.provider.phone<<","<<w.provider.identificationNumber<<"\n";
        }
    }
    provider_file.close();
}


int main() {

    int choice;


    while (true) {
        std::cout << "VEA Winery System" << std::endl;
        std::cout << "1. Add Wine" << std::endl;
        std::cout << "2. View Wine Inventory" << std::endl;
        std::cout << "3. Search Wine by Name" << std::endl;
        std::cout << "4. Update Selling Price" << std::endl;
        std::cout << "5. Update Entry Date" << std::endl;
        std::cout << "6. Search By Provider" << std::endl;
        std::cout << "7. Delete Wine" << std::endl;
        std::cout << "8. Get Product Info in CSV" << std::endl;
        std::cout << "9. Get Provider Info in CSV" << std::endl;
        std::cout << "10. Get List of All Products in CSV" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;


        if (std::cin.good())
        {
            //Input is okay
        }
        else
        {
            // resets the buffer's state to good
            std::cin.clear();
            //empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid input." << std::endl;
            std::cout<< std::endl;
            std::cout<< std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                addWine();
            break;
            case 2:
                viewInventory();
            break;
            case 3:
                searchByName();
            break;
            case 4:
                updateSellingPrice();
            break;
            case 5:
                updateEntryDate();
            break;
            case 6:
                searchByProvider();
            break;
            case 7:
                deleteWine();
            break;
            case 8:
                writeProductCSV();
            break;
            case 9:
                writeProviderCSV();
            break;
            case 10:
                writeCSV();
            break;
            case 0:
                std::cout << "Thanks for shopping with VEA, have a nice day." << std::endl;
                writeCSV();
            return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }


    return 0;
}