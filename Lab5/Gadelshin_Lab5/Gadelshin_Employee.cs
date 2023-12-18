using System;

namespace Gadelshin_Lab5
{
        [Serializable]
    public class Gadelshin_Employee
    {
        public string firstname;
        public string secondname;
        public string login;
        public ulong phone_number;

        public Gadelshin_Employee() { }

        public virtual void Add_employee()
        {
            Console.Write("Введите имя: ");
            firstname = Console.ReadLine();

            Console.Write("Введите фамилия: ");
            secondname = Console.ReadLine();

            Console.Write("Введите логин: ");
            login = Console.ReadLine();

            Console.Write("Введите номер телефона: ");
            phone_number = Utils.Check_Number();
        }

        public virtual void Print_employee(bool printSeparator = true)
        {
            if (printSeparator)
            {
                Console.WriteLine("\nРаботник:");
                Console.WriteLine("..................................");
            }
            Console.WriteLine($"Имя: {firstname}");
            Console.WriteLine($"Фамилия: {secondname}");
            Console.WriteLine($"Логин: {login}");
            Console.WriteLine($"Номер телефона: {phone_number}");
            if (printSeparator)
            {
                Console.WriteLine("..................................");
            }
        }

    }
}
