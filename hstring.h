#pragma once
#include <stdbool.h>

#define MAX_STRLEN 1024

typedef struct {
    char    str[MAX_STRLEN+1]; //+1 for null
    size_t  len;
} string;

inline void strCpy(string* dest, const char* cstr) {
    size_t len = strlen(cstr);
    if (len > MAX_STRLEN) len = MAX_STRLEN;
    memcpy(dest->str,cstr,len);
    dest->str[len] = '\0';
    dest->len = len;
}

inline void strCat(string* dest, const char* cstr) {
    if (dest->len >= MAX_STRLEN) return;
    size_t clen = strlen(cstr);
    size_t totlen = dest->len + clen; 
    if (totlen > MAX_STRLEN) totlen = MAX_STRLEN;
    memcpy(&dest->str[dest->len],cstr,MAX_STRLEN-dest->len);
    dest->str[totlen] = '\0';
    dest->len = totlen;
}

inline void strEmpty(string* dest) {
    //memset(dest->str, 0, MAX_STRLEN);
    dest->str[0] = '\0';
    dest->len = 0;
}

inline bool strEqual(string* dest, const char* cstr) {
    size_t len = strlen(cstr);
    if (len != dest->len) return false;
    return (memcmp(dest, cstr, len)==0) ? true : false;
}

inline bool strStartsWith(string* dest, const char* cstr) {
   return (memcmp(dest, cstr, strlen(cstr)) == 0) ? true: false;
}

//inspired from Apple Open Source
//https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/memmem.c
inline int strPos(const string* l, const char *s) {
	register char *cur, *last;
	const char *cl = (const char *)l;
	const char *cs = (const char *)s;
	
	size_t s_len = strlen(s);
	
	/* we need something to compare */
	if (l->len == 0 || s_len == 0) return -1;

	/* "s" must be smaller or equal to "l" */
	if (l->len < s_len) return -1;

	/* the last position where its possible to find "s" in "l" */
	last = (char *)cl + l->len - s_len;

	for (cur = (char *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && memcmp(cur, cs, s_len) == 0) return cur - cl;

	return -1;
}

