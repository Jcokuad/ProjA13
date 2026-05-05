//customer_loyalty.cpp

#include "customer_loyalty.hpp"


std::map<int, std::string> build_loyalty_tier_map() {

    return {{0, "Bronze"},
            {500, "Silver"},
            {1000, "Gold"},
            {2000, "Platinum"}
    };
}

std::string get_tier_for_customer_score(const std::map<int, std::string>& tier_map, int score) {
    
    // upper_bound gives the first key that is greater than score
    auto it = tier_map.upper_bound(score);

    if (it == tier_map.begin()) {
        return it->second;  // if smaller than all keys returns first key
    }

    // move iterator back one step if in between largest and smallest
    --it;

    return it->second;
}