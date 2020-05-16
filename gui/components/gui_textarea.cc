/*
 * This file is part of the Simutrans-Extended project under the Artistic License.
 * (see LICENSE.txt)
 */

#include <string.h>

#include "gui_textarea.h"
#include "../../display/simgraph.h"
#include "../../simdebug.h"
#include "../../simcolor.h"
#include "../../simskin.h"
#include "../gui_theme.h"
#include "../../utils/cbuffer_t.h"

#define L_PADDING_RIGHT (10)

gui_textarea_t::gui_textarea_t(const char* text)
{
	buf = new cbuffer_t();
	my_own_buf = true;
	buf->append(text);
	recalc_size();
}

gui_textarea_t::gui_textarea_t(cbuffer_t* buf_)
{
	buf = buf_;
	my_own_buf = false;
	recalc_size();
}

gui_textarea_t::~gui_textarea_t()
{
	if (my_own_buf) {
		delete buf;
	}
}

void gui_textarea_t::set_text(const char *const text)
{
	buf->clear();
	if(text)
	{
		buf->append(text);
	}
}

// recalcs the current size;
// usually not needed to be called explicitly
void gui_textarea_t::recalc_size()
{
	const char *text(*buf);

	// we cannot use: display_multiline_text(pos.x+offset.x, pos.y+offset.y+10, text, COL_BLACK);
	// since we also want to dynamically change the size of the component
	int new_lines=0;
	int x_size = 1;

	if (  (text != NULL)  &&  (*text != '\0')  ) {
		const char *buf=text;
		const char *next;

		do {
			next = strchr(buf, '\n');
			const size_t len = next != NULL ? next - buf : -1;
			int px_len = display_calc_proportional_string_len_width(buf, len);
			if(px_len>x_size) {
				x_size = px_len;
			}
			buf = next + 1;
			new_lines += LINESPACE;
		} while(  next != NULL  &&  *buf!=0  );
	}
DBG_MESSAGE("gui_textarea_t::recalc_size()","reset size to %i,%i",x_size+L_PADDING_RIGHT,new_lines);
	set_size( scr_size( x_size + L_PADDING_RIGHT, new_lines + 10) );
}


/**
 * Draw the component
 */
void gui_textarea_t::draw(scr_coord offset)
{
	const char *text(*buf);

	// we cannot use: display_multiline_text(pos.x+offset.x, pos.y+offset.y+10, text, COL_BLACK);
	// since we also want to dynamically change the size of the component
	int new_lines=0;

	// keep previous maximum width
	int x_size = get_size().w - L_PADDING_RIGHT;
	if (  (text != NULL)  &&  (*text != '\0')  ) {
		const char *buf=text;
		const char *next;
		const sint16 x = pos.x+offset.x;
		sint16 y = pos.y+offset.y;

		do {
			next = strchr(buf, '\n');
			if(  pos.y + new_lines + (LINESPACE >= 0)  ) {
				const int len = next != NULL ? (long)(size_t)(next - buf) : -1;
				int px_len = display_text_proportional_len_clip(x, y + new_lines, buf, ALIGN_LEFT | DT_CLIP, SYSCOL_TEXT, true, len);
				if(px_len>x_size) {
					x_size = px_len;
				}
			}
			buf = next + 1;
			new_lines += LINESPACE;
		} while(  next != NULL  &&  *buf!=0  );
	}
	scr_size size( max( x_size + L_PADDING_RIGHT, get_size().w ), new_lines );
	if(  size!=get_size()  ) {
		set_size(size);
	}
}
