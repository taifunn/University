import numpy as np
import matplotlib.pyplot as plt
import scipy.ndimage as nd

def to_float01(img):
    img = img.astype(np.float32)
    if img.max() > 1.0:
        img /= 255.0
    return img

def rgb_to_gray(img):
    if img.ndim == 2:
        return img
    r, g, b = img[..., 0], img[..., 1], img[..., 2]
    gray = 0.299 * r + 0.587 * g + 0.114 * b
    return gray

def edges_gray_gradient(img, thresh_rel=0.2):
    img = to_float01(img)
    img = nd.uniform_filter(img, size=3)
    gray = rgb_to_gray(img)
    gx = np.abs(np.roll(gray, -1, axis=1) - gray)
    gy = np.abs(np.roll(gray, -1, axis=0) - gray)
    grad = np.hypot(gx, gy)
    t = thresh_rel * grad.max()
    edges = grad > t
    return edges

def edges_color_distance(img, thresh_rel=0.2):
    img = to_float01(img)
    img = nd.uniform_filter(img, size=3)
    dx = img - np.roll(img, -1, axis=1)
    dy = img - np.roll(img, -1, axis=0)
    dist_x = np.linalg.norm(dx, axis=2)
    dist_y = np.linalg.norm(dy, axis=2)
    dist = np.hypot(dist_x, dist_y)
    t = thresh_rel * dist.max()
    edges = dist > t
    return edges

def outlines_to_rgb(edges):
    return np.dstack([edges.astype(np.float32)] * 3)

def show_outlines_comparison(img, thr1=0.2, thr2=0.2):
    e1 = edges_gray_gradient(img, thresh_rel=thr1)
    e2 = edges_color_distance(img, thresh_rel=thr2)
    o1 = outlines_to_rgb(e1)
    o2 = outlines_to_rgb(e2)
    fig, axs = plt.subplots(1, 3, figsize=(12, 4))
    axs[0].imshow(to_float01(img))
    axs[0].set_title("Obraz oryginalny")
    axs[0].axis("off")
    axs[1].imshow(o1)
    axs[1].set_title("Obrys gradient jasności")
    axs[1].axis("off")
    axs[2].imshow(o2)
    axs[2].set_title("Obrys odległość RGB")
    axs[2].axis("off")
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    import imageio.v3 as iio

    img = iio.imread("data/pic.png")

    show_outlines_comparison(img, thr1=0.05, thr2=0.05)