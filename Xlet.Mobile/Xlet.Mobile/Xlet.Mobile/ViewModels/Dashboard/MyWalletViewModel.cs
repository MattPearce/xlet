using System;
using System.Collections.ObjectModel;
using Xamarin.Forms;
using Xamarin.Forms.Internals;
using Xlet.Mobile.Models.Dashboard;
using Model = Xlet.Mobile.Models.Dashboard.Transaction;
using System.Linq;
using System.Threading.Tasks;
using stellar_dotnet_sdk;
using Xamarin.Forms.Xaml;
using stellar_dotnet_sdk.responses.operations;
using Syncfusion.DataSource.Extensions;
using stellar_dotnet_sdk.responses.effects;

namespace Xlet.Mobile.ViewModels.Dashboard
{
    /// <summary>
    /// ViewModel for my wallet page.
    /// </summary>
    [Preserve(AllMembers = true)]
    public class MyWalletViewModel : BaseViewModel
    {
        private double totalBalance;

        private bool isLoading;

        private ObservableCollection<Model> listItems;

        private Command<object> itemTappedCommand;

        private string GetShortAccount(string account)
        {
            return account.Substring(0, 6) + "..." + account.Substring(account.Length - 6);
        }

        /// <summary>
        /// Initializes a new instance for the <see cref="MyWalletViewModel" /> class.
        /// </summary>
        public MyWalletViewModel()
        {
            ListItems = new ObservableCollection<Model>();

            IsLoading = true;

            Task.Run(async () =>
            {
                //var horizonClient = new HorizonClient.HorizonClient("https://horizon.stellar.org");

                //var account = horizonClient.GetAccount("GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG").Result;

                var server = new Server("https://horizon.stellar.org");

                var account = await server.Accounts.Account("GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG");

                var balance = account.Balances.FirstOrDefault(b => b.AssetType == "native")?.BalanceString;

                if (balance != null)
                {
                    TotalBalance = Convert.ToDouble(balance);
                }

                var payments = await server.Payments.ForAccount("GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG")
                .Order(stellar_dotnet_sdk.requests.OrderDirection.DESC)
                .Execute();

                var transactions = await server.Transactions.ForAccount("GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG")
                .Order(stellar_dotnet_sdk.requests.OrderDirection.DESC)
                .Execute();

                var transactionsDict = transactions.Records
                .ToDictionary(r => r.Hash, r => r);

                ListItems = payments.Records
                    .Where(r => r is PaymentOperationResponse)
                    .Cast<PaymentOperationResponse>()
                    .Select(p => new Model
                    {
                        Amount = p.Amount,
                        Date = p.CreatedAt,
                        Name = GetShortAccount(p.SourceAccount == "GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG" ? p.To : p.SourceAccount),
                        AssetType = p.AssetType == "native" ? "XLM" : p.AssetCode.ToUpper(),
                        IsCredited = p.To == "GD35A65DVY6AYPC4YAZNC4VXQFT6XD65DQYXQH6CNWJOZMII65R6DFAG",
                        Title = transactionsDict.ContainsKey(p.TransactionHash) ? transactionsDict[p.TransactionHash].MemoValue : ""
                    })
                    .ToObservableCollection();

                OnPropertyChanged("WeekListItems");

                IsLoading = false;
            });
        }

        /// <summary>
        /// Gets or sets the my wallet items collection.
        /// </summary>
        public ObservableCollection<Model> ListItems
        {
            get
            {
                return this.listItems;
            }

            set
            {
                this.listItems = value;
                this.OnPropertyChanged();
            }
        }

        /// <summary>
        /// Gets the command that will be executed when an item is selected.
        /// </summary>
        public Command<object> ItemTappedCommand
        {
            get
            {
                return this.itemTappedCommand ?? (this.itemTappedCommand = new Command<object>(this.NavigateToNextPage));
            }
        }

        public bool IsLoading
        {
            get
            {
                return isLoading;
            }
            set
            {
                this.isLoading = value;
                this.OnPropertyChanged();
            }
        }
        /// <summary>
        /// Gets or sets the total balance remaining in the wallet.
        /// </summary>
        public double TotalBalance
        {
            get
            {
                return totalBalance;
            }
            set
            {
                this.totalBalance = value;
                this.OnPropertyChanged();
            }
        }

        /// <summary>
        /// Invoked when an item is selected from the my wallet page.
        /// </summary>
        /// <param name="selectedItem">Selected item from the list view.</param>
        private void NavigateToNextPage(object selectedItem)
        {

        }
    }
}