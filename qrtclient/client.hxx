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
			void search(QString const& owner);

		signals:
			void logged(struct rt_user* user);
			void foundTasks(struct rt_ticketlist* list);
	};

}

#endif // QRTCLIENT_HXX
