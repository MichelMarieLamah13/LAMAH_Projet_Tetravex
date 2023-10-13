#include "../headers/Plateau.h"
#include <string>

Plateau::Plateau()
{
    
}

Plateau::Plateau(string filename)
{
    this->filename = filename;
    this->pieces = {};
    format = 0;
    this->loadDataFromFile();
}

bool Plateau::isFileExist()
{
    ifstream myFile(filename);
    if (myFile)
    {
        return true;
    }
    return false;
}

void Plateau::loadDataFromFile()
{
    if (!isFileExist())
    {
        cout << "ERREUR: Le fichier '" << filename << "' n'existe pas" << endl;
        return;
    }

    ifstream myFile(filename);
    string line;

    getline(myFile, line);
    if (line.length() != 3)
    {
        cout << "ERREUR: La 1ere ligne du fichier ne doit contenir que 3 caractere. Ex: 3 3" << endl;
        cout << "Format 1ere ligne: format format => 3 3" << endl;
        return;
    }

    format = Helper::char2Int(line[0]);    
    while (getline(myFile, line))
    {
        if (line.length() != 7)
        {
            cout << "ERREUR: Une ligne representant une piece ne contient que 7 caracteres" << endl;
            cout << "Format ligne: left top right bottom => 2 3 1 4" << endl;
            return;
        }
        int left = Helper::char2Int(line[0]);
        int top = Helper::char2Int(line[2]);
        int right = Helper::char2Int(line[4]);
        int bottom = Helper::char2Int(line[6]);
        pieces.push_back(
            Piece(left, top, right, bottom)
        );
    }
}

ostream& operator<< (ostream& os, const Plateau& plateau)
{
    os << "Format: " << plateau.format << " x " << plateau.format << endl;
    os << "Pieces: " << endl;
    os << plateau.formatPlateau(plateau.pieces) << endl;
    return os;
}

string Plateau::formatPlateau(vector<Piece> pieces) const
{
    string result = "";
    if (pieces.size())
    {
        string lignes[4] = {"", "", "", ""};
        string fin = "";
        for (int i = 0; i < format; i++)
        {
            lignes[0] = "";
            lignes[1] = "";
            lignes[2] = "";
            lignes[3] = "";

            for (int j = 0; j < format; j++)
            {
                Piece p = pieces[j + i * format];

                if (i == 0) // 1ere ligne
                {
                    if (j == 0) // 1ere colonne
                    {
                        lignes[0] += "╔═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j != 0 && j != format - 1) // element du milieu
                    {
                        lignes[0] += "╦═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j == format - 1) // derniere colonne
                    {
                        lignes[0] += "╦═══╗";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ║";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight()) + "║";
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ║";
                    }
                }

                if (i != 0 && i != format - 1) // igne intermediaire
                {
                    if (j == 0) // 1ere colonne
                    {
                        lignes[0] += "╠═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j != 0 && j != format - 1) // element du milieu
                    {
                        lignes[0] += "╬═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j == format - 1) // derniere colonne
                    {
                        lignes[0] += "╬═══╣";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ║";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight()) + "║";
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ║";
                    }
                }

                if (i == format - 1) // derniere ligne
                {
                    if (j == 0) // 1ere colonne
                    {
                        lignes[0] += "╠═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                        fin += "╚═══";
                    }
                    if (j != 0 && j != format - 1) // element du milieu
                    {
                        lignes[0] += "╬═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                        fin += "╩═══";
                    }
                    if (j == format - 1) // derniere colonne
                    {
                        lignes[0] += "╬═══╣";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ║";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight()) + "║";
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ║";
                        fin += "╩═══╝";
                    }
                }
            }

            for (string ligne : lignes)
            {
                result += ligne + "\n";
            }
        }
        result+=fin+"\n";
    }
    return result;
}

string Plateau::formatPlateau(Piece * pieces) const
{
    string result = "";
    if (format)
    {
        string lignes[4] = {"", "", "", ""};
        string fin = "";
        for (int i = 0; i < format; i++)
        {
            lignes[0] = "";
            lignes[1] = "";
            lignes[2] = "";
            lignes[3] = "";

            for (int j = 0; j < format; j++)
            {
                Piece p = pieces[j + i * format];

                if (i == 0) // 1ere ligne
                {
                    if (j == 0) // 1ere colonne
                    {
                        lignes[0] += "╔═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j != 0 && j != format - 1) // element du milieu
                    {
                        lignes[0] += "╦═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j == format - 1) // derniere colonne
                    {
                        lignes[0] += "╦═══╗";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ║";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight()) + "║";
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ║";
                    }
                }

                if (i != 0 && i != format - 1) // igne intermediaire
                {
                    if (j == 0) // 1ere colonne
                    {
                        lignes[0] += "╠═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j != 0 && j != format - 1) // element du milieu
                    {
                        lignes[0] += "╬═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                    }
                    if (j == format - 1) // derniere colonne
                    {
                        lignes[0] += "╬═══╣";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ║";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight()) + "║";
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ║";
                    }
                }

                if (i == format - 1) // derniere ligne
                {
                    if (j == 0) // 1ere colonne
                    {
                        lignes[0] += "╠═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                        fin += "╚═══";
                    }
                    if (j != 0 && j != format - 1) // element du milieu
                    {
                        lignes[0] += "╬═══";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight());
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ";
                        fin += "╩═══";
                    }
                    if (j == format - 1) // derniere colonne
                    {
                        lignes[0] += "╬═══╣";
                        lignes[1] += "║ " + to_string(p.getTop()) + " ║";
                        lignes[2] += "║" + to_string(p.getLeft()) + " " + to_string(p.getRight()) + "║";
                        lignes[3] += "║ " + to_string(p.getBottom()) + " ║";
                        fin += "╩═══╝";
                    }
                }
            }

            for (string ligne : lignes)
            {
                result += ligne + "\n";
            }
        }
        result+=fin+"\n";
    }
    return result;
}
