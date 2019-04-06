default: vi

vi: ex
	ln -sf ex $@

ex: ex.o ex_command.o \
	ex_abbreviate.o\
	ex_append.o\
	ex_args.o\
	ex_change.o\
	ex_chdir.o\
	ex_copy.o\
	ex_delete.o\
	ex_edit.o\
	ex_file.o\
	ex_global.o\
	ex_insert.o\
	ex_join.o\
	ex_list.o\
	ex_map.o\
	ex_mark.o\
	ex_move.o\
	ex_next.o\
	ex_number.o\
	ex_open.o\
	ex_preserve.o\
	ex_print.o\
	ex_put.o\
	ex_quit.o\
	ex_read.o\
	ex_recover.o\
	ex_rewind.o\
	ex_set.o\
	ex_shell.o\
	ex_source.o\
	ex_substitute.o\
	ex_ampersand.o\
	ex_tilde.o\
	ex_suspend.o\
	ex_tag.o\
	ex_unabbrev.o\
	ex_undo.o\
	ex_unmap.o\
	ex_version.o\
	ex_visual.o\
	ex_write.o\
	ex_wq.o\
	ex_xit.o\
