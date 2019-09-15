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
