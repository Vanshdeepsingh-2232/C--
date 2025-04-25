// Function to plot the Lorenz attractor using separate 2D plots for each pair of axis
/*
void LorenzPlot() {
    // Create vectors to store the trajectory points
    static const int numPoints = 10000;
    static std::vector<float> xValues(numPoints), yValues(numPoints), zValues(numPoints);

    // Calculate the Lorenz attractor trajectory
    CalculateLorenzTrajectory(xValues, yValues, zValues);

    // Plot the trajectory in separate 2D plots for each pair of axes
    if (ImPlot::BeginPlot("Lorenz Attractor", nullptr, nullptr, ImVec2(800, 600))) {
        // Plot x-y trajectory
        ImPlot::PlotLine("X-Y", xValues.data(), yValues.data(), numPoints);
        ImPlot::EndPlot();

        // Plot x-z trajectory
        if (ImPlot::BeginPlot("Lorenz Attractor (X-Z)", nullptr, nullptr, ImVec2(800, 600))) {
            ImPlot::PlotLine("X-Z", xValues.data(), zValues.data(), numPoints);
            ImPlot::EndPlot();
        }

        // Plot y-z trajectory
        if (ImPlot::BeginPlot("Lorenz Attractor (Y-Z)", nullptr, nullptr, ImVec2(800, 600))) {
            ImPlot::PlotLine("Y-Z", yValues.data(), zValues.data(), numPoints);
            ImPlot::EndPlot();
        }
    }
}*/







//my classes
/*
class PerlinNoise {
public:
    PerlinNoise() {
        // Initialize permutation table with random values
        for (int i = 0; i < 256; ++i) {
            p[i] = i;
        }
        std::random_shuffle(std::begin(p), std::begin(p) + 256);
        for (int i = 0; i < 256; ++i) {
            p[256 + i] = p[i];
        }
    }

    double noise(double x) const {
        int X = static_cast<int>(std::floor(x)) & 255;
        x -= std::floor(x);
        double u = fade(x);
        return lerp(u, grad(p[X], x), grad(p[X + 1], x - 1)) * 2;
    }

private:
    int p[512];

    static double fade(double t) {
        return t * t * t * (t * (t * 6 - 15) + 10);
    }

    static double lerp(double t, double a, double b) {
        return a + t * (b - a);
    }

    static double grad(int hash, double x) {
        int h = hash & 15;
        double grad = 1 + (h & 7); // Gradient value from 1 to 8
        if (h & 8) grad = -grad; // Randomly invert gradient
        return grad * x;
    }
};*/



//my functions
/*
static void LinePlot(){
    
    static float xValues[1001], yValues[1001];
    for (int i = 0; i < 1001; i++) {
        xValues[i] = i * 0.001f;
        yValues[i] = 0.5f + 0.5f * sinf(50 * (xValues[i] + (float)ImGui::GetTime() / 10));
    }
    if (ImPlot::BeginPlot(" Sine Plotting realtime")) {
        ImPlot::SetupAxes("x", "y");
        ImPlot::PlotLine("f(x)", xValues, yValues, 1001);
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        ImPlot::EndPlot();
    }
}*/


