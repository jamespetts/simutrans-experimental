/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_COMPONENTS_GUI_LABEL_H
#define GUI_COMPONENTS_GUI_LABEL_H


#include "gui_component.h"
#include "../../simcolor.h"
#include "../gui_theme.h"
#include "../../simskin.h"


/**
 * The label component
 * just displays a text, will be auto-translated
 *
 * @author Hj. Malthaner
 * @date 04-Mar-01
 *
 * Added Alignment support
 * @author: Volker Meyer
 * @date 25.05.03
 */
class gui_label_t : public gui_component_t
{
public:
	enum align_t {
		left,
		centered,
		right,
		money
	};

private:
	align_t align;

	/**
	 * Color of the Labels
	 * @author Hansjorg Malthaner
	 */
	COLOR_VAL color;

	const char * text;	// only for direct access of non-translatable things. Do not use!
	const char * tooltip;

protected:
	using gui_component_t::init;

public:
	gui_label_t(const char* text=NULL, COLOR_VAL color=SYSCOL_TEXT, align_t align=left);

	void init( const char* text_par, scr_coord pos_par, COLOR_VAL color_par=SYSCOL_TEXT, align_t align_par=left) {
		set_pos  ( pos_par   );
		set_text ( text_par  );
		set_color( color_par );
		set_align( align_par );
	}

	/**
	 * Sets the text to display, after translating it.
	 * @author Hansjorg Malthaner
	 */
	void set_text(const char *text, bool autosize=true);

	/**
	 * Sets the text without translation.
	 * @author Hansjorg Malthaner
	 */
	void set_text_pointer(const char *text, bool autosize=true);

	/**
	 * returns the pointer (i.e. for freeing untranslated contents)
	 * @author Hansjorg Malthaner
	 */
	const char * get_text_pointer() const { return text; }

	/**
	 * returns the tooltip pointer (i.e. for freeing untranslated contents)
	 */
	const char * get_tooltip_pointer() { return tooltip; }

	/**
	 * Draws the component.
	 * @author Hj. Malthaner
	 */
	void draw(scr_coord offset);

	/**
	 * Sets the colour of the label
	 * @author Owen Rudge
	 */
	void set_color(COLOR_VAL colour) { this->color = colour; }
	COLOR_VAL get_color() const { return color; }

	/**
	 * Sets the alignment of the label
	 * @author Volker Meyer
	 */
	void set_align(align_t align) { this->align = align; }

	/**
	 * Sets the tooltip of this component.
	 * @author Hj. Malthaner
	 */
	void set_tooltip(const char * t);

	align_t get_align() const { return align; }
};

#endif
