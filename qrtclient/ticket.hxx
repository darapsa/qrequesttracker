#ifndef QRTCLIENT_TICKET_HXX
#define QRTCLIENT_TICKET_HXX

#include <QAbstractListModel>

struct rtclient_ticketlist;

namespace RTClient {

	class Ticket
	{
		public:
			Ticket(QString subject) : m_subject{subject} {}
			QString const& subject() const { return m_subject; }

		private:
			QString m_subject;
	};

	class TicketList : public QAbstractListModel
	{
		Q_OBJECT
		Q_PROPERTY(int rowCount READ rowCount NOTIFY rowCountChanged)

		public:
			enum TicketRoles {
				SubjectRole = Qt::UserRole + 1,
			};

			explicit TicketList(QObject* parent = nullptr)
				: QAbstractListModel{parent} {}

			int rowCount(QModelIndex const& parent
					= QModelIndex()) const Q_DECL_OVERRIDE;
			QVariant data(const QModelIndex& index
					, int role = Qt::DisplayRole
					) const Q_DECL_OVERRIDE;

		protected:
			QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

		signals:
			void updated();
			void rowCountChanged();

		private slots:
			void update(rtclient_ticketlist* ticketList);

		private:
			QList<Ticket> tickets;
			void addTicket(Ticket const& ticket);
	};

}

#endif // QRTCLIENT_TICKET_HXX
