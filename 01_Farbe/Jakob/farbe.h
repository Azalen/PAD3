#ifndef FARBE_H
#define FARBE_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Farbe
{
private:
    string name;
    unsigned short rot;
    unsigned short gruen;
    unsigned short blau;
    unsigned short transparenz;

    //sizeof(int) liefert 4 Byte zurück
    unsigned int rgba;
public:

    static const Farbe SCHWARZ;
    static const Farbe WEIß;
    static const Farbe ROT;
    static const Farbe GRUEN;
    static const Farbe BLAU;
    static const Farbe GRAUTON;
    static const short MAX = 255;
    static const short MIN = 0;

    // Default Konstruktor
    Farbe() {
        name = "";
        rot = MIN;
        gruen = MIN;
        blau = MIN;
        transparenz = MAX;
    }
    // Konstruktor mit Parametern
    Farbe(const string & p_name, unsigned short p_rot,unsigned short p_gruen,unsigned short p_blau) {

        name = p_name;

        if((p_rot >= MIN && p_rot <= MAX) && (p_gruen >= MIN && p_gruen <= MAX) && (p_blau >= MIN && p_blau <= MAX)) {
            rot = p_rot;
            gruen = p_gruen;
            blau = p_blau;
            transparenz = MAX;


        } else {
            throw invalid_argument("Keine gueltige Eingabe");
        }
    }

    Farbe(unsigned int x) {

        blau = x % 256;
        gruen = x / 256 % 256;
        rot = x / 65536 % 256;
        transparenz = x / 16777216 % 256;

    }

    friend std::ostream & operator<<(std::ostream & ausgabe, const Farbe & f);

    void eingabe() {
        string tmp;
        cout << "Farbe: ";
        cin >> tmp;
        name = tmp;

        cout << "(0 - 255) " << endl << endl;

        //Rot
        bool running = true;

        do {

            int temp;

            cout << "Rot: ";
            cin >> temp;

            if(temp >= 0 && temp <= 255) {
                rot = temp;
                running = false;
            } else {
                cout << " Error " << endl;
            }

        } while(running);

        //Gruen
        running = true;

        do {

            int temp;

            cout << "Gruen: ";
            cin >> temp;

            if(temp >= 0 && temp <= 255) {
                gruen = temp;
                running = false;
            } else {
                cout << " Error " << endl;
            }

        } while(running);

        //Blau
        running = true;

        do {

            int temp;

            cout << "Blau: ";
            cin >> temp;

            if(temp >= 0 && temp <= 255) {
                blau = temp;
                running = false;
            } else {
                cout << " Error " << endl;
            }

        } while(running);


        //Transparenz
        running = true;

        do {

            int temp;

            cout << "Transparenz: ";
            cin >> temp;

            if(temp >= 0 && temp <= 255) {
                transparenz = temp;
                running = false;
            } else {
                cout << " Error " << endl;
            }

        } while(running);

    }

    int RGBA() {
        rgba = (transparenz*16777216) + (rot*65536) + (gruen*256) + blau;
        return rgba;
    }

    void ausgabe() const {
        cout << setw(10) <<name << " -> (" << setw(3) << rot << "," << setw(3) << gruen << "," << setw(3) << blau << ")"  << " | T = " << setw(3) << transparenz << endl;

    }

    static Farbe darker(Farbe & t) {
        Farbe x;
        x.name = t.name + "(dark)";
        x.rot = t.rot * 0.7;
        x.gruen = t.gruen * 0.7;
        x.blau = t.blau * 0.7;

        return x;
    }




    unsigned short getRot() const;
    void setRot(unsigned short value);
    unsigned short getGruen() const;
    void setGruen(unsigned short value);
    unsigned short getBlau() const;
    void setBlau(unsigned short value);
    unsigned short getTransparenz() const;
    void setTransparenz(unsigned short value);
    string getName() const;
    void setName(const string &value);
};

bool operator== (const Farbe & x, const Farbe & y);

#endif // FARBE_H
