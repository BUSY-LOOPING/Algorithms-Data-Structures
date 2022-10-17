import numpy as np

import matplotlib.pyplot as plt

from matplotlib.pyplot import ion, ioff, isinteractive, draw

import matplotlib.animation as animation

from celluloid import Camera

# for binary classification! no softmax here


def forward(X, W1, b1, W2, b2):

    # sigmoid

    # Z = 1 / (1 + np.exp( -(X.dot(W1) + b1) ))


    # tanh

    # Z = np.tanh(X.dot(W1) + b1)


    # relu

    Z = X.dot(W1) + b1

    Z = Z * (Z > 0)


    activation = Z.dot(W2) + b2

    Y = 1 / (1 + np.exp(-activation))

    return Y, Z



def predict(X, W1, b1, W2, b2):

    Y, _ = forward(X, W1, b1, W2, b2)

    return np.round(Y)



def derivative_w2(Z, T, Y):

    # Z is (N, M)

    return (T - Y).dot(Z)


def derivative_b2(T, Y):

    return (T - Y).sum()



def derivative_w1(X, Z, T, Y, W2):

    # dZ = np.outer(T-Y, W2) * Z * (1 - Z) # this is for sigmoid activation

    # dZ = np.outer(T-Y, W2) * (1 - Z * Z) # this is for tanh activation

    dZ = np.outer(T-Y, W2) * (Z > 0) # this is for relu activation

    return X.T.dot(dZ)



def derivative_b1(Z, T, Y, W2):

    # dZ = np.outer(T-Y, W2) * Z * (1 - Z) # this is for sigmoid activation

    # dZ = np.outer(T-Y, W2) * (1 - Z * Z) # this is for tanh activation

    dZ = np.outer(T-Y, W2) * (Z > 0) # this is for relu activation

    return dZ.sum(axis=0)



def get_log_likelihood(T, Y):

    return np.sum(T*np.log(Y) + (1-T)*np.log(1-Y))



def RedOrBlue(P, X_in, X_out):

    #sort into red or blue based on index in P: 0 = red, 1 = blue

    xred = []

    yred = []

    xblue = []

    yblue = []

    for i in range(0,len(P)):

        if i < 500 and P[i] == 0:

            xred.append(X_in[i,0])

            yred.append(X_in[i,1])

        elif i < 500 and P[i] == 1:

            xblue.append(X_in[i - 500,0])

            yblue.append(X_in[i - 500,1])

        elif i >= 500 and P[i] == 1:

            xblue.append(X_out[i-500,0])

            yblue.append(X_out[i-500,1])

        elif i >= 500 and P[i] == 0:

            xred.append(X_out[i-500,0])

            yred.append(X_out[i-500,1])


    xyred = np.concatenate([[xred], [yred]]).T

    xyblue = np.concatenate([[xblue], [yblue]]).T

    bigX = np.concatenate([ xyred, xyblue ])

    return bigX


def main():

    # donut example

    N = 1000

    R_inner = 5

    R_outer = 10


    # distance from origin is radius + random normal

    # angle theta is uniformly distributed between (0, 2pi)

    R1 = np.random.randn(N//2) + R_inner

    theta = 2*np.pi*np.random.random(N//2)

    X_inner = np.concatenate([[R1 * np.cos(theta)], [R1 * np.sin(theta)]]).T


    R2 = np.random.randn(N//2) + R_outer

    theta = 2*np.pi*np.random.random(N//2)

    X_outer = np.concatenate([[R2 * np.cos(theta)], [R2 * np.sin(theta)]]).T

    print(len(X_inner), X_inner.shape)

    print(len(X_outer), X_outer.shape)


    X = np.concatenate([ X_inner, X_outer ])


    Y = np.array([0]*(N//2) + [1]*(N//2))

    print(len(Y))

    plt.scatter(X[:,0], X[:,1], c=Y)

    plt.title("Generated Points")

    plt.show()



    n_hidden = 4

    W1 = np.random.randn(2, n_hidden)

    b1 = np.random.randn(n_hidden)

    W2 = np.random.randn(n_hidden)

    b2 = np.random.randn(1)

    LL = [] # keep track of log-likelihoods

    learning_rate = 0.00005

    regularization = 0.2

    last_error_rate = None

    camera = Camera(plt.figure())

    for i in range(500):

        pY, Z = forward(X, W1, b1, W2, b2)

        ll = get_log_likelihood(Y, pY)

        prediction = predict(X, W1, b1, W2, b2)

        er = np.abs(prediction - Y).mean()

        LL.append(ll)

        W2 += learning_rate * (derivative_w2(Z, Y, pY) - regularization * W2)

        b2 += learning_rate * (derivative_b2(Y, pY) - regularization * b2)

        W1 += learning_rate * (derivative_w1(X, Z, Y, pY, W2) - regularization * W1)

        b1 += learning_rate * (derivative_b1(Z, Y, pY, W2) - regularization * b1)

#        print(prediction - Y)

        if i % 2 == 0:

            print("i:", i, "ll:", ll, "classification rate:", 1 - er)

        bigX = RedOrBlue(prediction, X_inner, X_outer)

        string = "Classification Rate: {0:5}".format((1 - er))

        plt.title(string)


        plt.scatter(bigX[:,0], bigX[:,1], c=Y)

        camera.snap()



    anim = camera.animate(blit=True)

    #anim.save('dounut.html')


    plt.show()

    plt.plot(LL)

    plt.show()


if __name__ == '__main__':

    main()