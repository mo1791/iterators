
#include <ranges>


class sentinel {};

class iterator : public std::output_iterator_tag
{

public:
    using difference_type = std::ptrdiff_t;

    using iterator_category = std::output_iterator_tag;

public:
    constexpr auto operator*() const noexcept -> int&;
    constexpr auto operator*()       noexcept -> int&;

public:
    constexpr auto operator++()    noexcept -> iterator&; 
    constexpr auto operator++(int) noexcept -> iterator ;
};


static_assert( std::output_iterator<iterator, int> );
static_assert( std::output_iterator<iterator, int&> );
static_assert( std::output_iterator<iterator, int const&> );
static_assert( std::output_iterator<iterator, int&&> );
static_assert( std::output_iterator<iterator, int const&&> );