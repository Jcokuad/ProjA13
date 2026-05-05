// tests/test_a13.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "api_monitor.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"

#include <vector>
#include <string>

TEST_CASE("test desc", "[t0]") {

    REQUIRE(true);
}

TEST_CASE("Check module 1: Empty Vector") {
    std::vector<int> empty_items;
    auto result = find_item_pair_for_exact_box_fit(empty_items, 30);
    
    REQUIRE(result.first == -1);
    REQUIRE(result.second == -1);
}

TEST_CASE("Check module 1: finds two items that together fit exactly in a box of given capacity") {   
    std::vector<int> items = {10, 20, 30, 40, 50};

    auto result = find_item_pair_for_exact_box_fit(items, 70);

    REQUIRE(result.first == 2);
    REQUIRE(result.second == 3);
}

TEST_CASE("Check module 2: extracts the common items from multiple customer carts") {
    std::vector<std::vector<std::string>> carts = {
        {"water", "fruit cups", "batteries"},
        {"gatorade", "water", "fruit cups"},
        {"fruit cups", "bread", "water"},
    };

    auto result = find_common_products_across_carts(carts);

    REQUIRE(result.size() == 2);
    REQUIRE(result[0] == "fruit cups");
    REQUIRE(result[1] == "water");
}

TEST_CASE("Check module 3: Based on customers total purchase value, assign loyalty grades") {
    auto tiers = build_loyalty_tier_map();

    REQUIRE(get_tier_for_customer_score(tiers, 0) == "Bronze");
    REQUIRE(get_tier_for_customer_score(tiers, 499) == "Bronze");
    REQUIRE(get_tier_for_customer_score(tiers, 500) == "Silver");
    REQUIRE(get_tier_for_customer_score(tiers, 999) == "Silver");
    REQUIRE(get_tier_for_customer_score(tiers, 1000) == "Gold");
    REQUIRE(get_tier_for_customer_score(tiers, 1999) == "Gold");
    REQUIRE(get_tier_for_customer_score(tiers, 2000) == "Platinum");
    REQUIRE(get_tier_for_customer_score(tiers, 5500) == "Platinum");
}

TEST_CASE("Check module 4: monitor which endpoint is hit most frequently") {
    std::vector<std::string> logs = {
        "/api/login",
        "/api/cart",
        "/api/checkout",
        "/api/cart",
        "/api/login",
        "/api/cart",
        "/api/checkout",
        "/api/cart",
        "/api/login",
        "/api/login",
    };

    auto result = find_most_frequent_endpoints(logs);

    REQUIRE(result.second == 4);
    REQUIRE(result.first.size() == 2);
    REQUIRE(result.first[0] == "/api/cart");
    REQUIRE(result.first[1] == "/api/login");
}

