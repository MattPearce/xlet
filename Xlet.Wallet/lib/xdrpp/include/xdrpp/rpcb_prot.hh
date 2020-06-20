// -*- C++ -*-
// Automatically generated from rpcb_prot.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_RPCB_PROT_HH_INCLUDED__
#define __XDR_RPCB_PROT_HH_INCLUDED__ 1

#include <xdrpp/types.h>

namespace xdr {

Constexpr const std::uint32_t RPCB_PORT = 111;

struct rpcb {
  std::uint32_t r_prog{};
  std::uint32_t r_vers{};
  xdr::xstring<> r_netid{};
  xdr::xstring<> r_addr{};
  xdr::xstring<> r_owner{};

  rpcb() = default;
  template<typename _r_prog_T,
           typename _r_vers_T,
           typename _r_netid_T,
           typename _r_addr_T,
           typename _r_owner_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _r_prog_T>::value
                          && std::is_constructible<std::uint32_t, _r_vers_T>::value
                          && std::is_constructible<xdr::xstring<>, _r_netid_T>::value
                          && std::is_constructible<xdr::xstring<>, _r_addr_T>::value
                          && std::is_constructible<xdr::xstring<>, _r_owner_T>::value
                         >::type>
  explicit rpcb(_r_prog_T &&_r_prog,
                _r_vers_T &&_r_vers,
                _r_netid_T &&_r_netid,
                _r_addr_T &&_r_addr,
                _r_owner_T &&_r_owner)
    : r_prog(std::forward<_r_prog_T>(_r_prog)),
      r_vers(std::forward<_r_vers_T>(_r_vers)),
      r_netid(std::forward<_r_netid_T>(_r_netid)),
      r_addr(std::forward<_r_addr_T>(_r_addr)),
      r_owner(std::forward<_r_owner_T>(_r_owner)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcb>
  : xdr_struct_base<field_ptr<::xdr::rpcb,
                              decltype(::xdr::rpcb::r_prog),
                              &::xdr::rpcb::r_prog>,
                    field_ptr<::xdr::rpcb,
                              decltype(::xdr::rpcb::r_vers),
                              &::xdr::rpcb::r_vers>,
                    field_ptr<::xdr::rpcb,
                              decltype(::xdr::rpcb::r_netid),
                              &::xdr::rpcb::r_netid>,
                    field_ptr<::xdr::rpcb,
                              decltype(::xdr::rpcb::r_addr),
                              &::xdr::rpcb::r_addr>,
                    field_ptr<::xdr::rpcb,
                              decltype(::xdr::rpcb::r_owner),
                              &::xdr::rpcb::r_owner>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcb &obj) {
    archive(ar, obj.r_prog, "r_prog");
    archive(ar, obj.r_vers, "r_vers");
    archive(ar, obj.r_netid, "r_netid");
    archive(ar, obj.r_addr, "r_addr");
    archive(ar, obj.r_owner, "r_owner");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcb &obj) {
    archive(ar, obj.r_prog, "r_prog");
    archive(ar, obj.r_vers, "r_vers");
    archive(ar, obj.r_netid, "r_netid");
    archive(ar, obj.r_addr, "r_addr");
    archive(ar, obj.r_owner, "r_owner");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rp__list {
  rpcb rpcb_map{};
  xdr::pointer<rp__list> rpcb_next{};

  rp__list() = default;
  template<typename _rpcb_map_T,
           typename _rpcb_next_T,
           typename = typename
           std::enable_if<std::is_constructible<rpcb, _rpcb_map_T>::value
                          && std::is_constructible<xdr::pointer<rp__list>, _rpcb_next_T>::value
                         >::type>
  explicit rp__list(_rpcb_map_T &&_rpcb_map,
                    _rpcb_next_T &&_rpcb_next)
    : rpcb_map(std::forward<_rpcb_map_T>(_rpcb_map)),
      rpcb_next(std::forward<_rpcb_next_T>(_rpcb_next)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rp__list>
  : xdr_struct_base<field_ptr<::xdr::rp__list,
                              decltype(::xdr::rp__list::rpcb_map),
                              &::xdr::rp__list::rpcb_map>,
                    field_ptr<::xdr::rp__list,
                              decltype(::xdr::rp__list::rpcb_next),
                              &::xdr::rp__list::rpcb_next>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rp__list &obj) {
    archive(ar, obj.rpcb_map, "rpcb_map");
    archive(ar, obj.rpcb_next, "rpcb_next");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rp__list &obj) {
    archive(ar, obj.rpcb_map, "rpcb_map");
    archive(ar, obj.rpcb_next, "rpcb_next");
    xdr::validate(obj);
  }
};
} namespace xdr {

using rpcblist_ptr = xdr::pointer<rp__list>;

struct rpcb_rmtcallargs {
  std::uint32_t prog{};
  std::uint32_t vers{};
  std::uint32_t proc{};
  xdr::opaque_vec<> args{};

  rpcb_rmtcallargs() = default;
  template<typename _prog_T,
           typename _vers_T,
           typename _proc_T,
           typename _args_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _prog_T>::value
                          && std::is_constructible<std::uint32_t, _vers_T>::value
                          && std::is_constructible<std::uint32_t, _proc_T>::value
                          && std::is_constructible<xdr::opaque_vec<>, _args_T>::value
                         >::type>
  explicit rpcb_rmtcallargs(_prog_T &&_prog,
                            _vers_T &&_vers,
                            _proc_T &&_proc,
                            _args_T &&_args)
    : prog(std::forward<_prog_T>(_prog)),
      vers(std::forward<_vers_T>(_vers)),
      proc(std::forward<_proc_T>(_proc)),
      args(std::forward<_args_T>(_args)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcb_rmtcallargs>
  : xdr_struct_base<field_ptr<::xdr::rpcb_rmtcallargs,
                              decltype(::xdr::rpcb_rmtcallargs::prog),
                              &::xdr::rpcb_rmtcallargs::prog>,
                    field_ptr<::xdr::rpcb_rmtcallargs,
                              decltype(::xdr::rpcb_rmtcallargs::vers),
                              &::xdr::rpcb_rmtcallargs::vers>,
                    field_ptr<::xdr::rpcb_rmtcallargs,
                              decltype(::xdr::rpcb_rmtcallargs::proc),
                              &::xdr::rpcb_rmtcallargs::proc>,
                    field_ptr<::xdr::rpcb_rmtcallargs,
                              decltype(::xdr::rpcb_rmtcallargs::args),
                              &::xdr::rpcb_rmtcallargs::args>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcb_rmtcallargs &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.args, "args");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcb_rmtcallargs &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.args, "args");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rpcb_rmtcallres {
  xdr::xstring<> addr{};
  xdr::opaque_vec<> results{};

  rpcb_rmtcallres() = default;
  template<typename _addr_T,
           typename _results_T,
           typename = typename
           std::enable_if<std::is_constructible<xdr::xstring<>, _addr_T>::value
                          && std::is_constructible<xdr::opaque_vec<>, _results_T>::value
                         >::type>
  explicit rpcb_rmtcallres(_addr_T &&_addr,
                           _results_T &&_results)
    : addr(std::forward<_addr_T>(_addr)),
      results(std::forward<_results_T>(_results)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcb_rmtcallres>
  : xdr_struct_base<field_ptr<::xdr::rpcb_rmtcallres,
                              decltype(::xdr::rpcb_rmtcallres::addr),
                              &::xdr::rpcb_rmtcallres::addr>,
                    field_ptr<::xdr::rpcb_rmtcallres,
                              decltype(::xdr::rpcb_rmtcallres::results),
                              &::xdr::rpcb_rmtcallres::results>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcb_rmtcallres &obj) {
    archive(ar, obj.addr, "addr");
    archive(ar, obj.results, "results");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcb_rmtcallres &obj) {
    archive(ar, obj.addr, "addr");
    archive(ar, obj.results, "results");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rpcb_entry {
  xdr::xstring<> r_maddr{};
  xdr::xstring<> r_nc_netid{};
  std::uint32_t r_nc_semantics{};
  xdr::xstring<> r_nc_protofmly{};
  xdr::xstring<> r_nc_proto{};

  rpcb_entry() = default;
  template<typename _r_maddr_T,
           typename _r_nc_netid_T,
           typename _r_nc_semantics_T,
           typename _r_nc_protofmly_T,
           typename _r_nc_proto_T,
           typename = typename
           std::enable_if<std::is_constructible<xdr::xstring<>, _r_maddr_T>::value
                          && std::is_constructible<xdr::xstring<>, _r_nc_netid_T>::value
                          && std::is_constructible<std::uint32_t, _r_nc_semantics_T>::value
                          && std::is_constructible<xdr::xstring<>, _r_nc_protofmly_T>::value
                          && std::is_constructible<xdr::xstring<>, _r_nc_proto_T>::value
                         >::type>
  explicit rpcb_entry(_r_maddr_T &&_r_maddr,
                      _r_nc_netid_T &&_r_nc_netid,
                      _r_nc_semantics_T &&_r_nc_semantics,
                      _r_nc_protofmly_T &&_r_nc_protofmly,
                      _r_nc_proto_T &&_r_nc_proto)
    : r_maddr(std::forward<_r_maddr_T>(_r_maddr)),
      r_nc_netid(std::forward<_r_nc_netid_T>(_r_nc_netid)),
      r_nc_semantics(std::forward<_r_nc_semantics_T>(_r_nc_semantics)),
      r_nc_protofmly(std::forward<_r_nc_protofmly_T>(_r_nc_protofmly)),
      r_nc_proto(std::forward<_r_nc_proto_T>(_r_nc_proto)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcb_entry>
  : xdr_struct_base<field_ptr<::xdr::rpcb_entry,
                              decltype(::xdr::rpcb_entry::r_maddr),
                              &::xdr::rpcb_entry::r_maddr>,
                    field_ptr<::xdr::rpcb_entry,
                              decltype(::xdr::rpcb_entry::r_nc_netid),
                              &::xdr::rpcb_entry::r_nc_netid>,
                    field_ptr<::xdr::rpcb_entry,
                              decltype(::xdr::rpcb_entry::r_nc_semantics),
                              &::xdr::rpcb_entry::r_nc_semantics>,
                    field_ptr<::xdr::rpcb_entry,
                              decltype(::xdr::rpcb_entry::r_nc_protofmly),
                              &::xdr::rpcb_entry::r_nc_protofmly>,
                    field_ptr<::xdr::rpcb_entry,
                              decltype(::xdr::rpcb_entry::r_nc_proto),
                              &::xdr::rpcb_entry::r_nc_proto>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcb_entry &obj) {
    archive(ar, obj.r_maddr, "r_maddr");
    archive(ar, obj.r_nc_netid, "r_nc_netid");
    archive(ar, obj.r_nc_semantics, "r_nc_semantics");
    archive(ar, obj.r_nc_protofmly, "r_nc_protofmly");
    archive(ar, obj.r_nc_proto, "r_nc_proto");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcb_entry &obj) {
    archive(ar, obj.r_maddr, "r_maddr");
    archive(ar, obj.r_nc_netid, "r_nc_netid");
    archive(ar, obj.r_nc_semantics, "r_nc_semantics");
    archive(ar, obj.r_nc_protofmly, "r_nc_protofmly");
    archive(ar, obj.r_nc_proto, "r_nc_proto");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rpcb_entry_list {
  rpcb_entry rpcb_entry_map{};
  xdr::pointer<rpcb_entry_list> rpcb_entry_next{};

  rpcb_entry_list() = default;
  template<typename _rpcb_entry_map_T,
           typename _rpcb_entry_next_T,
           typename = typename
           std::enable_if<std::is_constructible<rpcb_entry, _rpcb_entry_map_T>::value
                          && std::is_constructible<xdr::pointer<rpcb_entry_list>, _rpcb_entry_next_T>::value
                         >::type>
  explicit rpcb_entry_list(_rpcb_entry_map_T &&_rpcb_entry_map,
                           _rpcb_entry_next_T &&_rpcb_entry_next)
    : rpcb_entry_map(std::forward<_rpcb_entry_map_T>(_rpcb_entry_map)),
      rpcb_entry_next(std::forward<_rpcb_entry_next_T>(_rpcb_entry_next)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcb_entry_list>
  : xdr_struct_base<field_ptr<::xdr::rpcb_entry_list,
                              decltype(::xdr::rpcb_entry_list::rpcb_entry_map),
                              &::xdr::rpcb_entry_list::rpcb_entry_map>,
                    field_ptr<::xdr::rpcb_entry_list,
                              decltype(::xdr::rpcb_entry_list::rpcb_entry_next),
                              &::xdr::rpcb_entry_list::rpcb_entry_next>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcb_entry_list &obj) {
    archive(ar, obj.rpcb_entry_map, "rpcb_entry_map");
    archive(ar, obj.rpcb_entry_next, "rpcb_entry_next");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcb_entry_list &obj) {
    archive(ar, obj.rpcb_entry_map, "rpcb_entry_map");
    archive(ar, obj.rpcb_entry_next, "rpcb_entry_next");
    xdr::validate(obj);
  }
};
} namespace xdr {

using rpcb_entry_list_ptr = xdr::pointer<rpcb_entry_list>;

Constexpr const std::uint32_t rpcb_highproc_2 = 5;
Constexpr const std::uint32_t rpcb_highproc_3 = 8;
Constexpr const std::uint32_t rpcb_highproc_4 = 12;
Constexpr const std::uint32_t RPCBSTAT_HIGHPROC = 13;
Constexpr const std::uint32_t RPCBVERS_STAT = 3;
Constexpr const std::uint32_t RPCBVERS_4_STAT = 2;
Constexpr const std::uint32_t RPCBVERS_3_STAT = 1;
Constexpr const std::uint32_t RPCBVERS_2_STAT = 0;

struct rpcbs_addrlist {
  std::uint32_t prog{};
  std::uint32_t vers{};
  std::int32_t success{};
  std::int32_t failure{};
  xdr::xstring<> netid{};
  xdr::pointer<rpcbs_addrlist> next{};

  rpcbs_addrlist() = default;
  template<typename _prog_T,
           typename _vers_T,
           typename _success_T,
           typename _failure_T,
           typename _netid_T,
           typename _next_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _prog_T>::value
                          && std::is_constructible<std::uint32_t, _vers_T>::value
                          && std::is_constructible<std::int32_t, _success_T>::value
                          && std::is_constructible<std::int32_t, _failure_T>::value
                          && std::is_constructible<xdr::xstring<>, _netid_T>::value
                          && std::is_constructible<xdr::pointer<rpcbs_addrlist>, _next_T>::value
                         >::type>
  explicit rpcbs_addrlist(_prog_T &&_prog,
                          _vers_T &&_vers,
                          _success_T &&_success,
                          _failure_T &&_failure,
                          _netid_T &&_netid,
                          _next_T &&_next)
    : prog(std::forward<_prog_T>(_prog)),
      vers(std::forward<_vers_T>(_vers)),
      success(std::forward<_success_T>(_success)),
      failure(std::forward<_failure_T>(_failure)),
      netid(std::forward<_netid_T>(_netid)),
      next(std::forward<_next_T>(_next)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcbs_addrlist>
  : xdr_struct_base<field_ptr<::xdr::rpcbs_addrlist,
                              decltype(::xdr::rpcbs_addrlist::prog),
                              &::xdr::rpcbs_addrlist::prog>,
                    field_ptr<::xdr::rpcbs_addrlist,
                              decltype(::xdr::rpcbs_addrlist::vers),
                              &::xdr::rpcbs_addrlist::vers>,
                    field_ptr<::xdr::rpcbs_addrlist,
                              decltype(::xdr::rpcbs_addrlist::success),
                              &::xdr::rpcbs_addrlist::success>,
                    field_ptr<::xdr::rpcbs_addrlist,
                              decltype(::xdr::rpcbs_addrlist::failure),
                              &::xdr::rpcbs_addrlist::failure>,
                    field_ptr<::xdr::rpcbs_addrlist,
                              decltype(::xdr::rpcbs_addrlist::netid),
                              &::xdr::rpcbs_addrlist::netid>,
                    field_ptr<::xdr::rpcbs_addrlist,
                              decltype(::xdr::rpcbs_addrlist::next),
                              &::xdr::rpcbs_addrlist::next>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcbs_addrlist &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.success, "success");
    archive(ar, obj.failure, "failure");
    archive(ar, obj.netid, "netid");
    archive(ar, obj.next, "next");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcbs_addrlist &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.success, "success");
    archive(ar, obj.failure, "failure");
    archive(ar, obj.netid, "netid");
    archive(ar, obj.next, "next");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct rpcbs_rmtcalllist {
  std::uint32_t prog{};
  std::uint32_t vers{};
  std::uint32_t proc{};
  std::int32_t success{};
  std::int32_t failure{};
  std::int32_t indirect{};
  xdr::xstring<> netid{};
  xdr::pointer<rpcbs_rmtcalllist> next{};

  rpcbs_rmtcalllist() = default;
  template<typename _prog_T,
           typename _vers_T,
           typename _proc_T,
           typename _success_T,
           typename _failure_T,
           typename _indirect_T,
           typename _netid_T,
           typename _next_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _prog_T>::value
                          && std::is_constructible<std::uint32_t, _vers_T>::value
                          && std::is_constructible<std::uint32_t, _proc_T>::value
                          && std::is_constructible<std::int32_t, _success_T>::value
                          && std::is_constructible<std::int32_t, _failure_T>::value
                          && std::is_constructible<std::int32_t, _indirect_T>::value
                          && std::is_constructible<xdr::xstring<>, _netid_T>::value
                          && std::is_constructible<xdr::pointer<rpcbs_rmtcalllist>, _next_T>::value
                         >::type>
  explicit rpcbs_rmtcalllist(_prog_T &&_prog,
                             _vers_T &&_vers,
                             _proc_T &&_proc,
                             _success_T &&_success,
                             _failure_T &&_failure,
                             _indirect_T &&_indirect,
                             _netid_T &&_netid,
                             _next_T &&_next)
    : prog(std::forward<_prog_T>(_prog)),
      vers(std::forward<_vers_T>(_vers)),
      proc(std::forward<_proc_T>(_proc)),
      success(std::forward<_success_T>(_success)),
      failure(std::forward<_failure_T>(_failure)),
      indirect(std::forward<_indirect_T>(_indirect)),
      netid(std::forward<_netid_T>(_netid)),
      next(std::forward<_next_T>(_next)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcbs_rmtcalllist>
  : xdr_struct_base<field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::prog),
                              &::xdr::rpcbs_rmtcalllist::prog>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::vers),
                              &::xdr::rpcbs_rmtcalllist::vers>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::proc),
                              &::xdr::rpcbs_rmtcalllist::proc>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::success),
                              &::xdr::rpcbs_rmtcalllist::success>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::failure),
                              &::xdr::rpcbs_rmtcalllist::failure>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::indirect),
                              &::xdr::rpcbs_rmtcalllist::indirect>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::netid),
                              &::xdr::rpcbs_rmtcalllist::netid>,
                    field_ptr<::xdr::rpcbs_rmtcalllist,
                              decltype(::xdr::rpcbs_rmtcalllist::next),
                              &::xdr::rpcbs_rmtcalllist::next>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcbs_rmtcalllist &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.success, "success");
    archive(ar, obj.failure, "failure");
    archive(ar, obj.indirect, "indirect");
    archive(ar, obj.netid, "netid");
    archive(ar, obj.next, "next");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcbs_rmtcalllist &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.success, "success");
    archive(ar, obj.failure, "failure");
    archive(ar, obj.indirect, "indirect");
    archive(ar, obj.netid, "netid");
    archive(ar, obj.next, "next");
    xdr::validate(obj);
  }
};
} namespace xdr {

using rpcbs_proc = xdr::xarray<std::int32_t,RPCBSTAT_HIGHPROC>;
using rpcbs_addrlist_ptr = xdr::pointer<rpcbs_addrlist>;
using rpcbs_rmtcalllist_ptr = xdr::pointer<rpcbs_rmtcalllist>;

struct rpcb_stat {
  rpcbs_proc info{};
  std::int32_t setinfo{};
  std::int32_t unsetinfo{};
  rpcbs_addrlist_ptr addrinfo{};
  rpcbs_rmtcalllist_ptr rmtinfo{};

  rpcb_stat() = default;
  template<typename _info_T,
           typename _setinfo_T,
           typename _unsetinfo_T,
           typename _addrinfo_T,
           typename _rmtinfo_T,
           typename = typename
           std::enable_if<std::is_constructible<rpcbs_proc, _info_T>::value
                          && std::is_constructible<std::int32_t, _setinfo_T>::value
                          && std::is_constructible<std::int32_t, _unsetinfo_T>::value
                          && std::is_constructible<rpcbs_addrlist_ptr, _addrinfo_T>::value
                          && std::is_constructible<rpcbs_rmtcalllist_ptr, _rmtinfo_T>::value
                         >::type>
  explicit rpcb_stat(_info_T &&_info,
                     _setinfo_T &&_setinfo,
                     _unsetinfo_T &&_unsetinfo,
                     _addrinfo_T &&_addrinfo,
                     _rmtinfo_T &&_rmtinfo)
    : info(std::forward<_info_T>(_info)),
      setinfo(std::forward<_setinfo_T>(_setinfo)),
      unsetinfo(std::forward<_unsetinfo_T>(_unsetinfo)),
      addrinfo(std::forward<_addrinfo_T>(_addrinfo)),
      rmtinfo(std::forward<_rmtinfo_T>(_rmtinfo)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::rpcb_stat>
  : xdr_struct_base<field_ptr<::xdr::rpcb_stat,
                              decltype(::xdr::rpcb_stat::info),
                              &::xdr::rpcb_stat::info>,
                    field_ptr<::xdr::rpcb_stat,
                              decltype(::xdr::rpcb_stat::setinfo),
                              &::xdr::rpcb_stat::setinfo>,
                    field_ptr<::xdr::rpcb_stat,
                              decltype(::xdr::rpcb_stat::unsetinfo),
                              &::xdr::rpcb_stat::unsetinfo>,
                    field_ptr<::xdr::rpcb_stat,
                              decltype(::xdr::rpcb_stat::addrinfo),
                              &::xdr::rpcb_stat::addrinfo>,
                    field_ptr<::xdr::rpcb_stat,
                              decltype(::xdr::rpcb_stat::rmtinfo),
                              &::xdr::rpcb_stat::rmtinfo>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::rpcb_stat &obj) {
    archive(ar, obj.info, "info");
    archive(ar, obj.setinfo, "setinfo");
    archive(ar, obj.unsetinfo, "unsetinfo");
    archive(ar, obj.addrinfo, "addrinfo");
    archive(ar, obj.rmtinfo, "rmtinfo");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::rpcb_stat &obj) {
    archive(ar, obj.info, "info");
    archive(ar, obj.setinfo, "setinfo");
    archive(ar, obj.unsetinfo, "unsetinfo");
    archive(ar, obj.addrinfo, "addrinfo");
    archive(ar, obj.rmtinfo, "rmtinfo");
    xdr::validate(obj);
  }
};
} namespace xdr {

using rpcb_stat_byvers = xdr::xarray<rpcb_stat,RPCBVERS_STAT>;

struct netbuf {
  std::uint32_t maxlen{};
  xdr::opaque_vec<> buf{};

  netbuf() = default;
  template<typename _maxlen_T,
           typename _buf_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _maxlen_T>::value
                          && std::is_constructible<xdr::opaque_vec<>, _buf_T>::value
                         >::type>
  explicit netbuf(_maxlen_T &&_maxlen,
                  _buf_T &&_buf)
    : maxlen(std::forward<_maxlen_T>(_maxlen)),
      buf(std::forward<_buf_T>(_buf)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::netbuf>
  : xdr_struct_base<field_ptr<::xdr::netbuf,
                              decltype(::xdr::netbuf::maxlen),
                              &::xdr::netbuf::maxlen>,
                    field_ptr<::xdr::netbuf,
                              decltype(::xdr::netbuf::buf),
                              &::xdr::netbuf::buf>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::netbuf &obj) {
    archive(ar, obj.maxlen, "maxlen");
    archive(ar, obj.buf, "buf");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::netbuf &obj) {
    archive(ar, obj.maxlen, "maxlen");
    archive(ar, obj.buf, "buf");
    xdr::validate(obj);
  }
};
} namespace xdr {

using rpcb_string = xdr::xstring<>;

struct RPCBVERS {
  static Constexpr const std::uint32_t program = 100000;
  static Constexpr const char *program_name() { return "RPCBPROG"; }
  static Constexpr const std::uint32_t version = 3;
  static Constexpr const char *version_name() { return "RPCBVERS"; }

  struct RPCBPROC3_SET_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 1;
    static Constexpr const char *proc_name() { return "RPCBPROC3_SET"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = bool;
    using res_wire_type = bool;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_SET(std::forward<A>(a)...)) {
      return c.RPCBPROC3_SET(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_UNSET_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 2;
    static Constexpr const char *proc_name() { return "RPCBPROC3_UNSET"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = bool;
    using res_wire_type = bool;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_UNSET(std::forward<A>(a)...)) {
      return c.RPCBPROC3_UNSET(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_GETADDR_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 3;
    static Constexpr const char *proc_name() { return "RPCBPROC3_GETADDR"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = rpcb_string;
    using res_wire_type = rpcb_string;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_GETADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC3_GETADDR(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_DUMP_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 4;
    static Constexpr const char *proc_name() { return "RPCBPROC3_DUMP"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = rpcblist_ptr;
    using res_wire_type = rpcblist_ptr;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_DUMP(std::forward<A>(a)...)) {
      return c.RPCBPROC3_DUMP(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_CALLIT_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 5;
    static Constexpr const char *proc_name() { return "RPCBPROC3_CALLIT"; }
    using arg_type = rpcb_rmtcallargs;
    using arg_tuple_type = std::tuple<rpcb_rmtcallargs>;
    using res_type = rpcb_rmtcallres;
    using res_wire_type = rpcb_rmtcallres;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_CALLIT(std::forward<A>(a)...)) {
      return c.RPCBPROC3_CALLIT(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_GETTIME_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 6;
    static Constexpr const char *proc_name() { return "RPCBPROC3_GETTIME"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = unsigned;
    using res_wire_type = unsigned;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_GETTIME(std::forward<A>(a)...)) {
      return c.RPCBPROC3_GETTIME(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_UADDR2TADDR_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 7;
    static Constexpr const char *proc_name() { return "RPCBPROC3_UADDR2TADDR"; }
    using arg_type = rpcb_string;
    using arg_tuple_type = std::tuple<rpcb_string>;
    using res_type = netbuf;
    using res_wire_type = netbuf;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_UADDR2TADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC3_UADDR2TADDR(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC3_TADDR2UADDR_t {
    using interface_type = RPCBVERS;
    static Constexpr const std::uint32_t proc = 8;
    static Constexpr const char *proc_name() { return "RPCBPROC3_TADDR2UADDR"; }
    using arg_type = netbuf;
    using arg_tuple_type = std::tuple<netbuf>;
    using res_type = rpcb_string;
    using res_wire_type = rpcb_string;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC3_TADDR2UADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC3_TADDR2UADDR(std::forward<A>(a)...);
    }
  };

  template<typename T, typename...A> static bool
  call_dispatch(T &&t, std::uint32_t proc, A &&...a) {
    switch(proc) {
    case 1:
      t.template dispatch<RPCBPROC3_SET_t>(std::forward<A>(a)...);
      return true;
    case 2:
      t.template dispatch<RPCBPROC3_UNSET_t>(std::forward<A>(a)...);
      return true;
    case 3:
      t.template dispatch<RPCBPROC3_GETADDR_t>(std::forward<A>(a)...);
      return true;
    case 4:
      t.template dispatch<RPCBPROC3_DUMP_t>(std::forward<A>(a)...);
      return true;
    case 5:
      t.template dispatch<RPCBPROC3_CALLIT_t>(std::forward<A>(a)...);
      return true;
    case 6:
      t.template dispatch<RPCBPROC3_GETTIME_t>(std::forward<A>(a)...);
      return true;
    case 7:
      t.template dispatch<RPCBPROC3_UADDR2TADDR_t>(std::forward<A>(a)...);
      return true;
    case 8:
      t.template dispatch<RPCBPROC3_TADDR2UADDR_t>(std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  template<typename _XDR_INVOKER> struct _xdr_client {
    _XDR_INVOKER _xdr_invoker_;
    template<typename...ARGS> _xdr_client(ARGS &&...args)
      : _xdr_invoker_(std::forward<ARGS>(args)...) {}

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_SET(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_SET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_SET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_UNSET(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_UNSET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_UNSET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_GETADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_GETADDR_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_GETADDR_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_DUMP(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_DUMP_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_DUMP_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_CALLIT(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_CALLIT_t,
                                            rpcb_rmtcallargs>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_CALLIT_t,
                                            rpcb_rmtcallargs>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_GETTIME(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_GETTIME_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_GETTIME_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_UADDR2TADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_UADDR2TADDR_t,
                                            rpcb_string>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_UADDR2TADDR_t,
                                            rpcb_string>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC3_TADDR2UADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC3_TADDR2UADDR_t,
                                            netbuf>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC3_TADDR2UADDR_t,
                                            netbuf>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }
  };
};

struct RPCBVERS4 {
  static Constexpr const std::uint32_t program = 100000;
  static Constexpr const char *program_name() { return "RPCBPROG"; }
  static Constexpr const std::uint32_t version = 4;
  static Constexpr const char *version_name() { return "RPCBVERS4"; }

  struct RPCBPROC_SET_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 1;
    static Constexpr const char *proc_name() { return "RPCBPROC_SET"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = bool;
    using res_wire_type = bool;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_SET(std::forward<A>(a)...)) {
      return c.RPCBPROC_SET(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_UNSET_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 2;
    static Constexpr const char *proc_name() { return "RPCBPROC_UNSET"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = bool;
    using res_wire_type = bool;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_UNSET(std::forward<A>(a)...)) {
      return c.RPCBPROC_UNSET(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_GETADDR_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 3;
    static Constexpr const char *proc_name() { return "RPCBPROC_GETADDR"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = rpcb_string;
    using res_wire_type = rpcb_string;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_GETADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC_GETADDR(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_DUMP_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 4;
    static Constexpr const char *proc_name() { return "RPCBPROC_DUMP"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = rpcblist_ptr;
    using res_wire_type = rpcblist_ptr;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_DUMP(std::forward<A>(a)...)) {
      return c.RPCBPROC_DUMP(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_BCAST_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 5;
    static Constexpr const char *proc_name() { return "RPCBPROC_BCAST"; }
    using arg_type = rpcb_rmtcallargs;
    using arg_tuple_type = std::tuple<rpcb_rmtcallargs>;
    using res_type = rpcb_rmtcallres;
    using res_wire_type = rpcb_rmtcallres;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_BCAST(std::forward<A>(a)...)) {
      return c.RPCBPROC_BCAST(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_GETTIME_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 6;
    static Constexpr const char *proc_name() { return "RPCBPROC_GETTIME"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = unsigned;
    using res_wire_type = unsigned;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_GETTIME(std::forward<A>(a)...)) {
      return c.RPCBPROC_GETTIME(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_UADDR2TADDR_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 7;
    static Constexpr const char *proc_name() { return "RPCBPROC_UADDR2TADDR"; }
    using arg_type = rpcb_string;
    using arg_tuple_type = std::tuple<rpcb_string>;
    using res_type = netbuf;
    using res_wire_type = netbuf;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_UADDR2TADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC_UADDR2TADDR(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_TADDR2UADDR_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 8;
    static Constexpr const char *proc_name() { return "RPCBPROC_TADDR2UADDR"; }
    using arg_type = netbuf;
    using arg_tuple_type = std::tuple<netbuf>;
    using res_type = rpcb_string;
    using res_wire_type = rpcb_string;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_TADDR2UADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC_TADDR2UADDR(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_GETVERSADDR_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 9;
    static Constexpr const char *proc_name() { return "RPCBPROC_GETVERSADDR"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = rpcb_string;
    using res_wire_type = rpcb_string;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_GETVERSADDR(std::forward<A>(a)...)) {
      return c.RPCBPROC_GETVERSADDR(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_INDIRECT_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 10;
    static Constexpr const char *proc_name() { return "RPCBPROC_INDIRECT"; }
    using arg_type = rpcb_rmtcallargs;
    using arg_tuple_type = std::tuple<rpcb_rmtcallargs>;
    using res_type = rpcb_rmtcallres;
    using res_wire_type = rpcb_rmtcallres;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_INDIRECT(std::forward<A>(a)...)) {
      return c.RPCBPROC_INDIRECT(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_GETADDRLIST_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 11;
    static Constexpr const char *proc_name() { return "RPCBPROC_GETADDRLIST"; }
    using arg_type = rpcb;
    using arg_tuple_type = std::tuple<rpcb>;
    using res_type = rpcb_entry_list_ptr;
    using res_wire_type = rpcb_entry_list_ptr;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_GETADDRLIST(std::forward<A>(a)...)) {
      return c.RPCBPROC_GETADDRLIST(std::forward<A>(a)...);
    }
  };

  struct RPCBPROC_GETSTAT_t {
    using interface_type = RPCBVERS4;
    static Constexpr const std::uint32_t proc = 12;
    static Constexpr const char *proc_name() { return "RPCBPROC_GETSTAT"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = rpcb_stat_byvers;
    using res_wire_type = rpcb_stat_byvers;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.RPCBPROC_GETSTAT(std::forward<A>(a)...)) {
      return c.RPCBPROC_GETSTAT(std::forward<A>(a)...);
    }
  };

  template<typename T, typename...A> static bool
  call_dispatch(T &&t, std::uint32_t proc, A &&...a) {
    switch(proc) {
    case 1:
      t.template dispatch<RPCBPROC_SET_t>(std::forward<A>(a)...);
      return true;
    case 2:
      t.template dispatch<RPCBPROC_UNSET_t>(std::forward<A>(a)...);
      return true;
    case 3:
      t.template dispatch<RPCBPROC_GETADDR_t>(std::forward<A>(a)...);
      return true;
    case 4:
      t.template dispatch<RPCBPROC_DUMP_t>(std::forward<A>(a)...);
      return true;
    case 5:
      t.template dispatch<RPCBPROC_BCAST_t>(std::forward<A>(a)...);
      return true;
    case 6:
      t.template dispatch<RPCBPROC_GETTIME_t>(std::forward<A>(a)...);
      return true;
    case 7:
      t.template dispatch<RPCBPROC_UADDR2TADDR_t>(std::forward<A>(a)...);
      return true;
    case 8:
      t.template dispatch<RPCBPROC_TADDR2UADDR_t>(std::forward<A>(a)...);
      return true;
    case 9:
      t.template dispatch<RPCBPROC_GETVERSADDR_t>(std::forward<A>(a)...);
      return true;
    case 10:
      t.template dispatch<RPCBPROC_INDIRECT_t>(std::forward<A>(a)...);
      return true;
    case 11:
      t.template dispatch<RPCBPROC_GETADDRLIST_t>(std::forward<A>(a)...);
      return true;
    case 12:
      t.template dispatch<RPCBPROC_GETSTAT_t>(std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  template<typename _XDR_INVOKER> struct _xdr_client {
    _XDR_INVOKER _xdr_invoker_;
    template<typename...ARGS> _xdr_client(ARGS &&...args)
      : _xdr_invoker_(std::forward<ARGS>(args)...) {}

    template<typename..._XDR_ARGS> auto
    RPCBPROC_SET(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_SET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_SET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_UNSET(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_UNSET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_UNSET_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_GETADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_GETADDR_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_GETADDR_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_DUMP(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_DUMP_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_DUMP_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_BCAST(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_BCAST_t,
                                            rpcb_rmtcallargs>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_BCAST_t,
                                            rpcb_rmtcallargs>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_GETTIME(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_GETTIME_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_GETTIME_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_UADDR2TADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_UADDR2TADDR_t,
                                            rpcb_string>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_UADDR2TADDR_t,
                                            rpcb_string>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_TADDR2UADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_TADDR2UADDR_t,
                                            netbuf>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_TADDR2UADDR_t,
                                            netbuf>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_GETVERSADDR(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_GETVERSADDR_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_GETVERSADDR_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_INDIRECT(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_INDIRECT_t,
                                            rpcb_rmtcallargs>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_INDIRECT_t,
                                            rpcb_rmtcallargs>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_GETADDRLIST(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_GETADDRLIST_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_GETADDRLIST_t,
                                            rpcb>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    RPCBPROC_GETSTAT(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<RPCBPROC_GETSTAT_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<RPCBPROC_GETSTAT_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }
  };
};

Constexpr const std::uint32_t PMAP_PORT = 111;

struct mapping {
  std::uint32_t prog{};
  std::uint32_t vers{};
  std::uint32_t prot{};
  std::uint32_t port{};

  mapping() = default;
  template<typename _prog_T,
           typename _vers_T,
           typename _prot_T,
           typename _port_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _prog_T>::value
                          && std::is_constructible<std::uint32_t, _vers_T>::value
                          && std::is_constructible<std::uint32_t, _prot_T>::value
                          && std::is_constructible<std::uint32_t, _port_T>::value
                         >::type>
  explicit mapping(_prog_T &&_prog,
                   _vers_T &&_vers,
                   _prot_T &&_prot,
                   _port_T &&_port)
    : prog(std::forward<_prog_T>(_prog)),
      vers(std::forward<_vers_T>(_vers)),
      prot(std::forward<_prot_T>(_prot)),
      port(std::forward<_port_T>(_port)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::mapping>
  : xdr_struct_base<field_ptr<::xdr::mapping,
                              decltype(::xdr::mapping::prog),
                              &::xdr::mapping::prog>,
                    field_ptr<::xdr::mapping,
                              decltype(::xdr::mapping::vers),
                              &::xdr::mapping::vers>,
                    field_ptr<::xdr::mapping,
                              decltype(::xdr::mapping::prot),
                              &::xdr::mapping::prot>,
                    field_ptr<::xdr::mapping,
                              decltype(::xdr::mapping::port),
                              &::xdr::mapping::port>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::mapping &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.prot, "prot");
    archive(ar, obj.port, "port");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::mapping &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.prot, "prot");
    archive(ar, obj.port, "port");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct pmaplist_entry {
  mapping map{};
  xdr::pointer<pmaplist_entry> next{};

  pmaplist_entry() = default;
  template<typename _map_T,
           typename _next_T,
           typename = typename
           std::enable_if<std::is_constructible<mapping, _map_T>::value
                          && std::is_constructible<xdr::pointer<pmaplist_entry>, _next_T>::value
                         >::type>
  explicit pmaplist_entry(_map_T &&_map,
                          _next_T &&_next)
    : map(std::forward<_map_T>(_map)),
      next(std::forward<_next_T>(_next)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::pmaplist_entry>
  : xdr_struct_base<field_ptr<::xdr::pmaplist_entry,
                              decltype(::xdr::pmaplist_entry::map),
                              &::xdr::pmaplist_entry::map>,
                    field_ptr<::xdr::pmaplist_entry,
                              decltype(::xdr::pmaplist_entry::next),
                              &::xdr::pmaplist_entry::next>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::pmaplist_entry &obj) {
    archive(ar, obj.map, "map");
    archive(ar, obj.next, "next");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::pmaplist_entry &obj) {
    archive(ar, obj.map, "map");
    archive(ar, obj.next, "next");
    xdr::validate(obj);
  }
};
} namespace xdr {

using pmaplist = xdr::pointer<pmaplist_entry>;

struct call_args {
  std::uint32_t prog{};
  std::uint32_t vers{};
  std::uint32_t proc{};
  xdr::opaque_vec<> args{};

  call_args() = default;
  template<typename _prog_T,
           typename _vers_T,
           typename _proc_T,
           typename _args_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _prog_T>::value
                          && std::is_constructible<std::uint32_t, _vers_T>::value
                          && std::is_constructible<std::uint32_t, _proc_T>::value
                          && std::is_constructible<xdr::opaque_vec<>, _args_T>::value
                         >::type>
  explicit call_args(_prog_T &&_prog,
                     _vers_T &&_vers,
                     _proc_T &&_proc,
                     _args_T &&_args)
    : prog(std::forward<_prog_T>(_prog)),
      vers(std::forward<_vers_T>(_vers)),
      proc(std::forward<_proc_T>(_proc)),
      args(std::forward<_args_T>(_args)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::call_args>
  : xdr_struct_base<field_ptr<::xdr::call_args,
                              decltype(::xdr::call_args::prog),
                              &::xdr::call_args::prog>,
                    field_ptr<::xdr::call_args,
                              decltype(::xdr::call_args::vers),
                              &::xdr::call_args::vers>,
                    field_ptr<::xdr::call_args,
                              decltype(::xdr::call_args::proc),
                              &::xdr::call_args::proc>,
                    field_ptr<::xdr::call_args,
                              decltype(::xdr::call_args::args),
                              &::xdr::call_args::args>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::call_args &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.args, "args");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::call_args &obj) {
    archive(ar, obj.prog, "prog");
    archive(ar, obj.vers, "vers");
    archive(ar, obj.proc, "proc");
    archive(ar, obj.args, "args");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct call_result {
  std::uint32_t port{};
  xdr::opaque_vec<> res{};

  call_result() = default;
  template<typename _port_T,
           typename _res_T,
           typename = typename
           std::enable_if<std::is_constructible<std::uint32_t, _port_T>::value
                          && std::is_constructible<xdr::opaque_vec<>, _res_T>::value
                         >::type>
  explicit call_result(_port_T &&_port,
                       _res_T &&_res)
    : port(std::forward<_port_T>(_port)),
      res(std::forward<_res_T>(_res)) {}
};
} namespace xdr {
template<> struct xdr_traits<::xdr::call_result>
  : xdr_struct_base<field_ptr<::xdr::call_result,
                              decltype(::xdr::call_result::port),
                              &::xdr::call_result::port>,
                    field_ptr<::xdr::call_result,
                              decltype(::xdr::call_result::res),
                              &::xdr::call_result::res>> {
  template<typename Archive> static void
  save(Archive &ar, const ::xdr::call_result &obj) {
    archive(ar, obj.port, "port");
    archive(ar, obj.res, "res");
  }
  template<typename Archive> static void
  load(Archive &ar, ::xdr::call_result &obj) {
    archive(ar, obj.port, "port");
    archive(ar, obj.res, "res");
    xdr::validate(obj);
  }
};
} namespace xdr {

struct PMAP_VERS {
  static Constexpr const std::uint32_t program = 100000;
  static Constexpr const char *program_name() { return "PMAP_PROG"; }
  static Constexpr const std::uint32_t version = 2;
  static Constexpr const char *version_name() { return "PMAP_VERS"; }

  struct PMAPPROC_NULL_t {
    using interface_type = PMAP_VERS;
    static Constexpr const std::uint32_t proc = 0;
    static Constexpr const char *proc_name() { return "PMAPPROC_NULL"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = void;
    using res_wire_type = xdr::xdr_void;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.PMAPPROC_NULL(std::forward<A>(a)...)) {
      return c.PMAPPROC_NULL(std::forward<A>(a)...);
    }
  };

  struct PMAPPROC_SET_t {
    using interface_type = PMAP_VERS;
    static Constexpr const std::uint32_t proc = 1;
    static Constexpr const char *proc_name() { return "PMAPPROC_SET"; }
    using arg_type = mapping;
    using arg_tuple_type = std::tuple<mapping>;
    using res_type = bool;
    using res_wire_type = bool;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.PMAPPROC_SET(std::forward<A>(a)...)) {
      return c.PMAPPROC_SET(std::forward<A>(a)...);
    }
  };

  struct PMAPPROC_UNSET_t {
    using interface_type = PMAP_VERS;
    static Constexpr const std::uint32_t proc = 2;
    static Constexpr const char *proc_name() { return "PMAPPROC_UNSET"; }
    using arg_type = mapping;
    using arg_tuple_type = std::tuple<mapping>;
    using res_type = bool;
    using res_wire_type = bool;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.PMAPPROC_UNSET(std::forward<A>(a)...)) {
      return c.PMAPPROC_UNSET(std::forward<A>(a)...);
    }
  };

  struct PMAPPROC_GETPORT_t {
    using interface_type = PMAP_VERS;
    static Constexpr const std::uint32_t proc = 3;
    static Constexpr const char *proc_name() { return "PMAPPROC_GETPORT"; }
    using arg_type = mapping;
    using arg_tuple_type = std::tuple<mapping>;
    using res_type = unsigned;
    using res_wire_type = unsigned;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.PMAPPROC_GETPORT(std::forward<A>(a)...)) {
      return c.PMAPPROC_GETPORT(std::forward<A>(a)...);
    }
  };

  struct PMAPPROC_DUMP_t {
    using interface_type = PMAP_VERS;
    static Constexpr const std::uint32_t proc = 4;
    static Constexpr const char *proc_name() { return "PMAPPROC_DUMP"; }
    using arg_type = void;
    using arg_tuple_type = std::tuple<>;
    using res_type = pmaplist;
    using res_wire_type = pmaplist;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.PMAPPROC_DUMP(std::forward<A>(a)...)) {
      return c.PMAPPROC_DUMP(std::forward<A>(a)...);
    }
  };

  struct PMAPPROC_CALLIT_t {
    using interface_type = PMAP_VERS;
    static Constexpr const std::uint32_t proc = 5;
    static Constexpr const char *proc_name() { return "PMAPPROC_CALLIT"; }
    using arg_type = call_args;
    using arg_tuple_type = std::tuple<call_args>;
    using res_type = call_result;
    using res_wire_type = call_result;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.PMAPPROC_CALLIT(std::forward<A>(a)...)) {
      return c.PMAPPROC_CALLIT(std::forward<A>(a)...);
    }
  };

  template<typename T, typename...A> static bool
  call_dispatch(T &&t, std::uint32_t proc, A &&...a) {
    switch(proc) {
    case 0:
      t.template dispatch<PMAPPROC_NULL_t>(std::forward<A>(a)...);
      return true;
    case 1:
      t.template dispatch<PMAPPROC_SET_t>(std::forward<A>(a)...);
      return true;
    case 2:
      t.template dispatch<PMAPPROC_UNSET_t>(std::forward<A>(a)...);
      return true;
    case 3:
      t.template dispatch<PMAPPROC_GETPORT_t>(std::forward<A>(a)...);
      return true;
    case 4:
      t.template dispatch<PMAPPROC_DUMP_t>(std::forward<A>(a)...);
      return true;
    case 5:
      t.template dispatch<PMAPPROC_CALLIT_t>(std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  template<typename _XDR_INVOKER> struct _xdr_client {
    _XDR_INVOKER _xdr_invoker_;
    template<typename...ARGS> _xdr_client(ARGS &&...args)
      : _xdr_invoker_(std::forward<ARGS>(args)...) {}

    template<typename..._XDR_ARGS> auto
    PMAPPROC_NULL(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<PMAPPROC_NULL_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<PMAPPROC_NULL_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    PMAPPROC_SET(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<PMAPPROC_SET_t,
                                            mapping>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<PMAPPROC_SET_t,
                                            mapping>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    PMAPPROC_UNSET(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<PMAPPROC_UNSET_t,
                                            mapping>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<PMAPPROC_UNSET_t,
                                            mapping>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    PMAPPROC_GETPORT(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<PMAPPROC_GETPORT_t,
                                            mapping>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<PMAPPROC_GETPORT_t,
                                            mapping>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    PMAPPROC_DUMP(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<PMAPPROC_DUMP_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<PMAPPROC_DUMP_t>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }

    template<typename..._XDR_ARGS> auto
    PMAPPROC_CALLIT(_XDR_ARGS &&..._xdr_args) ->
    decltype(_xdr_invoker_->template invoke<PMAPPROC_CALLIT_t,
                                            call_args>(
             std::forward<_XDR_ARGS>(_xdr_args)...)) {
      return _xdr_invoker_->template invoke<PMAPPROC_CALLIT_t,
                                            call_args>(
             std::forward<_XDR_ARGS>(_xdr_args)...);
    }
  };
};

}

#endif // !__XDR_RPCB_PROT_HH_INCLUDED__
