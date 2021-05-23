#pragma once

#include <cstdint>

//------------------------------------------------------------------------------

namespace std {

//------------------------------------------------------------------------------

struct source_location
{

//------------------------------------------------------------------------------

	constexpr source_location() noexcept
		:	m_file_name{ "unknown" }
		,	m_function_name{ m_file_name }
		,	m_line{ 0 }
		,	m_column{ 0 }
	{

	}

//------------------------------------------------------------------------------

	static constexpr source_location current(
		const char * _file = __builtin_FILE(),
		const char * _func = __builtin_FUNCTION(),
		int _line = __builtin_LINE(),
		int _col = 0
	) noexcept
	{
		source_location location;
		location.m_file_name = _file;
		location.m_function_name = _func;
		location.m_line = _line;
		location.m_column = _col;
		return location;
	}

//------------------------------------------------------------------------------

	constexpr uint_least32_t line() const noexcept
	{
		return m_line;
	}
	constexpr uint_least32_t column() const noexcept
	{
		return m_column;
	}
	constexpr const char * file_name() const noexcept
	{
		return m_file_name;
	}
	constexpr const char * function_name() const noexcept
	{
		return m_function_name;
	}

//------------------------------------------------------------------------------

private:
	const char * m_file_name;
	const char * m_function_name;
	uint_least32_t m_line;
	uint_least32_t m_column;
  };

//------------------------------------------------------------------------------

}

