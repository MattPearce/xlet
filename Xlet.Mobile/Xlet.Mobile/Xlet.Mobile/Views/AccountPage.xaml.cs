using stellar_dotnet_sdk;
using stellar_dotnet_sdk.responses.operations;
using Syncfusion.DataSource.Extensions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using Xlet.Mobile.ViewModels;

namespace Xlet.Mobile.Views.Account
{
    [QueryProperty(nameof(AccountId), "Id")]
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class AccountPage : ContentPage
    {
        public AccountPage()
        {
            InitializeComponent();
        }

        private AccountViewModel DataContext => BindingContext as AccountViewModel;

        public string AccountId
        {
            set
            {
                BindingContext = new AccountViewModel
                {
                    Id = value,
                    IsLoading = true
                };

                LoadAccount(value);
            }
        }

        private string GetShortAccount(string account)
        {
            return account.Substring(0, 6) + "..." + account.Substring(account.Length - 6);
        }

        private void LoadAccount(string id)
        {
            Task.Run(async () =>
            {
                //var horizonClient = new HorizonClient.HorizonClient("https://horizon.stellar.org");

                //var account = horizonClient.GetAccount("GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG").Result;

                var server = new Server("https://horizon.stellar.org");

                var account = await server.Accounts.Account(id);

                var accountViewModel = new AccountViewModel
                {
                    Id = id
                };

                accountViewModel.TotalNativeBalance = account.Balances
                    .Where(b => b.AssetType == "native")
                    .Select(b => Convert.ToDouble(b.BalanceString))
                    .FirstOrDefault();

                var payments = await server.Payments.ForAccount(id)
                .Order(stellar_dotnet_sdk.requests.OrderDirection.DESC)
                .Execute();

                var transactions = await server.Transactions.ForAccount(id)
                .Order(stellar_dotnet_sdk.requests.OrderDirection.DESC)
                .Execute();

                var transactionsDict = transactions.Records
                .ToDictionary(r => r.Hash, r => r);

                accountViewModel.Transactions = payments.Records
                    .Where(r => r is PaymentOperationResponse)
                    .Cast<PaymentOperationResponse>()
                    .Select(p => new TransactionViewModel
                    {
                        TransactionAmount = p.Amount,
                        Date = p.CreatedAt,
                        Name = GetShortAccount(p.SourceAccount == "GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG" ? p.To : p.SourceAccount),
                        AssetType = p.AssetType == "native" ? "XLM" : p.AssetCode.ToUpper(),
                        IsCredited = p.To == "GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG",
                        TransactionDescription = transactionsDict.ContainsKey(p.TransactionHash) ? transactionsDict[p.TransactionHash].MemoValue : ""
                    })
                    .ToObservableCollection();

                OnPropertyChanged("WeekListItems");

                BindingContext = accountViewModel;
            });
        }
    }
}
