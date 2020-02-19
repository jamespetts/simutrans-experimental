/*
 * Copyright (c) 1997 - 2003 Hansj�rg Malthaner
 *
 * This file is part of the Simutrans project under the artistic licence.
 * (see licence.txt)
 */

/*
 * signal infowindow buttons //Ves
 */

#ifndef signal_info_t_h
#define signal_info_t_h

#include "obj_info.h"
#include "../obj/signal.h"
#include "components/action_listener.h"
#include "components/gui_numberinput.h"
#include "components/gui_container.h"
#include "../player/simplay.h"

/**
 * Info window for signals
 * @author Hj. Malthaner
 */
class signal_info_t : public obj_infowin_t, public action_listener_t
{
 private:
	signal_t* sig;
	button_t bt_goto_signalbox;
	button_t bt_info_signalbox;

 public:
	signal_info_t(signal_t* const s);
	
	/*
	 * Set the window associated helptext
	 * @return the filename for the helptext, or NULL
	 * @author Hj. Malthaner
	 */
	const char *get_help_filename() const { return "signals_overview.txt"; }

	bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;

	// called, after external change
	//void update_data();
};

#endif
