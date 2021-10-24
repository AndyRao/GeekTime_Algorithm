/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int[] inorder;
    int[] postorder;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.inorder = inorder;
        this.postorder = postorder;
        return build(0, inorder.length - 1, 0, postorder.length - 1);
    }

    TreeNode build(int li, int ri, int lp, int rp) {
        if(lp > rp) return null;
        TreeNode root = new TreeNode(postorder[rp]);
        int mid = li;
        while(inorder[mid] != root.val) {
            mid++;
        }
        //左子树范围: li ~ mid - 1 长度: mid - 1 - li + 1 = mid -li
        //右子树范围: mid + 1 ~ ri 
        root.left = build(li, mid - 1, lp, lp + mid - li - 1);
        root.right = build(mid + 1, ri, lp + mid - li, rp - 1);
        return root;
    }
}
