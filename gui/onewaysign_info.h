/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_ONEWAYSIGN_INFO_H
#define GUI_ONEWAYSIGN_INFO_H


#include "../simconst.h"
#include "obj_info.h"
#include "components/action_listener.h"
#include "components/gui_button.h"
#include "components/gui_container.h"

class roadsign_t;

/**
 * Info window for factories
 * @author Hj. Malthaner
 */
class onewaysign_info_t : public obj_infowin_t, public action_listener_t
{
	private:
		roadsign_t* sign;
		button_t direction[2];

	public:
		onewaysign_info_t(roadsign_t* s, koord3d first_intersection);

		/**
		 * Set the window associated helptext
		 * @return the filename for the helptext, or NULL
		 * @author Hj. Malthaner
		 */
		const char *get_help_filename() const OVERRIDE {return "onewaysign_info.txt";}

		bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;

		// called, after external change
		void update_data();
};

#endif
