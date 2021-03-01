// TestBDL1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string line;
class Item
{
    string name;
    int value;
public: void WriteAllInfo()
    {
        cout << "Item name: " << name << endl;
        cout << "         Item value: " << value << endl;
    }
      void Write(ofstream* wf)
      {
          *wf << "3" << endl;
          *wf << name << endl;
          *wf << value << endl;
      }
    Item()
    {
        name = "Default";
        value = 0;
    }
    Item(string n, int i)
    {
        name = n;
        value = i;
    }
};
class Character
{
    string name;
    int health;
    Item* items;
    int size;
public:
    void WriteAllInfo()
    {
        cout << "Character name: " << name << endl;
        cout << "     Character health: " << health << endl;
        cout << "     Items:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "       "<<i<<".";
            items[i].WriteAllInfo();
        }

    }
    void Write(ofstream* wf)
    {
        *wf << "2" << endl;
        *wf << name << endl;
        *wf << health << endl;
        for (int i = 0; i < size; i++)
        {
            items[i].Write(wf);
        }
    }
    void WriteCharacterInfo()
    {
        cout << "Character name: " << name << endl;
        cout << "Character health: " << health << endl;
    }
    void AddItem(Item itm)
    {
        Item* table = new Item[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = items[i];
        }
        size++;
        items = new Item[size];
        for (int i = 0; i < size - 1; i++)
        {
            items[i] = table[i];
        }
        items[size - 1] = itm;
    }
    void DeleteItem()
    {
        cout << "Choose item to delete" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << ". ";
            items[i].WriteAllInfo();
        }
        int input;
        cin >> input;
        if (input<0 || input>size)
        {
            cout << "Wrong input" << endl;
        }
        else
        {
            Item* table = new Item[size];
            for (int i = 0; i < size; i++)
            {
                table[i] = items[i];
            }
            size--;
            int t = 0;
            items = new Item[size];
            for (int i = 0; i < size + 1; i++)
            {
                if (i != input)
                    items[i - t] = table[i];
                else
                    t++;
            }
        }
    }
    Character()
    {
        name = "default name";
        size = 0;
    }
    Character(string n, int i, Item* itms,int s)
    {
        name = n;
        health = i;
        items = itms;
        size = s;
    }
};
class Hike
{
    string name;
    int length;
    Character *characters;
    int size;
public:
    void WriteAllInfo()
    {
        cout << "Hike name: " << name << endl;
        cout << "Hike length: " << length << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "   " << i << ".";
            characters[i].WriteAllInfo();
        }
    }
    void Write(ofstream* wf)
    {
        *wf << "1" << endl;
        *wf << name << endl;
        *wf << length << endl;
        for (int i = 0; i < size; i++)
        {
            characters[i].Write(wf);
        }
    }
    void WriteHikeInfo()
    {
        cout << "Hike name: " << name << endl;
        cout << "Hike length: " << length << endl;
    }
    void AddCharacter(Character chara)
    {
        Character* table = new Character[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = characters[i];
        }
        size++;
        characters = new Character[size];
        for (int i = 0; i < size - 1; i++)
        {
            characters[i] = table[i];
        }
        characters[size - 1] = chara;
    }
    void DeleteCharacter()
    {
        cout << "Choose character to delete" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << ". ";
            characters[i].WriteCharacterInfo();
        }
        int input;
        cin >> input;
        if (input<0 || input>size)
        {
            cout << "Wrong input" << endl;
        }
        else
        {
            Character* table = new Character[size];
            for (int i = 0; i < size; i++)
            {
                table[i] = characters[i];
            }
            size--;
            int t = 0;
            characters = new Character[size];
            for (int i = 0; i < size + 1; i++)
            {
                if (i != input)
                    characters[i - t] = table[i];
                else
                    t++;
            }
        }
    }
    Character* ChooseCharacter()
    {
        cout << "Choose character" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << ". ";
            characters[i].WriteCharacterInfo();
        }
        cout << size << ". Exit" << endl;
        int input;
        cin >> input;
        if (input<0 || input>size)
        {
            cout << "Wrong input" << endl;
        }
        else
        {
            if (input==size)
            {
                cout << "Exiting" << endl;
            }
            else
            {
                return &characters[input];
            }
        }
    }
    Hike()
    {
        name = "Default hike name";
        size = 0;
    }
    Hike(string n, int i, Character* chars,int s)
    {
        name = n;
        length = i;
        characters = chars;
        size = s;
    }
};
class File
{
    Hike* hikes;
    int size;
public:
    void WriteAllInfo()
    {
       
        for (int i = 0; i < size; i++)
        {
            cout << "Hike " << i << ":" << endl;
            hikes[i].WriteAllInfo();
        }

    }
    void Write(ofstream* wf)
    {
        for (int i = 0; i < size; i++)
        {
            hikes[i].Write(wf);
        }
        *wf << ";" << endl;
    }
    void AddHike(Hike hik)
    {
        Hike* table = new Hike[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = hikes[i];
        }
        size++;
        hikes = new Hike[size];
        for (int i = 0; i < size - 1; i++)
        {
            hikes[i] = table[i];
        }
        hikes[size - 1] = hik;
    }
    void DeleteHike()
    {
        cout << "Choose hike to delete" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << ". ";
            hikes[i].WriteHikeInfo();
        }
        int input;
        cin >> input;
        if (input<0 || input>size)
        {
            cout << "Wrong input" << endl;
        }
        else
        {
            Hike* table = new Hike[size];
            for (int i = 0; i < size; i++)
            {
                table[i] = hikes[i];
            }
            size--;
            int t = 0;
            hikes = new Hike[size];
            for (int i = 0; i < size + 1; i++)
            {
                if (i != input)
                    hikes[i - t] = table[i];
                else
                    t++;
            }
        }
       
   }
    Hike* ChooseHike()
    {
        cout << "Choose hike" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << ". ";
            hikes[i].WriteHikeInfo();
        }
        cout << size << ". Exit" << endl;
        int input;
        cin >> input;
        if (input<0 || input>size)
        {
            cout << "Wrong input" << endl;
        }
        else
        {
            if (input == size)
            {
                cout << "Exiting" << endl;
            }
            else
            {
                return &hikes[input];
            }
        }
    }
    File()
    {
        hikes = new Hike[0];
        size = 0;
    }
    File(Hike* hks, int s)
    {
        hikes = hks;
        size = s;
    }
};
Item ReadItem(ifstream* rf)
{
    getline(*rf, line);
    string name = line;
    getline(*rf, line);
    int value = stoi(line);
    return Item(name, value);
}
Character ReadCharacter(ifstream* rf)
{
    getline(*rf, line);
    string name = line;
    getline(*rf, line);
    int health = stoi(line);
    Item* items = new Item[0];
    int size = 0;
    Item* table;
    getline(*rf, line);
    while(stoi(line)==3)
    {
        table = new Item[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = items[i];
        }
        size++;
        items = new Item[size];
        if (size - 1 != 0)
        {
            for (int i = 0; i < size-1; i++)
            {
                items[i] = table[i];
            }
        }
        items[size-1] = ReadItem(rf);
        getline(*rf, line);
        if (line == ";")
            break;
    }
    return Character(name, health, items, size);
}
Hike ReadHike(ifstream* rf)
{
    getline(*rf, line);
    string name = line;
    getline(*rf, line);
    int length = stoi(line);
    Character* characters = new Character[0];
    int size = 0;
    Character* table;
    getline(*rf, line);
    while (stoi(line) == 2)
    {
        table = new Character[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = characters[i];
        }
        size++;
        characters = new Character[size];
        if (size - 1 != 0)
        {
            for (int i = 0; i < size-1; i++)
            {
                characters[i] = table[i];
            }
        }
        characters[size-1] = ReadCharacter(rf);
        if (line == ";")
            break;
    }
    return Hike(name, length, characters, size);
}
File ReadFile(ifstream* rf)
{
    Hike* hikes = new Hike[0];
    int size = 0;
    Hike* table;
    getline(*rf, line);
    while (stoi(line) == 1)
    {
        table = new Hike[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = hikes[i];
        }
        size++;
        hikes = new Hike[size];
        if (size - 1 != 0)
        {
            for (int i = 0; i < size - 1; i++)
            {
                hikes[i] = table[i];
            }
        }
        hikes[size - 1] = ReadHike(rf);
        if (line == ";")
            break;
    }
    return File(hikes, size);
}
Character EnterCharacterInfo()
{
    string name;
    int health;
    cout << "Enter character name" << endl;
    cin >> name;
    cout << "Enter character health" << endl;
    cin >> health;
    Item* startingItems = new Item[0];
    return Character(name, health, startingItems,0);
}
Item EnterItemInfo()
{
    string name;
    int value;
    cout << "Enter item name" << endl;
    cin >> name;
    cout << "Enter value health" << endl;
    cin >> value;
    return Item(name, value);
}
Hike EnterHikeInfo()
{
    string name;
    int length;
    cout << "Enter hike name" << endl;
    cin >> name;
    cout << "Enter hike length" << endl;
    cin >> length;
    Character* startingCharacters = new Character[0];
    return Hike(name, length, startingCharacters, 0);
}
int main()
{
    string name;
    int value;
    int ident;
    ofstream myfile;
    ifstream readFile;
    File file;
    Hike hike;
    Hike* hikePointer;
    Character character;
    Character* characterPointer;
    Item item;
    readFile.open("bd.txt");
    if (readFile.is_open())
    {
        file = ReadFile(&readFile);
         readFile.close();
    }
    int input;
    do
    {
        cin >> input;
        switch (input)
        {
        case (1):
        {
            file.WriteAllInfo();
            break;
        }
        case(2):
        {
            cout << "Enter Hike Name" << endl;
            cin >> name;
            cout << "Enter Hike Length" << endl;
            cin >> value;
            hike = Hike(name, value, new Character[0], 0);
            file.AddHike(hike);
            break;
        }
        case(3):
        {
            hikePointer = file.ChooseHike();
            cout << "Enter Character Name" << endl;
            cin >> name;
            cout << "Enter Character Health" << endl;
            cin >> value;
            character = Character(name, value, new Item[0], 0);
            hikePointer->AddCharacter(character);
            break;
        }
        case(4):
        {
            hikePointer = file.ChooseHike();
            characterPointer = hikePointer->ChooseCharacter();
            cout << "Enter Item Name" << endl;
            cin >> name;
            cout << "Enter Item Value" << endl;
            cin >> value;
            item = Item(name, value);
            characterPointer->AddItem(item);
            break;
        }
        case(5):
        {
            file.DeleteHike(); 
            break;
        }
        case(6):
        {
            hikePointer = file.ChooseHike();
            hikePointer->DeleteCharacter();
            break;
        }
        case(7):
        {
            hikePointer = file.ChooseHike();
            characterPointer = hikePointer->ChooseCharacter();
            characterPointer->DeleteItem();
            break;
        }
        case (9):
        {
            myfile.open("bd.txt");
            if (myfile.is_open())
            {
                file.Write(&myfile);
                }
            break;
        }
        default:
            break;
        }
    } while (input != 0);
    return 0;
}

