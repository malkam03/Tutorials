# ---------------------------------------------------------------
# Integratec programming workshop 2017
# @author Malcolm Davis Steele
# @since 5/2/2017
# ---------------------------------------------------------------
import random
#First learn how to print something
print("Hello World! Nice to meet you!")

#Then make it a function function that only print message if is a string
def showMSJ(message):
    if isinstance(message, str):
        print(message)
    else:
        print ("The message is not valid.")

#Shows what is the type of the data
def showType(data):
    if isinstance(data, str):
        print ("The entry is a string.")
    elif isinstance(data, int):
        print ("The entry is a integer number.")
    elif isinstance(data, float):
        print ("The entry is a floating point number.")
    else:
        print ("The entry is a for the moment unknonw data type.")

#Checks if the input is a letter
def isLetter(data):
    if isinstance(data, str):
        if len(data) == 1:
            return True
        else:
            print ("The data is not a letter.")
            return False
    else:
        print ("The data is invalid.")
        return False

#Choose a random word from the list
def randomWord():
    words = ["crater", "odd", "collider", "cyclical", "avocado", "clover", "sorrow",
         "beach", "narcotic", "breath", "begin", "ageless", "bestial", "super",
         "foot", "cathedral", "flatten", "forgery", "downtown", "kitten",
         "perfection", "hour", "behind", "defect","sweet", "cat", "car"]
    random_index = random.randrange(0, len(words))
    return words[random_index]

#Method that replace the letters of a word with x
def fillWithX(word):
    temp = ""
    if (isinstance(word, str)):
        for i in range(0, len(word)):
            temp += "x"
        return list(temp)
    else:
        print("Invalid entry")

#Method to check if letter is on the word.
def isOnWord(letter, word):
    for let in word:
        if let == letter:
            return True
    return False

#Method to show the letter on the guess word.
def showLetter(letter, word, guess):
    tmp = list(guess)
    for i in range(len(word)):
        if(word[i]==letter):
            tmp[i]=letter
    return "".join(tmp)

#Main game method
def play():
    lives = 5
    word = randomWord()
    word = word.lower()
    guess = fillWithX(word)
    while (lives >= 0):
        print ("Lives left: " + str(lives))
        print ("Guess the word: " +"".join(guess))
        letter = input("Enter the guess letter: ")
        letter = letter.lower()
        if( isLetter(letter)):
            if(isOnWord(letter, word)):
                guess = showLetter(letter, word, guess)
                if ("".join(guess) == word ):
                    print("Congratulations you just won the game!")
                    return
            else:
                lives -=1
                print ("Wrong!")
    print ( "Game over! You looser!")
            
        
play()
