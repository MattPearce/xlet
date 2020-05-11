using System;
using System.Collections.Generic;
using System.Text;

namespace Xlet.Mobile.Models
{
    public enum MenuItemType
    {
        Browse,
        Devices,
        Social
    }
    public class HomeMenuItem
    {
        public MenuItemType Id { get; set; }

        public string Title { get; set; }
    }
}
