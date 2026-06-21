#include <iostream>
#include <cstring>

void usage(char *programName) {
    printf("Usage: %s number1 operation number2\n", programName);
    printf("Available operations:\n");
    printf("\tadd\n");
    printf("\tsub\n");
    printf("\tmul\n");
    printf("\tdiv\n");
    printf("\n");
}

int main(int argc, char* argv[]) {

    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[3]);

        if (!strcmp("add", argv[2])) {
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("sub", argv[2])) {
            result = number1 - number2;
            printf("%d - %d = %d\n",number1, number2, result);
            return 0;
        }
        if (!strcmp("mul", argv[2])) {
            result = number1 * number2;
            printf("%d * %d = %d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("div", argv[2])) {
            if (number2 !=0){
               float result1 = (float) number1 / number2;
                printf("%d / %d = %.2f\n", number1, number2, result1);
                return 0;
            }else {
                printf("nie dzielimy przez %d\n",number2);
                return 1;
            }
        }

    }

    usage(argv[0]);

    return 0;
}












//
// int main(int argc, char const *argv[]) {
//     printf("Podano %d argument\n",argc);
//     for (int i=0; i<argc; i++) {
//         printf("Argument %d\t - \t%s\n",i, argv[i]);
//     }
//     return 0;
// // }
//
// void usage(const char* progname_name) {
//     printf("sposob uzycia %s <komunikat> <#powturzen>\n",progname_name);
//     exit(1);
// }
// int main (int argc, char const*argv[]) {
//     if (argc < 3)
//         usage(argv[0]);
//     int count = atoi(argv[2]);
//     printf("Powturzen %d razy..\n",count);
//     for (int i=0; i<count; i++ ) {
//         printf("%3d - %s\n",i, argv[1]);
//     }
//     return 0;
// }




