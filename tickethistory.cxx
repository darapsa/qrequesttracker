#include <cstddef>
#include "qrtclient/tickethistory.hxx"

namespace RTClient {

TicketHistoryList::TicketHistoryList(struct rtclient_ticket_history** list,
		QObject* parent)
	: QAbstractListModel{parent}
{
	size_t i = 0;
	while (list[i]) {
		beginInsertRows(QModelIndex(), rowCount(), rowCount());
		histories << TicketHistory{list[i++]};
		endInsertRows();
	}
}

int TicketHistoryList::rowCount(QModelIndex const& parent) const
{
	Q_UNUSED(parent)
	return histories.count();
}

QVariant TicketHistoryList::data(QModelIndex const& index, int role) const
{
	auto row = index.row();

	if (row < 0 || row >= histories.count()) return QVariant();

	auto history = histories[row];
	switch (role) {
		case IdRole:
			return history.id();
		case TicketRole:
			return history.ticket();
		case TimeTakenRole:
			return history.timeTaken();
		case TypeRole:
			return history.type();
		case FieldRole:
			return history.field();
		case OldValueRole:
			return history.oldValue();
		case NewValueRole:
			return history.newValue();
		case DataRole:
			return history.data();
		case DescriptionRole:
			return history.description();
		case ContentRole:
			return history.content();
		case CreatorRole:
			return history.creator();
		case CreatedRole:
			return history.created();/*
		case AttachmentsRole:
			return history.attachments();*/
		default:
			return QVariant();
	}
}

QHash<int, QByteArray> TicketHistoryList::roleNames() const
{
	return QHash<int, QByteArray>{{IdRole, "id"},
		{TicketRole, "ticket"},
		{TimeTakenRole, "timeTaken"},
		{TypeRole, "type"},
		{FieldRole, "field"},
		{OldValueRole, "oldValue"},
		{NewValueRole, "newValue"},
		{DataRole, "data"},
		{DescriptionRole, "description"},
		{ContentRole, "content"},
		{CreatorRole, "creator"},
		{CreatedRole, "created"}/*,
		{AttachmentsRole, "attachments"}*/
	};
}

}
