#include <persistent_query.h>
#include <iostream>

/* Component types */
struct Position {
    float x;
    float y;
};

struct Velocity {
    float x;
    float y;
};

int main(int argc, char *argv[]) {
    /* Create the world, pass arguments for overriding the number of threads,fps
     * or for starting the admin dashboard (see flecs.h for details). */
    flecs::world ecs(argc, argv);

    /* Create a query. Queries are 'persistent' meaning they are registered with
     * the world and continuously matched with new entities (tables). Queries
     * are the fastest way to iterate over entities, as a lot of processing is
     * done when entities are matched, outside of the main loop.
     *
     * Queries are the mechanism used by systems, and as such both accept the
     * same signature expressions, and have similar performance.  */
    auto q = ecs.query<Position, const Velocity>();

    /* Create a few entities that match the query */
    ecs.entity("E1")
        .set<Position>({1, 2})
        .set<Velocity>({1, 1});

    ecs.entity("E2")
        .set<Position>({3, 4})
        .set<Velocity>({1, 1});

    /* Don't add Velocity here, E3 will not match query */
    ecs.entity("E3")
        .set<Position>({5, 6});

    /* Iterate over entities matching the query using each */
    q.each([](flecs::entity e, Position& p, const Velocity& v) {
        p.x += v.x;
        p.y += v.y;

        std::cout << "Moved " << e.name() << " to {" <<
            p.x << ", " << p.y << "}" << std::endl;
    });

    /* Iterate over entities matching the query in a nested for loop */
    for (auto it : q) {
        flecs::column<Position> p(it, 1); 
        flecs::column<const Velocity> v(it, 2);
   
        for (auto row : it) {
            p[row].x += v[row].x;
            p[row].y += v[row].y;

            std::cout << "Moved " << it.entity(row).name() << " to {" <<
                p[row].x << ", " << p[row].y << "}" << std::endl;
        }
    }
}
