#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Article.h"
#include "Stock.h"

int main() {
    //open csv file
    std::ifstream inputCsv("Lager.csv");
    if (!inputCsv.is_open()) {
        std::cerr << "Error: Could not open file." << "\n";
        return 1;
    }

    //create an array to store values
    const int size = 5;
    Article articles[size];
    Stock stocks[size];

    //loop while there are still lines in the csv file
    std::string line;
    int index = 0;
    while (std::getline(inputCsv, line)) {
        std::stringstream ss(line);
        std::string value;

        //parse the values from string
        std::getline(ss, value, ';');
        int articleNumber = std::stoi(value);

        std::getline(ss, value, ';');
        std::string description = value;

        std::getline(ss, value, ';');
        float costPrice = std::stof(value);

        std::getline(ss, value, ';');
        int actualStock = std::stoi(value);

        std::getline(ss, value, ';');
        int maximumStock = std::stoi(value);

        std::getline(ss, value, ';');
        int consumption = std::stoi(value);

        std::getline(ss, value, ';');
        int orderDuration = std::stoi(value);

        //make new objects
        Article article(articleNumber, description, costPrice, orderDuration);
        Stock stock(article, actualStock, maximumStock, consumption);

        //store objects
        articles[index] = article;
        stocks[index] = stock;
        index++;
    }

    inputCsv.close();

    //open a new csv file
    std::ofstream outputCsv("Lager_updated.csv");
    if (!outputCsv.is_open()) {
        std::cerr << "Error: Could not create output file.\n";
        return 1;
    }

    // write header
    outputCsv << "ArticleNumber;Description;CostPrice;ActualStock;MaximumStock;ConsumptionPerDay;OrderDuration;ReorderPoint;OrderProposal\n";

    // process each article/stock
    for (int i = 0; i < size; i++) {
        const Article& article = articles[i];
        const Stock& stock = stocks[i];

        //calculate the reorder point and order proposal
        int reorderPoint = (article.getOrderDuration() + 2) * stock.getConsumption();
        int orderProposal = 0;
        if (stock.getActualStock() <= reorderPoint) {
            orderProposal = reorderPoint - stock.getActualStock();
        }

        // write the row
        outputCsv << article.getNumberOfArticle() << ";"
                << article.getDescription() << ";"
                << article.getCostPrice() << ";"
                << stock.getActualStock() << ";"
                << stock.getMaximumStock() << ";"
                << stock.getConsumption() << ";"
                << article.getOrderDuration() << ";"
                << reorderPoint << ";"
                << orderProposal << "\n";
    }

    outputCsv.close();

    std::cout << "Updated stock file: Lager_updated.csv\n";
    return 0;
}
