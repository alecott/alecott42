import sys, re
import rules_application

def check_modele(ret):
    #Check all the posssibles errors
    #->maybe commentary
    return(ret)

def parsing(lines):
    # do we need to handle commentary?
    rules = []
    symbols = [')','(','+','!','|','^','>','<','=',' ','\n','=','?']
    empty = [' ', '\n', '\t']
    s_facts = ""

    for line in lines:
        tmp = ""
        for c in line:
            if (c.isupper() == False and c not in symbols):
                print("Error : Wrong character :" + c)
                exit()
            elif (c not in empty):
                tmp = tmp + c
            if (c.isupper() == True and c not in s_facts):
                s_facts = s_facts + c
        if (tmp != ""):
            rules.append(tmp)
    initial_facts = list(rules[-2][1:])
    queries = list(rules[-1][1:])
    del rules[-2:]
    facts = {}
    for c in s_facts:
        facts[c] = False
        if (c in initial_facts):
            facts[c] = True
    return(check_modele({'rules':rules,'facts':facts,'queries':queries}))

def main():
    try:
        if (len(sys.argv) != 2):
            raise NameError("Error : Wrong number of parameter(must be one)")
        with open(sys.argv[1], 'r') as p:
            lines = p.readlines()
    except NameError:
        print("Error : Wrong number of parameter(must be one)")
        sys.exit(1)
    except OSError:
        print("Error : Can't open the parameter")
        sys.exit(1)
    my_dic = parsing(lines)
    print(my_dic)
    ret_dic = rules_application.begin(my_dic)
    for q in ret_dic['queries']:
        print(q,"is",ret_dic['facts'][q])

if __name__ == "__main__":
    main()
