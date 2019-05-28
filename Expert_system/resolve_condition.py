def resolve_or(ret):
    if (ret[0] == True or ret[2] == True):
        return(True)
    else:
        return(False)

def resolve_and(ret):
    if (ret[0] == True and ret[2] == True):
        return(True)
    else:
        return(False)

def resolve_xor(ret):
    if ((ret[0] == False and ret[2] == True)
    or (ret[0] == True and ret[2] == False)):
        return(True)
    else:
        return(False)

def resolve_condition(ret):
    if (ret[1] == '|'):
        ret[0] = resolve_or(ret)
        del(ret[1:3])
    elif (ret[1] == '+'):
        ret[0] = resolve_and(ret)
        del(ret[1:3])
    elif (ret[1] == '^'):
        ret[0] = resolve_or(ret)
        del(ret[1:3])
    return(ret)
