using System;
using System.Collections.Generic;
using System.Text;

namespace Xlet.Mobile
{
    // Based on https://github.com/google/google-authenticator-android/blob/master/AuthenticatorApp/src/main/java/com/google/android/apps/authenticator/Base32String.java
    public static class Base32Encoding
    {
        private const string _vocabulary = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
        private const int _mask = 31;
        private const int _shift = 5;

        public static string Encode(byte[] data)
        {
            int outputLength = (data.Length * 8 + _shift - 1) / _shift;
            var result = new StringBuilder(outputLength);

            int buffer = data[0];
            int next = 1;
            int bitsLeft = 8;

            while (bitsLeft > 0 || next < data.Length)
            {
                if (bitsLeft < _shift)
                {
                    if (next < data.Length)
                    {
                        buffer <<= 8;
                        buffer |= (data[next++] & 0xff);
                        bitsLeft += 8;
                    }
                    else
                    {
                        int pad = _shift - bitsLeft;
                        buffer <<= pad;
                        bitsLeft += pad;
                    }
                }

                int index = _mask & (buffer >> (bitsLeft - _shift));
                bitsLeft -= _shift;

                result.Append(_vocabulary[index]);
            }

            return result.ToString();
        }
    }
}
