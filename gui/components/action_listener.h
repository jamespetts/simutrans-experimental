/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_COMPONENTS_ACTION_LISTENER_H
#define GUI_COMPONENTS_ACTION_LISTENER_H


#include "../../simtypes.h"

class gui_action_creator_t;

/**
 * This interface must be implemented by all classes which want to
 * listen actions, i.e. button presses
 * @author Hj. Malthaner
 */
class action_listener_t
{
public:
	virtual ~action_listener_t() {}

	/**
	 * This method is called if an action is triggered
	 * @author Hj. Malthaner
	 *
	 * Returns true, if action is done and no more
	 * components should be triggered.
	 * V.Meyer
	 */
	virtual bool action_triggered(gui_action_creator_t *comp, value_t extra) = 0;
};

#endif
