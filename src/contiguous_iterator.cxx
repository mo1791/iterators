#include <contiguous_iterator.hxx>



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

// Random access operator for indexing
auto iterator::operator[](int index) const noexcept -> int&
{
    return *(m_current + index);
}
auto iterator::operator[](int index) noexcept -> int&
{
    return *(m_current + index);
}

// Arrow operator for accessing members of the pointed-to object
auto iterator::operator->() const noexcept -> int* { return m_current; }
auto iterator::operator->()       noexcept -> int* { return m_current; }


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


// Decrement operators
auto iterator::operator--() noexcept -> iterator&
{
    m_current -= 1;
    m_count   += 1;

    return *this;
}

[[nodiscard]]
auto iterator::operator--(this iterator& self, int) noexcept
    -> iterator
{
    auto copy = self;
    self     -= 1;

    return copy;
}

// Compound assignment operators
auto iterator::operator+=(int step) noexcept -> iterator&
{
    m_current += step;
    m_count   -= step;

    return *this;
}

auto iterator::operator-=(int step) noexcept -> iterator&
{
    m_current -= step;
    m_count   += step;

    return *this;
}



// Binary arithmetic operators
[[nodiscard]]
auto operator+(iterator current, int step) noexcept -> iterator
{
    current.m_current += step;
    current.m_count   -= step;

    return current;
}

[[nodiscard]]
auto operator+(int step, iterator current) noexcept -> iterator
{
    return (current + step);
}

[[nodiscard]]
auto operator-(iterator current, int step) noexcept -> iterator
{
    current.m_current -= step;
    current.m_count   += step;

    return current;
}

[[nodiscard]]
auto operator-(int step, iterator current) noexcept -> iterator
{
    return (current - step);
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

[[nodiscard]]
auto operator>(iterator const& lhs,
               iterator const& rhs) noexcept -> bool
{
    return (lhs.m_current > rhs.m_current);
}

[[nodiscard]]
auto operator>(iterator const& lhs,
               [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return (lhs.m_count < 0UL);
}

[[nodiscard]]
auto operator>(sentinel const& lhs,
               iterator const& rhs) noexcept -> bool
{
    return not(rhs > lhs);
}

[[nodiscard]]
auto operator<(iterator const& lhs,
               iterator const& rhs) noexcept -> bool
{
    return (lhs.m_current < rhs.m_current);
}

[[nodiscard]]
auto operator<(iterator const& lhs,
               [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return (lhs.m_count > 0UL);
}

[[nodiscard]]
auto operator<(sentinel const& lhs,
               iterator const& rhs) noexcept -> bool
{
    return not(rhs < lhs);
}

[[nodiscard]]
auto operator>=(iterator const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return (lhs.m_current >= rhs.m_current);
}

[[nodiscard]]
auto operator>=(iterator const& lhs,
                [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return (lhs.m_count <= 0UL);
}

[[nodiscard]]
auto operator>=(sentinel const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return not(rhs >= lhs);
}

[[nodiscard]]
auto operator<=(iterator const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return (lhs.m_current <= rhs.m_current);
}

[[nodiscard]]
auto operator<=(iterator const& lhs,
                [[maybe_unused]] sentinel const&) noexcept -> bool
{
    return (lhs.m_count >= 0UL);
}

[[nodiscard]]
auto operator<=(sentinel const& lhs,
                iterator const& rhs) noexcept -> bool
{
    return not(rhs <= lhs);
}


// Calculate difference between iterators
[[nodiscard]]
auto operator-(iterator const& lhs,
               iterator const& rhs) noexcept -> std::ptrdiff_t
{
    return std::ranges::distance(
            std::to_address(lhs), std::to_address(rhs)
        );
}

[[nodiscard]]
auto operator-(iterator const& lhs,
               [[maybe_unused]] sentinel const&) noexcept -> std::ptrdiff_t
{
    return lhs.m_count;
}

[[nodiscard]]
auto operator-(sentinel const& lhs,
               iterator const& rhs) noexcept -> std::ptrdiff_t
{
    return (rhs - lhs);
}