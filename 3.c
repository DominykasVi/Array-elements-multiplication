#include <stdio.h>
//This program alo makes sure that repetitive values are not printed
int add_number() {
    int number;
    int return_code;
    while ((return_code = scanf("%9d", &number) == 0) || (getchar() != '\n')) {
        scanf("%*[^\n]");
        printf("Enter a  valid number: ");
    }
    return number;

}

int main() {
    printf("Enter number s: ");
    int s = add_number();
    printf("Enter number n (number of how many elements an array will have): ");
    int n = add_number();
    int array[n];
    for(int i = 0; i < n; ++i){
        while (1){
            printf("Enter positive integer, which will be stored in array[%d] position", i);
            array[i] = add_number();
            if(array[i] > 0){
                break;
            }
        }
    }

    printf("s = %d\n", s);
    int saved_sums[n];
    int counter = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j <= n; ++j){
            if((array[i]*array[j]) == s){//part below could be replaced with just printf to also print repetitive values
                if (counter == 0) {
                    printf("%d %d\n", array[i], array[j]);
                    saved_sums[counter] = (array[i]+array[j]);
                    ++counter;
                }
                for(int k = 0; k < counter; ++k){
                    if((array[i]+array[j]) == saved_sums[k]){
                        continue;
                    } else {
                        printf("%d %d\n", array[i], array[j]);
                        saved_sums[counter] = (array[i]+array[j]);
                        ++counter;
                    }
                }
            }
        }
    }
}