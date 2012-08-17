using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.Ports;
using System.Text;
using ThermalDotNet;
using System.IO;

namespace ThermalPrinterTestApp
{
	class MainClass
	{
        class Item
        {
            public string Quantity
            {
                get;
                set;
            }

            public string Size
            {
                get;
                set;
            }

            public string ItemName
            {
                get;
                set;
            }

            public string Sugar
            {
                get;
                set;
            }

            public string Components
            {
                get;
                set;
            }

            public string Additionals
            {
                get;
                set;
            }

            public string Price
            {
                get;
                set;
            }
        }

        class Reciept
        {
            public Reciept()
            {
                items = new List<Item>();
            }

            public string total;
            public string discount;
            public string cash;

            public void add(Item item)
            {
                items.Add(item);
            }

            public List<Item> getItems()
            {
                return items;
            }

            private List<Item> items;
        }

        // file format
        // cash@  discount @ total
        // quantity @ size @ itemname @ sugar @ price @ component @ additional
        private static Reciept getReciept(string filename)
        {
            Reciept receipt = new Reciept();

            try
            {
                using (StreamReader reader = new StreamReader(filename))
                {
                    string line = reader.ReadLine();

                    receipt.cash = line.Split('@')[0];
                    receipt.discount = line.Split('@')[1];
                    receipt.total = line.Split('@')[2];

                    while ((line = reader.ReadLine()) != null)
                    {
                        if (line.Trim().Length < 1)
                            break;

                        Item item = new Item();

                        string [] arr = line.Split('@');

                        string quantity = arr[0];
                        string size= arr[1];
                        string itemName= arr[2];
                        string sugar= arr[3];
                        string price= arr[4];
                        string components = arr[5];
                        string addtitionals = arr[6];

                        item.Quantity = quantity.Trim();
                        item.Size = size.Trim();
                        item.ItemName = itemName.Trim();
                        item.Sugar = sugar.Trim();
                        item.Price = price.Trim();
                        item.Components = components.Trim();
                        item.Additionals = addtitionals.Trim();

                        receipt.add(item);
                    }
                }
            }
            catch (Exception)
            {
            }

            return receipt;
        }

        private static string getPrinterPort()
        {
            string portName = "";
            try
            {
                using (StreamReader reader = new StreamReader("ports.txt"))
                {
                    portName = reader.ReadLine();
                }
            }
            catch (Exception)
            {
                portName = "COM5/WP-T800";
            }

            return portName;
        }

		public static void Main(string[] args)
		{
            if (args.Length <= 0)
            {
                Console.Out.WriteLine("Command Line Error");
                return;
            }

            string path = args[0];
            Reciept reciept = getReciept(path);

            string printerPortName = getPrinterPort();
			SerialPort printerPort = new SerialPort(printerPortName);

			if (printerPort != null)
			{
				if (printerPort.IsOpen)
				{
					printerPort.Close();
				}
			}
			
			try {
				printerPort.Open();
			} catch{
				Console.WriteLine ("I/O error");
				Environment.Exit(0);
			}
			
			//Printer init
			ThermalPrinter printer = new ThermalPrinter(printerPort,2,180,2);
			printer.WakeUp();

            printer.SetLineSpacing(0);
            printer.SetAlignCenter();
            printer.WriteLine("Mango Talaat",
                (byte)ThermalPrinter.PrintingStyle.Bold +
                (byte)ThermalPrinter.PrintingStyle.DoubleHeight
                + (byte)ThermalPrinter.PrintingStyle.DoubleWidth);

            printer.WriteLine("Riyadh, Gadheer Branch");
            printer.Reset();
            printer.LineFeed();

            // show header
            string header = "Qty".PadLeft(2) + " " + "Size".PadLeft(3) + " " + "Sugar".PadLeft(5)  + " " + "Item".PadLeft(10) + " " + "Price".PadLeft(15);
            printer.WriteLine(header);
            printer.HorizontalLine(40);

            ShowItems(printer, reciept);

            printer.HorizontalLine(40);

            printer.WriteLine("CASH" + reciept.cash.PadLeft(26));
            printer.WriteLine("Discount" + reciept.discount.PadLeft(22));
            printer.WriteLine("TOTAL" + reciept.total.PadLeft(10), ThermalPrinter.PrintingStyle.DoubleWidth);

            printer.LineFeed();
            printer.SetAlignCenter();
            printer.WriteLine("Have a good day.", ThermalPrinter.PrintingStyle.Bold);

            printer.LineFeed();
            printer.SetAlignLeft();
            printer.WriteLine(DateTime.Now.ToString());
            printer.LineFeed(); 
	
            printer.LineFeed(3);
            printer.cutPaper();
            printer.openCashDrawer();
			printer.Sleep();
			Console.WriteLine("Printer is now offline.");
			printerPort.Close();
		}

        private static void ShowItems(ThermalPrinter printer, Reciept reciept) 
        {           
            foreach(Item item in reciept.getItems()) 
            {
                printer.Reset();

                // .PadLeft(Math.Abs(item.ItemName.Length - 30));
                string output = item.Quantity.PadRight(2) + " " + item.Size.PadRight(5) + " " + item.Sugar.PadRight(2) + " " + item.ItemName.Trim() + " " +
                   (item.Price.Trim() + ".SR").PadLeft(Math.Abs(item.ItemName.Length - 29));
                printer.WriteLine(output);

                if (item.Components.Trim().Length > 3 ) {
                    printer.WriteLine(item.Components.Trim());
                }

                if (item.Additionals.Trim().Length > 3)
                {
                    printer.WriteLine(item.Additionals.Trim());
                }         

                printer.Reset();
            }
        }
	}
}
