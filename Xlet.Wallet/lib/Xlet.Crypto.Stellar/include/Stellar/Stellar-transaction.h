// -*- C++ -*-
// Automatically generated from ../../src/xdr/Stellar-transaction.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_SRC_GENERATED_XDR_STELLAR_TRANSACTION_H_INCLUDED__
#define __XDR_SRC_GENERATED_XDR_STELLAR_TRANSACTION_H_INCLUDED__ 1

#include <xdrpp/types.h>

#include "Stellar-ledger-entries.h"

namespace stellar {

struct MuxedAccount {
  struct _med25519_t {
    uint64 id{};
    uint256 ed25519{};

    _med25519_t() = default;
    template<typename _id_T,
             typename _ed25519_T,
             typename = typename
             std::enable_if<std::is_constructible<uint64, _id_T>::value
                            && std::is_constructible<uint256, _ed25519_T>::value
                           >::type>
    explicit _med25519_t(_id_T &&_id,
                         _ed25519_T &&_ed25519)
      : id(std::forward<_id_T>(_id)),
        ed25519(std::forward<_ed25519_T>(_ed25519)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<CryptoKeyType>::case_type;
private:
  _xdr_case_type type_;
  union {
    uint256 ed25519_;
    _med25519_t med25519_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<CryptoKeyType> &_xdr_case_values() {
    static const std::vector<CryptoKeyType> _xdr_disc_vec {
      KEY_TYPE_ED25519,
      KEY_TYPE_MUXED_ED25519
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == KEY_TYPE_ED25519 ? 1
      : which == KEY_TYPE_MUXED_ED25519 ? 2
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case KEY_TYPE_ED25519:
      _f(&MuxedAccount::ed25519_, std::forward<_A>(_a)...);
      return true;
    case KEY_TYPE_MUXED_ED25519:
      _f(&MuxedAccount::med25519_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in MuxedAccount");
    if (fnum != _xdr_field_number(type_)) {
      this->~MuxedAccount();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit MuxedAccount(CryptoKeyType which = CryptoKeyType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  MuxedAccount(const MuxedAccount &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  MuxedAccount(MuxedAccount &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~MuxedAccount() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  MuxedAccount &operator=(const MuxedAccount &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~MuxedAccount();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  MuxedAccount &operator=(MuxedAccount &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~MuxedAccount();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  CryptoKeyType type() const { return CryptoKeyType(type_); }
  MuxedAccount &type(CryptoKeyType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  uint256 &ed25519() {
    if (_xdr_field_number(type_) == 1)
      return ed25519_;
    throw xdr::xdr_wrong_union("MuxedAccount: ed25519 accessed when not selected");
  }
  const uint256 &ed25519() const {
    if (_xdr_field_number(type_) == 1)
      return ed25519_;
    throw xdr::xdr_wrong_union("MuxedAccount: ed25519 accessed when not selected");
  }
  _med25519_t &med25519() {
    if (_xdr_field_number(type_) == 2)
      return med25519_;
    throw xdr::xdr_wrong_union("MuxedAccount: med25519 accessed when not selected");
  }
  const _med25519_t &med25519() const {
    if (_xdr_field_number(type_) == 2)
      return med25519_;
    throw xdr::xdr_wrong_union("MuxedAccount: med25519 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::MuxedAccount::_med25519_t>
  : xdr_struct_base<field_ptr<::stellar::MuxedAccount::_med25519_t,
                              decltype(::stellar::MuxedAccount::_med25519_t::id),
                              &::stellar::MuxedAccount::_med25519_t::id>,
                    field_ptr<::stellar::MuxedAccount::_med25519_t,
                              decltype(::stellar::MuxedAccount::_med25519_t::ed25519),
                              &::stellar::MuxedAccount::_med25519_t::ed25519>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::MuxedAccount::_med25519_t &obj) {
    archive(ar, obj.id, "id");
    archive(ar, obj.ed25519, "ed25519");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::MuxedAccount::_med25519_t &obj) {
    archive(ar, obj.id, "id");
    archive(ar, obj.ed25519, "ed25519");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::MuxedAccount> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::MuxedAccount;
  using case_type = ::stellar::MuxedAccount::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "ed25519";
    case 2:
      return "med25519";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::MuxedAccount &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in MuxedAccount");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::MuxedAccount &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in MuxedAccount");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::MuxedAccount &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct DecoratedSignature {
  SignatureHint hint{};
  Signature signature{};

  DecoratedSignature() = default;
  template<typename _hint_T,
           typename _signature_T,
           typename = typename
           std::enable_if<std::is_constructible<SignatureHint, _hint_T>::value
                          && std::is_constructible<Signature, _signature_T>::value
                         >::type>
  explicit DecoratedSignature(_hint_T &&_hint,
                              _signature_T &&_signature)
    : hint(std::forward<_hint_T>(_hint)),
      signature(std::forward<_signature_T>(_signature)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::DecoratedSignature>
  : xdr_struct_base<field_ptr<::stellar::DecoratedSignature,
                              decltype(::stellar::DecoratedSignature::hint),
                              &::stellar::DecoratedSignature::hint>,
                    field_ptr<::stellar::DecoratedSignature,
                              decltype(::stellar::DecoratedSignature::signature),
                              &::stellar::DecoratedSignature::signature>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::DecoratedSignature &obj) {
    archive(ar, obj.hint, "hint");
    archive(ar, obj.signature, "signature");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::DecoratedSignature &obj) {
    archive(ar, obj.hint, "hint");
    archive(ar, obj.signature, "signature");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum OperationType : std::int32_t {
  CREATE_ACCOUNT = 0,
  PAYMENT = 1,
  PATH_PAYMENT_STRICT_RECEIVE = 2,
  MANAGE_SELL_OFFER = 3,
  CREATE_PASSIVE_SELL_OFFER = 4,
  SET_OPTIONS = 5,
  CHANGE_TRUST = 6,
  ALLOW_TRUST = 7,
  ACCOUNT_MERGE = 8,
  INFLATION = 9,
  MANAGE_DATA = 10,
  BUMP_SEQUENCE = 11,
  MANAGE_BUY_OFFER = 12,
  PATH_PAYMENT_STRICT_SEND = 13,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OperationType>
  : xdr_integral_base<::stellar::OperationType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::OperationType val) {
    switch (val) {
    case ::stellar::CREATE_ACCOUNT:
      return "CREATE_ACCOUNT";
    case ::stellar::PAYMENT:
      return "PAYMENT";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE:
      return "PATH_PAYMENT_STRICT_RECEIVE";
    case ::stellar::MANAGE_SELL_OFFER:
      return "MANAGE_SELL_OFFER";
    case ::stellar::CREATE_PASSIVE_SELL_OFFER:
      return "CREATE_PASSIVE_SELL_OFFER";
    case ::stellar::SET_OPTIONS:
      return "SET_OPTIONS";
    case ::stellar::CHANGE_TRUST:
      return "CHANGE_TRUST";
    case ::stellar::ALLOW_TRUST:
      return "ALLOW_TRUST";
    case ::stellar::ACCOUNT_MERGE:
      return "ACCOUNT_MERGE";
    case ::stellar::INFLATION:
      return "INFLATION";
    case ::stellar::MANAGE_DATA:
      return "MANAGE_DATA";
    case ::stellar::BUMP_SEQUENCE:
      return "BUMP_SEQUENCE";
    case ::stellar::MANAGE_BUY_OFFER:
      return "MANAGE_BUY_OFFER";
    case ::stellar::PATH_PAYMENT_STRICT_SEND:
      return "PATH_PAYMENT_STRICT_SEND";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CREATE_ACCOUNT,
      ::stellar::PAYMENT,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE,
      ::stellar::MANAGE_SELL_OFFER,
      ::stellar::CREATE_PASSIVE_SELL_OFFER,
      ::stellar::SET_OPTIONS,
      ::stellar::CHANGE_TRUST,
      ::stellar::ALLOW_TRUST,
      ::stellar::ACCOUNT_MERGE,
      ::stellar::INFLATION,
      ::stellar::MANAGE_DATA,
      ::stellar::BUMP_SEQUENCE,
      ::stellar::MANAGE_BUY_OFFER,
      ::stellar::PATH_PAYMENT_STRICT_SEND
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct CreateAccountOp {
  AccountID destination{};
  int64 startingBalance{};

  CreateAccountOp() = default;
  template<typename _destination_T,
           typename _startingBalance_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _destination_T>::value
                          && std::is_constructible<int64, _startingBalance_T>::value
                         >::type>
  explicit CreateAccountOp(_destination_T &&_destination,
                           _startingBalance_T &&_startingBalance)
    : destination(std::forward<_destination_T>(_destination)),
      startingBalance(std::forward<_startingBalance_T>(_startingBalance)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::CreateAccountOp>
  : xdr_struct_base<field_ptr<::stellar::CreateAccountOp,
                              decltype(::stellar::CreateAccountOp::destination),
                              &::stellar::CreateAccountOp::destination>,
                    field_ptr<::stellar::CreateAccountOp,
                              decltype(::stellar::CreateAccountOp::startingBalance),
                              &::stellar::CreateAccountOp::startingBalance>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::CreateAccountOp &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.startingBalance, "startingBalance");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::CreateAccountOp &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.startingBalance, "startingBalance");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct PaymentOp {
  MuxedAccount destination{};
  Asset asset{};
  int64 amount{};

  PaymentOp() = default;
  template<typename _destination_T,
           typename _asset_T,
           typename _amount_T,
           typename = typename
           std::enable_if<std::is_constructible<MuxedAccount, _destination_T>::value
                          && std::is_constructible<Asset, _asset_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                         >::type>
  explicit PaymentOp(_destination_T &&_destination,
                     _asset_T &&_asset,
                     _amount_T &&_amount)
    : destination(std::forward<_destination_T>(_destination)),
      asset(std::forward<_asset_T>(_asset)),
      amount(std::forward<_amount_T>(_amount)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PaymentOp>
  : xdr_struct_base<field_ptr<::stellar::PaymentOp,
                              decltype(::stellar::PaymentOp::destination),
                              &::stellar::PaymentOp::destination>,
                    field_ptr<::stellar::PaymentOp,
                              decltype(::stellar::PaymentOp::asset),
                              &::stellar::PaymentOp::asset>,
                    field_ptr<::stellar::PaymentOp,
                              decltype(::stellar::PaymentOp::amount),
                              &::stellar::PaymentOp::amount>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PaymentOp &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.amount, "amount");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PaymentOp &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.amount, "amount");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct PathPaymentStrictReceiveOp {
  Asset sendAsset{};
  int64 sendMax{};
  MuxedAccount destination{};
  Asset destAsset{};
  int64 destAmount{};
  xdr::xvector<Asset,5> path{};

  PathPaymentStrictReceiveOp() = default;
  template<typename _sendAsset_T,
           typename _sendMax_T,
           typename _destination_T,
           typename _destAsset_T,
           typename _destAmount_T,
           typename _path_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _sendAsset_T>::value
                          && std::is_constructible<int64, _sendMax_T>::value
                          && std::is_constructible<MuxedAccount, _destination_T>::value
                          && std::is_constructible<Asset, _destAsset_T>::value
                          && std::is_constructible<int64, _destAmount_T>::value
                          && std::is_constructible<xdr::xvector<Asset,5>, _path_T>::value
                         >::type>
  explicit PathPaymentStrictReceiveOp(_sendAsset_T &&_sendAsset,
                                      _sendMax_T &&_sendMax,
                                      _destination_T &&_destination,
                                      _destAsset_T &&_destAsset,
                                      _destAmount_T &&_destAmount,
                                      _path_T &&_path)
    : sendAsset(std::forward<_sendAsset_T>(_sendAsset)),
      sendMax(std::forward<_sendMax_T>(_sendMax)),
      destination(std::forward<_destination_T>(_destination)),
      destAsset(std::forward<_destAsset_T>(_destAsset)),
      destAmount(std::forward<_destAmount_T>(_destAmount)),
      path(std::forward<_path_T>(_path)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PathPaymentStrictReceiveOp>
  : xdr_struct_base<field_ptr<::stellar::PathPaymentStrictReceiveOp,
                              decltype(::stellar::PathPaymentStrictReceiveOp::sendAsset),
                              &::stellar::PathPaymentStrictReceiveOp::sendAsset>,
                    field_ptr<::stellar::PathPaymentStrictReceiveOp,
                              decltype(::stellar::PathPaymentStrictReceiveOp::sendMax),
                              &::stellar::PathPaymentStrictReceiveOp::sendMax>,
                    field_ptr<::stellar::PathPaymentStrictReceiveOp,
                              decltype(::stellar::PathPaymentStrictReceiveOp::destination),
                              &::stellar::PathPaymentStrictReceiveOp::destination>,
                    field_ptr<::stellar::PathPaymentStrictReceiveOp,
                              decltype(::stellar::PathPaymentStrictReceiveOp::destAsset),
                              &::stellar::PathPaymentStrictReceiveOp::destAsset>,
                    field_ptr<::stellar::PathPaymentStrictReceiveOp,
                              decltype(::stellar::PathPaymentStrictReceiveOp::destAmount),
                              &::stellar::PathPaymentStrictReceiveOp::destAmount>,
                    field_ptr<::stellar::PathPaymentStrictReceiveOp,
                              decltype(::stellar::PathPaymentStrictReceiveOp::path),
                              &::stellar::PathPaymentStrictReceiveOp::path>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PathPaymentStrictReceiveOp &obj) {
    archive(ar, obj.sendAsset, "sendAsset");
    archive(ar, obj.sendMax, "sendMax");
    archive(ar, obj.destination, "destination");
    archive(ar, obj.destAsset, "destAsset");
    archive(ar, obj.destAmount, "destAmount");
    archive(ar, obj.path, "path");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PathPaymentStrictReceiveOp &obj) {
    archive(ar, obj.sendAsset, "sendAsset");
    archive(ar, obj.sendMax, "sendMax");
    archive(ar, obj.destination, "destination");
    archive(ar, obj.destAsset, "destAsset");
    archive(ar, obj.destAmount, "destAmount");
    archive(ar, obj.path, "path");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct PathPaymentStrictSendOp {
  Asset sendAsset{};
  int64 sendAmount{};
  MuxedAccount destination{};
  Asset destAsset{};
  int64 destMin{};
  xdr::xvector<Asset,5> path{};

  PathPaymentStrictSendOp() = default;
  template<typename _sendAsset_T,
           typename _sendAmount_T,
           typename _destination_T,
           typename _destAsset_T,
           typename _destMin_T,
           typename _path_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _sendAsset_T>::value
                          && std::is_constructible<int64, _sendAmount_T>::value
                          && std::is_constructible<MuxedAccount, _destination_T>::value
                          && std::is_constructible<Asset, _destAsset_T>::value
                          && std::is_constructible<int64, _destMin_T>::value
                          && std::is_constructible<xdr::xvector<Asset,5>, _path_T>::value
                         >::type>
  explicit PathPaymentStrictSendOp(_sendAsset_T &&_sendAsset,
                                   _sendAmount_T &&_sendAmount,
                                   _destination_T &&_destination,
                                   _destAsset_T &&_destAsset,
                                   _destMin_T &&_destMin,
                                   _path_T &&_path)
    : sendAsset(std::forward<_sendAsset_T>(_sendAsset)),
      sendAmount(std::forward<_sendAmount_T>(_sendAmount)),
      destination(std::forward<_destination_T>(_destination)),
      destAsset(std::forward<_destAsset_T>(_destAsset)),
      destMin(std::forward<_destMin_T>(_destMin)),
      path(std::forward<_path_T>(_path)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PathPaymentStrictSendOp>
  : xdr_struct_base<field_ptr<::stellar::PathPaymentStrictSendOp,
                              decltype(::stellar::PathPaymentStrictSendOp::sendAsset),
                              &::stellar::PathPaymentStrictSendOp::sendAsset>,
                    field_ptr<::stellar::PathPaymentStrictSendOp,
                              decltype(::stellar::PathPaymentStrictSendOp::sendAmount),
                              &::stellar::PathPaymentStrictSendOp::sendAmount>,
                    field_ptr<::stellar::PathPaymentStrictSendOp,
                              decltype(::stellar::PathPaymentStrictSendOp::destination),
                              &::stellar::PathPaymentStrictSendOp::destination>,
                    field_ptr<::stellar::PathPaymentStrictSendOp,
                              decltype(::stellar::PathPaymentStrictSendOp::destAsset),
                              &::stellar::PathPaymentStrictSendOp::destAsset>,
                    field_ptr<::stellar::PathPaymentStrictSendOp,
                              decltype(::stellar::PathPaymentStrictSendOp::destMin),
                              &::stellar::PathPaymentStrictSendOp::destMin>,
                    field_ptr<::stellar::PathPaymentStrictSendOp,
                              decltype(::stellar::PathPaymentStrictSendOp::path),
                              &::stellar::PathPaymentStrictSendOp::path>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PathPaymentStrictSendOp &obj) {
    archive(ar, obj.sendAsset, "sendAsset");
    archive(ar, obj.sendAmount, "sendAmount");
    archive(ar, obj.destination, "destination");
    archive(ar, obj.destAsset, "destAsset");
    archive(ar, obj.destMin, "destMin");
    archive(ar, obj.path, "path");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PathPaymentStrictSendOp &obj) {
    archive(ar, obj.sendAsset, "sendAsset");
    archive(ar, obj.sendAmount, "sendAmount");
    archive(ar, obj.destination, "destination");
    archive(ar, obj.destAsset, "destAsset");
    archive(ar, obj.destMin, "destMin");
    archive(ar, obj.path, "path");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ManageSellOfferOp {
  Asset selling{};
  Asset buying{};
  int64 amount{};
  Price price{};
  int64 offerID{};

  ManageSellOfferOp() = default;
  template<typename _selling_T,
           typename _buying_T,
           typename _amount_T,
           typename _price_T,
           typename _offerID_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _selling_T>::value
                          && std::is_constructible<Asset, _buying_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                          && std::is_constructible<Price, _price_T>::value
                          && std::is_constructible<int64, _offerID_T>::value
                         >::type>
  explicit ManageSellOfferOp(_selling_T &&_selling,
                             _buying_T &&_buying,
                             _amount_T &&_amount,
                             _price_T &&_price,
                             _offerID_T &&_offerID)
    : selling(std::forward<_selling_T>(_selling)),
      buying(std::forward<_buying_T>(_buying)),
      amount(std::forward<_amount_T>(_amount)),
      price(std::forward<_price_T>(_price)),
      offerID(std::forward<_offerID_T>(_offerID)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageSellOfferOp>
  : xdr_struct_base<field_ptr<::stellar::ManageSellOfferOp,
                              decltype(::stellar::ManageSellOfferOp::selling),
                              &::stellar::ManageSellOfferOp::selling>,
                    field_ptr<::stellar::ManageSellOfferOp,
                              decltype(::stellar::ManageSellOfferOp::buying),
                              &::stellar::ManageSellOfferOp::buying>,
                    field_ptr<::stellar::ManageSellOfferOp,
                              decltype(::stellar::ManageSellOfferOp::amount),
                              &::stellar::ManageSellOfferOp::amount>,
                    field_ptr<::stellar::ManageSellOfferOp,
                              decltype(::stellar::ManageSellOfferOp::price),
                              &::stellar::ManageSellOfferOp::price>,
                    field_ptr<::stellar::ManageSellOfferOp,
                              decltype(::stellar::ManageSellOfferOp::offerID),
                              &::stellar::ManageSellOfferOp::offerID>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageSellOfferOp &obj) {
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    archive(ar, obj.offerID, "offerID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageSellOfferOp &obj) {
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    archive(ar, obj.offerID, "offerID");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ManageBuyOfferOp {
  Asset selling{};
  Asset buying{};
  int64 buyAmount{};
  Price price{};
  int64 offerID{};

  ManageBuyOfferOp() = default;
  template<typename _selling_T,
           typename _buying_T,
           typename _buyAmount_T,
           typename _price_T,
           typename _offerID_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _selling_T>::value
                          && std::is_constructible<Asset, _buying_T>::value
                          && std::is_constructible<int64, _buyAmount_T>::value
                          && std::is_constructible<Price, _price_T>::value
                          && std::is_constructible<int64, _offerID_T>::value
                         >::type>
  explicit ManageBuyOfferOp(_selling_T &&_selling,
                            _buying_T &&_buying,
                            _buyAmount_T &&_buyAmount,
                            _price_T &&_price,
                            _offerID_T &&_offerID)
    : selling(std::forward<_selling_T>(_selling)),
      buying(std::forward<_buying_T>(_buying)),
      buyAmount(std::forward<_buyAmount_T>(_buyAmount)),
      price(std::forward<_price_T>(_price)),
      offerID(std::forward<_offerID_T>(_offerID)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageBuyOfferOp>
  : xdr_struct_base<field_ptr<::stellar::ManageBuyOfferOp,
                              decltype(::stellar::ManageBuyOfferOp::selling),
                              &::stellar::ManageBuyOfferOp::selling>,
                    field_ptr<::stellar::ManageBuyOfferOp,
                              decltype(::stellar::ManageBuyOfferOp::buying),
                              &::stellar::ManageBuyOfferOp::buying>,
                    field_ptr<::stellar::ManageBuyOfferOp,
                              decltype(::stellar::ManageBuyOfferOp::buyAmount),
                              &::stellar::ManageBuyOfferOp::buyAmount>,
                    field_ptr<::stellar::ManageBuyOfferOp,
                              decltype(::stellar::ManageBuyOfferOp::price),
                              &::stellar::ManageBuyOfferOp::price>,
                    field_ptr<::stellar::ManageBuyOfferOp,
                              decltype(::stellar::ManageBuyOfferOp::offerID),
                              &::stellar::ManageBuyOfferOp::offerID>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageBuyOfferOp &obj) {
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.buyAmount, "buyAmount");
    archive(ar, obj.price, "price");
    archive(ar, obj.offerID, "offerID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageBuyOfferOp &obj) {
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.buyAmount, "buyAmount");
    archive(ar, obj.price, "price");
    archive(ar, obj.offerID, "offerID");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct CreatePassiveSellOfferOp {
  Asset selling{};
  Asset buying{};
  int64 amount{};
  Price price{};

  CreatePassiveSellOfferOp() = default;
  template<typename _selling_T,
           typename _buying_T,
           typename _amount_T,
           typename _price_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _selling_T>::value
                          && std::is_constructible<Asset, _buying_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                          && std::is_constructible<Price, _price_T>::value
                         >::type>
  explicit CreatePassiveSellOfferOp(_selling_T &&_selling,
                                    _buying_T &&_buying,
                                    _amount_T &&_amount,
                                    _price_T &&_price)
    : selling(std::forward<_selling_T>(_selling)),
      buying(std::forward<_buying_T>(_buying)),
      amount(std::forward<_amount_T>(_amount)),
      price(std::forward<_price_T>(_price)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::CreatePassiveSellOfferOp>
  : xdr_struct_base<field_ptr<::stellar::CreatePassiveSellOfferOp,
                              decltype(::stellar::CreatePassiveSellOfferOp::selling),
                              &::stellar::CreatePassiveSellOfferOp::selling>,
                    field_ptr<::stellar::CreatePassiveSellOfferOp,
                              decltype(::stellar::CreatePassiveSellOfferOp::buying),
                              &::stellar::CreatePassiveSellOfferOp::buying>,
                    field_ptr<::stellar::CreatePassiveSellOfferOp,
                              decltype(::stellar::CreatePassiveSellOfferOp::amount),
                              &::stellar::CreatePassiveSellOfferOp::amount>,
                    field_ptr<::stellar::CreatePassiveSellOfferOp,
                              decltype(::stellar::CreatePassiveSellOfferOp::price),
                              &::stellar::CreatePassiveSellOfferOp::price>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::CreatePassiveSellOfferOp &obj) {
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::CreatePassiveSellOfferOp &obj) {
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct SetOptionsOp {
  xdr::pointer<AccountID> inflationDest{};
  xdr::pointer<uint32> clearFlags{};
  xdr::pointer<uint32> setFlags{};
  xdr::pointer<uint32> masterWeight{};
  xdr::pointer<uint32> lowThreshold{};
  xdr::pointer<uint32> medThreshold{};
  xdr::pointer<uint32> highThreshold{};
  xdr::pointer<string32> homeDomain{};
  xdr::pointer<Signer> signer{};

  SetOptionsOp() = default;
  template<typename _inflationDest_T,
           typename _clearFlags_T,
           typename _setFlags_T,
           typename _masterWeight_T,
           typename _lowThreshold_T,
           typename _medThreshold_T,
           typename _highThreshold_T,
           typename _homeDomain_T,
           typename _signer_T,
           typename = typename
           std::enable_if<std::is_constructible<xdr::pointer<AccountID>, _inflationDest_T>::value
                          && std::is_constructible<xdr::pointer<uint32>, _clearFlags_T>::value
                          && std::is_constructible<xdr::pointer<uint32>, _setFlags_T>::value
                          && std::is_constructible<xdr::pointer<uint32>, _masterWeight_T>::value
                          && std::is_constructible<xdr::pointer<uint32>, _lowThreshold_T>::value
                          && std::is_constructible<xdr::pointer<uint32>, _medThreshold_T>::value
                          && std::is_constructible<xdr::pointer<uint32>, _highThreshold_T>::value
                          && std::is_constructible<xdr::pointer<string32>, _homeDomain_T>::value
                          && std::is_constructible<xdr::pointer<Signer>, _signer_T>::value
                         >::type>
  explicit SetOptionsOp(_inflationDest_T &&_inflationDest,
                        _clearFlags_T &&_clearFlags,
                        _setFlags_T &&_setFlags,
                        _masterWeight_T &&_masterWeight,
                        _lowThreshold_T &&_lowThreshold,
                        _medThreshold_T &&_medThreshold,
                        _highThreshold_T &&_highThreshold,
                        _homeDomain_T &&_homeDomain,
                        _signer_T &&_signer)
    : inflationDest(std::forward<_inflationDest_T>(_inflationDest)),
      clearFlags(std::forward<_clearFlags_T>(_clearFlags)),
      setFlags(std::forward<_setFlags_T>(_setFlags)),
      masterWeight(std::forward<_masterWeight_T>(_masterWeight)),
      lowThreshold(std::forward<_lowThreshold_T>(_lowThreshold)),
      medThreshold(std::forward<_medThreshold_T>(_medThreshold)),
      highThreshold(std::forward<_highThreshold_T>(_highThreshold)),
      homeDomain(std::forward<_homeDomain_T>(_homeDomain)),
      signer(std::forward<_signer_T>(_signer)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SetOptionsOp>
  : xdr_struct_base<field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::inflationDest),
                              &::stellar::SetOptionsOp::inflationDest>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::clearFlags),
                              &::stellar::SetOptionsOp::clearFlags>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::setFlags),
                              &::stellar::SetOptionsOp::setFlags>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::masterWeight),
                              &::stellar::SetOptionsOp::masterWeight>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::lowThreshold),
                              &::stellar::SetOptionsOp::lowThreshold>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::medThreshold),
                              &::stellar::SetOptionsOp::medThreshold>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::highThreshold),
                              &::stellar::SetOptionsOp::highThreshold>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::homeDomain),
                              &::stellar::SetOptionsOp::homeDomain>,
                    field_ptr<::stellar::SetOptionsOp,
                              decltype(::stellar::SetOptionsOp::signer),
                              &::stellar::SetOptionsOp::signer>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SetOptionsOp &obj) {
    archive(ar, obj.inflationDest, "inflationDest");
    archive(ar, obj.clearFlags, "clearFlags");
    archive(ar, obj.setFlags, "setFlags");
    archive(ar, obj.masterWeight, "masterWeight");
    archive(ar, obj.lowThreshold, "lowThreshold");
    archive(ar, obj.medThreshold, "medThreshold");
    archive(ar, obj.highThreshold, "highThreshold");
    archive(ar, obj.homeDomain, "homeDomain");
    archive(ar, obj.signer, "signer");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SetOptionsOp &obj) {
    archive(ar, obj.inflationDest, "inflationDest");
    archive(ar, obj.clearFlags, "clearFlags");
    archive(ar, obj.setFlags, "setFlags");
    archive(ar, obj.masterWeight, "masterWeight");
    archive(ar, obj.lowThreshold, "lowThreshold");
    archive(ar, obj.medThreshold, "medThreshold");
    archive(ar, obj.highThreshold, "highThreshold");
    archive(ar, obj.homeDomain, "homeDomain");
    archive(ar, obj.signer, "signer");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ChangeTrustOp {
  Asset line{};
  int64 limit{};

  ChangeTrustOp() = default;
  template<typename _line_T,
           typename _limit_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _line_T>::value
                          && std::is_constructible<int64, _limit_T>::value
                         >::type>
  explicit ChangeTrustOp(_line_T &&_line,
                         _limit_T &&_limit)
    : line(std::forward<_line_T>(_line)),
      limit(std::forward<_limit_T>(_limit)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ChangeTrustOp>
  : xdr_struct_base<field_ptr<::stellar::ChangeTrustOp,
                              decltype(::stellar::ChangeTrustOp::line),
                              &::stellar::ChangeTrustOp::line>,
                    field_ptr<::stellar::ChangeTrustOp,
                              decltype(::stellar::ChangeTrustOp::limit),
                              &::stellar::ChangeTrustOp::limit>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ChangeTrustOp &obj) {
    archive(ar, obj.line, "line");
    archive(ar, obj.limit, "limit");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ChangeTrustOp &obj) {
    archive(ar, obj.line, "line");
    archive(ar, obj.limit, "limit");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AllowTrustOp {
  struct _asset_t {
    using _xdr_case_type = xdr::xdr_traits<AssetType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      AssetCode4 assetCode4_;
      AssetCode12 assetCode12_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<AssetType> &_xdr_case_values() {
      static const std::vector<AssetType> _xdr_disc_vec {
        ASSET_TYPE_CREDIT_ALPHANUM4,
        ASSET_TYPE_CREDIT_ALPHANUM12
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == ASSET_TYPE_CREDIT_ALPHANUM4 ? 1
        : which == ASSET_TYPE_CREDIT_ALPHANUM12 ? 2
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case ASSET_TYPE_CREDIT_ALPHANUM4:
        _f(&_asset_t::assetCode4_, std::forward<_A>(_a)...);
        return true;
      case ASSET_TYPE_CREDIT_ALPHANUM12:
        _f(&_asset_t::assetCode12_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _asset_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_asset_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _asset_t(AssetType which = AssetType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _asset_t(const _asset_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _asset_t(_asset_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_asset_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _asset_t &operator=(const _asset_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_asset_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _asset_t &operator=(_asset_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_asset_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    AssetType type() const { return AssetType(type_); }
    _asset_t &type(AssetType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    AssetCode4 &assetCode4() {
      if (_xdr_field_number(type_) == 1)
        return assetCode4_;
      throw xdr::xdr_wrong_union("_asset_t: assetCode4 accessed when not selected");
    }
    const AssetCode4 &assetCode4() const {
      if (_xdr_field_number(type_) == 1)
        return assetCode4_;
      throw xdr::xdr_wrong_union("_asset_t: assetCode4 accessed when not selected");
    }
    AssetCode12 &assetCode12() {
      if (_xdr_field_number(type_) == 2)
        return assetCode12_;
      throw xdr::xdr_wrong_union("_asset_t: assetCode12 accessed when not selected");
    }
    const AssetCode12 &assetCode12() const {
      if (_xdr_field_number(type_) == 2)
        return assetCode12_;
      throw xdr::xdr_wrong_union("_asset_t: assetCode12 accessed when not selected");
    }
  };

  AccountID trustor{};
  _asset_t asset{};
  uint32 authorize{};

  AllowTrustOp() = default;
  template<typename _trustor_T,
           typename _asset_T,
           typename _authorize_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _trustor_T>::value
                          && std::is_constructible<_asset_t, _asset_T>::value
                          && std::is_constructible<uint32, _authorize_T>::value
                         >::type>
  explicit AllowTrustOp(_trustor_T &&_trustor,
                        _asset_T &&_asset,
                        _authorize_T &&_authorize)
    : trustor(std::forward<_trustor_T>(_trustor)),
      asset(std::forward<_asset_T>(_asset)),
      authorize(std::forward<_authorize_T>(_authorize)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AllowTrustOp::_asset_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AllowTrustOp::_asset_t;
  using case_type = ::stellar::AllowTrustOp::_asset_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "assetCode4";
    case 2:
      return "assetCode12";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AllowTrustOp::_asset_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _asset_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AllowTrustOp::_asset_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _asset_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AllowTrustOp::_asset_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AllowTrustOp>
  : xdr_struct_base<field_ptr<::stellar::AllowTrustOp,
                              decltype(::stellar::AllowTrustOp::trustor),
                              &::stellar::AllowTrustOp::trustor>,
                    field_ptr<::stellar::AllowTrustOp,
                              decltype(::stellar::AllowTrustOp::asset),
                              &::stellar::AllowTrustOp::asset>,
                    field_ptr<::stellar::AllowTrustOp,
                              decltype(::stellar::AllowTrustOp::authorize),
                              &::stellar::AllowTrustOp::authorize>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AllowTrustOp &obj) {
    archive(ar, obj.trustor, "trustor");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.authorize, "authorize");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AllowTrustOp &obj) {
    archive(ar, obj.trustor, "trustor");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.authorize, "authorize");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ManageDataOp {
  string64 dataName{};
  xdr::pointer<DataValue> dataValue{};

  ManageDataOp() = default;
  template<typename _dataName_T,
           typename _dataValue_T,
           typename = typename
           std::enable_if<std::is_constructible<string64, _dataName_T>::value
                          && std::is_constructible<xdr::pointer<DataValue>, _dataValue_T>::value
                         >::type>
  explicit ManageDataOp(_dataName_T &&_dataName,
                        _dataValue_T &&_dataValue)
    : dataName(std::forward<_dataName_T>(_dataName)),
      dataValue(std::forward<_dataValue_T>(_dataValue)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageDataOp>
  : xdr_struct_base<field_ptr<::stellar::ManageDataOp,
                              decltype(::stellar::ManageDataOp::dataName),
                              &::stellar::ManageDataOp::dataName>,
                    field_ptr<::stellar::ManageDataOp,
                              decltype(::stellar::ManageDataOp::dataValue),
                              &::stellar::ManageDataOp::dataValue>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageDataOp &obj) {
    archive(ar, obj.dataName, "dataName");
    archive(ar, obj.dataValue, "dataValue");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageDataOp &obj) {
    archive(ar, obj.dataName, "dataName");
    archive(ar, obj.dataValue, "dataValue");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct BumpSequenceOp {
  SequenceNumber bumpTo{};

  BumpSequenceOp() = default;
  template<typename _bumpTo_T,
           typename = typename
           std::enable_if<std::is_constructible<SequenceNumber, _bumpTo_T>::value
                         >::type>
  explicit BumpSequenceOp(_bumpTo_T &&_bumpTo)
    : bumpTo(std::forward<_bumpTo_T>(_bumpTo)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::BumpSequenceOp>
  : xdr_struct_base<field_ptr<::stellar::BumpSequenceOp,
                              decltype(::stellar::BumpSequenceOp::bumpTo),
                              &::stellar::BumpSequenceOp::bumpTo>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::BumpSequenceOp &obj) {
    archive(ar, obj.bumpTo, "bumpTo");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::BumpSequenceOp &obj) {
    archive(ar, obj.bumpTo, "bumpTo");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Operation {
  struct _body_t {
    using _xdr_case_type = xdr::xdr_traits<OperationType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      CreateAccountOp createAccountOp_;
      PaymentOp paymentOp_;
      PathPaymentStrictReceiveOp pathPaymentStrictReceiveOp_;
      ManageSellOfferOp manageSellOfferOp_;
      CreatePassiveSellOfferOp createPassiveSellOfferOp_;
      SetOptionsOp setOptionsOp_;
      ChangeTrustOp changeTrustOp_;
      AllowTrustOp allowTrustOp_;
      MuxedAccount destination_;
      ManageDataOp manageDataOp_;
      BumpSequenceOp bumpSequenceOp_;
      ManageBuyOfferOp manageBuyOfferOp_;
      PathPaymentStrictSendOp pathPaymentStrictSendOp_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<OperationType> &_xdr_case_values() {
      static const std::vector<OperationType> _xdr_disc_vec {
        CREATE_ACCOUNT,
        PAYMENT,
        PATH_PAYMENT_STRICT_RECEIVE,
        MANAGE_SELL_OFFER,
        CREATE_PASSIVE_SELL_OFFER,
        SET_OPTIONS,
        CHANGE_TRUST,
        ALLOW_TRUST,
        ACCOUNT_MERGE,
        INFLATION,
        MANAGE_DATA,
        BUMP_SEQUENCE,
        MANAGE_BUY_OFFER,
        PATH_PAYMENT_STRICT_SEND
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == CREATE_ACCOUNT ? 1
        : which == PAYMENT ? 2
        : which == PATH_PAYMENT_STRICT_RECEIVE ? 3
        : which == MANAGE_SELL_OFFER ? 4
        : which == CREATE_PASSIVE_SELL_OFFER ? 5
        : which == SET_OPTIONS ? 6
        : which == CHANGE_TRUST ? 7
        : which == ALLOW_TRUST ? 8
        : which == ACCOUNT_MERGE ? 9
        : which == INFLATION ? 0
        : which == MANAGE_DATA ? 10
        : which == BUMP_SEQUENCE ? 11
        : which == MANAGE_BUY_OFFER ? 12
        : which == PATH_PAYMENT_STRICT_SEND ? 13
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case CREATE_ACCOUNT:
        _f(&_body_t::createAccountOp_, std::forward<_A>(_a)...);
        return true;
      case PAYMENT:
        _f(&_body_t::paymentOp_, std::forward<_A>(_a)...);
        return true;
      case PATH_PAYMENT_STRICT_RECEIVE:
        _f(&_body_t::pathPaymentStrictReceiveOp_, std::forward<_A>(_a)...);
        return true;
      case MANAGE_SELL_OFFER:
        _f(&_body_t::manageSellOfferOp_, std::forward<_A>(_a)...);
        return true;
      case CREATE_PASSIVE_SELL_OFFER:
        _f(&_body_t::createPassiveSellOfferOp_, std::forward<_A>(_a)...);
        return true;
      case SET_OPTIONS:
        _f(&_body_t::setOptionsOp_, std::forward<_A>(_a)...);
        return true;
      case CHANGE_TRUST:
        _f(&_body_t::changeTrustOp_, std::forward<_A>(_a)...);
        return true;
      case ALLOW_TRUST:
        _f(&_body_t::allowTrustOp_, std::forward<_A>(_a)...);
        return true;
      case ACCOUNT_MERGE:
        _f(&_body_t::destination_, std::forward<_A>(_a)...);
        return true;
      case INFLATION:
        return true;
      case MANAGE_DATA:
        _f(&_body_t::manageDataOp_, std::forward<_A>(_a)...);
        return true;
      case BUMP_SEQUENCE:
        _f(&_body_t::bumpSequenceOp_, std::forward<_A>(_a)...);
        return true;
      case MANAGE_BUY_OFFER:
        _f(&_body_t::manageBuyOfferOp_, std::forward<_A>(_a)...);
        return true;
      case PATH_PAYMENT_STRICT_SEND:
        _f(&_body_t::pathPaymentStrictSendOp_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _body_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_body_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _body_t(OperationType which = OperationType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _body_t(const _body_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _body_t(_body_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_body_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _body_t &operator=(const _body_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_body_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _body_t &operator=(_body_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_body_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    OperationType type() const { return OperationType(type_); }
    _body_t &type(OperationType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    CreateAccountOp &createAccountOp() {
      if (_xdr_field_number(type_) == 1)
        return createAccountOp_;
      throw xdr::xdr_wrong_union("_body_t: createAccountOp accessed when not selected");
    }
    const CreateAccountOp &createAccountOp() const {
      if (_xdr_field_number(type_) == 1)
        return createAccountOp_;
      throw xdr::xdr_wrong_union("_body_t: createAccountOp accessed when not selected");
    }
    PaymentOp &paymentOp() {
      if (_xdr_field_number(type_) == 2)
        return paymentOp_;
      throw xdr::xdr_wrong_union("_body_t: paymentOp accessed when not selected");
    }
    const PaymentOp &paymentOp() const {
      if (_xdr_field_number(type_) == 2)
        return paymentOp_;
      throw xdr::xdr_wrong_union("_body_t: paymentOp accessed when not selected");
    }
    PathPaymentStrictReceiveOp &pathPaymentStrictReceiveOp() {
      if (_xdr_field_number(type_) == 3)
        return pathPaymentStrictReceiveOp_;
      throw xdr::xdr_wrong_union("_body_t: pathPaymentStrictReceiveOp accessed when not selected");
    }
    const PathPaymentStrictReceiveOp &pathPaymentStrictReceiveOp() const {
      if (_xdr_field_number(type_) == 3)
        return pathPaymentStrictReceiveOp_;
      throw xdr::xdr_wrong_union("_body_t: pathPaymentStrictReceiveOp accessed when not selected");
    }
    ManageSellOfferOp &manageSellOfferOp() {
      if (_xdr_field_number(type_) == 4)
        return manageSellOfferOp_;
      throw xdr::xdr_wrong_union("_body_t: manageSellOfferOp accessed when not selected");
    }
    const ManageSellOfferOp &manageSellOfferOp() const {
      if (_xdr_field_number(type_) == 4)
        return manageSellOfferOp_;
      throw xdr::xdr_wrong_union("_body_t: manageSellOfferOp accessed when not selected");
    }
    CreatePassiveSellOfferOp &createPassiveSellOfferOp() {
      if (_xdr_field_number(type_) == 5)
        return createPassiveSellOfferOp_;
      throw xdr::xdr_wrong_union("_body_t: createPassiveSellOfferOp accessed when not selected");
    }
    const CreatePassiveSellOfferOp &createPassiveSellOfferOp() const {
      if (_xdr_field_number(type_) == 5)
        return createPassiveSellOfferOp_;
      throw xdr::xdr_wrong_union("_body_t: createPassiveSellOfferOp accessed when not selected");
    }
    SetOptionsOp &setOptionsOp() {
      if (_xdr_field_number(type_) == 6)
        return setOptionsOp_;
      throw xdr::xdr_wrong_union("_body_t: setOptionsOp accessed when not selected");
    }
    const SetOptionsOp &setOptionsOp() const {
      if (_xdr_field_number(type_) == 6)
        return setOptionsOp_;
      throw xdr::xdr_wrong_union("_body_t: setOptionsOp accessed when not selected");
    }
    ChangeTrustOp &changeTrustOp() {
      if (_xdr_field_number(type_) == 7)
        return changeTrustOp_;
      throw xdr::xdr_wrong_union("_body_t: changeTrustOp accessed when not selected");
    }
    const ChangeTrustOp &changeTrustOp() const {
      if (_xdr_field_number(type_) == 7)
        return changeTrustOp_;
      throw xdr::xdr_wrong_union("_body_t: changeTrustOp accessed when not selected");
    }
    AllowTrustOp &allowTrustOp() {
      if (_xdr_field_number(type_) == 8)
        return allowTrustOp_;
      throw xdr::xdr_wrong_union("_body_t: allowTrustOp accessed when not selected");
    }
    const AllowTrustOp &allowTrustOp() const {
      if (_xdr_field_number(type_) == 8)
        return allowTrustOp_;
      throw xdr::xdr_wrong_union("_body_t: allowTrustOp accessed when not selected");
    }
    MuxedAccount &destination() {
      if (_xdr_field_number(type_) == 9)
        return destination_;
      throw xdr::xdr_wrong_union("_body_t: destination accessed when not selected");
    }
    const MuxedAccount &destination() const {
      if (_xdr_field_number(type_) == 9)
        return destination_;
      throw xdr::xdr_wrong_union("_body_t: destination accessed when not selected");
    }
    ManageDataOp &manageDataOp() {
      if (_xdr_field_number(type_) == 10)
        return manageDataOp_;
      throw xdr::xdr_wrong_union("_body_t: manageDataOp accessed when not selected");
    }
    const ManageDataOp &manageDataOp() const {
      if (_xdr_field_number(type_) == 10)
        return manageDataOp_;
      throw xdr::xdr_wrong_union("_body_t: manageDataOp accessed when not selected");
    }
    BumpSequenceOp &bumpSequenceOp() {
      if (_xdr_field_number(type_) == 11)
        return bumpSequenceOp_;
      throw xdr::xdr_wrong_union("_body_t: bumpSequenceOp accessed when not selected");
    }
    const BumpSequenceOp &bumpSequenceOp() const {
      if (_xdr_field_number(type_) == 11)
        return bumpSequenceOp_;
      throw xdr::xdr_wrong_union("_body_t: bumpSequenceOp accessed when not selected");
    }
    ManageBuyOfferOp &manageBuyOfferOp() {
      if (_xdr_field_number(type_) == 12)
        return manageBuyOfferOp_;
      throw xdr::xdr_wrong_union("_body_t: manageBuyOfferOp accessed when not selected");
    }
    const ManageBuyOfferOp &manageBuyOfferOp() const {
      if (_xdr_field_number(type_) == 12)
        return manageBuyOfferOp_;
      throw xdr::xdr_wrong_union("_body_t: manageBuyOfferOp accessed when not selected");
    }
    PathPaymentStrictSendOp &pathPaymentStrictSendOp() {
      if (_xdr_field_number(type_) == 13)
        return pathPaymentStrictSendOp_;
      throw xdr::xdr_wrong_union("_body_t: pathPaymentStrictSendOp accessed when not selected");
    }
    const PathPaymentStrictSendOp &pathPaymentStrictSendOp() const {
      if (_xdr_field_number(type_) == 13)
        return pathPaymentStrictSendOp_;
      throw xdr::xdr_wrong_union("_body_t: pathPaymentStrictSendOp accessed when not selected");
    }
  };

  xdr::pointer<MuxedAccount> sourceAccount{};
  _body_t body{};

  Operation() = default;
  template<typename _sourceAccount_T,
           typename _body_T,
           typename = typename
           std::enable_if<std::is_constructible<xdr::pointer<MuxedAccount>, _sourceAccount_T>::value
                          && std::is_constructible<_body_t, _body_T>::value
                         >::type>
  explicit Operation(_sourceAccount_T &&_sourceAccount,
                     _body_T &&_body)
    : sourceAccount(std::forward<_sourceAccount_T>(_sourceAccount)),
      body(std::forward<_body_T>(_body)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Operation::_body_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::Operation::_body_t;
  using case_type = ::stellar::Operation::_body_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "createAccountOp";
    case 2:
      return "paymentOp";
    case 3:
      return "pathPaymentStrictReceiveOp";
    case 4:
      return "manageSellOfferOp";
    case 5:
      return "createPassiveSellOfferOp";
    case 6:
      return "setOptionsOp";
    case 7:
      return "changeTrustOp";
    case 8:
      return "allowTrustOp";
    case 9:
      return "destination";
    case 10:
      return "manageDataOp";
    case 11:
      return "bumpSequenceOp";
    case 12:
      return "manageBuyOfferOp";
    case 13:
      return "pathPaymentStrictSendOp";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::Operation::_body_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _body_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Operation::_body_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _body_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Operation::_body_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::Operation>
  : xdr_struct_base<field_ptr<::stellar::Operation,
                              decltype(::stellar::Operation::sourceAccount),
                              &::stellar::Operation::sourceAccount>,
                    field_ptr<::stellar::Operation,
                              decltype(::stellar::Operation::body),
                              &::stellar::Operation::body>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Operation &obj) {
    archive(ar, obj.sourceAccount, "sourceAccount");
    archive(ar, obj.body, "body");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Operation &obj) {
    archive(ar, obj.sourceAccount, "sourceAccount");
    archive(ar, obj.body, "body");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum MemoType : std::int32_t {
  MEMO_NONE = 0,
  MEMO_TEXT = 1,
  MEMO_ID = 2,
  MEMO_HASH = 3,
  MEMO_RETURN = 4,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::MemoType>
  : xdr_integral_base<::stellar::MemoType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::MemoType val) {
    switch (val) {
    case ::stellar::MEMO_NONE:
      return "MEMO_NONE";
    case ::stellar::MEMO_TEXT:
      return "MEMO_TEXT";
    case ::stellar::MEMO_ID:
      return "MEMO_ID";
    case ::stellar::MEMO_HASH:
      return "MEMO_HASH";
    case ::stellar::MEMO_RETURN:
      return "MEMO_RETURN";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::MEMO_NONE,
      ::stellar::MEMO_TEXT,
      ::stellar::MEMO_ID,
      ::stellar::MEMO_HASH,
      ::stellar::MEMO_RETURN
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct Memo {
  using _xdr_case_type = xdr::xdr_traits<MemoType>::case_type;
private:
  _xdr_case_type type_;
  union {
    xdr::xstring<28> text_;
    uint64 id_;
    Hash hash_;
    Hash retHash_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<MemoType> &_xdr_case_values() {
    static const std::vector<MemoType> _xdr_disc_vec {
      MEMO_NONE,
      MEMO_TEXT,
      MEMO_ID,
      MEMO_HASH,
      MEMO_RETURN
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == MEMO_NONE ? 0
      : which == MEMO_TEXT ? 1
      : which == MEMO_ID ? 2
      : which == MEMO_HASH ? 3
      : which == MEMO_RETURN ? 4
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case MEMO_NONE:
      return true;
    case MEMO_TEXT:
      _f(&Memo::text_, std::forward<_A>(_a)...);
      return true;
    case MEMO_ID:
      _f(&Memo::id_, std::forward<_A>(_a)...);
      return true;
    case MEMO_HASH:
      _f(&Memo::hash_, std::forward<_A>(_a)...);
      return true;
    case MEMO_RETURN:
      _f(&Memo::retHash_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in Memo");
    if (fnum != _xdr_field_number(type_)) {
      this->~Memo();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit Memo(MemoType which = MemoType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  Memo(const Memo &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  Memo(Memo &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~Memo() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  Memo &operator=(const Memo &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~Memo();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  Memo &operator=(Memo &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~Memo();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  MemoType type() const { return MemoType(type_); }
  Memo &type(MemoType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  xdr::xstring<28> &text() {
    if (_xdr_field_number(type_) == 1)
      return text_;
    throw xdr::xdr_wrong_union("Memo: text accessed when not selected");
  }
  const xdr::xstring<28> &text() const {
    if (_xdr_field_number(type_) == 1)
      return text_;
    throw xdr::xdr_wrong_union("Memo: text accessed when not selected");
  }
  uint64 &id() {
    if (_xdr_field_number(type_) == 2)
      return id_;
    throw xdr::xdr_wrong_union("Memo: id accessed when not selected");
  }
  const uint64 &id() const {
    if (_xdr_field_number(type_) == 2)
      return id_;
    throw xdr::xdr_wrong_union("Memo: id accessed when not selected");
  }
  Hash &hash() {
    if (_xdr_field_number(type_) == 3)
      return hash_;
    throw xdr::xdr_wrong_union("Memo: hash accessed when not selected");
  }
  const Hash &hash() const {
    if (_xdr_field_number(type_) == 3)
      return hash_;
    throw xdr::xdr_wrong_union("Memo: hash accessed when not selected");
  }
  Hash &retHash() {
    if (_xdr_field_number(type_) == 4)
      return retHash_;
    throw xdr::xdr_wrong_union("Memo: retHash accessed when not selected");
  }
  const Hash &retHash() const {
    if (_xdr_field_number(type_) == 4)
      return retHash_;
    throw xdr::xdr_wrong_union("Memo: retHash accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Memo> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::Memo;
  using case_type = ::stellar::Memo::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "text";
    case 2:
      return "id";
    case 3:
      return "hash";
    case 4:
      return "retHash";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::Memo &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in Memo");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Memo &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in Memo");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Memo &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TimeBounds {
  TimePoint minTime{};
  TimePoint maxTime{};

  TimeBounds() = default;
  template<typename _minTime_T,
           typename _maxTime_T,
           typename = typename
           std::enable_if<std::is_constructible<TimePoint, _minTime_T>::value
                          && std::is_constructible<TimePoint, _maxTime_T>::value
                         >::type>
  explicit TimeBounds(_minTime_T &&_minTime,
                      _maxTime_T &&_maxTime)
    : minTime(std::forward<_minTime_T>(_minTime)),
      maxTime(std::forward<_maxTime_T>(_maxTime)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TimeBounds>
  : xdr_struct_base<field_ptr<::stellar::TimeBounds,
                              decltype(::stellar::TimeBounds::minTime),
                              &::stellar::TimeBounds::minTime>,
                    field_ptr<::stellar::TimeBounds,
                              decltype(::stellar::TimeBounds::maxTime),
                              &::stellar::TimeBounds::maxTime>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TimeBounds &obj) {
    archive(ar, obj.minTime, "minTime");
    archive(ar, obj.maxTime, "maxTime");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TimeBounds &obj) {
    archive(ar, obj.minTime, "minTime");
    archive(ar, obj.maxTime, "maxTime");
    xdr::validate(obj);
  }
};
} namespace stellar {

Constexpr const std::uint32_t MAX_OPS_PER_TX = 100;

struct TransactionV0 {
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

  uint256 sourceAccountEd25519{};
  uint32 fee{};
  SequenceNumber seqNum{};
  xdr::pointer<TimeBounds> timeBounds{};
  Memo memo{};
  xdr::xvector<Operation,MAX_OPS_PER_TX> operations{};
  _ext_t ext{};

  TransactionV0() = default;
  template<typename _sourceAccountEd25519_T,
           typename _fee_T,
           typename _seqNum_T,
           typename _timeBounds_T,
           typename _memo_T,
           typename _operations_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<uint256, _sourceAccountEd25519_T>::value
                          && std::is_constructible<uint32, _fee_T>::value
                          && std::is_constructible<SequenceNumber, _seqNum_T>::value
                          && std::is_constructible<xdr::pointer<TimeBounds>, _timeBounds_T>::value
                          && std::is_constructible<Memo, _memo_T>::value
                          && std::is_constructible<xdr::xvector<Operation,MAX_OPS_PER_TX>, _operations_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit TransactionV0(_sourceAccountEd25519_T &&_sourceAccountEd25519,
                         _fee_T &&_fee,
                         _seqNum_T &&_seqNum,
                         _timeBounds_T &&_timeBounds,
                         _memo_T &&_memo,
                         _operations_T &&_operations,
                         _ext_T &&_ext)
    : sourceAccountEd25519(std::forward<_sourceAccountEd25519_T>(_sourceAccountEd25519)),
      fee(std::forward<_fee_T>(_fee)),
      seqNum(std::forward<_seqNum_T>(_seqNum)),
      timeBounds(std::forward<_timeBounds_T>(_timeBounds)),
      memo(std::forward<_memo_T>(_memo)),
      operations(std::forward<_operations_T>(_operations)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionV0::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TransactionV0::_ext_t;
  using case_type = ::stellar::TransactionV0::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TransactionV0::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionV0::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionV0::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TransactionV0>
  : xdr_struct_base<field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::sourceAccountEd25519),
                              &::stellar::TransactionV0::sourceAccountEd25519>,
                    field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::fee),
                              &::stellar::TransactionV0::fee>,
                    field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::seqNum),
                              &::stellar::TransactionV0::seqNum>,
                    field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::timeBounds),
                              &::stellar::TransactionV0::timeBounds>,
                    field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::memo),
                              &::stellar::TransactionV0::memo>,
                    field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::operations),
                              &::stellar::TransactionV0::operations>,
                    field_ptr<::stellar::TransactionV0,
                              decltype(::stellar::TransactionV0::ext),
                              &::stellar::TransactionV0::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionV0 &obj) {
    archive(ar, obj.sourceAccountEd25519, "sourceAccountEd25519");
    archive(ar, obj.fee, "fee");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.timeBounds, "timeBounds");
    archive(ar, obj.memo, "memo");
    archive(ar, obj.operations, "operations");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionV0 &obj) {
    archive(ar, obj.sourceAccountEd25519, "sourceAccountEd25519");
    archive(ar, obj.fee, "fee");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.timeBounds, "timeBounds");
    archive(ar, obj.memo, "memo");
    archive(ar, obj.operations, "operations");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TransactionV0Envelope {
  TransactionV0 tx{};
  xdr::xvector<DecoratedSignature,20> signatures{};

  TransactionV0Envelope() = default;
  template<typename _tx_T,
           typename _signatures_T,
           typename = typename
           std::enable_if<std::is_constructible<TransactionV0, _tx_T>::value
                          && std::is_constructible<xdr::xvector<DecoratedSignature,20>, _signatures_T>::value
                         >::type>
  explicit TransactionV0Envelope(_tx_T &&_tx,
                                 _signatures_T &&_signatures)
    : tx(std::forward<_tx_T>(_tx)),
      signatures(std::forward<_signatures_T>(_signatures)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionV0Envelope>
  : xdr_struct_base<field_ptr<::stellar::TransactionV0Envelope,
                              decltype(::stellar::TransactionV0Envelope::tx),
                              &::stellar::TransactionV0Envelope::tx>,
                    field_ptr<::stellar::TransactionV0Envelope,
                              decltype(::stellar::TransactionV0Envelope::signatures),
                              &::stellar::TransactionV0Envelope::signatures>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionV0Envelope &obj) {
    archive(ar, obj.tx, "tx");
    archive(ar, obj.signatures, "signatures");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionV0Envelope &obj) {
    archive(ar, obj.tx, "tx");
    archive(ar, obj.signatures, "signatures");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Transaction {
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

  MuxedAccount sourceAccount{};
  uint32 fee{};
  SequenceNumber seqNum{};
  xdr::pointer<TimeBounds> timeBounds{};
  Memo memo{};
  xdr::xvector<Operation,MAX_OPS_PER_TX> operations{};
  _ext_t ext{};

  Transaction() = default;
  template<typename _sourceAccount_T,
           typename _fee_T,
           typename _seqNum_T,
           typename _timeBounds_T,
           typename _memo_T,
           typename _operations_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<MuxedAccount, _sourceAccount_T>::value
                          && std::is_constructible<uint32, _fee_T>::value
                          && std::is_constructible<SequenceNumber, _seqNum_T>::value
                          && std::is_constructible<xdr::pointer<TimeBounds>, _timeBounds_T>::value
                          && std::is_constructible<Memo, _memo_T>::value
                          && std::is_constructible<xdr::xvector<Operation,MAX_OPS_PER_TX>, _operations_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit Transaction(_sourceAccount_T &&_sourceAccount,
                       _fee_T &&_fee,
                       _seqNum_T &&_seqNum,
                       _timeBounds_T &&_timeBounds,
                       _memo_T &&_memo,
                       _operations_T &&_operations,
                       _ext_T &&_ext)
    : sourceAccount(std::forward<_sourceAccount_T>(_sourceAccount)),
      fee(std::forward<_fee_T>(_fee)),
      seqNum(std::forward<_seqNum_T>(_seqNum)),
      timeBounds(std::forward<_timeBounds_T>(_timeBounds)),
      memo(std::forward<_memo_T>(_memo)),
      operations(std::forward<_operations_T>(_operations)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Transaction::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::Transaction::_ext_t;
  using case_type = ::stellar::Transaction::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::Transaction::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Transaction::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Transaction::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::Transaction>
  : xdr_struct_base<field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::sourceAccount),
                              &::stellar::Transaction::sourceAccount>,
                    field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::fee),
                              &::stellar::Transaction::fee>,
                    field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::seqNum),
                              &::stellar::Transaction::seqNum>,
                    field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::timeBounds),
                              &::stellar::Transaction::timeBounds>,
                    field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::memo),
                              &::stellar::Transaction::memo>,
                    field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::operations),
                              &::stellar::Transaction::operations>,
                    field_ptr<::stellar::Transaction,
                              decltype(::stellar::Transaction::ext),
                              &::stellar::Transaction::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Transaction &obj) {
    archive(ar, obj.sourceAccount, "sourceAccount");
    archive(ar, obj.fee, "fee");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.timeBounds, "timeBounds");
    archive(ar, obj.memo, "memo");
    archive(ar, obj.operations, "operations");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Transaction &obj) {
    archive(ar, obj.sourceAccount, "sourceAccount");
    archive(ar, obj.fee, "fee");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.timeBounds, "timeBounds");
    archive(ar, obj.memo, "memo");
    archive(ar, obj.operations, "operations");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TransactionV1Envelope {
  Transaction tx{};
  xdr::xvector<DecoratedSignature,20> signatures{};

  TransactionV1Envelope() = default;
  template<typename _tx_T,
           typename _signatures_T,
           typename = typename
           std::enable_if<std::is_constructible<Transaction, _tx_T>::value
                          && std::is_constructible<xdr::xvector<DecoratedSignature,20>, _signatures_T>::value
                         >::type>
  explicit TransactionV1Envelope(_tx_T &&_tx,
                                 _signatures_T &&_signatures)
    : tx(std::forward<_tx_T>(_tx)),
      signatures(std::forward<_signatures_T>(_signatures)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionV1Envelope>
  : xdr_struct_base<field_ptr<::stellar::TransactionV1Envelope,
                              decltype(::stellar::TransactionV1Envelope::tx),
                              &::stellar::TransactionV1Envelope::tx>,
                    field_ptr<::stellar::TransactionV1Envelope,
                              decltype(::stellar::TransactionV1Envelope::signatures),
                              &::stellar::TransactionV1Envelope::signatures>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionV1Envelope &obj) {
    archive(ar, obj.tx, "tx");
    archive(ar, obj.signatures, "signatures");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionV1Envelope &obj) {
    archive(ar, obj.tx, "tx");
    archive(ar, obj.signatures, "signatures");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct FeeBumpTransaction {
  struct _innerTx_t {
    using _xdr_case_type = xdr::xdr_traits<EnvelopeType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      TransactionV1Envelope v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<EnvelopeType> &_xdr_case_values() {
      static const std::vector<EnvelopeType> _xdr_disc_vec {
        ENVELOPE_TYPE_TX
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == ENVELOPE_TYPE_TX ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case ENVELOPE_TYPE_TX:
        _f(&_innerTx_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _innerTx_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_innerTx_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _innerTx_t(EnvelopeType which = EnvelopeType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _innerTx_t(const _innerTx_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _innerTx_t(_innerTx_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_innerTx_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _innerTx_t &operator=(const _innerTx_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_innerTx_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _innerTx_t &operator=(_innerTx_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_innerTx_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    EnvelopeType type() const { return EnvelopeType(type_); }
    _innerTx_t &type(EnvelopeType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    TransactionV1Envelope &v1() {
      if (_xdr_field_number(type_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_innerTx_t: v1 accessed when not selected");
    }
    const TransactionV1Envelope &v1() const {
      if (_xdr_field_number(type_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_innerTx_t: v1 accessed when not selected");
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

  MuxedAccount feeSource{};
  int64 fee{};
  _innerTx_t innerTx{};
  _ext_t ext{};

  FeeBumpTransaction() = default;
  template<typename _feeSource_T,
           typename _fee_T,
           typename _innerTx_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<MuxedAccount, _feeSource_T>::value
                          && std::is_constructible<int64, _fee_T>::value
                          && std::is_constructible<_innerTx_t, _innerTx_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit FeeBumpTransaction(_feeSource_T &&_feeSource,
                              _fee_T &&_fee,
                              _innerTx_T &&_innerTx,
                              _ext_T &&_ext)
    : feeSource(std::forward<_feeSource_T>(_feeSource)),
      fee(std::forward<_fee_T>(_fee)),
      innerTx(std::forward<_innerTx_T>(_innerTx)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::FeeBumpTransaction::_innerTx_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::FeeBumpTransaction::_innerTx_t;
  using case_type = ::stellar::FeeBumpTransaction::_innerTx_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

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

  static std::size_t serial_size(const ::stellar::FeeBumpTransaction::_innerTx_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _innerTx_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::FeeBumpTransaction::_innerTx_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _innerTx_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::FeeBumpTransaction::_innerTx_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::FeeBumpTransaction::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::FeeBumpTransaction::_ext_t;
  using case_type = ::stellar::FeeBumpTransaction::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::FeeBumpTransaction::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::FeeBumpTransaction::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::FeeBumpTransaction::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::FeeBumpTransaction>
  : xdr_struct_base<field_ptr<::stellar::FeeBumpTransaction,
                              decltype(::stellar::FeeBumpTransaction::feeSource),
                              &::stellar::FeeBumpTransaction::feeSource>,
                    field_ptr<::stellar::FeeBumpTransaction,
                              decltype(::stellar::FeeBumpTransaction::fee),
                              &::stellar::FeeBumpTransaction::fee>,
                    field_ptr<::stellar::FeeBumpTransaction,
                              decltype(::stellar::FeeBumpTransaction::innerTx),
                              &::stellar::FeeBumpTransaction::innerTx>,
                    field_ptr<::stellar::FeeBumpTransaction,
                              decltype(::stellar::FeeBumpTransaction::ext),
                              &::stellar::FeeBumpTransaction::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::FeeBumpTransaction &obj) {
    archive(ar, obj.feeSource, "feeSource");
    archive(ar, obj.fee, "fee");
    archive(ar, obj.innerTx, "innerTx");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::FeeBumpTransaction &obj) {
    archive(ar, obj.feeSource, "feeSource");
    archive(ar, obj.fee, "fee");
    archive(ar, obj.innerTx, "innerTx");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct FeeBumpTransactionEnvelope {
  FeeBumpTransaction tx{};
  xdr::xvector<DecoratedSignature,20> signatures{};

  FeeBumpTransactionEnvelope() = default;
  template<typename _tx_T,
           typename _signatures_T,
           typename = typename
           std::enable_if<std::is_constructible<FeeBumpTransaction, _tx_T>::value
                          && std::is_constructible<xdr::xvector<DecoratedSignature,20>, _signatures_T>::value
                         >::type>
  explicit FeeBumpTransactionEnvelope(_tx_T &&_tx,
                                      _signatures_T &&_signatures)
    : tx(std::forward<_tx_T>(_tx)),
      signatures(std::forward<_signatures_T>(_signatures)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::FeeBumpTransactionEnvelope>
  : xdr_struct_base<field_ptr<::stellar::FeeBumpTransactionEnvelope,
                              decltype(::stellar::FeeBumpTransactionEnvelope::tx),
                              &::stellar::FeeBumpTransactionEnvelope::tx>,
                    field_ptr<::stellar::FeeBumpTransactionEnvelope,
                              decltype(::stellar::FeeBumpTransactionEnvelope::signatures),
                              &::stellar::FeeBumpTransactionEnvelope::signatures>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::FeeBumpTransactionEnvelope &obj) {
    archive(ar, obj.tx, "tx");
    archive(ar, obj.signatures, "signatures");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::FeeBumpTransactionEnvelope &obj) {
    archive(ar, obj.tx, "tx");
    archive(ar, obj.signatures, "signatures");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TransactionEnvelope {
  using _xdr_case_type = xdr::xdr_traits<EnvelopeType>::case_type;
private:
  _xdr_case_type type_;
  union {
    TransactionV0Envelope v0_;
    TransactionV1Envelope v1_;
    FeeBumpTransactionEnvelope feeBump_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<EnvelopeType> &_xdr_case_values() {
    static const std::vector<EnvelopeType> _xdr_disc_vec {
      ENVELOPE_TYPE_TX_V0,
      ENVELOPE_TYPE_TX,
      ENVELOPE_TYPE_TX_FEE_BUMP
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ENVELOPE_TYPE_TX_V0 ? 1
      : which == ENVELOPE_TYPE_TX ? 2
      : which == ENVELOPE_TYPE_TX_FEE_BUMP ? 3
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ENVELOPE_TYPE_TX_V0:
      _f(&TransactionEnvelope::v0_, std::forward<_A>(_a)...);
      return true;
    case ENVELOPE_TYPE_TX:
      _f(&TransactionEnvelope::v1_, std::forward<_A>(_a)...);
      return true;
    case ENVELOPE_TYPE_TX_FEE_BUMP:
      _f(&TransactionEnvelope::feeBump_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in TransactionEnvelope");
    if (fnum != _xdr_field_number(type_)) {
      this->~TransactionEnvelope();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit TransactionEnvelope(EnvelopeType which = EnvelopeType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  TransactionEnvelope(const TransactionEnvelope &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  TransactionEnvelope(TransactionEnvelope &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~TransactionEnvelope() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  TransactionEnvelope &operator=(const TransactionEnvelope &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~TransactionEnvelope();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  TransactionEnvelope &operator=(TransactionEnvelope &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~TransactionEnvelope();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  EnvelopeType type() const { return EnvelopeType(type_); }
  TransactionEnvelope &type(EnvelopeType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  TransactionV0Envelope &v0() {
    if (_xdr_field_number(type_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("TransactionEnvelope: v0 accessed when not selected");
  }
  const TransactionV0Envelope &v0() const {
    if (_xdr_field_number(type_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("TransactionEnvelope: v0 accessed when not selected");
  }
  TransactionV1Envelope &v1() {
    if (_xdr_field_number(type_) == 2)
      return v1_;
    throw xdr::xdr_wrong_union("TransactionEnvelope: v1 accessed when not selected");
  }
  const TransactionV1Envelope &v1() const {
    if (_xdr_field_number(type_) == 2)
      return v1_;
    throw xdr::xdr_wrong_union("TransactionEnvelope: v1 accessed when not selected");
  }
  FeeBumpTransactionEnvelope &feeBump() {
    if (_xdr_field_number(type_) == 3)
      return feeBump_;
    throw xdr::xdr_wrong_union("TransactionEnvelope: feeBump accessed when not selected");
  }
  const FeeBumpTransactionEnvelope &feeBump() const {
    if (_xdr_field_number(type_) == 3)
      return feeBump_;
    throw xdr::xdr_wrong_union("TransactionEnvelope: feeBump accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionEnvelope> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TransactionEnvelope;
  using case_type = ::stellar::TransactionEnvelope::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v0";
    case 2:
      return "v1";
    case 3:
      return "feeBump";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TransactionEnvelope &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in TransactionEnvelope");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionEnvelope &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in TransactionEnvelope");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionEnvelope &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TransactionSignaturePayload {
  struct _taggedTransaction_t {
    using _xdr_case_type = xdr::xdr_traits<EnvelopeType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      Transaction tx_;
      FeeBumpTransaction feeBump_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<EnvelopeType> &_xdr_case_values() {
      static const std::vector<EnvelopeType> _xdr_disc_vec {
        ENVELOPE_TYPE_TX,
        ENVELOPE_TYPE_TX_FEE_BUMP
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == ENVELOPE_TYPE_TX ? 1
        : which == ENVELOPE_TYPE_TX_FEE_BUMP ? 2
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case ENVELOPE_TYPE_TX:
        _f(&_taggedTransaction_t::tx_, std::forward<_A>(_a)...);
        return true;
      case ENVELOPE_TYPE_TX_FEE_BUMP:
        _f(&_taggedTransaction_t::feeBump_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _taggedTransaction_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_taggedTransaction_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _taggedTransaction_t(EnvelopeType which = EnvelopeType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _taggedTransaction_t(const _taggedTransaction_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _taggedTransaction_t(_taggedTransaction_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_taggedTransaction_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _taggedTransaction_t &operator=(const _taggedTransaction_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_taggedTransaction_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _taggedTransaction_t &operator=(_taggedTransaction_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_taggedTransaction_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    EnvelopeType type() const { return EnvelopeType(type_); }
    _taggedTransaction_t &type(EnvelopeType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    Transaction &tx() {
      if (_xdr_field_number(type_) == 1)
        return tx_;
      throw xdr::xdr_wrong_union("_taggedTransaction_t: tx accessed when not selected");
    }
    const Transaction &tx() const {
      if (_xdr_field_number(type_) == 1)
        return tx_;
      throw xdr::xdr_wrong_union("_taggedTransaction_t: tx accessed when not selected");
    }
    FeeBumpTransaction &feeBump() {
      if (_xdr_field_number(type_) == 2)
        return feeBump_;
      throw xdr::xdr_wrong_union("_taggedTransaction_t: feeBump accessed when not selected");
    }
    const FeeBumpTransaction &feeBump() const {
      if (_xdr_field_number(type_) == 2)
        return feeBump_;
      throw xdr::xdr_wrong_union("_taggedTransaction_t: feeBump accessed when not selected");
    }
  };

  Hash networkId{};
  _taggedTransaction_t taggedTransaction{};

  TransactionSignaturePayload() = default;
  template<typename _networkId_T,
           typename _taggedTransaction_T,
           typename = typename
           std::enable_if<std::is_constructible<Hash, _networkId_T>::value
                          && std::is_constructible<_taggedTransaction_t, _taggedTransaction_T>::value
                         >::type>
  explicit TransactionSignaturePayload(_networkId_T &&_networkId,
                                       _taggedTransaction_T &&_taggedTransaction)
    : networkId(std::forward<_networkId_T>(_networkId)),
      taggedTransaction(std::forward<_taggedTransaction_T>(_taggedTransaction)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionSignaturePayload::_taggedTransaction_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TransactionSignaturePayload::_taggedTransaction_t;
  using case_type = ::stellar::TransactionSignaturePayload::_taggedTransaction_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "tx";
    case 2:
      return "feeBump";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TransactionSignaturePayload::_taggedTransaction_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _taggedTransaction_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionSignaturePayload::_taggedTransaction_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _taggedTransaction_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionSignaturePayload::_taggedTransaction_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TransactionSignaturePayload>
  : xdr_struct_base<field_ptr<::stellar::TransactionSignaturePayload,
                              decltype(::stellar::TransactionSignaturePayload::networkId),
                              &::stellar::TransactionSignaturePayload::networkId>,
                    field_ptr<::stellar::TransactionSignaturePayload,
                              decltype(::stellar::TransactionSignaturePayload::taggedTransaction),
                              &::stellar::TransactionSignaturePayload::taggedTransaction>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionSignaturePayload &obj) {
    archive(ar, obj.networkId, "networkId");
    archive(ar, obj.taggedTransaction, "taggedTransaction");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionSignaturePayload &obj) {
    archive(ar, obj.networkId, "networkId");
    archive(ar, obj.taggedTransaction, "taggedTransaction");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ClaimOfferAtom {
  AccountID sellerID{};
  int64 offerID{};
  Asset assetSold{};
  int64 amountSold{};
  Asset assetBought{};
  int64 amountBought{};

  ClaimOfferAtom() = default;
  template<typename _sellerID_T,
           typename _offerID_T,
           typename _assetSold_T,
           typename _amountSold_T,
           typename _assetBought_T,
           typename _amountBought_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _sellerID_T>::value
                          && std::is_constructible<int64, _offerID_T>::value
                          && std::is_constructible<Asset, _assetSold_T>::value
                          && std::is_constructible<int64, _amountSold_T>::value
                          && std::is_constructible<Asset, _assetBought_T>::value
                          && std::is_constructible<int64, _amountBought_T>::value
                         >::type>
  explicit ClaimOfferAtom(_sellerID_T &&_sellerID,
                          _offerID_T &&_offerID,
                          _assetSold_T &&_assetSold,
                          _amountSold_T &&_amountSold,
                          _assetBought_T &&_assetBought,
                          _amountBought_T &&_amountBought)
    : sellerID(std::forward<_sellerID_T>(_sellerID)),
      offerID(std::forward<_offerID_T>(_offerID)),
      assetSold(std::forward<_assetSold_T>(_assetSold)),
      amountSold(std::forward<_amountSold_T>(_amountSold)),
      assetBought(std::forward<_assetBought_T>(_assetBought)),
      amountBought(std::forward<_amountBought_T>(_amountBought)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimOfferAtom>
  : xdr_struct_base<field_ptr<::stellar::ClaimOfferAtom,
                              decltype(::stellar::ClaimOfferAtom::sellerID),
                              &::stellar::ClaimOfferAtom::sellerID>,
                    field_ptr<::stellar::ClaimOfferAtom,
                              decltype(::stellar::ClaimOfferAtom::offerID),
                              &::stellar::ClaimOfferAtom::offerID>,
                    field_ptr<::stellar::ClaimOfferAtom,
                              decltype(::stellar::ClaimOfferAtom::assetSold),
                              &::stellar::ClaimOfferAtom::assetSold>,
                    field_ptr<::stellar::ClaimOfferAtom,
                              decltype(::stellar::ClaimOfferAtom::amountSold),
                              &::stellar::ClaimOfferAtom::amountSold>,
                    field_ptr<::stellar::ClaimOfferAtom,
                              decltype(::stellar::ClaimOfferAtom::assetBought),
                              &::stellar::ClaimOfferAtom::assetBought>,
                    field_ptr<::stellar::ClaimOfferAtom,
                              decltype(::stellar::ClaimOfferAtom::amountBought),
                              &::stellar::ClaimOfferAtom::amountBought>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimOfferAtom &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    archive(ar, obj.assetSold, "assetSold");
    archive(ar, obj.amountSold, "amountSold");
    archive(ar, obj.assetBought, "assetBought");
    archive(ar, obj.amountBought, "amountBought");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimOfferAtom &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    archive(ar, obj.assetSold, "assetSold");
    archive(ar, obj.amountSold, "amountSold");
    archive(ar, obj.assetBought, "assetBought");
    archive(ar, obj.amountBought, "amountBought");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum CreateAccountResultCode : std::int32_t {
  CREATE_ACCOUNT_SUCCESS = 0,
  CREATE_ACCOUNT_MALFORMED = -1,
  CREATE_ACCOUNT_UNDERFUNDED = -2,
  CREATE_ACCOUNT_LOW_RESERVE = -3,
  CREATE_ACCOUNT_ALREADY_EXIST = -4,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::CreateAccountResultCode>
  : xdr_integral_base<::stellar::CreateAccountResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::CreateAccountResultCode val) {
    switch (val) {
    case ::stellar::CREATE_ACCOUNT_SUCCESS:
      return "CREATE_ACCOUNT_SUCCESS";
    case ::stellar::CREATE_ACCOUNT_MALFORMED:
      return "CREATE_ACCOUNT_MALFORMED";
    case ::stellar::CREATE_ACCOUNT_UNDERFUNDED:
      return "CREATE_ACCOUNT_UNDERFUNDED";
    case ::stellar::CREATE_ACCOUNT_LOW_RESERVE:
      return "CREATE_ACCOUNT_LOW_RESERVE";
    case ::stellar::CREATE_ACCOUNT_ALREADY_EXIST:
      return "CREATE_ACCOUNT_ALREADY_EXIST";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CREATE_ACCOUNT_SUCCESS,
      ::stellar::CREATE_ACCOUNT_MALFORMED,
      ::stellar::CREATE_ACCOUNT_UNDERFUNDED,
      ::stellar::CREATE_ACCOUNT_LOW_RESERVE,
      ::stellar::CREATE_ACCOUNT_ALREADY_EXIST
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct CreateAccountResult {
  using _xdr_case_type = xdr::xdr_traits<CreateAccountResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<CreateAccountResultCode> &_xdr_case_values() {
    static const std::vector<CreateAccountResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == CREATE_ACCOUNT_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case CREATE_ACCOUNT_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in CreateAccountResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~CreateAccountResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit CreateAccountResult(CreateAccountResultCode which = CreateAccountResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  CreateAccountResult(const CreateAccountResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  CreateAccountResult(CreateAccountResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~CreateAccountResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  CreateAccountResult &operator=(const CreateAccountResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~CreateAccountResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  CreateAccountResult &operator=(CreateAccountResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~CreateAccountResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  CreateAccountResultCode code() const { return CreateAccountResultCode(code_); }
  CreateAccountResult &code(CreateAccountResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::CreateAccountResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::CreateAccountResult;
  using case_type = ::stellar::CreateAccountResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::CreateAccountResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in CreateAccountResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::CreateAccountResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in CreateAccountResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::CreateAccountResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum PaymentResultCode : std::int32_t {
  PAYMENT_SUCCESS = 0,
  PAYMENT_MALFORMED = -1,
  PAYMENT_UNDERFUNDED = -2,
  PAYMENT_SRC_NO_TRUST = -3,
  PAYMENT_SRC_NOT_AUTHORIZED = -4,
  PAYMENT_NO_DESTINATION = -5,
  PAYMENT_NO_TRUST = -6,
  PAYMENT_NOT_AUTHORIZED = -7,
  PAYMENT_LINE_FULL = -8,
  PAYMENT_NO_ISSUER = -9,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PaymentResultCode>
  : xdr_integral_base<::stellar::PaymentResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::PaymentResultCode val) {
    switch (val) {
    case ::stellar::PAYMENT_SUCCESS:
      return "PAYMENT_SUCCESS";
    case ::stellar::PAYMENT_MALFORMED:
      return "PAYMENT_MALFORMED";
    case ::stellar::PAYMENT_UNDERFUNDED:
      return "PAYMENT_UNDERFUNDED";
    case ::stellar::PAYMENT_SRC_NO_TRUST:
      return "PAYMENT_SRC_NO_TRUST";
    case ::stellar::PAYMENT_SRC_NOT_AUTHORIZED:
      return "PAYMENT_SRC_NOT_AUTHORIZED";
    case ::stellar::PAYMENT_NO_DESTINATION:
      return "PAYMENT_NO_DESTINATION";
    case ::stellar::PAYMENT_NO_TRUST:
      return "PAYMENT_NO_TRUST";
    case ::stellar::PAYMENT_NOT_AUTHORIZED:
      return "PAYMENT_NOT_AUTHORIZED";
    case ::stellar::PAYMENT_LINE_FULL:
      return "PAYMENT_LINE_FULL";
    case ::stellar::PAYMENT_NO_ISSUER:
      return "PAYMENT_NO_ISSUER";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::PAYMENT_SUCCESS,
      ::stellar::PAYMENT_MALFORMED,
      ::stellar::PAYMENT_UNDERFUNDED,
      ::stellar::PAYMENT_SRC_NO_TRUST,
      ::stellar::PAYMENT_SRC_NOT_AUTHORIZED,
      ::stellar::PAYMENT_NO_DESTINATION,
      ::stellar::PAYMENT_NO_TRUST,
      ::stellar::PAYMENT_NOT_AUTHORIZED,
      ::stellar::PAYMENT_LINE_FULL,
      ::stellar::PAYMENT_NO_ISSUER
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct PaymentResult {
  using _xdr_case_type = xdr::xdr_traits<PaymentResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<PaymentResultCode> &_xdr_case_values() {
    static const std::vector<PaymentResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == PAYMENT_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case PAYMENT_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in PaymentResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~PaymentResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit PaymentResult(PaymentResultCode which = PaymentResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  PaymentResult(const PaymentResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  PaymentResult(PaymentResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~PaymentResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  PaymentResult &operator=(const PaymentResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~PaymentResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  PaymentResult &operator=(PaymentResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~PaymentResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  PaymentResultCode code() const { return PaymentResultCode(code_); }
  PaymentResult &code(PaymentResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::PaymentResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::PaymentResult;
  using case_type = ::stellar::PaymentResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::PaymentResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in PaymentResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PaymentResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in PaymentResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PaymentResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum PathPaymentStrictReceiveResultCode : std::int32_t {
  PATH_PAYMENT_STRICT_RECEIVE_SUCCESS = 0,
  PATH_PAYMENT_STRICT_RECEIVE_MALFORMED = -1,
  PATH_PAYMENT_STRICT_RECEIVE_UNDERFUNDED = -2,
  PATH_PAYMENT_STRICT_RECEIVE_SRC_NO_TRUST = -3,
  PATH_PAYMENT_STRICT_RECEIVE_SRC_NOT_AUTHORIZED = -4,
  PATH_PAYMENT_STRICT_RECEIVE_NO_DESTINATION = -5,
  PATH_PAYMENT_STRICT_RECEIVE_NO_TRUST = -6,
  PATH_PAYMENT_STRICT_RECEIVE_NOT_AUTHORIZED = -7,
  PATH_PAYMENT_STRICT_RECEIVE_LINE_FULL = -8,
  PATH_PAYMENT_STRICT_RECEIVE_NO_ISSUER = -9,
  PATH_PAYMENT_STRICT_RECEIVE_TOO_FEW_OFFERS = -10,
  PATH_PAYMENT_STRICT_RECEIVE_OFFER_CROSS_SELF = -11,
  PATH_PAYMENT_STRICT_RECEIVE_OVER_SENDMAX = -12,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PathPaymentStrictReceiveResultCode>
  : xdr_integral_base<::stellar::PathPaymentStrictReceiveResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::PathPaymentStrictReceiveResultCode val) {
    switch (val) {
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_SUCCESS:
      return "PATH_PAYMENT_STRICT_RECEIVE_SUCCESS";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_MALFORMED:
      return "PATH_PAYMENT_STRICT_RECEIVE_MALFORMED";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_UNDERFUNDED:
      return "PATH_PAYMENT_STRICT_RECEIVE_UNDERFUNDED";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_SRC_NO_TRUST:
      return "PATH_PAYMENT_STRICT_RECEIVE_SRC_NO_TRUST";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_SRC_NOT_AUTHORIZED:
      return "PATH_PAYMENT_STRICT_RECEIVE_SRC_NOT_AUTHORIZED";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NO_DESTINATION:
      return "PATH_PAYMENT_STRICT_RECEIVE_NO_DESTINATION";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NO_TRUST:
      return "PATH_PAYMENT_STRICT_RECEIVE_NO_TRUST";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NOT_AUTHORIZED:
      return "PATH_PAYMENT_STRICT_RECEIVE_NOT_AUTHORIZED";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_LINE_FULL:
      return "PATH_PAYMENT_STRICT_RECEIVE_LINE_FULL";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NO_ISSUER:
      return "PATH_PAYMENT_STRICT_RECEIVE_NO_ISSUER";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_TOO_FEW_OFFERS:
      return "PATH_PAYMENT_STRICT_RECEIVE_TOO_FEW_OFFERS";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_OFFER_CROSS_SELF:
      return "PATH_PAYMENT_STRICT_RECEIVE_OFFER_CROSS_SELF";
    case ::stellar::PATH_PAYMENT_STRICT_RECEIVE_OVER_SENDMAX:
      return "PATH_PAYMENT_STRICT_RECEIVE_OVER_SENDMAX";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_SUCCESS,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_MALFORMED,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_UNDERFUNDED,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_SRC_NO_TRUST,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_SRC_NOT_AUTHORIZED,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NO_DESTINATION,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NO_TRUST,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NOT_AUTHORIZED,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_LINE_FULL,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_NO_ISSUER,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_TOO_FEW_OFFERS,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_OFFER_CROSS_SELF,
      ::stellar::PATH_PAYMENT_STRICT_RECEIVE_OVER_SENDMAX
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct SimplePaymentResult {
  AccountID destination{};
  Asset asset{};
  int64 amount{};

  SimplePaymentResult() = default;
  template<typename _destination_T,
           typename _asset_T,
           typename _amount_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _destination_T>::value
                          && std::is_constructible<Asset, _asset_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                         >::type>
  explicit SimplePaymentResult(_destination_T &&_destination,
                               _asset_T &&_asset,
                               _amount_T &&_amount)
    : destination(std::forward<_destination_T>(_destination)),
      asset(std::forward<_asset_T>(_asset)),
      amount(std::forward<_amount_T>(_amount)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SimplePaymentResult>
  : xdr_struct_base<field_ptr<::stellar::SimplePaymentResult,
                              decltype(::stellar::SimplePaymentResult::destination),
                              &::stellar::SimplePaymentResult::destination>,
                    field_ptr<::stellar::SimplePaymentResult,
                              decltype(::stellar::SimplePaymentResult::asset),
                              &::stellar::SimplePaymentResult::asset>,
                    field_ptr<::stellar::SimplePaymentResult,
                              decltype(::stellar::SimplePaymentResult::amount),
                              &::stellar::SimplePaymentResult::amount>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SimplePaymentResult &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.amount, "amount");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SimplePaymentResult &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.amount, "amount");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct PathPaymentStrictReceiveResult {
  struct _success_t {
    xdr::xvector<ClaimOfferAtom> offers{};
    SimplePaymentResult last{};

    _success_t() = default;
    template<typename _offers_T,
             typename _last_T,
             typename = typename
             std::enable_if<std::is_constructible<xdr::xvector<ClaimOfferAtom>, _offers_T>::value
                            && std::is_constructible<SimplePaymentResult, _last_T>::value
                           >::type>
    explicit _success_t(_offers_T &&_offers,
                        _last_T &&_last)
      : offers(std::forward<_offers_T>(_offers)),
        last(std::forward<_last_T>(_last)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<PathPaymentStrictReceiveResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    _success_t success_;
    Asset noIssuer_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<PathPaymentStrictReceiveResultCode> &_xdr_case_values() {
    static const std::vector<PathPaymentStrictReceiveResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == PATH_PAYMENT_STRICT_RECEIVE_SUCCESS ? 1
      : which == PATH_PAYMENT_STRICT_RECEIVE_NO_ISSUER ? 2
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case PATH_PAYMENT_STRICT_RECEIVE_SUCCESS:
      _f(&PathPaymentStrictReceiveResult::success_, std::forward<_A>(_a)...);
      return true;
    case PATH_PAYMENT_STRICT_RECEIVE_NO_ISSUER:
      _f(&PathPaymentStrictReceiveResult::noIssuer_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in PathPaymentStrictReceiveResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~PathPaymentStrictReceiveResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit PathPaymentStrictReceiveResult(PathPaymentStrictReceiveResultCode which = PathPaymentStrictReceiveResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  PathPaymentStrictReceiveResult(const PathPaymentStrictReceiveResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  PathPaymentStrictReceiveResult(PathPaymentStrictReceiveResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~PathPaymentStrictReceiveResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  PathPaymentStrictReceiveResult &operator=(const PathPaymentStrictReceiveResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~PathPaymentStrictReceiveResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  PathPaymentStrictReceiveResult &operator=(PathPaymentStrictReceiveResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~PathPaymentStrictReceiveResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  PathPaymentStrictReceiveResultCode code() const { return PathPaymentStrictReceiveResultCode(code_); }
  PathPaymentStrictReceiveResult &code(PathPaymentStrictReceiveResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _success_t &success() {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("PathPaymentStrictReceiveResult: success accessed when not selected");
  }
  const _success_t &success() const {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("PathPaymentStrictReceiveResult: success accessed when not selected");
  }
  Asset &noIssuer() {
    if (_xdr_field_number(code_) == 2)
      return noIssuer_;
    throw xdr::xdr_wrong_union("PathPaymentStrictReceiveResult: noIssuer accessed when not selected");
  }
  const Asset &noIssuer() const {
    if (_xdr_field_number(code_) == 2)
      return noIssuer_;
    throw xdr::xdr_wrong_union("PathPaymentStrictReceiveResult: noIssuer accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PathPaymentStrictReceiveResult::_success_t>
  : xdr_struct_base<field_ptr<::stellar::PathPaymentStrictReceiveResult::_success_t,
                              decltype(::stellar::PathPaymentStrictReceiveResult::_success_t::offers),
                              &::stellar::PathPaymentStrictReceiveResult::_success_t::offers>,
                    field_ptr<::stellar::PathPaymentStrictReceiveResult::_success_t,
                              decltype(::stellar::PathPaymentStrictReceiveResult::_success_t::last),
                              &::stellar::PathPaymentStrictReceiveResult::_success_t::last>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PathPaymentStrictReceiveResult::_success_t &obj) {
    archive(ar, obj.offers, "offers");
    archive(ar, obj.last, "last");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PathPaymentStrictReceiveResult::_success_t &obj) {
    archive(ar, obj.offers, "offers");
    archive(ar, obj.last, "last");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::PathPaymentStrictReceiveResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::PathPaymentStrictReceiveResult;
  using case_type = ::stellar::PathPaymentStrictReceiveResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "success";
    case 2:
      return "noIssuer";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::PathPaymentStrictReceiveResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in PathPaymentStrictReceiveResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PathPaymentStrictReceiveResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in PathPaymentStrictReceiveResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PathPaymentStrictReceiveResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum PathPaymentStrictSendResultCode : std::int32_t {
  PATH_PAYMENT_STRICT_SEND_SUCCESS = 0,
  PATH_PAYMENT_STRICT_SEND_MALFORMED = -1,
  PATH_PAYMENT_STRICT_SEND_UNDERFUNDED = -2,
  PATH_PAYMENT_STRICT_SEND_SRC_NO_TRUST = -3,
  PATH_PAYMENT_STRICT_SEND_SRC_NOT_AUTHORIZED = -4,
  PATH_PAYMENT_STRICT_SEND_NO_DESTINATION = -5,
  PATH_PAYMENT_STRICT_SEND_NO_TRUST = -6,
  PATH_PAYMENT_STRICT_SEND_NOT_AUTHORIZED = -7,
  PATH_PAYMENT_STRICT_SEND_LINE_FULL = -8,
  PATH_PAYMENT_STRICT_SEND_NO_ISSUER = -9,
  PATH_PAYMENT_STRICT_SEND_TOO_FEW_OFFERS = -10,
  PATH_PAYMENT_STRICT_SEND_OFFER_CROSS_SELF = -11,
  PATH_PAYMENT_STRICT_SEND_UNDER_DESTMIN = -12,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PathPaymentStrictSendResultCode>
  : xdr_integral_base<::stellar::PathPaymentStrictSendResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::PathPaymentStrictSendResultCode val) {
    switch (val) {
    case ::stellar::PATH_PAYMENT_STRICT_SEND_SUCCESS:
      return "PATH_PAYMENT_STRICT_SEND_SUCCESS";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_MALFORMED:
      return "PATH_PAYMENT_STRICT_SEND_MALFORMED";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_UNDERFUNDED:
      return "PATH_PAYMENT_STRICT_SEND_UNDERFUNDED";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_SRC_NO_TRUST:
      return "PATH_PAYMENT_STRICT_SEND_SRC_NO_TRUST";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_SRC_NOT_AUTHORIZED:
      return "PATH_PAYMENT_STRICT_SEND_SRC_NOT_AUTHORIZED";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_NO_DESTINATION:
      return "PATH_PAYMENT_STRICT_SEND_NO_DESTINATION";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_NO_TRUST:
      return "PATH_PAYMENT_STRICT_SEND_NO_TRUST";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_NOT_AUTHORIZED:
      return "PATH_PAYMENT_STRICT_SEND_NOT_AUTHORIZED";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_LINE_FULL:
      return "PATH_PAYMENT_STRICT_SEND_LINE_FULL";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_NO_ISSUER:
      return "PATH_PAYMENT_STRICT_SEND_NO_ISSUER";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_TOO_FEW_OFFERS:
      return "PATH_PAYMENT_STRICT_SEND_TOO_FEW_OFFERS";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_OFFER_CROSS_SELF:
      return "PATH_PAYMENT_STRICT_SEND_OFFER_CROSS_SELF";
    case ::stellar::PATH_PAYMENT_STRICT_SEND_UNDER_DESTMIN:
      return "PATH_PAYMENT_STRICT_SEND_UNDER_DESTMIN";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::PATH_PAYMENT_STRICT_SEND_SUCCESS,
      ::stellar::PATH_PAYMENT_STRICT_SEND_MALFORMED,
      ::stellar::PATH_PAYMENT_STRICT_SEND_UNDERFUNDED,
      ::stellar::PATH_PAYMENT_STRICT_SEND_SRC_NO_TRUST,
      ::stellar::PATH_PAYMENT_STRICT_SEND_SRC_NOT_AUTHORIZED,
      ::stellar::PATH_PAYMENT_STRICT_SEND_NO_DESTINATION,
      ::stellar::PATH_PAYMENT_STRICT_SEND_NO_TRUST,
      ::stellar::PATH_PAYMENT_STRICT_SEND_NOT_AUTHORIZED,
      ::stellar::PATH_PAYMENT_STRICT_SEND_LINE_FULL,
      ::stellar::PATH_PAYMENT_STRICT_SEND_NO_ISSUER,
      ::stellar::PATH_PAYMENT_STRICT_SEND_TOO_FEW_OFFERS,
      ::stellar::PATH_PAYMENT_STRICT_SEND_OFFER_CROSS_SELF,
      ::stellar::PATH_PAYMENT_STRICT_SEND_UNDER_DESTMIN
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct PathPaymentStrictSendResult {
  struct _success_t {
    xdr::xvector<ClaimOfferAtom> offers{};
    SimplePaymentResult last{};

    _success_t() = default;
    template<typename _offers_T,
             typename _last_T,
             typename = typename
             std::enable_if<std::is_constructible<xdr::xvector<ClaimOfferAtom>, _offers_T>::value
                            && std::is_constructible<SimplePaymentResult, _last_T>::value
                           >::type>
    explicit _success_t(_offers_T &&_offers,
                        _last_T &&_last)
      : offers(std::forward<_offers_T>(_offers)),
        last(std::forward<_last_T>(_last)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<PathPaymentStrictSendResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    _success_t success_;
    Asset noIssuer_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<PathPaymentStrictSendResultCode> &_xdr_case_values() {
    static const std::vector<PathPaymentStrictSendResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == PATH_PAYMENT_STRICT_SEND_SUCCESS ? 1
      : which == PATH_PAYMENT_STRICT_SEND_NO_ISSUER ? 2
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case PATH_PAYMENT_STRICT_SEND_SUCCESS:
      _f(&PathPaymentStrictSendResult::success_, std::forward<_A>(_a)...);
      return true;
    case PATH_PAYMENT_STRICT_SEND_NO_ISSUER:
      _f(&PathPaymentStrictSendResult::noIssuer_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in PathPaymentStrictSendResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~PathPaymentStrictSendResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit PathPaymentStrictSendResult(PathPaymentStrictSendResultCode which = PathPaymentStrictSendResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  PathPaymentStrictSendResult(const PathPaymentStrictSendResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  PathPaymentStrictSendResult(PathPaymentStrictSendResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~PathPaymentStrictSendResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  PathPaymentStrictSendResult &operator=(const PathPaymentStrictSendResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~PathPaymentStrictSendResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  PathPaymentStrictSendResult &operator=(PathPaymentStrictSendResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~PathPaymentStrictSendResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  PathPaymentStrictSendResultCode code() const { return PathPaymentStrictSendResultCode(code_); }
  PathPaymentStrictSendResult &code(PathPaymentStrictSendResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _success_t &success() {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("PathPaymentStrictSendResult: success accessed when not selected");
  }
  const _success_t &success() const {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("PathPaymentStrictSendResult: success accessed when not selected");
  }
  Asset &noIssuer() {
    if (_xdr_field_number(code_) == 2)
      return noIssuer_;
    throw xdr::xdr_wrong_union("PathPaymentStrictSendResult: noIssuer accessed when not selected");
  }
  const Asset &noIssuer() const {
    if (_xdr_field_number(code_) == 2)
      return noIssuer_;
    throw xdr::xdr_wrong_union("PathPaymentStrictSendResult: noIssuer accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::PathPaymentStrictSendResult::_success_t>
  : xdr_struct_base<field_ptr<::stellar::PathPaymentStrictSendResult::_success_t,
                              decltype(::stellar::PathPaymentStrictSendResult::_success_t::offers),
                              &::stellar::PathPaymentStrictSendResult::_success_t::offers>,
                    field_ptr<::stellar::PathPaymentStrictSendResult::_success_t,
                              decltype(::stellar::PathPaymentStrictSendResult::_success_t::last),
                              &::stellar::PathPaymentStrictSendResult::_success_t::last>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PathPaymentStrictSendResult::_success_t &obj) {
    archive(ar, obj.offers, "offers");
    archive(ar, obj.last, "last");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PathPaymentStrictSendResult::_success_t &obj) {
    archive(ar, obj.offers, "offers");
    archive(ar, obj.last, "last");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::PathPaymentStrictSendResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::PathPaymentStrictSendResult;
  using case_type = ::stellar::PathPaymentStrictSendResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "success";
    case 2:
      return "noIssuer";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::PathPaymentStrictSendResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in PathPaymentStrictSendResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::PathPaymentStrictSendResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in PathPaymentStrictSendResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::PathPaymentStrictSendResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ManageSellOfferResultCode : std::int32_t {
  MANAGE_SELL_OFFER_SUCCESS = 0,
  MANAGE_SELL_OFFER_MALFORMED = -1,
  MANAGE_SELL_OFFER_SELL_NO_TRUST = -2,
  MANAGE_SELL_OFFER_BUY_NO_TRUST = -3,
  MANAGE_SELL_OFFER_SELL_NOT_AUTHORIZED = -4,
  MANAGE_SELL_OFFER_BUY_NOT_AUTHORIZED = -5,
  MANAGE_SELL_OFFER_LINE_FULL = -6,
  MANAGE_SELL_OFFER_UNDERFUNDED = -7,
  MANAGE_SELL_OFFER_CROSS_SELF = -8,
  MANAGE_SELL_OFFER_SELL_NO_ISSUER = -9,
  MANAGE_SELL_OFFER_BUY_NO_ISSUER = -10,
  MANAGE_SELL_OFFER_NOT_FOUND = -11,
  MANAGE_SELL_OFFER_LOW_RESERVE = -12,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageSellOfferResultCode>
  : xdr_integral_base<::stellar::ManageSellOfferResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ManageSellOfferResultCode val) {
    switch (val) {
    case ::stellar::MANAGE_SELL_OFFER_SUCCESS:
      return "MANAGE_SELL_OFFER_SUCCESS";
    case ::stellar::MANAGE_SELL_OFFER_MALFORMED:
      return "MANAGE_SELL_OFFER_MALFORMED";
    case ::stellar::MANAGE_SELL_OFFER_SELL_NO_TRUST:
      return "MANAGE_SELL_OFFER_SELL_NO_TRUST";
    case ::stellar::MANAGE_SELL_OFFER_BUY_NO_TRUST:
      return "MANAGE_SELL_OFFER_BUY_NO_TRUST";
    case ::stellar::MANAGE_SELL_OFFER_SELL_NOT_AUTHORIZED:
      return "MANAGE_SELL_OFFER_SELL_NOT_AUTHORIZED";
    case ::stellar::MANAGE_SELL_OFFER_BUY_NOT_AUTHORIZED:
      return "MANAGE_SELL_OFFER_BUY_NOT_AUTHORIZED";
    case ::stellar::MANAGE_SELL_OFFER_LINE_FULL:
      return "MANAGE_SELL_OFFER_LINE_FULL";
    case ::stellar::MANAGE_SELL_OFFER_UNDERFUNDED:
      return "MANAGE_SELL_OFFER_UNDERFUNDED";
    case ::stellar::MANAGE_SELL_OFFER_CROSS_SELF:
      return "MANAGE_SELL_OFFER_CROSS_SELF";
    case ::stellar::MANAGE_SELL_OFFER_SELL_NO_ISSUER:
      return "MANAGE_SELL_OFFER_SELL_NO_ISSUER";
    case ::stellar::MANAGE_SELL_OFFER_BUY_NO_ISSUER:
      return "MANAGE_SELL_OFFER_BUY_NO_ISSUER";
    case ::stellar::MANAGE_SELL_OFFER_NOT_FOUND:
      return "MANAGE_SELL_OFFER_NOT_FOUND";
    case ::stellar::MANAGE_SELL_OFFER_LOW_RESERVE:
      return "MANAGE_SELL_OFFER_LOW_RESERVE";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::MANAGE_SELL_OFFER_SUCCESS,
      ::stellar::MANAGE_SELL_OFFER_MALFORMED,
      ::stellar::MANAGE_SELL_OFFER_SELL_NO_TRUST,
      ::stellar::MANAGE_SELL_OFFER_BUY_NO_TRUST,
      ::stellar::MANAGE_SELL_OFFER_SELL_NOT_AUTHORIZED,
      ::stellar::MANAGE_SELL_OFFER_BUY_NOT_AUTHORIZED,
      ::stellar::MANAGE_SELL_OFFER_LINE_FULL,
      ::stellar::MANAGE_SELL_OFFER_UNDERFUNDED,
      ::stellar::MANAGE_SELL_OFFER_CROSS_SELF,
      ::stellar::MANAGE_SELL_OFFER_SELL_NO_ISSUER,
      ::stellar::MANAGE_SELL_OFFER_BUY_NO_ISSUER,
      ::stellar::MANAGE_SELL_OFFER_NOT_FOUND,
      ::stellar::MANAGE_SELL_OFFER_LOW_RESERVE
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

enum ManageOfferEffect : std::int32_t {
  MANAGE_OFFER_CREATED = 0,
  MANAGE_OFFER_UPDATED = 1,
  MANAGE_OFFER_DELETED = 2,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageOfferEffect>
  : xdr_integral_base<::stellar::ManageOfferEffect, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ManageOfferEffect val) {
    switch (val) {
    case ::stellar::MANAGE_OFFER_CREATED:
      return "MANAGE_OFFER_CREATED";
    case ::stellar::MANAGE_OFFER_UPDATED:
      return "MANAGE_OFFER_UPDATED";
    case ::stellar::MANAGE_OFFER_DELETED:
      return "MANAGE_OFFER_DELETED";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::MANAGE_OFFER_CREATED,
      ::stellar::MANAGE_OFFER_UPDATED,
      ::stellar::MANAGE_OFFER_DELETED
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct ManageOfferSuccessResult {
  struct _offer_t {
    using _xdr_case_type = xdr::xdr_traits<ManageOfferEffect>::case_type;
  private:
    _xdr_case_type effect_;
    union {
      OfferEntry offer_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = true;
    static const std::vector<ManageOfferEffect> &_xdr_case_values() {
      static const std::vector<ManageOfferEffect> _xdr_disc_vec {};
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == MANAGE_OFFER_CREATED || which == MANAGE_OFFER_UPDATED ? 1
        : 0;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case MANAGE_OFFER_CREATED:
      case MANAGE_OFFER_UPDATED:
        _f(&_offer_t::offer_, std::forward<_A>(_a)...);
        return true;
      default:
        return true;
      }
    }

    _xdr_case_type _xdr_discriminant() const { return effect_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of effect in _offer_t");
      if (fnum != _xdr_field_number(effect_)) {
        this->~_offer_t();
        effect_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, effect_, *this);
      }
      else
        effect_ = which;
    }
    explicit _offer_t(ManageOfferEffect which = ManageOfferEffect{}) : effect_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, effect_, *this);
    }
    _offer_t(const _offer_t &source) : effect_(source.effect_) {
      _xdr_with_mem_ptr(xdr::field_constructor, effect_, *this, source);
    }
    _offer_t(_offer_t &&source) : effect_(source.effect_) {
      _xdr_with_mem_ptr(xdr::field_constructor, effect_, *this,
                        std::move(source));
    }
    ~_offer_t() { _xdr_with_mem_ptr(xdr::field_destructor, effect_, *this); }
    _offer_t &operator=(const _offer_t &source) {
      if (_xdr_field_number(effect_)
          == _xdr_field_number(source.effect_))
        _xdr_with_mem_ptr(xdr::field_assigner, effect_, *this, source);
      else {
        this->~_offer_t();
        effect_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.effect_, *this, source);
      }
      effect_ = source.effect_;
      return *this;
    }
    _offer_t &operator=(_offer_t &&source) {
      if (_xdr_field_number(effect_)
           == _xdr_field_number(source.effect_))
        _xdr_with_mem_ptr(xdr::field_assigner, effect_, *this,
                          std::move(source));
      else {
        this->~_offer_t();
        effect_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.effect_, *this,
                          std::move(source));
      }
      effect_ = source.effect_;
      return *this;
    }

    ManageOfferEffect effect() const { return ManageOfferEffect(effect_); }
    _offer_t &effect(ManageOfferEffect _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    OfferEntry &offer() {
      if (_xdr_field_number(effect_) == 1)
        return offer_;
      throw xdr::xdr_wrong_union("_offer_t: offer accessed when not selected");
    }
    const OfferEntry &offer() const {
      if (_xdr_field_number(effect_) == 1)
        return offer_;
      throw xdr::xdr_wrong_union("_offer_t: offer accessed when not selected");
    }
  };

  xdr::xvector<ClaimOfferAtom> offersClaimed{};
  _offer_t offer{};

  ManageOfferSuccessResult() = default;
  template<typename _offersClaimed_T,
           typename _offer_T,
           typename = typename
           std::enable_if<std::is_constructible<xdr::xvector<ClaimOfferAtom>, _offersClaimed_T>::value
                          && std::is_constructible<_offer_t, _offer_T>::value
                         >::type>
  explicit ManageOfferSuccessResult(_offersClaimed_T &&_offersClaimed,
                                    _offer_T &&_offer)
    : offersClaimed(std::forward<_offersClaimed_T>(_offersClaimed)),
      offer(std::forward<_offer_T>(_offer)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageOfferSuccessResult::_offer_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ManageOfferSuccessResult::_offer_t;
  using case_type = ::stellar::ManageOfferSuccessResult::_offer_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().effect());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "offer";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ManageOfferSuccessResult::_offer_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of effect in _offer_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageOfferSuccessResult::_offer_t &obj) {
    xdr::archive(ar, obj.effect(), "effect");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.effect(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of effect in _offer_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageOfferSuccessResult::_offer_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "effect");
    obj.effect(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.effect(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::ManageOfferSuccessResult>
  : xdr_struct_base<field_ptr<::stellar::ManageOfferSuccessResult,
                              decltype(::stellar::ManageOfferSuccessResult::offersClaimed),
                              &::stellar::ManageOfferSuccessResult::offersClaimed>,
                    field_ptr<::stellar::ManageOfferSuccessResult,
                              decltype(::stellar::ManageOfferSuccessResult::offer),
                              &::stellar::ManageOfferSuccessResult::offer>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageOfferSuccessResult &obj) {
    archive(ar, obj.offersClaimed, "offersClaimed");
    archive(ar, obj.offer, "offer");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageOfferSuccessResult &obj) {
    archive(ar, obj.offersClaimed, "offersClaimed");
    archive(ar, obj.offer, "offer");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ManageSellOfferResult {
  using _xdr_case_type = xdr::xdr_traits<ManageSellOfferResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    ManageOfferSuccessResult success_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<ManageSellOfferResultCode> &_xdr_case_values() {
    static const std::vector<ManageSellOfferResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == MANAGE_SELL_OFFER_SUCCESS ? 1
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case MANAGE_SELL_OFFER_SUCCESS:
      _f(&ManageSellOfferResult::success_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in ManageSellOfferResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~ManageSellOfferResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit ManageSellOfferResult(ManageSellOfferResultCode which = ManageSellOfferResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  ManageSellOfferResult(const ManageSellOfferResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  ManageSellOfferResult(ManageSellOfferResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~ManageSellOfferResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  ManageSellOfferResult &operator=(const ManageSellOfferResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~ManageSellOfferResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  ManageSellOfferResult &operator=(ManageSellOfferResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~ManageSellOfferResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  ManageSellOfferResultCode code() const { return ManageSellOfferResultCode(code_); }
  ManageSellOfferResult &code(ManageSellOfferResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  ManageOfferSuccessResult &success() {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("ManageSellOfferResult: success accessed when not selected");
  }
  const ManageOfferSuccessResult &success() const {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("ManageSellOfferResult: success accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageSellOfferResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ManageSellOfferResult;
  using case_type = ::stellar::ManageSellOfferResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "success";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ManageSellOfferResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in ManageSellOfferResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageSellOfferResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in ManageSellOfferResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageSellOfferResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ManageBuyOfferResultCode : std::int32_t {
  MANAGE_BUY_OFFER_SUCCESS = 0,
  MANAGE_BUY_OFFER_MALFORMED = -1,
  MANAGE_BUY_OFFER_SELL_NO_TRUST = -2,
  MANAGE_BUY_OFFER_BUY_NO_TRUST = -3,
  MANAGE_BUY_OFFER_SELL_NOT_AUTHORIZED = -4,
  MANAGE_BUY_OFFER_BUY_NOT_AUTHORIZED = -5,
  MANAGE_BUY_OFFER_LINE_FULL = -6,
  MANAGE_BUY_OFFER_UNDERFUNDED = -7,
  MANAGE_BUY_OFFER_CROSS_SELF = -8,
  MANAGE_BUY_OFFER_SELL_NO_ISSUER = -9,
  MANAGE_BUY_OFFER_BUY_NO_ISSUER = -10,
  MANAGE_BUY_OFFER_NOT_FOUND = -11,
  MANAGE_BUY_OFFER_LOW_RESERVE = -12,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageBuyOfferResultCode>
  : xdr_integral_base<::stellar::ManageBuyOfferResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ManageBuyOfferResultCode val) {
    switch (val) {
    case ::stellar::MANAGE_BUY_OFFER_SUCCESS:
      return "MANAGE_BUY_OFFER_SUCCESS";
    case ::stellar::MANAGE_BUY_OFFER_MALFORMED:
      return "MANAGE_BUY_OFFER_MALFORMED";
    case ::stellar::MANAGE_BUY_OFFER_SELL_NO_TRUST:
      return "MANAGE_BUY_OFFER_SELL_NO_TRUST";
    case ::stellar::MANAGE_BUY_OFFER_BUY_NO_TRUST:
      return "MANAGE_BUY_OFFER_BUY_NO_TRUST";
    case ::stellar::MANAGE_BUY_OFFER_SELL_NOT_AUTHORIZED:
      return "MANAGE_BUY_OFFER_SELL_NOT_AUTHORIZED";
    case ::stellar::MANAGE_BUY_OFFER_BUY_NOT_AUTHORIZED:
      return "MANAGE_BUY_OFFER_BUY_NOT_AUTHORIZED";
    case ::stellar::MANAGE_BUY_OFFER_LINE_FULL:
      return "MANAGE_BUY_OFFER_LINE_FULL";
    case ::stellar::MANAGE_BUY_OFFER_UNDERFUNDED:
      return "MANAGE_BUY_OFFER_UNDERFUNDED";
    case ::stellar::MANAGE_BUY_OFFER_CROSS_SELF:
      return "MANAGE_BUY_OFFER_CROSS_SELF";
    case ::stellar::MANAGE_BUY_OFFER_SELL_NO_ISSUER:
      return "MANAGE_BUY_OFFER_SELL_NO_ISSUER";
    case ::stellar::MANAGE_BUY_OFFER_BUY_NO_ISSUER:
      return "MANAGE_BUY_OFFER_BUY_NO_ISSUER";
    case ::stellar::MANAGE_BUY_OFFER_NOT_FOUND:
      return "MANAGE_BUY_OFFER_NOT_FOUND";
    case ::stellar::MANAGE_BUY_OFFER_LOW_RESERVE:
      return "MANAGE_BUY_OFFER_LOW_RESERVE";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::MANAGE_BUY_OFFER_SUCCESS,
      ::stellar::MANAGE_BUY_OFFER_MALFORMED,
      ::stellar::MANAGE_BUY_OFFER_SELL_NO_TRUST,
      ::stellar::MANAGE_BUY_OFFER_BUY_NO_TRUST,
      ::stellar::MANAGE_BUY_OFFER_SELL_NOT_AUTHORIZED,
      ::stellar::MANAGE_BUY_OFFER_BUY_NOT_AUTHORIZED,
      ::stellar::MANAGE_BUY_OFFER_LINE_FULL,
      ::stellar::MANAGE_BUY_OFFER_UNDERFUNDED,
      ::stellar::MANAGE_BUY_OFFER_CROSS_SELF,
      ::stellar::MANAGE_BUY_OFFER_SELL_NO_ISSUER,
      ::stellar::MANAGE_BUY_OFFER_BUY_NO_ISSUER,
      ::stellar::MANAGE_BUY_OFFER_NOT_FOUND,
      ::stellar::MANAGE_BUY_OFFER_LOW_RESERVE
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct ManageBuyOfferResult {
  using _xdr_case_type = xdr::xdr_traits<ManageBuyOfferResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    ManageOfferSuccessResult success_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<ManageBuyOfferResultCode> &_xdr_case_values() {
    static const std::vector<ManageBuyOfferResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == MANAGE_BUY_OFFER_SUCCESS ? 1
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case MANAGE_BUY_OFFER_SUCCESS:
      _f(&ManageBuyOfferResult::success_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in ManageBuyOfferResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~ManageBuyOfferResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit ManageBuyOfferResult(ManageBuyOfferResultCode which = ManageBuyOfferResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  ManageBuyOfferResult(const ManageBuyOfferResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  ManageBuyOfferResult(ManageBuyOfferResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~ManageBuyOfferResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  ManageBuyOfferResult &operator=(const ManageBuyOfferResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~ManageBuyOfferResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  ManageBuyOfferResult &operator=(ManageBuyOfferResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~ManageBuyOfferResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  ManageBuyOfferResultCode code() const { return ManageBuyOfferResultCode(code_); }
  ManageBuyOfferResult &code(ManageBuyOfferResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  ManageOfferSuccessResult &success() {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("ManageBuyOfferResult: success accessed when not selected");
  }
  const ManageOfferSuccessResult &success() const {
    if (_xdr_field_number(code_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("ManageBuyOfferResult: success accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageBuyOfferResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ManageBuyOfferResult;
  using case_type = ::stellar::ManageBuyOfferResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "success";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ManageBuyOfferResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in ManageBuyOfferResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageBuyOfferResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in ManageBuyOfferResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageBuyOfferResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum SetOptionsResultCode : std::int32_t {
  SET_OPTIONS_SUCCESS = 0,
  SET_OPTIONS_LOW_RESERVE = -1,
  SET_OPTIONS_TOO_MANY_SIGNERS = -2,
  SET_OPTIONS_BAD_FLAGS = -3,
  SET_OPTIONS_INVALID_INFLATION = -4,
  SET_OPTIONS_CANT_CHANGE = -5,
  SET_OPTIONS_UNKNOWN_FLAG = -6,
  SET_OPTIONS_THRESHOLD_OUT_OF_RANGE = -7,
  SET_OPTIONS_BAD_SIGNER = -8,
  SET_OPTIONS_INVALID_HOME_DOMAIN = -9,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::SetOptionsResultCode>
  : xdr_integral_base<::stellar::SetOptionsResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::SetOptionsResultCode val) {
    switch (val) {
    case ::stellar::SET_OPTIONS_SUCCESS:
      return "SET_OPTIONS_SUCCESS";
    case ::stellar::SET_OPTIONS_LOW_RESERVE:
      return "SET_OPTIONS_LOW_RESERVE";
    case ::stellar::SET_OPTIONS_TOO_MANY_SIGNERS:
      return "SET_OPTIONS_TOO_MANY_SIGNERS";
    case ::stellar::SET_OPTIONS_BAD_FLAGS:
      return "SET_OPTIONS_BAD_FLAGS";
    case ::stellar::SET_OPTIONS_INVALID_INFLATION:
      return "SET_OPTIONS_INVALID_INFLATION";
    case ::stellar::SET_OPTIONS_CANT_CHANGE:
      return "SET_OPTIONS_CANT_CHANGE";
    case ::stellar::SET_OPTIONS_UNKNOWN_FLAG:
      return "SET_OPTIONS_UNKNOWN_FLAG";
    case ::stellar::SET_OPTIONS_THRESHOLD_OUT_OF_RANGE:
      return "SET_OPTIONS_THRESHOLD_OUT_OF_RANGE";
    case ::stellar::SET_OPTIONS_BAD_SIGNER:
      return "SET_OPTIONS_BAD_SIGNER";
    case ::stellar::SET_OPTIONS_INVALID_HOME_DOMAIN:
      return "SET_OPTIONS_INVALID_HOME_DOMAIN";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::SET_OPTIONS_SUCCESS,
      ::stellar::SET_OPTIONS_LOW_RESERVE,
      ::stellar::SET_OPTIONS_TOO_MANY_SIGNERS,
      ::stellar::SET_OPTIONS_BAD_FLAGS,
      ::stellar::SET_OPTIONS_INVALID_INFLATION,
      ::stellar::SET_OPTIONS_CANT_CHANGE,
      ::stellar::SET_OPTIONS_UNKNOWN_FLAG,
      ::stellar::SET_OPTIONS_THRESHOLD_OUT_OF_RANGE,
      ::stellar::SET_OPTIONS_BAD_SIGNER,
      ::stellar::SET_OPTIONS_INVALID_HOME_DOMAIN
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct SetOptionsResult {
  using _xdr_case_type = xdr::xdr_traits<SetOptionsResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<SetOptionsResultCode> &_xdr_case_values() {
    static const std::vector<SetOptionsResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == SET_OPTIONS_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case SET_OPTIONS_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in SetOptionsResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~SetOptionsResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit SetOptionsResult(SetOptionsResultCode which = SetOptionsResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  SetOptionsResult(const SetOptionsResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  SetOptionsResult(SetOptionsResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~SetOptionsResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  SetOptionsResult &operator=(const SetOptionsResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~SetOptionsResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  SetOptionsResult &operator=(SetOptionsResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~SetOptionsResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  SetOptionsResultCode code() const { return SetOptionsResultCode(code_); }
  SetOptionsResult &code(SetOptionsResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::SetOptionsResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::SetOptionsResult;
  using case_type = ::stellar::SetOptionsResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::SetOptionsResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in SetOptionsResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::SetOptionsResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in SetOptionsResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::SetOptionsResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ChangeTrustResultCode : std::int32_t {
  CHANGE_TRUST_SUCCESS = 0,
  CHANGE_TRUST_MALFORMED = -1,
  CHANGE_TRUST_NO_ISSUER = -2,
  CHANGE_TRUST_INVALID_LIMIT = -3,
  CHANGE_TRUST_LOW_RESERVE = -4,
  CHANGE_TRUST_SELF_NOT_ALLOWED = -5,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ChangeTrustResultCode>
  : xdr_integral_base<::stellar::ChangeTrustResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ChangeTrustResultCode val) {
    switch (val) {
    case ::stellar::CHANGE_TRUST_SUCCESS:
      return "CHANGE_TRUST_SUCCESS";
    case ::stellar::CHANGE_TRUST_MALFORMED:
      return "CHANGE_TRUST_MALFORMED";
    case ::stellar::CHANGE_TRUST_NO_ISSUER:
      return "CHANGE_TRUST_NO_ISSUER";
    case ::stellar::CHANGE_TRUST_INVALID_LIMIT:
      return "CHANGE_TRUST_INVALID_LIMIT";
    case ::stellar::CHANGE_TRUST_LOW_RESERVE:
      return "CHANGE_TRUST_LOW_RESERVE";
    case ::stellar::CHANGE_TRUST_SELF_NOT_ALLOWED:
      return "CHANGE_TRUST_SELF_NOT_ALLOWED";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CHANGE_TRUST_SUCCESS,
      ::stellar::CHANGE_TRUST_MALFORMED,
      ::stellar::CHANGE_TRUST_NO_ISSUER,
      ::stellar::CHANGE_TRUST_INVALID_LIMIT,
      ::stellar::CHANGE_TRUST_LOW_RESERVE,
      ::stellar::CHANGE_TRUST_SELF_NOT_ALLOWED
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct ChangeTrustResult {
  using _xdr_case_type = xdr::xdr_traits<ChangeTrustResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<ChangeTrustResultCode> &_xdr_case_values() {
    static const std::vector<ChangeTrustResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == CHANGE_TRUST_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case CHANGE_TRUST_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in ChangeTrustResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~ChangeTrustResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit ChangeTrustResult(ChangeTrustResultCode which = ChangeTrustResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  ChangeTrustResult(const ChangeTrustResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  ChangeTrustResult(ChangeTrustResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~ChangeTrustResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  ChangeTrustResult &operator=(const ChangeTrustResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~ChangeTrustResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  ChangeTrustResult &operator=(ChangeTrustResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~ChangeTrustResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  ChangeTrustResultCode code() const { return ChangeTrustResultCode(code_); }
  ChangeTrustResult &code(ChangeTrustResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::ChangeTrustResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ChangeTrustResult;
  using case_type = ::stellar::ChangeTrustResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ChangeTrustResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in ChangeTrustResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ChangeTrustResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in ChangeTrustResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ChangeTrustResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum AllowTrustResultCode : std::int32_t {
  ALLOW_TRUST_SUCCESS = 0,
  ALLOW_TRUST_MALFORMED = -1,
  ALLOW_TRUST_NO_TRUST_LINE = -2,
  ALLOW_TRUST_TRUST_NOT_REQUIRED = -3,
  ALLOW_TRUST_CANT_REVOKE = -4,
  ALLOW_TRUST_SELF_NOT_ALLOWED = -5,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AllowTrustResultCode>
  : xdr_integral_base<::stellar::AllowTrustResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::AllowTrustResultCode val) {
    switch (val) {
    case ::stellar::ALLOW_TRUST_SUCCESS:
      return "ALLOW_TRUST_SUCCESS";
    case ::stellar::ALLOW_TRUST_MALFORMED:
      return "ALLOW_TRUST_MALFORMED";
    case ::stellar::ALLOW_TRUST_NO_TRUST_LINE:
      return "ALLOW_TRUST_NO_TRUST_LINE";
    case ::stellar::ALLOW_TRUST_TRUST_NOT_REQUIRED:
      return "ALLOW_TRUST_TRUST_NOT_REQUIRED";
    case ::stellar::ALLOW_TRUST_CANT_REVOKE:
      return "ALLOW_TRUST_CANT_REVOKE";
    case ::stellar::ALLOW_TRUST_SELF_NOT_ALLOWED:
      return "ALLOW_TRUST_SELF_NOT_ALLOWED";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ALLOW_TRUST_SUCCESS,
      ::stellar::ALLOW_TRUST_MALFORMED,
      ::stellar::ALLOW_TRUST_NO_TRUST_LINE,
      ::stellar::ALLOW_TRUST_TRUST_NOT_REQUIRED,
      ::stellar::ALLOW_TRUST_CANT_REVOKE,
      ::stellar::ALLOW_TRUST_SELF_NOT_ALLOWED
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct AllowTrustResult {
  using _xdr_case_type = xdr::xdr_traits<AllowTrustResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<AllowTrustResultCode> &_xdr_case_values() {
    static const std::vector<AllowTrustResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ALLOW_TRUST_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ALLOW_TRUST_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in AllowTrustResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~AllowTrustResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit AllowTrustResult(AllowTrustResultCode which = AllowTrustResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  AllowTrustResult(const AllowTrustResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  AllowTrustResult(AllowTrustResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~AllowTrustResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  AllowTrustResult &operator=(const AllowTrustResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~AllowTrustResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  AllowTrustResult &operator=(AllowTrustResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~AllowTrustResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  AllowTrustResultCode code() const { return AllowTrustResultCode(code_); }
  AllowTrustResult &code(AllowTrustResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::AllowTrustResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AllowTrustResult;
  using case_type = ::stellar::AllowTrustResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AllowTrustResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in AllowTrustResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AllowTrustResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in AllowTrustResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AllowTrustResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum AccountMergeResultCode : std::int32_t {
  ACCOUNT_MERGE_SUCCESS = 0,
  ACCOUNT_MERGE_MALFORMED = -1,
  ACCOUNT_MERGE_NO_ACCOUNT = -2,
  ACCOUNT_MERGE_IMMUTABLE_SET = -3,
  ACCOUNT_MERGE_HAS_SUB_ENTRIES = -4,
  ACCOUNT_MERGE_SEQNUM_TOO_FAR = -5,
  ACCOUNT_MERGE_DEST_FULL = -6,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountMergeResultCode>
  : xdr_integral_base<::stellar::AccountMergeResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::AccountMergeResultCode val) {
    switch (val) {
    case ::stellar::ACCOUNT_MERGE_SUCCESS:
      return "ACCOUNT_MERGE_SUCCESS";
    case ::stellar::ACCOUNT_MERGE_MALFORMED:
      return "ACCOUNT_MERGE_MALFORMED";
    case ::stellar::ACCOUNT_MERGE_NO_ACCOUNT:
      return "ACCOUNT_MERGE_NO_ACCOUNT";
    case ::stellar::ACCOUNT_MERGE_IMMUTABLE_SET:
      return "ACCOUNT_MERGE_IMMUTABLE_SET";
    case ::stellar::ACCOUNT_MERGE_HAS_SUB_ENTRIES:
      return "ACCOUNT_MERGE_HAS_SUB_ENTRIES";
    case ::stellar::ACCOUNT_MERGE_SEQNUM_TOO_FAR:
      return "ACCOUNT_MERGE_SEQNUM_TOO_FAR";
    case ::stellar::ACCOUNT_MERGE_DEST_FULL:
      return "ACCOUNT_MERGE_DEST_FULL";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ACCOUNT_MERGE_SUCCESS,
      ::stellar::ACCOUNT_MERGE_MALFORMED,
      ::stellar::ACCOUNT_MERGE_NO_ACCOUNT,
      ::stellar::ACCOUNT_MERGE_IMMUTABLE_SET,
      ::stellar::ACCOUNT_MERGE_HAS_SUB_ENTRIES,
      ::stellar::ACCOUNT_MERGE_SEQNUM_TOO_FAR,
      ::stellar::ACCOUNT_MERGE_DEST_FULL
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct AccountMergeResult {
  using _xdr_case_type = xdr::xdr_traits<AccountMergeResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    int64 sourceAccountBalance_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<AccountMergeResultCode> &_xdr_case_values() {
    static const std::vector<AccountMergeResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ACCOUNT_MERGE_SUCCESS ? 1
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ACCOUNT_MERGE_SUCCESS:
      _f(&AccountMergeResult::sourceAccountBalance_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in AccountMergeResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~AccountMergeResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit AccountMergeResult(AccountMergeResultCode which = AccountMergeResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  AccountMergeResult(const AccountMergeResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  AccountMergeResult(AccountMergeResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~AccountMergeResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  AccountMergeResult &operator=(const AccountMergeResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~AccountMergeResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  AccountMergeResult &operator=(AccountMergeResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~AccountMergeResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  AccountMergeResultCode code() const { return AccountMergeResultCode(code_); }
  AccountMergeResult &code(AccountMergeResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  int64 &sourceAccountBalance() {
    if (_xdr_field_number(code_) == 1)
      return sourceAccountBalance_;
    throw xdr::xdr_wrong_union("AccountMergeResult: sourceAccountBalance accessed when not selected");
  }
  const int64 &sourceAccountBalance() const {
    if (_xdr_field_number(code_) == 1)
      return sourceAccountBalance_;
    throw xdr::xdr_wrong_union("AccountMergeResult: sourceAccountBalance accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountMergeResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AccountMergeResult;
  using case_type = ::stellar::AccountMergeResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "sourceAccountBalance";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AccountMergeResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in AccountMergeResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountMergeResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in AccountMergeResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountMergeResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum InflationResultCode : std::int32_t {
  INFLATION_SUCCESS = 0,
  INFLATION_NOT_TIME = -1,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::InflationResultCode>
  : xdr_integral_base<::stellar::InflationResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::InflationResultCode val) {
    switch (val) {
    case ::stellar::INFLATION_SUCCESS:
      return "INFLATION_SUCCESS";
    case ::stellar::INFLATION_NOT_TIME:
      return "INFLATION_NOT_TIME";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::INFLATION_SUCCESS,
      ::stellar::INFLATION_NOT_TIME
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct InflationPayout {
  AccountID destination{};
  int64 amount{};

  InflationPayout() = default;
  template<typename _destination_T,
           typename _amount_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _destination_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                         >::type>
  explicit InflationPayout(_destination_T &&_destination,
                           _amount_T &&_amount)
    : destination(std::forward<_destination_T>(_destination)),
      amount(std::forward<_amount_T>(_amount)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::InflationPayout>
  : xdr_struct_base<field_ptr<::stellar::InflationPayout,
                              decltype(::stellar::InflationPayout::destination),
                              &::stellar::InflationPayout::destination>,
                    field_ptr<::stellar::InflationPayout,
                              decltype(::stellar::InflationPayout::amount),
                              &::stellar::InflationPayout::amount>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::InflationPayout &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.amount, "amount");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::InflationPayout &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.amount, "amount");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct InflationResult {
  using _xdr_case_type = xdr::xdr_traits<InflationResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    xdr::xvector<InflationPayout> payouts_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<InflationResultCode> &_xdr_case_values() {
    static const std::vector<InflationResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == INFLATION_SUCCESS ? 1
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case INFLATION_SUCCESS:
      _f(&InflationResult::payouts_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in InflationResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~InflationResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit InflationResult(InflationResultCode which = InflationResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  InflationResult(const InflationResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  InflationResult(InflationResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~InflationResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  InflationResult &operator=(const InflationResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~InflationResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  InflationResult &operator=(InflationResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~InflationResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  InflationResultCode code() const { return InflationResultCode(code_); }
  InflationResult &code(InflationResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  xdr::xvector<InflationPayout> &payouts() {
    if (_xdr_field_number(code_) == 1)
      return payouts_;
    throw xdr::xdr_wrong_union("InflationResult: payouts accessed when not selected");
  }
  const xdr::xvector<InflationPayout> &payouts() const {
    if (_xdr_field_number(code_) == 1)
      return payouts_;
    throw xdr::xdr_wrong_union("InflationResult: payouts accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::InflationResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::InflationResult;
  using case_type = ::stellar::InflationResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "payouts";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::InflationResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in InflationResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::InflationResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in InflationResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::InflationResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ManageDataResultCode : std::int32_t {
  MANAGE_DATA_SUCCESS = 0,
  MANAGE_DATA_NOT_SUPPORTED_YET = -1,
  MANAGE_DATA_NAME_NOT_FOUND = -2,
  MANAGE_DATA_LOW_RESERVE = -3,
  MANAGE_DATA_INVALID_NAME = -4,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageDataResultCode>
  : xdr_integral_base<::stellar::ManageDataResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ManageDataResultCode val) {
    switch (val) {
    case ::stellar::MANAGE_DATA_SUCCESS:
      return "MANAGE_DATA_SUCCESS";
    case ::stellar::MANAGE_DATA_NOT_SUPPORTED_YET:
      return "MANAGE_DATA_NOT_SUPPORTED_YET";
    case ::stellar::MANAGE_DATA_NAME_NOT_FOUND:
      return "MANAGE_DATA_NAME_NOT_FOUND";
    case ::stellar::MANAGE_DATA_LOW_RESERVE:
      return "MANAGE_DATA_LOW_RESERVE";
    case ::stellar::MANAGE_DATA_INVALID_NAME:
      return "MANAGE_DATA_INVALID_NAME";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::MANAGE_DATA_SUCCESS,
      ::stellar::MANAGE_DATA_NOT_SUPPORTED_YET,
      ::stellar::MANAGE_DATA_NAME_NOT_FOUND,
      ::stellar::MANAGE_DATA_LOW_RESERVE,
      ::stellar::MANAGE_DATA_INVALID_NAME
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct ManageDataResult {
  using _xdr_case_type = xdr::xdr_traits<ManageDataResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<ManageDataResultCode> &_xdr_case_values() {
    static const std::vector<ManageDataResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == MANAGE_DATA_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case MANAGE_DATA_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in ManageDataResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~ManageDataResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit ManageDataResult(ManageDataResultCode which = ManageDataResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  ManageDataResult(const ManageDataResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  ManageDataResult(ManageDataResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~ManageDataResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  ManageDataResult &operator=(const ManageDataResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~ManageDataResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  ManageDataResult &operator=(ManageDataResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~ManageDataResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  ManageDataResultCode code() const { return ManageDataResultCode(code_); }
  ManageDataResult &code(ManageDataResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::ManageDataResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ManageDataResult;
  using case_type = ::stellar::ManageDataResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ManageDataResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in ManageDataResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ManageDataResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in ManageDataResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ManageDataResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum BumpSequenceResultCode : std::int32_t {
  BUMP_SEQUENCE_SUCCESS = 0,
  BUMP_SEQUENCE_BAD_SEQ = -1,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::BumpSequenceResultCode>
  : xdr_integral_base<::stellar::BumpSequenceResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::BumpSequenceResultCode val) {
    switch (val) {
    case ::stellar::BUMP_SEQUENCE_SUCCESS:
      return "BUMP_SEQUENCE_SUCCESS";
    case ::stellar::BUMP_SEQUENCE_BAD_SEQ:
      return "BUMP_SEQUENCE_BAD_SEQ";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::BUMP_SEQUENCE_SUCCESS,
      ::stellar::BUMP_SEQUENCE_BAD_SEQ
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct BumpSequenceResult {
  using _xdr_case_type = xdr::xdr_traits<BumpSequenceResultCode>::case_type;
private:
  _xdr_case_type code_;
public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<BumpSequenceResultCode> &_xdr_case_values() {
    static const std::vector<BumpSequenceResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == BUMP_SEQUENCE_SUCCESS ? 0
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case BUMP_SEQUENCE_SUCCESS:
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in BumpSequenceResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~BumpSequenceResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit BumpSequenceResult(BumpSequenceResultCode which = BumpSequenceResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  BumpSequenceResult(const BumpSequenceResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  BumpSequenceResult(BumpSequenceResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~BumpSequenceResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  BumpSequenceResult &operator=(const BumpSequenceResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~BumpSequenceResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  BumpSequenceResult &operator=(BumpSequenceResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~BumpSequenceResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  BumpSequenceResultCode code() const { return BumpSequenceResultCode(code_); }
  BumpSequenceResult &code(BumpSequenceResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

};
} namespace xdr {
template<> struct xdr_traits<::stellar::BumpSequenceResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::BumpSequenceResult;
  using case_type = ::stellar::BumpSequenceResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::BumpSequenceResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in BumpSequenceResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::BumpSequenceResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in BumpSequenceResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::BumpSequenceResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum OperationResultCode : std::int32_t {
  opINNER = 0,
  opBAD_AUTH = -1,
  opNO_ACCOUNT = -2,
  opNOT_SUPPORTED = -3,
  opTOO_MANY_SUBENTRIES = -4,
  opEXCEEDED_WORK_LIMIT = -5,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OperationResultCode>
  : xdr_integral_base<::stellar::OperationResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::OperationResultCode val) {
    switch (val) {
    case ::stellar::opINNER:
      return "opINNER";
    case ::stellar::opBAD_AUTH:
      return "opBAD_AUTH";
    case ::stellar::opNO_ACCOUNT:
      return "opNO_ACCOUNT";
    case ::stellar::opNOT_SUPPORTED:
      return "opNOT_SUPPORTED";
    case ::stellar::opTOO_MANY_SUBENTRIES:
      return "opTOO_MANY_SUBENTRIES";
    case ::stellar::opEXCEEDED_WORK_LIMIT:
      return "opEXCEEDED_WORK_LIMIT";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::opINNER,
      ::stellar::opBAD_AUTH,
      ::stellar::opNO_ACCOUNT,
      ::stellar::opNOT_SUPPORTED,
      ::stellar::opTOO_MANY_SUBENTRIES,
      ::stellar::opEXCEEDED_WORK_LIMIT
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct OperationResult {
  struct _tr_t {
    using _xdr_case_type = xdr::xdr_traits<OperationType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      CreateAccountResult createAccountResult_;
      PaymentResult paymentResult_;
      PathPaymentStrictReceiveResult pathPaymentStrictReceiveResult_;
      ManageSellOfferResult manageSellOfferResult_;
      ManageSellOfferResult createPassiveSellOfferResult_;
      SetOptionsResult setOptionsResult_;
      ChangeTrustResult changeTrustResult_;
      AllowTrustResult allowTrustResult_;
      AccountMergeResult accountMergeResult_;
      InflationResult inflationResult_;
      ManageDataResult manageDataResult_;
      BumpSequenceResult bumpSeqResult_;
      ManageBuyOfferResult manageBuyOfferResult_;
      PathPaymentStrictSendResult pathPaymentStrictSendResult_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<OperationType> &_xdr_case_values() {
      static const std::vector<OperationType> _xdr_disc_vec {
        CREATE_ACCOUNT,
        PAYMENT,
        PATH_PAYMENT_STRICT_RECEIVE,
        MANAGE_SELL_OFFER,
        CREATE_PASSIVE_SELL_OFFER,
        SET_OPTIONS,
        CHANGE_TRUST,
        ALLOW_TRUST,
        ACCOUNT_MERGE,
        INFLATION,
        MANAGE_DATA,
        BUMP_SEQUENCE,
        MANAGE_BUY_OFFER,
        PATH_PAYMENT_STRICT_SEND
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == CREATE_ACCOUNT ? 1
        : which == PAYMENT ? 2
        : which == PATH_PAYMENT_STRICT_RECEIVE ? 3
        : which == MANAGE_SELL_OFFER ? 4
        : which == CREATE_PASSIVE_SELL_OFFER ? 5
        : which == SET_OPTIONS ? 6
        : which == CHANGE_TRUST ? 7
        : which == ALLOW_TRUST ? 8
        : which == ACCOUNT_MERGE ? 9
        : which == INFLATION ? 10
        : which == MANAGE_DATA ? 11
        : which == BUMP_SEQUENCE ? 12
        : which == MANAGE_BUY_OFFER ? 13
        : which == PATH_PAYMENT_STRICT_SEND ? 14
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case CREATE_ACCOUNT:
        _f(&_tr_t::createAccountResult_, std::forward<_A>(_a)...);
        return true;
      case PAYMENT:
        _f(&_tr_t::paymentResult_, std::forward<_A>(_a)...);
        return true;
      case PATH_PAYMENT_STRICT_RECEIVE:
        _f(&_tr_t::pathPaymentStrictReceiveResult_, std::forward<_A>(_a)...);
        return true;
      case MANAGE_SELL_OFFER:
        _f(&_tr_t::manageSellOfferResult_, std::forward<_A>(_a)...);
        return true;
      case CREATE_PASSIVE_SELL_OFFER:
        _f(&_tr_t::createPassiveSellOfferResult_, std::forward<_A>(_a)...);
        return true;
      case SET_OPTIONS:
        _f(&_tr_t::setOptionsResult_, std::forward<_A>(_a)...);
        return true;
      case CHANGE_TRUST:
        _f(&_tr_t::changeTrustResult_, std::forward<_A>(_a)...);
        return true;
      case ALLOW_TRUST:
        _f(&_tr_t::allowTrustResult_, std::forward<_A>(_a)...);
        return true;
      case ACCOUNT_MERGE:
        _f(&_tr_t::accountMergeResult_, std::forward<_A>(_a)...);
        return true;
      case INFLATION:
        _f(&_tr_t::inflationResult_, std::forward<_A>(_a)...);
        return true;
      case MANAGE_DATA:
        _f(&_tr_t::manageDataResult_, std::forward<_A>(_a)...);
        return true;
      case BUMP_SEQUENCE:
        _f(&_tr_t::bumpSeqResult_, std::forward<_A>(_a)...);
        return true;
      case MANAGE_BUY_OFFER:
        _f(&_tr_t::manageBuyOfferResult_, std::forward<_A>(_a)...);
        return true;
      case PATH_PAYMENT_STRICT_SEND:
        _f(&_tr_t::pathPaymentStrictSendResult_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _tr_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_tr_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _tr_t(OperationType which = OperationType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _tr_t(const _tr_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _tr_t(_tr_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_tr_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _tr_t &operator=(const _tr_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_tr_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _tr_t &operator=(_tr_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_tr_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    OperationType type() const { return OperationType(type_); }
    _tr_t &type(OperationType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    CreateAccountResult &createAccountResult() {
      if (_xdr_field_number(type_) == 1)
        return createAccountResult_;
      throw xdr::xdr_wrong_union("_tr_t: createAccountResult accessed when not selected");
    }
    const CreateAccountResult &createAccountResult() const {
      if (_xdr_field_number(type_) == 1)
        return createAccountResult_;
      throw xdr::xdr_wrong_union("_tr_t: createAccountResult accessed when not selected");
    }
    PaymentResult &paymentResult() {
      if (_xdr_field_number(type_) == 2)
        return paymentResult_;
      throw xdr::xdr_wrong_union("_tr_t: paymentResult accessed when not selected");
    }
    const PaymentResult &paymentResult() const {
      if (_xdr_field_number(type_) == 2)
        return paymentResult_;
      throw xdr::xdr_wrong_union("_tr_t: paymentResult accessed when not selected");
    }
    PathPaymentStrictReceiveResult &pathPaymentStrictReceiveResult() {
      if (_xdr_field_number(type_) == 3)
        return pathPaymentStrictReceiveResult_;
      throw xdr::xdr_wrong_union("_tr_t: pathPaymentStrictReceiveResult accessed when not selected");
    }
    const PathPaymentStrictReceiveResult &pathPaymentStrictReceiveResult() const {
      if (_xdr_field_number(type_) == 3)
        return pathPaymentStrictReceiveResult_;
      throw xdr::xdr_wrong_union("_tr_t: pathPaymentStrictReceiveResult accessed when not selected");
    }
    ManageSellOfferResult &manageSellOfferResult() {
      if (_xdr_field_number(type_) == 4)
        return manageSellOfferResult_;
      throw xdr::xdr_wrong_union("_tr_t: manageSellOfferResult accessed when not selected");
    }
    const ManageSellOfferResult &manageSellOfferResult() const {
      if (_xdr_field_number(type_) == 4)
        return manageSellOfferResult_;
      throw xdr::xdr_wrong_union("_tr_t: manageSellOfferResult accessed when not selected");
    }
    ManageSellOfferResult &createPassiveSellOfferResult() {
      if (_xdr_field_number(type_) == 5)
        return createPassiveSellOfferResult_;
      throw xdr::xdr_wrong_union("_tr_t: createPassiveSellOfferResult accessed when not selected");
    }
    const ManageSellOfferResult &createPassiveSellOfferResult() const {
      if (_xdr_field_number(type_) == 5)
        return createPassiveSellOfferResult_;
      throw xdr::xdr_wrong_union("_tr_t: createPassiveSellOfferResult accessed when not selected");
    }
    SetOptionsResult &setOptionsResult() {
      if (_xdr_field_number(type_) == 6)
        return setOptionsResult_;
      throw xdr::xdr_wrong_union("_tr_t: setOptionsResult accessed when not selected");
    }
    const SetOptionsResult &setOptionsResult() const {
      if (_xdr_field_number(type_) == 6)
        return setOptionsResult_;
      throw xdr::xdr_wrong_union("_tr_t: setOptionsResult accessed when not selected");
    }
    ChangeTrustResult &changeTrustResult() {
      if (_xdr_field_number(type_) == 7)
        return changeTrustResult_;
      throw xdr::xdr_wrong_union("_tr_t: changeTrustResult accessed when not selected");
    }
    const ChangeTrustResult &changeTrustResult() const {
      if (_xdr_field_number(type_) == 7)
        return changeTrustResult_;
      throw xdr::xdr_wrong_union("_tr_t: changeTrustResult accessed when not selected");
    }
    AllowTrustResult &allowTrustResult() {
      if (_xdr_field_number(type_) == 8)
        return allowTrustResult_;
      throw xdr::xdr_wrong_union("_tr_t: allowTrustResult accessed when not selected");
    }
    const AllowTrustResult &allowTrustResult() const {
      if (_xdr_field_number(type_) == 8)
        return allowTrustResult_;
      throw xdr::xdr_wrong_union("_tr_t: allowTrustResult accessed when not selected");
    }
    AccountMergeResult &accountMergeResult() {
      if (_xdr_field_number(type_) == 9)
        return accountMergeResult_;
      throw xdr::xdr_wrong_union("_tr_t: accountMergeResult accessed when not selected");
    }
    const AccountMergeResult &accountMergeResult() const {
      if (_xdr_field_number(type_) == 9)
        return accountMergeResult_;
      throw xdr::xdr_wrong_union("_tr_t: accountMergeResult accessed when not selected");
    }
    InflationResult &inflationResult() {
      if (_xdr_field_number(type_) == 10)
        return inflationResult_;
      throw xdr::xdr_wrong_union("_tr_t: inflationResult accessed when not selected");
    }
    const InflationResult &inflationResult() const {
      if (_xdr_field_number(type_) == 10)
        return inflationResult_;
      throw xdr::xdr_wrong_union("_tr_t: inflationResult accessed when not selected");
    }
    ManageDataResult &manageDataResult() {
      if (_xdr_field_number(type_) == 11)
        return manageDataResult_;
      throw xdr::xdr_wrong_union("_tr_t: manageDataResult accessed when not selected");
    }
    const ManageDataResult &manageDataResult() const {
      if (_xdr_field_number(type_) == 11)
        return manageDataResult_;
      throw xdr::xdr_wrong_union("_tr_t: manageDataResult accessed when not selected");
    }
    BumpSequenceResult &bumpSeqResult() {
      if (_xdr_field_number(type_) == 12)
        return bumpSeqResult_;
      throw xdr::xdr_wrong_union("_tr_t: bumpSeqResult accessed when not selected");
    }
    const BumpSequenceResult &bumpSeqResult() const {
      if (_xdr_field_number(type_) == 12)
        return bumpSeqResult_;
      throw xdr::xdr_wrong_union("_tr_t: bumpSeqResult accessed when not selected");
    }
    ManageBuyOfferResult &manageBuyOfferResult() {
      if (_xdr_field_number(type_) == 13)
        return manageBuyOfferResult_;
      throw xdr::xdr_wrong_union("_tr_t: manageBuyOfferResult accessed when not selected");
    }
    const ManageBuyOfferResult &manageBuyOfferResult() const {
      if (_xdr_field_number(type_) == 13)
        return manageBuyOfferResult_;
      throw xdr::xdr_wrong_union("_tr_t: manageBuyOfferResult accessed when not selected");
    }
    PathPaymentStrictSendResult &pathPaymentStrictSendResult() {
      if (_xdr_field_number(type_) == 14)
        return pathPaymentStrictSendResult_;
      throw xdr::xdr_wrong_union("_tr_t: pathPaymentStrictSendResult accessed when not selected");
    }
    const PathPaymentStrictSendResult &pathPaymentStrictSendResult() const {
      if (_xdr_field_number(type_) == 14)
        return pathPaymentStrictSendResult_;
      throw xdr::xdr_wrong_union("_tr_t: pathPaymentStrictSendResult accessed when not selected");
    }
  };

  using _xdr_case_type = xdr::xdr_traits<OperationResultCode>::case_type;
private:
  _xdr_case_type code_;
  union {
    _tr_t tr_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = true;
  static const std::vector<OperationResultCode> &_xdr_case_values() {
    static const std::vector<OperationResultCode> _xdr_disc_vec {};
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == opINNER ? 1
      : 0;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case opINNER:
      _f(&OperationResult::tr_, std::forward<_A>(_a)...);
      return true;
    default:
      return true;
    }
  }

  _xdr_case_type _xdr_discriminant() const { return code_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of code in OperationResult");
    if (fnum != _xdr_field_number(code_)) {
      this->~OperationResult();
      code_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    else
      code_ = which;
  }
  explicit OperationResult(OperationResultCode which = OperationResultCode{}) : code_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
  }
  OperationResult(const OperationResult &source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
  }
  OperationResult(OperationResult &&source) : code_(source.code_) {
    _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                      std::move(source));
  }
  ~OperationResult() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
  OperationResult &operator=(const OperationResult &source) {
    if (_xdr_field_number(code_)
        == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
    else {
      this->~OperationResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
    }
    code_ = source.code_;
    return *this;
  }
  OperationResult &operator=(OperationResult &&source) {
    if (_xdr_field_number(code_)
         == _xdr_field_number(source.code_))
      _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                        std::move(source));
    else {
      this->~OperationResult();
      code_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                        std::move(source));
    }
    code_ = source.code_;
    return *this;
  }

  OperationResultCode code() const { return OperationResultCode(code_); }
  OperationResult &code(OperationResultCode _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _tr_t &tr() {
    if (_xdr_field_number(code_) == 1)
      return tr_;
    throw xdr::xdr_wrong_union("OperationResult: tr accessed when not selected");
  }
  const _tr_t &tr() const {
    if (_xdr_field_number(code_) == 1)
      return tr_;
    throw xdr::xdr_wrong_union("OperationResult: tr accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OperationResult::_tr_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::OperationResult::_tr_t;
  using case_type = ::stellar::OperationResult::_tr_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "createAccountResult";
    case 2:
      return "paymentResult";
    case 3:
      return "pathPaymentStrictReceiveResult";
    case 4:
      return "manageSellOfferResult";
    case 5:
      return "createPassiveSellOfferResult";
    case 6:
      return "setOptionsResult";
    case 7:
      return "changeTrustResult";
    case 8:
      return "allowTrustResult";
    case 9:
      return "accountMergeResult";
    case 10:
      return "inflationResult";
    case 11:
      return "manageDataResult";
    case 12:
      return "bumpSeqResult";
    case 13:
      return "manageBuyOfferResult";
    case 14:
      return "pathPaymentStrictSendResult";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::OperationResult::_tr_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _tr_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::OperationResult::_tr_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _tr_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::OperationResult::_tr_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::OperationResult> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::OperationResult;
  using case_type = ::stellar::OperationResult::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "tr";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::OperationResult &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in OperationResult");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::OperationResult &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in OperationResult");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::OperationResult &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum TransactionResultCode : std::int32_t {
  txFEE_BUMP_INNER_SUCCESS = 1,
  txSUCCESS = 0,
  txFAILED = -1,
  txTOO_EARLY = -2,
  txTOO_LATE = -3,
  txMISSING_OPERATION = -4,
  txBAD_SEQ = -5,
  txBAD_AUTH = -6,
  txINSUFFICIENT_BALANCE = -7,
  txNO_ACCOUNT = -8,
  txINSUFFICIENT_FEE = -9,
  txBAD_AUTH_EXTRA = -10,
  txINTERNAL_ERROR = -11,
  txNOT_SUPPORTED = -12,
  txFEE_BUMP_INNER_FAILED = -13,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionResultCode>
  : xdr_integral_base<::stellar::TransactionResultCode, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::TransactionResultCode val) {
    switch (val) {
    case ::stellar::txFEE_BUMP_INNER_SUCCESS:
      return "txFEE_BUMP_INNER_SUCCESS";
    case ::stellar::txSUCCESS:
      return "txSUCCESS";
    case ::stellar::txFAILED:
      return "txFAILED";
    case ::stellar::txTOO_EARLY:
      return "txTOO_EARLY";
    case ::stellar::txTOO_LATE:
      return "txTOO_LATE";
    case ::stellar::txMISSING_OPERATION:
      return "txMISSING_OPERATION";
    case ::stellar::txBAD_SEQ:
      return "txBAD_SEQ";
    case ::stellar::txBAD_AUTH:
      return "txBAD_AUTH";
    case ::stellar::txINSUFFICIENT_BALANCE:
      return "txINSUFFICIENT_BALANCE";
    case ::stellar::txNO_ACCOUNT:
      return "txNO_ACCOUNT";
    case ::stellar::txINSUFFICIENT_FEE:
      return "txINSUFFICIENT_FEE";
    case ::stellar::txBAD_AUTH_EXTRA:
      return "txBAD_AUTH_EXTRA";
    case ::stellar::txINTERNAL_ERROR:
      return "txINTERNAL_ERROR";
    case ::stellar::txNOT_SUPPORTED:
      return "txNOT_SUPPORTED";
    case ::stellar::txFEE_BUMP_INNER_FAILED:
      return "txFEE_BUMP_INNER_FAILED";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::txFEE_BUMP_INNER_SUCCESS,
      ::stellar::txSUCCESS,
      ::stellar::txFAILED,
      ::stellar::txTOO_EARLY,
      ::stellar::txTOO_LATE,
      ::stellar::txMISSING_OPERATION,
      ::stellar::txBAD_SEQ,
      ::stellar::txBAD_AUTH,
      ::stellar::txINSUFFICIENT_BALANCE,
      ::stellar::txNO_ACCOUNT,
      ::stellar::txINSUFFICIENT_FEE,
      ::stellar::txBAD_AUTH_EXTRA,
      ::stellar::txINTERNAL_ERROR,
      ::stellar::txNOT_SUPPORTED,
      ::stellar::txFEE_BUMP_INNER_FAILED
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct InnerTransactionResult {
  struct _result_t {
    using _xdr_case_type = xdr::xdr_traits<TransactionResultCode>::case_type;
  private:
    _xdr_case_type code_;
    union {
      xdr::xvector<OperationResult> results_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<TransactionResultCode> &_xdr_case_values() {
      static const std::vector<TransactionResultCode> _xdr_disc_vec {
        txSUCCESS,
        txFAILED,
        txTOO_EARLY,
        txTOO_LATE,
        txMISSING_OPERATION,
        txBAD_SEQ,
        txBAD_AUTH,
        txINSUFFICIENT_BALANCE,
        txNO_ACCOUNT,
        txINSUFFICIENT_FEE,
        txBAD_AUTH_EXTRA,
        txINTERNAL_ERROR,
        txNOT_SUPPORTED
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == txSUCCESS || which == txFAILED ? 1
        : which == txTOO_EARLY || which == txTOO_LATE || which == txMISSING_OPERATION || which == txBAD_SEQ || which == txBAD_AUTH || which == txINSUFFICIENT_BALANCE || which == txNO_ACCOUNT || which == txINSUFFICIENT_FEE || which == txBAD_AUTH_EXTRA || which == txINTERNAL_ERROR || which == txNOT_SUPPORTED ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case txSUCCESS:
      case txFAILED:
        _f(&_result_t::results_, std::forward<_A>(_a)...);
        return true;
      case txTOO_EARLY:
      case txTOO_LATE:
      case txMISSING_OPERATION:
      case txBAD_SEQ:
      case txBAD_AUTH:
      case txINSUFFICIENT_BALANCE:
      case txNO_ACCOUNT:
      case txINSUFFICIENT_FEE:
      case txBAD_AUTH_EXTRA:
      case txINTERNAL_ERROR:
      case txNOT_SUPPORTED:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return code_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of code in _result_t");
      if (fnum != _xdr_field_number(code_)) {
        this->~_result_t();
        code_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
      }
      else
        code_ = which;
    }
    explicit _result_t(TransactionResultCode which = TransactionResultCode{}) : code_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    _result_t(const _result_t &source) : code_(source.code_) {
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
    }
    _result_t(_result_t &&source) : code_(source.code_) {
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                        std::move(source));
    }
    ~_result_t() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
    _result_t &operator=(const _result_t &source) {
      if (_xdr_field_number(code_)
          == _xdr_field_number(source.code_))
        _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
      else {
        this->~_result_t();
        code_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
      }
      code_ = source.code_;
      return *this;
    }
    _result_t &operator=(_result_t &&source) {
      if (_xdr_field_number(code_)
           == _xdr_field_number(source.code_))
        _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                          std::move(source));
      else {
        this->~_result_t();
        code_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                          std::move(source));
      }
      code_ = source.code_;
      return *this;
    }

    TransactionResultCode code() const { return TransactionResultCode(code_); }
    _result_t &code(TransactionResultCode _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    xdr::xvector<OperationResult> &results() {
      if (_xdr_field_number(code_) == 1)
        return results_;
      throw xdr::xdr_wrong_union("_result_t: results accessed when not selected");
    }
    const xdr::xvector<OperationResult> &results() const {
      if (_xdr_field_number(code_) == 1)
        return results_;
      throw xdr::xdr_wrong_union("_result_t: results accessed when not selected");
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

  int64 feeCharged{};
  _result_t result{};
  _ext_t ext{};

  InnerTransactionResult() = default;
  template<typename _feeCharged_T,
           typename _result_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<int64, _feeCharged_T>::value
                          && std::is_constructible<_result_t, _result_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit InnerTransactionResult(_feeCharged_T &&_feeCharged,
                                  _result_T &&_result,
                                  _ext_T &&_ext)
    : feeCharged(std::forward<_feeCharged_T>(_feeCharged)),
      result(std::forward<_result_T>(_result)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::InnerTransactionResult::_result_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::InnerTransactionResult::_result_t;
  using case_type = ::stellar::InnerTransactionResult::_result_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "results";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::InnerTransactionResult::_result_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in _result_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::InnerTransactionResult::_result_t &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in _result_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::InnerTransactionResult::_result_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::InnerTransactionResult::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::InnerTransactionResult::_ext_t;
  using case_type = ::stellar::InnerTransactionResult::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::InnerTransactionResult::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::InnerTransactionResult::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::InnerTransactionResult::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::InnerTransactionResult>
  : xdr_struct_base<field_ptr<::stellar::InnerTransactionResult,
                              decltype(::stellar::InnerTransactionResult::feeCharged),
                              &::stellar::InnerTransactionResult::feeCharged>,
                    field_ptr<::stellar::InnerTransactionResult,
                              decltype(::stellar::InnerTransactionResult::result),
                              &::stellar::InnerTransactionResult::result>,
                    field_ptr<::stellar::InnerTransactionResult,
                              decltype(::stellar::InnerTransactionResult::ext),
                              &::stellar::InnerTransactionResult::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::InnerTransactionResult &obj) {
    archive(ar, obj.feeCharged, "feeCharged");
    archive(ar, obj.result, "result");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::InnerTransactionResult &obj) {
    archive(ar, obj.feeCharged, "feeCharged");
    archive(ar, obj.result, "result");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct InnerTransactionResultPair {
  Hash transactionHash{};
  InnerTransactionResult result{};

  InnerTransactionResultPair() = default;
  template<typename _transactionHash_T,
           typename _result_T,
           typename = typename
           std::enable_if<std::is_constructible<Hash, _transactionHash_T>::value
                          && std::is_constructible<InnerTransactionResult, _result_T>::value
                         >::type>
  explicit InnerTransactionResultPair(_transactionHash_T &&_transactionHash,
                                      _result_T &&_result)
    : transactionHash(std::forward<_transactionHash_T>(_transactionHash)),
      result(std::forward<_result_T>(_result)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::InnerTransactionResultPair>
  : xdr_struct_base<field_ptr<::stellar::InnerTransactionResultPair,
                              decltype(::stellar::InnerTransactionResultPair::transactionHash),
                              &::stellar::InnerTransactionResultPair::transactionHash>,
                    field_ptr<::stellar::InnerTransactionResultPair,
                              decltype(::stellar::InnerTransactionResultPair::result),
                              &::stellar::InnerTransactionResultPair::result>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::InnerTransactionResultPair &obj) {
    archive(ar, obj.transactionHash, "transactionHash");
    archive(ar, obj.result, "result");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::InnerTransactionResultPair &obj) {
    archive(ar, obj.transactionHash, "transactionHash");
    archive(ar, obj.result, "result");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TransactionResult {
  struct _result_t {
    using _xdr_case_type = xdr::xdr_traits<TransactionResultCode>::case_type;
  private:
    _xdr_case_type code_;
    union {
      InnerTransactionResultPair innerResultPair_;
      xdr::xvector<OperationResult> results_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = true;
    static const std::vector<TransactionResultCode> &_xdr_case_values() {
      static const std::vector<TransactionResultCode> _xdr_disc_vec {};
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == txFEE_BUMP_INNER_SUCCESS || which == txFEE_BUMP_INNER_FAILED ? 1
        : which == txSUCCESS || which == txFAILED ? 2
        : 0;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case txFEE_BUMP_INNER_SUCCESS:
      case txFEE_BUMP_INNER_FAILED:
        _f(&_result_t::innerResultPair_, std::forward<_A>(_a)...);
        return true;
      case txSUCCESS:
      case txFAILED:
        _f(&_result_t::results_, std::forward<_A>(_a)...);
        return true;
      default:
        return true;
      }
    }

    _xdr_case_type _xdr_discriminant() const { return code_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of code in _result_t");
      if (fnum != _xdr_field_number(code_)) {
        this->~_result_t();
        code_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
      }
      else
        code_ = which;
    }
    explicit _result_t(TransactionResultCode which = TransactionResultCode{}) : code_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this);
    }
    _result_t(const _result_t &source) : code_(source.code_) {
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this, source);
    }
    _result_t(_result_t &&source) : code_(source.code_) {
      _xdr_with_mem_ptr(xdr::field_constructor, code_, *this,
                        std::move(source));
    }
    ~_result_t() { _xdr_with_mem_ptr(xdr::field_destructor, code_, *this); }
    _result_t &operator=(const _result_t &source) {
      if (_xdr_field_number(code_)
          == _xdr_field_number(source.code_))
        _xdr_with_mem_ptr(xdr::field_assigner, code_, *this, source);
      else {
        this->~_result_t();
        code_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this, source);
      }
      code_ = source.code_;
      return *this;
    }
    _result_t &operator=(_result_t &&source) {
      if (_xdr_field_number(code_)
           == _xdr_field_number(source.code_))
        _xdr_with_mem_ptr(xdr::field_assigner, code_, *this,
                          std::move(source));
      else {
        this->~_result_t();
        code_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.code_, *this,
                          std::move(source));
      }
      code_ = source.code_;
      return *this;
    }

    TransactionResultCode code() const { return TransactionResultCode(code_); }
    _result_t &code(TransactionResultCode _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    InnerTransactionResultPair &innerResultPair() {
      if (_xdr_field_number(code_) == 1)
        return innerResultPair_;
      throw xdr::xdr_wrong_union("_result_t: innerResultPair accessed when not selected");
    }
    const InnerTransactionResultPair &innerResultPair() const {
      if (_xdr_field_number(code_) == 1)
        return innerResultPair_;
      throw xdr::xdr_wrong_union("_result_t: innerResultPair accessed when not selected");
    }
    xdr::xvector<OperationResult> &results() {
      if (_xdr_field_number(code_) == 2)
        return results_;
      throw xdr::xdr_wrong_union("_result_t: results accessed when not selected");
    }
    const xdr::xvector<OperationResult> &results() const {
      if (_xdr_field_number(code_) == 2)
        return results_;
      throw xdr::xdr_wrong_union("_result_t: results accessed when not selected");
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

  int64 feeCharged{};
  _result_t result{};
  _ext_t ext{};

  TransactionResult() = default;
  template<typename _feeCharged_T,
           typename _result_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<int64, _feeCharged_T>::value
                          && std::is_constructible<_result_t, _result_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit TransactionResult(_feeCharged_T &&_feeCharged,
                             _result_T &&_result,
                             _ext_T &&_ext)
    : feeCharged(std::forward<_feeCharged_T>(_feeCharged)),
      result(std::forward<_result_T>(_result)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TransactionResult::_result_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TransactionResult::_result_t;
  using case_type = ::stellar::TransactionResult::_result_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().code());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "innerResultPair";
    case 2:
      return "results";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TransactionResult::_result_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of code in _result_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionResult::_result_t &obj) {
    xdr::archive(ar, obj.code(), "code");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of code in _result_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionResult::_result_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "code");
    obj.code(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.code(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TransactionResult::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TransactionResult::_ext_t;
  using case_type = ::stellar::TransactionResult::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TransactionResult::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionResult::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionResult::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TransactionResult>
  : xdr_struct_base<field_ptr<::stellar::TransactionResult,
                              decltype(::stellar::TransactionResult::feeCharged),
                              &::stellar::TransactionResult::feeCharged>,
                    field_ptr<::stellar::TransactionResult,
                              decltype(::stellar::TransactionResult::result),
                              &::stellar::TransactionResult::result>,
                    field_ptr<::stellar::TransactionResult,
                              decltype(::stellar::TransactionResult::ext),
                              &::stellar::TransactionResult::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TransactionResult &obj) {
    archive(ar, obj.feeCharged, "feeCharged");
    archive(ar, obj.result, "result");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TransactionResult &obj) {
    archive(ar, obj.feeCharged, "feeCharged");
    archive(ar, obj.result, "result");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

}

#endif // !__XDR_SRC_GENERATED_XDR_STELLAR_TRANSACTION_H_INCLUDED__
