/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_GROUND_INFO_H
#define GUI_GROUND_INFO_H


#include "base_info.h"
#include "components/gui_location_view_t.h"
#include "../utils/cbuffer_t.h"
#include "components/gui_fixedwidth_textarea.h"

class grund_t;

class grund_info_t : public base_infowin_t
{
protected:
	/**
	 * The ground we observe. The ground will delete this object
	 * if self deleted.
	 * @author Hj. Malthaner
	 */
	const grund_t* gr;

	location_view_t view;

public:
	grund_info_t(const grund_t* gr);

	virtual koord3d get_weltpos(bool);

	virtual bool is_weltpos();

	void draw(scr_coord pos, scr_size size);

	virtual void map_rotate90( sint16 );
};

#endif
