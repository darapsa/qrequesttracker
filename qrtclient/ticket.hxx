#ifndef QRTCLIENT_TICKET_HXX
#define QRTCLIENT_TICKET_HXX

#include <QAbstractListModel>
#include <rtclient/ticket.h>
#include <rtclient/search.h>

struct rtclient_search_ticket_list;

namespace RTClient {

	class Ticket
	{
		public:
			Ticket(rtclient_ticket* ticket)
				: m_id{ticket->id}
				, m_subject{ticket->subject}
			{}
			unsigned int id() const { return m_id; }
			QString const& subject() const { return m_subject; }

		private:
			unsigned int m_id;
			QString m_subject;
	};

	class TicketList : public QAbstractListModel
	{
		Q_OBJECT
		Q_PROPERTY(int rowCount READ rowCount NOTIFY rowCountChanged)

		public:
			enum TicketRoles {
				IdRole = Qt::UserRole + 1,
				SubjectRole
			};

			explicit TicketList(QObject* parent = nullptr)
				: QAbstractListModel{parent} {}

			int rowCount(QModelIndex const& parent
					= QModelIndex()) const Q_DECL_OVERRIDE;
			QVariant data(const QModelIndex& index
					, int role = Qt::DisplayRole
					) const Q_DECL_OVERRIDE;

		public slots:
			void update(rtclient_search_ticket_list* list);

		protected:
			QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

		signals:
			void updated();
			void rowCountChanged();

		private:
			QList<Ticket> tickets;
			void addTicket(Ticket const& ticket);
	};

}

#endif // QRTCLIENT_TICKET_HXX
