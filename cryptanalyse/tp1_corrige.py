from hashlib import sha256, md5, sha1
from random import randrange


def md_hash_1(message_blocks, initial_value=0x12345678):
    """
    Args:
        message_blocks: list of message blocks as 64-bit integers
        initial_value (int): initial value as 32-bit integer

    Returns:
        int: hash of the message as a 32-bit integer.
    """
    chaining_value = initial_value

    for block in message_blocks:
        data = chaining_value.to_bytes(4, 'little') + block.to_bytes(8, 'little')
        chaining_value = int(sha256(data).hexdigest()[:8], 16)  # Use first 32 bits

    return chaining_value


def md_hash_2(message_blocks, initial_value=0x87654321):
    chaining_value = initial_value

    for block in message_blocks:
        data = chaining_value.to_bytes(4, 'little') + block.to_bytes(8, 'little')
        chaining_value = int(md5(data).hexdigest()[:8], 16)  # Use first 32 bits

    return chaining_value


#==========================
# Question 1: constructing a multicollision


def question1():
    for i in range(32):
        # each time, restart from the current message blocks, and try to find
        # two colliding blocks
        print(i)
        outputs = {}
        
        while True:
            random_block = randrange(1 << 64)
            new_output = md_hash_1( [t[0] for t in colliding_message_blocks] + [random_block] )
            if new_output in outputs:
                # new pair of message blocks
                colliding_message_blocks.append( (random_block, outputs[new_output]) )
                print("New message block")
                break
            else:
                outputs[new_output] = random_block
    return colliding_message_blocks

# colliding_message_blocks = question1()

colliding_message_blocks = [(12759331578210991743, 5987593579390451388), (3015591443382943624, 11854149634626726101), (8643669165177023452, 8843124066526341559), (1736392043948218029, 6557604007791056188), (4300802707040716402, 14769327018616280056), (1688734023608115223, 656765583273239620), (14964947478176925941, 6224457916613861214), (12198998733109871575, 15632203265036886080), (18171242184335930062, 5030609534093320690), (15481149502649288824, 3233606483950372726), (3205702897438700958, 13201218092546703864), (15071132974322971569, 7406404172495096732), (4662491048952011470, 8273612225397461259), (2749824134247492661, 17046423203006295197), (615604302231111894, 2112083023410410574), (14164164942300290074, 14007518558888759962), (5140206014153082493, 15242637763851968068), (2551671991840636591, 11598568714751131882), (16755694373183791353, 4793014084036843182), (9624151543147799576, 18070835995608964717), (6376845487170642069, 16399327693584545264), (1492396537494087537, 7595146127068636630), (8192758029204928646, 3236776506579535293), (11839287149427534264, 6567068234893130186), (14833218912197704517, 10899007237830763975), (947928927135374404, 18383591399886959846), (14828710739192875527, 16575366781631331933), (15514394214068356790, 6376435695758723302), (10075638504754287989, 13133429964416647168), (7867889642403550220, 10509658135141835534), (13211188359214840957, 11958832018277998231), (12003984621072487448, 624670172156285555)]

print( colliding_message_blocks )

# check that all choices lead to the same value

#for _ in range(20):
#    message_blocks = [ t[randrange(2)] for t in colliding_message_blocks ]
#    print( md_hash_1(message_blocks) )

#===========================
# Question 2: find a collision for the concatenation

def question2():
    msg1 = None
    msg2 = None

    outputs = {}
    while True:
        random_message_blocks = [ t[randrange(2)] for t in colliding_message_blocks ]
        new_output = md_hash_2(random_message_blocks)
        if new_output in outputs:
            # new pair of message blocks
            msg1 = random_message_blocks
            msg2 = outputs[new_output]
            break
        else:
            outputs[new_output] = random_message_blocks

    print(md_hash_1(msg1), md_hash_2(msg1) )
    print(md_hash_1(msg2), md_hash_2(msg2) )


#===================================
# Preimage attack

def md_hash_3(message_blocks, initial_value=0x12345678):
    chaining_value = initial_value
    for block in message_blocks:
        data = chaining_value.to_bytes(4, 'little') + block.to_bytes(8, 'little')
        chaining_value = int(sha256(data).hexdigest()[:5], 16)
    return chaining_value


