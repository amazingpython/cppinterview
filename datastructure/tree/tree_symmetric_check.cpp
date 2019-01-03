/**
 * This below function check if a tree is symmetric or not.
 * Example:
 * Symmetric
 * 					1
 *                 / \
 *                2   2
 *               / \ / \
 *              3  44   3
 *
 * NOT Symmetric
 *                 1
 *                / \
 *               2   2
 *              /    /
 *             3    3
 * A binary tree node looks like:
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isSymmetric(TreeNode* root) {
	queue<TreeNode*> q;

	if (root == NULL) { return true; }

	q.push(root->left);
	q.push(root->right);

	while(!q.empty()) {
		TreeNode* l = q.front(); q.pop();
		TreeNode* r = q.front(); q.pop();
	
		if (l == NULL && r == NULL) { continue; }
		
		if (l == NULL || r == NULL) { return false; }

		if(l->val != r->val) { return false; }
		
		q.push(l->left);
		q.push(r->right);
		q.push(l->right);
		q.push(r->left);
	}
		
	return true;
}
