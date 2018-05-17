#pragma once
#include <stdbool.h>

#define MAX_STRLEN 1024


typedef struct {
    char    str[MAX_STRLEN+1]; //+1 for null
    size_t  len;
} string;

//copy *char to string
inline void scpy(string* dest, const char* src) {
    size_t len = strlen(src);
    if (len > MAX_STRLEN) len = MAX_STRLEN;
    memcpy(dest->str,src,len);
    dest->str[len] = '\0';
    dest->len = len;
}

//copy string to string
inline void sCpy(string* dest, const string* src) {
    memcpy(dest->str,src->str,src->len);
    dest->str[src->len] = '\0';
    dest->len = src->len;
}

//concat *char to string
inline void scat(string* dest, const char* src) {
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
inline void sCat(string* dest, const string* src) {
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

inline void strEmpty(string* dest) {
    //memset(dest->str, 0, MAX_STRLEN);
    dest->str[0] = '\0';
    dest->len = 0;
}

inline bool strIsEmpty(string* dest) {
    if (dest->len == 0) return true;
    //we use null chars in our strings.
    //so null char does not determine the length
    //if (dest->str[0] == '\0') return true;
    return false;
}

//is equal? string and char*
inline bool sequ(string* dest, const char* src) {
    size_t len = strlen(src);
    if (len != dest->len) return false;
    return (memcmp(dest->str, src, len)==0) ? true : false;
}

//is equal? string and string
inline bool sEqu(string* dest, const string* src) {
    if (src->len != dest->len) return false;
    return (memcmp(dest->str, src->str, src->len)==0) ? true : false;
}

//startswith? string and char*
inline bool stw(string* dest, const char* src) {
   return (memcmp(dest->str, src, strlen(src)) == 0) ? true: false;
}

//startswith? string and string
inline bool sTW(string* dest, const string* src) {
   return (memcmp(dest->str, src->str, src->len) == 0) ? true: false;
}

//inspired from Apple Open Source
//https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/memmem.c
inline int spos(const string* l, const char *s) {
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

inline int sPos(const string* l, const string* s) {
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

