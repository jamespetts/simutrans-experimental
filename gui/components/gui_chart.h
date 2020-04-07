/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#ifndef GUI_COMPONENTS_GUI_CHART_H
#define GUI_COMPONENTS_GUI_CHART_H


#include "../../simtypes.h"
#include "gui_component.h"
#include "../../tpl/slist_tpl.h"

// CURVE TYPES
#define STANDARD 0
#define MONEY 1

/**
 * Draws a group of curves.
 */
class gui_chart_t : public gui_component_t
{
public:
	/**
	 * Set background color. -1 means no background
	 */
	void set_background(int color);

	gui_chart_t();

	/*
	 * paint chart
	 */
	void draw(scr_coord offset);

	bool infowin_event(event_t const*) OVERRIDE;

	/*
	 * set dimension
	 */
	void set_dimension(int x, int y) {
		x_elements = x;
		y_elements = y;
	}

	/**
	 * Pointer to function which converts supplied values before use
	 */
	typedef sint64 (*convert_proc) (const sint64);

	/**
	 * Adds a curve to the graph
	 * @param color    color for this curve; default 0
	 * @param values   reference to values
	 * @param size     elements to skip before next valid entry (only useful in multidimensional arrays)
	 * @param offset   element to start with
	 * @param elements elements in values
	 * @param proc     conversion procedure to be applied to supplied values
	 * @returns curve's id
	 */
	int add_curve(int color, const sint64 *values, int size, int offset, int elements, int type, bool show, bool show_value, int precision, convert_proc proc=NULL);

	uint32 add_line(int color, const sint64 *value, int times, bool show, bool show_value, int precision, convert_proc proc=NULL);

	void remove_curves() { curves.clear(); }

	void remove_lines() { lines.clear(); }

	/**
	 * Hide a curve of the set
	 */
	void hide_curve(unsigned int id);

	/**
	 * Show a curve of the set
	 */
	void show_curve(unsigned int id);

	/**
	 * Show/hide a line of the set
	 */
	void show_line(uint32 id);
	void hide_line(uint32 id);

	/*
	 * set starting value for x-axis of chart
	 * example: set_seed(1930) will make a graph starting in year 1930; use set_seed(-1) to display nothing
	 */
	void set_seed(int seed) { this->seed = seed; }

	void set_show_x_axis(bool yesno) { show_x_axis = yesno; }

	void set_show_y_axis(bool yesno) { show_y_axis = yesno; }

	void set_ltr(bool yesno) { ltr = yesno; }

	int get_curve_count() { return curves.get_count(); }

private:

	void calc_gui_chart_values(sint64 *baseline, float *scale, char *, char *) const;

	/*
	 * curve struct
	 */
	struct curve_t {
		int color;
		const sint64 *values;
		int size;
		int offset;
		int elements;
		bool show;
		bool show_value; // show first value of curve as number on chart?
		int type; // 0 = standard, 1 = money
		int precision;	// how many numbers ...
		convert_proc convert;	//  procedure for converting supplied values before use
	};

	/**
	 * line struct
	 */
	struct line_t {
		int color;
		const sint64 *value;		// pointer to a single value only
		int times;					// number of times the same value is repeated
		bool show;
		bool show_value;			// whether to show the value as number on the chart
		int precision;
		convert_proc convert;	//  procedure for converting supplied value before use
	};

	slist_tpl <curve_t> curves;
	slist_tpl <line_t> lines;

	int x_elements, y_elements;

	int seed;

	scr_coord tooltipcoord;

	bool show_x_axis, show_y_axis, ltr;

	/**
	 * Background color, -1 for transparent background
	 */
	int background;
};

#endif
