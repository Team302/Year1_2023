// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>

#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

//using ctre::phoenix::motorcontrol::can::TalonFX;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  m_motor = new TalonFX(2, "roborio");
  m_motor2 = new TalonFX(12, "roborio");
  m_motor3 = new TalonFX(14, "roborio");
  m_motor4 = new TalonFX(0, "roborio");

  m_cancoder2 = new ctre::phoenix::sensors::CANCoder(12, "roborio");
  
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

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
  MoveAllMotors();

  //cancoder values in degrees, encoder is in encoder counts
  std::cout << "cancoder counts (relative): " << std::to_string(m_cancoder2->GetPosition())<<std::endl;
  std::cout << "cancoder counts (absolute): " << std::to_string(m_cancoder2->GetAbsolutePosition())<<std::endl;
  /*if(m_counter2 % 20 == 0){
  std::cout << "encoder counts (relative): " << std::to_string(m_motor2->GetSensorCollection().GetIntegratedSensorPosition())<<std::endl;
  //relative is in terms of all in one rotation 0-infinite
  std::cout << "encoder counts (absolute): " << std::to_string(m_motor2->GetSensorCollection().GetIntegratedSensorAbsolutePosition())<<std::endl;
  //absolute is between 0-2048
  }*/
/*  m_speed +=0.001;
  if (m_speed>1){
    m_speed=0.0;
  }

  m_motor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed); */
}

void Robot::MoveAllMotors() {
  /*m_speed = 0.5;
  m_speed2 = 0.09;
  m_speed3 = 0.3;
  m_speed4 = 0.45;*/

  m_motor3->SetInverted(true);
  //m_motor2->SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::Clockwise);

  m_motor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motor2->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed2);
  m_motor3->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed3);
  m_motor4->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed4);
  
  m_motor4->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  m_motor3->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  m_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

  double encoderCounts2 = m_motor2->GetSelectedSensorPosition();
  double cancoderDegreeAbsolute = m_cancoder2->GetAbsolutePosition();

  if (std::abs(cancoderDegreeAbsolute - 136) < 6.0){ //the 4 is so it can be 5 greater or 5 less than target
    m_speed2*=-1;
  }
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
