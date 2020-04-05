/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

/*
 * a template class which implements a hashtable with quickstone keys
 * adapted from the pointer hashtable by jamespetts
 */

#ifndef TPL_QUICKSTONE_HASHTABLE_TPL_H
#define TPL_QUICKSTONE_HASHTABLE_TPL_H


#include "inthashtable_tpl.h"
#include "hashtable_tpl.h"
#include "quickstone_tpl.h"
#include <stdlib.h>

/*
 * Define the key characteristics for hashing IDs.
 */
template<class key_t>
class quickstone_hash_tpl {
public:
	typedef long diff_type;

	static uint16 hash(const quickstone_tpl<key_t> key)
	{
		return key.get_id();
	}

	static key_t null()
	{
		return NULL;
	}

	static void dump(const quickstone_tpl<key_t> key)
	{
		printf("%p", (void *)key.get_id());
	}

	static diff_type comp(quickstone_tpl<key_t> key1, quickstone_tpl<key_t> key2)
	{
		return (key1.get_id() - key2.get_id());
	}
};


/*
 * Ready to use class for hashing quickstones.
 */
template<class key_t, class value_t>
class quickstone_hashtable_tpl : public hashtable_tpl<quickstone_tpl<key_t>, value_t, quickstone_hash_tpl<key_t> >
{
};

#endif
