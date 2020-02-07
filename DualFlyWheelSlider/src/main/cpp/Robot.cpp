/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
std::shared_ptr<WPI_TalonSRX> Neo7;
std::shared_ptr<WPI_TalonSRX> Neo8;
nt::NetworkTableEntry NumberValue;
nt::NetworkTableEntry NumberValue2;

double MotorValue;
double MotorValue2;
std::shared_ptr<nt::Value> value;
void Robot::RobotInit() {
 
  

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
//frc::SmartDashboard::GetNumber("NumberSlider", NumberValue); 
  //std::cout << NumberValue << std::endl;
//frc::SmartDashboard::PutNumber("NumberSlider", 0);
Neo7.reset(new WPI_TalonSRX(7));
Neo8.reset(new WPI_TalonSRX(8));
NumberValue =  frc::Shuffleboard::GetTab("Driver").Add("Motor1",0).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
NumberValue2 =  frc::Shuffleboard::GetTab("Driver").Add("Motor2",0).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
 // frc::SmartDashboard::PutNumber("Value", 67);
 
  //frc::Shuffleboard::GetTab("Numbers");
  // frc::Shuffleboard::GetTab("Driver").Add("Speed",1).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
//frc::Shuffleboard::SelectTab("Speed");
 //frc::SmartDashboard::GetNumber("Speed", NumberValue);
 
 //frc::SmartDashboard::GetName("NumberSlider");
// frc::SmartDashboard::GetNumber("NumberSlider", NumberValue);
std::cout << NumberValue.GetDouble(0)<< "Talon1" << std::endl; 
std::cout << NumberValue2.GetDouble(0)<< "Talon2" << std::endl; 
//frc::SimpleWidget::GetEntry();
 //NumberValue = frc::SmartDashboard::GetNumber("Speed", NumberValue);
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
 // std::cout << MotorValue << std::endl;
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  MotorValue = NumberValue.GetDouble(1.0);
  MotorValue = MotorValue  * -1;
  MotorValue2 = NumberValue2.GetDouble(1.0);
  MotorValue2 = MotorValue2  * -1;
  Neo7->Set(MotorValue);
  Neo8->Set(MotorValue2);
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
