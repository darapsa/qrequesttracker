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
		struct rt_user* user = NULL;
		rtclient_user_show(&user, name.toLatin1().constData());
		if (user) emit logged(user);
	}

	void Client::userNew(QString const& name
			, QString const& emailAddress
			, QString const& realName
			, QString const& nickName
			, QString const& gecos
			, int lang
			, int timeZone
			, QString const& contactInfo
			, bool enabled
			, bool privileged
			, QString const& password
			, QString const& comments
			, QString const& signature
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
			, QString const& pagerPhone)
	{
		rtclient_user_new(name.toLatin1().constData()
				, emailAddress.toLatin1().constData()
				, realName.toLatin1().constData()
				, nickName.toLatin1().constData()
				, gecos.toLatin1().constData()
				, static_cast<enum rt_lang>(lang)
				, static_cast<enum rt_timezone>(timeZone)
				, contactInfo.toLatin1().constData()
				, enabled
				, privileged
				, password.toLatin1().constData()
				, comments.toLatin1().constData()
				, signature.toLatin1().constData()
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
				, pagerPhone.toLatin1().constData());
	}

	void Client::search(QString const& owner)
	{
		QString query{"Owner='"};
		query.append(owner);
		query.append("'");
		rt_ticketlist* taskList = NULL;
		rtclient_ticket_search(&taskList, query.toLatin1().constData());
		if (taskList) emit foundTasks(taskList);
	}

	Client::~Client()
	{
		rtclient_cleanup();
	}

}