/*
static void LinePlot() {
    static float xValues[1001], yValues[1001], yValuesCos[1001];
    for (int i = 0; i < 1001; i++) {
        float currentTime = ImGui::GetTime();
        xValues[i] = i * 0.001f;
        yValues[i] = 0.5f + 0.5f * sinf(50 * (xValues[i] + currentTime / 10));
        yValuesCos[i] = 0.5f + 0.5f * cosf(50 * (xValues[i] + currentTime / 10)); // Generate cosine wave
    }
    float yValuesProduct[1001]; // Array to store the product of sine and cosine waves
    for (int i = 0; i < 1001; i++) {
        yValuesProduct[i] = yValues[i] * yValuesCos[i]; // Element-wise multiplication
    }
    if (ImPlot::BeginPlot(" Sine-Cosine Product Plot", nullptr, nullptr, ImVec2(400, 300))) {
        ImPlot::SetupAxes("x", "y");
        ImPlot::PlotLine("f(x) * cos(x)", xValues, yValuesProduct, 1001); // Plot the product of sine and cosine waves
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        ImPlot::EndPlot();
    }
}
static void LinePlot() {
    static float frequency = 50.0f; // Initial frequency
    static float phase = 0.0f; // Initial phase
    static float xValues[1001], yValues[1001], yValuesCos[1001];
    for (int i = 0; i < 1001; i++) {
        float currentTime = ImGui::GetTime();
        xValues[i] = i * 0.001f;
        yValues[i] = 0.5f + 0.5f * sinf(frequency * (xValues[i] + phase));
        yValuesCos[i] = 0.5f + 0.5f * cosf(frequency * (xValues[i] + phase)); // Generate cosine wave
    }
    float yValuesProduct[1001]; // Array to store the product of sine and cosine waves
    for (int i = 0; i < 1001; i++) {
        yValuesProduct[i] = yValues[i] * yValuesCos[i]; // Element-wise multiplication
    }
    if (ImPlot::BeginPlot("Sine-Cosine Product Plot", nullptr, nullptr, ImVec2(400, 300))) {
        ImPlot::SetupAxes("x", "y");
        ImPlot::PlotLine("f(x) * cos(x)", xValues, yValuesProduct, 1001); // Plot the product of sine and cosine waves
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        //ImPlot::FitNextPlotAxes(true, true); // Automatically fit plot limits based on data
        ImPlot::EndPlot();
    }
    ImGui::SliderFloat("Frequency", &frequency, 1.0f, 100.0f); // Add slider to control frequency
    ImGui::SliderFloat("Phase", &phase, 0.0f, 2 * 3.14f); // Add slider to control phase
}
*/

/*
static void LinePlot() {
    static std::vector<double> xValues(1001); // Use vector instead of static array for dynamic size
    static std::vector<double> yValues(1001);

    // Generate random data
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(-1.0, 1.0); // Generate random numbers between -1 and 1

    // Update data
    for (int i = 0; i < 1001; ++i) {
        xValues[i] = i * 0.01;
        yValues[i] = distribution(generator); // Generate random y values
    }

    // Plot data
    if (ImPlot::BeginPlot("Real-Time Random Plot", nullptr, nullptr, ImVec2(400, 300))) {
        ImPlot::SetupAxes("x", "y");
        ImPlot::PlotLine("Random Points", xValues.data(), yValues.data(), xValues.size());
        ImPlot::EndPlot();
    }
}*/

/*
static void LinePlot() {
    static const int numPoints = 1001;
    static float xValues[numPoints], yValues[numPoints];

    // Generate Perlin noise values
    PerlinNoise perlin;
    for (int i = 0; i < numPoints; i++) {
        xValues[i] = i * 0.01f;
        yValues[i] = 0.05f + 0.05f * perlin.noise(50 * (xValues[i] + (float)ImGui::GetTime() / 0.00010f));
        
    }

    // Plot data
    if (ImPlot::BeginPlot("Perlin Noise Plot")) {
        ImPlot::SetupAxes("x", "y");
        ImPlot::PlotLine("Perlin Noise", xValues, yValues, numPoints);
        Sleep(100);
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);

        ImPlot::EndPlot();
    }
}
*/

/*
static void LinePlot() {
    static const int numPoints = 1001;
    static float xValues[numPoints], yValues[numPoints];

    // Generate x-values and corresponding y-values (logarithm of x)
    for (int i = 0; i < numPoints; i++) {
        xValues[i] = i * 0.001f;
        yValues[i] = std::log(xValues[i] + 1); // Natural logarithm (base e) of x
    }

    // Plot data
    if (ImPlot::BeginPlot("Logarithm Plot", nullptr, nullptr, ImVec2(400, 300))) {
        ImPlot::SetupAxes("x", "y");
        ImPlot::PlotLine("Logarithm", xValues, yValues, numPoints);
        ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        ImPlot::EndPlot();
    }
}
*/


