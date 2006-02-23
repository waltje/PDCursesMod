/************************************************************************ 
 * This file is part of PDCurses. PDCurses is public domain software;	*
 * you may use it for any purpose. This software is provided AS IS with	*
 * NO WARRANTY whatsoever.						*
 *									*
 * If you use PDCurses in an application, an acknowledgement would be	*
 * appreciated, but is not mandatory. If you make corrections or	*
 * enhancements to PDCurses, please forward them to the current		*
 * maintainer for the benefit of other users.				*
 *									*
 * No distribution of modified PDCurses code may be made under the name	*
 * "PDCurses", except by the current maintainer. (Although PDCurses is	*
 * public domain, the name is a trademark.)				*
 *									*
 * See the file maintain.er for details of the current maintainer.	*
 ************************************************************************/

#define	CURSES_LIBRARY 1
#include <term.h>

/* undefine any macros for functions defined in this module */
#undef mvcur
#undef vidattr
#undef vidputs

#ifdef PDCDEBUG
const char *rcsid_terminfo =
	"$Id: terminfo.c,v 1.20 2006/02/23 01:46:52 wmcbrine Exp $";
#endif

/*man-start**************************************************************

  Name:                                                      terminfo

  Synopsis:
	int mvcur(int oldrow, int oldcol, int newrow, int newcol);
	int del_curterm(TERMINAL *);
	int putp(const char *);
	int restartterm(char *, int, int *);
	TERMINAL *set_curterm(TERMINAL *);
	int setupterm(char *, int, int *);
	int tgetent(char *, const char *);
	int tgetflag(char *);
	int tgetnum(char *);
	char *tgetstr(char *, char **);
	char *tgoto(char *, int, int);
	int tigetflag(char *);
	int tigetnum(char *);
	char *tigetstr(char *);
	char *tparm(char *,long, long, long, long, long, long, long, 
		long, long);
	int tputs(const char *, int, int (*)(int));
	int vidattr(chtype attr);
	int vidputs(chtype attr, int (*putfunc)(int));

  X/Open Description:
	The mvcur() function controls low-level cursor motion with 
	optimization.

	NOTE: The remainer of the terminfo functions have not been
	implemented.

  X/Open Return Value:
	All functions return OK on success and ERR on error.

  X/Open Errors:
	No errors are defined for this function.

  Portability				     X/Open    BSD    SYS V
					     Dec '88
	mvcur					Y	Y	Y

**man-end****************************************************************/

TERMINAL *cur_term = NULL;

int mvcur(int oldrow, int oldcol, int newrow, int newcol)
{
	PDC_LOG(("mvcur() - called: oldrow %d oldcol %d newrow %d newcol %d\n",
		oldrow, oldcol, newrow, newcol));

	if ((newrow >= LINES) || (newcol >= COLS) ||
	    (newrow < 0) || (newcol < 0))
		return ERR;

	PDC_gotoxy(newrow, newcol);
	SP->cursrow = newrow;
	SP->curscol = newcol;

	return OK;
}

int del_curterm(TERMINAL *oterm)
{
	PDC_LOG(("del_curterm() - called\n"));

	return ERR;
}

int putp(const char *str)
{
	PDC_LOG(("putp() - called: str %s\n", str));

	return ERR;
}

int restartterm(char *term, int filedes, int *errret)
{
	PDC_LOG(("restartterm() - called\n"));

	if (errret)
		*errret = -1;

	return ERR;
}

TERMINAL *set_curterm(TERMINAL *nterm)
{
	PDC_LOG(("set_curterm() - called\n"));

	return (TERMINAL *)NULL;
}

int setterm(char *term)
{
	PDC_LOG(("setterm() - called\n"));

	return ERR;
}

int setupterm(char *term, int filedes, int *errret)
{
	PDC_LOG(("setupterm() - called\n"));

	if (errret)
		*errret = -1;
	else
		fprintf(stderr, "There is no terminfo database\n");

	return ERR;
}

int tgetent(char *bp, const char *name)
{
	PDC_LOG(("tgetent() - called: name %s\n", name));

	return ERR;
}

int tgetflag(char *id)
{
	PDC_LOG(("tgetflag() - called: id %s\n", id));

	return ERR;
}

int tgetnum(char *id)
{
	PDC_LOG(("tgetnum() - called: id %s\n", id));

	return ERR;
}

char *tgetstr(char *id, char **area)
{
	PDC_LOG(("tgetstr() - called: id %s\n", id));

	return (char *)NULL;
}

char *tgoto(char *cap, int col, int row)
{
	PDC_LOG(("tgoto() - called\n"));

	return (char *)NULL;
}

int tigetflag(char *capname)
{
	PDC_LOG(("tigetflag() - called: capname %s\n", capname));

	return -1;
}

int tigetnum(char *capname)
{
	PDC_LOG(("tigetnum() - called: capname %s\n", capname));

	return -2;
}

char *tigetstr(char *capname)
{
	PDC_LOG(("tigetstr() - called: capname %s\n", capname));

	return (char *)(-1);
}

char *tparm(char *cap, long p1, long p2, long p3, long p4, 
			long p5, long p6, long p7, long p8, long p9)
{
	PDC_LOG(("tparm() - called: cap %s\n", cap));

	return (char *)NULL;
}

int tputs(const char *str, int affcnt, int (*putfunc)(int))
{
	PDC_LOG(("tputs() - called\n"));

	return ERR;
}

int vidattr(chtype attr)
{
	PDC_LOG(("vidattr() - called: attr %d\n", attr));

	return ERR;
}

int vidputs(chtype attr, int (*putfunc)(int))
{
	PDC_LOG(("vidputs() - called: attr %d\n", attr));

	return ERR;
}
