#ifndef QRTCLIENT_TICKET_HISTORY_HXX
#define QRTCLIENT_TICKET_HISTORY_HXX

#include <QAbstractListModel>
#include <QDateTime>
#include <rtclient/ticket.h>

namespace RTClient {

class TicketHistory
{
	public:
		TicketHistory(struct rtclient_ticket_history* history) :
			m_id{history->id},
			m_ticket{history->ticket},
			m_timeTaken{history->time_taken},
			m_type{history->type},
			m_description{history->description},
			m_content{history->content},
			m_creator{history->creator}
		{
			if (history->field)
				m_field = QString{history->field};
			if (history->old_value)
				m_oldValue = QString{history->old_value};
			if (history->new_value)
				m_newValue = QString{history->new_value};
			if (history->data)
				m_data = QString{history->data};
		}
		unsigned int id() const { return m_id; }
		unsigned int ticket() const { return m_ticket; }
		unsigned int timeTaken() const { return m_timeTaken; }
		//Q_ENUM(rtclient_ticket_history_type)
		rtclient_ticket_history_type type() const { return m_type; }
		QString const& field() const { return m_field; }
		QString const& oldValue() const { return m_oldValue; }
		QString const& newValue() const { return m_newValue; }
		QString const& data() const { return m_data; }
		QString const& description() const { return m_description; }
		QString const& content() const { return m_content; }
		QString const& creator() const { return m_creator; }
		QDateTime const& created() const { return m_created; }

	private:
		unsigned int m_id;
		unsigned int m_ticket;
		unsigned int m_timeTaken;
		rtclient_ticket_history_type m_type;
		QString m_field;
		QString m_oldValue;
		QString m_newValue;
		QString m_data;
		QString m_description;
		QString m_content;
		QString m_creator;
		QDateTime m_created;
		//QList<TicketHistoryAttachment>* m_attachments;
};

class TicketHistoryList : public QAbstractListModel
{
	Q_OBJECT

	public:
		enum TicketHistoryRoles {
			IdRole = Qt::UserRole + 1,
			TicketRole,
			TimeTakenRole,
			TypeRole,
			FieldRole,
			OldValueRole,
			NewValueRole,
			DataRole,
			DescriptionRole,
			ContentRole,
			CreatorRole,
			CreatedRole/*,
			AttachmentsRole*/
		};

		TicketHistoryList(QObject* parent = nullptr)
			: QAbstractListModel{parent} {}
		TicketHistoryList(struct rtclient_ticket_history** list,
				QObject* parent = nullptr);
		TicketHistoryList(TicketHistoryList const& list)
		{
			histories = list.histories;
		}
		~TicketHistoryList() {}

		int rowCount(QModelIndex const& parent
				= QModelIndex()) const Q_DECL_OVERRIDE;
		QVariant data(const QModelIndex& index,
				int role = Qt::DisplayRole
			     ) const Q_DECL_OVERRIDE;

	protected:
		QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

	private:
		QList<TicketHistory> histories;
};

}

Q_DECLARE_METATYPE(RTClient::TicketHistoryList)

#endif
