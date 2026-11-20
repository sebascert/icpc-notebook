/**
 * Lines: [9,17]
 */
#pragma once
#include "template.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T, typename V>
using imap =
	tree<T, V, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using iset = imap<T, null_type>;

// Usage
// find_by_order(k)
// order_of_key(x)
