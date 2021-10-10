import random
def generate_data(filename: str, num: int):
    file = open(filename, 'w', encoding='utf-8')
    for i in range(num):
        animal = random.randint(1, 3)
        name = ""
        weight = 0
        ind = 0
        if (animal == 1):
            quant = random.randint(1, 10)
            for j in range(quant):
                ch = (chr)(random.randint(97,121))
                name+=ch
            ind = random.randint(0,2)
            weight = random.randint(1, 1000000)
        elif (animal == 2):
            quant = random.randint(1, 10)
            for j in range(quant):
                ch = (chr)(random.randint(97,121))
                name+=ch
            ind = random.randint(0,2)
            weight = random.randint(1, 1000000)
        if (animal == 3):
            quant = random.randint(1, 10)
            for j in range(quant):
                ch = (chr)(random.randint(97,121))
                name+=ch
            ind = random.randint(0,1)
            weight = random.randint(1, 1000000)
        file.write(f"{animal} \n{name} {ind} {weight} \n")

if __name__ == '__main__':
    generate_data("test_10000_elements.txt", 10000)
    print("done")