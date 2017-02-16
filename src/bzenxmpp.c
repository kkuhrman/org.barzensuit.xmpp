/**
 * @file:	bzenxmpp.c
 * @brief:	CLI
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

#include <config.h>
#include "bzenxmpp.h"
#include "errno.h"
#include "error.h"
#include "bzenxmpp_help.h"

static const struct option longopts[] = {
  {"help", no_argument, NULL, 'h'},
  {"version", no_argument, NULL, 'v'},
  {NULL, 0, NULL, 0}
};

int main (int argc, char *argv[])
{
  int optc;
  int lose = 0;

  set_program_name(argv[0]);

  /* Set locale via LC_ALL.  */
  setlocale (LC_ALL, "");

  atexit(close_stdout);

  while ((optc = getopt_long(argc, argv, "hv", longopts, NULL)) != -1)
    switch (optc)
      {
	/* --help and --version exit immediately, per GNU coding standards.  */
      case 'v':
	bzen_print_version();
	exit(EXIT_SUCCESS);
	break;
      case 'h':
	bzen_print_help();
	exit(EXIT_SUCCESS);
	break;
      default:
	lose = 1;
	break;
      }

  if (lose || optind < argc)
    {
      /* Print error message and exit.  */
      error(0, 0, "%s: %s", _("extra operand"), argv[optind]);
      bzen_print_help();
    }

#if ENABLE_NLS
  /* Set the text message domain.  */
  bindtextdomain(PACKAGE, LOCALEDIR);
  textdomain(PACKAGE);
#endif

  exit(EXIT_SUCCESS);
}
