// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
using ctre::phoenix::motorcontrol::can::TalonFX;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  m_motor = new TalonFX(1, "roborio");
  m_motor1 = new TalonFX(3, "roborio");
  m_motor2 = new TalonFX(13, "roborio");
  m_motor3 = new TalonFX(15, "roborio");


  std::cout << "Robot Init" << std::to_string(m_InitCounter) << std::endl;
  m_InitCounter++;
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
  std::cout << "Robot Periodic" << std::to_string(m_PeriCounter) << std::endl;
  m_PeriCounter++;
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
  std::cout << "Robot Teleop Init" << std::to_string(m_TeleInitCounter) << std::endl;
  m_TeleInitCounter++;
}

void Robot::TeleopPeriodic() {
  // std::cout << "Robot Teleop Periodic" << std::to_string(m_TelePeriCounter) << std::endl;
  // m_TelePeriCounter++;
  m_speed += 0.001;
  if(m_speed > 1.0){
    m_speed = 0.0;
  }
  m_motor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor1->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor3->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
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
