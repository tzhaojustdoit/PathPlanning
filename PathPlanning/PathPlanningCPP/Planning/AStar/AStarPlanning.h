/**
 * @file AStarPlanning.h
 * @brief Defines the AStarPlanning class.
 * @authur: Tianhua Zhao
 */

#ifndef ASTAR_PLANNING_
#define ASTAR_PLANNING_

#include <vector>
#include <iostream>

#include "../Planning.h"
#include "../library/Node.h"
#include "../library/OpenList.h"
#include "../../Utilities/Display.h"

/**
  * @class AStarPlanning
  *
  * @brief Planning using a* search algorithm.
  */
class AStarPlanning : public Planning
{
  public:
	/**
	 *@brief ctor
	 *@param rows, cols :discritized world frame, number of rows and columns in the grid world.
	 */
	AStarPlanning(int rows, int cols);

	/**
	 *@brief dtor
	 */
	~AStarPlanning();

	/**
	 *@brief set goal location, pre-compute heuristic values for each node.
	 *@param goal goal location
	 */
	void SetGoal(int goal) override;

	/**
	 *@brief find the shortest path using a* search.
	 *@param obstacles: contains obstacle info
	 *@param location: starting location
	 */
	std::vector<int> FindPath(const std::vector<bool> &obsacles, int location) override;

	/**
	 *@brief get number of searches
	 */
	int GetNumOfSearches() const override;

	/**
	 *@brief get number of nodes expanded
	 */
	int GetNumOfNodesExpanded() const override;

  private:
	int rows_;
	int cols_;
	std::vector<Node> graph_;
	int goal_location_ = -1;
	int num_of_searches_ = 0;
	int num_of_expanded_nodes_ = 0;

	/**
	 *@brief get heuristic from a to b
	 *@param a, b: two locations
	 */
	int GetHeuristic(int a, int b);

	/**
	 *@brief expand the node with given id
	 *@param id: node id
	 *@param obstacles: contains obstacle info for collision checking
	 *@param closed: the closed list
	 *@param open: the open list
	 */
	void Expand(int id, const std::vector<bool> &obstacles, std::vector<Node *> &closed, OpenList &open);

	/**
	 *@brief generate the node with given id
	 *@param id: node id
	 *@param parent: contains obstacle info
	 *@param closed: the closed list
	 *@param open: the open list
	 */
	void Generate(int id, int parent_id, std::vector<Node *> &closed, OpenList &open);
};
#endif // !ASTAR_PLANNING_