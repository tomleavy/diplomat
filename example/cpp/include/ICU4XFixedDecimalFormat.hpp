#ifndef ICU4XFixedDecimalFormat_HPP
#define ICU4XFixedDecimalFormat_HPP
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <algorithm>
#include <memory>
#include <variant>
#include <optional>
#include "diplomat_runtime.hpp"

namespace capi {
#include "ICU4XFixedDecimalFormat.h"
}

class ICU4XLocale;
class ICU4XDataProvider;
struct ICU4XFixedDecimalFormatOptions;
struct ICU4XFixedDecimalFormatResult;
class ICU4XFixedDecimal;

/**
 * A destruction policy for using ICU4XFixedDecimalFormat with std::unique_ptr.
 */
struct ICU4XFixedDecimalFormatDeleter {
  void operator()(capi::ICU4XFixedDecimalFormat* l) const noexcept {
    capi::ICU4XFixedDecimalFormat_destroy(l);
  }
};

/**
 * An ICU4X Fixed Decimal Format object, capable of formatting a [`ICU4XFixedDecimal`] as a string.
 * 
 * See the [Rust documentation](https://unicode-org.github.io/icu4x-docs/doc/icu/decimal/struct.FixedDecimalFormat.html) for more information.
 */
class ICU4XFixedDecimalFormat {
 public:

  /**
   * Creates a new [`ICU4XFixedDecimalFormat`] from locale data.
   * 
   * See the [Rust documentation](https://unicode-org.github.io/icu4x-docs/doc/icu/decimal/struct.FixedDecimalFormat.html#method.try_new) for more information.
   */
  static ICU4XFixedDecimalFormatResult try_new(const ICU4XLocale& locale, const ICU4XDataProvider& provider, ICU4XFixedDecimalFormatOptions options);

  /**
   * Formats a [`ICU4XFixedDecimal`] to a string.
   * 
   * See the [Rust documentation](https://unicode-org.github.io/icu4x-docs/doc/icu/decimal/struct.FixedDecimalFormat.html#method.format) for more information.
   */
  template<typename W> void format_write_to_writeable(const ICU4XFixedDecimal& value, W& write) const;

  /**
   * Formats a [`ICU4XFixedDecimal`] to a string.
   * 
   * See the [Rust documentation](https://unicode-org.github.io/icu4x-docs/doc/icu/decimal/struct.FixedDecimalFormat.html#method.format) for more information.
   */
  std::string format_write(const ICU4XFixedDecimal& value) const;
  inline const capi::ICU4XFixedDecimalFormat* AsFFI() const { return this->inner.get(); }
  inline capi::ICU4XFixedDecimalFormat* AsFFIMut() { return this->inner.get(); }
  inline ICU4XFixedDecimalFormat(capi::ICU4XFixedDecimalFormat* i) : inner(i) {}
  ICU4XFixedDecimalFormat() = default;
  ICU4XFixedDecimalFormat(ICU4XFixedDecimalFormat&&) noexcept = default;
  ICU4XFixedDecimalFormat& operator=(ICU4XFixedDecimalFormat&& other) noexcept = default;
 private:
  std::unique_ptr<capi::ICU4XFixedDecimalFormat, ICU4XFixedDecimalFormatDeleter> inner;
};

#include "ICU4XLocale.hpp"
#include "ICU4XDataProvider.hpp"
#include "ICU4XFixedDecimalFormatOptions.hpp"
#include "ICU4XFixedDecimalFormatResult.hpp"
#include "ICU4XFixedDecimal.hpp"

inline ICU4XFixedDecimalFormatResult ICU4XFixedDecimalFormat::try_new(const ICU4XLocale& locale, const ICU4XDataProvider& provider, ICU4XFixedDecimalFormatOptions options) {
  ICU4XFixedDecimalFormatOptions diplomat_wrapped_struct_options = options;
  capi::ICU4XFixedDecimalFormatResult diplomat_raw_struct_out_value = capi::ICU4XFixedDecimalFormat_try_new(locale.AsFFI(), provider.AsFFI(), capi::ICU4XFixedDecimalFormatOptions{ .grouping_strategy = static_cast<capi::ICU4XFixedDecimalGroupingStrategy>(diplomat_wrapped_struct_options.grouping_strategy), .sign_display = static_cast<capi::ICU4XFixedDecimalSignDisplay>(diplomat_wrapped_struct_options.sign_display) });
  auto diplomat_optional_raw_out_value_fdf = diplomat_raw_struct_out_value.fdf;
  std::optional<ICU4XFixedDecimalFormat> diplomat_optional_out_value_fdf;
  if (diplomat_optional_raw_out_value_fdf != nullptr) {
    diplomat_optional_out_value_fdf = ICU4XFixedDecimalFormat(diplomat_optional_raw_out_value_fdf);
  } else {
    diplomat_optional_out_value_fdf = std::nullopt;
  }
  return ICU4XFixedDecimalFormatResult{ .fdf = std::move(diplomat_optional_out_value_fdf), .success = std::move(diplomat_raw_struct_out_value.success) };
}
template<typename W> inline void ICU4XFixedDecimalFormat::format_write_to_writeable(const ICU4XFixedDecimal& value, W& write) const {
  capi::DiplomatWriteable write_writer = diplomat::WriteableTrait<W>::Construct(write);
  capi::ICU4XFixedDecimalFormat_format_write(this->inner.get(), value.AsFFI(), &write_writer);
}
inline std::string ICU4XFixedDecimalFormat::format_write(const ICU4XFixedDecimal& value) const {
  std::string diplomat_writeable_string;
  capi::DiplomatWriteable diplomat_writeable_out = diplomat::WriteableFromString(diplomat_writeable_string);
  capi::ICU4XFixedDecimalFormat_format_write(this->inner.get(), value.AsFFI(), &diplomat_writeable_out);
  return diplomat_writeable_string;
}
#endif
