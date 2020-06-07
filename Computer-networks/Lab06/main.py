import shlex, subprocess


def getEstablishedConnections():
    bashCommand = "netstat -atn"
    args = shlex.split(bashCommand)
    process = subprocess.Popen(args, stdout=subprocess.PIPE)
    output, error = process.communicate()
    return output


def parseConnections(connections):
    addresses = []
    for line in connections:
        lineArr = line.split(" ")
        if "ESTABLISHED" in lineArr:
            # print(lineArr)
            for _ in range(lineArr.count("")):
                # print(lineArr.count(" ")
                lineArr.remove("")
            addresses.append(lineArr)
    return addresses


def printAmountOfActiveConnections(addrs):
    print("Количество активых сетевых адресов(IPV4 / IPV6): ", len(addrs))


def printListOfActiveConnections(addrs):
    print("Тип             Локальный адрес            Внешний адрес")
    for addr in addrs:
        print("{:}  {:>25}  {:>25}".format(addr[0], addr[3], addr[4]))


def getPacketsInfo():
    bashCommand = "netstat -s"
    args = shlex.split(bashCommand)
    process = subprocess.Popen(args, stdout=subprocess.PIPE)
    output, error = process.communicate()
    return output


def parsePackets(packs):
    ipv4 = []
    ipv6 = []
    flag = -1
    for p in packs:
        _p = p.split("\n")
        for a in _p:
            if flag == 0:
                ipv4.append(a)
            elif flag == 1:
                ipv6.append(a)
            if a == "ip:":
                flag = 0
            elif a == "ip6:":
                flag = 1
            elif a == "icmp6:" or a == "icmp:":
                flag = -1
    for _ in range(ipv4.count("")):
        ipv4.remove("")
    for _ in range(ipv6.count("")):
        ipv6.remove("")
    return ipv4, ipv6


def printPacketsInfoIPV4(ipv4):
    print("Информация о пакетах IPV4: ")
    print(ipv4[0])
    print(ipv4[16])
    print(ipv4[17])
    print("Количество пакетов которые не удалось доставить:")
    for i in range(1, 12):
        print(ipv4[i])
    print("Фрагментированные пакеты:")
    print(ipv4[12])
    print("\t" + ipv4[13])
    print("\t" + ipv4[14])
    print("\t" + ipv4[15])


def printPacketsInfoIPV6(ipv6):
    print("\nИнформация о пакетах IPV6: ")
    print(ipv6[0])
    print(ipv6[13])
    print("Количество пакетов которые не удалось доставить:")
    for i in range(1, 6):
        print(ipv6[i])
    print("Фрагментированные пакеты:")
    print(ipv6[7])
    print("\t" + ipv6[8])
    print("\t" + ipv6[9])
    print("\t" + ipv6[10])
    print("\t" + ipv6[11])
    print("\t" + ipv6[12])


if __name__ == "__main__":
    # Получение активых соединений
    connections = getEstablishedConnections()
    addrs = parseConnections(connections.decode("utf-8").split("\n"))

    printAmountOfActiveConnections(addrs)
    printListOfActiveConnections(addrs)
    print("\n\n")

    # Получение информации о пакетах
    packs = getPacketsInfo()
    packs = packs.decode("utf-8").split("\t")
    ipv4, ipv6 = parsePackets(packs)

    printPacketsInfoIPV4(ipv4)
    printPacketsInfoIPV6(ipv6)
