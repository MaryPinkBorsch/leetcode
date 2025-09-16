class Solution {
public:
    enum GAME { A, B, TIE, GAMING };
    // 1 = A         2 = B      0 = pusto
    string tictactoe(vector<vector<int>>& moves) 
    {
        vector<vector<int>> field;
        field = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int tmp = 0;
        for (auto& it : moves) {
            field[it[0]][it[1]] = 1 + tmp % 2; // 1 = A   `````        2 = B
            GAME state = check(field);
            switch (state) {
            case A:
                return "A";
                break;
            case B:
                return "B";
                break;
            case TIE:
                return "Draw";
                break;
            default:
                break;
            };

            tmp++;
        }
        return "Pending";
    }

    GAME check(vector<vector<int>>& field) {
        bool a = false, b = false, tie = true;
        for (int i = 0; i < 3; i++) {
            a = true;
            b = true;
            for (int j = 0; j < 3; j++) {
                if (field[i][j] == 0)
                    tie = false;
                if (field[i][j] != 1)
                    a = false;
                if (field[i][j] != 2)
                    b = false;
            }
            if (a)
                return A;
            if (b)
                return B;
        }
        if (tie)
            return TIE;

        a = false, b = false, tie = true;
        for (int j = 0; j < 3; j++) {
            a = true;
            b = true;
            for (int i = 0; i < 3; i++) {
                if (field[i][j] == 0)
                    tie = false;
                if (field[i][j] != 1)
                    a = false;
                if (field[i][j] != 2)
                    b = false;
            }
            if (a)
                return A;
            if (b)
                return B;
        }
        if (tie)
            return TIE;

        tie = true;
        a = true;
        b = true;
        for (int i = 0; i < 3; i++) {

            if (field[i][i] != 1)
                a = false;
            if (field[i][i] != 2)
                b = false;
        }
        if (a)
            return A;
        if (b)
            return B;


        tie = true;
        a = true;
        b = true;
        for (int i = 0; i < 3; i++) {

            if (field[2-i][i] != 1)
                a = false;
            if (field[2-i][i] != 2)
                b = false;
        }
        if (a)
            return A;
        if (b)
            return B;    

        return GAMING;
    }
};