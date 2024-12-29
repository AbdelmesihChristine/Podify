# Podify: A Podcast Network Application

## 1. Introduction
**Podify** is a C++ application that simulates a podcast network platform. It allows users to explore podcasts, search for episodes by host or category, and play audio or video content. This project demonstrates advanced object-oriented programming (OOP) concepts, including:

- Operator overloading
- Templates
- Multiple inheritance
- Design patterns such as Factory and Strategy

### Key Features:
- Manage a collection of Podcasts and their Episodes.
- Search for episodes by host, category, or both.
- Play episodes in audio-only or audio-video mode.
- Dynamically load content from files stored in the `media` and `videos` directories.

---

## 2. Video Demo
*(Right-click → “Open Link in New Tab” for best viewing.)* 

[![Watch the video](https://img.youtube.com/vi/vf8kEcTLmm0/hqdefault.jpg)](https://www.youtube.com/watch?v=vf8kEcTLmm0)

---

## 3. Features and Learning Outcomes
- **Operator Overloading & Templates**:
  - The `Array` class uses operator overloading (`+=`, `-=`) and templates to handle dynamic collections of objects.
- **Multiple Inheritance in a Diamond Hierarchy**:
  - The `HorC_Search` class combines functionality from `H_Search` and `C_Search` using virtual inheritance.
- **Factory Pattern**:
  - The `PodcastFactory` class separates the creation of Podcast, Episode, and Search objects from the application logic.
- **Strategy Pattern**:
  - Toggle between audio-only and audio-video playback modes at runtime.
- **File Management**:
  - Episode metadata is loaded from the `media` directory.
  - Video files are stored in the `videos` directory.

---

## 4. Project Structure

├── main.cc // Entry point for the Podify application  
├── Controller.* // Manages interactions between View, Podify, and PodcastFactory  
├── View.* // Handles user input/output and menu displays  
├── Podify.* // Core logic for managing Podcasts and Episodes  
├── Podcast.* // Represents Podcasts and their metadata  
├── Episode.* // Represents individual Episodes within Podcasts  
├── PodcastFactory.* // Creates Podcast, Episode, and Search objects  
├── Search.* // Search functionality for finding Episodes (by host, category, etc.)  
├── PodcastPlayer.* // Handles audio-only or audio-video playback  
├── Array.* // A templated container class with operator overloading  
├── defs.h // Global definitions (e.g., MAX_ARR, constants)  
├── media/ // Directory containing podcast and episode data  
│ ├── media.txt // Metadata for podcasts and episodes  
│ ├── media2.txt // Additional episode metadata  
├── videos/ // Directory containing video files for episodes  
│ ├── video1.txt // ASCII art video for Episode 1  
│ ├── video2.txt // ASCII art video for Episode 2  
│ └── ... // Other video files  
└── README.md // This file  

---

## 5. Core Concepts Implemented
- **Operator Overloading & Templates**:
  - The `Array` class supports dynamic collections with custom operators (`+=`, `-=`) and is fully templated for reusability.
- **Multiple Inheritance in a Diamond Hierarchy**:
  - The `HorC_Search` class inherits from both `H_Search` (by host) and `C_Search` (by category) using virtual inheritance to resolve ambiguity.
- **Factory Design Pattern**:
  - The `PodcastFactory` ensures centralized object creation, allowing seamless addition of new object types in the future.
- **Strategy Pattern**:
  - Playback behavior (audio-only or audio-video) is dynamically adjustable using the strategy pattern.
- **File Management**:
  - Podcast and episode metadata is dynamically loaded from files in the `media` directory, while video playback loads ASCII art from the `videos` directory.

---

## 6. Quick Start

### Building the Project
1. Clone or download the repository.
2. Ensure the `media` and `videos` directories contain the appropriate files (e.g., `media.txt`, `videoX.txt`).
3. Build the project using the provided Makefile:
   make 

This produces an executable named Podify. 

Run the application:  
./Podify  
To clean up:    
make clean  

---

## 7. Usage Example
When you run the program, you will see a menu like the following:

1. Show all Podcasts
2. Show single Podcast
3. Get episode by host
4. Get episode by category
5. Get episode by host or category
6. Print current playlist
7. Play current playlist
8. Toggle video mode
9. Exit

Example Workflow:
Show All Podcasts: Lists all available podcasts and their metadata.  
Search for Episodes: Use options 3, 4, or 5 to find specific episodes based on host, category, or both.  
Add to Playlist: Found episodes are added to the playlist.  
Print or Play Playlist: Use options 6 and 7 to view or play episodes in the playlist.  
Toggle Video Mode: Switch between audio-only and audio-video playback.  

---

## 8. Classes Overview
**Controller**
Manages the flow of the application, handling user interactions and delegating tasks to the View, Podify, and PodcastFactory.

**View**
Handles displaying menus, output to the user, collecting input, and rendering playlists.

**Podify**
Centralized class for managing Podcast and Episode objects. Supports searching and playlist management.

**Podcast**
Represents a podcast, containing metadata (title, host) and a list of Episode objects.

**Episode**
Represents individual episodes, with metadata (title, category) and content (audio, video).

**PodcastFactory**
Centralized factory for creating Podcast, Episode, and Search objects.

**Search (Abstract)**
Base class for search functionality. Derived classes include:  
H_Search: Searches episodes by host.  
C_Search: Searches episodes by category.  
HorC_Search: Combines host and category searches using multiple inheritance.  

**PodcastPlayer (Abstract)**
Base class for episode playback. Derived classes include:  
AudioPlayer: Plays audio-only episodes.  
VideoPlayer: Plays episodes with audio and ASCII art video.  

**Array (Templated)**
A simple container class supporting operator overloading for addition (+=) and removal (-=).  
