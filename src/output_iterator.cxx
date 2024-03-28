#include <output_iterator.hxx>



[[nodiscard]] auto operator==([[maybe_unused]] sentinel const&,
                              [[maybe_unused]] sentinel const& ) noexcept -> bool
{
    return true;
}

[[nodiscard]] auto operator!=([[maybe_unused]] sentinel const&,
                              [[maybe_unused]] sentinel const& ) noexcept -> bool
{
    return false;
}

[[nodiscard]] auto operator>([[maybe_unused]] sentinel const&,
                             [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return false;
}

[[nodiscard]] auto operator<([[maybe_unused]] sentinel const&,
                             [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return false;
}

[[nodiscard]] auto operator>=([[maybe_unused]] sentinel const&,
                              [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return true;
}

[[nodiscard]] auto operator<=([[maybe_unused]] sentinel const&,
                              [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return true;
}
  



// Default constructor
iterator::iterator() noexcept = default;

// Constructor with current pointer and count of remaining elements
iterator::iterator(int* current, std::size_t count) noexcept
    : m_current{current}
    , m_count{count}
{}


// Dereference operator for reading and writing
auto iterator::operator*() const noexcept -> int& { return *m_current; }
auto iterator::operator*()       noexcept -> int& { return *m_current; }



// Increment operators
auto iterator::operator++() noexcept -> iterator&
{
    m_current += 1;
    m_count   -= 1;

    return *this;
}

[[nodiscard]]
auto iterator::operator++(this iterator& self, int) noexcept
    -> iterator
{
    auto copy = self;
    self     += 1;

    return copy;
}




// Comparison operators
[[nodiscard]]
auto operator==(iterator const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return (lhs.m_current == rhs.m_current);
}

[[nodiscard]]
auto operator==(iterator const& lhs,
                [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return (lhs.m_count == 0UL);
}

[[nodiscard]]
auto operator==(sentinel const& lhs,
                iterator const& rhs) noexcept-> bool
{
    return (rhs == lhs);
}

[[nodiscard]]
auto operator!=(iterator const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return not(lhs == rhs);
}

[[nodiscard]]
auto operator!=(iterator const& lhs,
                sentinel const& rhs) noexcept -> bool
{
    return not(lhs == rhs);
}

[[nodiscard]]
auto operator!=(sentinel const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return (rhs != lhs);
}