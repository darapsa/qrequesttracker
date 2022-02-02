#include <QStringBuilder>
#include <rtclient.h>
#include <rtclient/user.h>
#include <rtclient/ticket.h>
#include <rtclient/search.h>
#include "qrtclient.hxx"

namespace RTClient {

static Client* client;
static char *nCopy, *pwCopy;

Client::Client(char const* url, char const* cookies, char const* certificate)
{
	client = this;
	rtclient_init(url, cookies, certificate);
}

void Client::logIn(QString const& name, QString const& password)
{
	auto nData = name.toLatin1().constData();
	nCopy = (char*)malloc(strlen(nData) + 1);
	strcpy(nCopy, nData);
	auto pwData = password.toLatin1().constData();
	pwCopy = (char*)malloc(strlen(pwData) + 1);
	strcpy(pwCopy, pwData);
	rtclient_login(nCopy, pwCopy, [](rtclient_response* response) {
#ifdef __EMSCRIPTEN__
			free(response->userData);
#endif
			rtclient_free_response(response);
			client->emitLoggedIn(QString{nCopy});
			free(nCopy);
			free(pwCopy);
		});
}

void Client::userNew(QString const& name,
		QString const& password,
		QString const& emailAddress,
		QString const& realName,
		QString const& nickName,
		QString const& organization,
		QString const& address1,
		QString const& address2,
		QString const& city,
		QString const& state,
		QString const& zip,
		QString const& country,
		QString const& homePhone,
		QString const& workPhone,
		QString const& mobilePhone,
		QString const& pagerPhone,
		QString const& contactInfo,
		QString const& comments,
		QString const& signature,
		QString const& gecos,
		rtclient_user_lang lang,
		rtclient_user_timezone timezone,
		bool disabled,
		bool privileged)
{
	rtclient_user_new(name.toLatin1().constData(),
			password.toLatin1().constData(),
			emailAddress.toLatin1().constData(),
			realName.toLatin1().constData(),
			nickName.toLatin1().constData(),
			organization.toLatin1().constData(),
			address1.toLatin1().constData(),
			address2.toLatin1().constData(),
			city.toLatin1().constData(),
			state.toLatin1().constData(),
			zip.toLatin1().constData(),
			country.toLatin1().constData(),
			homePhone.toLatin1().constData(),
			workPhone.toLatin1().constData(),
			mobilePhone.toLatin1().constData(),
			pagerPhone.toLatin1().constData(),
			contactInfo.toLatin1().constData(),
			comments.toLatin1().constData(),
			signature.toLatin1().constData(),
			gecos.toLatin1().constData(),
			lang,
			timezone,
			disabled,
			privileged);
}

void Client::userShow(unsigned int id)
{
	rtclient_user_showid(id, [](struct rtclient_user* user) {
			client->emitUserShown(User{user});
			rtclient_user_free(user);
		});
}

void Client::userShow(QString const& name)
{
	rtclient_user_showname(name.toLatin1().constData(),
		[](struct rtclient_user* user) {
			client->emitUserShown(User{user});
			rtclient_user_free(user);
		});
}

void Client::ticketNew(QString const& queue,
		QString const& requestor,
		QString const& subject,
		QString const& cc,
		QString const& adminCc,
		QString const& owner,
		QString const& status,
		QString const& priority,
		QString const& initialPriority,
		QString const& finalPriority,
		QString const& timeEstimated,
		QString const& starts,
		QString const& due,
		QString const& text)
{
	rtclient_ticket_new(queue.toLatin1().constData(),
			requestor.toLatin1().constData(),
			subject.toLatin1().constData(),
			cc.toLatin1().constData(),
			adminCc.toLatin1().constData(),
			owner.toLatin1().constData(),
			status.toLatin1().constData(),
			priority.toLatin1().constData(),
			initialPriority.toLatin1().constData(),
			finalPriority.toLatin1().constData(),
			timeEstimated.toLatin1().constData(),
			starts.toLatin1().constData(),
			due.toLatin1().constData(),
			text.toLatin1().constData());
}

void Client::searchTicket(QString const& owner)
{
	QString query{"Owner='" % owner % "'"};
	rtclient_search_ticket(query.toLatin1().constData(),
		[](struct rtclient_ticket** list) {
			client->emitSearchedTicket(TicketList{list});
			size_t i = 0;
			while (list[i]) {
				free(list[i]->subject);
				free(list[i++]);
			}
		});
}

void Client::ticketHistoryList(int id, bool longFormat)
{
	rtclient_ticket_history_list(id, longFormat,
		[](struct rtclient_ticket_history** list) {
			client->emitGotTicketHistoryList(TicketHistoryList{list});
			size_t i = 0;
//			while (list[i]) rtclient_ticket_history_free(list[i++]);
		});
}

void Client::emitLoggedIn(QString const& name)
{
	emit loggedIn(name);
}

void Client::emitUserShown(User const& user)
{
	emit userShown(user);
}

void Client::emitSearchedTicket(TicketList const& list)
{
	emit searchedTicket(list);
}

void Client::emitGotTicketHistoryList(TicketHistoryList const& list)
{
	emit gotTicketHistoryList(list);
}

Client::~Client()
{
	rtclient_cleanup();
}

}
