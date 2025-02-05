## 1. Urban Planning and Zonning ##
Urban Planning and Zoning is the process of designing and organizing the physical layout and infrastructure of urban areas to meet the needs of residents, businesses, and the environment. It involves strategic decision-making to balance land use, population density, transportation, and environmental sustainability.

For Urban Planning and Zoning, the most suitable algorithm is a Graph Algorithm, such as the Minimum Spanning Tree (MST). MST helps design efficient infrastructure networks (e.g., roads, utilities) by minimizing the total cost of connecting different zones. Here, we are using Prim's algorithm since it is simple and efficient.

![Project Screenshot](assets/Screenshot 2024-12-23 141809.png)
## Key Aspects ##
- Focuses on creating livable, sustainable cities by addressing housing, transportation, public spaces, utilities, and infrastructure.
- Incorporates short-term and long-term goals for economic growth, environmental protection, and social equity.  
-  A regulatory tool that divides urban areas into zones or districts (e.g., residential, commercial, industrial).
- **Time Complexity**:O(Elog(V))
- **Space Complexity**:O(V)
- **code**: [Prim](https://github.com/01fe23bcs120/Bussiness-Cases.github.io/blob/main/Urban_Planning.cpp)

## 2. Energy Distribuion Network ##
Energy distribution networks are critical infrastructures that transport electricity from power generation facilities to end consumers. They include power lines, substations, transformers, and distribution nodes. The main goals of energy distribution networks are to ensure efficient, reliable, and cost-effective delivery of electricity while minimizing losses and meeting fluctuating demand.  

For energy distribution networks, Graph Algorithms Kruskal's Algorithm which is highly suitable for designing Minimum Spanning Trees (MSTs). MSTs minimize the total cost of connecting all nodes (e.g., substations, transformers) while maintaining connectivity, making them ideal for planning efficient distribution networks.

![Project Screenshot](assets/Screenshot 2024-12-25 170359.png)

## Key Aspects ##
- Optimizing energy flow to minimize losses.  
- Balancing load across the network.  
- Ensuring redundancy and fault tolerance for reliability.
- **Time Complexity**:O(Elog(E))
- **Space Complexity**:O(V)
- **code**: [Kruskal](https://github.com/01fe23bcs120/Bussiness-Cases.github.io/blob/main/Energy_Dist.cpp) 

## 3. Hospital Resource Management ##
  Hospital resource management involves the efficient allocation and utilization of resources like beds, staff, medical equipment, and facilities to provide effective patient care. Key challenges include handling fluctuating patient demand, optimizing resource allocation, and minimizing delays in critical situations.

  In hospital resource management, Sorting Algorithms i.e., Heapsort are suitable for organizing resources or tasks based on priority, availability, or demand. For example, sorting patients based on the severity of their condition ensures critical cases are addressed first.

## Key Aspects ##
- Scheduling surgeries and appointments.
- Allocating beds to patients.
- Optimizing staff duty rosters.
- Managing inventory for medical supplies.
- Time Complexity:O(nlog(n))
- Space Complexity:O(n)
- **code**: [HeapSort](https://github.com/01fe23bcs120/Bussiness-Cases.github.io/blob/main/Medical_Resource.cpp)

## 4. Air Quality Monitoring ##
  Air quality monitoring involves measuring the concentration of pollutants in the air, such as carbon dioxide (CO₂), nitrogen dioxide (NO₂), particulate matter (PM2.5/PM10), and ozone (O₃). The goal is to assess air pollution levels, predict trends, and ensure compliance with environmental standards. Challenges include managing data from numerous sensors, analyzing trends, and identifying pollution hotspots.

  Trees can be used in air quality monitoring to organize and query data hierarchically. For example, a Binary Search Tree (BST) can store air quality readings indexed by timestamps, enabling efficient insertion, deletion, and range queries (e.g., finding readings within a specific time range).

## Key Aspects ##
- Collecting and storing sensor data efficiently.
- Detecting patterns or anomalies in air quality over time.
- Mapping pollution levels across regions.
- Time Complexity:O(log(n))
- Space Complexity:O(n)
- **code**: [Binary Search Tree](https://github.com/01fe23bcs120/Bussiness-Cases.github.io/blob/main/Air_Quality.cpp)

## 5. Pedestrian and Bicycle Path Planning ##
  Pedestrian and bicycle path planning focuses on creating safe, efficient, and accessible pathways for walking and cycling within urban areas. The goal is to design networks of pathways that connect key locations (e.g., parks, schools, transit hubs) while minimizing travel time, ensuring safety, and promoting environmental sustainability. Path planning involves considering various factors, such as terrain, traffic conditions, and the availability of infrastructure.

  For pedestrian and bicycle path planning, Graph Algorithms are the most suitable choice. This is because the problem can be modeled as a graph, where:
Vertices (nodes) represent locations (e.g., intersections, landmarks).
Edges represent paths between locations (e.g., roads, sidewalks, bicycle lanes).
Graph algorithms, particularly Shortest Path algorithms like Dijkstra's Algorithm , is ideal for finding the most efficient paths between locations while considering constraints such as traffic, road conditions, or path length.

![Project Screenshot](assets/Screenshot 2024-12-25 171906.png)

## Key Aspects ##
- Optimizing routes: Finding the shortest or safest routes between locations.
- Safety considerations: Avoiding busy roads, intersections, or areas with high traffic.
- Environmental factors: Ensuring paths are integrated with the surrounding environment and land use.
- Accessibility: Designing paths that accommodate people with disabilities and varying cycling skill levels.
- Time Complexity:O(Elog(V*E))
- Space Complexity:O(V)
- **code**: [ Dijkstra](https://github.com/01fe23bcs120/Bussiness-Cases.github.io/blob/main/Bicycle_Path.cpp)

## 6. Integrated Urban Planning and Sustainable Pedestrian Path Design: Optimizing Zoning and Non-Motorized Transportation Networks ##
 Urban planning involves the efficient allocation of land and resources to create organized, sustainable, and functional urban environments. Zoning is a critical aspect of this process, focusing on the distribution of land for residential, commercial, industrial, and public use. It ensures resource optimization, prevents conflicts between land uses, and fosters economic and social development. Hence, we are using **Prim's algorithm**.

Pedestrian and bicycle path planning complements urban planning by prioritizing safe and efficient non-motorized transportation. It addresses the need for sustainable mobility by designing pathways that connect key urban zones while promoting environmental sustainability, public health, and accessibility. Hence we are using **Dijkstra's algorithm**.

By integrating these two domains, we can create urban spaces that are not only resource-efficient but also prioritize sustainable transportation, contributing to a holistic and livable urban environment.

## Key Aspects ##
- Resource Optimization: Allocate zones for residential, commercial, and industrial use while minimizing costs and conflicts. Utilize graph-based algorithms to create optimal connections between zones.
- Path Planning: Identify the safest and shortest paths for non-motorized traffic. Use pathfinding algorithms to compute routes that consider travel time, distance, and safety metrics.
- Scalability: Support dynamic updates to the network, such as new zones or pathways. Handle large datasets representing complex urban environments.
- Cost Efficiency: Minimize the cost of constructing connections between zones. Prioritize affordable and sustainable solutions for pedestrian and cyclist pathways.
- Sustainability and Accessibility: Promote environmentally friendly transportation modes. Ensure accessibility for all users, including differently-abled individuals.
- Time Complexity: O(E*logV)
- Space Compllexity: O(V+E)
- **code**: [Combined Code for Prim and Dijkstra](https://github.com/01fe23bcs120/Bussiness-Cases.github.io/blob/main/inte_urban_path.cpp)


