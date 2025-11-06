#ifndef ASSIGNMENT3_STOCK_H
#define ASSIGNMENT3_STOCK_H
#include "Article.h"

class Stock {
private:
    int articleNumber;
    int actualStock;
    int maximumStock;
    int consumption;

public:
    //Constructors
    Stock(); //default
    Stock(const Article& num, int actualStock, int maximumStock, int consumption); //with parameters

    //Getter methods
    int getArticleNumber() const;
    int getActualStock() const;
    int getMaximumStock() const;
    int getConsumption() const;

    //Setter methods
    void setActualStock(int stock);
    void setMaximumStock(int max);
    void setConsumption(int consumption);
};


#endif //ASSIGNMENT3_STOCK_H