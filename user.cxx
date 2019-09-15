#include <rtclient/client.h>
#include "qrtclient/user.hxx"

namespace RTClient {

	void User::setId(QString const& id)
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

	void User::setLang(QString const& lang)
	{
		if (m_lang != lang) {
			m_lang = lang;
			emit langChanged();
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
		}
	}

	void User::setLoggedIn(bool loggedIn)
	{
		if (m_loggedIn != loggedIn) {
			m_loggedIn = loggedIn;
			emit loggedInChanged();
		}
	}

	void User::update(rt_user* user)
	{
		if (user) {
			m_id = user->id;
			m_emailAddress = user->emailaddress;
			emit emailAddressChanged();
			m_realName = user->realname;
			emit realNameChanged();
			m_nickName = user->nickname;
			m_gecos = user->gecos;
			m_organization = user->organization;
			m_address1 = user->address1;
			m_address2 = user->address2;
			m_city = user->city;
			m_state = user->state;
			m_zip = user->zip;
			m_country = user->country;
			m_homePhone = user->homephone;
			m_workPhone = user->workphone;
			m_mobilePhone = user->mobilephone;
			m_pagerPhone = user->pagerphone;
			m_lang = user->lang;
			m_privileged = user->privileged;
			m_disabled = user->disabled;
			m_loggedIn = true;
			rtclient_user_free(user);
		} else {
			m_id = "";
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
			m_lang = "";
			m_privileged = false;
			m_disabled = true;
			m_loggedIn = false;
		}
	}

}
