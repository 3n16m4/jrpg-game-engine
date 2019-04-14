#ifndef JRPG_GAME_ENGINE_TILEMAP_PARSER_HPP
#define JRPG_GAME_ENGINE_TILEMAP_PARSER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace jrpg {
    using TileMap = std::vector<std::int32_t>;

    class tilemap_parser final {
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
