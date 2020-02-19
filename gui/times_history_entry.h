#ifndef times_history_entry_h
#define times_history_entry_h

#include "components/gui_component.h"
#include "components/gui_label.h"
#include "../tpl/slist_tpl.h"
#include "../dataobj/schedule.h"
#include "../simworld.h"

#define TIME_TEXT_WIDTH 50
#define TIME_TEXT_MARGIN 10
#define TIMES_HISTORY_ENTRY_WIDTH (TIME_TEXT_WIDTH * TIMES_HISTORY_SIZE + TIME_TEXT_MARGIN + TIME_TEXT_WIDTH)

// @author: suitougreentea
class times_history_entry_t : public gui_world_component_t
{
private:
	char times_str[TIMES_HISTORY_SIZE][32];
	char average_time_str[32];
	times_history_data_t *history;

public:
	times_history_entry_t() {}
	times_history_entry_t(times_history_data_t *history_);

	~times_history_entry_t() {}

	void draw(scr_coord offset);
};

#endif
