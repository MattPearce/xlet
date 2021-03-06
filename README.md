[![Xlet](https://xlet.io/assets/img/xlet-logo-dark.png "Xlet")](https://www.xlet.io)

# The Open Crypto Wallet

![Xlet](https://xlet.io/assets/img/xlet-payment.png "Xlet")

## Project Overview

We are building open source software to transform cheap devices into secure hardware cryptocurrency wallets. Our goal is to provide consumers with free software to turn cheap (as little as <US$10) devices into secure crypto wallets. Our dream would be to see manufacturers using the software to get cheap crypto wallets onto store shelves.

## Build Status

| Platform | Build Status | CI Platform |
| -------- | ------------ | ----------- |
| M5Stack  | [![Build Status](https://travis-ci.com/MattPearce/xlet.svg?token=6KEqPwFBQM7g7jtpd1Kz&branch=master)](https://travis-ci.com/MattPearce/xlet) | Travis CI |
| iOS | [![Build status](https://build.appcenter.ms/v0.1/apps/479251b3-7eb2-4ce2-94bd-987a3e1b864e/branches/master/badge)](https://appcenter.ms) | MS App Center |
| Android | [![Build status](https://build.appcenter.ms/v0.1/apps/6342c703-b5b5-4c29-8ca2-8456fb26615d/branches/master/badge)](https://appcenter.ms) | MS App Center |

## Repository Structure

| Directory | Description |
| --------- | ----------- |
| Xlet.Wallet | C++ source code for the Xlet wallet software targeting various embedded platforms |
| Xlet.Mobile | C#/Xamarin based wallet apps for iOS and Android that connect to the hardware wallet over BLE |
| Xlet.Web | The landing page hosted at https://www.xlet.io |
| ImageConverter | A .NET Core application to convert input image files into C headers with some extra metadata we use |

## Payment Flow

In order for the wallet to construct a valid Stellar transaction, it is necessary to know the current sequence number of the source account. Because of this, the communication flow involves the user first approving the transaction on the wallet, then the wallet sending the source account public key to the website, which requests the sequence number from Stellar

| Xlet Wallet                   |  BLE          | Website                            | HTTPS         | Stellar (Horizon server)      |
| ----------------------------- | ------------- | ---------------------------------- | ------------- | ----------------------------- |
|                               |               | User initiates transaction         |               |                               |
|                               |               | Scans for compatible BLE devices   |               |                               |
|                               |               | User selects wallet                |               |                               |
|                               | :arrow_left:  | Sends BeginPaymentRequest          |               |                               |
| Displays transaction details  |               |                                    |               |                               |
| User approves transaction     |               |                                    |               |                               |
| Sends PaymentDetailsRequired  | :arrow_right: |                                    |               |                               |
|                               |               | Requests account sequence number   | :arrow_right: |                               |
|                               |               |                                    | :arrow_left:  | Responds with account details |
|                               | :arrow_left:  | Sends CompletePaymentRequest       |               |                               |
| Verifies payment approved     |               |                                    |               |                               |
| Constructs transaction        |               |                                    |               |                               |
| Signs transaction             |               |                                    |               |                               |
| Sends CompletePaymentResponse | :arrow_right: |                                    |               |                               |
|                               |               | Submits transaction to network     | :arrow_right: |                               |
|                               |               |                                    |               | Verifies transaction          |
|                               |               |                                    |               | Completes transaction         |
|                               |               |                                    | :arrow_left:  | Sends transaction details     |
|                               |               | Informs user of transaction result |               |                               |
