import sys


def get_date_PXL(filename):
    parts = filename.split("_")
    date_part = parts[1]

    year = date_part[:4]
    month = date_part[4:6]
    day = date_part[6:]

    return year, month, day


def get_date_DCIM(filename):
    parts = filename.split("-")
    date_part = parts[1:4]

    year = date_part[0]
    month = date_part[1]
    day = date_part[2]

    return year, month, day


def get_date_DateTime(filename):
    parts = filename.split("-")
    date_part = parts[0]

    year = date_part[:4]
    month = date_part[4:6]
    day = date_part[6:8]

    return year, month, day


def get_date(filename):
    startSymbol = filename[0]

    if startSymbol == "P":
        return get_date_PXL(filename)
    elif startSymbol == "D":
        return get_date_DCIM(filename)

    return get_date_DateTime(filename)


def convert_filename(dates, filename):
    year, month, day = get_date(filename)
    id = year + month + day

    dates[id]["used"] += 1

    prefix = dates[id]["prefix"]
    photo_number = dates[id]["used"]

    extension = filename.split(".")[-1]
    return f"{prefix}_{year}_{month}_{day}_{photo_number}.{extension}"


def main():
    prefixesNum = 3
    dates = dict()
    for i in range(prefixesNum):
        prefix, year, month, day = input().split()
        id = year + month + day
        dates[id] = {"prefix": prefix, "used": 0}

    result = []
    for line in sys.stdin:
        fileName = line.rstrip()
        result.append(convert_filename(dates, fileName))
    result.sort()

    print(*result, sep="\n")

main()
