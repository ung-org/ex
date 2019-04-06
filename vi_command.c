#include "vi.h"

#define CTRL(x) (x - 'a' + 1)
#define ESCAPE '\033'

int vi_command(char buffer, int count, int key)
{
	switch (key) {
	case CTRL('b'):
		return vi_page_backwards(count);

	case CTRL('d'):
		return vi_scroll_forward(count);

	case CTRL('e'):
		return vi_scroll_forward_by_line(count);

	case CTRL('f'):
		return vi_page_forward(count);

	case CTRL('g'):
		return vi_display_information();

	case CTRL('h'):
	case 'h':
	/* case <erase>: */
		return vi_move_cursor_backwards(count);

	case '\n':
	#if CTRL('j') != '\n'
	case CTRL('j'):
	#endif
	#if CTRL('m') != '\r'
	case CTRL('m'):
	#endif
	case CTRL('n'):
	case 'j':
	case '\r':
	case '+':
		return vi_move_down(count);

	case CTRL('l'):
		return vi_clear_and_redisplay();

	case CTRL('p'):
	case 'k':
	case '-':
		return vi_move_up(count);

	case CTRL('r'):
		return vi_redraw_screen();

	case CTRL('u'):
		return vi_scroll_backward(count);

	case CTRL('y'):
		return vi_scroll_backward_by_line(count);

	case CTRL('^'):
		return vi_edit_alternate_file();

	case ESCAPE:
		return vi_terminate_command_or_input_mode();

	case CTRL(']'):
		return vi_search_for_tagstring();

	case ' ':
	case 'l':
		return vi_move_cursor_forward(count);

	case '!':
		return vi_replace_text_with_results_from_shell_command(count);

	case '$':
		return vi_move_cursor_to_end_of_line(count);

	case '%':
		return vi_move_to_matching_character();

	case '&':
		return vi_repeat_substitution();

	case '\'':
		return vi_return_to_previous_context_at_beggining_of_line();

	case '`':
		return vi_return_to_previous_context();

	/*
	case '[[':
		return vi_return_to_previous_section(count);

	case ']]':
		return vi_move_to_next_section(count);
	*/

	case '^':
		return vi_move_to_first_non_blank_position_on_current_line();

	case '_':
		return vi_current_and_line_above(count);

	case '(':
		return vi_move_back_to_beginning_of_sentence(count);

	case ')':
		return vi_move_forward_to_begginning_of_sentence(count);

	case '{':
		return vi_move_back_to_preceding_paragraph(count);

	case '}':
		return vi_move_forward_to_next_paragraph(count);

	case '|':
		return vi_move_to_specific_column_position(count);

	case ',':
		return vi_reverse_find_character(count);

	case '.':
		return vi_repeat(count);

	case '/':
		return vi_find_regular_expression();

	case '0':
		return vi_move_to_first_character_in_line();

	case ':':
		return vi_execute_ex_command();

	case ';':
		return vi_repeat_find(count);

	case '<':
		motion = vi_getmotion();
		return vi_shift_left(count);

	case '>':
		motion = vi_getmotion();
		return vi_shift_right(count);

	case '?':
		return vi_scan_backwards_for_regular_expression();

	case '@':
		return vi_execute(); /* buffer */

	case '~':
		return vi_reverse_case(count);

	case 'a':
		return vi_append(count);

	case 'A':
		return vi_append_at_end_of_line(count);

	case 'b':
		return vi_move_backward_to_preceding_word(count);

	case 'B':
		return vi_move_backward_to_preceding_bigword(count);

	case 'c':
		motion = vi_getmotion();
		return vi_change(buffer, count, motion);

	case 'C':
		return vi_change_to_end_of_line(buffer, count);

	case 'd':
		motion = vi_getmotion();
		return vi_delete(buffer, count, motion);

	case 'D':
		return vi_delete_to_end_of_line(buffer);

	case 'e':
		return vi_move_to_end_of_word(count);

	case 'E':
		return vi_move_to_end_of_bigword(count);

	case 'f':
		return vi_find_character_in_current_line_forward(count);

	case 'F':
		return vi_find_character_in_current_line_reverse(count);

	case 'G':
		return vi_move_to_line(count);

	case 'H':
		return vi_move_to_top_of_screen(count);

	case 'i':
		return vi_insert_before_cursor(count);

	case 'I':
		return vi_insert_at_beginning_of_line(count);

	case 'J':
		return vi_join(count);

	case 'L':
		return vi_move_to_bottom_of_screen(count);

	case 'm':
		return vi_mark();

	case 'M':
		return vi_move_to_middle_of_screen();

	case 'n':
		return vi_repeat_regular_expression_find_forward();

	case 'N':
		return vi_repeat_regular_expression_find_reverse();

	case 'o':
		return vi_insert_empty_line_below();

	case 'O':
		return vi_insert_empty_line_above();

	case 'p':
		return vi_put_from_buffer_following(buffer);

	case 'P':
		return vi_put_from_buffer_before(buffer);

	case 'Q':
		return vi_enter_ex_mode();

	case 'r':
		return vi_replace_character(count);

	case 'R':
		return vi_replace_characters();

	case 's':
		return vi_substitute_character(buffer, count);

	case 'S':
		return vi_substitute_lines(buffer, count);

	case 't':
		return vi_move_cursor_to_before_character_forward(count);

	case 'T':
		return vi_move_cursor_to_after_character_reverse(count);

	case 'u':
		return vi_undo();

	case 'U':
		return vi_undo_current_line();

	case 'w':
		return vi_move_to_beginning_of_word(count);

	case 'W':
		return vi_move_to_beginning_of_bigword(count);

	case 'x':
		return vi_delete_character_at_cursor(buffer, count);

	case 'X':
		return vi_delete_character_before_cursor(buffer, count);

	case 'y':
		motion = vi_getmotion();
		return vi_yank(buffer, count, motion);

	case 'Y':
		return vi_yank_current_line(buffer, count);

	case 'z':
		return vi_redraw_window(count);

	/*
	case 'ZZ':
		return vi_exit();
	*/
	}

	return 0;
}
