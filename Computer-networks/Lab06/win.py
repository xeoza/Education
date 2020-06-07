import os


def getIpList():
    cmd_res = os.popen("netstat -a").read().split("\n")
    for i in range(len(cmd_res)):
        cmd_res[i] = cmd_res[i].split()
    addressesIPv4 = []
    addressesIPv6 = []
    isFirst = 4
    for i in cmd_res:
        if len(i) > 2:
            if isFirst != 0:
                isFirst -= 1
                continue
            if i[1].find("::") != -1:
                addressesIPv6.append(i[1])
            else:
                addressesIPv4.append(i[1])
    print("IPv4 active addresses count: ", str(len(addressesIPv4)))
    print("IPv6 active addresses count: ", str(len(addressesIPv6)))
    print("IPv4 addresses list:")
    for i in addressesIPv4:
        print("\t", i)
    print("IPv6 addresses list:")
    for i in addressesIPv6:
        print("\t", i)


def getPacketsInfo():
    cmd_res = os.popen("netstat -e -s -p ip").read().split("\n")
    k = 0
    for i in cmd_res:
        line = i.split()
        if k == 13:
            print("Total packets: ", int(line[4]))
        if k == 27:
            print("Fragmented packets: ", line[len(line) - 1])
        if k == 18:
            print("Dropped packets: ", line[len(line) - 1])
        k += 1


if __name__ == "__main__":
    getIpList()
    getPacketsInfo()
