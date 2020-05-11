using Microsoft.AppCenter;
using Microsoft.AppCenter.Analytics;
using Microsoft.AppCenter.Crashes;
using System;
using System.Threading.Tasks;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using Xlet.Mobile.Services;
using Xlet.Mobile.Views;
using Xlet.Mobile.Views.Dashboard;
using Xlet.Mobile.Views.Navigation;
using Xlet.Mobile.Views.Onboarding;

namespace Xlet.Mobile
{
    public partial class App : Application
    {
        public static string BaseImageUrl { get; } = "https://cdn.syncfusion.com/essential-ui-kit-for-xamarin.forms/common/uikitimages/";

        public App()
        {
            Syncfusion.Licensing.SyncfusionLicenseProvider.RegisterLicense("MjU0MjQ4QDMxMzgyZTMxMmUzMEFzeU5ZWW1VR3hWUGJycnJ0S0FOK2NnaFpKRldPK0pBOGJNK2tIMHdjZGM9");

            InitializeComponent();

            DependencyService.Register<MockDataStore>();
            MainPage = new MainPage();
        }

        protected override void OnStart()
        {
            AppCenter.Start("ios=55bb8db2-0a98-4c2e-9dd0-e27a6c5ec37d;" +
                  "android=7ff37006-dd75-41e4-83df-3b02092f5b14",
                  typeof(Analytics), typeof(Crashes));
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
