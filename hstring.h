#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <wchar.h>


#define MAX_STRLEN 1024

typedef struct {
	char    str[MAX_STRLEN + 1]; //+1 for null
	size_t  len;
} String;

//copy *char to string
inline void STRCPY(String* dest, const char* src) {
	size_t len = strlen(src);
	if (len > MAX_STRLEN) len = MAX_STRLEN;
	memcpy(dest->str, src, len);
	dest->str[len] = '\0';
	dest->len = len;
}

//as copy
inline void ASSIGN(String* dest, const char* src) { STRCPY(dest, src); }

//copy string to string
inline void STRSTRCPY(String* dest, const String* src) {
	memcpy(dest->str, src->str, src->len);
	dest->str[src->len] = '\0';
	dest->len = src->len;
}

inline String COPY(const String* dest, int startindex, int count) {
	size_t len;
	size_t tot = startindex + count;
	String result;
	if (startindex < 0 || count <= 0) {
		result.str[0] = '\0';
		result.len = 0;
		return result;
	}
	len = (tot >= dest->len) ? dest->len - startindex : count;
	memcpy(result.str, &dest->str[startindex], len);
	result.str[len] = '\0';
	result.len = len;
	return result;
}

inline String LEFTSTR(const String* dest, int count) {
	return COPY(dest, 0, count);
}

inline String RIGHTSTR(const String* dest, int count) {
	return COPY(dest, dest->len-count, count);
}

inline String LSTR(const String* dest, int count) {
	return COPY(dest, 0, count);
}

inline String RSTR(const String* dest, int count) {
	return COPY(dest, dest->len - count, count);
}

//concat *char to string
inline void STRCAT(String* dest, const char* src) {
	if (dest->len >= MAX_STRLEN) return;
	size_t len2cpy = strlen(src);
	size_t totlen = dest->len + len2cpy;
	if (totlen > MAX_STRLEN) {
		len2cpy = MAX_STRLEN - dest->len;
		totlen = MAX_STRLEN;
	}
	memcpy(&dest->str[dest->len], src, len2cpy);
	dest->str[totlen] = '\0';
	dest->len = totlen;
}

//concat string to string
inline void STRSTRCAT(String* dest, const String* src) {
	if (dest->len >= MAX_STRLEN) return;
	size_t len2cpy = src->len;
	size_t totlen = dest->len + len2cpy;
	if (totlen > MAX_STRLEN) {
		len2cpy = MAX_STRLEN - dest->len;
		totlen = MAX_STRLEN;
	}
	memcpy(&dest->str[dest->len], src->str, len2cpy);
	dest->str[totlen] = '\0';
	dest->len = totlen;
}

inline size_t LEN(String* dest) {
    return dest->len;
}

inline void MAKEEMP(String* dest) {
	dest->str[0] = '\0';
	dest->len = 0;
}

inline bool ISEMP(const String* dest) {
	if (dest->len == 0) return true;
	return false;
}

inline void DELETE(String* dest, int startindex, int count) {
	size_t tot = startindex + count;
	if (startindex < 0 || count < 0 || tot >= dest->len) return;
	memmove(&dest->str[startindex], &dest->str[tot], dest->len - tot);
	dest->len -= count;
	dest->str[dest->len] = '\0';
}

inline void INSERT(String* dest, int startindex, const char* src) {
	if (startindex >= dest->len) return;
	size_t len = strlen(src);
	if (dest->len + len > MAX_STRLEN) return;
	memmove(&dest->str[startindex + len], &dest->str[startindex], dest->len);
	memcpy(&dest->str[startindex], src, len);
	dest->len += len;
	dest->str[dest->len] = '\0';
}


//is equal? string and char*
inline bool ISEQU(const String* dest, const char* src) {
	size_t len = strlen(src);
	if (len != dest->len) return false;
	return (memcmp(dest->str, src, len) == 0) ? true : false;
}

//is equal? string and string
inline bool STRISEQU(const String* dest, const String* src) {
	if (src->len != dest->len) return false;
	return (memcmp(dest->str, src->str, src->len) == 0) ? true : false;
}

//startswith? string and char*
inline bool STARTSWITH(const String* dest, const char* src) {
	return (memcmp(dest->str, src, strlen(src)) == 0) ? true : false;
}

//startswith? string and string
inline bool STRSTARTSWITH(const String* dest, const String* src) {
	return (memcmp(dest->str, src->str, src->len) == 0) ? true : false;
}

//endswith? string and char*
//0 1 2 3 4 5
inline bool ENDSWITH(const String* dest, const char* src) {
	size_t len = strlen(src);
	return (memcmp(&dest->str[dest->len - len], src, len) == 0) ? true : false;
}

