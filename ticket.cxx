#include <cstddef>
#include "qrtclient/ticket.hxx"

namespace RTClient {

	int TicketList::rowCount(QModelIndex const& parent) const
	{
		Q_UNUSED(parent)
		return tickets.count();
	}

	QVariant TicketList::data(QModelIndex const& index, int role) const
	{
		auto row = index.row();

		if (row < 0 || row >= tickets.count()) return QVariant();

		auto ticket = tickets[row];
		switch (role) {
			case IdRole:
				return ticket.id();
			case SubjectRole:
				return ticket.subject();
			default:
				return QVariant();
		}
	}

	QHash<int, QByteArray> TicketList::roleNames() const
	{
		return QHash<int, QByteArray>{
			{IdRole, "id"}
			, {SubjectRole, "subject"}
		};
	}

	void TicketList::addTicket(Ticket const& ticket)
	{
		beginInsertRows(QModelIndex(), rowCount(), rowCount());
		tickets << ticket;
		endInsertRows();
		emit rowCountChanged();
	}

	void TicketList::update(rtclient_ticketlist* ticketList)
	{
		if (ticketList) {
			for (size_t i = 0; i < ticketList->length; i++)
				addTicket(Ticket{ticketList->tickets[i]});
			rtclient_ticket_freelist(ticketList);
		}
		emit updated();
	}

}