/*
void PlotComplexCurve() {
    srand(time(NULL)); // Seed the random number generator

    constexpr int numPoints = 1000;
    std::vector<std::complex<double>> S(numPoints + 1, 0.0);

    // Generate random coefficients a, b, and c
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    int c = rand() % 9 + 1;
    int L = a * b * c;

    for (int n = 0; n <= L; ++n) {
        double m = n / static_cast<double>(a) + (n * n) / static_cast<double>(b) + (n * n * n) / static_cast<double>(c);
        S[n] = std::exp(std::complex<double>(0, 2 * PI * m));
    }

    // Calculate cumulative sum
    std::complex<double> sum(0.0);
    for (int n = 0; n <= L; ++n) {
        sum += S[n];
        S[n] = sum;
    }

    // Normalize
    std::complex<double> M = sum / static_cast<double>(L + 1);
    double R = std::abs(S[L]);
    for (int n = 0; n <= L; ++n) {
        S[n] = (S[n] - M) / R;
    }

    // Plot the curve
    if (ImPlot::BeginPlot("Complex Curve", nullptr, nullptr, ImVec2(800, 600))) {
        ImPlot::PlotLine("Curve", reinterpret_cast<double*>(S.data()), reinterpret_cast<double*>(S.data()) + L + 1, L + 1);
        ImPlot::EndPlot();
    }
}*/

//dynamic line
/*
void PlotDynamicLine(float time, int amplitude) {
    const int numPoints = 1001;
    static float xValues[numPoints], yValues[numPoints];

    // Generate X values based on time
    for (int i = 0; i < numPoints; ++i) {
        xValues[i] = (time + i * 0.01f); // Adjust according to your range and time scale
    }

    // Generate Y values based on X values and amplitude
    for (int i = 0; i < numPoints; ++i) {
        yValues[i] = amplitude * sinf(xValues[i]); // Adjust y-values based on amplitude
    }

    // Plot dynamic line
    if (ImPlot::BeginPlot("Dynamic Line Plot")) {
        ImPlot::PlotLine("f(x)", xValues, yValues, numPoints);
        ImPlot::EndPlot();
    }
}

*/

//ikk hor function

//this is FRACTAL TREE
/*
struct Branch {
    ImVec2 start;
    ImVec2 end;
};

void DrawBranch(const Branch& branch, int depth) {
    ImPlot::PushStyleColor(ImPlotCol_Line, ImVec4(0.5f, 0.3f, 0.0f, 1.0f - depth * 0.2f));
    ImPlot::PlotLine("Tree", &branch.start.x, &branch.start.y, 2);
    ImPlot::PopStyleColor();
}

void DrawFractalTree(const Branch& parentBranch, int depth, int maxDepth) {
    if (depth >= maxDepth)
        return;

    // Calculate new branches
    ImVec2 direction = ImVec2(parentBranch.end.x - parentBranch.start.x, parentBranch.end.y - parentBranch.start.y);
    ImVec2 normal = ImVec2(-direction.y, direction.x);
    ImVec2 offset1 = ImVec2(direction.x * 0.7f + normal.x * 0.3f, direction.y * 0.7f + normal.y * 0.3f);
    ImVec2 offset2 = ImVec2(direction.x * 0.7f - normal.x * 0.3f, direction.y * 0.7f - normal.y * 0.3f);

    Branch branch1 = { parentBranch.end, ImVec2(parentBranch.end.x + offset1.x, parentBranch.end.y + offset1.y) };
    Branch branch2 = { parentBranch.end, ImVec2(parentBranch.end.x + offset2.x, parentBranch.end.y + offset2.y) };

    // Draw the branches
    DrawBranch(branch1, depth);
    DrawBranch(branch2, depth);

    // Recursively draw child branches
    DrawFractalTree(branch1, depth + 1, maxDepth);
    DrawFractalTree(branch2, depth + 1, maxDepth);
}

void FractalTree(int maxDepth) {
    static const ImVec2 trunkStart = ImVec2(0.5f, 0.0f);
    static const ImVec2 trunkEnd = ImVec2(0.5f, 0.3f);
    Branch trunk = { trunkStart, trunkEnd };

    if (ImPlot::BeginPlot("Fractal Tree", nullptr, nullptr, ImVec2(800, 800))) {
        DrawBranch(trunk, 0);
        DrawFractalTree(trunk, 0, maxDepth);
        ImPlot::EndPlot();
    }
}

*/

