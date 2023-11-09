// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
using namespace ctre::phoenix::motorcontrol::can;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;
  void MoveAllMotors();

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  TalonFX* m_motor;
  TalonFX* m_motor2;
  TalonFX* m_motor3;
  TalonFX* m_motor4;

  double m_speed = 0.0;
  int m_counter = 0;
  double m_speed2 = 0.0;
  int m_counter2 = 0;
  double m_speed3 = 0.0;
  int m_counter3 = 0;
  double m_speed4 = 0.0;
  int m_counter4 = 0;
};
