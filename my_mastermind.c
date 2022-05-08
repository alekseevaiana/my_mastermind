#include "my_lib.h"

#define STDIN_FILE_DESCRIPTOR 0
#define EXPECTED_ANSWER_LENGTH 4
#define EXPECTED_INPUT_LENGTH (EXPECTED_ANSWER_LENGTH + 1)

typedef struct t_guess_result
{
    int well_placed_amount;
    int missplaced_amount;
} t_guess_result;

t_guess_result check_answer(char* secret, char* answer) {
    t_guess_result result;

    return result;
}

char* read_answer()
{
    char buff;
    char* input;
    
    input = malloc(sizeof(char) * EXPECTED_INPUT_LENGTH);
   
    int read_size = 0;

    write(0, "> ", 2);
    int result = read(STDIN_FILE_DESCRIPTOR, input, EXPECTED_INPUT_LENGTH);
    // Check user entered at lest minimal amount and no error happened
    if (result < EXPECTED_INPUT_LENGTH) {
        return NULL;
    }
    // Check user entered exact amount
    if (input[EXPECTED_INPUT_LENGTH - 1] != '\n') {
        return NULL;
    } 

    return input;
}

bool is_answer_valid(char *answer) {
    // TODO: add validation
    return true;
}



int main(int ac, char** av) {
    t_opt* options = get_opt(ac, av);
    if (strlen(options->c_val) != EXPECTED_ANSWER_LENGTH) {
        printf("Secret length should be %d", EXPECTED_ANSWER_LENGTH);
        return 1;
    }
    // TODO: CHECK SECRET CHARS

    printf("====> Will you find the secret code?\n");
    printf("---\n");

    int attempt = 0;
    char *answer;
    t_guess_result guess;

    while (attempt < options->t_val) {
        answer = read_answer();
        if (answer != NULL && is_answer_valid(answer)) {
            guess = check_answer(options->c_val, answer);
            
            // WHEN WON
            if (guess.well_placed_amount == EXPECTED_ANSWER_LENGTH) {
                printf("Congratz! You did it!");
                return 0;
            }



            // DO
        } else {
            printf("Wrong input!");
        }
        free(answer);
    }

    // TODO: add random generation

    // run loop on every attempt (-t). 10 attempts by default
    // read input from user
    //          -> must be 4 digits every one is from 0 - 7
    // store input in a struct or an object
    // compare input and secret code
    return 0;
}


int main2(int ac, char** av) {
    t_opt* options = get_opt(ac, av);
    int random;
    int secret_code = strlen(options->c_val);
    printf("====> Will you find the secret code?\n");
    printf("len of secret code %d\n", secret_code);
    printf("---\n");

    if(strlen(options->c_val) == 0) {
        // generate secret code if opt->c_val (secret code) is ""
        int index = 0;
        srand(time(NULL));
        while(index <= 4) {
            random = rand() % 8;
            printf("random number is %d\n", random);
            index++;
        }
        srand(time(NULL));
        random = rand() % 8;
        printf("random number is %d\n", random);

    }
    // run loop on every attempt (-t). 10 attempts by default
    // read input from user
    //          -> must be 4 digits every one is from 0 - 7
    // store input in a struct or an object
    // compare input and secret code
    free(options);
    return 0;
}