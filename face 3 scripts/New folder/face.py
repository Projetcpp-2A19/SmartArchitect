import cv2
import numpy as np
import os

# Load the pre-trained face detection model
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Create a directory to store the captured faces if it doesn't exist
if not os.path.exists('dataset'):
    os.makedirs('dataset')

# Try to initialize the face recognizer
try:
    recognizer = cv2.face.LBPHFaceRecognizer_create()
except AttributeError:
    print("ERROR: The face module is missing from your OpenCV installation.")
    print("Please install opencv-contrib-python by running this command:")
    print("pip install opencv-contrib-python --user")
    print("\nAfter installation, restart this program.")
    exit(1)

# Create labels dictionary to map labels to names
labels = {}

# Function to capture and save the face
def capture_face(face_id):
    user_dir = os.path.join('dataset', f"User_{face_id}")
    os.makedirs(user_dir, exist_ok=True)
    cap = cv2.VideoCapture(0)  # Start the camera
    print(f"Capturing samples for {face_id}, press 'q' to exit.")
    count = 0
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Failed to access the camera.")
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # Convert to grayscale
        faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

        for (x, y, w, h) in faces:
            count += 1
            cv2.imwrite(f"{user_dir}/User_{face_id}_{count}.jpg", gray[y:y + h, x:x + w])  # Save the image

            # Draw rectangle around the face
            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

        cv2.imshow("Capturing Faces", frame)

        if cv2.waitKey(1) & 0xFF == ord('q') or count >= 20:  # Stop after 20 images or press 'q'
            break

    cap.release()
    cv2.destroyAllWindows()
    print(f"Face data for {face_id} saved successfully!")

# Function to train the model with saved faces
def train_model():
    faces = []
    labels_list = []
    label = 0

    for dir_name in os.listdir('dataset'):
        person_path = os.path.join('dataset', dir_name)
        if os.path.isdir(person_path):  # Ensure it's a directory
            for image_name in os.listdir(person_path):
                image_path = os.path.join(person_path, image_name)
                image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
                if image is not None:
                    faces.append(image)
                    labels_list.append(label)
            labels[label] = dir_name.split('_')[1]  # Extract user name from directory
            label += 1

    recognizer.train(faces, np.array(labels_list))
    recognizer.save('trainer.yml')
    print("Training complete and model saved as 'trainer.yml'.")

# Function to recognize the face and check access
def recognize_face():
    if not os.path.exists('trainer.yml'):
        print("Model not trained. Please train the model first.")
        return

    recognizer.read('trainer.yml')
    cap = cv2.VideoCapture(0)  # Start the camera

    while True:
        ret, frame = cap.read()
        if not ret:
            print("Failed to access the camera.")
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # Convert to grayscale
        faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

        for (x, y, w, h) in faces:
            face_roi = gray[y:y + h, x:x + w]  # Region of Interest (face)
            label_id, confidence = recognizer.predict(face_roi)  # Predict the face

            # If the confidence is low, it's a match
            if confidence < 50:
                name = labels.get(label_id, "Unknown")
                text = f"Access Granted: {name}"
                color = (0, 255, 0)
            else:
                text = "Access Denied"
                color = (0, 0, 255)

            cv2.putText(frame, text, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
            cv2.rectangle(frame, (x, y), (x + w, y + h), color, 2)

        cv2.imshow("Face Recognition", frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

# Main Function
def main():
    while True:
        print("\nMenu:")
        print("Press 'A' to capture and save a new face.")
        print("Press 'T' to train the model.")
        print("Press 'P' to recognize a face.")
        print("Press 'Q' to quit.")
        
        choice = input("Enter your choice: ").strip().lower()

        if choice == 'a':  # Capture a new face
            name = input("Enter your name: ").strip()
            capture_face(name)

        elif choice == 't':  # Train the model
            train_model()

        elif choice == 'p':  # Recognize face
            recognize_face()

        elif choice == 'q':  # Quit the program
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == '__main__':
    main()
