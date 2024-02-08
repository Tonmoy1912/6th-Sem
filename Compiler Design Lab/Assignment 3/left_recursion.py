exp1="S->Aa|c|a"
exp2="A->Ab|c"


def directLeftRecursionRemoval(exp):
    left_symbol=exp.split("->")[0]
    right_part=exp.split("->")[1]
    tokens=right_part.split("|")

    terminals=[]
    nonTerminals=[]

    for i in tokens:
        if left_symbol==i[:len(left_symbol)]:
            nonTerminals.append(i[len(left_symbol):])
        else:
            terminals.append(i)

    if len(nonTerminals)==0:
        print(exp)
        return 

    firstProd=""
    secondProd=""

    newSymbol=left_symbol+"'"

    firstProd=firstProd+left_symbol+"->"
    secondProd=secondProd+newSymbol+"->"

    for i in terminals:
        firstProd+=i+newSymbol+"|"
    firstProd=firstProd[:len(firstProd)-1]

    for i in nonTerminals:
        secondProd+=i+newSymbol+"|"

    secondProd+="$"

    # print("After left recursion removal")
    print(firstProd)
    print(secondProd)


# exp=input("Enter the production rules\n")
# directLeftRecursionRemoval(exp)





directLeftRecursionRemoval(exp1)
directLeftRecursionRemoval(exp2)