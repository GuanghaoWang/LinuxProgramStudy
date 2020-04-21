#ifndef __ERROR_FUNC_H__
#define __ERROR_FUNC_H__

void errMsg(const char *format, ...);

#ifdef __GNUC__
	/* This macro stop 'gcc -Wall' complaining that "control reaches end of non-void function" if We use the following
	 * functions to terminte main() or some other non-void functions. */
	#define NORETURN __attribute__ ((__noreturn__))
#else
	#define NORETURN
#endif

void errExit(const char *format, ...) NORETURN;
void err_exit(const char *format, ...) NORETURN;
void errExitEN(int errnum, const char *format, ...) NORETURN;
void fatal(const char *format, ...) NORETURN;
void usageErr(const char *format, ...) NORETURN;
void cmdLineErr(const char *format, ...) NORETURN;

#endif
