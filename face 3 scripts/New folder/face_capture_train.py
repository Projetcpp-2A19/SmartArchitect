import cv2
import numpy as np
import os
import json

# Define absolute paths for all files
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATASET_DIR = os.path.join(BASE_DIR, 'dataset')
MODEL_PATH = os.path.join(BASE_DIR, 'trainer.yml')
LABELS_PATH = os.path.join(BASE_DIR, 'labels.json')

# Load the pre-trained face detection model
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Create dataset directory if it doesn't exist
os.makedirs(DATASET_DIR, exist_ok=True)

# Initialize face recognizer
try:
    recognizer = cv2.face.LBPHFaceRecognizer_create()
except AttributeError:
    print("ERROR: Install opencv-contrib-python package")
    exit(1)

def capture_face(face_id):
    """Capture and save face images"""
    user_dir = os.path.join(DATASET_DIR, f"User_{face_id}")
    os.makedirs(user_dir, exist_ok=True)
    
    cap = cv2.VideoCapture(0)
    print(f"Capturing samples for {face_id} (Press 'q' to exit)")
    
    count = 0
    while count < 20:  # Capture 20 images
        ret, frame = cap.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.1, 5, minSize=(30, 30))

        for (x, y, w, h) in faces:
            count += 1
            img_path = os.path.join(user_dir, f"User_{face_id}_{count}.jpg")
            cv2.imwrite(img_path, gray[y:y+h, x:x+w])
            
            cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
            cv2.putText(frame, f"Captures: {count}/20", (x, y-10), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)

        cv2.imshow("Capturing Faces", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
    print(f"Saved {count} images for {face_id}")

def train_model():
    """Train the face recognition model"""
    faces = []
    labels = []
    name_mapping = {}
    
    if not os.path.exists(DATASET_DIR) or not os.listdir(DATASET_DIR):
        print("No face data found. Capture faces first.")
        return False

    print("\nTraining model with:")
    for label, dir_name in enumerate(os.listdir(DATASET_DIR)):
        user_dir = os.path.join(DATASET_DIR, dir_name)
        if not os.path.isdir(user_dir):
            continue
            
        user_name = dir_name.split('_')[1]
        name_mapping[label] = user_name
        print(f"- {user_name} (ID: {label})")
        
        for img_name in [f for f in os.listdir(user_dir) if f.endswith('.jpg')]:
            img_path = os.path.join(user_dir, img_name)
            img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
            if img is not None:
                faces.append(img)
                labels.append(label)

    if not faces:
        print("No valid images found.")
        return False

    recognizer.train(faces, np.array(labels))
    recognizer.save(MODEL_PATH)
    
    with open(LABELS_PATH, 'w') as f:
        json.dump(name_mapping, f)
    
    print(f"\nTraining complete. Model saved to:\n{MODEL_PATH}\n{LABELS_PATH}")
    return True

def main():
    while True:
        print("\nMenu:")
        print("1. Capture new face")
        print("2. Train model")
        print("3. Exit")
        
        choice = input("Choice (1-3): ").strip()
        
        if choice == '1':
            name = input("Person's name: ").strip().lower()
            if name:
                capture_face(name)
        elif choice == '2':
            train_model()
        elif choice == '3':
            break
        else:
            print("Invalid choice")

if __name__ == '__main__':
    main()