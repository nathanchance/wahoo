#ifndef __LINUX_COMPILER_H
#error "Please don't include <linux/compiler-clang.h> directly, include <linux/compiler.h> instead."
#endif

/* Some compiler specific definitions are overwritten here
 * for Clang compiler
 */

#ifdef uninitialized_var
#undef uninitialized_var
#define uninitialized_var(x) x = *(&(x))
#endif

/*
* GCC does not warn about unused static inline functions for
* -Wunused-function.  This turns out to avoid the need for complex #ifdef
* directives.  Suppress the warning in clang as well.
*/
#undef inline
#define inline inline __attribute__((unused)) notrace

/*
 * Clang supports FORTIFY_SOURCE; this needs to override compiler-gcc.h turning it off
 */
#ifdef __NO_FORTIFY
#undef __NO_FORTIFY
#endif

#ifdef CONFIG_CC_LTO
#ifdef CONFIG_FTRACE_MCOUNT_RECORD
#define __norecordmcount \
	__attribute__((__section__(".text..ftrace")))
#endif
#endif

#define randomized_struct_fields_start	struct {
#define randomized_struct_fields_end	};
