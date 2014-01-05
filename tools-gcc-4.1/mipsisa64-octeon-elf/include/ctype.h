#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "_ansi.h"

_BEGIN_STD_C

int _EXFUN(isalnum, (int __c));
int _EXFUN(isalpha, (int __c));
int _EXFUN(iscntrl, (int __c));
int _EXFUN(isdigit, (int __c));
int _EXFUN(isgraph, (int __c));
int _EXFUN(islower, (int __c));
int _EXFUN(isprint, (int __c));
int _EXFUN(ispunct, (int __c));
int _EXFUN(isspace, (int __c));
int _EXFUN(isupper, (int __c));
int _EXFUN(isxdigit,(int __c));
int _EXFUN(tolower, (int __c));
int _EXFUN(toupper, (int __c));

#ifndef __STRICT_ANSI__
int _EXFUN(isblank, (int __c));
int _EXFUN(isascii, (int __c));
int _EXFUN(toascii, (int __c));
int _EXFUN(_tolower, (int __c));
int _EXFUN(_toupper, (int __c));
#endif

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200

extern	__IMPORT _CONST char	*__ctype_ptr;
extern	__IMPORT _CONST char	_ctype_[];  /* For backward compatibility.  */

#ifndef __cplusplus
/* Keep the type as int and don't cast to unsigned as apparently on
   LP64 that results in a (unsigned long) (unsigned) series of casts
   before the pointer addition.  The second cast will zero-extend
   which is incorrect for the negative values of C.  */
#define	isalpha(c)	((__ctype_ptr)[(int)(c)]&(_U|_L))
#define	isupper(c)	((__ctype_ptr)[(int)(c)]&_U)
#define	islower(c)	((__ctype_ptr)[(int)(c)]&_L)
#define	isdigit(c)	((__ctype_ptr)[(int)(c)]&_N)
#define	isxdigit(c)	((__ctype_ptr)[(int)(c)]&(_X|_N))
#define	isspace(c)	((__ctype_ptr)[(int)(c)]&_S)
#define ispunct(c)	((__ctype_ptr)[(int)(c)]&_P)
#define isalnum(c)	((__ctype_ptr)[(int)(c)]&(_U|_L|_N))
#define isprint(c)	((__ctype_ptr)[(int)(c)]&(_P|_U|_L|_N|_B))
#define	isgraph(c)	((__ctype_ptr)[(int)(c)]&(_P|_U|_L|_N))
#define iscntrl(c)	((__ctype_ptr)[(int)(c)]&_C)


/* Non-gcc versions will get the library versions, and will be
   slightly slower */
#ifdef __GNUC__
# define toupper(c) \
	__extension__ ({ int __x = (c); islower(__x) ? (__x - 'a' + 'A') : __x;})
# define tolower(c) \
	__extension__ ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x;})
#endif
#endif /* !__cplusplus */

#ifndef __STRICT_ANSI__
#define isascii(c)	((unsigned)(c)<=0177)
#define toascii(c)	((c)&0177)
#endif

_END_STD_C

#endif /* _CTYPE_H_ */
