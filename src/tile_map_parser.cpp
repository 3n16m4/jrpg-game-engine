#include "../include/tile_map_parser.hpp"

namespace jrpg {
    const layer_level_type jrpg::tile_map_parser::parse(const std::string &filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            throw parse_map_exception("Exception: failed to open file: " + filename);
        }

        // set name for map
        const std::string::size_type n = filename.find_last_of('/') + 1;
        const std::string::size_type dot = filename.find_last_of('.');
        if (n != std::string::npos && dot != std::string::npos) {
            // without extension and path separators
            _name = filename.substr(0, dot).substr(n);
        } else {
            throw parse_map_name_exception("Exception: failed to set map-name");
        }

        std::string line;
        std::stringstream ss;

        while (std::getline(file, line, ',')) {
            ss << line << '\n';
        }

        layer_level_type tile_map{};
        std::int32_t tile_id;
        while (ss >> tile_id) {
            tile_map.emplace_back(tile_id);
        }

        file.close();
        return tile_map;
    }

    const std::string &tile_map_parser::name() const {
        return _name;
    }
} // namespace jrpg
