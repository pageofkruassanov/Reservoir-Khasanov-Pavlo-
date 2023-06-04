#include "includes.h"

int Reservoir::sizeStr = 50;

int main()
{
    Reservoir* res = nullptr;
    int sizeRes = 0;
    bool menu = true;
    int button = 0;

    FILE* f = nullptr;
    fopen_s(&f, "reservoir.bin", "rb");
    if (f != nullptr) {
        fread(&sizeRes, sizeof(int), 1, f);
        res = new Reservoir[sizeRes];

        double buff;
        char* buffStr = new char[Reservoir::getSizeStr()];
        for (int i = 0; i < sizeRes; i++) {

            fread(&buff, sizeof(double), 1, f);
            res[i].setWidth(buff);

            fread(&buff, sizeof(double), 1, f);
            res[i].setLength(buff);

            fread(&buff, sizeof(double), 1, f);
            res[i].setDepth(buff);

            fread(buffStr, 50, 1, f);
            res[i].setName(buffStr);

            fread(buffStr, 50, 1, f);
            res[i].setType(buffStr);
        }
        delete[] buffStr;
        fclose(f);
    }
    while (menu) {
        displayMenu(button);
        if (moveMenu(button)) {
            switch (button) {
            case ADD:
            {
                system("cls");
                sizeRes++;
                Reservoir* tempRes = new Reservoir[sizeRes];
                for (int i = 0; i < sizeRes - 1; i++) {
                    tempRes[i].setWidth(res[i].getWidth());
                    tempRes[i].setLength(res[i].getLength());
                    tempRes[i].setDepth(res[i].getDepth());
                    tempRes[i].setName(res[i].getName());
                    tempRes[i].setType(res[i].getType());
                }
                int width, length, depth;
                char name[40];
                char type[40];
                cout << "Set the width of the reservoir: ";
                cin >> width;
                cout << endl << "Set the length of the reservoir: ";
                cin >> length;
                cout << endl << "Set the depth of the reservoir: ";
                cin >> depth;
                cout << endl << "Enter the name of the reservoir: ";
#undef max
                if (cin.rdbuf()->in_avail() > 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.getline(name, 40);
                cout << endl << "Enter the type of the reservoir: ";
                if (cin.rdbuf()->in_avail() > 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.getline(type, 40);

                tempRes[sizeRes - 1].setWidth(width);
                tempRes[sizeRes - 1].setLength(length);
                tempRes[sizeRes - 1].setDepth(depth);
                tempRes[sizeRes - 1].setName(name);
                tempRes[sizeRes - 1].setType(type);

                delete[] res;
                res = tempRes;

                cout << endl << endl << "COMPLETE! Reservoir is added." << endl;
                system("pause");
                break;
            }
#undef DELETE
            case DELETE:
            {
                system("cls");
                int index;
                cout << "Enter reservoir number: ";
                cin >> index;
                if (index < 1 || index > sizeRes) {
                    cout << endl << endl << "Error numbers" << endl;
                    system("pause");
                    break;
                }
                else {
                    index--;
                    sizeRes--;
                    Reservoir* tempRes = new Reservoir[sizeRes];
                    for (int i = 0; i < sizeRes; i++) {
                        if (index < i) {
                            tempRes[i].setWidth(res->getWidth());
                            tempRes[i].setLength(res->getLength());
                            tempRes[i].setDepth(res->getDepth());
                            tempRes[i].setName(res->getName());
                            tempRes[i].setType(res->getType());
                        }
                        else {
                            tempRes[i].setWidth(res->getWidth());
                            tempRes[i].setLength(res->getLength());
                            tempRes[i].setDepth(res->getDepth());
                            tempRes[i].setName(res->getName());
                            tempRes[i].setType(res->getType());
                        }
                    }
                    delete[] res;
                    res = tempRes;
                }
                cout << endl << endl << "Reservoir is deleted!" << endl;
                system("pause");
                break;
            }
            case DISPLAY:
            {
                system("cls");
                for (int i = 0; i < sizeRes; i++) {
                    cout << "Reservoir #" << i + 1 << endl;
                    cout << "Name: " << res[i].getName() << endl;
                    cout << "Type: " << res[i].getType() << endl;
                    cout << "Width: " << res[i].getWidth() << endl;
                    cout << "Length: " << res[i].getLength() << endl;
                    cout << "Depth: " << res[i].getDepth() << endl << endl;
                }
                cout << endl;
                system("pause");
                break;
            }
            case SAVE:
            {
                system("cls");
                if (sizeRes > 0) {
                    FILE* f = nullptr;
                    fopen_s(&f, "reservoir.bin", "wb");
                    fwrite(&sizeRes, sizeof(int), 1, f);
                    int sizeStr = Reservoir::getSizeStr();
                    char* buffStr = new char[sizeStr];
                    for (int i = 0; i < sizeRes; i++) {

                        double buff = res[i].getWidth();
                        fwrite(&buff, sizeof(double), 1, f);

                        buff = res[i].getLength();
                        fwrite(&buff, sizeof(double), 1, f);

                        buff = res[i].getDepth();
                        fwrite(&buff, sizeof(double), 1, f);

                        buffStr = res[i].getName();
                        fwrite(buffStr, 50, 1, f);

                        buffStr = res[i].getType();
                        fwrite(buffStr, 50, 1, f);

                    }
                    delete[] buffStr;
                    fclose(f);
                    cout << "Data save" << endl;
                }
                else {
                    cout << "Error data" << endl;
                }
                cout << endl;
                system("pause");
                break;
            }
            case EXIT:
            {
                menu = false;
                cout << endl;
                system("pause");
                break;
            }
            }
        }
        system("cls");
    }
}

