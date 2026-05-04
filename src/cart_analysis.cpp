//cart_analysis.cpp

#include "cart_analysis.hpp"
#include <unordered_map>
#include <algorithm>

std::vector<std::string> find_common_products_across_carts(const std::vector<std::vector<std::string>>& carts) {
    
    std::vector<std::string> common; // vector to hold common items
    std::unordered_map<std::string, int> product_count; // counts the frequency of each item

    if (carts.empty()) {
        return common;
    }

    // iterate over all carts
    for (const auto& cart : carts) {
        for (const auto& product : cart) {  // iterate over all products in each cart
            // Increment the frequency of this product
            product_count[product]++;
        }
    }

    int n = static_cast<int>(carts.size()); // n is the number of carts

    // iterate over hash map to check which products appear in all carts
    for (const auto& products : product_count) {
        if (products.second == n) { // if frequency is same as num of carts then is common
            common.push_back(products.first);  // product key pushed back
        }
    }

    // Put products in sorted order
    std::sort(common.begin(), common.end());

    return common;
}