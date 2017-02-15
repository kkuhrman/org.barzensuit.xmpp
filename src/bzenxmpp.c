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

static const struct option longopts[] = {
  {"greeting", required_argument, NULL, 'g'},
  {"help", no_argument, NULL, 'h'},
  {"traditional", no_argument, NULL, 't'},
  {"version", no_argument, NULL, 'v'},
  {NULL, 0, NULL, 0}
};

/* Forward declarations.  */
static void print_help (void);
static void print_version (void);

int main (int argc, char *argv[])
{
  int optc;
  int lose = 0;

  set_program_name (argv[0]);

  /* Set locale via LC_ALL.  */
  setlocale (LC_ALL, "");

  atexit (close_stdout);

  while ((optc = getopt_long (argc, argv, "hv", longopts, NULL)) != -1)
    switch (optc)
      {
	/* --help and --version exit immediately, per GNU coding standards.  */
      case 'v':
	print_version ();
	exit (EXIT_SUCCESS);
	break;
      case 'h':
	print_help ();
	exit (EXIT_SUCCESS);
	break;
      default:
	lose = 1;
	break;
      }

  if (lose || optind < argc)
    {
      /* Print error message and exit.  */
      error (0, 0, "%s: %s", _("extra operand"), argv[optind]);
      print_help ();
    }

#if ENABLE_NLS
  /* Set the text message domain.  */
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);
#endif

  exit (EXIT_SUCCESS);
}

/* Print help info.  This long message is split into
   several pieces to help translators be able to align different
   blocks and identify the various pieces.  */

static void print_help (void)
{
  /* TRANSLATORS: --help output 1 (synopsis)
     no-wrap */
  printf (_("\
Usage: %s [OPTION] [COMMAND]\n"), program_name);

  /* TRANSLATORS: --help output 2 (brief description)
     no-wrap */
  fputs (_("\
Provides some very basic environment configuration checks for the \
Barzensuit Project (https://www.barzensuit.org).\n"), stdout);

  /* repeat this two fn() sequence for more text to follow */
  puts ("");
  /* TRANSLATORS: --help output 3: options 1/2
     no-wrap */
  fputs (_("\
  -h, --help          display this help and exit\n\
  -v, --version       display version information and exit\n"), stdout);

  printf ("\n");
  /* TRANSLATORS: --help output 4+ (reports)
     TRANSLATORS: the placeholder indicates the bug-reporting address
     for this application.  Please add _another line_ with the
     address for translation bugs.
     no-wrap */
  printf (_("\
Report bugs to: %s\n"), PACKAGE_BUGREPORT);
#ifdef PACKAGE_PACKAGER_BUG_REPORTS
  printf (_("Report %s bugs to: %s\n"), PACKAGE_PACKAGER,
	  PACKAGE_PACKAGER_BUG_REPORTS);
#endif
#ifdef PACKAGE_URL
  printf (_("%s home page: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
#else
  printf (_("%s home page: <http://www.gnu.org/software/%s/>\n"),
	  PACKAGE_NAME, PACKAGE);
#endif
  fputs (_("General help using GNU software: <http://www.gnu.org/gethelp/>\n"),
	 stdout);
}



/* Print version and copyright information.  */

static void print_version (void)
{
  printf ("%s (%s) %s\n", PACKAGE, PACKAGE_NAME, VERSION);
  /* xgettext: no-wrap */
  puts ("");

  /* It is important to separate the year from the rest of the message,
     as done here, to avoid having to retranslate the message when a new
     year comes around.  */
  printf (_("\
Copyright (C) %d %s.\n\
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n"), 
	  BZENXMPP_COPYRIGHT_YEAR, BZENXMPP_COPYRIGHT_HOLDER);
}
