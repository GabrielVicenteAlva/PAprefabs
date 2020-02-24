int main(){
    prefab::name = "SingleObject";
    prefab::offset = 0.;
    // Create a new object. Like clicking the object button in the editor
    Object *obj = new Object(
        0., // Giving it its start time. It'll be relative to the prefab's time
        15, // Render depth. Objects with lower values overlap objects with higher values
        shapes::sq, // Shape. See list of shapes in prefab.h
        0, // Editor bin. 0 to 14
        false, // Checking "Helper"
        false, // Checking "AutoKill"
        false // Checking "Empty"
    );
    obj->name = "TheOnlyObject";
    // Like in the editor, time of an event is relative to the object
    // First give an starting event to every type.
    obj->posEvent(0.,-14.,10.);
    obj->scaEvent(0.,4.,4.);
    obj->rotEvent(0.,0.);
    obj->colEvent(0.,0);
    // Adding an event at 2 seconds to move obj to (16,-12)
    obj->posEvent(2.,16.,-12.);
    // Call this at the end of the program
    prefab::generate();
    return 0;
}
