/*
 * Copyright (c) 1997 - 2003 Hansj�rg Malthaner
 * Copyright 2013 Nathanael Nerode, James Petts
 *
 * This file is part of the Simutrans project under the artistic licence.
 * (see licence.txt)
 */

/*
 * Goods list dialog
 */

#ifndef goods_frame_t_h
#define goods_frame_t_h

#include "gui_frame.h"
#include "components/gui_button.h"
#include "components/gui_scrollpane.h"
#include "components/gui_label.h"
#include "components/gui_numberinput.h"
#include "components/action_listener.h"
#include "components/gui_combobox.h"
#include "goods_stats_t.h"
#include "../utils/cbuffer_t.h"

// for waytype_t
#include "../simtypes.h"


/**
 * Shows statistics. Only goods so far.
 * @author Hj. Malthaner
 */
class goods_frame_t : public gui_frame_t, private action_listener_t
{
private:
	enum sort_mode_t { unsortiert=0, nach_name=1, nach_gewinn=2, nach_catg=3, by_weight=4, SORT_MODES=5 };
	static const char *sort_text[SORT_MODES];

	// static, so we remember the last settings
	// Distance in meters
	static uint32 distance_meters;
	// Distance in km
	static uint16 distance;
	
	static uint32 vehicle_speed;
	static uint8 comfort;
	static uint8 catering_level;
	static uint8 g_class;
	static bool sortreverse;
	static sort_mode_t sortby;
	static bool filter_goods;

	char		speed[6];
	char		distance_txt[6];
	char		comfort_txt[6];
	char		catering_txt[6];
	char		class_txt[6];
	cbuffer_t	descriptive_text;
	uint16		good_list[256];

	gui_label_t		sort_label;
	button_t		sortedby;
	button_t		sorteddir;
	gui_label_t		change_speed_label;
	gui_label_t		change_distance_label;
	gui_label_t		change_comfort_label;
	gui_label_t		change_catering_label;
	gui_label_t		change_class_label;

	/*
	button_t		speed_up;
	button_t		speed_down;
	button_t		distance_up;
	button_t		distance_down;
	button_t		comfort_up;
	button_t		comfort_down;
	button_t		catering_up;
	button_t		catering_down;
	*/
	
	// replace button list with numberinput components for faster navigation
	// @author: HeinBloed, April 2012
	gui_numberinput_t distance_input, comfort_input, catering_input, speed_input, class_input;

	button_t		filter_goods_toggle;

	goods_stats_t goods_stats;
	gui_scrollpane_t scrolly;

	// creates the list and pass it to the child function good_stats, which does the display stuff ...
	static bool compare_goods(uint16, uint16);
	void sort_list();

public:
	goods_frame_t();

	/**
	* resize window in response to a resize event
	* @author Hj. Malthaner
	* @date   16-Oct-2003
	*/
	void resize(const scr_coord delta);

	bool has_min_sizer() const {return true;}

	/**
	 * Set the window associated helptext
	 * @return the filename for the helptext, or NULL
	 * @author V. Meyer
	 */
	const char * get_help_filename() const {return "goods_filter.txt"; }

	/**
	 * Draw new component. The values to be passed refer to the window
	 * i.e. It's the screen coordinates of the window where the
	 * component is displayed.
	 * @author Hj. Malthaner
	 */
	void draw(scr_coord pos, scr_size size);

	bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;
};

#endif
