/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_COMPONENTS_GUI_MAP_PREVIEW_H
#define GUI_COMPONENTS_GUI_MAP_PREVIEW_H


#include "gui_component.h"
#include "../../simcolor.h"
#include "../../display/simgraph.h"
#include "../../tpl/array2d_tpl.h"

#define MAP_PREVIEW_SIZE_X ((scr_coord_val)(64))
#define MAP_PREVIEW_SIZE_Y ((scr_coord_val)(64))

/**
 * A map preview component
 *
 * @author Max Kielland
 * @date 2013-06-02
 *
 */
class gui_map_preview_t : public gui_component_t
{

	private:
		array2d_tpl<uint8> *map_data;
		scr_size map_size;

	public:
		gui_map_preview_t(void);

		void init( scr_coord pos, scr_size size = scr_size(MAP_PREVIEW_SIZE_X,MAP_PREVIEW_SIZE_Y) ) {
			set_pos( pos );
			set_size( size );
		}

		void set_map_data(array2d_tpl<uint8> *map_data_par, scr_size max_size_par) {
			map_data = map_data_par;
			map_size = max_size_par;
		}

		/**
		 * Draws the component.
		 * @author Max Kielland, (Hj. Malthaner)
		 */
		virtual void draw(scr_coord offset) {
			display_ddd_box_clip(pos.x + offset.x, pos.y + offset.y, size.w, size.h, MN_GREY0, MN_GREY4);

			if(map_data) {
				display_array_wh(pos.x + offset.x + 1, pos.y + offset.y + 1, map_size.w, map_size.h, map_data->to_array());
			}
		}

};

#endif
