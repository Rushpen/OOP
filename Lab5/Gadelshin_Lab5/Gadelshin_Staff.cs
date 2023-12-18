using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace Gadelshin_Lab5
{
    public class Gadelshin_Staff
    {

        public Gadelshin_Staff() { }
        public string Store_file { get; set; } = "data.xml";

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
        public void SerializeData()
        {
            Console.Write("Введите путь к файлу для записи: ");
            string filePath = Console.ReadLine();

            var xs = new XmlSerializer(typeof(List<Gadelshin_Employee>), new[] { typeof(Gadelshin_Employee), typeof(Gadelshin_Manager) });

            if (System.IO.File.Exists(filePath))
            {
                using (Stream fs = new FileStream(filePath, FileMode.Create))
                {
                    xs.Serialize(fs, employees);
                    Console.WriteLine($"\nДанные успешно записаны в файл {filePath}");
                }
            }
            else
            {
                Console.WriteLine($"Файл {filePath} не существует.");
            }
        }

        public void DeserializeData()
        {
            Console.Write("Введите путь к файлу для загрузки: ");
            string filePath = Console.ReadLine();

            var xs = new XmlSerializer(typeof(List<Gadelshin_Employee>), new[] { typeof(Gadelshin_Employee), typeof(Gadelshin_Manager) });

            if (System.IO.File.Exists(filePath))
            {
                using (Stream fs = new FileStream(filePath, FileMode.Open))
                {
                    List<Gadelshin_Employee> deserializedData = xs.Deserialize(fs) as List<Gadelshin_Employee>;

                    if (deserializedData != null)
                    {
                        employees = deserializedData;
                        Console.WriteLine($"\nДанные успешно загружены из файла {filePath}");
                    }
                    else
                    {
                        Console.WriteLine($"Не удалось десериализовать данные из файла {filePath}");
                    }
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
