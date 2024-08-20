# Main Author: Saeed Bafana
# Main Reviewer: Sampreet Klair, Harsahbaj Singh

from a1_partc import Queue
from a1_partd import overflow

# Evaluation function to determine the score of the board for a specific player.
# This function calculates the score by summing up the absolute values of gems on the board.
# It returns a normalized score based on the total non-empty element values.
def evaluate_board(board, player) -> float:
    score_p1 = 0
    score_p2 = 0

    for row in board:
        for col in row:
            if col > 0:
                score_p1 += col
            elif col < 0:
                score_p2 += (-col)

    tot_non_empty_elem_value = score_p1 + score_p2

    if tot_non_empty_elem_value != 0:
        score_p1 /= tot_non_empty_elem_value
        score_p2 /= tot_non_empty_elem_value

    return score_p1 if player == 1 else score_p2


# GameTree class represents the structure of the game tree and includes methods to create the tree,
# evaluate possible moves, and determine the best move using the Minimax algorithm.
class GameTree:
    class Node:
        # Initializes a node in the game tree.
        # Parameters:
        # - board: The current board state.
        # - depth: The depth of the node in the tree.
        # - player: The player (1 or -1) for whom the node is created.
        # - tree_height: The maximum height of the game tree.
        def __init__(self, board, depth, player, tree_height=4):
            self.board = board
            self.depth = depth
            self.player = player
            self.tree_height = tree_height
            self.children = []

    # Initializes the GameTree object by creating the root node and building the game tree.
    # Parameters:
    # - board: The current state of the game board.
    # - player: The player (1 or -1) for whom the tree is created.
    # - tree_height: The maximum height of the game tree.
    def __init__(self, board, player, tree_height=4):
        self.player = player
        self.board = copy_board(board)
        self.tree_height = tree_height
        self.root = self.Node(self.board, 0, self.player, self.tree_height)
        self.board_list = [self.root]
        self.create_tree(self.root)

    # Recursively creates the game tree by generating child nodes for possible moves.
    # Stops when the maximum tree height is reached or when a terminal board state is encountered.
    def create_tree(self, node):
        curr_player = node.player
        nxt_player = curr_player * -1

        if node.tree_height <= node.depth or self.is_board_terminal(node.board, curr_player):
            return

        possible_moves, winning_row, winning_col = self.get_possible_moves(node.board, node.player)

        for move in possible_moves:
            child_node = self.Node(move, node.depth + 1, nxt_player, self.tree_height)
            node.children.append(child_node)
            self.board_list.append(child_node)
            self.create_tree(child_node)

    # Determines possible moves for the current player by analyzing the board and considering valid placements.
    # Returns a list of possible moves and the coordinates of a winning move if found.
    def get_possible_moves(self, board, player):
        def count_neighbors(row, col):
            rows = len(board)
            cols = len(board[0])
            neighbors = 0

            if row > 0:
                neighbors += 1
            if row < rows - 1:
                neighbors += 1
            if col > 0:
                neighbors += 1
            if col < cols - 1:
                neighbors += 1

            return neighbors

        def is_valid_cell_to_play(board, row, col, player):
            playable = board[row][col]

            if playable == 0:
                return True

            adjacent_cell_count = count_neighbors(row, col)
            player_sign = 1 if player > 0 else -1

            if player > 0:
                return (adjacent_cell_count > playable) and playable > 0

            if player < 0:
                return (adjacent_cell_count > playable) and playable < 0

            return False

        possible_moves = []
        winning_row = None
        winning_col = None

        for i in range(len(board)):
            for j in range(len(board[i])):
                if is_valid_cell_to_play(board, i, j, player):
                    new_board = copy_board(board)
                    new_board[i][j] += player

                    self.do_overflow(new_board)

                    possible_moves.append(new_board)

                    if self.is_board_terminal(new_board, player):
                        winning_row, winning_col = i, j
                        break

            if winning_row is not None:
                break

        return possible_moves, winning_row, winning_col

    # Performs the overflow operation on the board if the number of gems in a square exceeds the limit.
    def do_overflow(self, board):
        overflowed_boards = Queue()
        overflow(board, overflowed_boards)

    # Checks if the board is in a terminal state, meaning one player has won the game.
    def is_board_terminal(self, board, player) -> bool:
        return evaluate_board(board, player) == 1

    # Determines if it is the current player's turn based on the player value.
    def player_in_turn(self, player: int) -> bool:
        return player == 1

    # Evaluates the board value using the evaluation function and returns it.
    # The value is multiplied by the player to adjust the score direction.
    def min_max_board_value(self, board: list, player: int) -> float:
        return evaluate_board(board, player) * player

    # Prints the current state of the board to the console.
    def print_board(self, board):
        for row in board:
            print(' '.join(str(cell) for cell in row))
        print()

    # Recursively prints the game tree starting from the specified node, showing depth and player information.
    def print_tree(self, node, indent=""):
        print(f"Depth: {node.depth}, Player: {node.player}")
        self.print_board(node.board)
        for child in node.children:
            self.print_tree(child, indent + "    ")

    # Determines the best move by evaluating all possible moves using the Minimax algorithm.
    # Returns the row and column of the best move.
    def get_move(self):
        alpha = -float('inf')
        beta = float('inf')
        result_move = None
        best_value = -float('inf') if self.player == 1 else float('inf')

        possible_moves, winning_row, winning_col = self.get_possible_moves(self.board, self.player)

        if winning_row is not None:
            return winning_row, winning_col

        for move in possible_moves:
            move_value = self.min_max(move, alpha, beta, self.player * -1, 1)

            if self.player == 1 and move_value > best_value:
                best_value = move_value
                result_move = move
            elif self.player == -1 and move_value < best_value:
                best_value = move_value
                result_move = move

        if result_move:
            for i in range(len(self.board)):
                for j in range(len(self.board[i])):
                    if self.board[i][j] != result_move[i][j]:
                        return i, j
        return None

    # Minimax algorithm to evaluate the best possible move by considering all potential opponent moves.
    # Alpha-beta pruning is used to optimize the search process by eliminating unnecessary branches.
    def min_max(self, board, alpha, beta, player, depth):
        if self.tree_height == 0 or self.is_board_terminal(board, player) or depth >= self.tree_height:
            return self.min_max_board_value(board, player)

        if self.player_in_turn(player):
            max_value = -float('inf')

            possible_moves, _, _ = self.get_possible_moves(board, player)
            possible_moves.sort(key=lambda move: self.estimate_move_value(move, player), reverse=True)

            for move in possible_moves:
                eval = self.min_max(move, alpha, beta, -player, depth + 1)
                max_value = max(max_value, eval)
                alpha = max(alpha, max_value)
                if beta <= alpha:
                    break

            return max_value

        else:
            min_value = float('inf')

            possible_moves, _, _ = self.get_possible_moves(board, player)
            possible_moves.sort(key=lambda move: self.estimate_move_value(move, player))

            for move in possible_moves:
                eval = self.min_max(move, alpha, beta, -player, depth + 1)
                min_value = min(min_value, eval)
                beta = min(beta, min_value)
                if beta <= alpha:
                    break

            return min_value

    # Estimates the value of a move based on the Minimax evaluation of the resulting board state.
    def estimate_move_value(self, move, player):
        return self.min_max_board_value(move, player)

    # Placeholder method to clear the game tree by unlinking all nodes. This allows garbage collection to free memory.
    def clear_tree(self):
        pass

# Utility function to create a deep copy of the board.
# This ensures that changes to one board do not affect the original board.
def copy_board(board):
    current_board = []
    height = len(board)

    for i in range(height):
        current_board.append(board[i].copy())

    return current_board