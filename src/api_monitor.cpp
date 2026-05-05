//api_monitor.cpp

#include "api_monitor.hpp"
#include <unordered_map>
#include <algorithm>

std::pair<std::vector<std::string>, int>find_most_frequent_endpoints(const std::vector<std::string>& api_logs) {
    
    std::vector<std::string> endpoints;
    
    // no logs edge case
    if (api_logs.empty()) {
        return {endpoints, 0};
    }

    // unordered map to store api and its frequency
    std::unordered_map<std::string, int> api_call_count;

    // count occurances of endpoints
    for (const auto& call : api_logs) {
        api_call_count[call]++;
    }

    int max = 0; // tracks highest frequency
    // find the highest frequency
    for (const auto& endpoint : api_call_count) {
        if (endpoint.second > max) {
            max = endpoint.second;
        }
    }

    // store all endpoints with max frequency
    for (const auto& endpoint : api_call_count) {
        if (endpoint.second == max) {
            endpoints.push_back(endpoint.first);
        }
    }

    // sort the most frequent endpoints
    std::sort(endpoints.begin(), endpoints.end());

    return {endpoints, max};

}

