using System;

namespace Gadelshin_Lab5
{
    public class Utils
    {
        public static ulong Check_Number()
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
        public static uint Check_Uint()
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
        public static void Check_Interval(uint value, uint min, uint max)
        {
            if (value < min || value > max)
            {
                throw new ArgumentException($"Значение не в пределах [{min}, {max}]");
            }
        }
        public static uint Check_Value(uint min, uint max)
        {
            while (true)
            {
                try
                {
                    uint value = Convert.ToUInt32(Console.ReadLine());
                    Check_Interval(value, min, max);
                    return value;
                }
                catch (FormatException)
                {
                    Console.WriteLine("Некоректные данные!");
                }
                catch (ArgumentException e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }

    }
}
