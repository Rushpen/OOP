using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Gadelshin_Lab5
{
    class Program
    {
        static void do_command(uint choice, Gadelshin_Staff staff)
        {
            if (choice == 1)
            {
                Gadelshin_Employee employee = new Gadelshin_Employee();
                employee.Add_employee();
                staff.Add_employee_to_list(employee);
            }
            else if (choice == 2)
            {
                Gadelshin_Manager manager = new Gadelshin_Manager();
                manager.Add_employee();
                staff.Add_employee_to_list(manager);
            }
            else if(choice == 3) {
                staff.Print_data(); 
            }
            else if(choice == 4) {
                staff.DeserializeData(); 
            }
            else if(choice == 5) {
                staff.SerializeData(); 
            }
            else if(choice == 6) {
                staff.Clear_employes(); 
            }
        }

        static void Main(string[] args)
        {
            Gadelshin_Staff staff = new Gadelshin_Staff();
            uint choice = 0;

            while (true)
            {
                Console.WriteLine("\n1: Добавить работника");
                Console.WriteLine("2: Добавить менеджера");
                Console.WriteLine("3: Вывести всех работников");
                Console.WriteLine("4: Загрузить из файла");
                Console.WriteLine("5: Загрузить в файл");
                Console.WriteLine("6: Очистить всех работникв");
                Console.WriteLine("0: Выход\n");

                choice = Utils.check_value(0, 6);
                if (choice == 0)
                    break;
                do_command(choice, staff);
            }
        }
    }
}
