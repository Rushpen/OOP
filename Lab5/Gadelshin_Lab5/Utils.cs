using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gadelshin_Lab5
{
    class Utils
    {
        public static ulong check_number()
        {
            while (true)
            {
                string input = Console.ReadLine();

                if (input.Length == 11 && ulong.TryParse(input, out ulong value))
                {
                    return value;
                }

                Console.WriteLine("Ошибка! Введите 11-значный номер телефона");
            }
        }
        public static uint check_uint()
        {
            while (true)
            {
                string input = Console.ReadLine();

                if (uint.TryParse(input, out uint value))
                {
                    return value;
                }

                Console.WriteLine("Введите корректное значение!");
            }
        }

        public static void check_interval(uint value, uint min, uint max)
        {
            if (value >= min && value <= max)
            {
                return;
            }
            throw new ArgumentException($"Значение не в пределах [{min}, {max}]");
        }

        public static uint check_value(uint min, uint max)
        {
            while (true)
            {
                try
                {
                    uint value = Convert.ToUInt32(Console.ReadLine());
                    check_interval(value, min, max);
                    return value;
                }
                catch (ArgumentException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (FormatException)
                {
                    Console.WriteLine("Некоректные данные!");
                }
            }
        }

    }
}
