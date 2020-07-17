#include <iostream>
#include <string>

using namespace std;

class INotifier {
public:
	virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier {
public:
	SmsNotifier(string phone_num) : num(phone_num) {}
	void Notify (const string& message) const override {SendSms(num, message);}
private:
	const string num;
};

class EmailNotifier : public INotifier {
public:
	EmailNotifier (string email) : mail(email) {}
	void Notify (const string& message) const override {SendEmail(mail, message);}
private:
	const string mail;
};
