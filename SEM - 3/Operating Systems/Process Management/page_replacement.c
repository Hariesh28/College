#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fifo(int pages[], int page_count, int frame[], int frame_count);
int lru(int pages[], int page_count, int frame[], int frame_count);
int mru(int pages[], int page_count, int frame[], int frame_count);
int optimal(int pages[], int page_count, int frame[], int frame_count);

int main(){

    int page_count;
    printf("Enter no. of pages: ");
    scanf("%d", &page_count);

    int pages[page_count];
    for (int i = 0; i < page_count; i++) scanf("%d", &pages[i]);

    int frame_size;
    printf("Enter frame size: ");
    scanf("%d", &frame_size);

    int frames[frame_size];

    printf("FIFO: %d\n", fifo(pages, page_count, frames, frame_size));
    printf("LRU: %d\n", lru(pages, page_count, frames, frame_size));
    printf("MRU: %d\n", mru(pages, page_count, frames, frame_size));
    printf("OPTIMAL: %d\n", optimal(pages, page_count, frames, frame_size));

    return 0;
}

int fifo(int pages[], int page_count, int frame[], int frame_count){

    int page_faults = 0;
    int index = 0;
    bool found;

    for (int i = 0; i < frame_count; i++) frame[i] = -1;

    for (int i = 0; i < page_count; i++){

        found = false;

        for (int j = 0; j < frame_count; j++){

            if (frame[j] == pages[i]){

                found = true;
                break;
            }
        }

        if (!found){

            frame[index] = pages[i];
            index = (index + 1) % frame_count;
            page_faults++;
        }
    }

    return page_faults;
}

int lru(int pages[], int page_count, int frame[], int frame_count){

    int page_fault = 0;
    int time[frame_count];
    bool found;

    for (int i = 0; i < frame_count; i++) frame[i] = -1;

    for (int i = 0; i < page_count; i++){

        found = false;

        for (int j = 0; j < frame_count; j++){

            if (frame[j] == pages[i]){

                time[j] = i;
                found = true;
                break;
            }
        }

        if (!found){

            int lru_index = 0;

            for (int i = 0; i < frame_count; i++) if (time[i] < time[lru_index]) lru_index = i;

            frame[lru_index] = pages[i];
            time[lru_index] = i;
            page_fault++;
        }
    }

    return page_fault;
}

int mru(int pages[], int page_count, int frame[], int frame_count){

    int page_fault = 0;
    int time[frame_count];
    bool found;

    for (int i = 0; i < frame_count; i++) frame[i] = -1;

    for (int i = 0; i < page_count; i++){

        found = false;

        for (int j = 0; j < frame_count; j++){

            if (frame[j] == pages[i]){

                time[j] = i;
                found = true;
                break;
            }
        }

        if (!found){

            int mru_index = 0;

            for (int i = 0; i < frame_count; i++) if (time[i] > time[mru_index]) mru_index = i;

            frame[mru_index] = pages[i];
            time[mru_index] = i;
            page_fault++;
        }
    }

    return page_fault;
}

int optimal(int pages[], int page_count, int frame[], int frame_count){

    int page_fault = 0;
    bool found;

    for (int i = 0; i < frame_count; i++) frame[i] = -1;

    for (int i = 0; i < page_count; i++){

        found = false;

        for (int j = 0; j < frame_count; j++){

            if (frame[j] == pages[i]){

                found = true;
                break;
            }
        }

        if (!found){

            int far = i, index = -1;

            for (int j = 0; j < frame_count; j++){

                int k;

                for (k = i + 1; k < page_count; k++){

                    if (frame[j] == pages[k]) break;
                }

                if (k > far){

                    far = k;
                    index = j;
                }
            }

            if (index == -1) index = 0;
            frame[index] = pages[i];
            page_fault++;
        }
    }

    return page_fault;
}