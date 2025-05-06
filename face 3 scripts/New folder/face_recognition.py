import cv2
import numpy as np
import os
import json
import sys
import time

def print_to_qt(message):
    print(message, flush=True)

# Define absolute paths
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
MODEL_PATH = os.path.join(BASE_DIR, 'trainer.yml')
LABELS_PATH = os.path.join(BASE_DIR, 'labels.json')

# Initialize models
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

try:
    recognizer = cv2.face.LBPHFaceRecognizer_create()
    recognizer.read(MODEL_PATH)
    with open(LABELS_PATH) as f:
        labels = {int(k): v for k, v in json.load(f).items()}
except Exception as e:
    print_to_qt(f"ERROR|Initialization failed: {str(e)}")
    sys.exit(1)

def recognize_face():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print_to_qt("ERROR|Camera not accessible")
        return

    print_to_qt("STATUS|Recognition started - Press Q to quit")
    
    last_recognition = None
    last_time = 0
    
    while True:
        ret, frame = cap.read()
        if not ret:
            print_to_qt("ERROR|Frame capture failed")
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.2, 5, minSize=(60, 60))

        current_time = time.time()
        
        for (x, y, w, h) in faces:
            face_roi = gray[y:y+h, x:x+w]
            
            try:
                label, confidence = recognizer.predict(face_roi)
                
                if confidence < 45:  # Recognition threshold
                    name = labels.get(label, "Unknown")
                    
                    # Avoid duplicate notifications
                    if name != last_recognition or (current_time - last_time) > 2:
                        print_to_qt(f"RESULT|GRANTED|{name}|{confidence:.1f}")
                        last_recognition = name
                        last_time = current_time
                    
                    # Draw green box for recognized faces
                    cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
                    cv2.putText(frame, f"ACCESS: {name}", (x, y-10),
                              cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                else:
                    # Draw red box for unrecognized faces
                    cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 2)
                    cv2.putText(frame, "ACCESS DENIED", (x, y-10),
                              cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

            except Exception as e:
                print_to_qt(f"ERROR|Recognition failed: {str(e)}")

        cv2.imshow("Face Recognition", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
    print_to_qt("STATUS|Recognition ended")

if __name__ == '__main__':
    recognize_face()