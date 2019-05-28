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
        ret[0] = resolve_xor(ret)
        del(ret[1:3])
    return(ret)

def resolve_conclusion(ret,conclusion,facts):
    if (conclusion[1] == '+'):
        facts[conclusion[0]] = ret
        facts[conclusion[2]] = ret
    print('\n',conclusion[0],'=',ret,'\n',facts)
    print('\n',conclusion[2],'=',ret,'\n',facts,'\n\n')
    return(facts)
