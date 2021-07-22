// Assignment 2 21T1 COMP1511: Beats by CSE
// beats.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.

#include "beats.h"

// Add your own #defines here.

//////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    // TODO: You will have to add extra fields here in Stage 2.
    struct beat *head;
};

// You don't have to use the provided struct beat, you are free to
// make your own struct instead.
// If you use the provided struct beat, you may add fields
// to it to store other information.

struct beat {
    // You may choose to add or change fields in this struct.
    struct note *notes;
    struct beat *next;
};

// You don't have to use the provided struct note, you are free to
// make your own struct instead.
// If you use the provided struct note, you add fields
// to it to store other information.

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.
typedef struct note *Note;
//////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.

Note create_note(Note new_next, int new_octave, int new_key);
int compare_notes(Note curr, int octave, int key);
Note insert_after(Note insert_pos, int octave, int key);;
void print_note(Note note);


// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;

    // You do not need to change this function, unless you change
    // the implementation of struct beat.

    return new_beat;
}

// You need to implement the following functions.
// You can find descriptions of what each function should do in beats.h

//////////////////////////////////////////////////////////////////////
//                        Stage 1 Functions                         //
//////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {
    // Octave check, non-negative integer less than 10
    if(octave < 0 || octave > 9)
        return INVALID_OCTAVE;
    // Key check, non-negative integer less than 12
    if(key < 0 || key > 11)
        return INVALID_KEY;

    if(beat->notes == NULL) {
        beat->notes = insert_after(beat->notes, octave, key);
    }else {
        Note curr = beat->notes;
        Note prev = NULL;

        // Check if note exists already
        while(curr != NULL) {
            if(curr->octave == octave && curr->key == key) {
                return NOT_HIGHEST_NOTE;
            }
            curr =  curr->next;
        }

        // reset curr to head and find node to insert after
        curr = beat->notes;
        while(curr != NULL && compare_notes(curr, octave, key) < 0){
            prev = curr;
            curr = curr->next;
        }

        Note insert_result = insert_after(prev, octave, key);

        if(prev == NULL) {
            insert_result->next = beat->notes;
            beat->notes = insert_result;
        }
    }
    return VALID_NOTE;
}

// Returns a new note pointer but as our typedef
Note create_note(Note new_next, int new_octave, int new_key) {
    Note n = malloc(sizeof (struct note));
    n->octave = new_octave;
    n->key = new_key;
    n->next = new_next;
    return n;
}

// Note curr is the note in the list being examined
// octave & key are what makes up the prospective note
// Returns < 0 if given octave is greater than curr's
// Returns < 0 if given octave equals curr's but given key is
// greater than curr's
// Returns 0 if previous checks passed
int compare_notes(Note curr, int octave, int key) {

    if(octave > curr->octave) {
        return NOT_HIGHEST_NOTE;
    }

    if(octave == curr->octave) {
        if(key > curr->key) {
            return NOT_HIGHEST_NOTE;
        }
    }

    return VALID_NOTE;
}

// Inserts a node into a linked list after the node insert_pos
// Assumes the list is in working order, meaning the new octave and key
// are at least 1 of two things:
//  1) octave equals insert octave but key is higher
//  2) octave is greater than the insert_pos octave and if there is a next pointer
//     the note has either same octave and higher note OR higher octave
// Returns the insert pos or pointer to new list if given list is empty
Note insert_after(Note insert_pos, int octave, int key) {
    // Handle empty list situation
    if(insert_pos == NULL) {
        // new_note is now the head and our temporarily NULL insert_pos
        // is used to set the next pointer of this new note as it's the
        // only element in the list at the moment
        Note new_note = create_note(insert_pos, octave, key);

        // Set insert_pos as the new_note
        insert_pos = new_note;
    } else {
        // Insert into the list after the given note
        // Insert_post->next is either NULL or another note. So it will
        // either insert the note at the end of the list if insert_pos
        // was the end of the list OR it will insert the note as the next of
        // insert_pos after making the new_note point to the insert_pos'
        // next note.
        Note new_note = create_note(insert_pos->next, octave, key);
        // Actually insert the new note as the next note that
        // insert_pos points to
        insert_pos->next = new_note;

    }
    return insert_pos;
}

void print_note(Note note) {
    printf("Octave: %d\n", note->octave);
    printf("Key: %d\n", note->key);
}

// Print the contents of a beat.
void print_beat(Beat beat) {
    Note curr = beat->notes;
    while(curr != NULL) {
        if(curr->next == NULL) {
            printf(" %d %d", curr->octave, curr->key);
        }else {
            printf(" %d %d |", curr->octave, curr->key);
        }
        curr = curr->next;
    }
    return;
}

// Count the number of notes in a beat that are in a given octave.
// Returns 0
int count_notes_in_octave(Beat beat, int octave) {
    if(octave < 0 || octave > 9) {
        return 0;
    }else{
        Note curr = beat->notes;
        int count = 0;
        while(curr != NULL) {
            if(curr->octave == octave) {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }
}

//////////////////////////////////////////////////////////////////////
//                        Stage 2 Functions                         //
//////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    // Note: there is no fprintf in this function, as the
    // Stage 1 autotests call create_track but expect it to return NULL
    // (so this function should do nothing in Stage 1).

    return NULL;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {
    printf("add_beat_to_track not implemented yet.\n");
    return;
}

// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    printf("select_next_beat not implemented yet.\n");
    return TRACK_STOPPED;
}

// Print the contents of a track.
void print_track(Track track) {
    printf("print_track not implemented yet.\n");
    return;
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {
    printf("count_beats_left_in_track not implemented yet.\n");
    return 0;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 3 Functions                         //
//////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    Note next;
    while(beat->notes != NULL) {
        next = beat->notes->next;
        free(beat->notes);
        beat->notes = next;
    }
    free(beat);
    return;
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    if(track == NULL) {
        return;
    }
    Beat next;
    while(track->head != NULL) {
        next = track->head->next;
        free_beat(track->head);
        track->head = next;
    }
    free(track);
    return;
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {
    printf("remove_selected_beat not implemented yet.");
    return TRACK_STOPPED;
}
