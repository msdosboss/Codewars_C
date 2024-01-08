def shortener(message):
    messagelength = len(message)
    if messagelength <= 160:   
        return message
    newMessage = message
    
    for x in range(messagelength - 160):
        i = 1
        while newMessage[messagelength - i - x] != " " and messagelength - i - x  != 0:
            i += 1
        if messagelength - i - x == 0:
            return newMessage
        newMessageList = list(newMessage)
        
        for y in range(messagelength - i - x, messagelength - x - 1):
            if y >= messagelength - x:
                break
            newMessageList[y] = newMessage[y + 1]
            if y == messagelength - i - x:
                newMessageList[y] = newMessageList[y].upper()
        newMessageList[messagelength - 1 - x] = ""
        newMessage = ''.join(newMessageList)
        print(newMessage)
        

    return newMessage



print(shortener('SMS messages are limited to 160 characters. It tends to be irritating, '
               'especially when freshly written message is 164 characters long. '
               'SMS messages are limited to 160 characters. It tends to be irritating, '
               'especially when freshly written message is 164 characters long.'))



#the cat jumps
#the catjuumps
#thecatjumps