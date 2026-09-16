#include <stdio.h>
#include "config.h"

void my_quick_sort(int *arr, size_t size, size_t left, size_t right);
void print_qs_arr(int *arr, size_t size, size_t left, size_t right, int mid_value, const char *reason);
static void swap(int *a, int *b);

int main(void)
{
    size_t size = 3;

    int arr[] = {3, 1, 2};

    my_quick_sort(arr, size, 0, size - 1);

    return 0;
}

void my_quick_sort(int *arr, size_t size, size_t first, size_t last)
{
    if (first >= last)
        return;

    int mid_el = arr[(first + last) / 2];

    size_t left = first, right = last;

    while (left <= right)
    {
        print_qs_arr(arr, size, left, right, mid_el, "Новая итерация цикла");

        while (left < last && arr[left] < mid_el)
        {
            left++;
            print_qs_arr(arr, size, left, right, mid_el, "Увеличение left");
        }

        while (right > first && arr[right] > mid_el)
        {
            right--;
            print_qs_arr(arr, size, left, right, mid_el, "Уменьшение right");
        }

        if (left < right)
        {
            print_qs_arr(arr, size, left, right, mid_el, "До обмена");
            swap(arr + left++, arr + right--);
            print_qs_arr(arr, size, left, right, mid_el, "После обмена");
        }
    }

    print_qs_arr(arr, size, left, right, mid_el, "Вышли из цикла");

    if (size > 2)
    {
        my_quick_sort(arr + first, right - first + 1, 0, right - first);
        my_quick_sort(arr + left, last - left + 1, 0, last - left);
    }
}

void print_qs_arr(int *arr, size_t size, size_t left, size_t right, int mid_value, const char *reason)
{
    printf(GREEN_COLOR);
    printf("------------------------------------------------------------------------------------\n");

    int before_left_chars_count = 0,
        before_right_chars_count = 0;

    int *paddings = (int *)calloc(size, sizeof(int));

    for (size_t i = 0; i < size; i++)
    {
        if (i < left)
            printf(BLUE_COLOR);
        else if (i == left)
            printf(GREEN_COLOR);
        else if (left < i && i < right)
            printf(GREY_COLOR);
        else if (i == right)
            printf(YELLOW_COLOR);
        else if (i > right)
            printf(RED_COLOR);

        int symb_count = printf("%d ", arr[i]);
        paddings[i] = symb_count;

        if (i < left)
        {
            before_left_chars_count += symb_count;
        }
        if (i < right)
        {
            before_right_chars_count += symb_count;
        }
    }

    printf(RESET_COLOR);
    printf("\n");

    for (size_t i = 0; i < size; i++)
    {
        if (i == 0)
            printf("%zu", i);
        else
        {
            printf("%*zu", paddings[i], i);
        }
    }

    printf("\n");

    printf(BLUE_COLOR);
    int symb_count = printf("%*c", before_left_chars_count + 1, 'L');

    printf(RED_COLOR);
    printf("%*c", before_right_chars_count - symb_count + 1, 'R');

    printf("\n");

    printf(GREEN_COLOR);
    printf("\nLeft = %lu, Right = %lu\n", left, right);

    printf(RESET_COLOR);
    printf("Middle value = %d\n", mid_value);

    printf(BLUE_COLOR);
    printf("Reason: %s\n", reason);

    printf(RED_COLOR);
    printf("------------------------------------------------------------------------------------\n\n");
    printf(RESET_COLOR);

    free_ptr(paddings);

    getchar();
}

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
