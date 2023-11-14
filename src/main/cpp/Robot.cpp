// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>

#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);


  

  m_motor1 = new TalonFX(3, "roborio");
  m_motor2 = new TalonFX(13, "roborio");
  m_motor3 = new TalonFX(15, "roborio"); //set to be inverted
  m_motor4 = new TalonFX(1, "roborio");//set to be inverted
  //1 18 7 0 drive motors for robot 3

  m_motor5 = new TalonFX(0, "roborio");

  m_motor3->SetInverted(true);
  m_motor4->SetInverted(true);
  m_motor1->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  m_motor2->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  m_motor3->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  m_motor4->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

  m_motor5->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

  double encoderCounts = m_motor1->GetSelectedSensorPosition();

  m_cancoder = new ctre::phoenix::sensors::CANCoder(0, "roborio"); //can coder 0 represents motor 0

}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
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
  fmt::print("Auto selected: {}\n", m_autoSelected);

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
}

void Robot::TeleopInit() {
  
}

void Robot::TeleopPeriodic() {

  


  double absoluteDeg = std::abs(m_cancoder->GetPosition());

  if (absoluteDeg < 40)
  {
     m_motor5->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.07);
  }
  

  /*
  m_speed += 0.001;

  if (m_speed > 0.3)
  {
    m_speed = 0.0;
  }
  
  


  m_motor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor3->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor4->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  std::cout << "SelectedSensorPosition: " << std::to_string(m_cancoder->GetPosition()) <<std::endl;
  std::cout << "IntegratedSensorAbsolute: " << std::to_string(m_cancoder->GetAbsolutePosition()) <<std::endl;
  */
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
