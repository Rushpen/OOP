using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace Gadelshin_Lab5
{
    public class Gadelshin_Staff
    {

        public Gadelshin_Staff() { }

        public List<Gadelshin_Employee> employees = new List<Gadelshin_Employee>();

        public void Add_employee_to_list(Gadelshin_Employee employee)
        {
            employees.Add(employee);
        }

        public void Print_data()
        {
            if (employees.Count == 0)
            {
                Console.WriteLine("Ошибка! Работников нет!");
                return;
            }

            foreach (var employee in employees)
            {
                employee.Print_employee();
            }
        }
        public void Serialization_to_file()
        {
            Console.Write("Введите путь к файлу для записи: ");
            string filePath = Console.ReadLine();

            var serialize = new XmlSerializer(typeof(List<Gadelshin_Employee>), new[] { typeof(Gadelshin_Employee), typeof(Gadelshin_Manager) });

            using (Stream fs = new FileStream(filePath, FileMode.OpenOrCreate))
            {
                serialize.Serialize(fs, employees);
                Console.WriteLine($"\nДанные успешно записаны в файл {filePath}");
            }

        }

        public void Serialization_from_file()
        {
            Console.Write("Введите путь к файлу для загрузки: ");
            string filePath = Console.ReadLine();

            var serialize = new XmlSerializer(typeof(List<Gadelshin_Employee>), new[] { typeof(Gadelshin_Employee), typeof(Gadelshin_Manager) });

            if (System.IO.File.Exists(filePath))
            {
                using (Stream fs = new FileStream(filePath, FileMode.Open))
                {
                    employees = serialize.Deserialize(fs) as List<Gadelshin_Employee>;
                }
            }
            else
            {
                Console.WriteLine($"Файл {filePath} не существует.");
            }
        }

        public void Clear_employes()
        {
            employees.Clear();
        }

    }
}
