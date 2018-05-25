#pragma once
#include <stdbool.h>
#include <wchar.h>

#define MAX_STRLEN 1024

typedef struct {
    char    str[MAX_STRLEN+1]; //+1 for null
    size_t  len;
} String;

//copy *char to string
inline void scpy(String* dest, const char* src) {
    size_t len = strlen(src);
    if (len > MAX_STRLEN) len = MAX_STRLEN;
    memcpy(dest->str,src,len);
    dest->str[len] = '\0';
    dest->len = len;
}

//copy string to string
inline void sCpy(String* dest, const String* src) {
    memcpy(dest->str,src->str,src->len);
    dest->str[src->len] = '\0';
    dest->len = src->len;
}

//concat *char to string
inline void scat(String* dest, const char* src) {
    if (dest->len >= MAX_STRLEN) return;
    size_t len2cpy = strlen(src);
    size_t totlen = dest->len + len2cpy; 
    if (totlen > MAX_STRLEN) {
        len2cpy = MAX_STRLEN - dest->len;
        totlen = MAX_STRLEN;
    }
    memcpy(&dest->str[dest->len],src, len2cpy);
    dest->str[totlen] = '\0';
    dest->len = totlen;
}

//concat string to string
inline void sCat(String* dest, const String* src) {
    if (dest->len >= MAX_STRLEN) return;
    size_t len2cpy =src->len;
    size_t totlen = dest->len + len2cpy; 
    if (totlen > MAX_STRLEN) {
        len2cpy = MAX_STRLEN - dest->len;
        totlen = MAX_STRLEN;
    }
    memcpy(&dest->str[dest->len],src->str, len2cpy);
    dest->str[totlen] = '\0';
    dest->len = totlen;
}

inline void sEmp(String* dest) {
    //memset(dest->str, 0, MAX_STRLEN);
    dest->str[0] = '\0';
    dest->len = 0;
}

inline bool sIsEmp(String* dest) {
    if (dest->len == 0) return true;
    //we don't need this
    //if (dest->str[0] == '\0') return true;
    return false;
}

//is equal? string and char*
inline bool sequ(String* dest, const char* src) {
    size_t len = strlen(src);
    if (len != dest->len) return false;
    return (memcmp(dest->str, src, len)==0) ? true : false;
}

//is equal? string and string
inline bool sEqu(String* dest, const String* src) {
    if (src->len != dest->len) return false;
    return (memcmp(dest->str, src->str, src->len)==0) ? true : false;
}

//startswith? string and char*
inline bool stw(String* dest, const char* src) {
   return (memcmp(dest->str, src, strlen(src)) == 0) ? true: false;
}

//startswith? string and string
inline bool sTW(String* dest, const String* src) {
   return (memcmp(dest->str, src->str, src->len) == 0) ? true: false;
}

