#ifndef ASSIGNMENT3_ARTICLE_H
#define ASSIGNMENT3_ARTICLE_H

#include <string>


class Article {
private:
    int numberOfArticle;
    std::string description;
    float costPrice;
    int orderDuration;

public:
    //Constructors
    Article(); // default
    Article(int num, const std::string& desc, float price, int duration); //with parameters

    //Getter methods
    int getNumberOfArticle() const;
    std::string getDescription() const;
    float getCostPrice() const;
    int getOrderDuration() const;

    //Setter methods
    void setNumberOfArticle(int num);
    void setDescription(const std::string& desc);
    void setCostPrice(float price);
    void setOrderDuration(int duration);
};

#endif //ASSIGNMENT3_ARTICLE_H