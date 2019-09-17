#ifndef QRTCLIENT_HXX
#define QRTCLIENT_HXX

#include <QObject>

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
					, QString const& pagerPhone);
			void search(QString const& owner);

		signals:
			void logged(struct rt_user* user);
			void foundTasks(struct rt_ticketlist* list);
	};

}

#endif // QRTCLIENT_HXX
