#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#pragma region playZone: slot
struct playZone {
    string* slot;
};
#pragma endregion

void mainScreenReset()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    cout << "\t\t\t\t\t\t\033[33mГРА \"П'ЯТНАШКИ\"\033[0m" << endl << endl;
}

short zoneSizeAsk()
{
    short userChoice;

    cout << endl;

    do {
        cout << "\t\t\t\t\033[32mОберіть режим гри (1 - 8 (3x3); 2 - 15 (4x4)): \033[0m";
        cin >> userChoice;

        if (userChoice == 1 || userChoice == 2) break;
        else cout << "\t\t\t\t\033[31mБув вибран неіснуючий варінт!" << "\n\t\t\t\tБудь ласка зробіть вибір ще раз!\033[0m";

        Sleep(4000);
        mainScreenReset();
    } while (true);

    return userChoice;
}

short mixingModeAsk()
{
    short userChoice;

    cout << endl;

    do {
        cout << "\t\t\t\t\033[32mВиберіть режим розмішування п'ятнашок (1 - ручне; 2 - комп'ютерне): \033[0m";
        cin >> userChoice;

        if (userChoice == 1 || userChoice == 2) break;
        else cout << "\t\t\t\t\033[31mБув вибран неіснуючий варінт!" << "\n\t\t\t\tБудь ласка зробіть вибір ще раз!\033[0m";

        Sleep(4000);
        mainScreenReset();
    } while (true);

    return userChoice;
}

short playModeAsk()
{
    short userChoice;

    cout << endl;   

    do {
        cout << "\t\t\t\t\033[32mВибір хто буде грати (1 - людина; 2 - комп'ютер): \033[0m";
        cin >> userChoice;

        if (userChoice == 1 || userChoice == 2) break;
        else cout << "\t\t\t\t\033[31mБув вибран неіснуючий варінт!" << "\n\t\t\t\tБудь ласка зробіть вибір ще раз!\033[0m";

        Sleep(4000);
        mainScreenReset();
    } while (true);

    return userChoice;
}

short* getPossibleWays(playZone& fieald, short size, short zoneType, short& waysCount, short& indexEmpty)
{
    for (short i = 0; i < size; i++) {
        if (fieald.slot[i] == "  ") 
        {
            indexEmpty = i; 
            break;
        }
    }

    if (zoneType == 3)
    {
        if (indexEmpty / zoneType == 0)
        {
            if (indexEmpty == 0)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty + zoneType;
                waysCount = 2;

                return arWays;
            }
            else if (indexEmpty == zoneType - 1)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + zoneType;
                waysCount = 2;

                return arWays;
            }
            else
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }
        }

        else if (indexEmpty / zoneType == 1)
        {
            if (indexEmpty == zoneType)
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty - zoneType;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }

            else if (indexEmpty + 1 == zoneType + zoneType)
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty - zoneType;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }

            else
            {
                short* arWays = new short[4];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty - zoneType;
                arWays[3] = indexEmpty + zoneType;
                waysCount = 4;

                return arWays;
            }
        }

        else
        {
            if (indexEmpty == zoneType + zoneType)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty - zoneType;
                waysCount = 2;

                return arWays;
            }

            else if (indexEmpty == (zoneType * zoneType) - 1)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty - zoneType;
                waysCount = 2;

                return arWays;
            }

            else
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty - zoneType;
                waysCount = 3;

                return arWays;
            }
        }
    }

    else
    {
        if (indexEmpty / zoneType == 0)
        {
            if (indexEmpty == 0)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty + zoneType;
                waysCount = 2;

                return arWays;
            }
            else if (indexEmpty == zoneType - 1)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + zoneType;
                waysCount = 2;

                return arWays;
            }
            else
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }
        }

        else if (indexEmpty / zoneType == 1)
        {
            if (indexEmpty == zoneType)
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty - zoneType;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }
            else if (indexEmpty == (zoneType * 2) - 1)
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty - zoneType;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }
            else
            {
                short* arWays = new short[4];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty - zoneType;
                arWays[3] = indexEmpty + zoneType;
                waysCount = 4;

                return arWays;
            }
        }

        else if (indexEmpty / zoneType == 2)
        {
            if (indexEmpty == zoneType * 2)
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty - zoneType;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }
            else if (indexEmpty == (zoneType * 3) - 1)
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty - zoneType;
                arWays[2] = indexEmpty + zoneType;
                waysCount = 3;

                return arWays;
            }
            else
            {
                short* arWays = new short[4];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty - zoneType;
                arWays[3] = indexEmpty + zoneType;
                waysCount = 4;

                return arWays;
            }
        }

        else
        {
            if (indexEmpty == zoneType * 3)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty + 1;
                arWays[1] = indexEmpty - zoneType;
                waysCount = 2;

                return arWays;
            }
            else if (indexEmpty == 15)
            {
                short* arWays = new short[2];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty - zoneType;
                waysCount = 2;

                return arWays;
            }
            else
            {
                short* arWays = new short[3];
                arWays[0] = indexEmpty - 1;
                arWays[1] = indexEmpty + 1;
                arWays[2] = indexEmpty - zoneType;
                waysCount = 3;

                return arWays;
            }
        }
    }
}

