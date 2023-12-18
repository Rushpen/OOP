using System;

namespace Gadelshin_Lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Gadelshin_Staff staff = new Gadelshin_Staff();
            while (true)
            {
                Console.WriteLine("\n1: Добавить работника");
                Console.WriteLine("2: Добавить менеджера");
                Console.WriteLine("3: Вывести всех работников");
                Console.WriteLine("4: Загрузить из файла");
                Console.WriteLine("5: Загрузить в файл");
                Console.WriteLine("6: Очистить всех работникв");
                Console.WriteLine("0: Выход\n");

                uint Choice = Utils.Check_Value(0, 6);

                if (Choice == 1)
                {
                    Gadelshin_Employee employee = new Gadelshin_Employee();
                    employee.Add_employee();
                    staff.Add_employee_to_list(employee);
                }
                else if (Choice == 2)
                {
                    Gadelshin_Manager manager = new Gadelshin_Manager();
                    manager.Add_employee();
                    staff.Add_employee_to_list(manager);
                }
                else if (Choice == 3)
                {
                    staff.Print_data();
                }
                else if (Choice == 4)
                {
                    staff.DeserializeData();
                }
                else if (Choice == 5)
                {
                    staff.SerializeData();
                }
                else if (Choice == 6)
                {
                    staff.Clear_employes();
                }
                if (Choice == 0)
                    break;
            }
        }
    }
}
