import os

def getIpList():
    cmd_res = os.popen("netstat -i").read().split("\n")
    for i in range(len(cmd_res)):
        cmd_res[i] = cmd_res[i].split()
    addressesIPv4 = []
    addressesIPv6 = []
    isFirst = True
    for i in cmd_res:
        if isFirst:
            isFirst = False
            continue
        if len(i) == 9:
            if (i[3].find(":") != -1):
                addressesIPv6.append(i[3])
            else:
                addressesIPv4.append(i[3])
    print("IPv4 active addresses count: ",str(len(addressesIPv4)))
    print("IPv6 active addresses count: ", str(len(addressesIPv6)))
    print("IPv4 addresses list:")
    for i in addressesIPv4:
        print("\t",i)
    print("IPv6 addresses list:")
    for i in addressesIPv6:
        print("\t",i)


def getPacketsInfo():
    cmd_res = os.popen("netstat -sp ip").read().split('\n')
    k = 0
    for i in cmd_res:
        line = i.split()
        if (k == 1):
            print("Total packets: ", int(line[0]))
        if (k == 13):
            print("Fragmented packets: ", line[0])
        if (k == 31):
            print("Dropped packets: ", line[0])
        k += 1


if __name__ == '__main__':
    getIpList()
    getPacketsInfo()