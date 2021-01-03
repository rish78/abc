#include <stdio.h>

int main(){
    int t, john_packs, jack_packs;
    scanf("%d", &t);
    while (t != 0){
        scanf("%d %d", &john_packs, &jack_packs);
        int jack[jack_packs], john[john_packs];
        int jack_sum = 0, john_sum = 0;
        for (int i = 0; i < john_packs; i++){
            scanf("%d", &john[i]);
            john_sum += john[i];
        }

        for (int i = 0; i < jack_packs; i++){
            scanf("%d", &jack[i]);
            jack_sum += jack[i];
        }

        //selection sort of john's votes
        for (int i = 0; i < john_packs; i++){
            for (int j = i+1; j < john_packs; j++){
                if (john[i] > john[j]){
                    int temp = john[i];
                    john[i] = john[j];
                    john[j] = temp;
                }
            }
        }

        //selection sort of jack's votes
        for (int i = 0; i < jack_packs; i++){
            for (int j = i+1; j < jack_packs; j++){
                if (jack[i] > jack[j]){
                    int temp = jack[i];
                    jack[i] = jack[j];
                    jack[j] = temp;
                }
            }
        }

        for (int i = 0; i < john_packs; i++){
            printf("%d ", john[i]);
        }

        int counter = 0, n = 0;
        // swapping john's first vote with jack's last; then john's second with jack's last, until john has more votes
        while (jack_sum >= john_sum && n < john_packs && n < jack_packs){
            int temp = john[n];
            john[n] = jack[jack_packs-1-n];
            jack[jack_packs-1-n] = temp;
            john_sum = john_sum + john[n] - jack[jack_packs-1-n];
            jack_sum = jack_sum + jack[jack_packs-1-n] - john[n];
            n++;
            counter++;
        }

        if (john_sum > jack_sum){
            printf("%d\n", counter);
        }
        else{
            printf("-1");
        }
        t--;
    }

    return 0;
}