#include "echipament_electronic.h"
#include<iostream>
#include<algorithm>
#include<vector>

Echipament_electronic::Echipament_electronic(float pret = 0, std::string nume = "", std::string tip = "") :pret(pret), nume(nume), tip(tip) {}

float Echipament_electronic::get_pret() { return pret; }

std::string Echipament_electronic::get_nume() { return nume; }

std::string Echipament_electronic::get_tip() { return tip; }


Placa_baza::Placa_baza(float pret = 0, std::string nume = "", std::string tip = "", std::string socket = "") :Echipament_electronic(pret, nume, tip), socket(socket) {}

std::string Placa_baza::get_socket() { return socket; }

void Placa_baza::afisare() { std::cout << tip << ", " << nume << ", " << socket << ", " << pret << "\n"; }

float Placa_baza::raport_calitate_pret() { return pret; }



CPU::CPU(float pret = 0, std::string nume = "", std::string tip = "", std::string socket = "", int frecventa = 0) :Echipament_electronic(pret, nume, tip), socket(socket), frecventa(frecventa) {}

std::string CPU::get_socket() { return socket; }

int CPU::get_frecventa() { return frecventa; }

void CPU::afisare() { std::cout << tip << ", " << nume << ", " << socket << ", " << frecventa << ", " << pret << "\n"; }

float CPU::raport_calitate_pret() { return pret / frecventa; }


GPU::GPU(float pret = 0, std::string nume = "", std::string tip = "", int memorie = 0) :Echipament_electronic(pret, nume, tip), memorie(memorie) {}

int GPU::get_memorie() { return memorie; }

void GPU::afisare() { std::cout << tip << ", " << nume << ", " << memorie << ", " << pret << "\n"; }

float GPU::raport_calitate_pret() { return pret / memorie; }


Stocare::Stocare(float pret = 0, std::string nume = "", std::string tip = "", float memorie = 0) :Echipament_electronic(pret, nume, tip), memorie(memorie) {}

float Stocare::get_memorie() { return memorie; }

void Stocare::afisare() { std::cout << tip << ", " << nume << ", " << memorie << ", " << pret << "\n"; }

float Stocare::raport_calitate_pret() { return pret / memorie; }


PC::PC() {}

//PC::PC(Placa_baza placa_baza,CPU cpu, GPU gpu, Stocare stocare):placa_baza(placa_baza),cpu(cpu),gpu(gpu),stocare(stocare){};

void PC::adaugare(Placa_baza placa_baza, CPU cpu, GPU gpu, Stocare stocare)
{
    this->placa_baza = placa_baza;
    this->cpu = cpu;
    this->gpu = gpu;
    this->stocare = stocare;
}

void PC::setter_placa_baza(Placa_baza placa_baza) { this->placa_baza = placa_baza; };
void PC::setter_cpu(CPU cpu) { this->cpu = cpu; };
void PC::setter_gpu(GPU gpu) { this->gpu = gpu; };
void PC::setter_stocare(Stocare stocare) { this->stocare = stocare; };




void PC::afisare()
{
    placa_baza.afisare();
    cpu.afisare();
    gpu.afisare();
    stocare.afisare();

    /*
    std::cout<<placa_baza.get_tip()<<", "<<placa_baza.get_nume()<<", "<<placa_baza.get_socket()<<", "<<placa_baza.get_pret()<<std::endl;
    std::cout<<cpu.get_tip()<<", "<<cpu.get_nume()<<", "<<cpu.get_socket()<<", "<<cpu.get_pret()<<std::endl;
    std::cout<<gpu.get_tip()<<", "<<gpu.get_nume()<<", "<<gpu.get_memorie()<<", "<<gpu.get_pret()<<std::endl;
    std::cout<<stocare.get_tip()<<", "<<stocare.get_nume()<<", "<<stocare.get_memorie()<<", "<<stocare.get_pret()<<std::endl;
    */
}



Manager::Manager() {}

void Manager::adaugare_placa_baza(Placa_baza placa_baza)
{
    this->placa_baza = placa_baza;
}

void Manager::adaugare_cpu(CPU cpu)
{
    this->cpu[nr_cpu] = cpu;
    nr_cpu++;
}

void Manager::adaugare_gpu(GPU gpu)
{
    this->gpu[nr_gpu] = gpu;
    nr_gpu++;
}

void Manager::adaugare_stocare(Stocare stocare)
{
    this->stocare[nr_stocare] = stocare;
    nr_stocare++;
}

void Manager::afisare()
{

    placa_baza.afisare();

    for (int i = 0; i < nr_cpu; i++)
    {
        cpu[i].afisare();
    }

    for (int i = 0; i < nr_gpu; i++)
    {
        gpu[i].afisare();
    }

    for (int i = 0; i < nr_stocare; i++)
    {
        stocare[i].afisare();
    }

}

bool Manager::verificare_cpu(std::string nume_cpu)
{
    for (int i = 0; i < nr_cpu; i++)
        if (cpu[i].get_nume() == nume_cpu)
            return 1;

    return 0;
}

bool Manager::verificare_gpu(std::string nume_gpu)
{
    for (int i = 0; i < nr_gpu; i++)
        if (gpu[i].get_nume() == nume_gpu)
            return 1;

    return 0;
}

bool Manager::verificare_stocare(std::string nume_stocare)
{
    for (int i = 0; i < nr_stocare; i++)
        if (stocare[i].get_nume() == nume_stocare)
            return 1;

    return 0;
}

Placa_baza Manager::pb(std::string nume_placa_baza)
{
    return this->placa_baza;
}

CPU Manager::cp(std::string nume_cpu)
{
    for (int i = 0; i < nr_cpu; i++)
        if (cpu[i].get_nume() == nume_cpu)
            return cpu[i];

    return 0;
}

GPU Manager::gp(std::string nume_gpu)
{
    for (int i = 0; i < nr_gpu; i++)
        if (gpu[i].get_nume() == nume_gpu)
            return gpu[i];

    return 0;
}

Stocare Manager::st(std::string nume_stocare)
{
    for (int i = 0; i < nr_stocare; i++)
        if (stocare[i].get_nume() == nume_stocare)
            return stocare[i];

    return 0;
}

bool sort_calitate_pret(Echipament_electronic& e1, Echipament_electronic& e2) {
    return e1.raport_calitate_pret() < e2.raport_calitate_pret();
}

bool sort_buget(Echipament_electronic& e1, Echipament_electronic& e2) {
    return e1.get_pret() < e2.get_pret();
}



void Manager::sortare()
{
    std::sort(cpu, cpu + nr_cpu, sort_calitate_pret);
    std::sort(gpu, gpu + nr_gpu, sort_calitate_pret);
    std::sort(stocare, stocare + nr_stocare, sort_calitate_pret);
}

PC Manager::buget()
{
    std::sort(cpu, cpu + nr_cpu, sort_buget);
    std::sort(gpu, gpu + nr_gpu, sort_buget);
    std::sort(stocare, stocare + nr_stocare, sort_buget);

    pc.adaugare(placa_baza, cpu[0], gpu[0], stocare[0]);

    return pc;
}

PC Manager::configurare(int buget)
{
    int suma = placa_baza.get_pret();

    if (suma < buget)
        pc.setter_gpu(gpu[0]);
    else
        return pc;

    for (int i = 0; i < nr_cpu; i++)
    {
        if (suma < buget && cpu[i].get_socket() == placa_baza.get_socket())
            pc.setter_cpu(cpu[i]);
    }

    if (suma < buget)
        pc.setter_stocare(stocare[0]);


    return pc;
}

