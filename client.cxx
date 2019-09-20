#include <QStringBuilder>
#include <rtclient/client.h>
#include "qrtclient/client.hxx"

namespace RTClient {

	Client::Client(QString const& url)
	{
		rtclient_init(url.toLatin1().constData());
	}

	void Client::logIn(QString const& name, QString const& password)
	{
		rtclient_login(name.toLatin1().constData(), password.toLatin1().constData());
		emit loggedIn(name);
	}

	void Client::userNew(QString const& name
			, QString const& password
			, QString const& emailAddress
			, QString const& realName
			, QString const& nickName
			, QString const& organization
			, QString const& address1
			, QString const& address2
			, QString const& city
			, QString const& state
			, QString const& zip
			, QString const& country
			, QString const& homePhone
			, QString const& workPhone
			, QString const& mobilePhone
			, QString const& pagerPhone
			, QString const& contactInfo
			, QString const& comments
			, QString const& signature
			, QString const& gecos
			, rtclient_lang lang
			, rtclient_timezone timeZone
			, bool disabled
			, bool privileged)
	{
		rtclient_user_new(name.toLatin1().constData()
				, password.toLatin1().constData()
				, emailAddress.toLatin1().constData()
				, realName.toLatin1().constData()
				, nickName.toLatin1().constData()
				, organization.toLatin1().constData()
				, address1.toLatin1().constData()
				, address2.toLatin1().constData()
				, city.toLatin1().constData()
				, state.toLatin1().constData()
				, zip.toLatin1().constData()
				, country.toLatin1().constData()
				, homePhone.toLatin1().constData()
				, workPhone.toLatin1().constData()
				, mobilePhone.toLatin1().constData()
				, pagerPhone.toLatin1().constData()
				, contactInfo.toLatin1().constData()
				, comments.toLatin1().constData()
				, signature.toLatin1().constData()
				, gecos.toLatin1().constData()
				, lang
				, timeZone
				, disabled
				, privileged);
	}

	void Client::userShow(unsigned int id)
	{
		rtclient_user* user = NULL;
		rtclient_user_showid(&user, id);
		if (user) emit userShown(user);
	}

	void Client::userShow(QString const& name)
	{
		rtclient_user* user = NULL;
		rtclient_user_showname(&user, name.toLatin1().constData());
		if (user) emit userShown(user);
	}

	void Client::ticketNew(QString const& queue
			, QString const& requestor
			, QString const& subject
			, QString const& cc
			, QString const& admincc
			, QString const& owner
			, QString const& status
			, QString const& priority
			, QString const& initialpriority
			, QString const& finalpriority
			, QString const& timeestimated
			, QString const& starts
			, QString const& due
			, QString const& text)
	{
		rtclient_ticket_new(queue.toLatin1().constData()
			, requestor.toLatin1().constData()
			, subject.toLatin1().constData()
			, cc.toLatin1().constData()
			, admincc.toLatin1().constData()
			, owner.toLatin1().constData()
			, status.toLatin1().constData()
			, priority.toLatin1().constData()
			, initialpriority.toLatin1().constData()
			, finalpriority.toLatin1().constData()
			, timeestimated.toLatin1().constData()
			, starts.toLatin1().constData()
			, due.toLatin1().constData()
			, text.toLatin1().constData());
	}

	void Client::ticketSearch(QString const& owner)
	{
		QString query = "Owner='" % owner % "'";;
		rtclient_ticketlist* ticketList = NULL;
		rtclient_ticket_search(&ticketList, query.toLatin1().constData());
		if (ticketList) emit foundTickets(ticketList);
	}

	Client::~Client()
	{
		rtclient_cleanup();
	}

}
