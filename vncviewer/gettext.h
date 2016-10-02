/* Convenience header for conditional use of GNU <libintl.h>.
   Copyright (C) 1995-1998, 2000-2002, 2004-2006, 2009-2011 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef _LIBGETTEXT_H
#define _LIBGETTEXT_H 1

/* Disabled NLS.
   The casts to 'const char *' serve the purpose of producing warnings
   for invalid uses of the value returned from these functions.
   On pre-ANSI systems without 'const', the config.h file is supposed to
   contain "#define const".  */
# undef gettext
# define gettext(Msgid) ((const char *) (Msgid))
# undef dgettext
# define dgettext(Domainname, Msgid) ((void) (Domainname), gettext (Msgid))
# undef dcgettext
# define dcgettext(Domainname, Msgid, Category) \
    ((void) (Category), dgettext (Domainname, Msgid))
# undef ngettext
# define ngettext(Msgid1, Msgid2, N) \
    ((N) == 1 \
     ? ((void) (Msgid2), (const char *) (Msgid1)) \
     : ((void) (Msgid1), (const char *) (Msgid2)))
# undef dngettext
# define dngettext(Domainname, Msgid1, Msgid2, N) \
    ((void) (Domainname), ngettext (Msgid1, Msgid2, N))
# undef dcngettext
# define dcngettext(Domainname, Msgid1, Msgid2, N, Category) \
    ((void) (Category), dngettext (Domainname, Msgid1, Msgid2, N))
# undef textdomain
# define textdomain(Domainname) ((const char *) (Domainname))
# undef bindtextdomain
# define bindtextdomain(Domainname, Dirname) \
    ((void) (Domainname), (const char *) (Dirname))
# undef bind_textdomain_codeset
# define bind_textdomain_codeset(Domainname, Codeset) \
    ((void) (Domainname), (const char *) (Codeset))

# undef pgettext
# define pgettext(Context, String) \
    ((void) (Context), (const char *) (String))

#endif /* _LIBGETTEXT_H */
