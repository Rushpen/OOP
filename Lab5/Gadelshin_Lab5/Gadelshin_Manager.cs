using System;

namespace Gadelshin_Lab5
{
        [Serializable]
    public class Gadelshin_Manager : Gadelshin_Employee
    {
        public uint teamSize;
        public uint expYears;

        public Gadelshin_Manager() : base () { }

        public override void Add_employee()
        {
            base.Add_employee();

            Console.Write("Введите размер команды: ");
            teamSize = Utils.Check_Uint();

            Console.Write("Введите годы работ: ");
            expYears = Utils.Check_Uint();
        }

        public override void Print_employee(bool printSeparator = true)
        {
            Console.WriteLine("\nМенеджер:");
            if (printSeparator)
            {
                Console.WriteLine("..................................");
            }
            base.Print_employee(false);
            Console.WriteLine($"Размер команды: {teamSize}");
            Console.WriteLine($"Лет опыта: {expYears}");
            if (printSeparator)
            {
                Console.WriteLine("..................................");
            }
        }

    }
}
