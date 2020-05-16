/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_TRAFFICLIGHT_INFO_H
#define GUI_TRAFFICLIGHT_INFO_H


#include "obj_info.h"
#include "components/action_listener.h"
#include "components/gui_numberinput.h"
#include "components/gui_button.h"
#include "components/gui_label.h"
#include "components/gui_container.h"

class roadsign_t;

/*
 * Traffic light phase buttons
 */
class trafficlight_info_t : public obj_infowin_t, public action_listener_t
{
 private:
	roadsign_t* ampel;
	gui_numberinput_t ns, ow, offset;
  button_t direction_buttons[8];
  gui_label_t direction_labels[4];

 public:
	trafficlight_info_t(roadsign_t* s);

	/*
	 * Set the window associated helptext
	 * @return the filename for the helptext, or NULL
	 */
	const char *get_help_filename() const {return "trafficlight_info.txt";}

	bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;

	// called, after external change
	void update_data();
};

#endif
