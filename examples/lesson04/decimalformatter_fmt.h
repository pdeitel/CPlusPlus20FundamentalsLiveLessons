// decimalformatter.h
// Custom fmt::formatter that formats a 
// boost::multiprecision::cpp_dec_float_50 as a std::string
// with two digits to the right of the decimal point.
#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <fmt/format.h> // in C++20, this will be #include <format>
#include <iomanip>
#include <sstream>
#include <string>

// short name for boost::multiprecision::cpp_dec_float_50
using decimal = boost::multiprecision::cpp_dec_float_50;

// Custom formatter for boost::multiprecision::cpp_dec_float_50. 
// Formats as a string with two digits to the right of the decimal point.
// More info at: https://fmt.dev/latest/api.html#format-api
template<> struct fmt::formatter<decimal> : fmt::formatter<string_view> {
   template <typename FormatContext>
   auto format(decimal d, FormatContext& ctx) const {
      std::ostringstream out{};
      out << std::fixed << std::setprecision(2) << d;
      return formatter<string_view>::format(out.str(), ctx);
   }
};