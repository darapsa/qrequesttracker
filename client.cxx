#include <QStringBuilder>
#include <rtclient/client.h>
#include <rtclient/ticket.h>
#include <rtclient/search.h>
#include "qrtclient/client.hxx"

namespace RTClient {

	Client::Client(char const* url, char const* certificate)
	{
		rtclient_init(url, certificate);
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
			, rtclient_user_lang lang
			, rtclient_user_timezone timezone
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
				, timezone
				, disabled
				, privileged);
	}

	void Client::userShow(unsigned int id)
	{
		rtclient_user* user = nullptr;
		rtclient_user_showid(&user, id);
		emit userShown(user);
	}

	void Client::userShow(QString const& name)
	{
		rtclient_user* user = nullptr;
		rtclient_user_showname(&user, name.toLatin1().constData());
		emit userShown(user);
	}

	void Client::ticketNew(QString const& queue
			, QString const& requestor
			, QString const& subject
			, QString const& cc
			, QString const& adminCc
			, QString const& owner
			, QString const& status
			, QString const& priority
			, QString const& initialPriority
			, QString const& finalPriority
			, QString const& timeEstimated
			, QString const& starts
			, QString const& due
			, QString const& text)
	{
		rtclient_ticket_new(queue.toLatin1().constData()
			, requestor.toLatin1().constData()
			, subject.toLatin1().constData()
			, cc.toLatin1().constData()
			, adminCc.toLatin1().constData()
			, owner.toLatin1().constData()
			, status.toLatin1().constData()
			, priority.toLatin1().constData()
			, initialPriority.toLatin1().constData()
			, finalPriority.toLatin1().constData()
			, timeEstimated.toLatin1().constData()
			, starts.toLatin1().constData()
			, due.toLatin1().constData()
			, text.toLatin1().constData());
	}

	void Client::searchTicket(QString const& owner)
	{
		QString query{"Owner='" % owner % "'"};
		rtclient_search_ticket_list* ticketList = nullptr;
		rtclient_search_ticket(&ticketList, query.toLatin1().constData());
		emit searchedTicket(ticketList);
	}

	void Client::ticketHistory(int id)
	{
		rtclient_ticket_history_list* historyList = nullptr;
		rtclient_ticket_history(&historyList, id
				, RTCLIENT_TICKET_FORMAT_L);
		emit gotTicketHistory(historyList);
	}

	Client::~Client()
	{
		rtclient_cleanup();
	}

}
