// -*- C++ -*-
// Automatically generated from rpc_msg.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_RPC_MSG_HH_INCLUDED__
#define __XDR_RPC_MSG_HH_INCLUDED__ 1

#include <xdrpp/types.h>

namespace xdr {

enum auth_flavor : std::int32_t {
  AUTH_NONE = 0,
  AUTH_SYS = 1,
  AUTH_SHORT = 2,
  AUTH_DH = 3,
  RPCSEC_GSS = 6,
};
} namespace xdr {
template<> struct xdr_traits<::xdr::auth_flavor>
  : xdr_integral_base<::xdr::auth_flavor, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::xdr::auth_flavor val) {
    switch (val) {
    case ::xdr::AUTH_NONE:
      return "AUTH_NONE";
    case ::xdr::AUTH_SYS:
      return "AUTH_SYS";
    case ::xdr::AUTH_SHORT:
      return "AUTH_SHORT";
    case ::xdr::AUTH_DH:
      return "AUTH_DH";
    case ::xdr::RPCSEC_GSS:
      return "RPCSEC_GSS";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::xdr::AUTH_NONE,
      ::xdr::AUTH_SYS,
      ::xdr::AUTH_SHORT,
      ::xdr::AUTH_DH,
      ::xdr::RPCSEC_GSS
    };
    return _xdr_enum_vec;
  }
};
} namespace xdr {

struct opaque_auth {
  auth_flavor flavor{};
  xdr::opaque_vec<400> body{};

  opaque_auth() = default;
  template<typename _flavor_T,
           typename _body_T,
           typename = typename
           std::enable_if<std::is_constructible<auth_flavor, _flavor_T>::value
                          && std::is_constructible<xdr::opaque_vec<400>, _body_T>::value
                         >::type>
  explicit opaque_auth(_flavor_T &&_flavor,
                       _body_T &&_body)
    : flavor(std::forward<_flavor_T>(_flavor)),
      body(std::forward<_body_T>(_body)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::opaque_auth>
  : xdr_struct_base<field_ptr<::xdr::opaque_auth,
                              decltype(::xdr::opaque_auth::flavor),
                              &::xdr::opaque_auth::flavor>,
                    field_ptr<::xdr::opaque_auth,
                              decltype(::xdr::opaque_auth::body),
                              &::xdr::opaque_auth::body>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::opaque_auth &obj) {
    archive(ar, obj.flavor, "flavor");
    archive(ar, obj.body, "body");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::opaque_auth &obj) {
    archive(ar, obj.flavor, "flavor");
    archive(ar, obj.body, "body");
    xdr::validate(obj);
  }
};
} namespace xdr {

enum msg_type : std::int32_t {
  CALL = 0,
  REPLY = 1,
};
} namespace xdr {
template<> struct xdr_traits<::xdr::msg_type>
  : xdr_integral_base<::xdr::msg_type, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::xdr::msg_type val) {
    switch (val) {
    case ::xdr::CALL:
      return "CALL";
    case ::xdr::REPLY:
      return "REPLY";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::xdr::CALL,
      ::xdr::REPLY
    };
    return _xdr_enum_vec;
  }
};
} namespace xdr {

enum reply_stat : std::int32_t {
  MSG_ACCEPTED = 0,
  MSG_DENIED = 1,
};
} namespace xdr {
template<> struct xdr_traits<::xdr::reply_stat>
  : xdr_integral_base<::xdr::reply_stat, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::xdr::reply_stat val) {
    switch (val) {
    case ::xdr::MSG_ACCEPTED:
      return "MSG_ACCEPTED";
    case ::xdr::MSG_DENIED:
      return "MSG_DENIED";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::xdr::MSG_ACCEPTED,
      ::xdr::MSG_DENIED
    };
    return _xdr_enum_vec;
  }
};
} namespace xdr {

enum accept_stat : std::int32_t {
  SUCCESS = 0,
  PROG_UNAVAIL = 1,
  PROG_MISMATCH = 2,
  PROC_UNAVAIL = 3,
  GARBAGE_ARGS = 4,
  SYSTEM_ERR = 5,
};
} namespace xdr {
template<> struct xdr_traits<::xdr::accept_stat>
  : xdr_integral_base<::xdr::accept_stat, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::xdr::accept_stat val) {
    switch (val) {
    case ::xdr::SUCCESS:
      return "SUCCESS";
    case ::xdr::PROG_UNAVAIL:
      return "PROG_UNAVAIL";
    case ::xdr::PROG_MISMATCH:
      return "PROG_MISMATCH";
    case ::xdr::PROC_UNAVAIL:
      return "PROC_UNAVAIL";
    case ::xdr::GARBAGE_ARGS:
      return "GARBAGE_ARGS";
    case ::xdr::SYSTEM_ERR:
      return "SYSTEM_ERR";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::xdr::SUCCESS,
      ::xdr::PROG_UNAVAIL,
      ::xdr::PROG_MISMATCH,
      ::xdr::PROC_UNAVAIL,
      ::xdr::GARBAGE_ARGS,
      ::xdr::SYSTEM_ERR
    };
    return _xdr_enum_vec;
  }
};
} namespace xdr {

enum reject_stat : std::int32_t {
  RPC_MISMATCH = 0,
  AUTH_ERROR = 1,
};
} namespace xdr {
template<> struct xdr_traits<::xdr::reject_stat>
  : xdr_integral_base<::xdr::reject_stat, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::xdr::reject_stat val) {
    switch (val) {
    case ::xdr::RPC_MISMATCH:
      return "RPC_MISMATCH";
    case ::xdr::AUTH_ERROR:
      return "AUTH_ERROR";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::xdr::RPC_MISMATCH,
      ::xdr::AUTH_ERROR
    };
    return _xdr_enum_vec;
  }
};
} namespace xdr {

enum auth_stat : std::int32_t {
  AUTH_OK = 0,
  AUTH_BADCRED = 1,
  AUTH_REJECTEDCRED = 2,
  AUTH_BADVERF = 3,
  AUTH_REJECTEDVERF = 4,
  AUTH_TOOWEAK = 5,
  AUTH_INVALIDRESP = 6,
  AUTH_FAILED = 7,
  AUTH_KERB_GENERIC = 8,
  AUTH_TIMEEXPIRE = 9,
  AUTH_TKT_FILE = 10,
  AUTH_DECODE = 11,
  AUTH_NET_ADDR = 12,
  RPCSEC_GSS_CREDPROBLEM = 13,
  RPCSEC_GSS_CTXPROBLEM = 14,
};
} namespace xdr {
template<> struct xdr_traits<::xdr::auth_stat>
  : xdr_integral_base<::xdr::auth_stat, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::xdr::auth_stat val) {
    switch (val) {
    case ::xdr::AUTH_OK:
      return "AUTH_OK";
    case ::xdr::AUTH_BADCRED:
      return "AUTH_BADCRED";
    case ::xdr::AUTH_REJECTEDCRED:
      return "AUTH_REJECTEDCRED";
    case ::xdr::AUTH_BADVERF:
      return "AUTH_BADVERF";
    case ::xdr::AUTH_REJECTEDVERF:
      return "AUTH_REJECTEDVERF";
    case ::xdr::AUTH_TOOWEAK:
      return "AUTH_TOOWEAK";
    case ::xdr::AUTH_INVALIDRESP:
      return "AUTH_INVALIDRESP";
    case ::xdr::AUTH_FAILED:
      return "AUTH_FAILED";
    case ::xdr::AUTH_KERB_GENERIC:
      return "AUTH_KERB_GENERIC";
    case ::xdr::AUTH_TIMEEXPIRE:
      return "AUTH_TIMEEXPIRE";
    case ::xdr::AUTH_TKT_FILE:
      return "AUTH_TKT_FILE";
    case ::xdr::AUTH_DECODE:
      return "AUTH_DECODE";
    case ::xdr::AUTH_NET_ADDR:
      return "AUTH_NET_ADDR";
    case ::xdr::RPCSEC_GSS_CREDPROBLEM:
      return "RPCSEC_GSS_CREDPROBLEM";
    case ::xdr::RPCSEC_GSS_CTXPROBLEM:
      return "RPCSEC_GSS_CTXPROBLEM";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::xdr::AUTH_OK,
      ::xdr::AUTH_BADCRED,
      ::xdr::AUTH_REJECTEDCRED,
      ::xdr::AUTH_BADVERF,
      ::xdr::AUTH_REJECTEDVERF,
      ::xdr::AUTH_TOOWEAK,
      ::xdr::AUTH_INVALIDRESP,
      ::xdr::AUTH_FAILED,
      ::xdr::AUTH_KERB_GENERIC,
      ::xdr::AUTH_TIMEEXPIRE,
      ::xdr::AUTH_TKT_FILE,
      ::xdr::AUTH_DECODE,
      ::xdr::AUTH_NET_ADDR,
      ::xdr::RPCSEC_GSS_CREDPROBLEM,
      ::xdr::RPCSEC_GSS_CTXPROBLEM
    };
    return _xdr_enum_vec;
  }
};
} namespace xdr {

struct call_body {
  std::uint32_t rpcvers{};
  std::uint32_t prog{};
  std::uint32_t vers{};
  std::uint32_t proc{};
  opaque_auth cred{};
  opaque_auth verf{};

  call_body() = default;
  template<typename _rpcvers_T,
           typename _prog_T,
           typename _vers_T,
           typename _proc_T,
           typename _cred_T,
           typename _verf_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _rpcvers_T>::value
                          && std::is_constructible<std::uint32_t, _prog_T>::value
                          && std::is_constructible<std::uint32_t, _vers_T>::value
                          && std::is_constructible<std::uint32_t, _proc_T>::value
                          && std::is_constructible<opaque_auth, _cred_T>::value
                          && std::is_constructible<opaque_auth, _verf_T>::value
                         >::type>
  explicit call_body(_rpcvers_T &&_rpcvers,
                     _prog_T &&_prog,
                     _vers_T &&_vers,
                     _proc_T &&_proc,
                     _cred_T &&_cred,
                     _verf_T &&_verf)
    : rpcvers(std::forward<_rpcvers_T>(_rpcvers)),
      prog(std::forward<_prog_T>(_prog)),
      vers(std::forward<_vers_T>(_vers)),
      proc(std::forward<_proc_T>(_proc)),
      cred(std::forward<_cred_T>(_cred)),
      verf(std::forward<_verf_T>(_verf)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::call_body>
  : xdr_struct_base<field_ptr<::xdr::call_body,
                              decltype(::xdr::call_body::rpcvers),
                              &::xdr::call_body::rpcvers>,
                    field_ptr<::xdr::call_body,
                              decltype(::xdr::call_body::prog),
                              &::xdr::call_body::prog>,
                    field_ptr<::xdr::call_body,
                              decltype(::xdr::call_body::vers),
                              &::xdr::call_body::vers>,
                    field_ptr<::xdr::call_body,
                              decltype(::xdr::call_body::proc),
                              &::xdr::call_body::proc>,
                    field_ptr<::xdr::call_body,
                              decltype(::xdr::call_body::cred),
                              &::xdr::call_body::cred>,
                    field_ptr<::xdr::call_body,
                              decltype(::xdr::call_body::verf),
                              &::xdr::call_body::verf>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::call_body &obj) {
    archive(ar, obj.rpcvers, "rpcvers");
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.cred, "cred");
    archive(ar, obj.verf, "verf");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::call_body &obj) {
    archive(ar, obj.rpcvers, "rpcvers");
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.cred, "cred");
    archive(ar, obj.verf, "verf");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct accepted_reply {
  struct _reply_data_t {
    struct _mismatch_info_t {
      std::uint32_t low{};
      std::uint32_t high{};

      _mismatch_info_t() = default;
      template<typename _low_T,
               typename _high_T,
               typename = typename
               std::enable_if<std::is_constructible<std::uint32_t, _low_T>::value
                              && std::is_constructible<std::uint32_t, _high_T>::value
                             >::type>
      explicit _mismatch_info_t(_low_T &&_low,
                                _high_T &&_high)
        : low(std::forward<_low_T>(_low)),
          high(std::forward<_high_T>(_high)) {}
    };

    using _xdr_case_type = xdr::xdr_traits<accept_stat>::case_type;
  private:
    _xdr_case_type stat_;
    union {
      xdr::opaque_array<0> results_;
      _mismatch_info_t mismatch_info_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = true;
    static const std::vector<accept_stat> &_xdr_case_values() {
      static const std::vector<accept_stat> _xdr_disc_vec {};
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == SUCCESS ? 1
        : which == PROG_MISMATCH ? 2
        : 0;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case SUCCESS:
        _f(&_reply_data_t::results_, std::forward<_A>(_a)...);
        return true;
      case PROG_MISMATCH:
        _f(&_reply_data_t::mismatch_info_, std::forward<_A>(_a)...);
        return true;
      default:
        return true;
      }
    }

    _xdr_case_type _xdr_discriminant() const { return stat_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of stat in _reply_data_t");
      if (fnum != _xdr_field_number(stat_)) {
        this->~_reply_data_t();
        stat_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this);
      }
      else
        stat_ = which;
    }
    explicit _reply_data_t(accept_stat which = accept_stat{}) : stat_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this);
    }
    _reply_data_t(const _reply_data_t &source) : stat_(source.stat_) {
      _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this, source);
    }
    _reply_data_t(_reply_data_t &&source) : stat_(source.stat_) {
      _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this,
                        std::move(source));
    }
    ~_reply_data_t() { _xdr_with_mem_ptr(xdr::field_destructor, stat_, *this); }
    _reply_data_t &operator=(const _reply_data_t &source) {
      if (_xdr_field_number(stat_)
          == _xdr_field_number(source.stat_))
        _xdr_with_mem_ptr(xdr::field_assigner, stat_, *this, source);
      else {
        this->~_reply_data_t();
        stat_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.stat_, *this, source);
      }
      stat_ = source.stat_;
      return *this;
    }
    _reply_data_t &operator=(_reply_data_t &&source) {
      if (_xdr_field_number(stat_)
           == _xdr_field_number(source.stat_))
        _xdr_with_mem_ptr(xdr::field_assigner, stat_, *this,
                          std::move(source));
      else {
        this->~_reply_data_t();
        stat_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.stat_, *this,
                          std::move(source));
      }
      stat_ = source.stat_;
      return *this;
    }

    accept_stat stat() const { return accept_stat(stat_); }
    _reply_data_t &stat(accept_stat _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    xdr::opaque_array<0> &results() {
      if (_xdr_field_number(stat_) == 1)
        return results_;
      throw xdr::xdr_wrong_union("_reply_data_t: results accessed when not selected");
    }
    const xdr::opaque_array<0> &results() const {
      if (_xdr_field_number(stat_) == 1)
        return results_;
      throw xdr::xdr_wrong_union("_reply_data_t: results accessed when not selected");
    }
    _mismatch_info_t &mismatch_info() {
      if (_xdr_field_number(stat_) == 2)
        return mismatch_info_;
      throw xdr::xdr_wrong_union("_reply_data_t: mismatch_info accessed when not selected");
    }
    const _mismatch_info_t &mismatch_info() const {
      if (_xdr_field_number(stat_) == 2)
        return mismatch_info_;
      throw xdr::xdr_wrong_union("_reply_data_t: mismatch_info accessed when not selected");
    }
  };

  opaque_auth verf{};
  _reply_data_t reply_data{};

  accepted_reply() = default;
  template<typename _verf_T,
           typename _reply_data_T,
           typename = typename
           std::enable_if<std::is_constructible<opaque_auth, _verf_T>::value
                          && std::is_constructible<_reply_data_t, _reply_data_T>::value
                         >::type>
  explicit accepted_reply(_verf_T &&_verf,
                          _reply_data_T &&_reply_data)
    : verf(std::forward<_verf_T>(_verf)),
      reply_data(std::forward<_reply_data_T>(_reply_data)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::accepted_reply::_reply_data_t::_mismatch_info_t>
  : xdr_struct_base<field_ptr<::xdr::accepted_reply::_reply_data_t::_mismatch_info_t,
                              decltype(::xdr::accepted_reply::_reply_data_t::_mismatch_info_t::low),
                              &::xdr::accepted_reply::_reply_data_t::_mismatch_info_t::low>,
                    field_ptr<::xdr::accepted_reply::_reply_data_t::_mismatch_info_t,
                              decltype(::xdr::accepted_reply::_reply_data_t::_mismatch_info_t::high),
                              &::xdr::accepted_reply::_reply_data_t::_mismatch_info_t::high>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::accepted_reply::_reply_data_t::_mismatch_info_t &obj) {
    archive(ar, obj.low, "low");
    archive(ar, obj.high, "high");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::accepted_reply::_reply_data_t::_mismatch_info_t &obj) {
    archive(ar, obj.low, "low");
    archive(ar, obj.high, "high");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::xdr::accepted_reply::_reply_data_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::xdr::accepted_reply::_reply_data_t;
  using case_type = ::xdr::accepted_reply::_reply_data_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().stat());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "results";
    case 2:
      return "mismatch_info";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::xdr::accepted_reply::_reply_data_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of stat in _reply_data_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::accepted_reply::_reply_data_t &obj) {
    xdr::archive(ar, obj.stat(), "stat");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.stat(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of stat in _reply_data_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::accepted_reply::_reply_data_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "stat");
    obj.stat(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.stat(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::xdr::accepted_reply>
  : xdr_struct_base<field_ptr<::xdr::accepted_reply,
                              decltype(::xdr::accepted_reply::verf),
                              &::xdr::accepted_reply::verf>,
                    field_ptr<::xdr::accepted_reply,
                              decltype(::xdr::accepted_reply::reply_data),
                              &::xdr::accepted_reply::reply_data>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::accepted_reply &obj) {
    archive(ar, obj.verf, "verf");
    archive(ar, obj.reply_data, "reply_data");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::accepted_reply &obj) {
    archive(ar, obj.verf, "verf");
    archive(ar, obj.reply_data, "reply_data");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rejected_reply {
  struct _mismatch_info_t {
    std::uint32_t low{};
    std::uint32_t high{};

    _mismatch_info_t() = default;
    template<typename _low_T,
             typename _high_T,
             typename = typename
             std::enable_if<std::is_constructible<std::uint32_t, _low_T>::value
                            && std::is_constructible<std::uint32_t, _high_T>::value
                           >::type>
    explicit _mismatch_info_t(_low_T &&_low,
                              _high_T &&_high)
      : low(std::forward<_low_T>(_low)),
        high(std::forward<_high_T>(_high)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<reject_stat>::case_type;
private:
  _xdr_case_type stat_;
  union {
    _mismatch_info_t mismatch_info_;
    auth_stat rj_why_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<reject_stat> &_xdr_case_values() {
    static const std::vector<reject_stat> _xdr_disc_vec {
      RPC_MISMATCH,
      AUTH_ERROR
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == RPC_MISMATCH ? 1
      : which == AUTH_ERROR ? 2
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case RPC_MISMATCH:
      _f(&rejected_reply::mismatch_info_, std::forward<_A>(_a)...);
      return true;
    case AUTH_ERROR:
      _f(&rejected_reply::rj_why_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return stat_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of stat in rejected_reply");
    if (fnum != _xdr_field_number(stat_)) {
      this->~rejected_reply();
      stat_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this);
    }
    else
      stat_ = which;
  }
  explicit rejected_reply(reject_stat which = reject_stat{}) : stat_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this);
  }
  rejected_reply(const rejected_reply &source) : stat_(source.stat_) {
    _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this, source);
  }
  rejected_reply(rejected_reply &&source) : stat_(source.stat_) {
    _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this,
                      std::move(source));
  }
  ~rejected_reply() { _xdr_with_mem_ptr(xdr::field_destructor, stat_, *this); }
  rejected_reply &operator=(const rejected_reply &source) {
    if (_xdr_field_number(stat_)
        == _xdr_field_number(source.stat_))
      _xdr_with_mem_ptr(xdr::field_assigner, stat_, *this, source);
    else {
      this->~rejected_reply();
      stat_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.stat_, *this, source);
    }
    stat_ = source.stat_;
    return *this;
  }
  rejected_reply &operator=(rejected_reply &&source) {
    if (_xdr_field_number(stat_)
         == _xdr_field_number(source.stat_))
      _xdr_with_mem_ptr(xdr::field_assigner, stat_, *this,
                        std::move(source));
    else {
      this->~rejected_reply();
      stat_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.stat_, *this,
                        std::move(source));
    }
    stat_ = source.stat_;
    return *this;
  }

  reject_stat stat() const { return reject_stat(stat_); }
  rejected_reply &stat(reject_stat _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _mismatch_info_t &mismatch_info() {
    if (_xdr_field_number(stat_) == 1)
      return mismatch_info_;
    throw xdr::xdr_wrong_union("rejected_reply: mismatch_info accessed when not selected");
  }
  const _mismatch_info_t &mismatch_info() const {
    if (_xdr_field_number(stat_) == 1)
      return mismatch_info_;
    throw xdr::xdr_wrong_union("rejected_reply: mismatch_info accessed when not selected");
  }
  auth_stat &rj_why() {
    if (_xdr_field_number(stat_) == 2)
      return rj_why_;
    throw xdr::xdr_wrong_union("rejected_reply: rj_why accessed when not selected");
  }
  const auth_stat &rj_why() const {
    if (_xdr_field_number(stat_) == 2)
      return rj_why_;
    throw xdr::xdr_wrong_union("rejected_reply: rj_why accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rejected_reply::_mismatch_info_t>
  : xdr_struct_base<field_ptr<::xdr::rejected_reply::_mismatch_info_t,
                              decltype(::xdr::rejected_reply::_mismatch_info_t::low),
                              &::xdr::rejected_reply::_mismatch_info_t::low>,
                    field_ptr<::xdr::rejected_reply::_mismatch_info_t,
                              decltype(::xdr::rejected_reply::_mismatch_info_t::high),
                              &::xdr::rejected_reply::_mismatch_info_t::high>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rejected_reply::_mismatch_info_t &obj) {
    archive(ar, obj.low, "low");
    archive(ar, obj.high, "high");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rejected_reply::_mismatch_info_t &obj) {
    archive(ar, obj.low, "low");
    archive(ar, obj.high, "high");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::xdr::rejected_reply> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::xdr::rejected_reply;
  using case_type = ::xdr::rejected_reply::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().stat());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "mismatch_info";
    case 2:
      return "rj_why";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::xdr::rejected_reply &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of stat in rejected_reply");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rejected_reply &obj) {
    xdr::archive(ar, obj.stat(), "stat");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.stat(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of stat in rejected_reply");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rejected_reply &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "stat");
    obj.stat(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.stat(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace xdr {

struct reply_body {
  using _xdr_case_type = xdr::xdr_traits<reply_stat>::case_type;
private:
  _xdr_case_type stat_;
  union {
    accepted_reply areply_;
    rejected_reply rreply_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<reply_stat> &_xdr_case_values() {
    static const std::vector<reply_stat> _xdr_disc_vec {
      MSG_ACCEPTED,
      MSG_DENIED
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == MSG_ACCEPTED ? 1
      : which == MSG_DENIED ? 2
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case MSG_ACCEPTED:
      _f(&reply_body::areply_, std::forward<_A>(_a)...);
      return true;
    case MSG_DENIED:
      _f(&reply_body::rreply_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return stat_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of stat in reply_body");
    if (fnum != _xdr_field_number(stat_)) {
      this->~reply_body();
      stat_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this);
    }
    else
      stat_ = which;
  }
  explicit reply_body(reply_stat which = reply_stat{}) : stat_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this);
  }
  reply_body(const reply_body &source) : stat_(source.stat_) {
    _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this, source);
  }
  reply_body(reply_body &&source) : stat_(source.stat_) {
    _xdr_with_mem_ptr(xdr::field_constructor, stat_, *this,
                      std::move(source));
  }
  ~reply_body() { _xdr_with_mem_ptr(xdr::field_destructor, stat_, *this); }
  reply_body &operator=(const reply_body &source) {
    if (_xdr_field_number(stat_)
        == _xdr_field_number(source.stat_))
      _xdr_with_mem_ptr(xdr::field_assigner, stat_, *this, source);
    else {
      this->~reply_body();
      stat_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.stat_, *this, source);
    }
    stat_ = source.stat_;
    return *this;
  }
  reply_body &operator=(reply_body &&source) {
    if (_xdr_field_number(stat_)
         == _xdr_field_number(source.stat_))
      _xdr_with_mem_ptr(xdr::field_assigner, stat_, *this,
                        std::move(source));
    else {
      this->~reply_body();
      stat_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.stat_, *this,
                        std::move(source));
    }
    stat_ = source.stat_;
    return *this;
  }

  reply_stat stat() const { return reply_stat(stat_); }
  reply_body &stat(reply_stat _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  accepted_reply &areply() {
    if (_xdr_field_number(stat_) == 1)
      return areply_;
    throw xdr::xdr_wrong_union("reply_body: areply accessed when not selected");
  }
  const accepted_reply &areply() const {
    if (_xdr_field_number(stat_) == 1)
      return areply_;
    throw xdr::xdr_wrong_union("reply_body: areply accessed when not selected");
  }
  rejected_reply &rreply() {
    if (_xdr_field_number(stat_) == 2)
      return rreply_;
    throw xdr::xdr_wrong_union("reply_body: rreply accessed when not selected");
  }
  const rejected_reply &rreply() const {
    if (_xdr_field_number(stat_) == 2)
      return rreply_;
    throw xdr::xdr_wrong_union("reply_body: rreply accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::xdr::reply_body> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::xdr::reply_body;
  using case_type = ::xdr::reply_body::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().stat());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "areply";
    case 2:
      return "rreply";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::xdr::reply_body &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of stat in reply_body");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::reply_body &obj) {
    xdr::archive(ar, obj.stat(), "stat");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.stat(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of stat in reply_body");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::reply_body &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "stat");
    obj.stat(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.stat(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rpc_msg {
  struct _body_t {
    using _xdr_case_type = xdr::xdr_traits<msg_type>::case_type;
  private:
    _xdr_case_type mtype_;
    union {
      call_body cbody_;
      reply_body rbody_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<msg_type> &_xdr_case_values() {
      static const std::vector<msg_type> _xdr_disc_vec {
        CALL,
        REPLY
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == CALL ? 1
        : which == REPLY ? 2
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case CALL:
        _f(&_body_t::cbody_, std::forward<_A>(_a)...);
        return true;
      case REPLY:
        _f(&_body_t::rbody_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return mtype_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of mtype in _body_t");
      if (fnum != _xdr_field_number(mtype_)) {
        this->~_body_t();
        mtype_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, mtype_, *this);
      }
      else
        mtype_ = which;
    }
    explicit _body_t(msg_type which = msg_type{}) : mtype_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, mtype_, *this);
    }
    _body_t(const _body_t &source) : mtype_(source.mtype_) {
      _xdr_with_mem_ptr(xdr::field_constructor, mtype_, *this, source);
    }
    _body_t(_body_t &&source) : mtype_(source.mtype_) {
      _xdr_with_mem_ptr(xdr::field_constructor, mtype_, *this,
                        std::move(source));
    }
    ~_body_t() { _xdr_with_mem_ptr(xdr::field_destructor, mtype_, *this); }
    _body_t &operator=(const _body_t &source) {
      if (_xdr_field_number(mtype_)
          == _xdr_field_number(source.mtype_))
        _xdr_with_mem_ptr(xdr::field_assigner, mtype_, *this, source);
      else {
        this->~_body_t();
        mtype_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.mtype_, *this, source);
      }
      mtype_ = source.mtype_;
      return *this;
    }
    _body_t &operator=(_body_t &&source) {
      if (_xdr_field_number(mtype_)
           == _xdr_field_number(source.mtype_))
        _xdr_with_mem_ptr(xdr::field_assigner, mtype_, *this,
                          std::move(source));
      else {
        this->~_body_t();
        mtype_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.mtype_, *this,
                          std::move(source));
      }
      mtype_ = source.mtype_;
      return *this;
    }

    msg_type mtype() const { return msg_type(mtype_); }
    _body_t &mtype(msg_type _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    call_body &cbody() {
      if (_xdr_field_number(mtype_) == 1)
        return cbody_;
      throw xdr::xdr_wrong_union("_body_t: cbody accessed when not selected");
    }
    const call_body &cbody() const {
      if (_xdr_field_number(mtype_) == 1)
        return cbody_;
      throw xdr::xdr_wrong_union("_body_t: cbody accessed when not selected");
    }
    reply_body &rbody() {
      if (_xdr_field_number(mtype_) == 2)
        return rbody_;
      throw xdr::xdr_wrong_union("_body_t: rbody accessed when not selected");
    }
    const reply_body &rbody() const {
      if (_xdr_field_number(mtype_) == 2)
        return rbody_;
      throw xdr::xdr_wrong_union("_body_t: rbody accessed when not selected");
    }
  };

  std::uint32_t xid{};
  _body_t body{};

  rpc_msg() = default;
  template<typename _xid_T,
           typename _body_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _xid_T>::value
                          && std::is_constructible<_body_t, _body_T>::value
                         >::type>
  explicit rpc_msg(_xid_T &&_xid,
                   _body_T &&_body)
    : xid(std::forward<_xid_T>(_xid)),
      body(std::forward<_body_T>(_body)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpc_msg::_body_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::xdr::rpc_msg::_body_t;
  using case_type = ::xdr::rpc_msg::_body_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().mtype());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "cbody";
    case 2:
      return "rbody";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::xdr::rpc_msg::_body_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of mtype in _body_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpc_msg::_body_t &obj) {
    xdr::archive(ar, obj.mtype(), "mtype");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.mtype(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of mtype in _body_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpc_msg::_body_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "mtype");
    obj.mtype(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.mtype(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::xdr::rpc_msg>
  : xdr_struct_base<field_ptr<::xdr::rpc_msg,
                              decltype(::xdr::rpc_msg::xid),
                              &::xdr::rpc_msg::xid>,
                    field_ptr<::xdr::rpc_msg,
                              decltype(::xdr::rpc_msg::body),
                              &::xdr::rpc_msg::body>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpc_msg &obj) {
    archive(ar, obj.xid, "xid");
    archive(ar, obj.body, "body");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpc_msg &obj) {
    archive(ar, obj.xid, "xid");
    archive(ar, obj.body, "body");
    xdr::validate(obj);
  }
};
} namespace xdr {

}

#endif // !__XDR_RPC_MSG_HH_INCLUDED__
