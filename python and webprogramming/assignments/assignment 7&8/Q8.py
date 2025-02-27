# 8. Decode the message: 
# A message containing the letters from A-Z can be encoded into the numbers using the mapping 
# A-> 1, B-> 2, C-> 3, ..., Z-> 26. To decode an encoded message, you need to group the digits 
# and do the reverse mapping. You are required to display all the possible decoded messages. 
# For example: "11106" can be decoded into: 
# a. "AAJF" with the grouping (1 1 10 6) 
# b. "KJF" with the grouping (11 10 6)

Code = input("Enter the coded Message: ")
def decode_message(message, index=0, decoded=''):
    if index == len(message):
        print(decoded)
        return
    if index < len(message) and 1 <= int(message[index]) <= 9:
        decode_message(message, index + 1, decoded + chr(64 + int(message[index])))
    if index + 1 < len(message) and 10 <= int(message[index:index+2]) <= 26:
        decode_message(message, index + 2, decoded + chr(64 + int(message[index:index+2])))

decode_message(Code)