/*using Chaos.NaCl;
using System;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Text;

namespace Xlet.Mobile
{
    // Workaround because NSec isn't supported on Xamarin
    public class StellarKeyPair
    {
        public byte[] PublicKeyBytes => Ed25519.PublicKeyFromSeed(_privateSeed);

        public string _publicKey;
        public string PublicKey
        {
            get
            {
                return _publicKey ?? (_publicKey = KeyToString(AccountIdByte, PublicKeyBytes));
            }
        }

        private string _secretKey;
        public string SecretKey
        {
            get
            {
                return _secretKey ?? (_secretKey = KeyToString(SecretKeyByte, _privateSeed));
            }
        }

        private byte[] _privateSeed = new byte[32];

        private static byte[] CalculateXmodemCRC16(IEnumerable<byte> bytes)
        {
            // Xmodem CRC16
            uint crc = 0;

            foreach (var value in bytes)
            {
                uint code = (crc >> 8) ^ value;
                code ^= code >> 4;

                crc = crc << 8
                    ^ code
                    ^ (code << 5)
                    ^ (code << 12);

                crc &= 0xFFFF;
            }

            return new[]
            {
                (byte)crc,
                (byte)(crc >> 8)
            };
        }

        public StellarKeyPair()
        {
            var crypto = RNGCryptoServiceProvider.Create();

            crypto.GetBytes(_privateSeed);
        }

        public StellarKeyPair(byte[] bytes)
        {
            _privateSeed = bytes;
        }

        private const byte AccountIdByte = 6 << 3;
        private const byte SecretKeyByte = 18 << 3;

        private string KeyToString(byte versionByte, byte[] key)
        {
            var bytes = new List<byte> { versionByte };
            bytes.AddRange(key);
            bytes.AddRange(CalculateXmodemCRC16(bytes.ToArray()));
            return Base32Encoding.Encode(bytes.ToArray());
        }
    }

}
*/