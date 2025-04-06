import os
import numpy as np
from PIL import Image

def data_generator(root_dir, batch_size, target_size=(28, 28), color_mode='grayscale', num_classes=None):
    """
    Generates batches of images and labels without using external deep learning libraries.

    Parameters:
      root_dir (str): Root directory containing subdirectories for each class.
      batch_size (int): Number of samples per batch.
      target_size (tuple): Desired image size (height, width).
      color_mode (str): 'grayscale' or 'rgb'. If 'grayscale', images are converted.
      num_classes (int): Total number of classes. If None, inferred from subfolders.

    Yields:
      (X_batch, y_batch):
        - X_batch: NumPy array of shape (batch_size, target_size[0], target_size[1], channels).
        - y_batch: One-hot encoded label array of shape (batch_size, num_classes).
    """
    # Get sorted class names (subfolder names)
    classes = sorted([d for d in os.listdir(root_dir) if os.path.isdir(os.path.join(root_dir, d))])

    if num_classes is None:
        num_classes = len(classes)

    # Create a dictionary mapping class names to numerical labels
    class_to_label = {cls_name: idx for idx, cls_name in enumerate(classes)}

    # Collect all image paths and their respective labels
    image_paths, labels = [], []
    for cls_name in classes:
        cls_dir = os.path.join(root_dir, cls_name)
        for fname in os.listdir(cls_dir):
            if fname.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp')):
                image_paths.append(os.path.join(cls_dir, fname))
                labels.append(class_to_label[cls_name])

    num_samples = len(image_paths)
    indices = np.arange(num_samples)

    while True:  # Infinite loop for continuous batch generation
        np.random.shuffle(indices)  # Shuffle at the start of each epoch
        for start in range(0, num_samples, batch_size):
            end = min(start + batch_size, num_samples)
            batch_indices = indices[start:end]

            batch_images, batch_labels = [], []
            for idx in batch_indices:
                # Load image using PIL
                image = Image.open(image_paths[idx])

                # Convert to grayscale if needed
                if color_mode == 'grayscale':
                    image = image.convert('L')  # 'L' mode is for grayscale

                # Resize image
                image = image.resize(target_size, Image.Resampling.LANCZOS)

                # Convert image to NumPy array and normalize pixel values to [0,1]
                image_array = np.array(image) / 255.0

                # Ensure grayscale images have a single channel
                if color_mode == 'grayscale':
                    image_array = np.expand_dims(image_array, axis=-1)

                batch_images.append(image_array)
                batch_labels.append(labels[idx])

            # Convert lists to NumPy arrays
            X_batch = np.array(batch_images, dtype=np.float32)
            X_batch = X_batch.reshape(X_batch.shape[0], target_size[0]*target_size[1])

            # Convert labels to one-hot encoding
            y_batch = np.zeros((len(batch_labels), num_classes), dtype=np.float32)
            for i, label in enumerate(batch_labels):
                y_batch[i, label] = 1.0

            yield X_batch, y_batch


# classes = sorted([d for d in os.listdir(data_dir) if os.path.isdir(os.path.join(data_dir, d))])

# num_samples = 0
# for class_name in os.listdir(data_dir):
#     class_dir = os.path.join(data_dir, class_name)
#     if os.path.isdir(class_dir):
#         num_samples += len([fname for fname in os.listdir(class_dir)
#                             if fname.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp'))])
# steps_per_epoch = num_samples // batch_size

# gen = data_generator(data_dir, batch_size, target_size, color_mode='grayscale', num_classes=num_classes)

# model = NeuralNetworkClassifier(
#     layer_dims=layer_dims,
#     verbose=1,
#     learning_rate=2e-3,
#     dropout_prob = 0.1,
#     batch_size=batch_size,
#     early_stopping = True
# )

# Epoch 1/20 - Loss: 1.1571 - Acc: 0.6921 - LR: 0.001992 - Time: 548.43s
