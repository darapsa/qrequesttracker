#include <cstddef>
#include "qrtclient/ticket.hxx"

namespace RTClient {

TicketList::TicketList(struct rtclient_ticket** list,
		QObject* parent)
	: QAbstractListModel{parent}
{
	size_t i = 0;
	while (list[i]) {
		beginInsertRows(QModelIndex(), rowCount(), rowCount());
		tickets << Ticket{list[i++]};
		endInsertRows();
	}
}

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
	return QHash<int, QByteArray>{{IdRole, "id"},
		{SubjectRole, "subject"}
	};
}

}
