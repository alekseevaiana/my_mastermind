#include "my_lib.h"

#define STDIN_FILE_DESCRIPTOR 0
#define EXPECTED_ANSWER_LENGTH 4
#define EXPECTED_INPUT_LENGTH (EXPECTED_ANSWER_LENGTH + 1)

// Function that compares secret code and answer and return number of well placed and missplaced
// Function expects inputs are valid
t_guess_result check_answer(char* secret, char* answer) 
{
    t_guess_result result;
    result.missplaced_amount = 0;
    result.well_placed_amount = 0;
    int place;
    int index = 0;
    while (answer[index] != '\0')
    {
        place = find_index(secret, answer[index]);
        if (place == -1)
        {
            index++;
            continue;
        }
        else if (answer[index] == secret[index]) 
        {
            result.well_placed_amount += 1;
        } 
        else if (answer[place] != secret[place]) 
        {
            result.missplaced_amount += 1;
        }
        index++;
    }
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
    if (result < EXPECTED_INPUT_LENGTH)
    {
        return NULL;
    }
    // Check user entered exact amount
    if (input[EXPECTED_INPUT_LENGTH - 1] != '\n')
    {
        return NULL;
    } 

    input[EXPECTED_INPUT_LENGTH - 1] = '\0';

    return input;
}

bool is_code_valid(char *code) {
    int index;
    // checks length of code, must be 4 digits
    if (strlen(code) != EXPECTED_ANSWER_LENGTH)
    {
        return false;
    }
    index = 0;
    while(index < EXPECTED_ANSWER_LENGTH)
    {
        if(code[index] > '7' || code[index] < '0')
        {
            printf("Each digit must be between 0 and 7 included\n");
            return false;
        }
        index++;
    }
    return true;
}

void get_random(t_opt* options)
{
    int random;
    options->c_val = malloc(sizeof(char) * EXPECTED_INPUT_LENGTH);
    int index = 0;
    srand(time(NULL));
    while(index < EXPECTED_ANSWER_LENGTH)
    {
        random = rand() % 8;
        options->c_val[index] = random + '0';
        index++;
    }
    options->c_val[index] = '\0';
}


int main(int ac, char** av)
{
    t_opt* options = get_opt(ac, av);
    if(options->c == 1 && strlen(options->c_val) < 2)
    {
        printf("Wrong option value after -c\n");
        return 1;
    }
    
    if(strlen(options->c_val) == 0)
    {
        get_random(options);
    }
    
    if (!is_code_valid(options->c_val) )
    {
        printf("Secret is invalid\n");
        free(options);
        return 1;
    }

    printf("====> Will you find the secret code?\n");
    printf("---\n");

    int attempt = 0;
    char *answer;
    t_guess_result guess;

    while (attempt < options->t_val)
    {
        printf("Round %d\n", attempt);
        answer = read_answer();

        if (answer != NULL && is_code_valid(answer))
        {
            guess = check_answer(options->c_val, answer);
            
            // WHEN WON
            if (guess.well_placed_amount == EXPECTED_ANSWER_LENGTH)
            {
                printf("Congratz! You did it!\n");
                free(answer);
                free(options->c_val);
                free(options);
                return 0;
            }

            printf("Well placed pieces: %d\n", guess.well_placed_amount);
            printf("Misplaced pieces: %d\n", guess.missplaced_amount);
        }
        else
        {
            printf("Wrong input! Try again\n");
        }
        attempt++;
        free(answer);
        printf("---\n");
    }
    printf("Exeded amount of attempts\n");
    printf("The right answer was %s\n", options->c_val);
    free(options->c_val);
    free(options);
    return 1;
}