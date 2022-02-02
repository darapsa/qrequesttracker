#ifndef QRTCLIENT_TICKET_HXX
#define QRTCLIENT_TICKET_HXX

#include <QAbstractListModel>
#include <rtclient/ticket.h>

namespace RTClient {

class Ticket
{
	public:
		Ticket(rtclient_ticket* ticket) :
			m_id{ticket->id},
			m_subject{ticket->subject}
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

	public:
		enum TicketRoles {
			IdRole = Qt::UserRole + 1,
			SubjectRole
		};

		TicketList(QObject* parent = nullptr)
			: QAbstractListModel{parent} {}
		TicketList(struct rtclient_ticket** list,
				QObject* parent = nullptr);
		TicketList(TicketList const& list) { tickets = list.tickets; }
		~TicketList() {}

		int rowCount(QModelIndex const& parent
				= QModelIndex()) const Q_DECL_OVERRIDE;
		QVariant data(const QModelIndex& index,
				int role = Qt::DisplayRole
			     ) const Q_DECL_OVERRIDE;

	protected:
		QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

	private:
		QList<Ticket> tickets;
};

}

Q_DECLARE_METATYPE(RTClient::TicketList)

#endif
