#ifndef QRTCLIENT_CLIENT_HXX
#define QRTCLIENT_CLIENT_HXX

#include <QObject>
#include <rtclient/user.h>

struct rtclient_user;
struct rtclient_ticket_list;

namespace RTClient {

	class Client : public QObject
	{
		Q_OBJECT

		public:
			Client(char const* url, char const* certificate = nullptr);
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
					, rtclient_user_lang lang
						= RTCLIENT_USER_LANG_NONE
					, rtclient_user_timezone timezone
						= RTCLIENT_USER_TIMEZONE_NONE
					, bool disabled = false
					, bool privileged = false);
			void userShow(unsigned int id);
			void userShow(QString const& name);
			void ticketNew(QString const& queue = nullptr
					, QString const& requestor = nullptr
					, QString const& subject = nullptr
					, QString const& cc = nullptr
					, QString const& adminCc = nullptr
					, QString const& owner = nullptr
					, QString const& status = nullptr
					, QString const& priority = nullptr
					, QString const& initialPriority = nullptr
					, QString const& finalPriority = nullptr
					, QString const& timeEstimated = nullptr
					, QString const& starts = nullptr
					, QString const& due = nullptr
					, QString const& text = nullptr);
			void ticketSearch(QString const& owner);
			void ticketHistory(int id);

		signals:
			void loggedIn(QString const& name);
			void userShown(rtclient_user* user);
			void ticketSearched(rtclient_ticket_list* list);
	};

}

#endif // QRTCLIENT_CLIENT_HXX
