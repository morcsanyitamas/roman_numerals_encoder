
def get_roman_symbol(num, decimal_place):
    symbols = {
            1: 'I',
            5: 'V',
            10: 'X',
            50: 'L',
            100: 'C',
            500: 'D',
            1000: 'M'

    }
    int_num = int(num)
    div_by_five = int_num // 5
    mod_by_five = int_num % 5
    symbol_index = 10 ** decimal_place

    if mod_by_five == 4:
        return f'{symbols[symbol_index]}{symbols[symbol_index * 5 * (div_by_five + 1)]}'
    else:
        return f'{symbols[symbol_index * 5] * div_by_five}{symbols[symbol_index] * mod_by_five}'
        


def roman_numerals_encoder(number):
    decimal_place = len(str(number)) - 1
    result = ""
    for num in str(number):
        result += get_roman_symbol(num, decimal_place)
        decimal_place -= 1
    return result

print(roman_numerals_encoder(432))

    
# print(get_roman_symbol('0', 0))
# print(get_roman_symbol('1', 0))
# print(get_roman_symbol('2', 0))
# print(get_roman_symbol('3', 0))
# print(get_roman_symbol('4', 0))
# print(get_roman_symbol('5', 0))
# print(get_roman_symbol('6', 0))
# print(get_roman_symbol('7', 0))
# print(get_roman_symbol('8', 0))
# print(get_roman_symbol('9', 0))

# print(get_roman_symbol('0', 1))
# print(get_roman_symbol('1', 1))
# print(get_roman_symbol('2', 1))
# print(get_roman_symbol('3', 1))
# print(get_roman_symbol('4', 1))
# print(get_roman_symbol('5', 1))
# print(get_roman_symbol('6', 1))
# print(get_roman_symbol('7', 1))
# print(get_roman_symbol('8', 1))
# print(get_roman_symbol('9', 1))
