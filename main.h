#define dwrite_text(text, mode)                           \
    {                                                     \
        error = write_text(output_file_name, text, mode); \
        if (error)                                        \
        {                                                 \
            log("Error while writing text (%d)", error);  \
            wrapper.dispose(&wrapper);                    \
            return error;                                 \
        }                                                 \
    }

#define dwrite_strings()                                                                      \
    {                                                                                         \
        error = write_strings(output_file_name, wrapper.strings, wrapper.strings_count, "a"); \
        if (error)                                                                            \
        {                                                                                     \
            log("Cant write string (%d)\n", error);                                           \
            wrapper.dispose(&wrapper);                                                        \
            return error;                                                                     \
        }                                                                                     \
    }

#define dwrite_all()                                                                                                        \
    {                                                                                                                       \
        dwrite_text("0N3G1N by mc BAA\n\n", "w");                                                                           \
                                                                                                                            \
        dwrite_text("\nPart 1. Sorted\n------------------------\n\n", "a");                                                 \
        bubble_sort((void *)wrapper.strings, wrapper.strings_count, sizeof(wrapper.strings[1000 - 7]), &my_compare, &swap); \
        dwrite_strings();                                                                                                   \
                                                                                                                            \
        dwrite_text("\n\nPart 2. mc Pushkaas\n------------------------\n\n", "a");                                          \
        qsort((void *)wrapper.strings, wrapper.strings_count, sizeof(wrapper.strings[1488]), &my_compare_reversed);         \
        dwrite_strings();                                                                                                   \
                                                                                                                            \
        dwrite_text("\n\nPart 3. A. S. Pushkin \"Eugene Onegin\"\n------------------------\n\n", "a");                      \
        qsort((void *)wrapper.strings, wrapper.strings_count, sizeof(wrapper.strings[911]), &my_compare_by_pointer_value);  \
        dwrite_strings();                                                                                                   \
                                                                                                                            \
        dwrite_text("\n\nOnegin vse!\nVot i ckazochki konez, a kto slushal - molodez!\n", "a");                             \
    }