#include "sorting.h"

const int RMAX = 100;

void sorting(int argc, char *argv[]) {
    int n;
    char g_i;
    int *a;

    /* Get no. of elements n and choice of generating/reading array from user*/
    Get_args(argc, argv, &n, &g_i);

    /* Allocate memory for array for n int elements*/
    a = (int *)malloc(n * sizeof(int));

    /* Generate or read in list depending on user choice*/
    if (g_i == 'g') {
        Generate_list(a, n);
        Print_list(a, n, "Before sort");
    } else {
        Read_list(a, n);
    }

    /* Perform odd-even sort*/
    Odd_even_sort(a, n);

    /* Print sorted list*/
    Print_list(a, n, "After sort");

    free(a);
}

/*-----------------------------------------------------------------
 * Function:  Usage
 * Purpose:   Summary of how to run program
 */
void Usage(char *prog_name) {
    fprintf(stderr, "usage:   %s <n> <g|i>\n", prog_name);
    fprintf(stderr, "   n:   number of elements in list\n");
    fprintf(stderr, "  'g':  generate list using a random number generator\n");
    fprintf(stderr, "  'i':  user input list\n");
} /* Usage */

/*-----------------------------------------------------------------
 * Function:  Get_args
 * Purpose:   Get and check command line arguments
 * In args:   argc, argv
 * Out args:  n_p, g_i_p
 */
void Get_args(int argc, char *argv[], int *n_p, char *g_i_p) {
    if (argc != 3) {
        Usage(argv[0]);
        exit(0);
    }
    *n_p = atoi(argv[1]);
    *g_i_p = argv[2][0];

    if (*n_p <= 0 || (*g_i_p != 'g' && *g_i_p != 'i')) {
        Usage(argv[0]);
        exit(0);
    }
} /* Get_args */

/*-----------------------------------------------------------------
 * Function:  Generate_list
 * Purpose:   Use random number generator to generate list elements
 * In args:   n
 * Out args:  a
 */
void Generate_list(int a[], int n) {
    int i;

    srandom(0);
    for (i = 0; i < n; i++)
        a[i] = random() % RMAX;
} /* Generate_list */

void Print_list(int a[], int n, char *title) {
    int i;

    printf("%s:\n", title);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");
} /* Print_list */

void Read_list(int a[], int n) {
    int i;

    printf("Please enter the elements of the list\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
} /* Read_list */

void Odd_even_sort(int a[] /* in/out */,
                   int n /* in     */) {
    int phase, i, temp;

    for (phase = 0; phase < n; phase++)
        if (phase % 2 == 0) { /* Even phase */
            for (i = 1; i < n; i += 2)
                if (a[i - 1] > a[i]) {
                    temp = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = temp;
                }
        } else { /* Odd phase */
            for (i = 1; i < n - 1; i += 2)
                if (a[i] > a[i + 1]) {
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
        }
} /* Odd_even_sort */
