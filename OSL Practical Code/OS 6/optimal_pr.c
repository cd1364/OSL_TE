#include <stdio.h>
#include <stdbool.h>

int findOptimal(int frame[], int ref_str[], int n, int no, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < no; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == ref_str[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int i, j, n, ref_str[50], frame[10], no, k, fcount = 0;  // Declaration of variables required
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);  // total no. of pages in reference string
    printf("\n ENTER THE PAGE NUMBER :\n");
    for (i = 0; i < n; i++)  // accept entire reference string
        scanf("%d", &ref_str[i]);
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
        frame[i] = -1;  // initialize all page frames to -1

    printf("\n ref string  \t page frames     \tHit/Fault\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", ref_str[i]);
        bool isPageFault = true;
        for (k = 0; k < no; k++) {
            if (frame[k] == ref_str[i]) {  // input of page requested is compared with existing content of FRAME
                isPageFault = false;
                printf("%d\t", frame[k]);   // Print Current state of FRAME
                printf("H");                        // Indication of Page Hit
                break;
            }
        }
        if (isPageFault) {  // input page requested NOT existing in FRAME
            int pos = findOptimal(frame, ref_str, n, no, i + 1);
            frame[pos] = ref_str[i];  // place page requested at position in FRAME
            fcount++;  // Increment Counter for Page Fault
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);  // Print Current state of FRAME
            printf("F");  // Indication of Page Fault
        }
        printf("\n");
    }
    printf("Page Fault Is %d", fcount);
    return 0;
}
