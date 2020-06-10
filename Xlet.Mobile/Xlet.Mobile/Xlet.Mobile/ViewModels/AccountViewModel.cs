using stellar_dotnet_sdk;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;
using Xamarin.Forms;

namespace Xlet.Mobile.ViewModels
{
    public class AccountViewModel : INotifyPropertyChanged
    {
        private string _id;
        public string Id 
        {
            get => _id; 
            set
            {
                _id = value;
                NotifyPropertyChanged();
            }
        }

        private bool _isLoading;
        public bool IsLoading
        {
            get => _isLoading;
            set
            {
                _isLoading = value;
                NotifyPropertyChanged();
            }
        }

        private double _totalNativeBalance;
        public double TotalNativeBalance
        {
            get
            {
                return _totalNativeBalance;
            }
            set
            {
                _totalNativeBalance = value;
                NotifyPropertyChanged();
            }
        }

        private ObservableCollection<TransactionViewModel> _transactions;
        public ObservableCollection<TransactionViewModel> Transactions
        {
            get
            {
                return _transactions;
            }
            set
            {
                _transactions = value;
                NotifyPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        protected void NotifyPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
