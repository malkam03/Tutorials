# ---------------------------------------------------------------
# Integratec programming workshop 2017
# @author Malcolm Davis Steele
# @since 5/2/2017
# ---------------------------------------------------------------
#First learn how to print something
print("Hello World! Nice to meet you!")
#Then make it a function function that only print message if is a string
def showMSJ(message):
    if isinstance(message, str):
        print(message)
    else:
        print ("The message is not valid.")

def repeat():
    data = input("Enter your input: ")
    lowercaseData = data.lower()
    print("What you say was that "+lowercaseData)
