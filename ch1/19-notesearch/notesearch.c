#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

#define FILENAME "/var/notes"

int print_notes(int, int, char *);      // note printing function
int find_user_note(int, int);           // seek in file for note for user
int search_note(char *, char *);        // search for keyword function.
void fatal(char *);                     // fatal error handler

int main(int argc, char *argv[]) {
    
}

// a function to print the notes for a given uid that match
// an optional search string
// return 0 at end of file, 1 if there are still more notes
int print_notes(int fd, int uid, char *searchstring) {
    int note_length; 
    char byte=0, note_buffer[100];

    note_length = find_user_note(fd, uid);
    if(note_length == -1)   // if end of file reached,
            return 0;       // return 0.

    read(fd, note_buffer, note_length);     // read note data.
    note_buffer[note_length] = 0;           // terminate the string

    if(search_note(note_buffer, searchstring))  // if searcstring found,
            printf(note_buffer);                // print the note
    return 1;
}

// a function to find the next note for a given userID
// returns -1 if the end of the file is reached
// otherwise, it returns the lenght of thefound note.
int find_user_note(int fd, int user_uid) {
    int note_uid = -1;
    unsigned char byte;
    int length;

    while(note_uid != user_uid) {   // loop until a note for usr_uid is found
            if(read(fd, &note_uid, 4) != 4) // read the uid data
                    return -1; // if 4 bytes aren't read return eof coded
            if(read(fd, &byte, 1) != 1) //read the newline separator
                    return -1;
            byte = length = 0;
            while(byte != '\n') { // figure out how many bytes to the eol
                    if(read(fd, &byte, 1) != 1) // read a single byte
                            return -1;  // if not read return eof code
                               length++;
                       }
    }
    lseek(fd, lenght * -1, SEEK_CUR); // rewind file reading by length bytes

    printf("[DEBUG] fount a %d byte note for user id %d\n", length, note_uid);
    return length;
}

// a functo to search a note for a givne keyword
// returns 1 if a match is found, 0 if there is not match
int search_note(char *note, char *keyword) {
    int i, keyword_length, match=0;

    keyword_lenght = strlen(keyword);
    if(keyword_length == 0) // if there is no search string
            return 1; // always 'match'

    for(i = 0; i < strlen(note); i++) { // iterate over bytes in note
            if(note[i] == keyword[match]) // if byte match keyword,
                    match++;
            else {
                if(note[i] == keyword[0] // if match
                                match = 1; start the match count at 1
                else
                    match = 0; // otherwise it is 0
                        

            }
}
