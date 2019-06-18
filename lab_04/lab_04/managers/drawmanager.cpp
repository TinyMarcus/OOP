#include "drawmanager.h"

void DrawManager::draw_model(BaseDrawer &drw, const ObjectIter &beg, const ObjectIter &end, std::shared_ptr<Object> obj)
{
    std::shared_ptr<Camera> cm = std::static_pointer_cast<Camera>(obj);
    for (ObjectIter iter = beg; iter != end; ++iter)
    {
        if (!(*iter))
            throw NoObjectException();

        if ((*iter)->is_visible())
        {
            std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);

            const std::vector<Edge> edges = model->get_edges();
            if (edges.empty())
                throw NoEdgesException();

            std::vector<Node> nodes = model->get_nodes();
            if (nodes.empty())
                throw NoNodesException();

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                nodes[i].move(cm->move_get_x(), cm->move_get_y(), cm->move_get_z());
                nodes[i].scale(cm->scale_get_x(), cm->scale_get_y(), cm->scale_get_z());

                nodes[i].rotate_x(cm->rotate_get_x());
                nodes[i].rotate_y(cm->rotate_get_y());
                nodes[i].rotate_z(cm->rotate_get_z());
            }

            for (size_t i = 0; i < edges.size(); ++i)
            {
                const Node& source = nodes[edges[i].get_source()];
                const Node& goal = nodes[edges[i].get_goal()];
                drw.draw_line(get_x(source.get_x(), source.get_z()), get_y(source.get_y(), source.get_z()),
                              get_x(goal.get_x(), goal.get_z()), get_y(goal.get_y(), goal.get_z()));
            }
        }
    }
}

double DrawManager::get_x(const double x, const double z) const
{
    return x + z * coeff3D;
}

double DrawManager::get_y(const double y, const double z) const
{
    return -y - z * coeff3D;
}

