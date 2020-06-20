// -*- C++ -*-
// Automatically generated from ../../src/xdr/Stellar-ledger-entries.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_SRC_GENERATED_XDR_STELLAR_LEDGER_ENTRIES_H_INCLUDED__
#define __XDR_SRC_GENERATED_XDR_STELLAR_LEDGER_ENTRIES_H_INCLUDED__ 1

#include <xdrpp/types.h>

#include "Stellar-types.h"

namespace stellar {

using AccountID = PublicKey;
using Thresholds = xdr::opaque_array<4>;
using string32 = xdr::xstring<32>;
using string64 = xdr::xstring<64>;
using SequenceNumber = int64;
using TimePoint = uint64;
using DataValue = xdr::opaque_vec<64>;
using AssetCode4 = xdr::opaque_array<4>;
using AssetCode12 = xdr::opaque_array<12>;

enum AssetType : std::int32_t {
  ASSET_TYPE_NATIVE = 0,
  ASSET_TYPE_CREDIT_ALPHANUM4 = 1,
  ASSET_TYPE_CREDIT_ALPHANUM12 = 2,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AssetType>
  : xdr_integral_base<::stellar::AssetType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::AssetType val) {
    switch (val) {
    case ::stellar::ASSET_TYPE_NATIVE:
      return "ASSET_TYPE_NATIVE";
    case ::stellar::ASSET_TYPE_CREDIT_ALPHANUM4:
      return "ASSET_TYPE_CREDIT_ALPHANUM4";
    case ::stellar::ASSET_TYPE_CREDIT_ALPHANUM12:
      return "ASSET_TYPE_CREDIT_ALPHANUM12";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ASSET_TYPE_NATIVE,
      ::stellar::ASSET_TYPE_CREDIT_ALPHANUM4,
      ::stellar::ASSET_TYPE_CREDIT_ALPHANUM12
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct Asset {
  struct _alphaNum4_t {
    AssetCode4 assetCode{};
    AccountID issuer{};

    _alphaNum4_t() = default;
    template<typename _assetCode_T,
             typename _issuer_T,
             typename = typename
             std::enable_if<std::is_constructible<AssetCode4, _assetCode_T>::value
                            && std::is_constructible<AccountID, _issuer_T>::value
                           >::type>
    explicit _alphaNum4_t(_assetCode_T &&_assetCode,
                          _issuer_T &&_issuer)
      : assetCode(std::forward<_assetCode_T>(_assetCode)),
        issuer(std::forward<_issuer_T>(_issuer)) {}
  };
  struct _alphaNum12_t {
    AssetCode12 assetCode{};
    AccountID issuer{};

    _alphaNum12_t() = default;
    template<typename _assetCode_T,
             typename _issuer_T,
             typename = typename
             std::enable_if<std::is_constructible<AssetCode12, _assetCode_T>::value
                            && std::is_constructible<AccountID, _issuer_T>::value
                           >::type>
    explicit _alphaNum12_t(_assetCode_T &&_assetCode,
                           _issuer_T &&_issuer)
      : assetCode(std::forward<_assetCode_T>(_assetCode)),
        issuer(std::forward<_issuer_T>(_issuer)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<AssetType>::case_type;
private:
  _xdr_case_type type_;
  union {
    _alphaNum4_t alphaNum4_;
    _alphaNum12_t alphaNum12_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<AssetType> &_xdr_case_values() {
    static const std::vector<AssetType> _xdr_disc_vec {
      ASSET_TYPE_NATIVE,
      ASSET_TYPE_CREDIT_ALPHANUM4,
      ASSET_TYPE_CREDIT_ALPHANUM12
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ASSET_TYPE_NATIVE ? 0
      : which == ASSET_TYPE_CREDIT_ALPHANUM4 ? 1
      : which == ASSET_TYPE_CREDIT_ALPHANUM12 ? 2
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ASSET_TYPE_NATIVE:
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM4:
      _f(&Asset::alphaNum4_, std::forward<_A>(_a)...);
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM12:
      _f(&Asset::alphaNum12_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in Asset");
    if (fnum != _xdr_field_number(type_)) {
      this->~Asset();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit Asset(AssetType which = AssetType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  Asset(const Asset &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  Asset(Asset &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~Asset() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  Asset &operator=(const Asset &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~Asset();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  Asset &operator=(Asset &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~Asset();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  AssetType type() const { return AssetType(type_); }
  Asset &type(AssetType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _alphaNum4_t &alphaNum4() {
    if (_xdr_field_number(type_) == 1)
      return alphaNum4_;
    throw xdr::xdr_wrong_union("Asset: alphaNum4 accessed when not selected");
  }
  const _alphaNum4_t &alphaNum4() const {
    if (_xdr_field_number(type_) == 1)
      return alphaNum4_;
    throw xdr::xdr_wrong_union("Asset: alphaNum4 accessed when not selected");
  }
  _alphaNum12_t &alphaNum12() {
    if (_xdr_field_number(type_) == 2)
      return alphaNum12_;
    throw xdr::xdr_wrong_union("Asset: alphaNum12 accessed when not selected");
  }
  const _alphaNum12_t &alphaNum12() const {
    if (_xdr_field_number(type_) == 2)
      return alphaNum12_;
    throw xdr::xdr_wrong_union("Asset: alphaNum12 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Asset::_alphaNum4_t>
  : xdr_struct_base<field_ptr<::stellar::Asset::_alphaNum4_t,
                              decltype(::stellar::Asset::_alphaNum4_t::assetCode),
                              &::stellar::Asset::_alphaNum4_t::assetCode>,
                    field_ptr<::stellar::Asset::_alphaNum4_t,
                              decltype(::stellar::Asset::_alphaNum4_t::issuer),
                              &::stellar::Asset::_alphaNum4_t::issuer>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Asset::_alphaNum4_t &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Asset::_alphaNum4_t &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::Asset::_alphaNum12_t>
  : xdr_struct_base<field_ptr<::stellar::Asset::_alphaNum12_t,
                              decltype(::stellar::Asset::_alphaNum12_t::assetCode),
                              &::stellar::Asset::_alphaNum12_t::assetCode>,
                    field_ptr<::stellar::Asset::_alphaNum12_t,
                              decltype(::stellar::Asset::_alphaNum12_t::issuer),
                              &::stellar::Asset::_alphaNum12_t::issuer>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Asset::_alphaNum12_t &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Asset::_alphaNum12_t &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::Asset> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::Asset;
  using case_type = ::stellar::Asset::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "alphaNum4";
    case 2:
      return "alphaNum12";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::Asset &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in Asset");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Asset &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in Asset");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Asset &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Price {
  int32 n{};
  int32 d{};

  Price() = default;
  template<typename _n_T,
           typename _d_T,
           typename = typename
           std::enable_if<std::is_constructible<int32, _n_T>::value
                          && std::is_constructible<int32, _d_T>::value
                         >::type>
  explicit Price(_n_T &&_n,
                 _d_T &&_d)
    : n(std::forward<_n_T>(_n)),
      d(std::forward<_d_T>(_d)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Price>
  : xdr_struct_base<field_ptr<::stellar::Price,
                              decltype(::stellar::Price::n),
                              &::stellar::Price::n>,
                    field_ptr<::stellar::Price,
                              decltype(::stellar::Price::d),
                              &::stellar::Price::d>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Price &obj) {
    archive(ar, obj.n, "n");
    archive(ar, obj.d, "d");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Price &obj) {
    archive(ar, obj.n, "n");
    archive(ar, obj.d, "d");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Liabilities {
  int64 buying{};
  int64 selling{};

  Liabilities() = default;
  template<typename _buying_T,
           typename _selling_T,
           typename = typename
           std::enable_if<std::is_constructible<int64, _buying_T>::value
                          && std::is_constructible<int64, _selling_T>::value
                         >::type>
  explicit Liabilities(_buying_T &&_buying,
                       _selling_T &&_selling)
    : buying(std::forward<_buying_T>(_buying)),
      selling(std::forward<_selling_T>(_selling)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Liabilities>
  : xdr_struct_base<field_ptr<::stellar::Liabilities,
                              decltype(::stellar::Liabilities::buying),
                              &::stellar::Liabilities::buying>,
                    field_ptr<::stellar::Liabilities,
                              decltype(::stellar::Liabilities::selling),
                              &::stellar::Liabilities::selling>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Liabilities &obj) {
    archive(ar, obj.buying, "buying");
    archive(ar, obj.selling, "selling");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Liabilities &obj) {
    archive(ar, obj.buying, "buying");
    archive(ar, obj.selling, "selling");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ThresholdIndexes : std::int32_t {
  THRESHOLD_MASTER_WEIGHT = 0,
  THRESHOLD_LOW = 1,
  THRESHOLD_MED = 2,
  THRESHOLD_HIGH = 3,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ThresholdIndexes>
  : xdr_integral_base<::stellar::ThresholdIndexes, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ThresholdIndexes val) {
    switch (val) {
    case ::stellar::THRESHOLD_MASTER_WEIGHT:
      return "THRESHOLD_MASTER_WEIGHT";
    case ::stellar::THRESHOLD_LOW:
      return "THRESHOLD_LOW";
    case ::stellar::THRESHOLD_MED:
      return "THRESHOLD_MED";
    case ::stellar::THRESHOLD_HIGH:
      return "THRESHOLD_HIGH";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::THRESHOLD_MASTER_WEIGHT,
      ::stellar::THRESHOLD_LOW,
      ::stellar::THRESHOLD_MED,
      ::stellar::THRESHOLD_HIGH
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

enum LedgerEntryType : std::int32_t {
  ACCOUNT = 0,
  TRUSTLINE = 1,
  OFFER = 2,
  DATA = 3,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LedgerEntryType>
  : xdr_integral_base<::stellar::LedgerEntryType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::LedgerEntryType val) {
    switch (val) {
    case ::stellar::ACCOUNT:
      return "ACCOUNT";
    case ::stellar::TRUSTLINE:
      return "TRUSTLINE";
    case ::stellar::OFFER:
      return "OFFER";
    case ::stellar::DATA:
      return "DATA";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ACCOUNT,
      ::stellar::TRUSTLINE,
      ::stellar::OFFER,
      ::stellar::DATA
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct Signer {
  SignerKey key{};
  uint32 weight{};

  Signer() = default;
  template<typename _key_T,
           typename _weight_T,
           typename = typename
           std::enable_if<std::is_constructible<SignerKey, _key_T>::value
                          && std::is_constructible<uint32, _weight_T>::value
                         >::type>
  explicit Signer(_key_T &&_key,
                  _weight_T &&_weight)
    : key(std::forward<_key_T>(_key)),
      weight(std::forward<_weight_T>(_weight)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Signer>
  : xdr_struct_base<field_ptr<::stellar::Signer,
                              decltype(::stellar::Signer::key),
                              &::stellar::Signer::key>,
                    field_ptr<::stellar::Signer,
                              decltype(::stellar::Signer::weight),
                              &::stellar::Signer::weight>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Signer &obj) {
    archive(ar, obj.key, "key");
    archive(ar, obj.weight, "weight");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Signer &obj) {
    archive(ar, obj.key, "key");
    archive(ar, obj.weight, "weight");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum AccountFlags : std::int32_t {
  AUTH_REQUIRED_FLAG = 0x1,
  AUTH_REVOCABLE_FLAG = 0x2,
  AUTH_IMMUTABLE_FLAG = 0x4,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountFlags>
  : xdr_integral_base<::stellar::AccountFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::AccountFlags val) {
    switch (val) {
    case ::stellar::AUTH_REQUIRED_FLAG:
      return "AUTH_REQUIRED_FLAG";
    case ::stellar::AUTH_REVOCABLE_FLAG:
      return "AUTH_REVOCABLE_FLAG";
    case ::stellar::AUTH_IMMUTABLE_FLAG:
      return "AUTH_IMMUTABLE_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::AUTH_REQUIRED_FLAG,
      ::stellar::AUTH_REVOCABLE_FLAG,
      ::stellar::AUTH_IMMUTABLE_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_ACCOUNT_FLAGS = 0x7;

struct AccountEntry {
  struct _ext_t {
    struct _v1_t {
      struct _ext_t {
        using _xdr_case_type = xdr::xdr_traits<int>::case_type;
      private:
        _xdr_case_type v_;
      public:
        static Constexpr const bool _xdr_has_default_case = false;
        static const std::vector<int> &_xdr_case_values() {
          static const std::vector<int> _xdr_disc_vec {
            0
          };
          return _xdr_disc_vec;
        }
        static Constexpr int _xdr_field_number(_xdr_case_type which) {
          return which == 0 ? 0
            : -1;
        }
        template<typename _F, typename..._A> static bool
        _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
          switch (_which) {
          case 0:
            return true;
          }
          return false;
        }

        _xdr_case_type _xdr_discriminant() const { return v_; }
        void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
          int fnum = _xdr_field_number(which);
          if (fnum < 0 && validate)
            throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
          if (fnum != _xdr_field_number(v_)) {
            this->~_ext_t();
            v_ = which;
            _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
          }
          else
            v_ = which;
        }
        explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
        }
        _ext_t(const _ext_t &source) : v_(source.v_) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
        }
        _ext_t(_ext_t &&source) : v_(source.v_) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                            std::move(source));
        }
        ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
        _ext_t &operator=(const _ext_t &source) {
          if (_xdr_field_number(v_)
              == _xdr_field_number(source.v_))
            _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
          else {
            this->~_ext_t();
            v_ = std::numeric_limits<_xdr_case_type>::max();
            _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
          }
          v_ = source.v_;
          return *this;
        }
        _ext_t &operator=(_ext_t &&source) {
          if (_xdr_field_number(v_)
               == _xdr_field_number(source.v_))
            _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                              std::move(source));
          else {
            this->~_ext_t();
            v_ = std::numeric_limits<_xdr_case_type>::max();
            _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                              std::move(source));
          }
          v_ = source.v_;
          return *this;
        }

        std::int32_t v() const { return std::int32_t(v_); }
        _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
          _xdr_discriminant(_xdr_d, _xdr_validate);
          return *this;
        }

      };

      Liabilities liabilities{};
      _ext_t ext{};

      _v1_t() = default;
      template<typename _liabilities_T,
               typename _ext_T,
               typename = typename
               std::enable_if<std::is_constructible<Liabilities, _liabilities_T>::value
                              && std::is_constructible<_ext_t, _ext_T>::value
                             >::type>
      explicit _v1_t(_liabilities_T &&_liabilities,
                     _ext_T &&_ext)
        : liabilities(std::forward<_liabilities_T>(_liabilities)),
          ext(std::forward<_ext_T>(_ext)) {}
    };

    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      _v1_t v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        1
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 1 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 1:
        _f(&_ext_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    _v1_t &v1() {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
    const _v1_t &v1() const {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
  };

  AccountID accountID{};
  int64 balance{};
  SequenceNumber seqNum{};
  uint32 numSubEntries{};
  xdr::pointer<AccountID> inflationDest{};
  uint32 flags{};
  string32 homeDomain{};
  Thresholds thresholds{};
  xdr::xvector<Signer,20> signers{};
  _ext_t ext{};

  AccountEntry() = default;
  template<typename _accountID_T,
           typename _balance_T,
           typename _seqNum_T,
           typename _numSubEntries_T,
           typename _inflationDest_T,
           typename _flags_T,
           typename _homeDomain_T,
           typename _thresholds_T,
           typename _signers_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                          && std::is_constructible<int64, _balance_T>::value
                          && std::is_constructible<SequenceNumber, _seqNum_T>::value
                          && std::is_constructible<uint32, _numSubEntries_T>::value
                          && std::is_constructible<xdr::pointer<AccountID>, _inflationDest_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                          && std::is_constructible<string32, _homeDomain_T>::value
                          && std::is_constructible<Thresholds, _thresholds_T>::value
                          && std::is_constructible<xdr::xvector<Signer,20>, _signers_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit AccountEntry(_accountID_T &&_accountID,
                        _balance_T &&_balance,
                        _seqNum_T &&_seqNum,
                        _numSubEntries_T &&_numSubEntries,
                        _inflationDest_T &&_inflationDest,
                        _flags_T &&_flags,
                        _homeDomain_T &&_homeDomain,
                        _thresholds_T &&_thresholds,
                        _signers_T &&_signers,
                        _ext_T &&_ext)
    : accountID(std::forward<_accountID_T>(_accountID)),
      balance(std::forward<_balance_T>(_balance)),
      seqNum(std::forward<_seqNum_T>(_seqNum)),
      numSubEntries(std::forward<_numSubEntries_T>(_numSubEntries)),
      inflationDest(std::forward<_inflationDest_T>(_inflationDest)),
      flags(std::forward<_flags_T>(_flags)),
      homeDomain(std::forward<_homeDomain_T>(_homeDomain)),
      thresholds(std::forward<_thresholds_T>(_thresholds)),
      signers(std::forward<_signers_T>(_signers)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountEntry::_ext_t::_v1_t::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AccountEntry::_ext_t::_v1_t::_ext_t;
  using case_type = ::stellar::AccountEntry::_ext_t::_v1_t::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AccountEntry::_ext_t::_v1_t::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntry::_ext_t::_v1_t::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntry::_ext_t::_v1_t::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AccountEntry::_ext_t::_v1_t>
  : xdr_struct_base<field_ptr<::stellar::AccountEntry::_ext_t::_v1_t,
                              decltype(::stellar::AccountEntry::_ext_t::_v1_t::liabilities),
                              &::stellar::AccountEntry::_ext_t::_v1_t::liabilities>,
                    field_ptr<::stellar::AccountEntry::_ext_t::_v1_t,
                              decltype(::stellar::AccountEntry::_ext_t::_v1_t::ext),
                              &::stellar::AccountEntry::_ext_t::_v1_t::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntry::_ext_t::_v1_t &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntry::_ext_t::_v1_t &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AccountEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AccountEntry::_ext_t;
  using case_type = ::stellar::AccountEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v1";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AccountEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AccountEntry>
  : xdr_struct_base<field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::accountID),
                              &::stellar::AccountEntry::accountID>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::balance),
                              &::stellar::AccountEntry::balance>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::seqNum),
                              &::stellar::AccountEntry::seqNum>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::numSubEntries),
                              &::stellar::AccountEntry::numSubEntries>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::inflationDest),
                              &::stellar::AccountEntry::inflationDest>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::flags),
                              &::stellar::AccountEntry::flags>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::homeDomain),
                              &::stellar::AccountEntry::homeDomain>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::thresholds),
                              &::stellar::AccountEntry::thresholds>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::signers),
                              &::stellar::AccountEntry::signers>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::ext),
                              &::stellar::AccountEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.numSubEntries, "numSubEntries");
    archive(ar, obj.inflationDest, "inflationDest");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.homeDomain, "homeDomain");
    archive(ar, obj.thresholds, "thresholds");
    archive(ar, obj.signers, "signers");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.numSubEntries, "numSubEntries");
    archive(ar, obj.inflationDest, "inflationDest");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.homeDomain, "homeDomain");
    archive(ar, obj.thresholds, "thresholds");
    archive(ar, obj.signers, "signers");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum TrustLineFlags : std::int32_t {
  AUTHORIZED_FLAG = 1,
  AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG = 2,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TrustLineFlags>
  : xdr_integral_base<::stellar::TrustLineFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::TrustLineFlags val) {
    switch (val) {
    case ::stellar::AUTHORIZED_FLAG:
      return "AUTHORIZED_FLAG";
    case ::stellar::AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG:
      return "AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::AUTHORIZED_FLAG,
      ::stellar::AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_TRUSTLINE_FLAGS = 1;
Constexpr const std::uint32_t MASK_TRUSTLINE_FLAGS_V13 = 3;

struct TrustLineEntry {
  struct _ext_t {
    struct _v1_t {
      struct _ext_t {
        using _xdr_case_type = xdr::xdr_traits<int>::case_type;
      private:
        _xdr_case_type v_;
      public:
        static Constexpr const bool _xdr_has_default_case = false;
        static const std::vector<int> &_xdr_case_values() {
          static const std::vector<int> _xdr_disc_vec {
            0
          };
          return _xdr_disc_vec;
        }
        static Constexpr int _xdr_field_number(_xdr_case_type which) {
          return which == 0 ? 0
            : -1;
        }
        template<typename _F, typename..._A> static bool
        _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
          switch (_which) {
          case 0:
            return true;
          }
          return false;
        }

        _xdr_case_type _xdr_discriminant() const { return v_; }
        void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
          int fnum = _xdr_field_number(which);
          if (fnum < 0 && validate)
            throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
          if (fnum != _xdr_field_number(v_)) {
            this->~_ext_t();
            v_ = which;
            _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
          }
          else
            v_ = which;
        }
        explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
        }
        _ext_t(const _ext_t &source) : v_(source.v_) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
        }
        _ext_t(_ext_t &&source) : v_(source.v_) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                            std::move(source));
        }
        ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
        _ext_t &operator=(const _ext_t &source) {
          if (_xdr_field_number(v_)
              == _xdr_field_number(source.v_))
            _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
          else {
            this->~_ext_t();
            v_ = std::numeric_limits<_xdr_case_type>::max();
            _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
          }
          v_ = source.v_;
          return *this;
        }
        _ext_t &operator=(_ext_t &&source) {
          if (_xdr_field_number(v_)
               == _xdr_field_number(source.v_))
            _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                              std::move(source));
          else {
            this->~_ext_t();
            v_ = std::numeric_limits<_xdr_case_type>::max();
            _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                              std::move(source));
          }
          v_ = source.v_;
          return *this;
        }

        std::int32_t v() const { return std::int32_t(v_); }
        _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
          _xdr_discriminant(_xdr_d, _xdr_validate);
          return *this;
        }

      };

      Liabilities liabilities{};
      _ext_t ext{};

      _v1_t() = default;
      template<typename _liabilities_T,
               typename _ext_T,
               typename = typename
               std::enable_if<std::is_constructible<Liabilities, _liabilities_T>::value
                              && std::is_constructible<_ext_t, _ext_T>::value
                             >::type>
      explicit _v1_t(_liabilities_T &&_liabilities,
                     _ext_T &&_ext)
        : liabilities(std::forward<_liabilities_T>(_liabilities)),
          ext(std::forward<_ext_T>(_ext)) {}
    };

    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      _v1_t v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        1
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 1 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 1:
        _f(&_ext_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    _v1_t &v1() {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
    const _v1_t &v1() const {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
  };

  AccountID accountID{};
  Asset asset{};
  int64 balance{};
  int64 limit{};
  uint32 flags{};
  _ext_t ext{};

  TrustLineEntry() = default;
  template<typename _accountID_T,
           typename _asset_T,
           typename _balance_T,
           typename _limit_T,
           typename _flags_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                          && std::is_constructible<Asset, _asset_T>::value
                          && std::is_constructible<int64, _balance_T>::value
                          && std::is_constructible<int64, _limit_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit TrustLineEntry(_accountID_T &&_accountID,
                          _asset_T &&_asset,
                          _balance_T &&_balance,
                          _limit_T &&_limit,
                          _flags_T &&_flags,
                          _ext_T &&_ext)
    : accountID(std::forward<_accountID_T>(_accountID)),
      asset(std::forward<_asset_T>(_asset)),
      balance(std::forward<_balance_T>(_balance)),
      limit(std::forward<_limit_T>(_limit)),
      flags(std::forward<_flags_T>(_flags)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t;
  using case_type = ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntry::_ext_t::_v1_t>
  : xdr_struct_base<field_ptr<::stellar::TrustLineEntry::_ext_t::_v1_t,
                              decltype(::stellar::TrustLineEntry::_ext_t::_v1_t::liabilities),
                              &::stellar::TrustLineEntry::_ext_t::_v1_t::liabilities>,
                    field_ptr<::stellar::TrustLineEntry::_ext_t::_v1_t,
                              decltype(::stellar::TrustLineEntry::_ext_t::_v1_t::ext),
                              &::stellar::TrustLineEntry::_ext_t::_v1_t::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry::_ext_t::_v1_t &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry::_ext_t::_v1_t &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TrustLineEntry::_ext_t;
  using case_type = ::stellar::TrustLineEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v1";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TrustLineEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntry>
  : xdr_struct_base<field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::accountID),
                              &::stellar::TrustLineEntry::accountID>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::asset),
                              &::stellar::TrustLineEntry::asset>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::balance),
                              &::stellar::TrustLineEntry::balance>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::limit),
                              &::stellar::TrustLineEntry::limit>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::flags),
                              &::stellar::TrustLineEntry::flags>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::ext),
                              &::stellar::TrustLineEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.limit, "limit");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.limit, "limit");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum OfferEntryFlags : std::int32_t {
  PASSIVE_FLAG = 1,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OfferEntryFlags>
  : xdr_integral_base<::stellar::OfferEntryFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::OfferEntryFlags val) {
    switch (val) {
    case ::stellar::PASSIVE_FLAG:
      return "PASSIVE_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::PASSIVE_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_OFFERENTRY_FLAGS = 1;

struct OfferEntry {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  AccountID sellerID{};
  int64 offerID{};
  Asset selling{};
  Asset buying{};
  int64 amount{};
  Price price{};
  uint32 flags{};
  _ext_t ext{};

  OfferEntry() = default;
  template<typename _sellerID_T,
           typename _offerID_T,
           typename _selling_T,
           typename _buying_T,
           typename _amount_T,
           typename _price_T,
           typename _flags_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _sellerID_T>::value
                          && std::is_constructible<int64, _offerID_T>::value
                          && std::is_constructible<Asset, _selling_T>::value
                          && std::is_constructible<Asset, _buying_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                          && std::is_constructible<Price, _price_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit OfferEntry(_sellerID_T &&_sellerID,
                      _offerID_T &&_offerID,
                      _selling_T &&_selling,
                      _buying_T &&_buying,
                      _amount_T &&_amount,
                      _price_T &&_price,
                      _flags_T &&_flags,
                      _ext_T &&_ext)
    : sellerID(std::forward<_sellerID_T>(_sellerID)),
      offerID(std::forward<_offerID_T>(_offerID)),
      selling(std::forward<_selling_T>(_selling)),
      buying(std::forward<_buying_T>(_buying)),
      amount(std::forward<_amount_T>(_amount)),
      price(std::forward<_price_T>(_price)),
      flags(std::forward<_flags_T>(_flags)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OfferEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::OfferEntry::_ext_t;
  using case_type = ::stellar::OfferEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::OfferEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::OfferEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::OfferEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::OfferEntry>
  : xdr_struct_base<field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::sellerID),
                              &::stellar::OfferEntry::sellerID>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::offerID),
                              &::stellar::OfferEntry::offerID>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::selling),
                              &::stellar::OfferEntry::selling>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::buying),
                              &::stellar::OfferEntry::buying>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::amount),
                              &::stellar::OfferEntry::amount>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::price),
                              &::stellar::OfferEntry::price>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::flags),
                              &::stellar::OfferEntry::flags>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::ext),
                              &::stellar::OfferEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::OfferEntry &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::OfferEntry &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct DataEntry {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  AccountID accountID{};
  string64 dataName{};
  DataValue dataValue{};
  _ext_t ext{};

  DataEntry() = default;
  template<typename _accountID_T,
           typename _dataName_T,
           typename _dataValue_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                          && std::is_constructible<string64, _dataName_T>::value
                          && std::is_constructible<DataValue, _dataValue_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit DataEntry(_accountID_T &&_accountID,
                     _dataName_T &&_dataName,
                     _dataValue_T &&_dataValue,
                     _ext_T &&_ext)
    : accountID(std::forward<_accountID_T>(_accountID)),
      dataName(std::forward<_dataName_T>(_dataName)),
      dataValue(std::forward<_dataValue_T>(_dataValue)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::DataEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::DataEntry::_ext_t;
  using case_type = ::stellar::DataEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::DataEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::DataEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::DataEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::DataEntry>
  : xdr_struct_base<field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::accountID),
                              &::stellar::DataEntry::accountID>,
                    field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::dataName),
                              &::stellar::DataEntry::dataName>,
                    field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::dataValue),
                              &::stellar::DataEntry::dataValue>,
                    field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::ext),
                              &::stellar::DataEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::DataEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.dataName, "dataName");
    archive(ar, obj.dataValue, "dataValue");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::DataEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.dataName, "dataName");
    archive(ar, obj.dataValue, "dataValue");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct LedgerEntry {
  struct _data_t {
    using _xdr_case_type = xdr::xdr_traits<LedgerEntryType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      AccountEntry account_;
      TrustLineEntry trustLine_;
      OfferEntry offer_;
      DataEntry data_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<LedgerEntryType> &_xdr_case_values() {
      static const std::vector<LedgerEntryType> _xdr_disc_vec {
        ACCOUNT,
        TRUSTLINE,
        OFFER,
        DATA
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == ACCOUNT ? 1
        : which == TRUSTLINE ? 2
        : which == OFFER ? 3
        : which == DATA ? 4
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case ACCOUNT:
        _f(&_data_t::account_, std::forward<_A>(_a)...);
        return true;
      case TRUSTLINE:
        _f(&_data_t::trustLine_, std::forward<_A>(_a)...);
        return true;
      case OFFER:
        _f(&_data_t::offer_, std::forward<_A>(_a)...);
        return true;
      case DATA:
        _f(&_data_t::data_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _data_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_data_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _data_t(LedgerEntryType which = LedgerEntryType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _data_t(const _data_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _data_t(_data_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_data_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _data_t &operator=(const _data_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_data_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _data_t &operator=(_data_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_data_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    LedgerEntryType type() const { return LedgerEntryType(type_); }
    _data_t &type(LedgerEntryType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    AccountEntry &account() {
      if (_xdr_field_number(type_) == 1)
        return account_;
      throw xdr::xdr_wrong_union("_data_t: account accessed when not selected");
    }
    const AccountEntry &account() const {
      if (_xdr_field_number(type_) == 1)
        return account_;
      throw xdr::xdr_wrong_union("_data_t: account accessed when not selected");
    }
    TrustLineEntry &trustLine() {
      if (_xdr_field_number(type_) == 2)
        return trustLine_;
      throw xdr::xdr_wrong_union("_data_t: trustLine accessed when not selected");
    }
    const TrustLineEntry &trustLine() const {
      if (_xdr_field_number(type_) == 2)
        return trustLine_;
      throw xdr::xdr_wrong_union("_data_t: trustLine accessed when not selected");
    }
    OfferEntry &offer() {
      if (_xdr_field_number(type_) == 3)
        return offer_;
      throw xdr::xdr_wrong_union("_data_t: offer accessed when not selected");
    }
    const OfferEntry &offer() const {
      if (_xdr_field_number(type_) == 3)
        return offer_;
      throw xdr::xdr_wrong_union("_data_t: offer accessed when not selected");
    }
    DataEntry &data() {
      if (_xdr_field_number(type_) == 4)
        return data_;
      throw xdr::xdr_wrong_union("_data_t: data accessed when not selected");
    }
    const DataEntry &data() const {
      if (_xdr_field_number(type_) == 4)
        return data_;
      throw xdr::xdr_wrong_union("_data_t: data accessed when not selected");
    }
  };
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  uint32 lastModifiedLedgerSeq{};
  _data_t data{};
  _ext_t ext{};

  LedgerEntry() = default;
  template<typename _lastModifiedLedgerSeq_T,
           typename _data_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<uint32, _lastModifiedLedgerSeq_T>::value
                          && std::is_constructible<_data_t, _data_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit LedgerEntry(_lastModifiedLedgerSeq_T &&_lastModifiedLedgerSeq,
                       _data_T &&_data,
                       _ext_T &&_ext)
    : lastModifiedLedgerSeq(std::forward<_lastModifiedLedgerSeq_T>(_lastModifiedLedgerSeq)),
      data(std::forward<_data_T>(_data)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LedgerEntry::_data_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LedgerEntry::_data_t;
  using case_type = ::stellar::LedgerEntry::_data_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "account";
    case 2:
      return "trustLine";
    case 3:
      return "offer";
    case 4:
      return "data";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LedgerEntry::_data_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _data_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntry::_data_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _data_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntry::_data_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LedgerEntry::_ext_t;
  using case_type = ::stellar::LedgerEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LedgerEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerEntry>
  : xdr_struct_base<field_ptr<::stellar::LedgerEntry,
                              decltype(::stellar::LedgerEntry::lastModifiedLedgerSeq),
                              &::stellar::LedgerEntry::lastModifiedLedgerSeq>,
                    field_ptr<::stellar::LedgerEntry,
                              decltype(::stellar::LedgerEntry::data),
                              &::stellar::LedgerEntry::data>,
                    field_ptr<::stellar::LedgerEntry,
                              decltype(::stellar::LedgerEntry::ext),
                              &::stellar::LedgerEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntry &obj) {
    archive(ar, obj.lastModifiedLedgerSeq, "lastModifiedLedgerSeq");
    archive(ar, obj.data, "data");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntry &obj) {
    archive(ar, obj.lastModifiedLedgerSeq, "lastModifiedLedgerSeq");
    archive(ar, obj.data, "data");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum EnvelopeType : std::int32_t {
  ENVELOPE_TYPE_TX_V0 = 0,
  ENVELOPE_TYPE_SCP = 1,
  ENVELOPE_TYPE_TX = 2,
  ENVELOPE_TYPE_AUTH = 3,
  ENVELOPE_TYPE_SCPVALUE = 4,
  ENVELOPE_TYPE_TX_FEE_BUMP = 5,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::EnvelopeType>
  : xdr_integral_base<::stellar::EnvelopeType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::EnvelopeType val) {
    switch (val) {
    case ::stellar::ENVELOPE_TYPE_TX_V0:
      return "ENVELOPE_TYPE_TX_V0";
    case ::stellar::ENVELOPE_TYPE_SCP:
      return "ENVELOPE_TYPE_SCP";
    case ::stellar::ENVELOPE_TYPE_TX:
      return "ENVELOPE_TYPE_TX";
    case ::stellar::ENVELOPE_TYPE_AUTH:
      return "ENVELOPE_TYPE_AUTH";
    case ::stellar::ENVELOPE_TYPE_SCPVALUE:
      return "ENVELOPE_TYPE_SCPVALUE";
    case ::stellar::ENVELOPE_TYPE_TX_FEE_BUMP:
      return "ENVELOPE_TYPE_TX_FEE_BUMP";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ENVELOPE_TYPE_TX_V0,
      ::stellar::ENVELOPE_TYPE_SCP,
      ::stellar::ENVELOPE_TYPE_TX,
      ::stellar::ENVELOPE_TYPE_AUTH,
      ::stellar::ENVELOPE_TYPE_SCPVALUE,
      ::stellar::ENVELOPE_TYPE_TX_FEE_BUMP
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

}

#endif // !__XDR_SRC_GENERATED_XDR_STELLAR_LEDGER_ENTRIES_H_INCLUDED__