//Double Pendulum
/*
// Global variables for the double pendulum simulation
constexpr float global_dt = 0.01f; // Fixed: renamed to avoid redefinition error
constexpr float g = 9.81f;
float L1 = 1.0f, L2 = 1.0f; // Lengths of the rods
float m1 = 1.0f, m2 = 1.0f; // Masses of the pendulums
float theta1 = 1.0f, theta2 = 1.5f; // Initial angles (global)
float omega1 = 0.0f, omega2 = 0.0f; // Initial angular velocities (global)

// Vectors to store the trajectory points
std::vector<float> theta1Values(1000), theta2Values(1000);

// Function to calculate the double pendulum motion
void CalculateDoublePendulumTrajectory(float& theta1, float& theta2, float& omega1, float& omega2) {
    float domega1, domega2;

    // Calculate the angular velocities and accelerations using the equations of motion
    float num1 = -g * (2 * m1 + m2) * sin(theta1);
    float num2 = -m2 * g * sin(theta1 - 2 * theta2);
    float num3 = -2 * sin(theta1 - theta2) * m2 * (omega2 * omega2 * L2 + omega1 * omega1 * L1 * cos(theta1 - theta2));
    float denom = L1 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2));

    domega1 = (num1 + num2 + num3) / denom;

    float num4 = 2 * sin(theta1 - theta2) * (omega1 * omega1 * L1 * (m1 + m2) + g * (m1 + m2) * cos(theta1) + omega2 * omega2 * L2 * m2 * cos(theta1 - theta2));
    float denom2 = L2 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2));

    domega2 = num4 / denom2;

    // Update the angles and angular velocities using Euler method
    theta1 += omega1 * global_dt; // Fixed: using global_dt to avoid redefinition
    theta2 += omega2 * global_dt;
    omega1 += domega1 * global_dt;
    omega2 += domega2 * global_dt;
}

// Function to plot the real-time double pendulum
void RealTimeDoublePendulumPlot() {
    // Update the double pendulum's motion and trajectory using global variables
    CalculateDoublePendulumTrajectory(::theta1, ::theta2, ::omega1, ::omega2);

    // Shift the trajectory buffers to make space for the new data points
    std::rotate(theta1Values.begin(), theta1Values.begin() + 1, theta1Values.end());
    std::rotate(theta2Values.begin(), theta2Values.begin() + 1, theta2Values.end());

    // Store the new points
    theta1Values.back() = ::theta1;
    theta2Values.back() = ::theta2;

    // Plot the angular positions (theta1 and theta2) over time
    if (ImPlot::BeginPlot("Double Pendulum Angles", nullptr, nullptr, ImVec2(800, 600))) {
        ImPlot::PlotLine("Theta1", theta1Values.data(), theta1Values.size());
        ImPlot::PlotLine("Theta2", theta2Values.data(), theta2Values.size());
        ImPlot::EndPlot();
    }
}

// Function to control pendulum parameters with ImGui sliders and buttons
void DoublePendulumControlPanel() {
    ImGui::SliderFloat("Length 1", &L1, 0.1f, 2.0f);
    ImGui::SliderFloat("Length 2", &L2, 0.1f, 2.0f);
    ImGui::SliderFloat("Mass 1", &m1, 0.1f, 5.0f);
    ImGui::SliderFloat("Mass 2", &m2, 0.1f, 5.0f);

    if (ImGui::Button("Reset Pendulum")) {
        // Reset angles and velocities
        ::theta1 = 1.0f; // Fixed: using global variables
        ::theta2 = 1.5f;
        ::omega1 = 0.0f;
        ::omega2 = 0.0f;
    }

    if (ImGui::Button("Run Simulation")) {
        RealTimeDoublePendulumPlot();  // Call this function to run the simulation
    }
}

// Main function to call everything in one click
void RenderDoublePendulumSimulation() {
    ImGui::Begin("Double Pendulum Control Panel");
    DoublePendulumControlPanel();  // Add controls for pendulum parameters
    ImGui::End();

    ImGui::Begin("Double Pendulum Simulation");
    RealTimeDoublePendulumPlot();  // Run and plot the double pendulum simulation
    ImGui::End();
}
*/


