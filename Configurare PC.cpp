#include "echipament_electronic.h"
#include<iostream>
#include<string>

int main() {
    float pret;
    std::string nume;
    std::string tip;
    std::string socket;
    int frecventa;
    float memorie_Stocare;
    int memorie_GPU;
    std::string nume_cpu, nume_gpu, nume_stocare, nume_placadebaza;
    int valoare;

    Placa_baza placa_baza();
    CPU cpu();
    GPU gpu();
    Stocare stocare();
    Manager manager;
    PC pc;


    int x;

    while (1)
    {

         std::cout<<"Meniu:"<<std::endl;
         std::cout<<"Apasati tasta 1 pentru citire componente"<<std::endl;
         std::cout<<"Apasati tasta 2 pentru afisare componente"<<std::endl;
         std::cout<<"Apasati tasta 3 pentru configurare PC"<<std::endl;
         std::cout<<"Apasati tasta 4 pentru configurare PC pentru un buget anume"<<std::endl;
         std::cout<<"Apasati tasta 5 pentru afisare componente PC"<<std::endl;

        std::cin >> x;

        switch (x)
        {
        case 1:
             std::cout<<"Pretul componentei este:";
            std::cin >> pret;
             std::cout<<"Numele componentei este:";
            std::getline(std::cin >> std::ws, nume);
             std::cout<<"Tipul componentei este:(placa_baza, cpu, gpu, stocare)";
            std::getline(std::cin >> std::ws, tip);

            if (tip == "placa_baza")
            {
                 std::cout<<"Socket-ul componentei este:";
                std::getline(std::cin >> std::ws, socket);
                Placa_baza placa_baza(pret, nume, tip, socket);
                manager.adaugare_placa_baza(placa_baza);
            }

            else if (tip == "cpu")
            {
                 std::cout<<"Socket-ul componentei este:";
                std::getline(std::cin >> std::ws, socket);
                 std::cout<<"Frecventa componentei este:";
                std::cin >> frecventa;
                CPU cpu(pret, nume, tip, socket, frecventa);
                manager.adaugare_cpu(cpu);
            }

            else if (tip == "gpu")
            {
                 std::cout<<"Memoria componentei este:";
                std::cin >> memorie_GPU;
                GPU gpu(pret, nume, tip, memorie_GPU);
                manager.adaugare_gpu(gpu);
            }

            else if (tip == "stocare")
            {
                 std::cout<<"Memoria componentei este:";
                std::cin >> memorie_Stocare;
                Stocare stocare(pret, nume, tip, memorie_Stocare);
                manager.adaugare_stocare(stocare);
            }
            else
            {
                std::cout << "Nu exista acest tip de componenta!\n";
            }


            break;

        case 2:
            manager.afisare();

            break;

        case 3:
             std::cout<<"Configurare PC:\nIntrodu componentele din lista de componente:\nNume cpu:";
            std::getline(std::cin >> std::ws, nume_cpu);

            while (manager.verificare_cpu(nume_cpu) == 0)
            {
                 std::cout<<"Nu avem aceasta componenta in stoc. Introdu alta componenta cpu:";
                std::getline(std::cin >> std::ws, nume_cpu);
            }

            std::cout<<"\nNume gpu:";
            std::getline(std::cin >> std::ws, nume_gpu);

            while (manager.verificare_gpu(nume_gpu) == 0)
            {
                std::cout << "Nu avem aceasta componenta in stoc. Introdu alta componenta gpu:";
                std::getline(std::cin >> std::ws, nume_gpu);
            }

            std::cout<<"\nNume stocare:";
            std::getline(std::cin >> std::ws, nume_stocare);

            while (manager.verificare_stocare(nume_stocare) == 0)
            {
                std::cout<<"Nu avem aceasta componenta in stoc. Introdu alta componenta stocare:";
                std::getline(std::cin >> std::ws, nume_stocare);
            }

            pc.adaugare(manager.pb(nume_placadebaza), manager.cp(nume_cpu), manager.gp(nume_gpu), manager.st(nume_stocare));

            pc.afisare();
            std::cout << manager.pb(nume_placadebaza).get_pret() + manager.cp(nume_cpu).get_pret() + manager.gp(nume_gpu).get_pret() + manager.st(nume_stocare).get_pret() << "\n";


            break;

        case 4:
            std::cout << "Introdu bugetul pe care il ai la dispozitie si iti vom configura PC-ul dupa cele mai bune posibilitati:";
            std::cin >> valoare;
            std::cout << "\n";
            pc = manager.buget();

            manager.sortare();
            pc = manager.configurare(valoare);
            pc.afisare();

            break;

        case 5:
            exit(1);
        }


    }

    return 0;
}