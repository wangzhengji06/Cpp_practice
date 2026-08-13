#pragma once

#include <cstddef>
#include <format>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T> class Grid {
public:
  explicit Grid(std::size_t width = DefaultWidth,
                std::size_t height = DefaultHeight);
  virtual ~Grid() = default;

  Grid(const Grid &&src) = default;
  Grid &operator=(Grid &&rhs) = default;

  std::optional<T> &at(std::size_t x, std::size_t y);
  const std::optional<T> &at(std::size_t x, std::size_t y) const;

  std::size_t getHeight() const { return m_height; }
  std::size_t getWidth() const { return m_width; }

  static constexpr std::size_t DefaultWidth{10};
  static constexpr std::size_t DefaultHeight{10};

private:
  void verifyCoordinate(std::size_t x, std::size_t y) const;
  std::vector<std::optional<T>> m_cells;
  std::size_t m_width{0}, m_height{0};
};
