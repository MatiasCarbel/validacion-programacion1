#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>


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

void addWine() {
    Wine newWine;

    std::cout<< std::endl;
    std::cout << "Enter the wine code: ";
    std::cin >> newWine.wineCode;
    std::cout<< std::endl;

    //validate wine code is not repeated
    for (const auto& wine : inventory) {
        if (wine.wineCode == newWine.wineCode) {
            std::cout << "The wine code is already in use." << std::endl;
            std::cout<< std::endl;
            return;
        }
    }


    std::cout << "Enter the wine name: ";
    std::cin >> newWine.name;
    std::cout<< std::endl;

    //validate wine name is not repeated
    for (const auto& wine : inventory) {
        if (wine.name == newWine.name) {
            std::cout << "The wine name is already in use." << std::endl;
            std::cout<< std::endl;
            return;
        }
    }


    std::cout << "Enter the brand: ";
    std::cin >> newWine.brand;
    std::cout<< std::endl;


    std::cout << "Enter the production date (dd mm yyyy): ";
    std::cin >> newWine.productionDate.day >> newWine.productionDate.month >> newWine.productionDate.year;
    assert(newWine.productionDate.day <= 31 && newWine.productionDate.month <= 12 && newWine.productionDate.year <= 2023);
    std::cout<< std::endl;


    std::cout << "Enter the entry date (dd mm yyyy): ";
    std::cin >> newWine.entryDate.day >> newWine.entryDate.month >> newWine.entryDate.year;
    assert(newWine.entryDate.day <= 31 && newWine.entryDate.month <= 12 && newWine.entryDate.year <= 2023);
    assert(newWine.entryDate.day >= newWine.productionDate.day && newWine.entryDate.month >= newWine.productionDate.month && newWine.entryDate.year >= newWine.productionDate.year);
    std::cout<< std::endl;


    std::cout << "Enter the wine type(Red, White, Rose): ";
    std::cin >> newWine.type;
    assert(newWine.type == "Red" || newWine.type == "White" || newWine.type == "Rose");
    std::cout<< std::endl;


    std::cout << "Enter the price without taxes: ";
    std::cin >> newWine.priceWithoutTaxes;
    std::cout<< std::endl;



    newWine.sellingPrice = newWine.priceWithoutTaxes + (newWine.priceWithoutTaxes * 0.15);


    std::cout << "Enter the provider name: ";
    std::cin >> newWine.provider.name;
    std::cout<< std::endl;


    std::cout << "Enter the provider phone: ";
    std::cin >> newWine.provider.phone;
    std::cout<< std::endl;


    std::cout << "Enter the provider identification number: ";
    std::cin >> newWine.provider.identificationNumber;
    std::cout<< std::endl;


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
    std::cout << "Enter the wine code to search for: ";
    std::cin >> name;

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
    std::cout << "Enter the wine code to update the selling price: ";
    std::cin >> code;

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
    std::cout << "Enter the wine code to update the entry date: ";
    std::cin >> code;

    bool found = false;
    for (auto& wine : inventory) {
        if (wine.wineCode == code) {
            found = true;
            Date newEntryDate;
            std::cout << "Enter the new entry date (dd mm yyyy): ";
            std::cin >> newEntryDate.day >> newEntryDate.month >> newEntryDate.year;
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
    std::string providerName;
    std::cout << "Enter the provider name to search for: ";
    std::cin >> providerName;

    bool found = false;
    std::cout << "Wines provided by " << providerName << ":" << std::endl;
    for (const auto& wine : inventory) {
        if (wine.provider.name == providerName) {
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
        std::cout << "No wines found for provider " << providerName << std::endl;
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
    std::cout << "Enter the wine code to delete: ";
    std::cin >> code;

    bool found = false;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->wineCode == code) {
            found = true;
            inventory.erase(it);
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
    std::cout << "Enter the wine code to get the product info: ";
    std::cin >> code;
    std::cout<< std::endl;

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
    std::cout << "Enter the DNI of the provider: ";
    std::cin >> providerId;
    std::cout<< std::endl;

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
        std::cout << "3. Search Wine by Code" << std::endl;
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
                std::cout << "Goodbye..." << std::endl;
                writeCSV();
            return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }


    return 0;
}