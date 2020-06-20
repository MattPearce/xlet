// -*- C++ -*-
// Automatically generated from ../../src/xdr/Stellar-overlay.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_SRC_GENERATED_XDR_STELLAR_OVERLAY_H_INCLUDED__
#define __XDR_SRC_GENERATED_XDR_STELLAR_OVERLAY_H_INCLUDED__ 1

#include <xdrpp/types.h>

#include "Stellar-ledger.h"

namespace stellar {

enum ErrorCode : std::int32_t {
  ERR_MISC = 0,
  ERR_DATA = 1,
  ERR_CONF = 2,
  ERR_AUTH = 3,
  ERR_LOAD = 4,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ErrorCode>
  : xdr_integral_base<::stellar::ErrorCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ErrorCode val) {
    switch (val) {
    case ::stellar::ERR_MISC:
      return "ERR_MISC";
    case ::stellar::ERR_DATA:
      return "ERR_DATA";
    case ::stellar::ERR_CONF:
      return "ERR_CONF";
    case ::stellar::ERR_AUTH:
      return "ERR_AUTH";
    case ::stellar::ERR_LOAD:
      return "ERR_LOAD";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ERR_MISC,
      ::stellar::ERR_DATA,
      ::stellar::ERR_CONF,
      ::stellar::ERR_AUTH,
      ::stellar::ERR_LOAD
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct Error {
  ErrorCode code{};
  xdr::xstring<100> msg{};

  Error() = default;
  template<typename _code_T,
           typename _msg_T,
           typename = typename
           std::enable_if<std::is_constructible<ErrorCode, _code_T>::value
                          && std::is_constructible<xdr::xstring<100>, _msg_T>::value
                         >::type>
  explicit Error(_code_T &&_code,
                 _msg_T &&_msg)
    : code(std::forward<_code_T>(_code)),
      msg(std::forward<_msg_T>(_msg)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Error>
  : xdr_struct_base<field_ptr<::stellar::Error,
                              decltype(::stellar::Error::code),
                              &::stellar::Error::code>,
                    field_ptr<::stellar::Error,
                              decltype(::stellar::Error::msg),
                              &::stellar::Error::msg>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Error &obj) {
    archive(ar, obj.code, "code");
    archive(ar, obj.msg, "msg");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Error &obj) {
    archive(ar, obj.code, "code");
    archive(ar, obj.msg, "msg");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AuthCert {
  Curve25519Public pubkey{};
  uint64 expiration{};
  Signature sig{};

  AuthCert() = default;
  template<typename _pubkey_T,
           typename _expiration_T,
           typename _sig_T,
           typename = typename
           std::enable_if<std::is_constructible<Curve25519Public, _pubkey_T>::value
                          && std::is_constructible<uint64, _expiration_T>::value
                          && std::is_constructible<Signature, _sig_T>::value
                         >::type>
  explicit AuthCert(_pubkey_T &&_pubkey,
                    _expiration_T &&_expiration,
                    _sig_T &&_sig)
    : pubkey(std::forward<_pubkey_T>(_pubkey)),
      expiration(std::forward<_expiration_T>(_expiration)),
      sig(std::forward<_sig_T>(_sig)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AuthCert>
  : xdr_struct_base<field_ptr<::stellar::AuthCert,
                              decltype(::stellar::AuthCert::pubkey),
                              &::stellar::AuthCert::pubkey>,
                    field_ptr<::stellar::AuthCert,
                              decltype(::stellar::AuthCert::expiration),
                              &::stellar::AuthCert::expiration>,
                    field_ptr<::stellar::AuthCert,
                              decltype(::stellar::AuthCert::sig),
                              &::stellar::AuthCert::sig>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AuthCert &obj) {
    archive(ar, obj.pubkey, "pubkey");
    archive(ar, obj.expiration, "expiration");
    archive(ar, obj.sig, "sig");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AuthCert &obj) {
    archive(ar, obj.pubkey, "pubkey");
    archive(ar, obj.expiration, "expiration");
    archive(ar, obj.sig, "sig");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Hello {
  uint32 ledgerVersion{};
  uint32 overlayVersion{};
  uint32 overlayMinVersion{};
  Hash networkID{};
  xdr::xstring<100> versionStr{};
  std::int32_t listeningPort{};
  NodeID peerID{};
  AuthCert cert{};
  uint256 nonce{};

  Hello() = default;
  template<typename _ledgerVersion_T,
           typename _overlayVersion_T,
           typename _overlayMinVersion_T,
           typename _networkID_T,
           typename _versionStr_T,
           typename _listeningPort_T,
           typename _peerID_T,
           typename _cert_T,
           typename _nonce_T,
           typename = typename
           std::enable_if<std::is_constructible<uint32, _ledgerVersion_T>::value
                          && std::is_constructible<uint32, _overlayVersion_T>::value
                          && std::is_constructible<uint32, _overlayMinVersion_T>::value
                          && std::is_constructible<Hash, _networkID_T>::value
                          && std::is_constructible<xdr::xstring<100>, _versionStr_T>::value
                          && std::is_constructible<std::int32_t, _listeningPort_T>::value
                          && std::is_constructible<NodeID, _peerID_T>::value
                          && std::is_constructible<AuthCert, _cert_T>::value
                          && std::is_constructible<uint256, _nonce_T>::value
                         >::type>
  explicit Hello(_ledgerVersion_T &&_ledgerVersion,
                 _overlayVersion_T &&_overlayVersion,
                 _overlayMinVersion_T &&_overlayMinVersion,
                 _networkID_T &&_networkID,
                 _versionStr_T &&_versionStr,
                 _listeningPort_T &&_listeningPort,
                 _peerID_T &&_peerID,
                 _cert_T &&_cert,
                 _nonce_T &&_nonce)
    : ledgerVersion(std::forward<_ledgerVersion_T>(_ledgerVersion)),
      overlayVersion(std::forward<_overlayVersion_T>(_overlayVersion)),
      overlayMinVersion(std::forward<_overlayMinVersion_T>(_overlayMinVersion)),
      networkID(std::forward<_networkID_T>(_networkID)),
      versionStr(std::forward<_versionStr_T>(_versionStr)),
      listeningPort(std::forward<_listeningPort_T>(_listeningPort)),
      peerID(std::forward<_peerID_T>(_peerID)),
      cert(std::forward<_cert_T>(_cert)),
      nonce(std::forward<_nonce_T>(_nonce)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Hello>
  : xdr_struct_base<field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::ledgerVersion),
                              &::stellar::Hello::ledgerVersion>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::overlayVersion),
                              &::stellar::Hello::overlayVersion>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::overlayMinVersion),
                              &::stellar::Hello::overlayMinVersion>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::networkID),
                              &::stellar::Hello::networkID>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::versionStr),
                              &::stellar::Hello::versionStr>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::listeningPort),
                              &::stellar::Hello::listeningPort>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::peerID),
                              &::stellar::Hello::peerID>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::cert),
                              &::stellar::Hello::cert>,
                    field_ptr<::stellar::Hello,
                              decltype(::stellar::Hello::nonce),
                              &::stellar::Hello::nonce>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Hello &obj) {
    archive(ar, obj.ledgerVersion, "ledgerVersion");
    archive(ar, obj.overlayVersion, "overlayVersion");
    archive(ar, obj.overlayMinVersion, "overlayMinVersion");
    archive(ar, obj.networkID, "networkID");
    archive(ar, obj.versionStr, "versionStr");
    archive(ar, obj.listeningPort, "listeningPort");
    archive(ar, obj.peerID, "peerID");
    archive(ar, obj.cert, "cert");
    archive(ar, obj.nonce, "nonce");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Hello &obj) {
    archive(ar, obj.ledgerVersion, "ledgerVersion");
    archive(ar, obj.overlayVersion, "overlayVersion");
    archive(ar, obj.overlayMinVersion, "overlayMinVersion");
    archive(ar, obj.networkID, "networkID");
    archive(ar, obj.versionStr, "versionStr");
    archive(ar, obj.listeningPort, "listeningPort");
    archive(ar, obj.peerID, "peerID");
    archive(ar, obj.cert, "cert");
    archive(ar, obj.nonce, "nonce");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Auth {
  std::int32_t unused{};

  Auth() = default;
  template<typename _unused_T,
           typename = typename
           std::enable_if<std::is_constructible<std::int32_t, _unused_T>::value
                         >::type>
  explicit Auth(_unused_T &&_unused)
    : unused(std::forward<_unused_T>(_unused)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Auth>
  : xdr_struct_base<field_ptr<::stellar::Auth,
                              decltype(::stellar::Auth::unused),
                              &::stellar::Auth::unused>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Auth &obj) {
    archive(ar, obj.unused, "unused");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Auth &obj) {
    archive(ar, obj.unused, "unused");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum IPAddrType : std::int32_t {
  IPv4 = 0,
  IPv6 = 1,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::IPAddrType>
  : xdr_integral_base<::stellar::IPAddrType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::IPAddrType val) {
    switch (val) {
    case ::stellar::IPv4:
      return "IPv4";
    case ::stellar::IPv6:
      return "IPv6";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::IPv4,
      ::stellar::IPv6
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct PeerAddress {
  struct _ip_t {
    using _xdr_case_type = xdr::xdr_traits<IPAddrType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      xdr::opaque_array<4> ipv4_;
      xdr::opaque_array<16> ipv6_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<IPAddrType> &_xdr_case_values() {
      static const std::vector<IPAddrType> _xdr_disc_vec {
        IPv4,
        IPv6
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == IPv4 ? 1
        : which == IPv6 ? 2
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case IPv4:
        _f(&_ip_t::ipv4_, std::forward<_A>(_a)...);
        return true;
      case IPv6:
        _f(&_ip_t::ipv6_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _ip_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_ip_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _ip_t(IPAddrType which = IPAddrType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _ip_t(const _ip_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _ip_t(_ip_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_ip_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _ip_t &operator=(const _ip_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_ip_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _ip_t &operator=(_ip_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_ip_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    IPAddrType type() const { return IPAddrType(type_); }
    _ip_t &type(IPAddrType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    xdr::opaque_array<4> &ipv4() {
      if (_xdr_field_number(type_) == 1)
        return ipv4_;
      throw xdr::xdr_wrong_union("_ip_t: ipv4 accessed when not selected");
    }
    const xdr::opaque_array<4> &ipv4() const {
      if (_xdr_field_number(type_) == 1)
        return ipv4_;
      throw xdr::xdr_wrong_union("_ip_t: ipv4 accessed when not selected");
    }
    xdr::opaque_array<16> &ipv6() {
      if (_xdr_field_number(type_) == 2)
        return ipv6_;
      throw xdr::xdr_wrong_union("_ip_t: ipv6 accessed when not selected");
    }
    const xdr::opaque_array<16> &ipv6() const {
      if (_xdr_field_number(type_) == 2)
        return ipv6_;
      throw xdr::xdr_wrong_union("_ip_t: ipv6 accessed when not selected");
    }
  };

  _ip_t ip{};
  uint32 port{};
  uint32 numFailures{};

  PeerAddress() = default;
  template<typename _ip_T,
           typename _port_T,
           typename _numFailures_T,
           typename = typename
           std::enable_if<std::is_constructible<_ip_t, _ip_T>::value
                          && std::is_constructible<uint32, _port_T>::value
                          && std::is_constructible<uint32, _numFailures_T>::value
                         >::type>
  explicit PeerAddress(_ip_T &&_ip,
                       _port_T &&_port,
                       _numFailures_T &&_numFailures)
    : ip(std::forward<_ip_T>(_ip)),
      port(std::forward<_port_T>(_port)),
      numFailures(std::forward<_numFailures_T>(_numFailures)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PeerAddress::_ip_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::PeerAddress::_ip_t;
  using case_type = ::stellar::PeerAddress::_ip_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "ipv4";
    case 2:
      return "ipv6";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::PeerAddress::_ip_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _ip_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PeerAddress::_ip_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _ip_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PeerAddress::_ip_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::PeerAddress>
  : xdr_struct_base<field_ptr<::stellar::PeerAddress,
                              decltype(::stellar::PeerAddress::ip),
                              &::stellar::PeerAddress::ip>,
                    field_ptr<::stellar::PeerAddress,
                              decltype(::stellar::PeerAddress::port),
                              &::stellar::PeerAddress::port>,
                    field_ptr<::stellar::PeerAddress,
                              decltype(::stellar::PeerAddress::numFailures),
                              &::stellar::PeerAddress::numFailures>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PeerAddress &obj) {
    archive(ar, obj.ip, "ip");
    archive(ar, obj.port, "port");
    archive(ar, obj.numFailures, "numFailures");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PeerAddress &obj) {
    archive(ar, obj.ip, "ip");
    archive(ar, obj.port, "port");
    archive(ar, obj.numFailures, "numFailures");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum MessageType : std::int32_t {
  ERROR_MSG = 0,
  AUTH = 2,
  DONT_HAVE = 3,
  GET_PEERS = 4,
  PEERS = 5,
  GET_TX_SET = 6,
  TX_SET = 7,
  TRANSACTION = 8,
  GET_SCP_QUORUMSET = 9,
  SCP_QUORUMSET = 10,
  SCP_MESSAGE = 11,
  GET_SCP_STATE = 12,
  HELLO = 13,
  SURVEY_REQUEST = 14,
  SURVEY_RESPONSE = 15,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::MessageType>
  : xdr_integral_base<::stellar::MessageType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::MessageType val) {
    switch (val) {
    case ::stellar::ERROR_MSG:
      return "ERROR_MSG";
    case ::stellar::AUTH:
      return "AUTH";
    case ::stellar::DONT_HAVE:
      return "DONT_HAVE";
    case ::stellar::GET_PEERS:
      return "GET_PEERS";
    case ::stellar::PEERS:
      return "PEERS";
    case ::stellar::GET_TX_SET:
      return "GET_TX_SET";
    case ::stellar::TX_SET:
      return "TX_SET";
    case ::stellar::TRANSACTION:
      return "TRANSACTION";
    case ::stellar::GET_SCP_QUORUMSET:
      return "GET_SCP_QUORUMSET";
    case ::stellar::SCP_QUORUMSET:
      return "SCP_QUORUMSET";
    case ::stellar::SCP_MESSAGE:
      return "SCP_MESSAGE";
    case ::stellar::GET_SCP_STATE:
      return "GET_SCP_STATE";
    case ::stellar::HELLO:
      return "HELLO";
    case ::stellar::SURVEY_REQUEST:
      return "SURVEY_REQUEST";
    case ::stellar::SURVEY_RESPONSE:
      return "SURVEY_RESPONSE";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ERROR_MSG,
      ::stellar::AUTH,
      ::stellar::DONT_HAVE,
      ::stellar::GET_PEERS,
      ::stellar::PEERS,
      ::stellar::GET_TX_SET,
      ::stellar::TX_SET,
      ::stellar::TRANSACTION,
      ::stellar::GET_SCP_QUORUMSET,
      ::stellar::SCP_QUORUMSET,
      ::stellar::SCP_MESSAGE,
      ::stellar::GET_SCP_STATE,
      ::stellar::HELLO,
      ::stellar::SURVEY_REQUEST,
      ::stellar::SURVEY_RESPONSE
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct DontHave {
  MessageType type{};
  uint256 reqHash{};

  DontHave() = default;
  template<typename _type_T,
           typename _reqHash_T,
           typename = typename
           std::enable_if<std::is_constructible<MessageType, _type_T>::value
                          && std::is_constructible<uint256, _reqHash_T>::value
                         >::type>
  explicit DontHave(_type_T &&_type,
                    _reqHash_T &&_reqHash)
    : type(std::forward<_type_T>(_type)),
      reqHash(std::forward<_reqHash_T>(_reqHash)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::DontHave>
  : xdr_struct_base<field_ptr<::stellar::DontHave,
                              decltype(::stellar::DontHave::type),
                              &::stellar::DontHave::type>,
                    field_ptr<::stellar::DontHave,
                              decltype(::stellar::DontHave::reqHash),
                              &::stellar::DontHave::reqHash>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::DontHave &obj) {
    archive(ar, obj.type, "type");
    archive(ar, obj.reqHash, "reqHash");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::DontHave &obj) {
    archive(ar, obj.type, "type");
    archive(ar, obj.reqHash, "reqHash");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum SurveyMessageCommandType : std::int32_t {
  SURVEY_TOPOLOGY = 0,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SurveyMessageCommandType>
  : xdr_integral_base<::stellar::SurveyMessageCommandType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::SurveyMessageCommandType val) {
    switch (val) {
    case ::stellar::SURVEY_TOPOLOGY:
      return "SURVEY_TOPOLOGY";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::SURVEY_TOPOLOGY
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct SurveyRequestMessage {
  NodeID surveyorPeerID{};
  NodeID surveyedPeerID{};
  uint32 ledgerNum{};
  Curve25519Public encryptionKey{};
  SurveyMessageCommandType commandType{};

  SurveyRequestMessage() = default;
  template<typename _surveyorPeerID_T,
           typename _surveyedPeerID_T,
           typename _ledgerNum_T,
           typename _encryptionKey_T,
           typename _commandType_T,
           typename = typename
           std::enable_if<std::is_constructible<NodeID, _surveyorPeerID_T>::value
                          && std::is_constructible<NodeID, _surveyedPeerID_T>::value
                          && std::is_constructible<uint32, _ledgerNum_T>::value
                          && std::is_constructible<Curve25519Public, _encryptionKey_T>::value
                          && std::is_constructible<SurveyMessageCommandType, _commandType_T>::value
                         >::type>
  explicit SurveyRequestMessage(_surveyorPeerID_T &&_surveyorPeerID,
                                _surveyedPeerID_T &&_surveyedPeerID,
                                _ledgerNum_T &&_ledgerNum,
                                _encryptionKey_T &&_encryptionKey,
                                _commandType_T &&_commandType)
    : surveyorPeerID(std::forward<_surveyorPeerID_T>(_surveyorPeerID)),
      surveyedPeerID(std::forward<_surveyedPeerID_T>(_surveyedPeerID)),
      ledgerNum(std::forward<_ledgerNum_T>(_ledgerNum)),
      encryptionKey(std::forward<_encryptionKey_T>(_encryptionKey)),
      commandType(std::forward<_commandType_T>(_commandType)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SurveyRequestMessage>
  : xdr_struct_base<field_ptr<::stellar::SurveyRequestMessage,
                              decltype(::stellar::SurveyRequestMessage::surveyorPeerID),
                              &::stellar::SurveyRequestMessage::surveyorPeerID>,
                    field_ptr<::stellar::SurveyRequestMessage,
                              decltype(::stellar::SurveyRequestMessage::surveyedPeerID),
                              &::stellar::SurveyRequestMessage::surveyedPeerID>,
                    field_ptr<::stellar::SurveyRequestMessage,
                              decltype(::stellar::SurveyRequestMessage::ledgerNum),
                              &::stellar::SurveyRequestMessage::ledgerNum>,
                    field_ptr<::stellar::SurveyRequestMessage,
                              decltype(::stellar::SurveyRequestMessage::encryptionKey),
                              &::stellar::SurveyRequestMessage::encryptionKey>,
                    field_ptr<::stellar::SurveyRequestMessage,
                              decltype(::stellar::SurveyRequestMessage::commandType),
                              &::stellar::SurveyRequestMessage::commandType>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SurveyRequestMessage &obj) {
    archive(ar, obj.surveyorPeerID, "surveyorPeerID");
    archive(ar, obj.surveyedPeerID, "surveyedPeerID");
    archive(ar, obj.ledgerNum, "ledgerNum");
    archive(ar, obj.encryptionKey, "encryptionKey");
    archive(ar, obj.commandType, "commandType");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SurveyRequestMessage &obj) {
    archive(ar, obj.surveyorPeerID, "surveyorPeerID");
    archive(ar, obj.surveyedPeerID, "surveyedPeerID");
    archive(ar, obj.ledgerNum, "ledgerNum");
    archive(ar, obj.encryptionKey, "encryptionKey");
    archive(ar, obj.commandType, "commandType");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct SignedSurveyRequestMessage {
  Signature requestSignature{};
  SurveyRequestMessage request{};

  SignedSurveyRequestMessage() = default;
  template<typename _requestSignature_T,
           typename _request_T,
           typename = typename
           std::enable_if<std::is_constructible<Signature, _requestSignature_T>::value
                          && std::is_constructible<SurveyRequestMessage, _request_T>::value
                         >::type>
  explicit SignedSurveyRequestMessage(_requestSignature_T &&_requestSignature,
                                      _request_T &&_request)
    : requestSignature(std::forward<_requestSignature_T>(_requestSignature)),
      request(std::forward<_request_T>(_request)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SignedSurveyRequestMessage>
  : xdr_struct_base<field_ptr<::stellar::SignedSurveyRequestMessage,
                              decltype(::stellar::SignedSurveyRequestMessage::requestSignature),
                              &::stellar::SignedSurveyRequestMessage::requestSignature>,
                    field_ptr<::stellar::SignedSurveyRequestMessage,
                              decltype(::stellar::SignedSurveyRequestMessage::request),
                              &::stellar::SignedSurveyRequestMessage::request>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SignedSurveyRequestMessage &obj) {
    archive(ar, obj.requestSignature, "requestSignature");
    archive(ar, obj.request, "request");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SignedSurveyRequestMessage &obj) {
    archive(ar, obj.requestSignature, "requestSignature");
    archive(ar, obj.request, "request");
    xdr::validate(obj);
  }
};
} namespace stellar {

using EncryptedBody = xdr::opaque_vec<64000>;

struct SurveyResponseMessage {
  NodeID surveyorPeerID{};
  NodeID surveyedPeerID{};
  uint32 ledgerNum{};
  SurveyMessageCommandType commandType{};
  EncryptedBody encryptedBody{};

  SurveyResponseMessage() = default;
  template<typename _surveyorPeerID_T,
           typename _surveyedPeerID_T,
           typename _ledgerNum_T,
           typename _commandType_T,
           typename _encryptedBody_T,
           typename = typename
           std::enable_if<std::is_constructible<NodeID, _surveyorPeerID_T>::value
                          && std::is_constructible<NodeID, _surveyedPeerID_T>::value
                          && std::is_constructible<uint32, _ledgerNum_T>::value
                          && std::is_constructible<SurveyMessageCommandType, _commandType_T>::value
                          && std::is_constructible<EncryptedBody, _encryptedBody_T>::value
                         >::type>
  explicit SurveyResponseMessage(_surveyorPeerID_T &&_surveyorPeerID,
                                 _surveyedPeerID_T &&_surveyedPeerID,
                                 _ledgerNum_T &&_ledgerNum,
                                 _commandType_T &&_commandType,
                                 _encryptedBody_T &&_encryptedBody)
    : surveyorPeerID(std::forward<_surveyorPeerID_T>(_surveyorPeerID)),
      surveyedPeerID(std::forward<_surveyedPeerID_T>(_surveyedPeerID)),
      ledgerNum(std::forward<_ledgerNum_T>(_ledgerNum)),
      commandType(std::forward<_commandType_T>(_commandType)),
      encryptedBody(std::forward<_encryptedBody_T>(_encryptedBody)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SurveyResponseMessage>
  : xdr_struct_base<field_ptr<::stellar::SurveyResponseMessage,
                              decltype(::stellar::SurveyResponseMessage::surveyorPeerID),
                              &::stellar::SurveyResponseMessage::surveyorPeerID>,
                    field_ptr<::stellar::SurveyResponseMessage,
                              decltype(::stellar::SurveyResponseMessage::surveyedPeerID),
                              &::stellar::SurveyResponseMessage::surveyedPeerID>,
                    field_ptr<::stellar::SurveyResponseMessage,
                              decltype(::stellar::SurveyResponseMessage::ledgerNum),
                              &::stellar::SurveyResponseMessage::ledgerNum>,
                    field_ptr<::stellar::SurveyResponseMessage,
                              decltype(::stellar::SurveyResponseMessage::commandType),
                              &::stellar::SurveyResponseMessage::commandType>,
                    field_ptr<::stellar::SurveyResponseMessage,
                              decltype(::stellar::SurveyResponseMessage::encryptedBody),
                              &::stellar::SurveyResponseMessage::encryptedBody>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SurveyResponseMessage &obj) {
    archive(ar, obj.surveyorPeerID, "surveyorPeerID");
    archive(ar, obj.surveyedPeerID, "surveyedPeerID");
    archive(ar, obj.ledgerNum, "ledgerNum");
    archive(ar, obj.commandType, "commandType");
    archive(ar, obj.encryptedBody, "encryptedBody");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SurveyResponseMessage &obj) {
    archive(ar, obj.surveyorPeerID, "surveyorPeerID");
    archive(ar, obj.surveyedPeerID, "surveyedPeerID");
    archive(ar, obj.ledgerNum, "ledgerNum");
    archive(ar, obj.commandType, "commandType");
    archive(ar, obj.encryptedBody, "encryptedBody");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct SignedSurveyResponseMessage {
  Signature responseSignature{};
  SurveyResponseMessage response{};

  SignedSurveyResponseMessage() = default;
  template<typename _responseSignature_T,
           typename _response_T,
           typename = typename
           std::enable_if<std::is_constructible<Signature, _responseSignature_T>::value
                          && std::is_constructible<SurveyResponseMessage, _response_T>::value
                         >::type>
  explicit SignedSurveyResponseMessage(_responseSignature_T &&_responseSignature,
                                       _response_T &&_response)
    : responseSignature(std::forward<_responseSignature_T>(_responseSignature)),
      response(std::forward<_response_T>(_response)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SignedSurveyResponseMessage>
  : xdr_struct_base<field_ptr<::stellar::SignedSurveyResponseMessage,
                              decltype(::stellar::SignedSurveyResponseMessage::responseSignature),
                              &::stellar::SignedSurveyResponseMessage::responseSignature>,
                    field_ptr<::stellar::SignedSurveyResponseMessage,
                              decltype(::stellar::SignedSurveyResponseMessage::response),
                              &::stellar::SignedSurveyResponseMessage::response>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SignedSurveyResponseMessage &obj) {
    archive(ar, obj.responseSignature, "responseSignature");
    archive(ar, obj.response, "response");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SignedSurveyResponseMessage &obj) {
    archive(ar, obj.responseSignature, "responseSignature");
    archive(ar, obj.response, "response");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct PeerStats {
  NodeID id{};
  xdr::xstring<100> versionStr{};
  uint64 messagesRead{};
  uint64 messagesWritten{};
  uint64 bytesRead{};
  uint64 bytesWritten{};
  uint64 secondsConnected{};
  uint64 uniqueFloodBytesRecv{};
  uint64 duplicateFloodBytesRecv{};
  uint64 uniqueFetchBytesRecv{};
  uint64 duplicateFetchBytesRecv{};
  uint64 uniqueFloodMessageRecv{};
  uint64 duplicateFloodMessageRecv{};
  uint64 uniqueFetchMessageRecv{};
  uint64 duplicateFetchMessageRecv{};

  PeerStats() = default;
  template<typename _id_T,
           typename _versionStr_T,
           typename _messagesRead_T,
           typename _messagesWritten_T,
           typename _bytesRead_T,
           typename _bytesWritten_T,
           typename _secondsConnected_T,
           typename _uniqueFloodBytesRecv_T,
           typename _duplicateFloodBytesRecv_T,
           typename _uniqueFetchBytesRecv_T,
           typename _duplicateFetchBytesRecv_T,
           typename _uniqueFloodMessageRecv_T,
           typename _duplicateFloodMessageRecv_T,
           typename _uniqueFetchMessageRecv_T,
           typename _duplicateFetchMessageRecv_T,
           typename = typename
           std::enable_if<std::is_constructible<NodeID, _id_T>::value
                          && std::is_constructible<xdr::xstring<100>, _versionStr_T>::value
                          && std::is_constructible<uint64, _messagesRead_T>::value
                          && std::is_constructible<uint64, _messagesWritten_T>::value
                          && std::is_constructible<uint64, _bytesRead_T>::value
                          && std::is_constructible<uint64, _bytesWritten_T>::value
                          && std::is_constructible<uint64, _secondsConnected_T>::value
                          && std::is_constructible<uint64, _uniqueFloodBytesRecv_T>::value
                          && std::is_constructible<uint64, _duplicateFloodBytesRecv_T>::value
                          && std::is_constructible<uint64, _uniqueFetchBytesRecv_T>::value
                          && std::is_constructible<uint64, _duplicateFetchBytesRecv_T>::value
                          && std::is_constructible<uint64, _uniqueFloodMessageRecv_T>::value
                          && std::is_constructible<uint64, _duplicateFloodMessageRecv_T>::value
                          && std::is_constructible<uint64, _uniqueFetchMessageRecv_T>::value
                          && std::is_constructible<uint64, _duplicateFetchMessageRecv_T>::value
                         >::type>
  explicit PeerStats(_id_T &&_id,
                     _versionStr_T &&_versionStr,
                     _messagesRead_T &&_messagesRead,
                     _messagesWritten_T &&_messagesWritten,
                     _bytesRead_T &&_bytesRead,
                     _bytesWritten_T &&_bytesWritten,
                     _secondsConnected_T &&_secondsConnected,
                     _uniqueFloodBytesRecv_T &&_uniqueFloodBytesRecv,
                     _duplicateFloodBytesRecv_T &&_duplicateFloodBytesRecv,
                     _uniqueFetchBytesRecv_T &&_uniqueFetchBytesRecv,
                     _duplicateFetchBytesRecv_T &&_duplicateFetchBytesRecv,
                     _uniqueFloodMessageRecv_T &&_uniqueFloodMessageRecv,
                     _duplicateFloodMessageRecv_T &&_duplicateFloodMessageRecv,
                     _uniqueFetchMessageRecv_T &&_uniqueFetchMessageRecv,
                     _duplicateFetchMessageRecv_T &&_duplicateFetchMessageRecv)
    : id(std::forward<_id_T>(_id)),
      versionStr(std::forward<_versionStr_T>(_versionStr)),
      messagesRead(std::forward<_messagesRead_T>(_messagesRead)),
      messagesWritten(std::forward<_messagesWritten_T>(_messagesWritten)),
      bytesRead(std::forward<_bytesRead_T>(_bytesRead)),
      bytesWritten(std::forward<_bytesWritten_T>(_bytesWritten)),
      secondsConnected(std::forward<_secondsConnected_T>(_secondsConnected)),
      uniqueFloodBytesRecv(std::forward<_uniqueFloodBytesRecv_T>(_uniqueFloodBytesRecv)),
      duplicateFloodBytesRecv(std::forward<_duplicateFloodBytesRecv_T>(_duplicateFloodBytesRecv)),
      uniqueFetchBytesRecv(std::forward<_uniqueFetchBytesRecv_T>(_uniqueFetchBytesRecv)),
      duplicateFetchBytesRecv(std::forward<_duplicateFetchBytesRecv_T>(_duplicateFetchBytesRecv)),
      uniqueFloodMessageRecv(std::forward<_uniqueFloodMessageRecv_T>(_uniqueFloodMessageRecv)),
      duplicateFloodMessageRecv(std::forward<_duplicateFloodMessageRecv_T>(_duplicateFloodMessageRecv)),
      uniqueFetchMessageRecv(std::forward<_uniqueFetchMessageRecv_T>(_uniqueFetchMessageRecv)),
      duplicateFetchMessageRecv(std::forward<_duplicateFetchMessageRecv_T>(_duplicateFetchMessageRecv)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PeerStats>
  : xdr_struct_base<field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::id),
                              &::stellar::PeerStats::id>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::versionStr),
                              &::stellar::PeerStats::versionStr>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::messagesRead),
                              &::stellar::PeerStats::messagesRead>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::messagesWritten),
                              &::stellar::PeerStats::messagesWritten>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::bytesRead),
                              &::stellar::PeerStats::bytesRead>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::bytesWritten),
                              &::stellar::PeerStats::bytesWritten>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::secondsConnected),
                              &::stellar::PeerStats::secondsConnected>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::uniqueFloodBytesRecv),
                              &::stellar::PeerStats::uniqueFloodBytesRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::duplicateFloodBytesRecv),
                              &::stellar::PeerStats::duplicateFloodBytesRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::uniqueFetchBytesRecv),
                              &::stellar::PeerStats::uniqueFetchBytesRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::duplicateFetchBytesRecv),
                              &::stellar::PeerStats::duplicateFetchBytesRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::uniqueFloodMessageRecv),
                              &::stellar::PeerStats::uniqueFloodMessageRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::duplicateFloodMessageRecv),
                              &::stellar::PeerStats::duplicateFloodMessageRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::uniqueFetchMessageRecv),
                              &::stellar::PeerStats::uniqueFetchMessageRecv>,
                    field_ptr<::stellar::PeerStats,
                              decltype(::stellar::PeerStats::duplicateFetchMessageRecv),
                              &::stellar::PeerStats::duplicateFetchMessageRecv>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PeerStats &obj) {
    archive(ar, obj.id, "id");
    archive(ar, obj.versionStr, "versionStr");
    archive(ar, obj.messagesRead, "messagesRead");
    archive(ar, obj.messagesWritten, "messagesWritten");
    archive(ar, obj.bytesRead, "bytesRead");
    archive(ar, obj.bytesWritten, "bytesWritten");
    archive(ar, obj.secondsConnected, "secondsConnected");
    archive(ar, obj.uniqueFloodBytesRecv, "uniqueFloodBytesRecv");
    archive(ar, obj.duplicateFloodBytesRecv, "duplicateFloodBytesRecv");
    archive(ar, obj.uniqueFetchBytesRecv, "uniqueFetchBytesRecv");
    archive(ar, obj.duplicateFetchBytesRecv, "duplicateFetchBytesRecv");
    archive(ar, obj.uniqueFloodMessageRecv, "uniqueFloodMessageRecv");
    archive(ar, obj.duplicateFloodMessageRecv, "duplicateFloodMessageRecv");
    archive(ar, obj.uniqueFetchMessageRecv, "uniqueFetchMessageRecv");
    archive(ar, obj.duplicateFetchMessageRecv, "duplicateFetchMessageRecv");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PeerStats &obj) {
    archive(ar, obj.id, "id");
    archive(ar, obj.versionStr, "versionStr");
    archive(ar, obj.messagesRead, "messagesRead");
    archive(ar, obj.messagesWritten, "messagesWritten");
    archive(ar, obj.bytesRead, "bytesRead");
    archive(ar, obj.bytesWritten, "bytesWritten");
    archive(ar, obj.secondsConnected, "secondsConnected");
    archive(ar, obj.uniqueFloodBytesRecv, "uniqueFloodBytesRecv");
    archive(ar, obj.duplicateFloodBytesRecv, "duplicateFloodBytesRecv");
    archive(ar, obj.uniqueFetchBytesRecv, "uniqueFetchBytesRecv");
    archive(ar, obj.duplicateFetchBytesRecv, "duplicateFetchBytesRecv");
    archive(ar, obj.uniqueFloodMessageRecv, "uniqueFloodMessageRecv");
    archive(ar, obj.duplicateFloodMessageRecv, "duplicateFloodMessageRecv");
    archive(ar, obj.uniqueFetchMessageRecv, "uniqueFetchMessageRecv");
    archive(ar, obj.duplicateFetchMessageRecv, "duplicateFetchMessageRecv");
    xdr::validate(obj);
  }
};
} namespace stellar {

using PeerStatList = xdr::xvector<PeerStats,25>;

struct TopologyResponseBody {
  PeerStatList inboundPeers{};
  PeerStatList outboundPeers{};
  uint32 totalInboundPeerCount{};
  uint32 totalOutboundPeerCount{};

  TopologyResponseBody() = default;
  template<typename _inboundPeers_T,
           typename _outboundPeers_T,
           typename _totalInboundPeerCount_T,
           typename _totalOutboundPeerCount_T,
           typename = typename
           std::enable_if<std::is_constructible<PeerStatList, _inboundPeers_T>::value
                          && std::is_constructible<PeerStatList, _outboundPeers_T>::value
                          && std::is_constructible<uint32, _totalInboundPeerCount_T>::value
                          && std::is_constructible<uint32, _totalOutboundPeerCount_T>::value
                         >::type>
  explicit TopologyResponseBody(_inboundPeers_T &&_inboundPeers,
                                _outboundPeers_T &&_outboundPeers,
                                _totalInboundPeerCount_T &&_totalInboundPeerCount,
                                _totalOutboundPeerCount_T &&_totalOutboundPeerCount)
    : inboundPeers(std::forward<_inboundPeers_T>(_inboundPeers)),
      outboundPeers(std::forward<_outboundPeers_T>(_outboundPeers)),
      totalInboundPeerCount(std::forward<_totalInboundPeerCount_T>(_totalInboundPeerCount)),
      totalOutboundPeerCount(std::forward<_totalOutboundPeerCount_T>(_totalOutboundPeerCount)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TopologyResponseBody>
  : xdr_struct_base<field_ptr<::stellar::TopologyResponseBody,
                              decltype(::stellar::TopologyResponseBody::inboundPeers),
                              &::stellar::TopologyResponseBody::inboundPeers>,
                    field_ptr<::stellar::TopologyResponseBody,
                              decltype(::stellar::TopologyResponseBody::outboundPeers),
                              &::stellar::TopologyResponseBody::outboundPeers>,
                    field_ptr<::stellar::TopologyResponseBody,
                              decltype(::stellar::TopologyResponseBody::totalInboundPeerCount),
                              &::stellar::TopologyResponseBody::totalInboundPeerCount>,
                    field_ptr<::stellar::TopologyResponseBody,
                              decltype(::stellar::TopologyResponseBody::totalOutboundPeerCount),
                              &::stellar::TopologyResponseBody::totalOutboundPeerCount>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TopologyResponseBody &obj) {
    archive(ar, obj.inboundPeers, "inboundPeers");
    archive(ar, obj.outboundPeers, "outboundPeers");
    archive(ar, obj.totalInboundPeerCount, "totalInboundPeerCount");
    archive(ar, obj.totalOutboundPeerCount, "totalOutboundPeerCount");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TopologyResponseBody &obj) {
    archive(ar, obj.inboundPeers, "inboundPeers");
    archive(ar, obj.outboundPeers, "outboundPeers");
    archive(ar, obj.totalInboundPeerCount, "totalInboundPeerCount");
    archive(ar, obj.totalOutboundPeerCount, "totalOutboundPeerCount");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct SurveyResponseBody {
  using _xdr_case_type = xdr::xdr_traits<SurveyMessageCommandType>::case_type;
private:
  _xdr_case_type type_;
  union {
    TopologyResponseBody topologyResponseBody_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<SurveyMessageCommandType> &_xdr_case_values() {
    static const std::vector<SurveyMessageCommandType> _xdr_disc_vec {
      SURVEY_TOPOLOGY
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == SURVEY_TOPOLOGY ? 1
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case SURVEY_TOPOLOGY:
      _f(&SurveyResponseBody::topologyResponseBody_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in SurveyResponseBody");
    if (fnum != _xdr_field_number(type_)) {
      this->~SurveyResponseBody();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit SurveyResponseBody(SurveyMessageCommandType which = SurveyMessageCommandType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  SurveyResponseBody(const SurveyResponseBody &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  SurveyResponseBody(SurveyResponseBody &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~SurveyResponseBody() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  SurveyResponseBody &operator=(const SurveyResponseBody &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~SurveyResponseBody();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  SurveyResponseBody &operator=(SurveyResponseBody &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~SurveyResponseBody();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  SurveyMessageCommandType type() const { return SurveyMessageCommandType(type_); }
  SurveyResponseBody &type(SurveyMessageCommandType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  TopologyResponseBody &topologyResponseBody() {
    if (_xdr_field_number(type_) == 1)
      return topologyResponseBody_;
    throw xdr::xdr_wrong_union("SurveyResponseBody: topologyResponseBody accessed when not selected");
  }
  const TopologyResponseBody &topologyResponseBody() const {
    if (_xdr_field_number(type_) == 1)
      return topologyResponseBody_;
    throw xdr::xdr_wrong_union("SurveyResponseBody: topologyResponseBody accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SurveyResponseBody> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::SurveyResponseBody;
  using case_type = ::stellar::SurveyResponseBody::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "topologyResponseBody";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::SurveyResponseBody &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in SurveyResponseBody");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SurveyResponseBody &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in SurveyResponseBody");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SurveyResponseBody &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct StellarMessage {
  using _xdr_case_type = xdr::xdr_traits<MessageType>::case_type;
private:
  _xdr_case_type type_;
  union {
    Error error_;
    Hello hello_;
    Auth auth_;
    DontHave dontHave_;
    xdr::xvector<PeerAddress,100> peers_;
    uint256 txSetHash_;
    TransactionSet txSet_;
    TransactionEnvelope transaction_;
    SignedSurveyRequestMessage signedSurveyRequestMessage_;
    SignedSurveyResponseMessage signedSurveyResponseMessage_;
    uint256 qSetHash_;
    SCPQuorumSet qSet_;
    SCPEnvelope envelope_;
    uint32 getSCPLedgerSeq_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<MessageType> &_xdr_case_values() {
    static const std::vector<MessageType> _xdr_disc_vec {
      ERROR_MSG,
      HELLO,
      AUTH,
      DONT_HAVE,
      GET_PEERS,
      PEERS,
      GET_TX_SET,
      TX_SET,
      TRANSACTION,
      SURVEY_REQUEST,
      SURVEY_RESPONSE,
      GET_SCP_QUORUMSET,
      SCP_QUORUMSET,
      SCP_MESSAGE,
      GET_SCP_STATE
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ERROR_MSG ? 1
      : which == HELLO ? 2
      : which == AUTH ? 3
      : which == DONT_HAVE ? 4
      : which == GET_PEERS ? 0
      : which == PEERS ? 5
      : which == GET_TX_SET ? 6
      : which == TX_SET ? 7
      : which == TRANSACTION ? 8
      : which == SURVEY_REQUEST ? 9
      : which == SURVEY_RESPONSE ? 10
      : which == GET_SCP_QUORUMSET ? 11
      : which == SCP_QUORUMSET ? 12
      : which == SCP_MESSAGE ? 13
      : which == GET_SCP_STATE ? 14
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ERROR_MSG:
      _f(&StellarMessage::error_, std::forward<_A>(_a)...);
      return true;
    case HELLO:
      _f(&StellarMessage::hello_, std::forward<_A>(_a)...);
      return true;
    case AUTH:
      _f(&StellarMessage::auth_, std::forward<_A>(_a)...);
      return true;
    case DONT_HAVE:
      _f(&StellarMessage::dontHave_, std::forward<_A>(_a)...);
      return true;
    case GET_PEERS:
      return true;
    case PEERS:
      _f(&StellarMessage::peers_, std::forward<_A>(_a)...);
      return true;
    case GET_TX_SET:
      _f(&StellarMessage::txSetHash_, std::forward<_A>(_a)...);
      return true;
    case TX_SET:
      _f(&StellarMessage::txSet_, std::forward<_A>(_a)...);
      return true;
    case TRANSACTION:
      _f(&StellarMessage::transaction_, std::forward<_A>(_a)...);
      return true;
    case SURVEY_REQUEST:
      _f(&StellarMessage::signedSurveyRequestMessage_, std::forward<_A>(_a)...);
      return true;
    case SURVEY_RESPONSE:
      _f(&StellarMessage::signedSurveyResponseMessage_, std::forward<_A>(_a)...);
      return true;
    case GET_SCP_QUORUMSET:
      _f(&StellarMessage::qSetHash_, std::forward<_A>(_a)...);
      return true;
    case SCP_QUORUMSET:
      _f(&StellarMessage::qSet_, std::forward<_A>(_a)...);
      return true;
    case SCP_MESSAGE:
      _f(&StellarMessage::envelope_, std::forward<_A>(_a)...);
      return true;
    case GET_SCP_STATE:
      _f(&StellarMessage::getSCPLedgerSeq_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in StellarMessage");
    if (fnum != _xdr_field_number(type_)) {
      this->~StellarMessage();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit StellarMessage(MessageType which = MessageType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  StellarMessage(const StellarMessage &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  StellarMessage(StellarMessage &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~StellarMessage() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  StellarMessage &operator=(const StellarMessage &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~StellarMessage();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  StellarMessage &operator=(StellarMessage &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~StellarMessage();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  MessageType type() const { return MessageType(type_); }
  StellarMessage &type(MessageType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  Error &error() {
    if (_xdr_field_number(type_) == 1)
      return error_;
    throw xdr::xdr_wrong_union("StellarMessage: error accessed when not selected");
  }
  const Error &error() const {
    if (_xdr_field_number(type_) == 1)
      return error_;
    throw xdr::xdr_wrong_union("StellarMessage: error accessed when not selected");
  }
  Hello &hello() {
    if (_xdr_field_number(type_) == 2)
      return hello_;
    throw xdr::xdr_wrong_union("StellarMessage: hello accessed when not selected");
  }
  const Hello &hello() const {
    if (_xdr_field_number(type_) == 2)
      return hello_;
    throw xdr::xdr_wrong_union("StellarMessage: hello accessed when not selected");
  }
  Auth &auth() {
    if (_xdr_field_number(type_) == 3)
      return auth_;
    throw xdr::xdr_wrong_union("StellarMessage: auth accessed when not selected");
  }
  const Auth &auth() const {
    if (_xdr_field_number(type_) == 3)
      return auth_;
    throw xdr::xdr_wrong_union("StellarMessage: auth accessed when not selected");
  }
  DontHave &dontHave() {
    if (_xdr_field_number(type_) == 4)
      return dontHave_;
    throw xdr::xdr_wrong_union("StellarMessage: dontHave accessed when not selected");
  }
  const DontHave &dontHave() const {
    if (_xdr_field_number(type_) == 4)
      return dontHave_;
    throw xdr::xdr_wrong_union("StellarMessage: dontHave accessed when not selected");
  }
  xdr::xvector<PeerAddress,100> &peers() {
    if (_xdr_field_number(type_) == 5)
      return peers_;
    throw xdr::xdr_wrong_union("StellarMessage: peers accessed when not selected");
  }
  const xdr::xvector<PeerAddress,100> &peers() const {
    if (_xdr_field_number(type_) == 5)
      return peers_;
    throw xdr::xdr_wrong_union("StellarMessage: peers accessed when not selected");
  }
  uint256 &txSetHash() {
    if (_xdr_field_number(type_) == 6)
      return txSetHash_;
    throw xdr::xdr_wrong_union("StellarMessage: txSetHash accessed when not selected");
  }
  const uint256 &txSetHash() const {
    if (_xdr_field_number(type_) == 6)
      return txSetHash_;
    throw xdr::xdr_wrong_union("StellarMessage: txSetHash accessed when not selected");
  }
  TransactionSet &txSet() {
    if (_xdr_field_number(type_) == 7)
      return txSet_;
    throw xdr::xdr_wrong_union("StellarMessage: txSet accessed when not selected");
  }
  const TransactionSet &txSet() const {
    if (_xdr_field_number(type_) == 7)
      return txSet_;
    throw xdr::xdr_wrong_union("StellarMessage: txSet accessed when not selected");
  }
  TransactionEnvelope &transaction() {
    if (_xdr_field_number(type_) == 8)
      return transaction_;
    throw xdr::xdr_wrong_union("StellarMessage: transaction accessed when not selected");
  }
  const TransactionEnvelope &transaction() const {
    if (_xdr_field_number(type_) == 8)
      return transaction_;
    throw xdr::xdr_wrong_union("StellarMessage: transaction accessed when not selected");
  }
  SignedSurveyRequestMessage &signedSurveyRequestMessage() {
    if (_xdr_field_number(type_) == 9)
      return signedSurveyRequestMessage_;
    throw xdr::xdr_wrong_union("StellarMessage: signedSurveyRequestMessage accessed when not selected");
  }
  const SignedSurveyRequestMessage &signedSurveyRequestMessage() const {
    if (_xdr_field_number(type_) == 9)
      return signedSurveyRequestMessage_;
    throw xdr::xdr_wrong_union("StellarMessage: signedSurveyRequestMessage accessed when not selected");
  }
  SignedSurveyResponseMessage &signedSurveyResponseMessage() {
    if (_xdr_field_number(type_) == 10)
      return signedSurveyResponseMessage_;
    throw xdr::xdr_wrong_union("StellarMessage: signedSurveyResponseMessage accessed when not selected");
  }
  const SignedSurveyResponseMessage &signedSurveyResponseMessage() const {
    if (_xdr_field_number(type_) == 10)
      return signedSurveyResponseMessage_;
    throw xdr::xdr_wrong_union("StellarMessage: signedSurveyResponseMessage accessed when not selected");
  }
  uint256 &qSetHash() {
    if (_xdr_field_number(type_) == 11)
      return qSetHash_;
    throw xdr::xdr_wrong_union("StellarMessage: qSetHash accessed when not selected");
  }
  const uint256 &qSetHash() const {
    if (_xdr_field_number(type_) == 11)
      return qSetHash_;
    throw xdr::xdr_wrong_union("StellarMessage: qSetHash accessed when not selected");
  }
  SCPQuorumSet &qSet() {
    if (_xdr_field_number(type_) == 12)
      return qSet_;
    throw xdr::xdr_wrong_union("StellarMessage: qSet accessed when not selected");
  }
  const SCPQuorumSet &qSet() const {
    if (_xdr_field_number(type_) == 12)
      return qSet_;
    throw xdr::xdr_wrong_union("StellarMessage: qSet accessed when not selected");
  }
  SCPEnvelope &envelope() {
    if (_xdr_field_number(type_) == 13)
      return envelope_;
    throw xdr::xdr_wrong_union("StellarMessage: envelope accessed when not selected");
  }
  const SCPEnvelope &envelope() const {
    if (_xdr_field_number(type_) == 13)
      return envelope_;
    throw xdr::xdr_wrong_union("StellarMessage: envelope accessed when not selected");
  }
  uint32 &getSCPLedgerSeq() {
    if (_xdr_field_number(type_) == 14)
      return getSCPLedgerSeq_;
    throw xdr::xdr_wrong_union("StellarMessage: getSCPLedgerSeq accessed when not selected");
  }
  const uint32 &getSCPLedgerSeq() const {
    if (_xdr_field_number(type_) == 14)
      return getSCPLedgerSeq_;
    throw xdr::xdr_wrong_union("StellarMessage: getSCPLedgerSeq accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::StellarMessage> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::StellarMessage;
  using case_type = ::stellar::StellarMessage::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "error";
    case 2:
      return "hello";
    case 3:
      return "auth";
    case 4:
      return "dontHave";
    case 5:
      return "peers";
    case 6:
      return "txSetHash";
    case 7:
      return "txSet";
    case 8:
      return "transaction";
    case 9:
      return "signedSurveyRequestMessage";
    case 10:
      return "signedSurveyResponseMessage";
    case 11:
      return "qSetHash";
    case 12:
      return "qSet";
    case 13:
      return "envelope";
    case 14:
      return "getSCPLedgerSeq";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::StellarMessage &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in StellarMessage");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::StellarMessage &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in StellarMessage");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::StellarMessage &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AuthenticatedMessage {
  struct _v0_t {
    uint64 sequence{};
    StellarMessage message{};
    HmacSha256Mac mac{};

    _v0_t() = default;
    template<typename _sequence_T,
             typename _message_T,
             typename _mac_T,
             typename = typename
             std::enable_if<std::is_constructible<uint64, _sequence_T>::value
                            && std::is_constructible<StellarMessage, _message_T>::value
                            && std::is_constructible<HmacSha256Mac, _mac_T>::value
                           >::type>
    explicit _v0_t(_sequence_T &&_sequence,
                   _message_T &&_message,
                   _mac_T &&_mac)
      : sequence(std::forward<_sequence_T>(_sequence)),
        message(std::forward<_message_T>(_message)),
        mac(std::forward<_mac_T>(_mac)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<uint32>::case_type;
private:
  _xdr_case_type v_;
  union {
    _v0_t v0_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<uint32> &_xdr_case_values() {
    static const std::vector<uint32> _xdr_disc_vec {
      0
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == 0 ? 1
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case 0:
      _f(&AuthenticatedMessage::v0_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return v_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of v in AuthenticatedMessage");
    if (fnum != _xdr_field_number(v_)) {
      this->~AuthenticatedMessage();
      v_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    else
      v_ = which;
  }
  explicit AuthenticatedMessage(uint32 which = uint32{}) : v_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
  }
  AuthenticatedMessage(const AuthenticatedMessage &source) : v_(source.v_) {
    _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
  }
  AuthenticatedMessage(AuthenticatedMessage &&source) : v_(source.v_) {
    _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                      std::move(source));
  }
  ~AuthenticatedMessage() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
  AuthenticatedMessage &operator=(const AuthenticatedMessage &source) {
    if (_xdr_field_number(v_)
        == _xdr_field_number(source.v_))
      _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
    else {
      this->~AuthenticatedMessage();
      v_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
    }
    v_ = source.v_;
    return *this;
  }
  AuthenticatedMessage &operator=(AuthenticatedMessage &&source) {
    if (_xdr_field_number(v_)
         == _xdr_field_number(source.v_))
      _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                        std::move(source));
    else {
      this->~AuthenticatedMessage();
      v_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                        std::move(source));
    }
    v_ = source.v_;
    return *this;
  }

  uint32 v() const { return uint32(v_); }
  AuthenticatedMessage &v(uint32 _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _v0_t &v0() {
    if (_xdr_field_number(v_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("AuthenticatedMessage: v0 accessed when not selected");
  }
  const _v0_t &v0() const {
    if (_xdr_field_number(v_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("AuthenticatedMessage: v0 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AuthenticatedMessage::_v0_t>
  : xdr_struct_base<field_ptr<::stellar::AuthenticatedMessage::_v0_t,
                              decltype(::stellar::AuthenticatedMessage::_v0_t::sequence),
                              &::stellar::AuthenticatedMessage::_v0_t::sequence>,
                    field_ptr<::stellar::AuthenticatedMessage::_v0_t,
                              decltype(::stellar::AuthenticatedMessage::_v0_t::message),
                              &::stellar::AuthenticatedMessage::_v0_t::message>,
                    field_ptr<::stellar::AuthenticatedMessage::_v0_t,
                              decltype(::stellar::AuthenticatedMessage::_v0_t::mac),
                              &::stellar::AuthenticatedMessage::_v0_t::mac>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AuthenticatedMessage::_v0_t &obj) {
    archive(ar, obj.sequence, "sequence");
    archive(ar, obj.message, "message");
    archive(ar, obj.mac, "mac");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AuthenticatedMessage::_v0_t &obj) {
    archive(ar, obj.sequence, "sequence");
    archive(ar, obj.message, "message");
    archive(ar, obj.mac, "mac");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AuthenticatedMessage> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AuthenticatedMessage;
  using case_type = ::stellar::AuthenticatedMessage::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v0";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AuthenticatedMessage &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in AuthenticatedMessage");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AuthenticatedMessage &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in AuthenticatedMessage");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AuthenticatedMessage &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

}

#endif // !__XDR_SRC_GENERATED_XDR_STELLAR_OVERLAY_H_INCLUDED__