def md_hash_4(message_blocks, initial_value=0x87654321):
    chaining_value = initial_value
    for block in message_blocks:
        data = chaining_value.to_bytes(4, 'little') + block.to_bytes(8, 'little')
        chaining_value = int(md5(data).hexdigest()[:5], 16)
    return chaining_value


#====================================
# start by constructing a multicollision

def question7():
    colliding_message_blocks = []
    
    for i in range(32):
        # each time, restart from the current message blocks, and try to find
        # two colliding blocks
        print(i)
        outputs = {}
        
        while True:
            random_block = randrange(2**64)
            new_output = md_hash_3( [t[0] for t in colliding_message_blocks] + [random_block] )
            if new_output in outputs:
                # new pair of message blocks
                colliding_message_blocks.append( (random_block, outputs[new_output]) )
                print("New message block")
                break
            else:
                outputs[new_output] = random_block


    # connect the last chaining value to the wanted output
    cur_chaining_val = md_hash_3( [t[0] for t in colliding_message_blocks] )
    final_block = None

    while True:
        random_block = randrange(2**64)
        new_output = md_hash_3( [t[0] for t in colliding_message_blocks] + [random_block] )
        if new_output == 0:
            final_block = random_block
            print("Found final block")
            break

    print( colliding_message_blocks )
    print( final_block )
    return colliding_message_blocks, final_block


colliding_message_blocks = [(281989031243090721, 1335115419322625663), (9057222544972648237, 11892630717560121085), (3548907711684017271, 6893215060183484219), (5240176005317984616, 18391913952017095995), (15869301684152716044, 8018174116310841163), (12294164229841986293, 16973248695214173031), (8318670524576737171, 15962811740171048882), (17193590034812392030, 683410617624692697), (13445806166936614457, 18219849229450832696), (9549634603916476954, 16566597688637707707), (18048014071161865910, 16136287018590531664), (12677141341674875537, 11704833130698270890), (15830900990827840166, 13760157336297551454), (12220196008784005921, 11512696155220042392), (15136326969004449058, 15919365396313079489), (14858063291278054026, 4023199520465378989), (10631871602465490736, 13005829794413972386), (11523901201301735895, 16455494401346692449), (2107163257695730177, 3935088962610527675), (4250682415354700041, 13193726176319201153), (13980053364574756800, 544875928052196574), (344598790600299, 3158070729551004726), (6121020294218083355, 12997682616783810702), (7928814625781862303, 5051646802399407403), (14665282148792228767, 11564050659009900848), (7602348308049774518, 5003875680549675420), (4301718325930786131, 7654655572897893903), (10440486859960609792, 6338233457608553459), (1331027148344640934, 16839840145461284582), (15784268563769251327, 7512508516339096135), (10137662648291695037, 251634069500330398), (5780148207869682775, 1575867809702470604)]

final_block = 8239226874239682388

def question72():
    msg = None
    while True:
        random_message_blocks = (
            [ t[randrange(2)] for t in colliding_message_blocks ] + [final_block])
        #print( md_hash_3(random_message_blocks) )
        if md_hash_4(random_message_blocks) == 0:
            msg = random_message_blocks
            break
    
    msg = [281989031243090721, 11892630717560121085, 3548907711684017271, 5240176005317984616, 8018174116310841163, 12294164229841986293, 15962811740171048882, 683410617624692697, 13445806166936614457, 9549634603916476954, 16136287018590531664, 12677141341674875537, 13760157336297551454, 12220196008784005921, 15136326969004449058, 14858063291278054026, 13005829794413972386, 16455494401346692449, 2107163257695730177, 4250682415354700041, 13980053364574756800, 3158070729551004726, 6121020294218083355, 5051646802399407403, 14665282148792228767, 5003875680549675420, 4301718325930786131, 6338233457608553459, 1331027148344640934, 15784268563769251327, 251634069500330398, 1575867809702470604, 8239226874239682388]
    
    print(msg)
    print(md_hash_3(msg), md_hash_4(msg) )


question72()


