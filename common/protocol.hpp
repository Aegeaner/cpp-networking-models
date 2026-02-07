#pragma once

#include <string>
#include <string_view>
#include <optional>
#include <variant>
#include <vector>
#include <algorithm>
#include <sstream>

namespace networking_lab {

enum class CommandType {
    GET,
    SET,
    UNKNOWN
};

struct Command {
    CommandType type;
    std::string key;
    std::optional<std::string> value;
};

// Simple Redis-like parser: 
// SET key value
// GET key
inline std::optional<Command> parse_command(std::string_view input) {
    if (input.empty()) return std::nullopt;

    // Remove trailing newline if present
    if (input.back() == '\n') input.remove_suffix(1);
    if (!input.empty() && input.back() == '\r') input.remove_suffix(1);

    std::stringstream ss{std::string(input)};
    std::string type_str;
    
    if (!(ss >> type_str)) return std::nullopt;

    // Case-insensitive comparison could be added, assuming uppercase for now
    std::transform(type_str.begin(), type_str.end(), type_str.begin(), ::toupper);

    if (type_str == "GET") {
        std::string key;
        if (ss >> key) {
            return Command{CommandType::GET, key, std::nullopt};
        }
    } else if (type_str == "SET") {
        std::string key;
        std::string value;
        if (ss >> key >> value) {
            return Command{CommandType::SET, key, value};
        }
    }

    return std::nullopt;
}

} // namespace networking_lab