﻿using Xamarin.Forms.Internals;
using Xamarin.Forms.Xaml;
using Xlet.Mobile.DataService;

namespace Xlet.Mobile.Views.Notification
{
    /// <summary>
    /// Page to display E-Commerce notifications list.
    /// </summary>
    [Preserve(AllMembers = true)]
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class ECommerceNotificationPage
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="ECommerceNotificationPage" /> class.
        /// </summary>
        public ECommerceNotificationPage()
        {
            InitializeComponent();
            this.BindingContext = ECommerceNotificationDataService.Instance.ECommerceNotificationViewModel;
        }

    }
}