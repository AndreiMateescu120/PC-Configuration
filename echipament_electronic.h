#ifndef ECHIPAMENT_ELECTRONIC_H
#define ECHIPAMENT_ELECTRONIC_H

#include <string>

class Echipament_electronic {
protected:
    float pret;
    std::string nume;
    std::string tip;
public:
    Echipament_electronic(float, std::string, std::string);
    float get_pret();
    std::string get_nume();
    std::string get_tip();
    virtual void afisare() = 0;
    virtual float raport_calitate_pret() = 0;
};


class Placa_baza : public Echipament_electronic
{
private:
    std::string socket;

public:
    Placa_baza(float, std::string, std::string, std::string);

    std::string get_socket();
    void afisare();
    float raport_calitate_pret();
};


class CPU : public Echipament_electronic
{
private:
    std::string socket;
    int frecventa;
public:
    CPU(float, std::string, std::string, std::string, int);

    std::string get_socket();
    int get_frecventa();

    void afisare();
    float raport_calitate_pret();
};


class GPU : public Echipament_electronic
{
private:
    int memorie;

public:
    GPU(float, std::string, std::string, int);

    int get_memorie();
    void afisare();
    float raport_calitate_pret();
};


class Stocare : public Echipament_electronic
{
private:
    float memorie;

public:
    Stocare(float, std::string, std::string, float);

    float get_memorie();
    void afisare();
    float raport_calitate_pret();
};

class PC
{
private:
    Placa_baza placa_baza;
    CPU cpu;
    GPU gpu;
    Stocare stocare;

public:
    PC();
    void setter_placa_baza(Placa_baza);
    void setter_cpu(CPU);
    void setter_gpu(GPU);
    void setter_stocare(Stocare);
    void adaugare(Placa_baza, CPU, GPU, Stocare);
    void afisare();


};

class Manager
{
private:
    Placa_baza placa_baza;
    CPU cpu[10];
    GPU gpu[10];
    Stocare stocare[10];
    int nr_cpu = 0, nr_gpu = 0, nr_stocare = 0;
    PC pc;

public:

    Manager();
    void adaugare_placa_baza(Placa_baza);
    void adaugare_cpu(CPU);
    void adaugare_gpu(GPU);
    void adaugare_stocare(Stocare);

    bool verificare_cpu(std::string);
    bool verificare_gpu(std::string);
    bool verificare_stocare(std::string);

    Placa_baza pb(std::string);
    CPU cp(std::string);
    GPU gp(std::string);
    Stocare st(std::string);
    PC buget();
    PC configurare(int);


    void sortare();
    void afisare();
};

bool sort_calitate_pret(Echipament_electronic&, Echipament_electronic&);
bool sort_buget(Echipament_electronic&, Echipament_electronic&);










#endif