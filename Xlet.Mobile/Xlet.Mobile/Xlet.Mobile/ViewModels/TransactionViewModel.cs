using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;

namespace Xlet.Mobile.ViewModels
{
    public class TransactionViewModel
    {
        private string _name;
        public string Name
        {
            get
            {
                return _name;
            }

            set
            {
                _name = value;
                NotifyPropertyChanged();
            }
        }

        private string _assetType;
        public string AssetType
        {
            get
            {
                return _assetType;
            }

            set
            {
                _assetType = value;
                NotifyPropertyChanged();
            }
        }

        private string _transactionDescription;
        public string TransactionDescription
        {
            get
            {
                return _transactionDescription;
            }

            set
            {
                _transactionDescription = value;
                NotifyPropertyChanged();
            }
        }

        private string _transactionAmount;
        public string TransactionAmount
        {
            get
            {
                return _transactionAmount;
            }

            set
            {
                _transactionAmount = value;
                NotifyPropertyChanged();
            }
        }

        private bool _isCredited;
        public bool IsCredited
        {
            get
            {
                return _isCredited;
            }

            set
            {
                _isCredited = value;
                NotifyPropertyChanged();
            }
        }

        private string _date;
        public string Date
        {
            get
            {
                return _date;
            }

            set
            {
                _date = value;
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
