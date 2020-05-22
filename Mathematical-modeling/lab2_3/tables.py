from math import log


class Record1(object):
    def __init__(self, amperage, temperature, m):
        self.I = amperage
        self.T0 = temperature
        self.m = m


class Record2(object):
    def __init__(self, temperature, sigma):
        self.T = temperature
        self.sigma = sigma


class Tables(object):
    def __init__(self):
        self.table1 = [Record1(0.5, 6400, 0.4),
                       Record1(1, 6790, 0.55),
                       Record1(5, 7150, 1.7),
                       Record1(10, 7270, 3),
                       Record1(50, 8010, 11),
                       Record1(200, 9185, 32),
                       Record1(400, 10010, 40),
                       Record1(800, 11140, 41),
                       Record1(1200, 12010, 39)]

        self.table2 = [Record2(4000, 0.031),
                       Record2(5000, 0.27),
                       Record2(6000, 2.05),
                       Record2(7000, 6.06),
                       Record2(8000, 12.0),
                       Record2(9000, 19.9),
                       Record2(10000, 29.6),
                       Record2(11000, 41.1),
                       Record2(12000, 54.1),
                       Record2(13000, 67.7),
                       Record2(14000, 81.5)]

    def get_I(self):
        return [rec.I for rec in self.table1]

    def get_T0(self):
        return [rec.T0 for rec in self.table1]

    def get_m(self):
        return [rec.m for rec in self.table1]

    def get_T(self):
        return [rec.T for rec in self.table2]

    def get_sigma(self):
        return [rec.sigma for rec in self.table2]

    def get_log_T(self):
        return [log(k) for k in self.get_T()]

    def get_log_sigma(self):
        return [log(k) for k in self.get_sigma()]


if __name__ == '__main__':
    tables = Tables()
    print(tables.get_I())
    print(tables.get_T0())
    print(tables.get_m())
    print(tables.get_T())
    print(tables.get_sigma())
    print(tables.get_log_T())
    print(tables.get_log_sigma())