//inspired from Apple Open Source
//https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/memmem.c
inline int spos(const String* l, const char* s) {
	register char *cur, *last;
	const char *cl = (const char *)l->str;
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

inline int sPos(const String* l, const String* s) {
	register char *cur, *last;
	const char *cl = (const char *)l->str;
	const char *cs = (const char *)s->str;
	
	/* we need something to compare */
	if (l->len == 0 || s->len == 0) return -1;

	/* "s" must be smaller or equal to "l" */
	if (l->len < s->len) return -1;

	/* the last position where its possible to find "s" in "l" */
	last = (char *)cl + l->len - s->len;

	for (cur = (char *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && memcmp(cur, cs, s->len) == 0) return cur - cl;

	return -1;
}

//##############################################################################
//##############################################################################
//##############################################################################

typedef struct {
    wchar_t   str[MAX_STRLEN+1]; //+1 for null
    size_t  len;
} WString;

//copy *wchar_t to string
inline void wscpy(WString* dest, const wchar_t* src) {
    size_t len = wcslen(src);
    if (len > MAX_STRLEN) len = MAX_STRLEN;
    wmemcpy(dest->str,src,len);
    dest->str[len] = L'\0';
    dest->len = len;
}

//copy wstring to wstring
inline void wsCpy(WString* dest, const WString* src) {
    wmemcpy(dest->str,src->str,src->len);
    dest->str[src->len] = L'\0';
    dest->len = src->len;
}

//concat *wchar to wstring
inline void wscat(WString* dest, const wchar_t* src) {
    if (dest->len >= MAX_STRLEN) return;
    size_t len2cpy = wcslen(src);
    size_t totlen = dest->len + len2cpy; 
    if (totlen > MAX_STRLEN) {
        len2cpy = MAX_STRLEN - dest->len;
        totlen = MAX_STRLEN;
    }
    wmemcpy(&dest->str[dest->len], src, len2cpy);
    dest->str[totlen] = L'\0';
    dest->len = totlen;
}

//concat swtring to wstring
inline void wsCat(WString* dest, const WString* src) {
    if (dest->len >= MAX_STRLEN) return;
    size_t len2cpy =src->len;
    size_t totlen = dest->len + len2cpy; 
    if (totlen > MAX_STRLEN) {
        len2cpy = MAX_STRLEN - dest->len;
        totlen = MAX_STRLEN;
    }
    wmemcpy(&dest->str[dest->len],src->str, len2cpy);
    dest->str[totlen] = L'\0';
    dest->len = totlen;
}

inline void wsEmp(WString* dest) {
    //wmemset(dest->str, 0, MAX_STRLEN);
    dest->str[0] = L'\0';
    dest->len = 0;
}

inline bool wsIsEmp(WString* dest) {
    if (dest->len == 0) return true;
    return false;
}

//is equal? wstring and wchar*
inline bool wsequ(WString* dest, const wchar_t* src) {
    size_t len = wcslen(src);
    if (len != dest->len) return false;
    return (wmemcmp(dest->str, src, len)==0) ? true : false;
}

//is equal? string and string
inline bool wsEqu(WString* dest, const WString* src) {
    if (src->len != dest->len) return false;
    return (wmemcmp(dest->str, src->str, src->len)==0) ? true : false;
}

//startswith? string and char*
inline bool wstw(WString* dest, const wchar_t* src) {
   return (wmemcmp(dest->str, src, wcslen(src)) == 0) ? true: false;
}

//startswith? string and string
inline bool wsTW(WString* dest, const WString* src) {
   return (wmemcmp(dest->str, src->str, src->len) == 0) ? true: false;
}

//inspired from Apple Open Source
//https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/memmem.c
inline int wspos(const WString* l, const wchar_t* s) {
	register wchar_t *cur, *last;
	const wchar_t *cl = (const wchar_t *)l->str;
	const wchar_t *cs = (const wchar_t *)s;
	
	size_t s_len = wcslen(s);
	
	/* we need something to compare */
	if (l->len == 0 || s_len == 0) return -1;

	/* "s" must be smaller or equal to "l" */
	if (l->len < s_len) return -1;

	/* the last position where its possible to find "s" in "l" */
	last = (wchar_t *)cl + l->len - s_len;

	for (cur = (wchar_t *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && wmemcmp(cur, cs, s_len) == 0) return cur - cl;

	return -1;
}

inline int wsPos(const WString* l, const WString* s) {
	register wchar_t *cur, *last;
	const wchar_t *cl = (const wchar_t *)l->str;
	const wchar_t *cs = (const wchar_t *)s->str;
	
	/* we need something to compare */
	if (l->len == 0 || s->len == 0) return -1;

	/* "s" must be smaller or equal to "l" */
	if (l->len < s->len) return -1;

	/* the last position where its possible to find "s" in "l" */
	last = (char *)cl + l->len - s->len;

	for (cur = (char *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && wmemcmp(cur, cs, s->len) == 0) return cur - cl;

	return -1;
}

