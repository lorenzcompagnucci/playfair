#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

#define KEY_DATA_ERROR "ERROR WHILE ALLOCATING A COMPONENT OF key_data"

typedef struct _Key_Key_Data_t {
    char* alphabet;
    char* replacement;
    char* special;
    char* keyword;
} Key_Key_Data_t;

typedef struct _Key_key_t {
    Key_Key_Data_t* kd;
    char missing;
    char replacement;
    char special;
    char** matrix;
} Key_key_t;

Key_key_t* Key_getKey(char* key_path);

#endif //PLAYFAIR_KEY_H