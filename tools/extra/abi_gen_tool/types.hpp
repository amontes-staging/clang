/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once
#include <memory>
#include <vector>
#include <deque>
#include <cstdint>

namespace fc {
   struct path {};
   struct smart_ref {};
   struct variant_object {};
   struct variant {};
   struct enum_type {};
   struct optional {};
   struct unsigned_int {};
   struct time_point_sec {};
   struct time_point {};
   struct safe {};
   struct flat_map {};
   struct flat_set {};
   struct static_variant {};
   namespace ecc {
   struct  {};
   struct  {};
   struct  {};
   struct  {};
   struct  {};
   } // namespace ecc
} // namespace fc
namespace eosio { namespace chain {
   using                               std::map;
   using                               std::vector;
   using                               std::unordered_map;
   using                               std::string;
   using                               std::deque;
   using                               std::shared_ptr;
   using                               std::weak_ptr;
   using                               std::unique_ptr;
   using                               std::set;
   using                               std::pair;
   using                               std::make_pair;
   using                               std::enable_shared_from_this;
   using                               std::tie;
   using                               std::move;
   using                               std::forward;
   using                               std::to_string;
   using                               std::all_of;

   using                               fc::path;
   using                               fc::smart_ref;
   using                               fc::variant_object;
   using                               fc::variant;
   using                               fc::enum_type;
   using                               fc::optional;
   using                               fc::unsigned_int;
   using                               fc::signed_int;
   using                               fc::time_point_sec;
   using                               fc::time_point;
   using                               fc::safe;
   using                               fc::flat_map;
   using                               fc::flat_set;
   using                               fc::static_variant;
   using                               fc::ecc::range_proof_type;
   using                               fc::ecc::range_proof_info;
   using                               fc::ecc::commitment_type;

   using public_key_type  = fc::crypto::public_key;
   using private_key_type = fc::crypto::private_key;
   using signature_type   = fc::crypto::signature;

   struct void_t{};

   using chainbase::allocator;
   using shared_string = boost::interprocess::basic_string<char, std::char_traits<char>, allocator<char>>;
   template<typename T>
   using shared_vector = boost::interprocess::vector<T, allocator<T>>;
   template<typename T>
   using shared_set = boost::interprocess::set<T, std::less<T>, allocator<T>>;

   using action_name      = name;
   using scope_name       = name;
   using account_name     = name;
   using permission_name  = name;
   using table_name       = name;


   /**
    * List all object types from all namespaces here so they can
    * be easily reflected and displayed in debug output.  If a 3rd party
    * wants to extend the core code then they will have to change the
    * packed_object::type field from enum_type to uint16 to avoid
    * warnings when converting packed_objects to/from json.
    */
   enum object_type
   {
      null_object_type,
      account_object_type,
      account_sequence_object_type,
      permission_object_type,
      permission_usage_object_type,
      permission_link_object_type,
      action_code_object_type,
      key_value_object_type,
      index64_object_type,
      index128_object_type,
      index256_object_type,
      index_double_object_type,
      index_long_double_object_type,
      global_property_object_type,
      dynamic_global_property_object_type,
      block_summary_object_type,
      transaction_object_type,
      generated_transaction_object_type,
      producer_object_type,
      chain_property_object_type,
      account_control_history_object_type, ///< Defined by account_history_plugin
      account_transaction_history_object_type, ///< Defined by account_history_plugin
      transaction_history_object_type, ///< Defined by account_history_plugin
      public_key_history_object_type, ///< Defined by account_history_plugin
      balance_object_type, ///< Defined by native_contract library
      staked_balance_object_type, ///< Defined by native_contract library
      producer_votes_object_type, ///< Defined by native_contract library
      producer_schedule_object_type, ///< Defined by native_contract library
      proxy_vote_object_type, ///< Defined by native_contract library
      scope_sequence_object_type,
      table_id_object_type,
      resource_limits_object_type,
      resource_usage_object_type,
      resource_limits_state_object_type,
      resource_limits_config_object_type,
      account_history_object_type,
      action_history_object_type,
      reversible_block_object_type,
      OBJECT_TYPE_COUNT ///< Sentry value which contains the number of different object types
   };

   class account_object;
   class producer_object;

   using block_id_type       = fc::sha256;
   using checksum_type       = fc::sha256;
   using checksum256_type    = fc::sha256;
   using checksum512_type    = fc::sha512;
   using checksum160_type    = fc::ripemd160;
   using transaction_id_type = checksum_type;
   using digest_type         = checksum_type;
   using weight_type         = uint16_t;
   using block_num_type      = uint32_t;
   using share_type          = int64_t;
   using int128_t            = __int128;
   using uint128_t           = unsigned __int128;
   using bytes               = vector<char>;


   /**
    *  Extentions are prefixed with type and are a buffer that can be
    *  interpreted by code that is aware and ignored by unaware code.
    */
   typedef vector<std::pair<uint16_t,vector<char>>> extensions_type;


} }  // eosio::chain

FC_REFLECT_ENUM(eosio::chain::object_type,
                (null_object_type)
                (account_object_type)
                (account_sequence_object_type)
                (permission_object_type)
                (permission_usage_object_type)
                (permission_link_object_type)
                (action_code_object_type)
                (key_value_object_type)
                (index64_object_type)
                (index128_object_type)
                (index256_object_type)
                (index_double_object_type)
                (index_long_double_object_type)
                (global_property_object_type)
                (dynamic_global_property_object_type)
                (block_summary_object_type)
                (transaction_object_type)
                (generated_transaction_object_type)
                (producer_object_type)
                (chain_property_object_type)
                (account_control_history_object_type)
                (account_transaction_history_object_type)
                (transaction_history_object_type)
                (public_key_history_object_type)
                (balance_object_type)
                (staked_balance_object_type)
                (producer_votes_object_type)
                (producer_schedule_object_type)
                (proxy_vote_object_type)
                (scope_sequence_object_type)
                (table_id_object_type)
                (resource_limits_object_type)
                (resource_usage_object_type)
                (resource_limits_state_object_type)
                (resource_limits_config_object_type)
                (account_history_object_type)
                (action_history_object_type)
                (reversible_block_object_type)
                (OBJECT_TYPE_COUNT)
               )
FC_REFLECT( eosio::chain::void_t, )
