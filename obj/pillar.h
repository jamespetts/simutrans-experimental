/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef OBJ_PILLAR_H
#define OBJ_PILLAR_H


#include "../simobj.h"

class bridge_desc_t;
class loadsave_t;
class karte_t;


/**
 * Brueckenteile (sichtbar)
 */
class pillar_t : public obj_t
{
	const bridge_desc_t *desc;
	uint8 dir;
	bool asymmetric;
	image_id image;

protected:
	void rdwr(loadsave_t *file);

public:
	pillar_t(loadsave_t *file);
	pillar_t(koord3d pos, player_t *player, const bridge_desc_t *desc, bridge_desc_t::img_t img, int height);

	const char* get_name() const { return "Pillar"; }
#ifdef INLINE_OBJ_TYPE
#else
	typ get_typ() const { return obj_t::pillar; }
#endif

	const bridge_desc_t* get_desc() const { return desc; }

	image_id get_image() const { return asymmetric ? IMG_EMPTY : image; }

	// asymmetric pillars are placed at the southern/eastern boundary of the tile
	// thus the images have to be displayed after vehicles
	image_id get_front_image() const { return asymmetric ? image : IMG_EMPTY;}

	// needs to check for hiding asymmetric pillars
	void calc_image();

	/**
	 * @return Einen Beschreibungsstring fuer das Objekt, der z.B. in einem
	 * Beobachtungsfenster angezeigt wird.
	 */
	void show_info();

	void rotate90();
};

#endif
