import base64


def base64_encode(int_list):
    """
    Convert a list of integers (0 to 255) to a Base64-encoded string.

    Args:
        int_list (list[int]): A list of integers between 0 and 255.

    Returns:
        str: A Base64-encoded string.
    """
    # Validate that all integers are between 0 and 255
    if not all(0 <= num <= 255 for num in int_list):
        raise ValueError("All integers in the list must be between 0 and 255.")
    
    # Convert the list of integers to bytes
    byte_data = bytes(int_list)
    # Encode the bytes to a Base64 string
    res = base64.b64encode(byte_data).decode('utf-8')
    return res


def base64_decode(base64_str):
    """
    Convert a Base64-encoded string to a list of integers (0 to 255).

    Args:
        base64_str (str): A Base64-encoded string.

    Returns:
        list[int]: A list of integers between 0 and 255.
    """
    # Decode the Base64 string to bytes
    my_bytes = base64_str.encode('utf-8')
    byte_data = base64.b64decode(my_bytes)
    # Convert bytes to a list of integers
    return list(byte_data)


def weakCipher1(message: str, k1: int, k2: int):
    s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,?!"
    n = len(s)
    res = ""
    for c in message:
        pos = s.find(c)
        if pos >= 0:
            c = s[(pos*k1+k2)%n]
            res += c
        else:
            raise ValueError("Unrecognized character: '%s'" % str(c))
    return res


def weakCipher2(message: str, key):
    # key should be a list of integers
    if len(key) != 6:
        raise ValueError("Expected a list of length 6 (of integers)")
    s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,?!"
    n = len(s)
    if (len(message) % 2 != 0):
        message += "."
    res = ""
    for i in range(0, len(message), 2):
        pos1 = s.find(message[i])
        pos2 = s.find(message[i+1])
        res += s[(pos1*key[0] + pos2*key[1] + key[2])%n]
        res += s[(pos1*key[3] + pos2*key[4] + key[5])%n]
    return res


 

# à toutes fins utiles, on indique qu'en Python l'inverse de x modulo N peut être
# obtenu à l'aide de la fonction pow(x, -1, N)

#=================== QUESTION 1

q1_challenge = ",?jtajY.tcrL0tvtl?20.Y"


#================= QUESTION 2

q2_challenge = "j5YTlG!wLkVu2QU 5,Iz.QlGApwkUGEYlL0,TzYiC3m0lYhtE,gzGu7TCc"

#================ QUESTION 3

q3_challenge = "0liLBTrm2?B.rsBzr7u 2K2ZB0iLBE.gBz.8iL2Y8YD0B.rsB,TIQ7oFmMl1AJBrrUoQDz"

#================ QUESTION 4

q4_challenge = "9GVHL2Jb+QLfityW1Umw5w=="

#================ QUESTION 5

q5_challenge = "rv6mp36Doa6Zyt2WjMDd6w=="


