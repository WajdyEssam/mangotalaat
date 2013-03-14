using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace EPOS_CashDrawer
{
    public class PortAccess
    {
        [DllImport("CashDrawer.dll", EntryPoint = "Initial_CashDrawer")]
        public static extern void Initial_CashDrawer();
        [DllImport("CashDrawer.dll", EntryPoint = "fnPxGetCashDrawerStatus")]
        public static extern bool fnPxGetCashDrawerStatus(short num_drawer);
        [DllImport("CashDrawer.dll", EntryPoint = "fnPxCashDrawerOpen")]
        public static extern bool fnPxCashDrawerOpen(short num_drawer);
    }

    class Program
    {
        static void Main(string[] args)
        {
            PortAccess.Initial_CashDrawer();
            PortAccess.fnPxCashDrawerOpen(0x01);
        }
    }
}
