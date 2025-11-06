#include "Article.h"

// Default constructor
Article::Article()
    : numberOfArticle(0), description(""), costPrice(0.0f), orderDuration(0) {}

// Parameterized constructor
Article::Article(int num, const std::string& desc, float price, int duration)
    : numberOfArticle(num), description(desc), costPrice(price), orderDuration(duration) {}

// Getters
int Article::getNumberOfArticle() const {
    return numberOfArticle;
}
std::string Article::getDescription() const {
    return description;
}
float Article::getCostPrice() const {
    return costPrice;
}
int Article::getOrderDuration() const {
    return orderDuration;
}

// Setters
void Article::setNumberOfArticle(int num) {
    numberOfArticle = num;
}
void Article::setDescription(const std::string& desc) {
    description = desc;
}
void Article::setCostPrice(float price) {
    costPrice = price;
}
void Article::setOrderDuration(int duration) {
    orderDuration = duration;
}
