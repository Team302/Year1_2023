// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include<iostream>
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

 m_motor=new TalonFX(12, "roborio");
m_motora=new TalonFX(2, "roborio");
 m_motorb=new TalonFX(15, "roborio");
 m_motorc=new TalonFX(0, "roborio");

 /* m_motor=new TalonFX(1, "roborio");
m_motora=new TalonFX(18, "roborio");
 m_motorb=new TalonFX(0, "roborio");
 m_motorc=new TalonFX(7, "roborio");
*/



m_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake); 
m_motora->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake); 
m_motorb->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake); 
m_motorc->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake); 

double encoderCounts = m_motor->GetSelectedSensorPosition();

m_cancoder=new ctre::phoenix::sensors::CANCoder(2,"roborio");

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

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

/*std::cout<<"Encoder Counts (Relative): "<<std::to_string(m_motor->GetSensorCollection().GetIntegratedSensorPosition()) << std::endl;
std::cout<<"Encoder Counts (Absolute): "<<std::to_string(m_motor->GetSensorCollection().GetIntegratedSensorAbsolutePosition()) << std::endl;*/

double position=m_cancoder->GetAbsolutePosition();
  m_motor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motora->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motorb->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);
  m_motorc->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, m_speed);

 if (std::abs(position) < 5.0)
{
  m_speed=m_speed*-1;
}


  /*m_speed+=0.001;
  if (m_speed > 1.0)
  {
    m_speed=0.0;
  }*/


   /*m_speeda+=0.001;
  if (m_speeda > 1.0)
  {
    m_speeda=0.0;
  }*/
  

  /*if (m_speedb > 1.0)
  {
    m_speedb=0.0;
  }*/
/*
   m_speedc+=0.001;
  if (m_speedc > 1.0)
  {
    m_speedc=0.0;
  }*/

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
