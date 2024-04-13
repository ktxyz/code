def who_is_winner(pieces_position_list):
    width, height = 7, 6
    heights = [0 for _ in range(width)]
    board = [[] for _ in range(width)]

    def check_board(x, y, c):
        def check_type(x, y, dx, dy, c):
            amount = 0
            for sign in [-1, 1]:
                nx, ny = x, y
                while nx >= 0 and nx < width and ny >= 0 and ny < len(board[nx]):
                    if board[nx][ny] != c:
                        break
                    amount += 1
                    nx += dx * sign
                    ny += dy * sign
            return amount > 4
        return check_type(x, y, 1, 0, c) or check_type(x, y, 0, 1, c) or check_type(x, y, 1, 1, c) or check_type(x, y, -1, 1, c) 

    for p in pieces_position_list:
        player = p[2]
        column = ord(p[0]) - ord('A')
        board[column].append(player)
        if check_board(column, len(board[column]) - 1, player):
            return p[2:]
        
    return "Draw"