void printField(playZone& field, short zoneType)
{
    cout << endl;

    if (zoneType == 3)
    {
        cout << "\t\t\t\t\t \033[34m         +=======+\033[0m" << endl;

        short count = 0;

        for (short i = 0; i < zoneType * zoneType; i++) {
            if (count == 0)
            {
                cout << "\t\t\t\t\t          \033[34m|\033[0m " << field.slot[i];
                count++;
            }
            else if (count == 1)
            {
                cout << field.slot[i];
                count++;
            }
            else
            {
                cout << field.slot[i] << "\033[34m|\033[0m" << endl;
                count = 0;
            }
        }

        cout << "\t\t\t\t\t          \033[34m+=======+\033[0m" << endl;
    }

    else
    {
        cout << "\t\t          \t\t\t\033[34m+=============+\033[0m" << endl;

        short count = 0;

        for (short i = 0; i < zoneType * zoneType; i++) {
            if (count == 0)
            {
                cout << "\t\t\t\t\t        \033[34m|\033[0m " << field.slot[i];
                count++;
            }
            else if (count == 1 || count == 2)
            {
                cout << ' ' << field.slot[i];
                count++;
            }
            else
            {
                cout << ' ' << field.slot[i] << " \033[34m|\033[0m" << endl;
                count = 0;
            }
        }

        cout << "\t\t            \t\t\t\033[34m+=============+\033[0m" << endl;
    }

    cout << endl << endl;
}

bool getWinCheck(playZone& field, short zoneType)
{
    if (zoneType == 3)
    {
        string* arCheck = new string[9];
        arCheck[0] = "1 ";
        arCheck[1] = "2 ";
        arCheck[2] = "3 ";
        arCheck[3] = "4 ";
        arCheck[4] = "5 ";
        arCheck[5] = "6 ";
        arCheck[6] = "7 ";
        arCheck[7] = "8 ";
        arCheck[8] = "  ";

        for (short i = 0; i < 9; i++) {
            if (arCheck[i] != field.slot[i])
            {
                delete[] arCheck;
                return false;
            }
        }

        delete[] arCheck;

        return true;
    }

    if (zoneType == 4)
    {
        string* arCheck = new string[16];
        arCheck[0] = " 1";
        arCheck[1] = " 2";
        arCheck[2] = " 3";
        arCheck[3] = " 4";
        arCheck[4] = " 5";
        arCheck[5] = " 6";
        arCheck[6] = " 7";
        arCheck[7] = " 8";
        arCheck[8] = " 9";
        arCheck[9] = "10";
        arCheck[10] = "11";
        arCheck[11] = "12";
        arCheck[12] = "13";
        arCheck[13] = "14";
        arCheck[14] = "15";
        arCheck[15] = "  ";

        for (short i = 0; i < 16; i++) {
            if (arCheck[i] != field.slot[i])
            {
                delete[] arCheck;
                return false;
            }
        }

        delete[] arCheck;

        return true;
    }

    return false;
}

short* deleteObject(short*& ar, short& size, short objectToDelete)
{
    bool objectExist = false;
    for (short i = 0; i < size; i++) {
        if (objectToDelete == ar[i])
        {
            objectExist = true;
            break;
        }
    }

    if (!objectExist) return ar;

    else
    {
        short* newAr = new short[size - 1];

        bool objectDeleteStatus = false;

        for (short i = 0; i < size; i++) {
            if (objectToDelete == ar[i])
            {
                objectDeleteStatus = true;
            }
            else if (!objectDeleteStatus)
            {
                newAr[i] = ar[i];
            }
            else
            {
                newAr[i - 1] = ar[i];
            }
        }

        size--;
        delete[] ar;

        return newAr;
    }
}

