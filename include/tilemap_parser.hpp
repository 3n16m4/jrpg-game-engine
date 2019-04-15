#ifndef JRPG_GAME_ENGINE_TILEMAP_PARSER_HPP
#define JRPG_GAME_ENGINE_TILEMAP_PARSER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "utility/non_copyable.hpp"
#include "utility/non_moveable.hpp"

namespace jrpg {
    using TileMap = std::vector<std::int32_t>;

    class tilemap_parser final : public non_copyable, public non_moveable {
      public:
        explicit tilemap_parser() = default;
        ~tilemap_parser() = default;

        const TileMap parse(const std::string &filename);

        const std::string &get_name() const;

      private:
        std::string _name;
    };
} // namespace jrpg

#endif // JRPG_GAME_ENGINE_TILEMAP_PARSER_HPP
