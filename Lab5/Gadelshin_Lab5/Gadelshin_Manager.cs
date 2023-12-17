using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization;

namespace Gadelshin_Lab5
{
        [Serializable]
    class Gadelshin_Manager : Gadelshin_Employee
    {
        public uint teamSize;
        public uint expYears;

        public Gadelshin_Manager() : base () { }

        public override void Print_employee()
        {
            Console.WriteLine("----------");
            Console.WriteLine("Менеджер:");
            base.Print_employee();
            Console.WriteLine($"Размер команды: {teamSize}");
            Console.WriteLine($"Лет опыта: {expYears}");
            Console.WriteLine("----------");
        }
        public override void Add_employee()
        {
            base.Add_employee();

            Console.Write("Введите размер команды: ");
            teamSize = Utils.check_uint();

            Console.Write("Введите годы работ: ");
            expYears = Utils.check_uint();
        }
    }
}
