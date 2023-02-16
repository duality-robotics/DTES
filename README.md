Digital Twin Encapsulation Standard
===================================
Welcome to the Digital Twin Encapsulation Standard (DTES) repository. The DTES is a proposal to enable the standardization and interoperability of digital twins (DT). The standard is based on Pixar's USD (Universal Scene Description) framework.


What is the DTES?
-----------------
The DTES is a proposed standard for representing digital twins using USD. It provides a set of schemas and guidelines for organizing and storing information about a digital twin, such as its appearance, physics, and domain specific metadata. By using the DTES, developers can create digital twins that are compatible with a wide range of systems and platforms.


DTES In Practice
----------------



https://user-images.githubusercontent.com/2530388/219462159-b0598d8e-7146-4fe6-b852-929513743eb3.mp4



Below is a basic example of a DT definition in DTES.

```usda
#usda 1.0
(
    upAxis = "Z"
    metersPerUnit = 0.01
    kilogramsPerUnit = 1
    defaultPrim = "Pringles"
)


def dtEncapsulation "Pringles"
(
)
{
    token dtType = "ItemTwin"

    def dtObjectReference "GLTF"
    {
        asset dtAsset = @./pringles.glb@
        string dtScope = "/"

        def dtPhysics "Physics"
        {
            token dtPhysicsType = "Dynamic"
            double dtMass = 0.1
            double dtRestitution = 0.3
            double dtStaticFriction = 0.3

            def dtCollisionShape "CollisionShapeBoxApproximation"
            (
                prepend apiSchemas = ["dtBoxApproximationAPI"]
            )
            {
            }

            rel dtCollisionShape = <CollisionShapeBoxApproximation>
        }
    }

    def Scope "RetailCatalog"  # Additional Metadata for domain specific scope
    {
        string GTIN = "0038000845512"
    }
}
```

In the [examples folder](./examples) you can find more complex examples of:
1. An [Item Twin](./examples/items/PringlesDT/PringlesDT.usda) with multiple LODs and style variants, and multiple object references for specific architectures.
2. A [Space Twin](./examples/items/../spaces/StoreDT/StoreDT.usda) with composition arcs over compiled objects, and multiple object references for specific architectures.
3. A [Scenario](./examples/scenarios/StoreScenario.usda) example, showed in the video above, using the other twins.


What is a Digital Twin?
-----------------------
A digital twin is a digital replica of a physical object or system that can be used for various purposes, such as visualization, simulation, and analysis. Digital twins are often used in industries such as manufacturing, healthcare, and architecture to improve efficiency, reduce costs, and optimize performance.

A DT is more than a visual replica of its physical counterpart. It needs to be "simulation-ready," meaning it should behave and function like the real-world object it represents, carrying information and properties tied to its ontology and physics.

![image4](https://user-images.githubusercontent.com/2530388/218102889-df17ee33-926f-4112-ba6d-b346c891124a.png)

As shown in the figure above, the information that constitutes a DT can be divided into three categories: 3D Assets Properties, Digital Twin Properties, and Platform Properties.

- 3D Assets Properties define the structure and appearance of the DT.
- Digital Twin Properties make the DT simulation-ready and interoperable with other DTs.
- Platform Properties, which are outside of the scope of DTES, provide metadata about the ownership and version history of the DT to enable workflow functions.


Why is Standardization Important?
---------------------------------
The potential applications for digital twins are diverse and far-reaching, from manufacturing and healthcare to architecture and beyond. In order for digital twins to truly realize their full potential, however, it is crucial that they can move across systems and platforms.

Standardization helps ensure that digital twins can be easily shared, exchanged, and made interoperable across different systems and platforms. Furthermore, it promotes collaboration and innovation within the community, as it provides a common framework for DT development and use. Without standardization, the exchange and utilization of digital twins can become complicated and limited, as each system or platform may have its own proprietary formats and protocols. 


Types of Digital Twins
----------------------
The DTES classifies digital twins into three different types:

- **Item Twins**: These are digital twins of simple objects such as consumer packaged goods, trees, furniture, etc. Item twins include information about the object's appearance, dimensions, and material properties.

- **Space Twins**: These are digital twins of environments such as warehouses, buildings, and forests, including all of their "dressing" such as furniture, decor, and other objects. This type of digital twin contains information about multiple objects.

- **System Twins**: These are digital twins of complex systems with logic and behavior, such as robots, vehicles, and people. System twins include information about the system's logic, functionality, dynamics, and control systems.

By categorizing digital twins into these three categories, the DTES provides a framework for organizing and storing information about different types of digital twins.

Building DTES
-------------

### Prerequisites

- [CMake](https://cmake.org/) >= 3.18
- [USD](https://github.com/PixarAnimationStudios/USD)

### Build steps

Clone the repository to your local machine

```shell
$ git clone git@github.com:duality-robotics/DTES.git
```

Create a build directory inside the project directory

```shell
$ cd DTES
$ mkdir build
$ cd build
```

Run CMake to generate the build files

```shell
$ cmake -DUSD_BUILD_ROOT=/path/to/usd ..
```

Build the project using the generated build files

```shell
$ cmake --build . --target install
```

Installation
------------
In order to use the DTES, some environment variables must be set.

1. The usdDTEncapsulation plugin must be added to the `PXR_PLUGINPATH_NAME` environment variable:

    e.g. `/path/to/DTES/build/install/usd/usdDTEncapsulation/resources`

1. The python module must be added to the PYTHONPATH environment variable:

    e.g. `/path/to/DTES/build/install/python`


How Can I Use the DTES?
-----------------------
To use the DTES, you will need a USD viewer or editor that supports the DTES schemas.


To create a digital twin using the DTES, you will need to define the properties and characteristics of your digital twin using the DTES schemas. You can find examples and guidelines for creating digital twins in the examples folder of this repository.


How Can I Contribute to the DTES?
---------------------------------
We welcome contributions to the DTES! If you have suggestions for improving the DTES, or if you have developed extensions or additions to the DTES, please open a pull request or issue on this repository.
