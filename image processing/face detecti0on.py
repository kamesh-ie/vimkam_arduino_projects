import cv2
import numpy as np

cam = cv2.VideoCapture(0)
while True:
    _,img = cam.read()
    cv2.imshow("original",img)
    face_cascade = cv2.CascadeClassifier('data.xml')
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Detect faces
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)
    # Draw rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
        face = img[y:y+h, x:x+w, :] # slicing only face from the frame
        face = cv2.resize(face, (50,50)) # resizing all faces to 5@ x 50, so that all images will be of same size
            # print(len(data))
        # if len(data) < 200: # condition for only storing 200 images
        #     data.append(face) # storing face data
    cv2.imshow('result',face) # to show the window
    cv2.waitKey(0)
    #27 - ASCII of Escape
    if cv2.waitKey(2) == 27: # or len(data) >= 200: # break Loop if escaped is pressed or 20@ faces are stored
        break
    cam.release() # release the camera object holded by opencV
    cv2.destroyAllWindows() # close all the windows opened by opency