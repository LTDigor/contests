def convert_PXL(filename):
    parts = filename.split("_")
    date_part = parts[1]
    extension = filename.split(".")[-1]

    year = date_part[:4]
    month = date_part[4:6]
    day = date_part[6:]

    new_filename = "DRIFT_" + year + "_" + month + "_" + day + '.' + extension
    return new_filename


def convert_DCIM(filename):
    parts = filename.split("-")
    date_part = parts[1:4]
    extension = filename.split(".")[-1]

    new_filename = "DRIFT_" + "_".join(date_part) + '.' + extension
    return new_filename


def convert_DateTime(filename):
    parts = filename.split("-")
    date_part = parts[0]
    year = date_part[:4]
    month = date_part[4:6]
    day = date_part[6:8]
    extension = filename.split(".")[-1]

    new_filename = "DRIFT_" + year + "_" + month + "_" + day + '.' + extension
    return new_filename


def convert_filename(filename):
    startSymbol = filename[0]
    if startSymbol == "P":
        return convert_PXL(filename)
    elif startSymbol == "D":
        return convert_DCIM(filename)
    else:
        return convert_DateTime(filename)


filename = input()
print(convert_filename(filename))

