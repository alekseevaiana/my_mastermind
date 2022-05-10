#include "my_lib.h"

#define STDIN_FILE_DESCRIPTOR 0
#define EXPECTED_ANSWER_LENGTH 4
#define EXPECTED_INPUT_LENGTH (EXPECTED_ANSWER_LENGTH + 1)

// Function that compares secret and answer and return number of well placed and missplaced
// Function expects inputs are valid
t_guess_result check_answer(char* secret, char* answer) {
    t_guess_result result;
    printf("secret code is %s\n", secret);
    printf("input answer %s\n", answer);
    result.missplaced_amount = 1;
    result.well_placed_amount = 3;
    // TODO: all

    return result;
}

char* read_answer()
{
    char* input;
    int result;
    
    input = malloc(sizeof(char) * EXPECTED_INPUT_LENGTH);
   
    write(0, "> ", 2);
    result = read(STDIN_FILE_DESCRIPTOR, input, EXPECTED_INPUT_LENGTH);
    // Check user entered at lest minimal amount and no error happened
    if (result < EXPECTED_INPUT_LENGTH) {
        return NULL;
    }
    // Check user entered exact amount
    if (input[EXPECTED_INPUT_LENGTH - 1] != '\n') {
        return NULL;
    } 

    input[EXPECTED_INPUT_LENGTH - 1] = '\0';

    return input;
}

bool is_code_valid(char *code) {
    // checks length of code, must be 4 digits
    if (strlen(code) != EXPECTED_ANSWER_LENGTH) {
        return false;
    }
    // TODO: add validation for each char
    int index = 0;
    while(index < EXPECTED_ANSWER_LENGTH) {
        if(code[index] > '7' || code[index] < '0') {
            printf("Each digit must be between 0 and 7 included\n");
            return false;
        }
        index++;
    }
    return true;
}


int main(int ac, char** av) {
    int random;
    t_opt* options = get_opt(ac, av);
    
    if(strlen(options->c_val) == 0) {
        // generate secret code if opt->c_val (secret code) is ""
        options->c_val = malloc(sizeof(char) * EXPECTED_INPUT_LENGTH);
        int index = 0;
        srand(time(NULL));
        while(index < EXPECTED_ANSWER_LENGTH) {
            random = rand() % 8;
            printf("random number is original %d, and char is %c\n", random, random + '0');
            // TODO: integer to str
            options->c_val[index] = random + '0';
            printf("option letter is %c\n", options->c_val[index]);
            index++;
        }
        options->c_val[index] = '\0';
        printf("NEW SECRET RANDOM IS %s\n", options->c_val);
    }

    if (!is_code_valid(options->c_val) ) {
        printf("Secret is invalid\n");
        return 1;
    }

    printf("====> Will you find the secret code?\n");
    printf("---\n");

    int attempt = 0;
    char *answer;
    t_guess_result guess;

    while (attempt < options->t_val) {
        printf("Round %d\n", attempt);
        answer = read_answer();
        if (answer != NULL && is_code_valid(answer)) {
            guess = check_answer(options->c_val, answer);
            
            // WHEN WON
            if (guess.well_placed_amount == EXPECTED_ANSWER_LENGTH) {
                printf("Congratz! You did it!\n");
                return 0;
            }

            printf("Well placed pieces: %d\n", guess.well_placed_amount);
            printf("Misplaced pieces: %d\n", guess.missplaced_amount);
        } else {
            printf("Wrong input!\n");
        }
        attempt++;
        free(answer);
        printf("---\n");
    }
    printf("Exeded amount of attempts\n");
    free(options);
    return 1;
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