int getLastGameNumber(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return 0;
    }

    string line;
    int lastGameNumber = 0;

    while (getline(file, line)) {
        if (line[0] == 'Г')
        {
            int gameNumber = char(line[5]) - '0';
            lastGameNumber = max(gameNumber, lastGameNumber);
        }
    }

    file.close();

    return lastGameNumber;
}

void addGameData(string& filename, double playTime, int numberOfPermutations) {
    int lastGameNumber = getLastGameNumber(filename);
    int newGameNumber = lastGameNumber + 1;

    ofstream file;
    file.open(filename, ios::app);

    file << "Гра №" << newGameNumber << ":\n";
    file << "Кількість часу, витрачено на збирання п’ятнашок: " << playTime << " сек..\n";
    file << "Кількість перестановок п’ятнашок для збору: " << numberOfPermutations << ".\n\n";
    file.close();
}

int main()
{
    srand(time(0));

    #pragma region КИРИЛИЦЯ
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    #pragma endregion

    while (true)
    {
        mainScreenReset();

        short zoneSize = zoneSizeAsk();
        short mixingSpotsMode = mixingModeAsk();
        short playMode = playModeAsk();

        short actionsCount = 0;
        vector <short> actionsSave;

        short numberOfPermutations = 0;

        playZone fieald;

        auto startPlayTime = chrono::steady_clock::now();
        auto endPlayTime = chrono::steady_clock::now();
        double playTime;

        if (zoneSize == 1)
        {
            fieald.slot = new string[9];

            if (mixingSpotsMode == 1)
            {
                fieald.slot[0] = "1 ";
                fieald.slot[1] = "2 ";
                fieald.slot[2] = "3 ";
                fieald.slot[3] = "4 ";
                fieald.slot[4] = "5 ";
                fieald.slot[5] = "6 ";
                fieald.slot[6] = "7 ";
                fieald.slot[7] = "8 ";
                fieald.slot[8] = "  ";

                mainScreenReset();
                printField(fieald, 3);

                while (true) {
                    short emptyIndex;
                    short waysCount;
                    short* possibleWays = getPossibleWays(fieald, 9, 3, waysCount, emptyIndex);
                    short userActionIndex;
                    string userAction;

                    do {
                        mainScreenReset();
                        printField(fieald, 3);
                        cout << endl;
                        cout << "\t  \033[32mВиберіть яке число поставити на пусте місце (якщо хочете закінчити перемішування то напишіть - stop): \033[0m";
                        cin >> userAction;

                        if (userAction == "stop") break;

                        if (userAction != "1" && userAction != "2" && userAction != "3" && userAction != "4" && userAction != "5" && userAction != "6" && userAction != "7" && userAction != "8")
                        {
                            cout << "\t\t\t\t\t\t\033[31mВиберіть існуюче число!\033[0m";
                            Sleep(2000);
                            continue;
                        }

                        userAction += " ";

                        for (short i = 0; i < 9; i++) {
                            if (fieald.slot[i] == userAction)
                            {
                                userActionIndex = i;
                                break;
                            }
                        }

                        bool breakActive = false;

                        for (short i = 0; i < waysCount; i++) {
                            if (possibleWays[i] == userActionIndex)
                            {
                                breakActive = true;
                                break;
                            }
                        }
                        if (breakActive) break;
                        cout << "\t\t\t\t\033[31mВведіть число котре поручь з пустою клітинкою!\033[0m";
                        Sleep(2000);
                    } while (true);

                    if (userAction == "stop") break;

                    swap(fieald.slot[userActionIndex], fieald.slot[emptyIndex]);
                    if (playMode == 2)
                    {
                        actionsSave.push_back(emptyIndex);
                        actionsCount++;
                    }
                }

            }

            else
            {
                short randomShuffleCount = rand() % 45 + 41;

                short emptyIndex;
                short waysCount;
                short* possibleWays;
                short pcActionIndex;
                short noRepeatSave = 0;

                fieald.slot[0] = "1 ";
                fieald.slot[1] = "2 ";
                fieald.slot[2] = "3 ";
                fieald.slot[3] = "4 ";
                fieald.slot[4] = "5 ";
                fieald.slot[5] = "6 ";
                fieald.slot[6] = "7 ";
                fieald.slot[7] = "8 ";
                fieald.slot[8] = "  ";

                for (short i = 0; i < randomShuffleCount; i++) {
                    possibleWays = getPossibleWays(fieald, 9, 3, waysCount, emptyIndex);
                    possibleWays = deleteObject(possibleWays, waysCount, noRepeatSave);
                    pcActionIndex = possibleWays[rand() % waysCount];

                    mainScreenReset();
                    printField(fieald, 3);

                    swap(fieald.slot[pcActionIndex], fieald.slot[emptyIndex]);

                    if (playMode == 2)
                    {
                        actionsSave.push_back(emptyIndex);
                        actionsCount++;
                    }

                    noRepeatSave = emptyIndex;

                    Sleep(100);
                }
            }

            cout << "\n\t\t\t\t\t      \033[33mГра починається!\033[0m\n";
            Sleep(2000);

            if (playMode == 1)
            {
                startPlayTime = chrono::steady_clock::now();
                while (!getWinCheck(fieald, 3)) {
                    short emptyIndex;
                    short waysCount;
                    short* possibleWays = getPossibleWays(fieald, 9, 3, waysCount, emptyIndex);
                    short userActionIndex;
                    string userAction;

                    do {
                        mainScreenReset();
                        printField(fieald, 3);
                        cout << endl;
                        cout << "\t\t\t\t\033[32mВиберіть яке число поставити на пусте місце: \033[0m";
                        cin >> userAction;

                        if (userAction != "1" && userAction != "2" && userAction != "3" && userAction != "4" && userAction != "5" && userAction != "6" && userAction != "7" && userAction != "8")
                        {
                            cout << "\t\t\t\t\t    \033[31mВиберіть існуюче число!\033[0m";
                            Sleep(2000);
                            continue;
                        }

                        userAction += " ";

                        for (short i = 0; i < 9; i++) {
                            if (fieald.slot[i] == userAction)
                            {
                                userActionIndex = i;
                                break;
                            }
                        }

                        bool breakActive = false;

                        for (short i = 0; i < waysCount; i++) {
                            if (possibleWays[i] == userActionIndex)
                            {
                                breakActive = true;
                                break;
                            }
                        }
                        if (breakActive) break;
                        cout << "\t\t\t\t\033[31mВведіть число котре поручь з пустою клітинкою!\033[0m";
                        Sleep(2000);
                    } while (true);

                    swap(fieald.slot[userActionIndex], fieald.slot[emptyIndex]);
                    numberOfPermutations++;
                }

                mainScreenReset();
                printField(fieald, 3);
                cout << "\t\t\t\t\t\tВи перемогли!\n\n\n";
                endPlayTime = chrono::steady_clock::now();
                chrono::duration<double> elapsedPlayer = endPlayTime - startPlayTime;
                playTime = elapsedPlayer.count();
            }

            else
            {
                startPlayTime = chrono::steady_clock::now();
                short emptyIndex;
                for (short i = actionsCount - 1; i != -1; i--) {
                    mainScreenReset();
                    printField(fieald, 3);

                    cout << "\t\t\t\t\t     \033[35mКомп'ютер робить хід";
                    for (short j = 0; j < 3; j++) { Sleep(250); cout << " ."; }
                    Sleep(250);
                    cout << endl;

                    for (short j = 0; j < 9; j++) {
                        if (fieald.slot[j] == "  ")
                        {
                            emptyIndex = j;
                            break;
                        }
                    }

                    swap(fieald.slot[actionsSave[i]], fieald.slot[emptyIndex]);
                    numberOfPermutations++;
                    if (getWinCheck(fieald, 3)) break;
                }

                mainScreenReset();
                printField(fieald, 3);
                cout << "\t\t\t\t\t     \033[0m\033[33mКомп'ютер переміг!\033[0m\n\n\n";
                endPlayTime = chrono::steady_clock::now();
                chrono::duration<double> elapsedPlayer = endPlayTime - startPlayTime;
                playTime = elapsedPlayer.count();
            }

            delete[] fieald.slot;
        }

        else
        {
            fieald.slot = new string[16];

            if (mixingSpotsMode == 1)
            {
                fieald.slot[0] = " 1";
                fieald.slot[1] = " 2";
                fieald.slot[2] = " 3";
                fieald.slot[3] = " 4";
                fieald.slot[4] = " 5";
                fieald.slot[5] = " 6";
                fieald.slot[6] = " 7";
                fieald.slot[7] = " 8";
                fieald.slot[8] = " 9";
                fieald.slot[9] = "10";
                fieald.slot[10] = "11";
                fieald.slot[11] = "12";
                fieald.slot[12] = "13";
                fieald.slot[13] = "14";
                fieald.slot[14] = "15";
                fieald.slot[15] = "  ";

                mainScreenReset();
                printField(fieald, 4);

                while (true) {
                    short emptyIndex;
                    short waysCount;
                    short* possibleWays = getPossibleWays(fieald, 16, 4, waysCount, emptyIndex);
                    short userActionIndex;
                    string userAction;

                    do {
                        mainScreenReset();
                        printField(fieald, 4);
                        cout << endl;
                        cout << "\t  \033[32mВиберіть яке число поставити на пусте місце (якщо хочете закінчити перемішування то напишіть - stop): \033[0m";
                        cin >> userAction;

                        if (userAction == "stop") break;

                        if (userAction != "1" && userAction != "2" && userAction != "3" && userAction != "4" && userAction != "5" && userAction != "6" && userAction != "7" && userAction != "8" && userAction != "9" && userAction != "10" && userAction != "11" && userAction != "12" && userAction != "13" && userAction != "14" && userAction != "15")
                        {
                            cout << "\t\t\t\t\t\t\033[31mВиберіть існуюче число!\033[0m";
                            Sleep(2000);
                            continue;
                        }

                        if (userAction == "1" || userAction == "2" || userAction == "3" || userAction == "4" || userAction == "5" || userAction == "6" || userAction == "7" || userAction == "8" || userAction == "9")
                        {
                            userAction = " " + userAction;
                        }

                        for (short i = 0; i < 16; i++) {
                            if (fieald.slot[i] == userAction)
                            {
                                userActionIndex = i;
                                break;
                            }
                        }

                        bool breakActive = false;

                        for (short i = 0; i < waysCount; i++) {
                            if (possibleWays[i] == userActionIndex)
                            {
                                breakActive = true;
                                break;
                            }
                        }
                        if (breakActive) break;
                        cout << "\t\t\t\t\033[31mВведіть число котре поручь з пустою клітинкою!\033[0m";
                        Sleep(2000);
                    } while (true);

                    if (userAction == "stop") break;

                    swap(fieald.slot[userActionIndex], fieald.slot[emptyIndex]);
                    if (playMode == 2)
                    {
                        actionsSave.push_back(emptyIndex);
                        actionsCount++;
                    }
                }

            }

            else
            {
                short randomShuffleCount = rand() % 101 + 205;

                short emptyIndex;
                short waysCount;
                short* possibleWays = getPossibleWays(fieald, 16, 4, waysCount, emptyIndex);
                short pcActionIndex;
                short noRepeatSave = 0;

                fieald.slot[0] = " 1";
                fieald.slot[1] = " 2";
                fieald.slot[2] = " 3";
                fieald.slot[3] = " 4";
                fieald.slot[4] = " 5";
                fieald.slot[5] = " 6";
                fieald.slot[6] = " 7";
                fieald.slot[7] = " 8";
                fieald.slot[8] = " 9";
                fieald.slot[9] = "10";
                fieald.slot[10] = "11";
                fieald.slot[11] = "12";
                fieald.slot[12] = "13";
                fieald.slot[13] = "14";
                fieald.slot[14] = "15";
                fieald.slot[15] = "  ";

                for (short i = 0; i < randomShuffleCount; i++) {
                    possibleWays = getPossibleWays(fieald, 16, 4, waysCount, emptyIndex);
                    possibleWays = deleteObject(possibleWays, waysCount, noRepeatSave);
                    pcActionIndex = possibleWays[rand() % waysCount];

                    mainScreenReset();
                    printField(fieald, 4);

                    swap(fieald.slot[pcActionIndex], fieald.slot[emptyIndex]);
                    if (playMode == 2)
                    {
                        actionsSave.push_back(emptyIndex);
                        actionsCount++;
                    }

                    noRepeatSave = emptyIndex;

                    Sleep(100);
                }
            }

            cout << "\n\t\t\t\t\t        \033[33mГра починається!\033[0m\n";
            Sleep(2000);

            if (playMode == 1)
            {
                startPlayTime = chrono::steady_clock::now();
                while (!getWinCheck(fieald, 4)) {
                    short emptyIndex = 0;
                    short waysCount = 0;
                    short* possibleWays = getPossibleWays(fieald, 16, 4, waysCount, emptyIndex);
                    short userActionIndex = 0;
                    string userAction;

                    do {
                        mainScreenReset();
                        printField(fieald, 4);
                        cout << endl;
                        cout << "\t\t\t\t\033[32mВиберіть яке число поставити на пусте місце: \033[0m";
                        cin >> userAction;

                        if (userAction != "1" && userAction != "2" && userAction != "3" && userAction != "4" && userAction != "5" && userAction != "6" && userAction != "7" && userAction != "8" && userAction != "9" && userAction != "10" && userAction != "11" && userAction != "12" && userAction != "13" && userAction != "14" && userAction != "15")
                        {
                            cout << "\t\t\t\t\t    \033[31mВиберіть існуюче число!\0330m";
                            Sleep(2000);
                            continue;
                        }

                        if (userAction == "1" || userAction == "2" || userAction == "3" || userAction == "4" || userAction == "5" || userAction == "6" || userAction == "7" || userAction == "8" || userAction == "9")
                        {
                            userAction = " " + userAction;
                        }

                        for (short i = 0; i < 16; i++) {
                            if (fieald.slot[i] == userAction)
                            {
                                userActionIndex = i;
                                break;
                            }
                        }

                        bool breakActive = false;
                        for (short i = 0; i < waysCount; i++) {
                            if (possibleWays[i] == userActionIndex)
                            {
                                breakActive = true;
                                break;
                            }
                        }
                        if (breakActive) break;
                        cout << "\t\t\t\t\033[31mВведіть число котре поручь з пустою клітинкою!\033[0m";
                        Sleep(2000);
                    } while (true);

                    swap(fieald.slot[userActionIndex], fieald.slot[emptyIndex]);
                    numberOfPermutations++;
                }

                mainScreenReset();
                printField(fieald, 4);
                cout << "\t\t\t\t\t\t \033[33mВи перемогли!\033[0m\n\n\n";
                endPlayTime = chrono::steady_clock::now();
                chrono::duration<double> elapsedPlayer = endPlayTime - startPlayTime;
                playTime = elapsedPlayer.count();
            }

            else
            {
                startPlayTime = chrono::steady_clock::now();
                short emptyIndex;
                for (short i = actionsCount - 1; i != -1; i--) {
                    mainScreenReset();
                    printField(fieald, 4);

                    cout << "\t\t\t\t\t     \033[35mКомп'ютер робить хід\033[0m";
                    for (short j = 0; j < 3; j++) { Sleep(250); cout << " ."; }
                    Sleep(250);
                    cout << endl;

                    for (short j = 0; j < 16; j++) {
                        if (fieald.slot[j] == "  ")
                        {
                            emptyIndex = j;
                            break;
                        }
                    }

                    swap(fieald.slot[actionsSave[i]], fieald.slot[emptyIndex]);
                    numberOfPermutations++;
                    if (getWinCheck(fieald, 4)) break;
                }

                mainScreenReset();
                printField(fieald, 4);
                cout << "\t\t\t\t\t     \033[0m\033[33mКомп'ютер переміг!\033[0m\n\n\n";
                endPlayTime = chrono::steady_clock::now();
                chrono::duration<double> elapsedPlayer = endPlayTime - startPlayTime;
                playTime = elapsedPlayer.count();
            }

            delete[] fieald.slot;
        }

        string fileName = "GameStats.txt";

        addGameData(fileName, round(playTime * 100.0) / 100.0, numberOfPermutations);

        cout << "\t\t\t\t\t     \033[36m Статистика цієї гри:\n" << "\t\t\t      Кількість часу, витрачено на збирання п’ятнашок: " << round(playTime * 100.0) / 100.0 << " сек..\n\t\t\t      Кількість перестановок п’ятнашок для збору: " << numberOfPermutations << "\n\033[0m\n";

        short userChoice;
        Sleep(5000);
        
        do {
            mainScreenReset();
            cout << endl;
            cout << "\033[32m\t\t\t     Якщо ви хочете зіграти ще раз напишіть - 1, якщо ні то 2: \033[0m";
            cin >> userChoice;
            if (userChoice == 1 || userChoice == 2) break;
            cout << "\033\n[31m\t\t\t\t\t         Введіть 1 або 2!\033[0m";
            Sleep(2000);
        } while (true);
        if (userChoice == 2) break;
    }

    return 0;
}