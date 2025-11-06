#include "Stock.h"

//Default constructor
Stock::Stock()
    : articleNumber(0), actualStock(0), maximumStock(0), consumption(0) {}
Stock::Stock(const Article &num, int actualStock, int maximumStock, int consumption)
    : articleNumber(num.getNumberOfArticle()), actualStock(actualStock), maximumStock(maximumStock), consumption(consumption) {}

// Getters
int Stock::getArticleNumber() const {
    return articleNumber;
}
int Stock::getActualStock() const {
    return actualStock;
}
int Stock::getMaximumStock() const {
    return maximumStock;
}
int Stock::getConsumption() const {
    return consumption;
}

// Setters
void Stock::setActualStock(int stock) {
    actualStock = stock;
}
void Stock::setMaximumStock(int max) {
    maximumStock = max;
}
void Stock::setConsumption(int val) {
    consumption = val;
}