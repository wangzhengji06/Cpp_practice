#include <functional>
#include <iterator>
template <std::forward_iterator InputIt, std::sentinel_for<InputIt> Sentinel,
          std::output_iterator<std::iter_value_t<InputIt>> OutputIt,
          std::indirectly_unary_invocable<InputIt> UnaryOp,
          typename Projection = std::identity,
          std::indirect_unary_predicate<std::projected<InputIt, Projection>>
              Predicate>
OutputIt transform_if(InputIt first, Sentinel last, OutputIt dest, UnaryOp op,
                      Predicate pred, Projection proj = {}) {
  while (first != last) {
    if (invoke(pred, invoke(proj, *first))) {
      *dest = op(*first);
    } else {
      *dest = *first;
    }
    ++dest;
    ++first;
  }
  return dest;
}
