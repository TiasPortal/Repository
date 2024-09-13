#Global lists that store the three types of codes
valid = [ ]
invalid = [ ]
restricted = [ ]

#The main function opens and reads the Codes.txt file and passes each code to the test() method to get sorted
#into the appropriate list. Then the main function prints out all the contents in each list.
def main():

 
    # Open the codes file.
    infile = open('Codes.txt', 'r')

    # Read the file's contents and passes the codes to the test method to get sorted
    for i in infile.readlines():
        i = i.strip()
        test(i)
    infile.close();

    #Prints valid codes
    print( 'Valid Code(s) are: ' )
    for code in valid:
        print(code)
    print( " ")

    #Prints invalid codes
    print('Invalid Code(s) are: ' )
    for code in invalid:
        print(code)
    print( " ")

    #Prints restricted codes
    print('Invalid Restricted Code(s) are : ')
    for code in restricted:
        print(code)
    print( " ")
    

#This function tests each code and sorts them into the appropriate list (valid,invalid or restricted)
def test(code):

    #booleans for restricted codes and codes that conform to the rules (listed in class description)
    restrict= False
    conforms = False

    #If the code length is > 10,the 10th element in the code is an upper case letter and if the elements in the 4-7th position are digits
    #Then the code conforms
    #If the 10th element in the code is "R" and the country code is >2000 then the code is Restricted
    if(len(code)>10 and code[9].isupper() and code[3:7].isdigit()):
        conforms = True
        if(code[9] =="R"and  int(code[3:7]) > 2000):
             restrict= True
             restricted.append(code)

    #If the code conforms and is not restricted then it is added to the list of valid codes
    if(conforms and not restrict):
        valid.append(code)

    #If the code does not conform or restrict then it is added to the list of invalid codes
    if( not conforms and not restrict):
        invalid.append(code)
        

main()
