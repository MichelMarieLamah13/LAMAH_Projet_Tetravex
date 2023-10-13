#pragma once
#include <vector>
#include <fstream>

#include "Piece.h"
#include "Helper.h"
class Plateau
{
private:
    vector<Piece> pieces;
    int format;
    string filename;
    void loadDataFromFile();
    bool isFileExist();

public:
    Plateau();
    Plateau(string filename);

    int getFormat() const {return format;};

    vector<Piece> getPieces() const {return pieces;};
    string formatPlateau(vector<Piece> pieces) const;
    string formatPlateau(Piece * pieces) const;
    friend ostream& operator<< (ostream& os, const Plateau& piece);
    
};