/*
// Generate a Fourier series approximation of a square wave
void GenerateFourierSquareWave(std::vector<float>& yValues, int numHarmonics, int numPoints) {
    yValues.resize(numPoints);
    float period = 2.0f * M_PI; // Period of the square wave
    float dx = period / numPoints;

    // Reset yValues to zero
    for (int i = 0; i < numPoints; ++i) {
        yValues[i] = 0.0f;
    }

    // Add odd harmonics to approximate the square wave
    for (int n = 1; n <= numHarmonics; n += 2) {
        for (int i = 0; i < numPoints; ++i) {
            float x = i * dx;
            yValues[i] += (4.0f / M_PI) * (sin(n * x) / n);
        }
    }
}

// Visualization using ImPlot and ImGui
void FourierSquareWaveVisualization() {
    static int numHarmonics = 1;
    static const int numPoints = 1000;
    static std::vector<float> yValues(numPoints);

    // Slider to control the number of harmonics
    ImGui::SliderInt("Number of Harmonics", &numHarmonics, 1, 25);

    // Generate the Fourier series approximation
    GenerateFourierSquareWave(yValues, numHarmonics, numPoints);

    // Plot the Fourier series approximation
    if (ImPlot::BeginPlot("Fourier Series Approximation of Square Wave", "x", "y", ImVec2(800, 400))) {
        std::vector<float> xValues(numPoints);
        for (int i = 0; i < numPoints; ++i) {
            xValues[i] = i * 2.0f * M_PI / numPoints;
        }

        ImPlot::PlotLine("Fourier Approximation", xValues.data(), yValues.data(), numPoints);
        ImPlot::EndPlot();
    }
}
*/


// Recursive function to draw the fractal tree
// Helper function to draw a line between two points using ImPlot
/*
void PlotLineBetweenPoints(float x1, float y1, float x2, float y2) {
    std::vector<float> xs = { x1, x2 };
    std::vector<float> ys = { y1, y2 };
    ImPlot::PlotLine("Branch", xs.data(), ys.data(), 2);
}
*/

// Recursive function to draw the fractal tree
// Recursive function to draw the fractal tree
/*
void DrawFractalTree(float x1, float y1, float angle, float length, int depth) {
    if (depth == 0) return;

    // Calculate the new branch position
    float x2 = x1 + length * cos(angle);
    float y2 = y1 + length * sin(angle);

    // Plot a line between (x1, y1) and (x2, y2)
    float xs[] = { x1, x2 };
    float ys[] = { y1, y2 };
    ImPlot::PlotLine("Branch", xs, ys, 2);  // Plotting just two points

    // Recursively draw the branches
    DrawFractalTree(x2, y2, angle - M_PI / 4, length * 0.7f, depth - 1);  // Left branch
    DrawFractalTree(x2, y2, angle + M_PI / 4, length * 0.7f, depth - 1);  // Right branch
}

// Visualization using ImPlot and ImGui
void FractalTreeVisualization() {
    static int depth = 5;  // Recursion depth
    static float angle = M_PI / 4;  // Branching angle
    static float length = 100.0f;  // Initial branch length

    // Create controls to adjust parameters
    ImGui::SliderInt("Recursion Depth", &depth, 1, 10);
    ImGui::SliderFloat("Branching Angle (Radians)", &angle, 0.0f, M_PI / 2);
    ImGui::SliderFloat("Branch Length", &length, 50.0f, 200.0f);

    // Begin plotting
    if (ImPlot::BeginPlot("Fractal Tree", nullptr, nullptr, ImVec2(800, 600))) {
        // Center of the plot (root of the tree)
        float xRoot = 400;
        float yRoot = 600;

        // Draw the tree starting from the root
        DrawFractalTree(xRoot, yRoot, -M_PI / 2, length, depth);

        ImPlot::EndPlot();
    }
}

*/
// Main code

