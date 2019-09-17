#ifndef QRTCLIENT_HXX
#define QRTCLIENT_HXX

#include <QObject>
#include <rtclient/user.h>

struct rt_user;
struct rt_ticketlist;

namespace RTClient {

	class Client : public QObject
	{
		Q_OBJECT

		public:
			Client(QString const& url);
			~Client();

		public slots:
			void logIn(QString const& name, QString const& password);
			void userNew(QString const& name
					, QString const& password
					, QString const& emailAddress = nullptr
					, QString const& realName = nullptr
					, QString const& nickName = nullptr
					, QString const& organization = nullptr
					, QString const& address1 = nullptr
					, QString const& address2 = nullptr
					, QString const& city = nullptr
					, QString const& state = nullptr
					, QString const& zip = nullptr
					, QString const& country = nullptr
					, QString const& homePhone = nullptr
					, QString const& workPhone = nullptr
					, QString const& mobilePhone = nullptr
					, QString const& pagerPhone = nullptr
					, QString const& contactInfo = nullptr
					, QString const& comments = nullptr
					, QString const& signature = nullptr
					, QString const& gecos = nullptr
					, enum rt_lang lang = RT_LANG_NONE
					, enum rt_timezone timeZone = RT_TIMEZONE_NONE
					, bool disabled = false
					, bool privileged = false);
			void search(QString const& owner);

		signals:
			void logged(struct rt_user* user);
			void foundTickets(struct rt_ticketlist* list);
	};

}

#endif // QRTCLIENT_HXX
