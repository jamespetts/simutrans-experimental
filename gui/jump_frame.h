/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_JUMP_FRAME_H
#define GUI_JUMP_FRAME_H


#include "components/action_listener.h"
#include "gui_frame.h"
#include "components/gui_textinput.h"
#include "components/gui_divider.h"
#include "components/gui_button.h"



class jump_frame_t : public gui_frame_t, action_listener_t
{
	char buf[64];
	gui_textinput_t input;
	gui_divider_t divider1;
	button_t jumpbutton;

public:
	jump_frame_t();

	/**
	* Set the window associated helptext
	* @return the filename for the helptext, or NULL
	* @author Hj. Malthaner
	*/
	const char * get_help_filename() const { return "jump_frame.txt"; }

	bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;
};

#endif