/*
struct Point {
    float x;
    float y;
};

struct Edge {
    int src;
    int dest;
    float weight;
};

class Graph {
public:
    int V;
    std::vector<Point> points;
    std::vector<Edge> edges;


    Graph(int V) : V(V) {}

    void addPoint(float x, float y) {
        points.push_back({ x, y });
    }

    void addEdge(int src, int dest, float weight) {
        edges.push_back({ src, dest, weight });
    }

    std::vector<Edge> kruskalMST() {
        std::vector<Edge> result;

        // Sort edges by weight
        std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
            });

        std::vector<int> parent(V, -1);

        int e = 0;
        int i = 0;
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result.push_back(next_edge);
                unionSet(parent, x, y);
                ++e;
            }
        }

        return result;
    }

    void drawGraphWithMST() {
        // Print the number of points and edges to verify they are correct
        std::cout << "Number of points: " << points.size() << std::endl;
        std::cout << "Number of edges: " << edges.size() << std::endl;

        // Print the coordinates of each point
        for (const auto& point : points) {
            std::cout << "Point: (" << point.x << ", " << point.y << ")" << std::endl;
        }

        // Print the source, destination, and weight of each edge
        for (const auto& edge : edges) {
            std::cout << "Edge: (" << edge.src << " -> " << edge.dest << "), Weight: " << edge.weight << std::endl;
        }

        // Compute MST
        auto mst = kruskalMST();
        std::cout << "Number of edges in MST: " << mst.size() << std::endl;

        // Print the source and destination of each edge in the MST
        for (const auto& edge : mst) {
            std::cout << "MST Edge: (" << edge.src << " -> " << edge.dest << "), Weight: " << edge.weight << std::endl;
        }

        // Plot the graph and MST
        if (ImPlot::BeginPlot("Graph with MST", nullptr, nullptr, ImVec2(800, 800), ImPlotFlags_NoMenus, ImPlotAxisFlags_AutoFit)) {
            // Plot points
            std::vector<double> xs, ys;
            for (const auto& point : points) {
                xs.push_back(point.x);
                ys.push_back(point.y);
            }
            ImPlot::PlotScatter("Points", xs.data(), ys.data(), points.size());

            // Plot edges
            for (const auto& edge : edges) {
                const auto& src = points[edge.src];
                const auto& dest = points[edge.dest];
                ImPlot::PlotLine("Edges", &src.x, &src.y, 1);
                ImPlot::PlotLine("Edges", &dest.x, &dest.y, 1);
            }

            // Plot MST
            for (const auto& edge : mst) {
                const auto& src = points[edge.src];
                const auto& dest = points[edge.dest];
                ImPlot::PlotLine("MST", &src.x, &src.y, 1);
                ImPlot::PlotLine("MST", &dest.x, &dest.y, 1);
            }

            ImPlot::EndPlot();
        }
    }




private:
    int find(std::vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void unionSet(std::vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }
};

Graph generateRandomGraph(int numPoints) {
    Graph graph(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        float x = static_cast<float>(rand()) / RAND_MAX * 2 - 1;
        float y = static_cast<float>(rand()) / RAND_MAX * 2 - 1;
        graph.addPoint(x, y);
    }

    // Add edges between all pairs of points
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            float dist = std::hypot(graph.points[i].x - graph.points[j].x, graph.points[i].y - graph.points[j].y);
            graph.addEdge(i, j, dist);
        }
    }

    return graph;
}
*/























