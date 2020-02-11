# Stephen Chew 
# 2020 Codecademy Code Challenge (Backend Software Engineer)
# Last edited: 2-11-2020

import random
from ufo import x

# generates the number of possible answers in the dictionary given the length of the
# codeword, incorrect guesses, and character alignment 
def num_possible(all_lines, hiddenWord, incorrect_guesses):
    count = 0
    #str_possible = []
    for line in all_lines:
        valid = True
        all_lines[all_lines.index(line)] = line.strip().upper()
        line = line.strip().upper()
        if len(hiddenWord) == len(line):
            for i in range(len(incorrect_guesses)):
                if incorrect_guesses[i] in line:
                    valid = False
                    break
            if valid == True:
                for index in range(len(line)):
                    if hiddenWord[index] == "_":
                        continue
                    if hiddenWord[index] != line[index]:
                        valid = False
                        break
            if valid == True:
                #str_possible.append(line)
                count += 1
            else:
                all_lines.remove(line)
    print("The number of possible answers in the dictionary is: " + str(count))
    #print(str_possible)

def main():
    # open file and store dictionary in all_lines
    file_nouns = open("nouns.txt", "r")
    all_lines = file_nouns.readlines()
    file_nouns.close()

    # generate codeword
    num_words = len(all_lines)
    codeword = all_lines[random.randrange(num_words)].strip().upper()

    # create blank spots for each letter in the codeword
    hiddenWord = ""
    for i in codeword:
        hiddenWord += "_"

    print("UFO: The Game")
    print("Instructions: save us from alien abduction by guessing letters in the codeword.")

    # starts the game, giving the user 6 attempts to guess the correct codeword
    attempt = 0
    incorrect_guesses = []
    while attempt < 6:
        print(x[attempt])
        print("Incorrect Guesses:")
        if attempt == 0:
            print("None")
        else:
            print(incorrect_guesses)
        print("Codeword: " + hiddenWord + "\n")

        # calculates the number of possible answers from the dictionary
        num_possible(all_lines, hiddenWord, incorrect_guesses)

        # user inputs a single letter guess that has not been guessed before
        guess = raw_input("Please enter your guess: ").upper()
        while guess in incorrect_guesses or len(guess) > 1 or guess in hiddenWord:
            if guess in incorrect_guesses or guess in hiddenWord:
                print("You can only guess that letter once, please try again.")
                guess = raw_input("Please enter your guess: ").upper()
            if len(guess) > 1:
                print("I cannot understand your input. Please guess a single letter")
                guess = raw_input("Please enter your guess: ").upper()

        # evaluates whether the user's guess was correct or incorrect
        if guess in codeword:
            for i in range(len(hiddenWord)):
                if guess == codeword[i]:
                    hiddenWord = hiddenWord[0:i] + guess + hiddenWord[i+1: len(hiddenWord)]
            if not "_" in hiddenWord:
                break
            print("Correct! You're closer to cracking the codeword.")
        else:
            print("Incorrect! The tractor beam pulls the person in further.")
            attempt += 1
            incorrect_guesses.append(guess)

    # evaluates whether the player won or lost
    if "_" in hiddenWord:
        print(x[6])
        print("Oh no, the person was abducted! The codeword was: " + codeword)
    else:
        print("Correct! You saved the person and earned a metal!")
        print("The Codeword is: " + codeword + "\n")

play_again = "Y"
while play_again[0] == "Y":
    main()
    play_again = raw_input("Would you like to play again (Y/N)? ").upper()
print("Goodbye!")