template <typename T> class Grid {
public:
  template <typename E> Grid(const Grid<E> &src);
  template <typename E> Grid &operator=(const Grid<E> &rhs);

  void swap(Grid &other) noexcept;
};

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E> &src) : Grid{src.getWidth(), src.getHeight()} {}
