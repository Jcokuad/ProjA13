//box_optimizer.cpp
#include "box_optimizer.hpp"
#include <unordered_map>
#include <algorithm>

std::pair<int, int> find_item_pair_for_exact_box_fit(const std::vector<int>& item_weights, int box_capacity) {

    std::unordered_map<int, int> visited;  // holds visited items

    for (int i = 0; i < item_weights.size(); i++) {
        int curr = item_weights[i];  // current item weight
        int rem = box_capacity - curr;  // remainder needed to meet box capacity

        // check if weight needed has been visited before
        if (visited.find(rem) != visited.end()) {
            // if in map get the index
            int ind1 = visited[rem];
            int ind2 = i;

            if (ind1 > ind2) {
                std::swap(ind1, ind2); // return in ascending order
            }
            
            return {ind1, ind2};
        }
        // if not visited before then store with its index
        visited[curr] = i;
    }
    return {-1, -1}; // if pair not found
}