//endswith? string and string
inline bool STRENDSWITH(const String* dest, const String* src) {
	return (memcmp(&dest->str[dest->len - src->len], src->str, src->len) == 0) ? true : false;
}

//inspired from Apple Open Source
//https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/memmem.c
inline int POS(const String* l, const char* s) {
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

inline int STRPOS(const String* l, const String* s) {
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

inline bool CONTAINS(const String* l, const char* s) {
	return (POS(l, s) >-1) ? true : false;
}

inline bool STRCONTAINS(const String* l, const String* s) {
	return (STRPOS(l, s) >-1) ? true : false;
}

inline void REPLACE(String* dest, const char* olD, const char* neW) {
	size_t olDlen = strlen(olD);
	size_t neWlen = strlen(neW);
	if ((dest->len-olDlen+neWlen) > MAX_STRLEN) return;
	int pos = POS(dest, olD);
	if (pos < 0) return;
	while (pos>-1) {
		DELETE(dest, pos, olDlen);
		INSERT(dest, pos, neW);
		pos = POS(dest, olD);
	}
}

inline void STRREPLACE(String* dest, const String* olD, const String* neW) {
    if ((dest->len-olD->len+neW->len) > MAX_STRLEN) return;
	int pos = STRPOS(dest, olD);
	if (pos < 0) return;
	while (pos>-1) {
		DELETE(dest, pos, olD->len);
		INSERT(dest, pos, neW->str);
		pos = STRPOS(dest, olD);
	}
}

//inspired from Michael Burr
//https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
inline void TRIMLEFT(String* dest) {
    if (dest->len < 1) return; 
    char* newstart = dest->str;
    int whcount = 0;

    while (isspace( *newstart)) {
        ++newstart;
        ++whcount;
    }
    dest->len -= whcount;
    memmove( dest->str, newstart, dest->len);
    dest->str[dest->len] = '\0';
}

inline void LTRIM(String* dest) {
    TRIMLEFT(dest);
}

inline void TRIMRIGHT(String* dest) {
    if (dest->len < 1) return; 
    char* end = dest->str + dest->len;
    int whcount = 0;
    while ((end != dest->str) && isspace( *(end-1))) {
            --end;
            ++whcount;
    }
    
    dest->len -= whcount;
    *end = '\0';
}

inline void RTRIM(String* dest) {
    TRIMRIGHT(dest);
}

inline void TRIM(String* dest) {
    TRIMRIGHT(dest);
    TRIMLEFT(dest);
}


inline void DUPE(String* dest, const char* src, int count) {
    if (count < 1) return;
    size_t len = strlen(src);
    size_t totlen = len*count;
    if (totlen > MAX_STRLEN) totlen = MAX_STRLEN;
    dest->len = totlen;
    int i = 0;
    while (i < dest->len) {
        memcpy(&dest->str[i], src, len );
        i += len;
    }
    dest->str[dest->len] = '\0';
}

inline void ADDDUPE(String* dest, const char* src, int count) {
    if (count < 1) return;
    size_t len = strlen(src);
    size_t totlen = dest->len + (len*count);
    if (totlen > MAX_STRLEN) totlen = MAX_STRLEN;
    int i = dest->len;
    while (i < totlen) {
        memcpy(&dest->str[i], src, len );
        i += len;
    }
    dest->len = totlen;
    dest->str[dest->len] = '\0';
}

inline void TOUPP(String* dest) {
    for (int i = 0; i < dest->len; i++) dest->str[i] = toupper((unsigned char)dest->str[i]);
}

inline void TOLOW(String* dest) {
    for (int i = 0; i < dest->len; i++) dest->str[i] = tolower((unsigned char)dest->str[i]);
}


inline String ITOS(int i) {
    String s;
    sprintf(s.str, "%d", i);
    return s;
}

inline int STOI(String* s) {
    return atoi(s->str);
}




//##############################################################################
//##############################################################################
//##############################################################################

typedef struct {
	wchar_t   str[MAX_STRLEN + 1]; //+1 for null
	size_t  len;
} WString;

//copy *wchar_t to string
inline void WSTRCPY(WString* dest, const wchar_t* src) {
	size_t len = wcslen(src);
	if (len > MAX_STRLEN) len = MAX_STRLEN;
	wmemcpy(dest->str, src, len);
	dest->str[len] = L'\0';
	dest->len = len;
}

//as Wcopy
inline void WASSIGN(WString* dest, const wchar_t* src) { WSTRCPY(dest, src); }

//copy wstring to wstring
inline void WSTRSTRCPY(WString* dest, const WString* src) {
	wmemcpy(dest->str, src->str, src->len);
	dest->str[src->len] = L'\0';
	dest->len = src->len;
}

//PASCAL COPY
inline WString WCOPY(const WString* dest, int startindex, int count) {
	size_t len;
	size_t tot = startindex + count;
	WString result;
	if (startindex < 0 || count <= 0) {
		result.str[0] = L'\0';
		result.len = 0;
		return result;
	}
	len = (tot >= dest->len) ? dest->len - startindex : count;
	wmemcpy(result.str, &dest->str[startindex], len);
	result.str[len] = L'\0';
	result.len = len;
	return result;
}

inline WString WLEFTSTR(const WString* dest, int count) {
	return WCOPY(dest, 0, count);
}

inline WString WRIGHTSTR(const WString* dest, int count) {
	return WCOPY(dest, dest->len - count, count);
}

inline WString WLSTR(const WString* dest, int count) {
	return WCOPY(dest, 0, count);
}

inline WString WRSTR(const WString* dest, int count) {
	return WCOPY(dest, dest->len - count, count);
}

//concat *wchar to wstring
inline void WSTRCAT(WString* dest, const wchar_t* src) {
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
inline void WSTRSTRCAT(WString* dest, const WString* src) {
	if (dest->len >= MAX_STRLEN) return;
	size_t len2cpy = src->len;
	size_t totlen = dest->len + len2cpy;
	if (totlen > MAX_STRLEN) {
		len2cpy = MAX_STRLEN - dest->len;
		totlen = MAX_STRLEN;
	}
	wmemcpy(&dest->str[dest->len], src->str, len2cpy);
	dest->str[totlen] = L'\0';
	dest->len = totlen;
}

inline size_t WLEN(WString* dest) {
    return dest->len;
}

inline void WMAKEEMP(WString* dest) {
	dest->str[0] = L'\0';
	dest->len = 0;
}

inline bool WISEMP(WString* dest) {
	if (dest->len == 0) return true;
	return false;
}

inline void WDELETE(WString* dest, int startindex, int count) {
	size_t tot = startindex + count;
	if (startindex < 0 || count < 0 || tot >= dest->len) return;
	wmemmove(&dest->str[startindex], &dest->str[tot], dest->len - tot);
	dest->len -= count;
	dest->str[dest->len] = '\0';
}

inline void WINSERT(WString* dest, int startindex, const wchar_t* src) {
	if (startindex >= dest->len) return;
	size_t len = wcslen(src);
	if (dest->len + len > MAX_STRLEN) return;
	wmemmove(&dest->str[startindex + len], &dest->str[startindex], dest->len);
	wmemcpy(&dest->str[startindex], src, len);
	dest->len += len;
	dest->str[dest->len] = '\0';
}

//is equal? wstring and wchar*
inline bool WISEQU(WString* dest, const wchar_t* src) {
	size_t len = wcslen(src);
	if (len != dest->len) return false;
	return (wmemcmp(dest->str, src, len) == 0) ? true : false;
}

//is equal? Wstring and Wstring
inline bool WSTRISEQU(WString* dest, const WString* src) {
	if (src->len != dest->len) return false;
	return (wmemcmp(dest->str, src->str, src->len) == 0) ? true : false;
}

//Wstartswith? Wstring and Wchar*
inline bool WSTARTSWITH(WString* dest, const wchar_t* src) {
	return (wmemcmp(dest->str, src, wcslen(src)) == 0) ? true : false;
}

//startswith? Wstring and Wstring
inline bool WSTRSTARTSWITH(WString* dest, const WString* src) {
	return (wmemcmp(dest->str, src->str, src->len) == 0) ? true : false;
}

//endswith? Wstring and Wchar*
//0 1 2 3 4 5
inline bool WENDSWITH(const String* dest, const wchar_t* src) {
	size_t len = wcslen(src);
	return (wmemcmp(&dest->str[dest->len - len], src, len) == 0) ? true : false;
}

//endswith? Wstring and Wstring
inline bool WSTRENDSWITH(const WString* dest, const WString* src) {
	return (wmemcmp(&dest->str[dest->len - src->len], src->str, src->len) == 0) ? true : false;
}

//inspired from Apple Open Source
//https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/memmem.c
inline int WPOS(const WString* l, const wchar_t* s) {
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

inline int WSTRPOS(const WString* l, const WString* s) {
	register wchar_t *cur, *last;
	const wchar_t *cl = (const wchar_t *)l->str;
	const wchar_t *cs = (const wchar_t *)s->str;

	/* we need something to compare */
	if (l->len == 0 || s->len == 0) return -1;

	/* "s" must be smaller or equal to "l" */
	if (l->len < s->len) return -1;

	/* the last position where its possible to find "s" in "l" */
	last = (wchar_t *)cl + l->len - s->len;

	for (cur = (wchar_t *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && wmemcmp(cur, cs, s->len) == 0) return cur - cl;

	return -1;
}

inline bool WCONTAINS(const WString* l, const wchar_t* s) {
	return (WPOS(l, s) >-1) ? true : false;
}

inline bool WSTRCONTAINS(const WString* l, const WString* s) {
	return (WSTRPOS(l, s) >-1) ? true : false;
}

inline void WREPLACE(WString* dest, const wchar_t* olD, const wchar_t* neW) {
	size_t olDlen = wcslen(olD);
	size_t neWlen = wcslen(neW);
	if ((dest->len-olDlen+neWlen) > MAX_STRLEN) return;
	int pos = WPOS(dest, olD);
	if (pos < 0) return;
	while (pos>-1) {
		WDELETE(dest, pos, olDlen);
		WINSERT(dest, pos, neW);
		pos = WPOS(dest, olD);
	}
}

inline void WSTRREPLACE(WString* dest, const WString* olD, const WString* neW) {
    if ((dest->len-olD->len+neW->len) > MAX_STRLEN) return;
	int pos = WSTRPOS(dest, olD);
	if (pos < 0) return;
	while (pos>-1) {
		WDELETE(dest, pos, olD->len);
		WINSERT(dest, pos, neW->str);
		pos = WSTRPOS(dest, olD);
	}
}

//inspired from Michael Burr
//https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
inline void WTRIMLEFT(WString* dest) {
    if (dest->len < 1) return; 
    wchar_t* newstart = dest->str;
    int whcount = 0;

    while (iswspace( *newstart)) {
        ++newstart;
        ++whcount;
    }
    dest->len -= whcount;
    wmemmove( dest->str, newstart, dest->len);
    dest->str[dest->len] = L'\0';
}

inline void WLTRIM(WString* dest) {
    WTRIMLEFT(dest);
}

inline void WTRIMRIGHT(WString* dest) {
    if (dest->len < 1) return; 
    wchar_t* end = dest->str + dest->len;
    int whcount = 0;
    while ((end != dest->str) && iswspace( *(end-1))) {
            --end;
            ++whcount;
    }
    
    dest->len -= whcount;
    *end = L'\0';
}

inline void WRTRIM(WString* dest) {
    WTRIMRIGHT(dest);
}

inline void WTRIM(WString* dest) {
   WRIGHTTRIM(dest);
   WLEFTRIM(dest);
}

inline void WDUPE(WString* dest, const wchar_t* src, int count) {
    if (count < 1) return;
    size_t len = wcslen(src);
    size_t totlen = len*count;
    if (totlen > MAX_STRLEN) totlen = MAX_STRLEN;
    dest->len = totlen;
    int i = 0;
    while (i<dest->len) {
        wmemcpy(&dest->str[i], src, len );
        i += len;
    }
    dest->str[dest->len] = L'\0';
}

inline void WADDDUPE(WString* dest, const wchar_t* src, int count) {
    if (count < 1) return;
    size_t len = wcslen(src);
    size_t totlen = dest->len + (len*count);
    if (totlen > MAX_STRLEN) totlen = MAX_STRLEN;
    int i = dest->len;
    while ( i< totlen) {
        wmemcpy(&dest->str[i], src, len );
        i += len;
    }
    dest->len = totlen;
    dest->str[dest->len] = L'\0';
}

inline void WTOUPP(WString* dest) {
    for (int i = 0; i < dest->len; i++) dest->str[i] = towupper((unsigned char)dest->str[i]);
}

inline void WTOLOW(WString* dest) {
    for (int i = 0; i < dest->len; i++) dest->str[i] = towlower((unsigned char)dest->str[i]);
}

inline WString ITOWS(int i) {
    WString s;
    swprintf(s.str, MAX_STRLEN, L"%d", i);
    return s;
}

inline int WSTOI(WString* s) {
    return wcstol(s->str,0,10);
}

inline String WTOS(const wchar_t* src) {
    size_t len = wcslen(src);
    String dest;
    wcstombs(dest.str, src, len);
    dest.len = len;
    dest.str[dest.len] = '\0';
    return dest;
}

inline WString STOW(const char* src) {
    size_t len = strlen(src);
    WString dest;
    mbstowcs(dest.str, src, len);
    dest.len = len;
    dest.str[dest.len] = L'\0';
    return dest;
}

