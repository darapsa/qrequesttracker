#ifndef QRTCLIENT_USER_HXX
#define QRTCLIENT_USER_HXX

#include <QObject>
#include <rtclient/user.h>

struct rtclient_user;

namespace RTClient {

class User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(unsigned int id READ id WRITE setId NOTIFY idChanged)
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
	Q_PROPERTY(QString emailAddress READ emailAddress WRITE setEmailAddress NOTIFY emailAddressChanged)
	Q_PROPERTY(QString realName READ realName WRITE setRealName NOTIFY realNameChanged)
	Q_PROPERTY(QString nickName READ nickName WRITE setNickName NOTIFY nickNameChanged)
	Q_PROPERTY(QString organization READ organization WRITE setOrganization NOTIFY organizationChanged)
	Q_PROPERTY(QString address1 READ address1 WRITE setAddress1 NOTIFY address1Changed)
	Q_PROPERTY(QString address2 READ address2 WRITE setAddress2 NOTIFY address2Changed)
	Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
	Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged)
	Q_PROPERTY(QString zip READ zip WRITE setZip NOTIFY zipChanged)
	Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
	Q_PROPERTY(QString homePhone READ homePhone WRITE setHomePhone NOTIFY homePhoneChanged)
	Q_PROPERTY(QString workPhone READ workPhone WRITE setWorkPhone NOTIFY workPhoneChanged)
	Q_PROPERTY(QString mobilePhone READ mobilePhone WRITE setMobilePhone NOTIFY mobilePhoneChanged)
	Q_PROPERTY(QString pagerPhone READ pagerPhone WRITE setPagerPhone NOTIFY pagerPhoneChanged)
	Q_PROPERTY(QString contactInfo READ contactInfo WRITE setContactInfo NOTIFY contactInfoChanged)
	Q_PROPERTY(QString comments READ comments WRITE setComments NOTIFY commentsChanged)
	Q_PROPERTY(QString signature READ signature WRITE setSignature NOTIFY signatureChanged)
	Q_PROPERTY(QString gecos READ gecos WRITE setGecos NOTIFY gecosChanged)
	Q_PROPERTY(rtclient_user_lang lang READ lang WRITE setLang NOTIFY langChanged)
	Q_PROPERTY(rtclient_user_timezone timezone READ timezone WRITE setTimeZone NOTIFY timezoneChanged)
	Q_PROPERTY(bool privileged READ privileged WRITE setPrivileged NOTIFY privilegedChanged)
	Q_PROPERTY(bool disabled READ disabled WRITE setDisabled NOTIFY disabledChanged)

	public:
		User(struct rtclient_user* user, QObject* parent = nullptr) :
			QObject{parent},
			m_id{user->id},
			m_name{QString{user->name}},
			m_password{QString{user->password}},
			m_emailAddress{user->email_address
				? QString{user->email_address}
				: ""},
			m_realName{QString{user->real_name}},
			m_nickName{QString{user->nick_name}},
			m_organization{QString{user->organization}},
			m_address1{QString{user->address1}},
			m_address2{QString{user->address2}},
			m_city{QString{user->city}},
			m_state{QString{user->state}},
			m_zip{QString{user->zip}},
			m_country{QString{user->country}},
			m_homePhone{QString{user->home_phone}},
			m_workPhone{QString{user->work_phone}},
			m_mobilePhone{QString{user->mobile_phone}},
			m_pagerPhone{QString{user->pager_phone}},
			m_contactInfo{QString{user->contact_info}},
			m_comments{QString{user->comments}},
			m_signature{QString{user->signature}},
			m_gecos{QString{user->gecos}},
			m_lang{user->lang},
			m_timezone{user->timezone},
			m_privileged{user->privileged},
			m_disabled{user->disabled}
		{}
		~User() {}

		unsigned int id() const { return m_id; }
		QString const& name() const { return m_name; }
		QString const& password() const { return m_password; }
		QString const& emailAddress() const { return m_emailAddress; }
		QString const& realName() const { return m_realName; }
		QString const& nickName() const { return m_nickName; }
		QString const& organization() const { return m_organization; }
		QString const& address1() const { return m_address1; }
		QString const& address2() const { return m_address2; }
		QString const& city() const { return m_city; }
		QString const& state() const { return m_state; }
		QString const& zip() const { return m_zip; }
		QString const& country() const { return m_country; }
		QString const& homePhone() const { return m_homePhone; }
		QString const& workPhone() const { return m_workPhone; }
		QString const& mobilePhone() const { return m_mobilePhone; }
		QString const& pagerPhone() const { return m_pagerPhone; }
		QString const& contactInfo() const { return m_contactInfo; }
		QString const& comments() const { return m_comments; }
		QString const& signature() const { return m_signature; }
		QString const& gecos() const { return m_gecos; }
		rtclient_user_lang lang() const { return m_lang; }
		rtclient_user_timezone timezone() const { return m_timezone; }
		bool privileged() const { return m_privileged; }
		bool disabled() const { return m_disabled; }

		void setId(unsigned int id);
		void setName(QString const& name);
		void setPassword(QString const& password);
		void setEmailAddress(QString const& emailAddress);
		void setRealName(QString const& realName);
		void setNickName(QString const& nickName);
		void setOrganization(QString const& organization);
		void setAddress1(QString const& address1);
		void setAddress2(QString const& address2);
		void setCity(QString const& city);
		void setState(QString const& state);
		void setZip(QString const& zip);
		void setCountry(QString const& country);
		void setHomePhone(QString const& homePhone);
		void setWorkPhone(QString const& workPhone);
		void setMobilePhone(QString const& mobilePhone);
		void setPagerPhone(QString const& pagerPhone);
		void setContactInfo(QString const& contactInfo);
		void setComments(QString const& comments);
		void setSignature(QString const& signature);
		void setGecos(QString const& gecos);
		void setLang(rtclient_user_lang lang);
		void setTimeZone(rtclient_user_timezone timezone);
		void setPrivileged(bool privileged);
		void setDisabled(bool disabled);
		public slots:
			void update(rtclient_user* user);

	signals:
		void idChanged();
		void nameChanged();
		void passwordChanged();
		void emailAddressChanged();
		void realNameChanged();
		void nickNameChanged();
		void organizationChanged();
		void address1Changed();
		void address2Changed();
		void cityChanged();
		void stateChanged();
		void zipChanged();
		void countryChanged();
		void homePhoneChanged();
		void workPhoneChanged();
		void mobilePhoneChanged();
		void pagerPhoneChanged();
		void contactInfoChanged();
		void commentsChanged();
		void signatureChanged();
		void gecosChanged();
		void langChanged();
		void timezoneChanged();
		void privilegedChanged();
		void disabledChanged();

	private:
		unsigned int m_id;
		QString m_name;
		QString m_password;
		QString m_emailAddress;
		QString m_realName;
		QString m_nickName;
		QString m_organization;
		QString m_address1;
		QString m_address2;
		QString m_city;
		QString m_state;
		QString m_zip;
		QString m_country;
		QString m_homePhone;
		QString m_workPhone;
		QString m_mobilePhone;
		QString m_pagerPhone;
		QString m_contactInfo;
		QString m_comments;
		QString m_signature;
		QString m_gecos;
		rtclient_user_lang m_lang;
		rtclient_user_timezone m_timezone;
		bool m_privileged;
		bool m_disabled;
	};

}

#endif
