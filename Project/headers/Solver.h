#pragma once
#include <vector>
#include <chrono>
#include "Plateau.h"
#include "Helper.h"
class Solver
{
private:
    Plateau plateau;
    virtual Piece * algorithm() = 0;
    void recordSolutionTo(string filename, double s, string t);
protected:
    struct SolverState
    {
        int position = - 1; // where to place the piece in finalPieces
        int piece = -1; // idx of piece to place (idx from InitialPieces)
        int popPiece = -1; // idx of piece placed before piece, we keep this if bad move, we remove
    };
    bool isValidMove(Piece * solution, Piece * piece, int index);
    vector<Piece> pieces;
    int width;
    int size;
public:
    Solver();
    void solve(string dataFile, string solutionFile);
    void displaySolution (Piece * solution);

};