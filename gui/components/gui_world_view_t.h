/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_COMPONENTS_GUI_WORLD_VIEW_T_H
#define GUI_COMPONENTS_GUI_WORLD_VIEW_T_H


#include "gui_component.h"

#include "../../dataobj/koord3d.h"
#include "../../tpl/vector_tpl.h"

class obj_t;


/**
 * Displays a little piece of the world
 * @author Hj. Malthaner
 */
class world_view_t : public gui_world_component_t
{
private:
	vector_tpl<koord> offsets; /**< Offsets are stored. */
	sint16            raster;  /**< For this rastersize. */

protected:
	virtual koord3d get_location() = 0;

	void internal_draw(scr_coord offset, obj_t const *);

	void calc_offsets(scr_size size, sint16 dy_off);

public:
	world_view_t(scr_size size);

	world_view_t();

	bool infowin_event(event_t const*) OVERRIDE;

	/**
	 * resize window in response to a resize event
	 * need to recalculate the list of offsets
	 * @author prissi
	 */
	void set_size(scr_size size) OVERRIDE;
};

#endif
