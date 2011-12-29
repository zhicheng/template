/*
 *   Copyright Zhicheng Wei <zhicheng1988@gmail.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <locale.h>
#include <config.h>

#include "gettext.h"
#define _(string) gettext (string)

const char *program_name;

static const struct option longopts[] =
{
	{"greeting", required_argument, NULL, 'g'},
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'v'},
	{NULL, 0, NULL, 0}
};

/* Forward declarations.  */
static void print_help(void);
static void print_version(void);

int
main(int argc, char *argv[])
{
	int optc;
	const char *greeting_msg = NULL;

	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	program_name = argv[0];
	while ((optc = getopt_long (argc, argv, "g:hv", longopts, NULL)) != -1)
		switch (optc) {
		case 'v':
			print_version();
			exit(EXIT_SUCCESS);
			break;
		case 'g':
			greeting_msg = optarg;
			break;
		case 'h':
			print_help();
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	printf(_("Hello, world!\n"));

	exit(EXIT_SUCCESS);
}

static void
print_help(void)
{
	printf(_("\
	    Usage: %s [OPTION]...\n"), program_name);

	fputs(_("\
	    Print a friendly, customizable greeting.\n"), stdout);

	puts("");
	fputs(_("\
	    -h, --help          display this help and exit\n\
	    -v, --version       display version information and exit\n"), stdout);

	puts("");
	fputs(_("\
	    -t, --traditional       use traditional greeting format\n\
	    -n, --next-generation   use next-generation greeting format\n\
	    -g, --greeting=TEXT     use TEXT as the greeting message\n"), stdout);

	printf("\n");
	printf(_(" Report bugs to: %s\n"), PACKAGE_BUGREPORT);
#ifdef PACKAGE_PACKAGER_BUG_REPORTS
	printf(_("Report %s bugs to: %s\n"), PACKAGE_PACKAGER,
	    PACKAGE_PACKAGER_BUG_REPORTS);
#endif
#ifdef PACKAGE_URL
	printf(_("%s home page: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
#else
	printf(_("%s home page: <http://www.%s.org/>\n"),
	    PACKAGE_NAME, PACKAGE);
#endif
	fputs(_("General help using GNU software: <http://www.gnu.org/gethelp/>\n"),
	    stdout);
}

static void
print_version(void)
{
	printf("%s %s\n", PACKAGE, VERSION);
	puts("");
	printf(_(
	    "\n"
	    "  Copyright Zhicheng Wei <zhicheng1988@gmail.com>\n"
	    "\n"
	    " Licensed under the Apache License, Version 2.0 (the \"License\");\n"
	    " you may not use this file except in compliance with the License.\n"
	    " You may obtain a copy of the License at\n"
	    "\n"
	    "     http://www.apache.org/licenses/LICENSE-2.0\n"
	    "\n"
	    " Unless required by applicable law or agreed to in writing, software\n"
	    " distributed under the License is distributed on an \"AS IS\" BASIS,\n"
	    " WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
	    " See the License for the specific language governing permissions and\n"
	    " limitations under the License.\n"
	    ));
}

