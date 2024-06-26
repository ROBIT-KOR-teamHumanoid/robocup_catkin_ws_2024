
(cl:in-package :asdf)

(defsystem "serial_mcu-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Motor_msg" :depends-on ("_package_Motor_msg"))
    (:file "_package_Motor_msg" :depends-on ("_package"))
    (:file "Mt2Serial_msg" :depends-on ("_package_Mt2Serial_msg"))
    (:file "_package_Mt2Serial_msg" :depends-on ("_package"))
    (:file "motion_end" :depends-on ("_package_motion_end"))
    (:file "_package_motion_end" :depends-on ("_package"))
    (:file "serial_msg" :depends-on ("_package_serial_msg"))
    (:file "_package_serial_msg" :depends-on ("_package"))
  ))