A, B = map(int, input().split())
result = [
    ['=', '>', '>', '>', '>', '<'],
    ['<', '=', '<', '=', '=', '<'],
    ['<', '>', '=', '>', '>', '>'],
    ['<', '=', '<', '=', '=', '<'],
    ['<', '=', '<', '=', '=', '<'],
    ['>', '>', '<', '>', '>', '='],
]

print(result[A][B])
