using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;
using static System.Net.WebRequestMethods;

namespace Gadelshin_Lab5
{
    class Gadelshin_Staff
    {
        public string Store_file { get; set; } = "data.xml";

        public List<Gadelshin_Employee> employees = new List<Gadelshin_Employee>();

        public Gadelshin_Staff() { }


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
            try
            {
                var xs = new XmlSerializer(typeof(List<Gadelshin_Employee>), new[] { typeof(Gadelshin_Employee), typeof(Gadelshin_Manager) });
                using (Stream fs = new FileStream(Store_file, FileMode.Create))
                {
                    xs.Serialize(fs, employees);
                }
            }
            catch (Exception)
            {
                Console.WriteLine($"Невозможно записать в файл {Store_file}");
            }
        }

        public void DeserializeData()
        {
            var xs = new XmlSerializer(typeof(List<Gadelshin_Employee>), new[] { typeof(Gadelshin_Employee), typeof(Gadelshin_Manager) });
            try
            {
                using (Stream fs = new FileStream(Store_file, FileMode.Open))
                {
                    employees = xs.Deserialize(fs) as List<Gadelshin_Employee>;
                }
            }
            catch (Exception)
            {
                Console.WriteLine($"Не удается открыть файл {Store_file}");
            }
        }
        public void Clear_employes()
        {
            employees.Clear();
        }

    }
}
