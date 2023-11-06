//Activity Selection Problem

#include <stdio.h>
struct activity {
    int start;
    int finish;
    char name[2];
} a[6], temp, solution[6];

int main(void) {
// Input activities
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a[i].start);
        scanf("%d", &a[i].finish);
        //scanf("%s", a[i].name);
    }

// Bubble sort
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (a[j].finish > a[j + 1].finish)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

// Select activities
    int count = 1;
    solution[0] = a[0];
    for (int i = 1; i < 6; i++)
    {
        if (a[i].start >= solution[count - 1].finish)
        {
            count++;
            solution[count - 1] = a[i];

        }
    }
// Print selected activities
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%s\n", solution[i].start, solution[i].finish, solution[i].name);
    };
    printf("Number of selected activities: %d\n", count);
    return 0;
}


/*

Input Set
0 6
5 7
3 4
1 2
8 9
5 9

*/