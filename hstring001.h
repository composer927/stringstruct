#define MAX_STRLEN 1024

typedef struct {
    char str[MAX_STRLEN+1];
    size_t len;
} string;

inline void strCpy(string* dest, const char* cstr) {
    size_t len = strlen(cstr);
    if (len>MAX_STRLEN) len = MAX_STRLEN;
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
    memset(dest->str,0,MAX_STRLEN);
    dest->len = 0;
}
