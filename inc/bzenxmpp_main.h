/**
 * @file:	bzenxmpp_main.h
 * @brief:	bzenxmpp program global settings.
 * 
 * @copyright:	Copyright (C) 2017 Kuhrman Technology Solutions LLC
 * @license:	GPLv3+: GNU GPL version 3
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BZENXMPP_H_
#define _BZENXMPP_H_

/* Assume ANSI C89 headers are available.  */
# include <locale.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* Use POSIX headers.  If they are not available, we use the substitute
   provided by gnulib.  */
# include <getopt.h>
# include <unistd.h>

/* Unicode. */
#include <wchar.h>
#include <wctype.h>

/* Internationalization.  */
# include "gettext.h"
# define _(str) gettext (str)
# define N_(str) gettext_noop (str)

/* gnulib */
#include "closeout.h"
#include "long-options.h"
#include "progname.h"

#endif /* _BZENXMPP_H_ */
