#pragma once
#include <math.h>

//  Random Message Generator


std::string successMessages(int number) {
    switch (number) {
    case 1:
        return "\tSweet! That went well. ";
        break;

    case 2:
        return "\tI've got that very clear! ";
        break;

    case 3:
        return "\tThis should be good to go. ";
        break;

    case 4:
        return "\tI see, I see. ";
        break;

    case 5:
        return "\tThat was fast and neat! Moving forward. ";
        break;

    default:
        return "\tUnknown parameter passed";
        break;
    }

}

std::string wrongMessages(int number) {
    switch (number) {
    case 1:
        return "\n\n\tThat doesn't seem right. Please try again...\n\n";
        break;

    case 2:
        return "\n\n\tIt seems you've failed to follow the conditions. Retrying...\n\n";
        break;

    case 3:
        return "\n\n\tThere was a mistake in your input. Going back up...\n\n";
        break;

    case 4:
        return "\n\n\tLet's try to avoid that mistake next time. Re-enter that data needed...\n\n";
        break;

    case 5:
        return "\n\n\tLet me guess, you have a typographical error. Don't worry, we'll return to the previous question...\n\n";
        break;

    default:
        return "\n\nUnknown parameter passed\n\n";
        break;
    }
}

std::string taskDoneMessages(int number) {
    switch (number) {
    case 1:
        return "\tSweet! That went well. ";
        break;

    case 2:
        return "\tTask done smoothly! ";
        break;

    case 3:
        return "\tFlawlessly done. ";
        break;

    case 4:
        return "\tFlawless. Clean. Neat. ";
        break;

    case 5:
        return "\tThat was fast and neat! Moving forward. ";
        break;

    default:
        return "\tUnknown parameter passed";
        break;
    }

}

std::string systemBlocked(int number) {
    // TODO: Make atleast 5 of system blocked messages
    switch (number) {
    case 1:
        return "System blocked 1";
        break;
    case 2:
        return "System blocked 1";
        break;
    case 3:
        return "System blocked 1";
        break;
    case 4:
        return "System blocked 1";
        break;
    case 5:
        return "System blocked 1";
        break;
    default:
        return "Def";
        break;
    }
    
}

//  Randomize Messages
std::string generateRandomMessage(int type) {
    //Initialize Variables
    std::string messageString;

    //RNG
    srand((unsigned)time(NULL));
    int rng = 1 + rand() % 5;
    //Process data received
    //  Types are: 1 - Wrong Input, 2 - Success, 3 - Task Done, 4 - System Blocked
    switch (type) {
    case 1:
        messageString = wrongMessages(rng);
        break;

    case 2:
        messageString = successMessages(rng);
        break;
    case 3:
        messageString = taskDoneMessages(rng);
        break;
    case 4:
        messageString = systemBlocked(rng);
        break;
    }

    //Return
    return messageString;
}