/*!
 * @file light_switch.cpp
 * @author Michal Šlesár (xslesa01)
 * @author Erik Belko (xbelko02)
 * @brief WidgetLightSwitch implementation
 */

#include "light_switch.h"

#include <QString>
#include <QDateTime>
#include <QPushButton>
#include <QJsonObject>

#include "../../utils.h"
#include "../../explorer.h"

#include "ui_light_switch_settings.h"

WidgetLightSwitch::WidgetLightSwitch(Explorer* explorer) : Widget(explorer) {}

void WidgetLightSwitch::onToggleButtonClicked()
{
    if(state)
        explorer->publishData(topic, QString("off"));
    else
        explorer->publishData(topic, QString("on"));
}

void WidgetLightSwitch::onRemoveButtonClicked()
{
    explorer->removeWidget(this);
}

bool WidgetLightSwitch::Setup(QJsonObject data)
{
    name = data.value("name").toString();
    topic = data.value("topic").toString();
    return true;
}

bool WidgetLightSwitch::Setup()
{
    auto dialog = new QDialog(explorer);
    Ui_LightSwitchWidgetSettings settings;
    settings.setupUi(dialog);
    Utils::centerWidget(dialog, explorer);
    auto result = dialog->exec();

    topic = settings.topic->text();
    name = settings.name->text();

    delete dialog;
    return result;
}

QJsonObject WidgetLightSwitch::ExtractConfig()
{
    QJsonObject result;
    result.insert("widget", "LightSwitch");
    result.insert("name", name);
    result.insert("topic", topic);
    return result;
}

void WidgetLightSwitch::messageReceived(QString topic, QVariant data, [[maybe_unused]] bool local)
{
    if(this->topic != topic || data.userType() != QMetaType::QString)
        return;

    auto string = qvariant_cast<QString>(data);

    if(string != "on" && string != "off")
        return;

    labelStatus->setText(string);
    labelDate->setText(QDateTime::currentDateTime().toString("HH:mm:ss"));

    state = string == "on" ? true : false;
}

bool WidgetLightSwitch::Render()
{
    auto result = explorer->subscribeTopic(topic);

    if(result == 1)
    {
        explorer->setStatus("Wildcard is not supported");
        return false;
    }
    else if(result == 2)
    {
        explorer->setStatus("Invalid topic format");
        return false;
    }

    if(name.isEmpty())
    {
        explorer->setStatus("Widget name can not be empty");
        return false;
    }

    setupUi(this);

    labelName->setText(name);

    connect(buttonToggleSwitch, &QPushButton::clicked, this, &WidgetLightSwitch::onToggleButtonClicked);
    connect(buttonRemove, &QPushButton::clicked, this, &WidgetLightSwitch::onRemoveButtonClicked);

    return true;
}