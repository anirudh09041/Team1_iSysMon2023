#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "LoginCred.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace std;
using namespace System::Windows::Forms;


ref class ClientSocket
{
private:
    TcpClient^ client;
    NetworkStream^ stream;

public:
    bool Connect(String^ serverAddress, int port)
    {
        try
        {
            client = gcnew TcpClient(serverAddress, port);
            stream = client->GetStream();
            return true;
        }
        catch (SocketException^ e)
        {
            Console::WriteLine("SocketException: {0}", e->Message);
            return false;
        }
    }

    // Convert a C++ std::string to a byte array

    cli::array<Byte>^ StringToByteArray(const std::string& str)
    {
        // Convert the string to a System::String^
        String^ systemStr = marshal_as<String^>(str);

        // Convert the string to a UTF-8 byte array
        cli::array<Byte>^ byteArray = System::Text::Encoding::UTF8->GetBytes(systemStr);

        return byteArray;
    }

    cli::array<Byte>^ SerializePerson(LoginCred lc)
    {
        // Convert the username field to a UTF-8 byte array
        cli::array<Byte>^ nameBytes = StringToByteArray(lc.username);

        // Allocate a byte array to hold the serialized struct
        cli::array<Byte>^ buffer = gcnew cli::array<Byte>(sizeof(int) + nameBytes->Length);

        // Copy the password field to the buffer
        Buffer::BlockCopy(BitConverter::GetBytes(lc.password), 0, buffer, 0, sizeof(int));

        // Copy the password field to the buffer
        Buffer::BlockCopy(BitConverter::GetBytes(lc.purpose), 0, buffer, 0, sizeof(int));

        // Copy the name field to the buffer
        Buffer::BlockCopy(nameBytes, 0, buffer, sizeof(int), nameBytes->Length);

        return buffer;
    }

    void SendLogin(String^ str) {

        cli::array<Byte>^ data = Encoding::ASCII->GetBytes(str);
        stream->Write(data, 0, data->Length);
        //MessageBox::Show(data->GetLength);
    }

    void Send(String^ clientName, String^ password, Boolean^ purpose)
    {
        char message[7000];

        char loginCredBuffer[200];
        LoginCred lc;
        char loginStat[200];
        string username = msclr::interop::marshal_as<std::string>(clientName);
        string pass = msclr::interop::marshal_as<std::string>(password);
        //'true' for sign in and 'false' for sign up
        lc.purpose = static_cast<bool>(purpose);
        strcpy_s(lc.username, username.c_str());
        strcpy_s(lc.password, pass.c_str());

        /*memcpy(loginCredBuffer, &lc, sizeof(lc));
        printf("sizeof lc = %d\n", (int)sizeof(lc));*/

        //iResult = send(ConnectSocket, loginCredBuffer, (int)sizeof(lc), 0);
        cli::array<Byte>^ buffer = gcnew cli::array<Byte>(sizeof(lc));
        System::Runtime::InteropServices::Marshal::Copy((IntPtr)&lc, buffer, 0, sizeof(lc));
        stream->Write(buffer, 0, buffer->Length);
    }

    String^ Receive()
    {
        cli::array<Byte>^ data = gcnew cli::array<Byte>(1024);
        int bytes = stream->Read(data, 0, data->Length);
        return Encoding::UTF8->GetString(data, 0, bytes);
    }

    void Close()
    {
        stream->Close();
        client->Close();
    }

    String^ SocketConnection(String^ username, String^ password, Boolean^ purpose)
    {
        ClientSocket^ socket = gcnew ClientSocket();
        String^ response;
        if (socket->Connect("127.0.0.1", 27015))
        {
            //socket->Send("Hello, server!");
            socket->SendLogin("LOGIN");
            socket->Send(username, password, purpose);
            response = socket->Receive();
            socket->Close();
        }
        else {
            System::Windows::Forms::MessageBox::Show("Unable to connect");
        }
        return response;
    }
};

