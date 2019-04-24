#ifndef JRPG_GAME_ENGINE_TILE_MAP_PARSER_HPP
#define JRPG_GAME_ENGINE_TILE_MAP_PARSER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    using parse_map_exception = std::runtime_error;
    using parse_map_name_exception = std::runtime_error;
}

namespace jrpg {
    using layer_level_type = std::vector<std::int32_t>;

    class tile_map_parser final : public non_copyable, public non_moveable {
      public:
        explicit tile_map_parser() = default;
        ~tile_map_parser() = default;

        const layer_level_type parse(const std::string &filename);

        const std::string &name() const;

      private:
        std::string _name;
    };
} // namespace jrpg

#endif //JRPG_GAME_ENGINE_TILE_MAP_PARSER_HPP
