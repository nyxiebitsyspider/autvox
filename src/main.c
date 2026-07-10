/*

>>===========================================================================<<
||                                                                           ||
||    ,---.            ,--. ,--.   ,--.                  ,-----.,--.   ,--.  ||
||   /  O  \ ,--.,--.,-'  '-.\  `.'  /,---.,--.  ,--.   '  .--./|  |   |  |  ||
||  |  .-.  ||  ||  |'-.  .-' \     /| .-. |\  `'  /    |  |    |  |   |  |  ||
||  |  | |  |'  ''  '  |  |    \   / ' '-' '/  /.  \    '  '--'\|  '--.|  |  ||
||  `--' `--' `----'   `--'     `-'   `---''--'  '--'    `-----'`-----'`--'  ||
||                                                                           ||
>>===========================================================================<<

AutVox CLI v0.0.1 - Open Alpha
by nyxiebitsyspider
licensed under GPL3.0-or-later

*/

// INCLUDE LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <espeak-ng/speak_lib.h>


// INITIALIZE VARIABLES
char command = '\0'; // set command to null
char exitConfirm = '\0'; // set exit confirmation to null
char speakAgain = '\0'; // set speak again confirmation to null
char optionSelect = '\0'; // set option selection to null
char *speech;
int iteration = 1; // initialize iteration counter for do while loop
int speechUses = 0; // initialize counter for speech while loop
int maxSpeechUses = 128; // initialize iteration limit for speech while loop

// INITIALIZE ESPEAK LIBRARY VARIABLES
espeak_AUDIO_OUTPUT output = AUDIO_OUTPUT_SYNCH_PLAYBACK;
char *path = NULL;
void* user_data;
unsigned int *identifier;


// GET SINGLE-CHARACTER INPUT
static char read_first_nonws_char(void) {
    char buf[64]; // create input string
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return '\0'; // return null if no input
    }
    for (size_t i = 0; buf[i] != '\0'; ++i) { // loop through input until null operator
        if (!isspace((unsigned char)buf[i])) {
            return buf[i]; // return first non-whitespace character if input
        }
    }
    return '\0'; // return null operator
}

// TEXT-TO-SPEECH FUNCTION
static void speakText() {
    while (speechUses < maxSpeechUses) {
        printf("Please enter the text you'd like to say (up to 256 characters):\n"); // prompt user for input
        speech = (char *) calloc(128, sizeof(char)); // allocate memory for speech input
        if (speech == NULL) { // check if memory allocated
            printf("ERROR: failed to allocate memory for input\n");
            exit(1);
        }
        fgets(speech, 128, stdin); // get speech input
        if (speech[0] == '\0') { // check if input intered
            printf("You have not entered any text to speak. Please type what you'd like to say and press ENTER.\n");
        } else {
            speech[strlen(speech) - 1] = '\0'; // remove trailing newline
            // set espeak variables
            int options = 0;
            int buflength = 512;
            char voicename[] = "en-us+anikaRobot";
            unsigned int position = 0, position_type = 0, end_position = 0, flags = espeakCHARS_AUTO;
            // perform text-to-speech operation
            espeak_Initialize(output, buflength, path, options);
            espeak_SetVoiceByName(voicename);
            espeak_SetParameter(espeakRATE, 105, 0);
            printf("Saying: \'%s\'...\n", speech);
            espeak_Synth(speech, buflength, position, position_type, end_position, flags, identifier, user_data);
            printf("Done!\n");
            espeak_Terminate();
        }
        free(speech); // free memory allocated for speech input
        speechUses++; // increment speech use counter
        printf("Would you like to say something again?\n");
        printf("(Y for yes, any other character to cancel)\n");
        speakAgain = read_first_nonws_char(); // check if user wants to speak again
        if (speakAgain != 'y' && speakAgain != 'Y') { // exit loop if user doesn't confirm to speak again
            printf("Exiting speech interface. Spoke %d times.\n", speechUses);
            break;
        }
    }
}

// MAIN FUNCTION
int main(int argc, char *argv[]) {

    // BEGIN PROGRAM
    printf("Welcome to AutVox, an Alternative and Augmented Communication (AAC) software made with love by an autistic developer!\n"); // print welcome message

    do { // run program until user exits or until it hits its sixty-fourth iteration

        printf("Please enter a command (enter H to list commands): \n"); // prompt user for command
        command = read_first_nonws_char(); // get command

        //  HANDLE USER COMMANDS

        if (command == 'h' || command == 'H') {
        //  HANDLE HELP COMMAND
            printf("Available commands:\n");
            printf("H - Help (list commands)\n");
            printf("S - Speak (input text to be spoken)\n");
            // printf("O - Options (COMING SOON)\n");
            printf("Q - Quit (exit the application)\n");
            iteration++; // increment iteration before continuing the loop
            continue;

        } else if (command == 'q' || command == 'Q') {
        //  HANDLE QUIT COMMAND
            printf("Exit AutVox?\n");
            printf("(Y for yes, any other character to cancel)\n");
            exitConfirm = read_first_nonws_char(); // get exit confirmation
            if (exitConfirm == 'y' || exitConfirm == 'Y') {
                iteration++; // increment iteration before exiting the loop
                break;
            } else {
                iteration++; // increment iteration before continuing the loop
                continue;
            }

        } else if (command == 's' || command == 'S') {
        //  HANDLE SPEAK COMMAND
            
            printf("Welcome to the speech interface!\n");

            speakText(); // call text-to-speech function

            iteration++; // increment iteration before continuing the loop
            continue;

        } else {
        //  HANDLE UNKNOWN COMAMND
            printf("You have entered an invalid or empty command. Please enter a valid command, or enter H to list commands.\n");
            iteration++; // increment iteration before continuing the loop
            continue;
        }
        
    } while (iteration <= 64); // Limit iterations to prevent infinite loop

    printf("Goodbye!\n"); // exit message

    return 0;
}
