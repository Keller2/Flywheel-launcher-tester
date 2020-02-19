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
#include <rev/CANEncoder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
//std::shared_ptr<WPI_TalonSRX> Neo1;
//std::shared_ptr<WPI_TalonSRX> Neo2;
std::shared_ptr<WPI_TalonSRX> Neo3;
//std::shared_ptr<rev::CANSparkMax> Neo1;
//std::shared_ptr<rev::CANSparkMax> Neo2;
std::shared_ptr<WPI_TalonFX> Neo1;
std::shared_ptr<WPI_TalonFX> Neo2;
nt::NetworkTableEntry NumberValue;
double velValue;
nt::NetworkTableEntry NumberValue2;
nt::NetworkTableEntry NumberValue3;
nt::NetworkTableEntry Velocity;
double MotorValue;
double MotorValue2;
double MotorValue3;
double RPM;
int rpms;
std::shared_ptr<nt::Value> value;
void Robot::RobotInit()
{

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  //frc::SmartDashboard::GetNumber("NumberSlider", NumberValue);
  //std::cout << NumberValue << std::endl;
  //frc::SmartDashboard::PutNumber("NumberSlider", 0);
  //Neo1.reset(new WPI_TalonSRX(7));
  //Neo2.reset(new WPI_TalonSRX(8));
  Neo3.reset(new WPI_TalonSRX(3));
  //_CANCoder = new CANCoder(5);
  //Neo2.reset(new rev::CANSparkMax(1, rev::CANSparkMaxLowLevel::MotorType::kBrushed));
  //Neo1.reset(new rev::CANSparkMax(2, rev::CANSparkMaxLowLevel::MotorType::kBrushed));
  NumberValue = frc::Shuffleboard::GetTab("Driver").Add("Motor1", 0).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  NumberValue2 = frc::Shuffleboard::GetTab("Driver").Add("Motor2", 0).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  NumberValue3 = frc::Shuffleboard::GetTab("Driver").Add("Motor3", 0).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  Neo1.reset(new WPI_TalonFX(5));
  Neo2.reset(new WPI_TalonFX(6));
  // double velValue = _CANCoder->GetVelocity();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{
  // frc::SmartDashboard::PutNumber("Value", 67);
  // double Velocity = Neo1->GetEncoder().GetVelocity();
  //frc::Shuffleboard::GetTab("Numbers");
  // frc::Shuffleboard::GetTab("Driver").Add("Speed",1).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  //frc::Shuffleboard::SelectTab("Speed");
  //frc::SmartDashboard::GetNumber("Speed", NumberValue);
  //velValue = _CANCoder->GetVelocity();
  //int rpms = velValue;
  Neo1->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);
  //frc::SmartDashboard::GetName("NumberSlider");
  // frc::SmartDashboard::GetNumber("NumberSlider", NumberValue);
  int kTimeoutMs = 30;
  Neo1->ConfigSetParameter((ParamEnum)430, 2, 0, 0, kTimeoutMs);
  double magVel_UnitsPer100ms = Neo1->GetSelectedSensorVelocity(0);
  double magRPM = magVel_UnitsPer100ms * 600 / 4096;
  std::cout << NumberValue.GetDouble(0) << "Talon1" << std::endl;
  //std::cout << NumberValue2.GetDouble(0) << "Talon2" << std::endl;
  //std::cout << NumberValue3.GetDouble(0) << "Talon3" << std::endl;
  frc::SmartDashboard::PutNumber("Rpm", magRPM);
  std::cout << "RPM" << magRPM << std::endl;
  //std::cout << velValue << std::endl;
  //std::cout << rpms << std::endl;
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
void Robot::AutonomousInit()
{
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom)
  {
    // Custom Auto goes here
  }
  else
  {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic()
{
  if (m_autoSelected == kAutoNameCustom)
  {
    // Custom Auto goes here
  }
  else
  {
    // Default Auto goes here
  }
  // std::cout << MotorValue << std::endl;
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
  MotorValue = NumberValue.GetDouble(1.0);
  MotorValue = MotorValue * -1;
  MotorValue2 = NumberValue2.GetDouble(1.0);
  MotorValue2 = MotorValue2 * -1;
  MotorValue3 = NumberValue3.GetDouble(1.0);
  Neo1->Set(MotorValue);
  Neo2->Set(MotorValue);
  Neo3->Set(MotorValue3);
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
