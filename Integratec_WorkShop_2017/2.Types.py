# ---------------------------------------------------------------
# Integratec programming workshop 2017
# @author Malcolm Davis Steele
# @since 5/2/2017
# ---------------------------------------------------------------
import random

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
        return temp
    else:
        print("Invalid entry")
