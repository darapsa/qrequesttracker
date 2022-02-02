#include <cstddef>
#include <rtclient.h>
#include "qrtclient/user.hxx"

namespace RTClient {

void User::setId(unsigned int id)
{
	if (m_id != id) {
		m_id = id;
		emit idChanged();
	}
}

void User::setName(QString const& name)
{
	if (m_name != name) {
		m_name = name;
		emit nameChanged();
	}
}

void User::setPassword(QString const& password)
{
	if (m_password != password) {
		m_password = password;
		emit passwordChanged();
	}
}

void User::setEmailAddress(QString const& emailAddress)
{
	if (m_emailAddress != emailAddress) {
		m_emailAddress = emailAddress;
		emit emailAddressChanged();
	}
}

void User::setRealName(QString const& realName)
{
	if (m_realName != realName) {
		m_realName = realName;
		emit realNameChanged();
	}
}

void User::setNickName(QString const& nickName)
{
	if (m_nickName != nickName) {
		m_nickName = nickName;
		emit nickNameChanged();
	}
}

void User::setOrganization(QString const& organization)
{
	if (m_organization != organization) {
		m_organization = organization;
		emit organizationChanged();
	}
}

void User::setAddress1(QString const& address1)
{
	if (m_address1 != address1) {
		m_address1 = address1;
		emit address1Changed();
	}
}

void User::setAddress2(QString const& address2)
{
	if (m_address2 != address2) {
		m_address2 = address2;
		emit address2Changed();
	}
}

void User::setCity(QString const& city)
{
	if (m_city != city) {
		m_city = city;
		emit cityChanged();
	}
}

void User::setState(QString const& state)
{
	if (m_state != state) {
		m_state = state;
		emit stateChanged();
	}
}

void User::setZip(QString const& zip)
{
	if (m_zip != zip) {
		m_zip = zip;
		emit zipChanged();
	}
}

void User::setCountry(QString const& country)
{
	if (m_country != country) {
		m_country = country;
		emit countryChanged();
	}
}

void User::setHomePhone(QString const& homePhone)
{
	if (m_homePhone != homePhone) {
		m_homePhone = homePhone;
		emit homePhoneChanged();
	}
}

void User::setWorkPhone(QString const& workPhone)
{
	if (m_workPhone != workPhone) {
		m_workPhone = workPhone;
		emit workPhoneChanged();
	}
}

void User::setMobilePhone(QString const& mobilePhone)
{
	if (m_mobilePhone != mobilePhone) {
		m_mobilePhone = mobilePhone;
		emit mobilePhoneChanged();
	}
}

void User::setPagerPhone(QString const& pagerPhone)
{
	if (m_pagerPhone != pagerPhone) {
		m_pagerPhone = pagerPhone;
		emit pagerPhoneChanged();
	}
}

void User::setContactInfo(QString const& contactInfo)
{
	if (m_contactInfo != contactInfo) {
		m_contactInfo = contactInfo;
		emit contactInfoChanged();
	}
}

void User::setComments(QString const& comments)
{
	if (m_comments != comments) {
		m_comments = comments;
		emit commentsChanged();
	}
}

void User::setSignature(QString const& signature)
{
	if (m_signature != signature) {
		m_signature = signature;
		emit signatureChanged();
	}
}

void User::setGecos(QString const& gecos)
{
	if (m_gecos != gecos) {
		m_gecos = gecos;
		emit gecosChanged();
	}
}

void User::setLang(rtclient_user_lang lang)
{
	if (m_lang != lang) {
		m_lang = lang;
		emit langChanged();
	}
}

void User::setTimeZone(rtclient_user_timezone timezone)
{
	if (m_timezone != timezone) {
		m_timezone = timezone;
		emit timezoneChanged();
	}
}

void User::setPrivileged(bool privileged)
{
	if (m_privileged != privileged) {
		m_privileged = privileged;
		emit privilegedChanged();
	}
}

void User::setDisabled(bool disabled)
{
	if (m_disabled != disabled) {
		m_disabled = disabled;
		emit disabledChanged();
	void User::update(rtclient_user* user)
	{
		if (user) {
			if (user->id) {
				m_id = user->id;
				emit idChanged();
			}
			if (user->email_address) {
				m_emailAddress = user->email_address;
				emit emailAddressChanged();
			}
			if (user->real_name) {
				m_realName = user->real_name;
				emit realNameChanged();
			}
			if (user->nick_name) {
				m_nickName = user->nick_name;
				emit nickNameChanged();
			}
			if (user->organization) {
				m_organization = user->organization;
				emit organizationChanged();
			}
			if (user->address1) {
				m_address1 = user->address1;
				emit address1Changed();
			}
			if (user->address2) {
				m_address2 = user->address2;
				emit address2Changed();
			}
			if (user->city) {
				m_city = user->city;
				emit cityChanged();
			}
			if (user->state) {
				m_state = user->state;
				emit stateChanged();
			}
			if (user->zip) {
				m_zip = user->zip;
				emit zipChanged();
			}
			if (user->country) {
				m_country = user->country;
				emit countryChanged();
			}
			if (user->home_phone) {
				m_homePhone = user->home_phone;
				emit homePhoneChanged();
			}
			if (user->work_phone) {
				m_workPhone = user->work_phone;
				emit workPhoneChanged();
			}
			if (user->mobile_phone) {
				m_mobilePhone = user->mobile_phone;
				emit mobilePhoneChanged();
			}
			if (user->pager_phone) {
				m_pagerPhone = user->pager_phone;
				emit pagerPhoneChanged();
			}
			if (user->gecos) {
				m_gecos = user->gecos;
				emit gecosChanged();
			}
			if (user->timezone) {
				m_timezone = user->timezone;
				emit timezoneChanged();
			}
			if (user->lang) {
				m_lang = user->lang;
				emit langChanged();
			}
			if (user->privileged) {
				m_privileged = user->privileged;
				emit privilegedChanged();
			}
			if (!user->disabled) {
				m_disabled = user->disabled;
				emit disabledChanged();
			}
			rtclient_user_free(user);
		} else {
			m_id = 0;
			m_name = "";
			m_password = "";
			m_emailAddress = "";
			m_realName = "";
			m_nickName = "";
			m_organization = "";
			m_address1 = "";
			m_address2 = "";
			m_city = "";
			m_state = "";
			m_zip = "";
			m_country = "";
			m_homePhone = "";
			m_workPhone = "";
			m_mobilePhone = "";
			m_pagerPhone = "";
			m_contactInfo = "";
			m_comments = "";
			m_signature = "";
			m_gecos = "";
			m_lang = RTCLIENT_USER_LANG_NONE;
			m_timezone = RTCLIENT_USER_TIMEZONE_NONE;
			m_privileged = false;
			m_disabled = true;
		}
	}
}

}
