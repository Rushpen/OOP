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
                Console.WriteLine("\n1: Добавить работника \n2: Добавить менеджера" +
                    " \n3: Вывести всех работников \n4: Загрузить из файла \n5: Загрузить в файл" +
                    " \n6: Очистить всех работникв \n7: Изменить файл хранения \n0: Выход\n");

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
                    staff.Serialization_from_file();
                }
                else if (Choice == 5)
                {
                    staff.Serialization_to_file();
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
