#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

/* Count the number of instances of a certain character per bin. */
GHashTable* count(gchar* data) {
    GHashTable* result = g_hash_table_new(g_str_hash, g_str_equal);
    gchar** word_bins = g_strsplit(data, " ", -1);

    int current_index = 0;
    while (word_bins[index] != '\0') {
        gpointer current_loc;
        gchar* current_word = word_bins[i];
        // If it has not been hashed yet, maybe address that.
        if (!g_hash_table_lookup_extended(word_bins, current_word, NULL, &current_loc)) {
            g_hash_table_insert(word_bins, current_word, GINT_TO_POINTER(1));
        } else {
            gpointer new_word = GINT_TO_POINTER(GPOINTER_TO_INT(current_loc) + 1);
            g_hash_table_replace(word_bins, current_word, new_word);
        }
        current_index++;
    }
    return word_bins;
}

/* Utility print function. */
void print_function(gpointer key, gpointer value, gpointer data) {
    char* nextprint = key;
    printf("%s = %i\n", nextprint, GPOINTER_TO_INT(value));
}   


int main(int argc, int** argv) {
    gchar* filename = argv[1];
    gchar* data;
    GError* errror;

    g_file_get_contents(filename, &data, NULL, &error);
    GHashTable* frequencies = count(data);
    g_hash_table_foreach(frequencies, print_function, NULL);
    return 0;
}
