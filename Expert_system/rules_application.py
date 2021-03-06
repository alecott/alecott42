import resolve_condition

def replace_condition(tab_tmp,tab,x,y):
    tmp = resolve_rule(tab_tmp)
    tab.insert(x,tmp[0])
    del(tab[x+1:y+2])
    return(tab)

def handle_parentheses(tab):
    if ('('  in tab):
        x = 0
        while(x < len(tab)):
            if (tab[x] == ')'):
                break
            x += 1
        y = x
        while (x != 0):
            if (tab[x] == '('):
                break
            x -= 1
        return(replace_condition(tab[(x+1):y],tab,x,y))
    return(tab)

def resolve_rule(tab):
    while ('(' in tab):
        tab = handle_parentheses(tab)
    while (len(tab) != 1):
        tab = resolve_condition.resolve_condition(tab)
    return(tab)

def put_boolean(s,dic):
    if (s[0] == '!'):
        if (dic["facts"][s[1:]] == True):
            return(False)
        else:
            return(True)
    else:
            return(dic["facts"][s])

def create_tab(str):
    tab = []
    tmp = ""
    for c in str:
        tmp = tmp + c
        if (c != '!'):
            tab.append(tmp)
            tmp = ""
    return (tab)

def clean_rule(rule):
    clean_rule = {}
    tmp = ""
    for c in rule:
        if (c == '='):
            clean_rule["condition"] = tmp
            tmp = ""
        tmp = tmp + c
    if (clean_rule["condition"][-1] == '<'):
        clean_rule["opperand"] = '<' + tmp[:2]
        clean_rule["condition"] = clean_rule["conditions"][:-1]
    else:
        clean_rule["opperand"] = tmp[:2]
    tmp = tmp[2:]
    clean_rule["conclusion"] = tmp
    return(clean_rule)

def begin(dic):
    for rule in dic["rules"]:
        c_rule = clean_rule(rule)
        tab_tmp = create_tab(c_rule["condition"])
        tab_conclusion = create_tab(c_rule["conclusion"])
        tab = []
        for elem in tab_tmp:
            if (elem.isupper()):
                elem = put_boolean(elem,dic)
            tab.append(elem)
        print ("\n\n","-Starting to resolve the rule:",rule,'\n',c_rule,"\n","Resolving condition","\n",tab_tmp,"\n",tab)
        ret = resolve_rule(tab)
        if (len(tab_conclusion) == 1):
            dic["facts"][c_rule["conclusion"]] = ret[0]
            print('\n',c_rule["conclusion"],'=',ret[0],'\n',dic['facts'],'\n\n')
        elif(len(tab_conclusion) == 3):
            tab_conclusion = create_tab(c_rule["conclusion"])
            dic["facts"] = resolve_condition.resolve_conclusion(ret[0],tab_conclusion,dic["facts"])
        else:
            print("Error: Conclusion of",rule,"rule is to complex")
            sys.exit(1)
    return(dic)
