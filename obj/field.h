/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef OBJ_FIELD_H
#define OBJ_FIELD_H


#include "../simobj.h"
#include "../display/simimg.h"


class field_class_desc_t;
class fabrik_t;

class field_t : public obj_t
{
	fabrik_t *fab;
	const field_class_desc_t *desc;

public:
	field_t(const koord3d pos, player_t *player, const field_class_desc_t *desc, fabrik_t *fab);
	virtual ~field_t();

	const char* get_name() const { return "Field"; }
#ifdef INLINE_OBJ_TYPE
#else
	typ get_typ() const { return obj_t::field; }
#endif

	image_id get_image() const;

	/**
	 * @return Einen Beschreibungsstring f�r das Objekt, der z.B. in einem
	 * Beobachtungsfenster angezeigt wird.
	 * @author Hj. Malthaner
	 */
	void show_info();

	/**
	 * @return NULL when OK, otherwise an error message
	 * @author Hj. Malthaner
	 */
	const char *  is_deletable(const player_t *);

	void cleanup(player_t *player);
};

#endif
