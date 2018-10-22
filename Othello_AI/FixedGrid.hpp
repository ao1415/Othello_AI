#pragma once
#include <array>

namespace alib {

	template<typename Type, size_t Width = Size, size_t Height = Size>
	class FixedGrid {
	private:

		using ContainerType = std::array<Type, Width * Height>;
		ContainerType m_data;

	public:

		FixedGrid() = default;
		FixedGrid(const Type& v) { fill(v); }
		FixedGrid(const FixedGrid& other) = default;
		FixedGrid(FixedGrid&& other) {
			m_data = std::move(other.m_data);
		}

		FixedGrid& operator=(const FixedGrid& other) = default;
		FixedGrid& operator=(FixedGrid&& other) = default;

		const Type* operator[](size_t y) const {
			return &m_data[y * Width];
		}
		Type* operator[](size_t y) {
			return &m_data[y * Width];
		}

		const Type& operator[](const Point& p) const {
			return m_data[p.y * Width + p.x];
		}
		Type& operator[](const Point& p) {
			return m_data[p.y * Width + p.x];
		}

		const Type& at(size_t x, size_t y) const {
			if (outside(x, y))
				throw std::out_of_range("FixedGrid::at");
			return m_data[y * Width + x];
		}
		Type& at(size_t x, size_t y) {
			if (outside(x, y))
				throw std::out_of_range("FixedGrid::at");
			return m_data[y * Width + x];
		}

		const Type& at(const Point& p) const {
			if (outside(p.x, p.y))
				throw std::out_of_range("FixedGrid::at");
			return m_data[p.y * Width + p.x];
		}
		Type& at(const Point& p) {
			if (outside(p.x, p.y))
				throw std::out_of_range("FixedGrid::at");
			return m_data[p.y * Width + p.x];
		}

		constexpr size_t width() const {
			return Width;
		}
		constexpr size_t height() const {
			return Height;
		}

		bool inside(size_t x, size_t y) const {
			return (0 <= x && x < Width && 0 <= y && y < Height);
		}
		bool outside(size_t x, size_t y) const {
			return (0 > x || x >= Width || 0 > y || y >= Height);
		}

		void fill(const Type& v) noexcept {
			m_data.fill(v);
		}

		void clear() {
			m_data.swap(ContainerType());
		}

	};

}
