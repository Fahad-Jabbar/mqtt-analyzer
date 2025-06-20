/*!
 * @file light_switch.h
 * @author Michal Šlesár (xslesa01)
 * @author Erik Belko (xbelko02)
 * @brief Generic Light Switch widget
 */

#ifndef E_WIDGET_LIGHT_SWITCH_H
#define E_WIDGET_LIGHT_SWITCH_H

#include <QWidget>
#include <QString>
#include <QVariant>
#include <QJsonObject>

#include "../widget.h"

#include "../../explorer.h"

#include "ui_light_switch.h"

// Forward declarations
class Explorer;

/*! 
 * @brief Widget for controlling generic light switch
 * 
 * This widget listens on provided topic and accepts only "on" and "off" messages
 */
class WidgetLightSwitch : public Widget, public Ui::LightSwitchWidget
{
    Q_OBJECT

public:
    /*!
     * @brief Constructor
     * @param explorer Explorer instance
     */
    WidgetLightSwitch(Explorer* explorer);

    /*!
     * @brief Setup widget when added to dashboard
     * @returns true if successful, false otherwise
     */
    virtual bool Setup() override;

    /*!
     * @brief Setup widget when loaded from configuration file
     * @param data JSON object loaded from file
     * @returns true if successful, false otherwise
     */
    virtual bool Setup(QJsonObject data) override;

    /*!
     * @brief Render widget to dashboard
     * @returns true if successful, false otherwise
     */
    virtual bool Render() override;

    /*!
     * @brief Return config created by widget so it can be saved to configuration file
     * @returns Config in JSON format
     */
    virtual QJsonObject ExtractConfig() override;

private slots:   
    //! This slot is called when toggle button is clicked
    void onToggleButtonClicked();

    //! This slot is called when remove button is clicked
    void onRemoveButtonClicked();

    /*!
     * @brief This slot is called when client receives new message
     * @param topic Topic
     * @param data Image or string
     * @param local Whether the message was sent from us
     */
    virtual void messageReceived(QString topic, QVariant data, bool local) override;

private:
    //! Widget name
    QString name;

    //! Topic name
    QString topic;

    //! Whether the switch is turned on or off
    bool state = false;
};

#endif